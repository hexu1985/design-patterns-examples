#include "TableTray.hpp"
#include <sstream>

TableTray::TableTray(const std::string& caption): Tray(caption) {
}

std::string TableTray::makeHTML() {
    std::ostringstream buffer;
    buffer << "<td>";
    buffer << "<table width=\"100%\" border=\"1\"><tr>";
    buffer << "<td bgcolor=\"#cccccc\" align=\"center\" colspan=\"" 
           << tray.size() << "\"><b>" << caption << "</b></td>";
    buffer << "</tr>\n";
    buffer << "<tr>\n";
    for (auto item : tray) {
        buffer << item->makeHTML();
    }
    buffer << "</tr></table>";
    buffer << "</td>";
    return buffer.str();
}

