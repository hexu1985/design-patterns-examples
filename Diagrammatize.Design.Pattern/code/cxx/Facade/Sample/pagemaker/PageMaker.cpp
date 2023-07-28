#include "PageMaker.hpp"

#include <iostream>
#include <fstream>
#include <exception>

#include "Database.hpp"
#include "HtmlWriter.hpp"

void PageMaker::makeWelcomePage(const std::string& mailaddr, const std::string& filename) {
    try {
        auto mailprop = Database::getProperties("maildata");
        std::string username = mailprop.at(mailaddr);
        std::ofstream ofile(filename, std::ofstream::out | std::ofstream::trunc);
        HtmlWriter writer(ofile);
        writer.title("Welcome to " + username + "'s page!");
        writer.paragraph("欢迎来到" + username + "的主页。");
        writer.paragraph("等着你的邮件哦！");
        writer.mailto(mailaddr, username);
        writer.close();
        ofile.close();
        std::cout << filename << " is created for " << mailaddr << " (" << username << ")" << std::endl;
    } catch (std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

