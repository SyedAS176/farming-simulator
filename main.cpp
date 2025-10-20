#include <iostream>

#include "src/farm.hpp"
#include "src/farm_printer.h"

int main() {
    Farm farm(10, 10);
    FarmPrinter printer(&farm);
    std::cout << printer.pp();
}