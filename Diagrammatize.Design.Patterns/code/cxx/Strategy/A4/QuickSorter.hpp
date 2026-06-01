#pragma once

#include "quick_sort.hpp"

class QuickSorter {
public:
    template <typename T>
    void sort(std::vector<T>& data) {
        QuickSort(data);
    }
};
