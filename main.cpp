#include "game.h"
#include <iostream>

int main() {
    while (true) {
        // Print basic instructions
        std::cout << "==== Connect 4 ====" << std::endl;
        std::cout << "1. Start Game" << std::endl;
        std::cout << "2. Instructions" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Select an option: ";
        int option;
        std::cin >> option;
        switch(option) {
            case 1:
                {
                    Game game;
                    game.start();
                    break;
                }
            case 2:
                std::cout << "Instructions: Connect 4 is a two-player game. Take turns dropping pieces into columns. First to connect 4 in a row wins!" << std::endl;
                break;
            case 3:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid option. Try again." << std::endl;
                break;
        }
    }
    return 0;
}
