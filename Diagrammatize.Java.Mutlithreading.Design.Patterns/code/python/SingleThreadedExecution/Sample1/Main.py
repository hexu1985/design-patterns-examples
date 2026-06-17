import threading
import time
from Gate import Gate
from UserThread import UserThread

def main():
    print("Testing Gate, hit CTRL+C to exit.")
    gate = Gate()
    
    # Create and start threads
    alice = UserThread(gate, "Alice", "Alaska")
    bobby = UserThread(gate, "Bobby", "Brazil")
    chris = UserThread(gate, "Chris", "Canada")
    
    alice.start()
    bobby.start()
    chris.start()
    
    # Keep main thread alive to catch CTRL+C
    while True:
        time.sleep(1)

if __name__ == "__main__":
    main()
