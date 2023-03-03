
import threading
import time

def synchronized(func):
    func.__lock__ = threading.Lock()

    def _synchronized_wrapper(*args, **kwargs):
        with func.__lock__:
            return func(*args, **kwargs)

    return _synchronized_wrapper

class Singleton:
    _singleton = None

    def __init__(self):
        print("生成了一个实例。")
        self.slowdown()

    @classmethod
    @synchronized
    def getInstance(cls):
        if not cls._singleton:
            cls._singleton = cls()
        return cls._singleton

    def slowdown(self):
        time.sleep(1.0)
