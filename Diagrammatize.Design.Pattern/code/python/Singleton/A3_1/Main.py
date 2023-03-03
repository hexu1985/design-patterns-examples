
import threading
from Singleton import Singleton

def run():
    obj = Singleton.getInstance();
    print(threading.current_thread().getName() + ": obj = " + str(obj));

def main():
    print("Start.")
    thread_list = [threading.Thread(target=run), threading.Thread(target=run), threading.Thread(target=run)]
    for t in thread_list:
        t.start()
    for t in thread_list:
        t.join()
    print("End.")

if __name__ == "__main__":
    main()
