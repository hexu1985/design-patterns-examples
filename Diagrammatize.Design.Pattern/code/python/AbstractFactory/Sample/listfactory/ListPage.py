import io
from factory import Page

class ListPage(Page):
    def __init__(self, title, author):
        super().__init__(title, author)

    def makeHTML(self):
        buffer = io.StringIO()
        buffer.write("<html><head><title>" + self.title + "</title></head>\n")
        buffer.write("<body>\n")
        buffer.write("<h1>" + self.title + "</h1>\n")
        buffer.write("<ul>\n")
        for item in self.content:
            buffer.write(item.makeHTML())
        buffer.write("</ul>\n")
        buffer.write("<hr><address>" + self.author + "</address>")
        buffer.write("</body></html>\n")
        return buffer.getvalue()
