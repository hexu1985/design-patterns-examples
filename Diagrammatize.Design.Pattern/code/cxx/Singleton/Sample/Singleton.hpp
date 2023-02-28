#pragma once

class Singleton {
private:
    Singleton();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton singleton; 

public:
    static Singleton& getInstance();
};
