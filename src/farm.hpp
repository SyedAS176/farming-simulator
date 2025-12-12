#pragma once

#include <string>
#include <vector>

#include "plot.hpp"
#include "player.hpp"
#include "bunny.hpp"

class Farm {
private:
    int rows;
    int columns;
    int day = 1;            // MOVE THIS WHEN YOU MAKE A WORLD LOGIC CLASS; which i shouldve done in the beginning but i got lazy
    Player *player;
    std::vector<std::vector<Plot *>> plots;

    Bunny* bunny;
    double bunny_spawn_probability;

public:
    // Farm constructor
    Farm(int rows, int columns, Player *player, double bunny_spawn_probability = 0.99); // Default bunny spawn probability of 5% (will be 0% for unit testing)

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
    bool on_bunny(int new_row, int new_column);
    void move_player_right();
    void move_player_left();
    void move_player_up();
    void move_player_down();

    // Watering logic
    void water(int row, int column);

    // Movement logic methods for the bunny
    void move_bunny_down();
    void move_bunny_left();
    void move_bunny_right();
    void move_bunny_up();

    void move_bunny_away_from_player();   // For scared movement
    bool is_adjacent_to_bunny(int player_row, int player_column);    // Checks if the player is directly up, down, left, or right from the bunny

    void bunny_spawn(); // Handles bunny spawning probability/logic
};