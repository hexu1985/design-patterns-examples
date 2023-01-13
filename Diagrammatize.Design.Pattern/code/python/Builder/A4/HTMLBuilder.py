import traceback

from Builder import Builder

class HTMLBuilder(Builder):
    def __init__(self):
        self.filename = ''          # 文件名
        self.writer = None          # 用于编写文件的writer

    def makeTitle(self, title):         # HTML文件的标题
        self.filename = title + ".html"     # 将标题作为文件名
        try: 
            self.writer = open(self.filename, 'w')    # 生成 writer
        except:
            traceback.print_exc()
            raise
            
        print("<html><head><title>" + title + "</title></head><body>", file=self.writer)    # 输出标题
        print("<h1>" + title + "</h1>", file=self.writer)

    def makeString(self, str_):                     # HTML文件中的字符串
        print("<p>" + str_ + "</p>", file=self.writer)      # 用<p>标签输出

    def makeItems(self, items):                     # HTML文件中的条目
        print("<ul>", file=self.writer)                     # 用<ul>和<li>输出
        for i in range(len(items)):
            print("<li>" + items[i] + "</li>", file=self.writer)
        print("</ul>", file=self.writer)

    def close(self):                        # 完成文档
        print("</body></html>", file=self.writer)   # 关闭标签
        self.writer.close()                         # 关闭文件

    def getResult(self):                    # 编写完成的文档
        return self.filename                    # 返回文件名
