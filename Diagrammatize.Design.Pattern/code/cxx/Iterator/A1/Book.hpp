#pragma once

#include <string>

class Book {
private:
    std::string name;

public:
    Book(const std::string& name_): name(name_) {
    }

    const std::string& getName() {
        return name;
    }
};

