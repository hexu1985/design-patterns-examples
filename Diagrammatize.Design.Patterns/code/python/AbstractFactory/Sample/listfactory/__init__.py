from factory import Factory
from .ListFactory import ListFactory
Factory.registerFactory(ListFactory.__name__, ListFactory)
