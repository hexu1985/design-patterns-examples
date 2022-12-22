
import io
from Builder import Builder

class TextBuilder(Builder):
    def __init__(self):
        super().__init__()
        self.buffer = io.StringIO()       # 文档内容保存在该字段中 

    def buildTitle(self, title):                         # 纯文本的标题
        self.buffer.write("==============================\n")       # 装饰线
        self.buffer.write("『" + title + "』\n")                    # 为标题加上『』
        self.buffer.write("\n")                                     # 换行

    def buildString(self, str_):                         # 纯文本的字符串
        self.buffer.write("■" + str_ + "\n")                        # 为字符串添加■
        self.buffer.write("\n")                                     # 换行

    def buildItems(self, items):                         # 纯文本的条目
        for i in range(len(items)):
            self.buffer.write("　・" + items[i] + "\n")             # 为条目添加・
        self.buffer.write("\n")                                     # 换行

    def buildDone(self):                                    # 完成文档
        self.buffer.write("==============================\n")       # 装饰线

    def getResult(self):                                # 完成后的文档
        return self.buffer.getvalue()
