from Observer import Observer
import time

class GraphObserver(Observer):
    def update(self, generator):
        print("GraphObserver:", end='')
        count = generator.getNumber()
        for i in range(0, count):
            print('*', end='')
        print('')
        time.sleep(0.1)
