#pragma once

#include "Database.hpp"

class PageMaker {
public:
    static void makeWelcomePage(const std::string& mailaddr, const std::string& filename); 

    static void makeLinkPage(const std::string& filename);
};
