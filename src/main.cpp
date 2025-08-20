#include "Game.h"
#include <iostream>

int main(int argc, char* argv[]) {
    Game game;
    
    // Initialize the game
    if (!game.init("SDL Template", 800, 600)) {
        std::cerr << "Failed to initialize game!" << std::endl;
        return -1;
    }
    
    // Run the game
    game.run();
    
    std::cout << "Game finished!" << std::endl;
    return 0;
}

