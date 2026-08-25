#pragma once

#include <iostream>
#include <queue>
#include <deque>

// 方法1：通过拷贝队列来打印（不修改原队列）
template<typename T, typename Container = std::deque<T>>
void printQueue(const std::queue<T, Container>& q, std::ostream& os = std::cout) {
    auto temp = q;  // 拷贝一份
    os << "[ ";
    while (!temp.empty()) {
        os << temp.front();
        temp.pop();
        if (!temp.empty()) os << ", ";
    }
    os << " ]";
}

// operator<< 重载实现
template<typename T, typename Container>
std::ostream& operator<<(std::ostream& os, const std::queue<T, Container>& q) {
    printQueue(q, os);
    return os;
}

