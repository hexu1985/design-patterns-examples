
import time

class Singleton:
    _singleton = None

    def __init__(self):
        print("生成了一个实例。")
        self.slowdown()

    @classmethod
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton

    def slowdown(self):
        time.sleep(1.0)
