from factory import Link

class ListLink(Link):
    def __init__(self, caption, url):
        super().__init__(caption, url)

    def makeHTML(self):
        return "  <li><a href=\"" + self.url + "\">" + self.caption + "</a></li>\n"
