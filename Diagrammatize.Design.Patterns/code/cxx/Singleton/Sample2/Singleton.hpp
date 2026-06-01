#pragma once

class Singleton {
private:
    Singleton();

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    static Singleton& getInstance();
};
