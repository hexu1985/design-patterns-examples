#pragma once

#include <string>
#include "json.hpp"

class Database {
public:
    static nlohmann::json getProperties(const std::string& dbname); 
};
