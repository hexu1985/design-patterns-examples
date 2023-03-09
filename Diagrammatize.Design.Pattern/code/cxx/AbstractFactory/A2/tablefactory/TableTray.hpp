#pragma once

#include "factory/Tray.hpp"

class TableTray: public Tray {
public:
    TableTray(const std::string& caption);

    std::string makeHTML() override;
};
