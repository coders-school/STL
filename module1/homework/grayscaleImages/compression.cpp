#include "compression.hpp"

#include <algorithm>
#include <iostream>
#include <utility>

using vector_of_pairs = std::vector<std::pair<uint8_t, uint8_t>>;
using array_of_arrays = std::array<std::array<uint8_t, width>, height>;

vector_of_pairs compressGrayscale(const array_of_arrays& bitmap) {
    vector_of_pairs compressed{};
    compressed.reserve(width * height);
    uint8_t occurrences = 0;
    uint8_t color_code = 0;
    for (const auto& row : bitmap) {
        color_code = row.front();
        occurrences = 1;
        for (auto element = row.begin(); element != row.end(); ++element) {
            auto next = std::next(element);
            if (color_code != *next || next == row.end()) {
                compressed.push_back({color_code, occurrences});
                color_code = *next;
                occurrences = 1;
            } else {
                ++occurrences;
            }
        }
    }
    compressed.shrink_to_fit();
    return compressed;
}

array_of_arrays decompressGrayscale(const vector_of_pairs& bitmap) {
    array_of_arrays decompressed{};
    auto it = bitmap.begin();
    int counter = 0;
    for (size_t row = 0; row < height; ++row) {
        for (size_t column = 0; column < width;) {
            while (counter++ < it->second) {
                decompressed[row][column++] = it->first;
            }
            ++it;
            counter = 0;
        }
    }
    return decompressed;
}

void printMap(const array_of_arrays& bitmap) {
    char empty_char = ' ';
    for (const auto& row : bitmap) {
        for (const auto& column : row) {
            if (column == empty_char) {
                std::cout << empty_char;
            } else {
                std::cout << column;
            }
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}
