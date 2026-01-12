#include <fstream>
#include <iostream>
#include <string>

#include "ProgramNode.hpp"

int main(int argc, char* argv[]) {
    std::string file_path = "program.txt";

    std::ifstream ifile{file_path};
    if (!ifile) {
        std::cerr << "open file " << file_path << " failed!\n";
        return 1;
    }

    std::string text;
    while (std::getline(ifile, text)) {
        std::cout << "text = \"" << text << "\"" << std::endl;
        ProgramNode node;
        Context context{text};
        node.parse(context);
        std::cout << "node = " << node.toString() << "\n";
    }
}

