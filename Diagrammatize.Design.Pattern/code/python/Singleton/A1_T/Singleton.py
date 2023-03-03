from threading import RLock

class SingletonType(type):
    single_lock = RLock()

    def __call__(cls, *args, **kwargs):   # 创建cls的对象时候调用
        with SingletonType.single_lock:
            if not hasattr(cls, "_instance"):
                cls._instance = super(SingletonType, cls).__call__(*args, **kwargs)     # 创建cls的对象

        return cls._instance

