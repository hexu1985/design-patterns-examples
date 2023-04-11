import io
from factory import Page

class TablePage(Page):
    def __init__(self, title, author):
        super().__init__(title, author)

    def makeHTML(self):
        buffer = io.StringIO()
        buffer.write("<html><head><title>" + self.title + "</title></head>\n")
        buffer.write("<body>\n")
        buffer.write("<h1>" + self.title + "</h1>\n")
        buffer.write("<table width=\"80%\" border=\"3\">\n")
        for item in self.content:
            buffer.write("<tr>" + item.makeHTML() + "</tr>")
        buffer.write("</table>\n")
        buffer.write("<hr><address>" + self.author + "</address>")
        buffer.write("</body></html>\n")
        return buffer.getvalue()
