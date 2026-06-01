from factory import Factory
from .TableFactory import TableFactory
Factory.registerFactory(TableFactory.__name__, TableFactory)
