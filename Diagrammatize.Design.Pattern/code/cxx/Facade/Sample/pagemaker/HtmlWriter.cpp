#include "HtmlWriter.hpp"

HtmlWriter::HtmlWriter(std::ostream& writer_): writer(writer_) {
}

void HtmlWriter::title(const std::string& title) {
    writer << "<html>";
    writer << "<head>";
    writer << "<title>" << title << "</title>";
    writer << "</head>";
    writer << "<body>\n";
    writer << "<h1>" << title << "</h1>\n";
}

void HtmlWriter::paragraph(const std::string& msg) {
    writer << "<p>" << msg << "</p>\n";
}

void HtmlWriter::link(const std::string& href, const std::string& caption) {
    paragraph("<a href=\"" + href + "\">" + caption + "</a>");
}

void HtmlWriter::mailto(const std::string& mailaddr, const std::string& username) {
    link("mailto:" + mailaddr, username);
}

void HtmlWriter::close() {
    writer << "</body>";
    writer << "</html>\n";
}
