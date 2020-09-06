#pragma once

#include <deque>
#include <list>
#include <map>
#include <sstream>
#include <string>
#include <vector>

enum class Volume {
    g,
    m,
    s
};

bool AppendNewRecipe(std::vector<std::string> steps,
                     const std::list<std::string>& ingredients,
                     const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                           const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);

std::string convertEnumToString(char c);