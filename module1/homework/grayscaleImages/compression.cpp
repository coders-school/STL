#include "compression.hpp"

#include <iostream>
#include <string>

CompressedImage compressGrayscale(const UncompressedImage& uncompressed) {
    CompressedImage compressed;
    compressed.reserve(height * width);

    for (const auto& row : uncompressed) {
        auto rowIterator = row.cbegin();
        uint8_t currentValue = *rowIterator;
        uint8_t currentValueCounter = 1;
        rowIterator++;

        while (rowIterator != row.cend()) {
            if (*rowIterator == currentValue) {
                currentValueCounter++;
            } else {
                compressed.push_back(std::make_pair(currentValue, currentValueCounter));
                currentValue = *rowIterator;
                currentValueCounter = 1;
            }
            rowIterator++;
        }
        // and when row reach end:
        compressed.push_back(std::make_pair(currentValue, currentValueCounter));
    }

    compressed.shrink_to_fit();
    return compressed;
}

UncompressedImage decompressGrayscale(const CompressedImage& compressed) {
    UncompressedImage uncompressed;
    auto pixelGroup = compressed.begin();
    uint8_t howManyPixels = pixelGroup->second;

    for (auto& row : uncompressed) {
        for (auto& pixel : row) {
            if (howManyPixels == 0) {
                pixelGroup++;
                howManyPixels = pixelGroup->second;
            }
            pixel = pixelGroup->first;
            howManyPixels--;
        }
    }
    return uncompressed;
}

void printMap(const UncompressedImage& bitmap) {
    const std::string palette = R"( .'`^",:;Il!i><~+_-?][}{1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$)";
    int level;
    const double normalizingFactor = palette.size() / 256.0;
    std::cout << "\n";

    for (auto& row : bitmap) {
        for (auto& pixel : row) {
            level = pixel * normalizingFactor;
            std::cout << palette[level];
        }
        std::cout << "\n";
    }
}
