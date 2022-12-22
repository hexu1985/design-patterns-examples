class Director:
    def __init__(self, builder):    # 因为接收的参数是Builder类的子类
        self.builder = builder      # 所以可以将其保存在builder字段中

    def construct(self):                       # 编写文档
        self.builder.makeTitle("Greeting")              # 标题
        self.builder.makeString("从早上至下午")         # 字符串
        self.builder.makeItems([                         # 条目
            "早上好。",
            "下午好。"
            ])
        self.builder.makeString("晚上")                 # 其他字符串
        self.builder.makeItems([                     # 其他条目
            "晚上好。",
            "晚安。",
            "再见。",
            ])
        self.builder.close()                            # 完成文档
