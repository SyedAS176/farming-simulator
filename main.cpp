#include <iostream>
#include <algorithm>

#include "src/player.hpp"
#include "src/farm.hpp"
#include "src/farm_printer.hpp"
#include "src/carrot.hpp"
#include "src/ansi_clear.hpp"
#include "src/legend.hpp"

int main() {
    Player player;
    Farm farm(7, 8, &player);
    FarmPrinter printer(&farm);
    bool game_in_progress = true;
    std::string player_input;
    print_legend(); // Print legend on first running the game

    while(game_in_progress) {
        ansi_clear();
        std::cout << printer.pp() << std::endl;
        std::cin >> player_input;

        // Convert input to lowercase for case-insensitivity
        std::transform(player_input.begin(), player_input.end(), player_input.begin(), ::tolower);

        if(player_input == "q") {
            game_in_progress = false;
        } else if (player_input == "d") {
            farm.move_player_right();
        } else if (player_input == "a") {
            farm.move_player_left();
        } else if (player_input == "w") {
            farm.move_player_up();
        } else if (player_input == "s") {
            farm.move_player_down();
        } else if (player_input == "c") {
            Carrot *carrot = new Carrot();
            farm.plant(player.row(), player.column(), carrot);
        } else if (player_input == "e") {
            farm.end_day();
        } else if (player_input == "h") {
            farm.harvest(player.row(), player.column());
        } else if (player_input == "l") {
            print_legend();
        }
    }
}