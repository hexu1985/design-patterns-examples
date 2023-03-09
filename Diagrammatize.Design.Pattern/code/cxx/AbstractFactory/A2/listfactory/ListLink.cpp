#include "ListLink.hpp"

ListLink::ListLink(const std::string& caption, const std::string& url): Link(caption, url) {
}

std::string ListLink::makeHTML() {
    return "  <li><a href=\"" + url + "\">" + caption + "</a></li>\n";
}
