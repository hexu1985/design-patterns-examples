from factory import Link

class TableLink(Link):
    def __init__(self, caption, url):
        super().__init__(caption, url)

    def makeHTML(self):
        return "<td><a href=\"" + self.url + "\">" + self.caption + "</a></td>\n"

