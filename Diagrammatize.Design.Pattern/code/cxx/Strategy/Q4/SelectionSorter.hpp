#pragma once

#include "selection_sort.hpp"

class SelectionSorter {
public:
    template <typename T>
    void sort(std::vector<T>& data) {
        SelectionSort(data);
    }
};
