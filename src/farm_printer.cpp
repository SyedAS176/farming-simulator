#include <string>

#include "farm.hpp"
#include "farm_printer.hpp"

#include <iostream>
#include <ostream>

FarmPrinter::FarmPrinter(Farm *farm) : farm(farm) {}

std::string FarmPrinter::pp() {
    std::cout << "======= DAY " << farm->get_day() << " =======" << std::endl;

    std::string output = "";

    Bunny* bunny = farm->get_bunny();   // Cache pointer for convenience
    int bunny_row = -1;
    int bunny_col = -1;

    if (bunny != nullptr) { // If bunny has spawned, grabs the row and column of spawning
        bunny_row = bunny->get_row();
        bunny_col = bunny->get_column();
    }

    for(int i = 0; i < farm->number_of_rows(); i++) {
        for(int j = 0; j < farm->number_of_columns(); j++) {

            // Bunny has the highest priority for printing except player
            if (bunny != nullptr && i == bunny_row && j == bunny_col) {
                output += "U ";   // Bunny symbol
                continue;   // Skip to the next iteration of the for loop
            }

            // If the above block did not run, the bunny did not spawn, and we just print the farm (player and plots) as usual
            output += farm-> get_symbol(i, j);
            output += " ";
        }
        output += "\n";
    }
    return output;
}