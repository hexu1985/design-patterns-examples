from factory import Factory
from .ListLink import ListLink
from .ListTray import ListTray
from .ListPage import ListPage


class ListFactory(Factory):
    def createLink(self, caption, url):
        return ListLink(caption, url)

    def createTray(self, caption):
        return ListTray(caption)

    def createPage(self, title, author):
        return ListPage(title, author)
