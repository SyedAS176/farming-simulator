#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"

class Farm {
private:
    int rows;
    int columns;
    Player *player;
    std::vector<std::vector<Plot *>> plots;

public:
    Farm(int rows, int columns, Player *player);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
    void plant(int row, int column, Plot *plot);
    void end_day();

    // Movement logic functions for the player
    bool in_bounds(int new_row, int new_column);
    void move_player_right();
    void move_player_left();
    void move_player_up();
    void move_player_down();
};