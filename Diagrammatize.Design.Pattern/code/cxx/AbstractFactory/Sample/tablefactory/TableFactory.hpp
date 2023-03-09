#pragma once

#include "factory/Factory.hpp"

class TableFactory: public Factory {
public:
    Link* createLink(const std::string& caption, const std::string& url) override;

    Tray* createTray(const std::string& caption) override;

    Page* createPage(const std::string& title, const std::string& author) override;
};
