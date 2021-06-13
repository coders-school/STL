#pragma once
#include <algorithm>
#include <array>
#include <vector>
#include <stdint.h>

constexpr size_t width = 240;
constexpr size_t height = 160;

std::vector<std::pair<uint8_t, uint8_t >> compressGrayscale(std::array<std::array<uint8_t, width>, height>);
std::array<std::array<uint8_t, width>, height> decompressGrayscale(std::vector<std::pair<uint8_t, uint8_t >>);
