#include "game/Gamer.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>

static std::string SAVEFILENAME = "game.dat";       

void saveMemento(Memento* memento) {
    std::ofstream out(SAVEFILENAME, std::ofstream::out | std::ofstream::trunc);
    if (!out) {
        std::cout << "open file[" << SAVEFILENAME << "] for write failed!" << std::endl;
        return;
    }

    std::string data = memento->dumpToJson();
    out.write(data.c_str(), data.size());
    out.close();
    return;
}

Memento* loadMemento() {
    Memento* memento = nullptr;
    std::ifstream in(SAVEFILENAME, std::ifstream::in);
    if (!in) {
        std::cout << "open file[" << SAVEFILENAME << "] for read failed!" << std::endl;
        return memento;
    }

    // get length of file:
    in.seekg (0, in.end);
    int length = in.tellg();
    in.seekg (0, in.beg);

    std::string data(length, '\0');
    in.read(const_cast<char*>(data.data()), length);

    return Memento::createFromJson(data);
}

int main() {
    Gamer* gamer = new Gamer(100);               // 最初的所持金钱数为100
    Memento* memento = loadMemento();            // 从文件中读取起始状态   
    if (memento != nullptr) {
        std::cout << "读取上次保存存档开始游戏。\n";
        gamer->restoreMemento(memento);
    } else {
        std::cout << "新游戏。\n";
        memento = gamer->createMemento();
    }
    for (int i = 0; i < 100; i++) {
        std::cout << "==== " << i << '\n';          // 显示掷骰子的次数
        std::cout << "当前状态:" << *gamer << '\n';  // 显示主人公现在的状态

        gamer->bet();    // 进行游戏 

        std::cout << "所持金钱为" << gamer->getMoney() << "元。\n";

        // 决定如何处理Memento
        if (gamer->getMoney() > memento->getMoney()) {
            std::cout << "    （所持金钱增加了许多，因此保存游戏当前的状态）\n";
            memento = gamer->createMemento();
            saveMemento(memento);
        } else if (gamer->getMoney() < memento->getMoney() / 2) {
            std::cout << "    （所持金钱减少了许多，因此将游戏恢复至以前的状态）\n";
            gamer->restoreMemento(memento);
        }

        // 等待一段时间
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
}

