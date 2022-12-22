import sys
from Director import Director
from TextBuilder import TextBuilder
from HTMLBuilder import HTMLBuilder

def usage():
    print("Usage: python Main.py plain      编写纯文本文档")
    print("Usage: python Main.py html       编写HTML文档")

def main():
    if len(sys.argv) != 2:
        usage()
        sys.exit(0)

    if sys.argv[1] == "plain":
        textbuilder = TextBuilder()
        director = Director(textbuilder)
        director.construct()
        result = textbuilder.getResult()
        print(result);
    elif sys.argv[1] == "html":
        htmlbuilder = HTMLBuilder()
        director = Director(htmlbuilder)
        director.construct()
        filename = htmlbuilder.getResult();
        print(filename + "文件编写完成。");
    else:
        usage()
        sys.exit(0)

if __name__ == "__main__":
    main()
