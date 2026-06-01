
class PrinterManager:
    factory_method_map = dict()

    @staticmethod
    def newInstance(className):
        factory_method = PrinterManager.factory_method_map.get(className, None)
        if factory_method is None:
            return None
        return factory_method()

    @staticmethod
    def registerFactoryMethod(className, factory_method):
        PrinterManager.factory_method_map[className] = factory_method

