
from Director import Director
from MarkdownBuilder import MarkdownBuilder

def main():
    markdownbuilder = MarkdownBuilder()
    director = Director(markdownbuilder)
    director.construct()
    filename = markdownbuilder.getResult()
    print(filename + "文件编写完成。")

if __name__ == "__main__":
    main()
