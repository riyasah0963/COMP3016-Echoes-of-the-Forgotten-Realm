#include "GameEngine.h"
#include <iostream>
#include <stdexcept>

int main() {
    try {
        GameEngine game;
        game.startGame();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    catch (...) {
        std::cerr << "Unknown error occurred" << std::endl;
        return 1;
    }
    
    return 0;
}
