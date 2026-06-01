import io
from factory import Tray

class ListTray(Tray):
    def __init__(self, caption):
        super().__init__(caption)

    def makeHTML(self):
        buffer = io.StringIO()
        buffer.write("<li>\n")
        buffer.write(self.caption + "\n")
        buffer.write("<ul>\n")
        for item in self.tray:
            buffer.write(item.makeHTML())
        buffer.write("</ul>\n")
        buffer.write("</li>\n")
        return buffer.getvalue()
