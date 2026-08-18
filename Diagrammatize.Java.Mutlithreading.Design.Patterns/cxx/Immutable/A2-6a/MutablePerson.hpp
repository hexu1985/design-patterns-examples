#pragma once

#include <string>
#include <mutex>
#include <memory>

class ImmutablePerson; // 前向声明

class MutablePerson {
private:
    std::string name;
    std::string address;
    mutable std::mutex mtx; // 用于同步

public:
    MutablePerson(const std::string& name, const std::string& address)
        : name(name), address(address) {}

    MutablePerson(const ImmutablePerson& person);

    void setPerson(const std::string& newName, const std::string& newAddress) {
        std::lock_guard<std::mutex> lock(mtx);
        name = newName;
        address = newAddress;
    }

    std::shared_ptr<ImmutablePerson> getImmutablePerson() const;

    const std::string& getName() const {
        return name;
    }

    const std::string& getAddress() const {
        return address;
    }

    std::string toString() const {
        std::lock_guard<std::mutex> lock(mtx);
        return "[ MutablePerson: " + name + ", " + address + " ]";
    }

    // 声明ImmutablePerson为友元类
    friend class ImmutablePerson;
};
