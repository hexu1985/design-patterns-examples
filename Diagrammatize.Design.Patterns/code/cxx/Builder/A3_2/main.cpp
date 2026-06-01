#include <cstdlib>
#include <iostream>
#include <string>

#include "Director.hpp"
#include "MarkdownBuilder.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    MarkdownBuilder* markdownbuilder = new MarkdownBuilder();
    Director* director = new Director(markdownbuilder);
    director->construct();
    string filename = markdownbuilder->getResult();
    cout << filename << "文件编写完成。" << endl;
}
