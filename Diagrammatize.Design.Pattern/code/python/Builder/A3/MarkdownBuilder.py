import traceback

class MarkdownBuilder:
    def __init__(self):
        self.filename = ''          # 文件名
        self.writer = None          # 用于编写文件的writer

    def makeTitle(self, title):         # Markdown文件的标题
        self.filename = title + ".md"     # 将标题作为文件名
        try: 
            self.writer = open(self.filename, 'w')    # 生成 writer
        except:
            traceback.print_exc()
            raise
            
        print("- - -", file=self.writer)            # 分割线
        print("# " + title, file=self.writer)       # 输出标题
        print("", file=self.writer)

    def makeString(self, str_):                     # Markdown文件中的字符串
        print("> " + str_, file=self.writer)
        print("", file=self.writer)

    def makeItems(self, items):                     # Markdown文件中的条目
        for i in range(len(items)):
            print("* " + items[i], file=self.writer)
        print("", file=self.writer)

    def close(self):                        # 完成文档
        print("- - -", file=self.writer)        # 分割线
        self.writer.close()                     # 关闭文件

    def getResult(self):                    # 编写完成的文档
        return self.filename                    # 返回文件名
