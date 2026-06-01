#include "ListPage.hpp"
#include <sstream>

ListPage::ListPage(const std::string& title, const std::string& author): Page(title, author) {
}

std::string ListPage::makeHTML() {
    std::stringstream buffer;
    buffer << "<html><head><title>" << title << "</title></head>\n";
    buffer << "<body>\n";
    buffer << "<h1>" << title << "</h1>\n";
    buffer << "<ul>\n";
    for (auto item : content) {
        buffer << item->makeHTML();
    }
    buffer << "</ul>\n";
    buffer << "<hr><address>" << author << "</address>";
    buffer << "</body></html>\n";
    return buffer.str();
}
