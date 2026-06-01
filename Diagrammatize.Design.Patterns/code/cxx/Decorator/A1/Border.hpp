#pragma once

#include "Display.hpp"

class Border: public Display {
protected:
    Display* display;          // 表示被装饰物
    Border(Display* display);  // 在生成实例时通过参数指定被装饰物
};

