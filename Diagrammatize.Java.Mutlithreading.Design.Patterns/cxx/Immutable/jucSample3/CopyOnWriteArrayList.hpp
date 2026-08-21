#pragma once

#include <vector>
#include <memory>
#include <mutex>
#include <atomic>

class CopyOnWriteArrayList {
private:
    std::shared_ptr<std::vector<int>> data;
    mutable std::mutex write_mutex;

public:
    CopyOnWriteArrayList() : data(std::make_shared<std::vector<int>>()) {}

    // 读操作：无锁，直接读取当前快照
    std::shared_ptr<const std::vector<int>> getSnapshot() const {
        return std::atomic_load(&data);
    }

    // 写操作：复制整个底层数组，修改副本，然后原子地替换
    void add(int value) {
        std::lock_guard<std::mutex> lock(write_mutex);
        auto new_data = std::make_shared<std::vector<int>>(*data);
        new_data->push_back(value);
        std::atomic_store(&data, new_data);
    }

    void remove(int index) {
        std::lock_guard<std::mutex> lock(write_mutex);
        if (index < 0 || index >= data->size()) return;

        auto new_data = std::make_shared<std::vector<int>>(*data);
        new_data->erase(new_data->begin() + index);
        std::atomic_store(&data, new_data);
    }
};
