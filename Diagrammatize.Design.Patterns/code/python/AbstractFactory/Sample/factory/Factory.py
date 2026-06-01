import abc
import traceback

class Factory(abc.ABC):
    factory_set = dict()
    
    @staticmethod
    def registerFactory(classname, cls):
        Factory.factory_set[classname] = cls

    @staticmethod
    def getFactory(classname):
        factory = None
        try:
            cls = Factory.factory_set[classname]
            factory = cls()
        except KeyError as e:
            print("没有找到 " + classname + "类。")
        except:
            traceback.print_exc()
        return factory

    @abc.abstractmethod
    def createLink(self, caption, url):
        pass

    @abc.abstractmethod
    def createTray(self, caption):
        pass

    @abc.abstractmethod
    def createPage(self, title, author):
        pass
    
