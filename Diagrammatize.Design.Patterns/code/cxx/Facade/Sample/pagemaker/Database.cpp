#include "Database.hpp"

#include <iostream>
#include <fstream>

nlohmann::json Database::getProperties(const std::string& dbname) {
    std::string filename = dbname + ".json";
    std::ifstream ifile(filename);
    if (!ifile) {
        std::cerr << "Warning: " << filename << " is not found." << '\n';
        return {};
    }

    nlohmann::json prop;
    ifile >> prop;
    return prop;
}

