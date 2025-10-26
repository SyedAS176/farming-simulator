#include <string>
#include <vector>

#include "farm.hpp"
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

int Farm::number_of_rows() { // Return the # of rows of the farm
    return rows;
}

int Farm::number_of_columns() { // Returns the # of columns of the farm
    return columns;
}

std::string Farm::get_symbol(int row, int column) {
    if(player->row() == row && player->column() == column) {
        return "@";
    } else {
        return plots.at(row).at(column)->symbol();
    }
}

// Farm class controls planting logic
void Farm::plant(int row, int column, Plot *plot) {
    Plot *current_plot = plots.at(row).at(column);
    plots.at(row).at(column) = plot;
    delete current_plot;
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