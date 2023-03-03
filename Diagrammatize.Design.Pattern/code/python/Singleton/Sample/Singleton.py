
class Singleton:
    _singleton = None

    def __init__(self):
        print("生成了一个实例。")

    @classmethod
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton
