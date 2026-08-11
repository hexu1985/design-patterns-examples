#pragma once

#include <string>

class UserInfo {
private:
    std::string info;

public:
    UserInfo(const std::string& name, const std::string& address) {
        info = "<info name=\"" + name + "\" address=\"" + address + "\" />";
    }

    std::string& getInfo() {
        return info;
    }

    std::string toString() const {
        return "[ UserInfo: " + info + " ]";
    }
};

