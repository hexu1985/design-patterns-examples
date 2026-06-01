#pragma once

#include <string>
#include <iosfwd>

class Hand {
public:
    static constexpr int HANDVALUE_GUU = 0;  // 表示石头的值
    static constexpr int HANDVALUE_CHO = 1;  // 表示剪刀的值
    static constexpr int HANDVALUE_PAA = 2;  // 表示布的值

    static Hand hand[];         // 表示猜拳中3种手势的实例
    static std::string name[];  // 表示猜拳中手势所对应的字符串

private:
    int handvalue = 0;                      // 表示猜拳中出的手势的值
    Hand(int handvalue); 

public:
    Hand() = default;
    static const Hand& getHand(int handvalue);      // 根据手势的值获取其对应的实例
    bool isStrongerThan(const Hand& h) const;       // 如果this胜了h则返回true
    bool isWeakerThan(const Hand& h) const;         // 如果this输给了h则返回true
    std::string toString() const;                   // 转换为手势值所对应的字符串

private:
    int fight(const Hand& h) const;                 // 计分：平0, 胜1, 负-1
};

std::ostream& operator<<(std::ostream&, const Hand&);
