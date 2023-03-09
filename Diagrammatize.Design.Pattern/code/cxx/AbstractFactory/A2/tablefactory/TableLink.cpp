#include "TableLink.hpp"

TableLink::TableLink(const std::string& caption, const std::string& url): Link(caption, url) {
}

std::string TableLink::makeHTML() {
    return "<td><a href=\"" + url + "\">" + caption + "</a></td>\n";
}
