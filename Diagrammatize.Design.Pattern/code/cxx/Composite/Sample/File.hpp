#pragma once

#include <string>
#include "Entry.hpp"

class File: public Entry {
private:
    std::string name;
    int size;

public:
    File(const std::string& name, int size);

    std::string getName() const override;

    int getSize() const override;

    using Entry::printList;

protected:
    void printList(const std::string& prefix) const override;
};
