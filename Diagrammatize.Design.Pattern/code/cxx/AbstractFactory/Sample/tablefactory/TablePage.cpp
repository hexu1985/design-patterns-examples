#include "TablePage.hpp"
#include <sstream>

TablePage::TablePage(const std::string& title, const std::string& author): Page(title, author) {
} 

std::string TablePage::makeHTML() {
    std::stringstream buffer;
    buffer << "<html><head><title>" << title << "</title></head>\n";
    buffer << "<body>\n";
    buffer << "<h1>" << title << "</h1>\n";
    buffer << "<table width=\"80%\" border=\"3\">\n";
    for (auto item : content) {
        buffer << "<tr>" << item->makeHTML() << "</tr>";
    }
    buffer << "</table>\n";
    buffer << "<hr><address>" << author << "</address>";
    buffer << "</body></html>\n";
    return buffer.str();
}

