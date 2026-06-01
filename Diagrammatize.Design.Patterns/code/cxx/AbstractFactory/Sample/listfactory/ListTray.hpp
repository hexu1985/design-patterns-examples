#pragma once

#include "factory/Tray.hpp"

class ListTray: public Tray {
public:
    ListTray(const std::string& caption);

    std::string makeHTML() override;
};
