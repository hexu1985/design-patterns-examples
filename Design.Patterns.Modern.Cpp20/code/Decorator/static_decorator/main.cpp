#include <cstdint>
#include <iostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

using namespace std;

struct Shape {
    virtual string str() const = 0;
};

struct Circle : Shape {
    float radius;

    Circle() {}
    Circle(float radius) : radius(radius) {}

    void resize(float factor) { radius *= factor; }

    string str() const override {
        ostringstream oss;
        oss << "A circle of radius " << radius;
        return oss.str();
    }
};

struct Square : Shape {
    float side;

    Square() {}
    Square(float side) : side(side) {}

    string str() const override {
        ostringstream oss;
        oss << "An square with side " << side;
        return oss.str();
    }
};

// ==================== 编译期装饰器（区分标准） ====================

#if __cplusplus >= 202002L
// ---------- C++20：使用 concept ----------

template <typename T>
concept IsAShape = std::is_base_of<Shape, T>::value;

template <IsAShape T> struct ColoredShape : T {
    string color;

    template <typename... Args>
    ColoredShape(const string &color, Args... args)
        : T(std::forward<Args>(args)...), color(color) {}

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

template <IsAShape T> struct TransparentShape : T {
    uint8_t transparency;

    template <typename... Args>
    TransparentShape(uint8_t transparency, Args... args)
        : T(std::forward<Args>(args)...), transparency(transparency) {}

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
        return oss.str();
    }
};

#else
// ---------- C++14/17：使用 enable_if + SFINAE ----------

template <typename T>
using EnableIfShape =
    typename std::enable_if<std::is_base_of<Shape, T>::value, int>::type;

template <typename T, EnableIfShape<T> = 0>
struct ColoredShape : T {
    string color;

    template <typename... Args>
    ColoredShape(const string &color, Args... args)
        : T(std::forward<Args>(args)...), color(color) {}

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has the color " << color;
        return oss.str();
    }
};

template <typename T, EnableIfShape<T> = 0>
struct TransparentShape : T {
    uint8_t transparency;

    template <typename... Args>
    TransparentShape(uint8_t transparency, Args... args)
        : T(std::forward<Args>(args)...), transparency(transparency) {}

    string str() const override {
        ostringstream oss;
        oss << T::str() << " has "
            << static_cast<float>(transparency) / 255.f * 100.f << "% transparency";
        return oss.str();
    }
};

#endif  // __cplusplus >= 202002L

// ==================== main（两个标准都用） ====================

int main() {
    ColoredShape<Circle> green_circle{"green", 5};
    cout << green_circle.str() << endl;

    TransparentShape<Square> transparent_sq{51, 5};
    cout << transparent_sq.str() << endl;

    TransparentShape<ColoredShape<Square>> crazy_sq{0, "blue", 5};
    crazy_sq.color = "light blue";
    cout << crazy_sq.str() << endl;

    return 0;
}
