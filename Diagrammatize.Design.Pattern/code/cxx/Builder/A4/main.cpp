#include <cstdlib>
#include <iostream>
#include <string>

#include "TextBuilder.hpp"
#include "Director.hpp"
#include "HTMLBuilder.hpp"

using namespace std;

void usage(const char *cmd) {
    cout << "Usage: " << cmd << " plain      编写纯文本文档" << endl; 
    cout << "Usage: " << cmd << " html       编写HTML文档" << endl;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        usage(argv[0]);
        exit(0);
    }

    if (argv[1] == string("plain")) {
        TextBuilder* textbuilder = new TextBuilder();
        Director* director = new Director(textbuilder);
        director->construct();
        string result = textbuilder->getResult();
        cout << result << endl;
    } else if (argv[1] == string("html")) {
        HTMLBuilder* htmlbuilder = new HTMLBuilder();
        Director* director = new Director(htmlbuilder);
        director->construct();
        string filename = htmlbuilder->getResult();
        cout << filename << "文件编写完成。" << endl;
    } else {
        usage(argv[0]);
        exit(0);
    }
}
