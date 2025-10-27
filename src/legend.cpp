#include "legend.hpp"

void print_legend() {
    std::cout << "======= FARMING SIMULATOR LEGEND =======" << std::endl;
    std::cout << "@ : Your player" << std::endl;
    std::cout << ". : Empty soil plot" << std::endl;
    std::cout << "v / V : Carrot (or other crops)" << std::endl;
    std::cout << std::endl;

    std::cout << "CONTROLS:" << std::endl;
    std::cout << "W : Move Up" << std::endl;
    std::cout << "A : Move Left" << std::endl;
    std::cout << "S : Move Down" << std::endl;
    std::cout << "D : Move Right" << std::endl;
    std::cout << "P : Plant a vegetable at your current location" << std::endl;
    std::cout << "H : Harvest a vegetable at your current location" << std::endl;
    std::cout << "E : End the day" << std::endl;
    std::cout << "L : Print out the game legend" << std::endl;
    std::cout << "Q : Quit the game" << std::endl;
    std::cout << "=================================" << std::endl;
}