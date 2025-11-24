#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"

class Farm {
private:
    int rows;
    int columns;
    int day = 1;            // MOVE THIS WHEN YOU MAKE A WORLD LOGIC CLASS; which i shouldve done in the beginning but i got lazy
    Player *player;
    std::vector<std::vector<Plot *>> plots;

public:
    // Farm constructor
    Farm(int rows, int columns, Player *player);

    // Farm getter methods
    int number_of_rows();
    int number_of_columns();
    int get_day();          // MOVE THIS WHEN YOU MAKE A WORLD LOGIC CLASS
    std::string get_symbol(int row, int column);

    // Farm functionality logic methods
    void plant(int row, int column, Plot *plot);
    void harvest(int row, int column);
    void end_day();

    // Movement logic methods for the player
    bool in_bounds(int new_row, int new_column);
    void move_player_right();
    void move_player_left();
    void move_player_up();
    void move_player_down();

    // Watering logic
    void water(int row, int column);
};