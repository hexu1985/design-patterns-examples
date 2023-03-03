from Singleton import Singleton

def main():
    print("Start.")
    obj1 = Singleton.getInstance()
    obj2 = Singleton.getInstance()
    if obj1 is obj2:
        print("obj1与obj2是相同的实例。")
    else:
        print("obj1与obj2是不同的实例。")
    print("End.")

if __name__ == "__main__":
    main()
