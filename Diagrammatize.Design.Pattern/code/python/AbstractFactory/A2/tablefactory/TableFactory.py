from factory import Factory
from .TableLink import TableLink
from .TableTray import TableTray
from .TablePage import TablePage

class TableFactory(Factory):
    def createLink(self, caption, url):
        return TableLink(caption, url)

    def createTray(self, caption):
        return TableTray(caption)

    def createPage(self, title, author):
        return TablePage(title, author)
