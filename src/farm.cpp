#include <string>
#include <vector>

#include "farm.hpp"

#include <bits/ios_base.h>

#include "soil.hpp"

Farm::Farm(int rows, int columns, Player *player) : rows(rows), columns(columns), player(player) {
    for(int i = 0; i < rows; i++) {
        std::vector<Plot *> row;
        for(int j = 0; j < columns; j++) {
            Soil *soil = new Soil();
            row.push_back(soil);
        }
        plots.push_back(row);
    }
}

// Return the # of rows of the farm
int Farm::number_of_rows() {
    return rows;
}

// Returns the # of columns of the farm
int Farm::number_of_columns() {
    return columns;
}

std::string Farm::get_symbol(int row, int column) {
    if(player->row() == row && player->column() == column) {
        return "@";                             // Player's position is printed as '@'
    } else {
        return plots.at(row).at(column)->symbol(); // Soil or other plot types are printed normally
    }
}

// Farm class controls planting logic
void Farm::plant(int row, int column, Plot *plot) {
    Plot *current_plot = plots.at(row).at(column);  // We grab the Plot object pointer; the @ (player) is not a Plot object
    if (current_plot->symbol() == ".") {            // Allows you to plant only if the current plot is empty (has a "." Plot object)
        plots.at(row).at(column) = plot;            // Remember @ is the printer level but "." is the Plot object level
        delete current_plot;
    }
}

// Farm class harvest controls logic; pretty similar to the plant method
void Farm::harvest(int row, int column) {
    Plot *current_plot = plots.at(row).at(column);  // We grab the Plot object pointer; could be a crop or soil
    if (current_plot->is_mature()) {                // Check if the crop is mature (harvestable)
        plots.at(row).at(column) = new Soil();      // Replace the harvested crop with an empty soil plot (represented by ".")
        delete current_plot;                        // Delete the old crop object to free memory
    }
}

// Farm class controls day logic
void Farm::end_day() {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            plots.at(i).at(j)->end_day();
        }
    }
}

// Player movement logic is dictated by the Farm class; it permits the player to move in the world
bool Farm::in_bounds(int new_row, int new_column) {
    return new_row >= 0 && new_row < rows && new_column >= 0 && new_column < columns;
}

void Farm::move_player_right() {
    int new_col = player->column() + 1;                // Storing the desired row for moving right
    if (in_bounds(player->row(), new_col)) { // Determine if Player can move right; ensure movement is not out of bounds
        player->move_right();                          // Call move_right() method from Player class
    }
}

void Farm::move_player_left() {
    int new_col = player->column() - 1;                // Storing the desired row for moving left
    if (in_bounds(player->row(), new_col)) { // Determine if Player can move left; ensure movement is not out of bounds
        player->move_left();                           // Call move_left() method from Player class
    }
}

void Farm::move_player_up() {
    int new_row = player->row() - 1;            // Storing the desired row for moving up
    if (in_bounds(new_row, player->column())) { // Determine if Player can move up; ensure movement is not out of bounds
        player->move_up();                      // Call move_up() method from Player class
    }
}

void Farm::move_player_down() {
    int new_row = player->row() + 1;            // Storing the desired row for moving down
    if (in_bounds(new_row, player->column())) { // Determine if Player can move down; ensure movement is not out of bounds
        player->move_down();                    // Call move_down() method from Player class
    }
}