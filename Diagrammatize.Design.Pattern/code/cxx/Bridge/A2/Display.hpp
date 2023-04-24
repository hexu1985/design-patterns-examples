#pragma once

class DisplayImpl;

class Display {
private:
    DisplayImpl* impl;

public:
    Display(DisplayImpl* impl);
    virtual ~Display();

    void open();
    void print();
    void close();

    void display();
};
