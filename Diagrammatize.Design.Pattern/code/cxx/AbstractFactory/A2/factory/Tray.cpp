#include "Tray.hpp"

Tray::Tray(const std::string& caption): Item(caption) {
}

void Tray::add(Item* item) {
    tray.push_back(item);
}
