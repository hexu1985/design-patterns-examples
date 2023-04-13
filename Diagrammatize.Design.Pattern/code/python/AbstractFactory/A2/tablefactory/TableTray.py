import io
from factory import Tray

class TableTray(Tray):
    def __init__(self, caption):
        super().__init__(caption)

    def makeHTML(self):
        buffer = io.StringIO()
        buffer.write("<td>")
        buffer.write("<table width=\"100%\" border=\"1\"><tr>")
        buffer.write("<td bgcolor=\"#cccccc\" align=\"center\" colspan=\""+ str(len(self.tray)) + "\"><b>" + self.caption + "</b></td>")
        buffer.write("</tr>\n")
        buffer.write("<tr>\n")
        for item in self.tray:
            buffer.write(item.makeHTML())
        buffer.write("</tr></table>")
        buffer.write("</td>")
        return buffer.getvalue()
