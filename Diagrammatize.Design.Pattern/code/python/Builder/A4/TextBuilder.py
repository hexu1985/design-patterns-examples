import io

from Builder import Builder

class TextBuilder(Builder):
    def __init__(self):
        self.buffer = ''       # 文档内容保存在该字段中 

    def makeTitle(self, title):                         # 纯文本的标题
        self.buffer += "==============================\n"       # 装饰线
        self.buffer += "『" + title + "』\n"                    # 为标题加上『』
        self.buffer += "\n"                                     # 换行

    def makeString(self, str_):                         # 纯文本的字符串
        self.buffer += "■" + str_ + "\n"                        # 为字符串添加■
        self.buffer += "\n"                                     # 换行

    def makeItems(self, items):                         # 纯文本的条目
        for i in range(len(items)):
            self.buffer += "　・" + items[i] + "\n"             # 为条目添加・
        self.buffer += "\n"                                     # 换行

    def close(self):                                    # 完成文档
        self.buffer += "==============================\n"       # 装饰线

    def getResult(self):                                # 完成后的文档
        return self.buffer
