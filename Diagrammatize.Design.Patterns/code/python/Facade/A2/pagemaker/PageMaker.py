import traceback

from . Database import Database
from . HtmlWriter import HtmlWriter

class PageMaker:
    @staticmethod
    def makeWelcomePage(mailaddr, filename):
        try:
            mailprop = Database.getProperties("maildata")
            username = mailprop[mailaddr]
            writer = HtmlWriter(open(filename, "w"))
            writer.title("Welcome to " + username + "'s page!")
            writer.paragraph("欢迎来到" + username + "的主页。")
            writer.paragraph("等着你的邮件哦！")
            writer.mailto(mailaddr, username)
            writer.close()
            print(filename + " is created for " + mailaddr + " (" + username + ")")
        except Exception as e:
            traceback.print_exc()

    @staticmethod
    def makeLinkPage(filename):
        try:
            writer = HtmlWriter(open(filename, "w"))
            writer.title("Link page")
            mailprop = Database.getProperties("maildata")
            for mailaddr, username in mailprop.items():
                writer.mailto(mailaddr, username)
            writer.close()
            print(filename + " is created.")
        except Exception as e:
            traceback.print_exc()

