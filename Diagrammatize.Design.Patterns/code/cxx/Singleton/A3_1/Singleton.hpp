#pragma once

class Singleton {
private:
    static Singleton* singleton;

    Singleton();
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    void slowdown();

public:
    static Singleton& getInstance();
};
