#pragma once

#include <iostream>

class HtmlWriter {
private:
    std::ostream& writer;

public:
    HtmlWriter(std::ostream& writer);

    void title(const std::string& title);

    void paragraph(const std::string& msg);

    void link(const std::string& href, const std::string& caption);

    void mailto(const std::string& mailaddr, const std::string& username);

    void close();
};
