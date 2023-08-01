
class HtmlWriter:
    def __init__(self, writer):
        self.writer = writer

    def title(self, title):
        self.writer.write("<html>")
        self.writer.write("<head>")
        self.writer.write("<title>" + title + "</title>")
        self.writer.write("</head>")
        self.writer.write("<body>\n")
        self.writer.write("<h1>" + title + "</h1>\n")

    def paragraph(self, msg):
        self.writer.write("<p>" + msg + "</p>\n")

    def link(self, href, caption):
        self.paragraph("<a href=\"" + href + "\">" + caption + "</a>");

    def mailto(self, mailaddr, username):
        self.link("mailto:" + mailaddr, username)

    def close(self):
        self.writer.write("</body>")
        self.writer.write("</html>\n")
        self.writer.close()
