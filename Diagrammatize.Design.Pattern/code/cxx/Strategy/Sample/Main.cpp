#include <iostream>
#include <string>

#include "Player.hpp"
#include "WinningStrategy.hpp"
#include "ProbStrategy.hpp"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cout << "Usage: " << argv[0] << " randomseed1 randomseed2\n";
        std::cout << "Example: " << argv[0] << " 314 15\n";
        return 0;
    }

    int seed1 = std::stoi(argv[1]);
    int seed2 = std::stoi(argv[2]);

    Player player1("Taro", new WinningStrategy(seed1));
    Player player2("Hana", new ProbStrategy(seed2));
    for (int i = 0; i < 10000; i++) {
        Hand nextHand1 = player1.nextHand();
        Hand nextHand2 = player2.nextHand();
        if (nextHand1.isStrongerThan(nextHand2)) {
            std::cout << "Winner:" << player1 << std::endl;
            player1.win();
            player2.lose();
        } else if (nextHand2.isStrongerThan(nextHand1)) {
            std::cout << "Winner:" << player2 << std::endl;
            player1.lose();
            player2.win();
        } else {
            std::cout << "Even..." << std::endl;
            player1.even();
            player2.even();
        }
    }

    std::cout << "Total result:\n";
    std::cout << player1 << std::endl;
    std::cout << player2 << std::endl;
}
