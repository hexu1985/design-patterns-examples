#pragma once

#include <vector>
#include <iostream>

template <typename T, typename Sorter>
class SortAndPrint {
private:
    std::vector<T> data;
    Sorter sorter;

public:
    SortAndPrint(const std::vector<T>& data_, const Sorter& sorter_):
        data(data_), sorter(sorter_) {
    }

    void execute() {
        print();
        sorter.sort(data);
        print();
    }

    void print() {
        for (const auto& item: data) {
            std::cout << item << ", ";
        }
        std::cout << std::endl;
    }
};
