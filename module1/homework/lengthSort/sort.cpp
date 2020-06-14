#include "sort.hpp"
#include <algorithm>

std::deque<std::string> lengthSort(std::forward_list<std::string>& list) {
    list.sort();
    std::deque<std::string> dequeSorted;

    for (auto &el : list) {
        dequeSorted.emplace_back(el);
    }

    std::sort(dequeSorted.begin(), dequeSorted.end(), [](const auto& el, const auto& nextEl) {
        if (el.size() == nextEl.size())
        {
            return el < nextEl;
        }
        return el.size() < nextEl.size();
    });

    return dequeSorted;
}
