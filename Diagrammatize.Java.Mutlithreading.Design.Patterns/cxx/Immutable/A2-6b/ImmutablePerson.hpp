#pragma once

#include <string>
#include <mutex>
#include <memory>

class MutablePerson; 

class ImmutablePerson {
private:
    std::string name;
    std::string address;

public:
    ImmutablePerson(const std::string& name, const std::string& address)
        : name(name), address(address) {}
    
    ImmutablePerson(const MutablePerson& person);
    
    std::shared_ptr<MutablePerson> getMutablePerson() const; 
    
    const std::string& getName() const {
        return name;
    }
    
    const std::string& getAddress() const {
        return address;
    }
    
    std::string toString() const {
        return "[ ImmutablePerson: " + name + ", " + address + " ]";
    }
    
    // 声明MutablePerson为友元类
    friend class MutablePerson;
};
