#pragma once

#include <vector>
#include <string>

#include "Entry.hpp"

class Directory: public Entry {
private:
    std::string name;       // 文件夹的名字
    std::vector<Entry*> directory;      // 文件夹中目录条目的集合

public:
    Directory(const std::string& name);

    std::string getName() const override;

    int getSize() const override;

    Entry* add(Entry* entry);

    using Entry::printList;

protected:
    void printList(const std::string& prefix) const override;
};
