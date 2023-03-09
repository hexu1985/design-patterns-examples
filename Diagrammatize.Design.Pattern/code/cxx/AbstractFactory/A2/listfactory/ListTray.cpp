#include "ListTray.hpp"
#include <sstream>

ListTray::ListTray(const std::string& caption): Tray(caption) {
}

std::string ListTray::makeHTML() {
    std::ostringstream buffer;
    buffer << "<li>\n";
    buffer << caption << "\n";
    buffer << "<ul>\n";
    for (auto item : tray) {
        buffer << item->makeHTML();
    }
    buffer << "</ul>\n";
    buffer << "</li>\n";
    return buffer.str();
}
