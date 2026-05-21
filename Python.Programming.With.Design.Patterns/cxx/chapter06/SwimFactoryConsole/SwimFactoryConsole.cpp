#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

#include "SwimClasses.hpp"

// -------------------------- Builder 类 --------------------------
class Builder {
public:
    void build() {
        int dist = 1;
        while (dist > 0) {
            std::cout << "Enter 1 for 100, 5 for 500 or 0 to quit: ";
            std::cin >> dist;
            if (dist == 1 || dist == 5) {
                evselect(dist);
            }
        }
    }

    // 根据距离选择并排位指定项目
    void evselect(int dist) {
        Event* event = nullptr;

        if (dist == 5) {
            event = new TimedFinalEvent("500free.txt", 6);
        } else if (dist == 1) {
            event = new PrelimEvent("100free.txt", 6);
        }

        if (event) {
            // 工厂方法：获取合适的排位策略
            Seeding* seeding = event->getSeeding();
            std::vector<Swimmer*> swmrs = seeding->getSwimmers();

            // 打印排位后的选手列表
            std::cout << std::right;
            for (Swimmer* sw : swmrs) {
                std::cout << std::setw(3) << sw->heat
                          << std::setw(3) << sw->lane << " "
                          << std::setw(20) << sw->getName()
                          << std::setw(3) << sw->age << " "
                          << std::setw(9) << sw->seedtime << std::endl;
            }

            delete seeding;
            delete event;
        }
    }
};

int main() {
    Builder builder;
    builder.build();
    return 0;
}
