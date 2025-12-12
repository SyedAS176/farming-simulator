#include "legend.hpp"

void print_legend() {
    std::cout << "======= FARMING SIMULATOR LEGEND =======" << std::endl;
    std::cout << "@ : Your player" << std::endl;
    std::cout << "U : The bunny" << std::endl;
    std::cout << ". : Empty soil plot" << std::endl;
    std::cout << "# : Tilled soil plot" << std::endl;
    std::cout << "c / C : Carrot" << std::endl;
    std::cout << "l / L : Lettuce" << std::endl;
    std::cout << "s / S : Spinach" << std::endl;
    std::cout << "b / B : Beet" << std::endl;
    std::cout << "bs / BS : Brussels" << std::endl;

    std::cout << std::endl;

    std::cout << "CONTROLS:" << std::endl;
    std::cout << "W : Move Up" << std::endl;
    std::cout << "A : Move Left" << std::endl;
    std::cout << "S : Move Down" << std::endl;
    std::cout << "D : Move Right" << std::endl;

    std::cout << "c/C : Plant a carrot at your current location" << std::endl;
    std::cout << "l/L : Plant a lettuce at your current location" << std::endl;
    std::cout << "s/S : Plant a spinach at your current location" << std::endl;
    std::cout << "b/B : Plant a beet at your current location" << std::endl;
    std::cout << "bs/BS : Plant a brussels sprouts at your current location" << std::endl;

    std::cout << "H : Harvest a vegetable at your current location" << std::endl;
    std::cout << "E : End the day" << std::endl;
    std::cout << "? : Print out the game legend" << std::endl;
    std::cout << "Q : Quit the game" << std::endl;
    std::cout << "=================================" << std::endl;
}