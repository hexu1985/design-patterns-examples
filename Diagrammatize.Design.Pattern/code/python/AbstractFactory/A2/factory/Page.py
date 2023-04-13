import abc

class Page:
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self.content = list()

    def add(self, item):
        self.content.append(item)

    def output(self):
        filename = self.title + ".html"
        writer = open(filename, "w")
        writer.write(self.makeHTML())
        writer.close()
        print(filename + " 编写完成。")

    @abc.abstractmethod
    def makeHTML(self):
        pass
