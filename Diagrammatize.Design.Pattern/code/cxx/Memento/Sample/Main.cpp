#include "game/Gamer.hpp"
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    Gamer* gamer = new Gamer(100);               // 最初的所持金钱数为100
    Memento* memento = gamer->createMemento();    // 保存最初的状态
    for (int i = 0; i < 100; i++) {
        std::cout << "==== " << i << '\n';          // 显示掷骰子的次数
        std::cout << "当前状态:" << *gamer << '\n';  // 显示主人公现在的状态

        gamer->bet();    // 进行游戏 

        std::cout << "所持金钱为" << gamer->getMoney() << "元。\n";

        // 决定如何处理Memento
        if (gamer->getMoney() > memento->getMoney()) {
            std::cout << "    （所持金钱增加了许多，因此保存游戏当前的状态）\n";
            memento = gamer->createMemento();
        } else if (gamer->getMoney() < memento->getMoney() / 2) {
            std::cout << "    （所持金钱减少了许多，因此将游戏恢复至以前的状态）\n";
            gamer->restoreMemento(memento);
        }

        // 等待一段时间
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

