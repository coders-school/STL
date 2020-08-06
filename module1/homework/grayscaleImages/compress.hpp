#pragma once

#include <iostream>
#include <vector>
#include <array>

std::vector<std::pair<uint8_t, uint8_t>> compressGrayscale(std::array<std::array<uint8_t, 240>, 160> const bitmap);
