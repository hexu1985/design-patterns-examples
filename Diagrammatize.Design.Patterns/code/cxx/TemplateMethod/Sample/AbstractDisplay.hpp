#pragma once

class AbstractDisplay { // 抽象类AbstractDisplay
public:
    virtual ~AbstractDisplay();

    virtual void open() = 0;        // 交给子类去实现的抽象方法(1) open
    virtual void print() = 0;       // 交给子类去实现的抽象方法(2) print
    virtual void close() = 0;       // 交给子类去实现的抽象方法(3) close

    void display() {       // 本抽象类中实现的display方法
        open();                         // 首先打开…
        for (int i = 0; i < 5; i++) {   // 循环调用5次print
            print();                    
        }
        close();                        // …最后关闭。这就是display方法所实现的功能
    }
};
