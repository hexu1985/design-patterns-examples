#pragma once

#include <string>

class Person {
private:
    std::string name;
    std::string address;

public:
    // 构造函数
    Person(const std::string& name, const std::string& address) 
        : name(name), address(address) {}

    const std::string& getName() const {
        return name;
    }

    const std::string& getAddress() const {
        return address;
    }

    // toString方法
    std::string toString() const {
        return "[ Person: name = " + name + ", address = " + address + " ]";
    }
};
