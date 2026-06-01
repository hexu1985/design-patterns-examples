from factory import *
import listfactory
import tablefactory

import sys

def main():
    if len(sys.argv) != 2:
        print("Usage: python {} class.name.of.ConcreteFactory".format(sys.argv[0]))
        print("Example 1: python {} ListFactory".format(sys.argv[0]))
        print("Example 2: python {} TableFactory".format(sys.argv[0]))
        sys.exit(1)

    factory = Factory.getFactory(sys.argv[1])

    people = factory.createLink("人民日报", "http://www.people.com.cn/")
    gmw = factory.createLink("光明日报", "http://www.gmw.cn/")

    us_yahoo = factory.createLink("Yahoo!", "http://www.yahoo.com/")
    jp_yahoo = factory.createLink("Yahoo!Japan", "http://www.yahoo.co.jp/")
    excite = factory.createLink("Excite", "http://www.excite.com/")
    google = factory.createLink("Google", "http://www.google.com/")

    traynews = factory.createTray("日报")
    traynews.add(people)
    traynews.add(gmw)

    trayyahoo = factory.createTray("Yahoo!")
    trayyahoo.add(us_yahoo)
    trayyahoo.add(jp_yahoo)

    traysearch = factory.createTray("检索引擎")
    traysearch.add(trayyahoo)
    traysearch.add(excite)
    traysearch.add(google)

    page = factory.createPage("LinkPage", "杨文轩")
    page.add(traynews)
    page.add(traysearch)
    page.output()

if __name__ == "__main__":
    main()
