from idcard import IDCardFactory

def main():
    factory = IDCardFactory()
    card1 = factory.create("小明")
    card2 = factory.create("小红")
    card3 = factory.create("小刚")
    card1.use()
    card2.use()
    card3.use()

if __name__ == "__main__":
    main()
