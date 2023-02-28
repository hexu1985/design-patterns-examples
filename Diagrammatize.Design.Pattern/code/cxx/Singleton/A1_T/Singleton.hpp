#pragma once

template <typename T>
class Singleton {
private:
    friend T;
    Singleton() = default;
    ~Singleton() = default;

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    Singleton(Singleton&&) = default;
    Singleton& operator=(Singleton&&) = default;

public:
    static T& getInstance() {
        static T singleton;
        return singleton;
    }
};

