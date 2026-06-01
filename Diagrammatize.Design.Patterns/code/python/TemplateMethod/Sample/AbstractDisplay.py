import abc

class AbstractDisplay(abc.ABC):
    @abc.abstractmethod
    def open(self):
        # 交给子类去实现的抽象方法(1) open
        pass

    @abc.abstractmethod
    def print(self):
        # 交给子类去实现的抽象方法(2) print
        pass

    @abc.abstractmethod
    def close(self):
        # 交给子类去实现的抽象方法(3) close
        pass

    def display(self):
        self.open()             # 首先打开…
        for _ in range(5):      # 循环调用5次print
            self.print()
        self.close()            # …最后关闭。这就是display方法所实现的功能


