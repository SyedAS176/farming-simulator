#include <string>
#include <vector>
#include <random>

#include "farm.hpp"
#include "soil.hpp"

Farm::Farm(int rows, int columns, Player *player, double bunny_spawn_probability) : rows(rows), columns(columns), player(player), bunny_spawn_probability(bunny_spawn_probability), bunny(nullptr) {
    for(int i = 0; i < rows; i++) {
        std::vector<Plot *> row;
        for(int j = 0; j < columns; j++) {
            Soil *soil = new Soil();
            row.push_back(soil);
        }
        plots.push_back(row);
    }

    // Bunny spawn
    bunny_spawn();
}

// Return the # of rows of the farm
int Farm::number_of_rows() {
    return rows;
}

// Returns the # of columns of the farm
int Farm::number_of_columns() {
    return columns;
}

// Returns the # of days elapsed
int Farm::get_day() {
    return day;
}


std::string Farm::get_symbol(int row, int column) {
    if(player->row() == row && player->column() == column) {
        return "@";                             // Player's position is printed as '@'
    } else if (bunny != nullptr && bunny->get_row() == row && bunny->get_column() == column) {
        return "U";                             // Bunny's position is printed as 'U'
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
    day +=1;    // Increment the in-game day
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            plots.at(i).at(j)->end_day();
        }
    }

    // Check if the bunny has moved near the player at the end of the day
    if (bunny != nullptr && is_adjacent_to_bunny(player->row(), player->column())) {    // Check if player is on an adjacent tile to the bunny
        bunny->scare();
    }

    // Bunny movement at the end of the day
    if (bunny != nullptr) { // Check if bunny spawned in
        if (bunny->is_scared()) {   // Check if bunny is scared and if it should move 4 tiles
            move_bunny_away_from_player();
        } else {
            move_bunny_down(); // Regular movement --- THIS MUST CHANGE TO RANDOMNESS WHEN YOU DECIDE TO IMPLEMENT IT, but for now im lazy and dont really have much time
        }
    }

    // Bunny eats plants if on a vegetable
    if (bunny != nullptr) {
        int br = bunny->get_row();
        int bc = bunny->get_column();

        // Check if the bunny is inside farm boundaries (just in case)
        if (br >= 0 && br < rows && bc >= 0 && bc < columns) {
            Plot* current_plot = plots.at(br).at(bc);
            if (current_plot->symbol() != ".") {   // It is a plant
                plots.at(br).at(bc) = new Soil(); // Replace plant with soil
                delete current_plot;              // Free memory
            }
        }
    }

    // Start of end_day(): handle new bunny spawn if none exists
    if (bunny == nullptr || bunny->get_row() < 0 || bunny->get_row() >= rows || bunny->get_column() < 0 || bunny->get_column() >= columns) {
        delete bunny;  // Free previous bunny object memory if off-map
        bunny = nullptr;
        // Run the bunny spawn probability
        bunny_spawn();
    }
}

// Player movement logic is dictated by the Farm class; it permits the player to move in the world
bool Farm::in_bounds(int new_row, int new_column) {
    return new_row >= 0 && new_row < rows && new_column >= 0 && new_column < columns;
}

bool Farm::on_bunny(int new_row, int new_column) {
    if (bunny == nullptr) {
        return true; // No bunny has spawned = tile is safe to move onto
    }
    return !(bunny->get_row() == new_row && bunny->get_column() == new_column); // Check if the bunny's row and column matches the player's next move, if they do, return false, else true
}

void Farm::move_player_right() {
    int new_col = player->column() + 1;                                                              // Storing the desired row for moving right
    if (in_bounds(player->row(), new_col) && on_bunny(player->row(), new_col)) { // Determine if Player can move right; ensure movement is not out of bounds or onto a bunny
        player->move_right();                                                                        // Call move_right() method from Player class
    }
    if (bunny != nullptr && is_adjacent_to_bunny(player->row(), player->column())) {    // Check if player is on an adjacent tile to the bunny
        bunny->scare();
    }
}

void Farm::move_player_left() {
    int new_col = player->column() - 1;                                                              // Storing the desired row for moving left
    if (in_bounds(player->row(), new_col) && on_bunny(player->row(), new_col)) { // Determine if Player can move left; ensure movement is not out of bounds or onto a bunny
        player->move_left();                                                                         // Call move_left() method from Player class
    }
    if (bunny != nullptr && is_adjacent_to_bunny(player->row(), player->column())) {    // Check if player is on an adjacent tile to the bunny
        bunny->scare();
    }
}

void Farm::move_player_up() {
    int new_row = player->row() - 1;                                                   // Storing the desired row for moving up
    if (in_bounds(new_row, player->column()) && on_bunny(new_row, player->column())) { // Determine if Player can move up; ensure movement is not out of bounds or onto a bunny
        player->move_up();                                                             // Call move_up() method from Player class
    }
    if (bunny != nullptr && is_adjacent_to_bunny(player->row(), player->column())) {    // Check if player is on an adjacent tile to the bunny
        bunny->scare();
    }
}

void Farm::move_player_down() {
    int new_row = player->row() + 1;                                                   // Storing the desired row for moving down
    if (in_bounds(new_row, player->column()) && on_bunny(new_row, player->column())) { // Determine if Player can move down; ensure movement is not out of bounds or onto a bunny
        player->move_down();                                                           // Call move_down() method from Player class
    }
    if (bunny != nullptr && is_adjacent_to_bunny(player->row(), player->column())) {    // Check if player is on an adjacent tile to the bunny
        bunny->scare();
    }
}

//  Watering logic for plants
void Farm::water(int row, int column) {
    Plot *current_plot = plots.at(row).at(column);
    current_plot->water();
}

// ======= BUNNY LOGIC =======

void Farm::move_bunny_down() {
    if (bunny == nullptr) { // Bunny did not spawn
        return;
    }
    bunny->set_position(bunny->get_row() + 1, bunny->get_column());
}


void Farm::move_bunny_left() { /* TODO */ }
void Farm::move_bunny_right() { /* TODO */ }
void Farm::move_bunny_up() { /* TODO */ }

void Farm::move_bunny_away_from_player() {
    if (bunny == nullptr || !bunny->is_scared()) {  // Bunny did not spawn OR is not scared
        return;
    }

    int dr = bunny->get_row() - player->row();
    int dc = bunny->get_column() - player->column();

    int new_row = bunny->get_row();
    int new_column = bunny->get_column();

    // Determine which axis to move along
    if (abs(dr) >= abs(dc)) {
        new_row += (dr > 0) ? 4 : -4;       // Move vertically away
    } else {
        new_column += (dc > 0) ? 4 : -4;    // Move horizontally away
    }

    bunny->set_position(new_row, new_column);
    bunny->calm();
}

bool Farm::is_adjacent_to_bunny(int player_row, int player_column) {
    if (bunny == nullptr) { // Bunny did not spawn
        return false;
    }

    // Grab bunny location
    int bunny_row = bunny->get_row();
    int bunny_col = bunny->get_column();

    // Check the four adjacent positions
    if ((player_row == bunny_row - 1 && player_column == bunny_col) ||  // Above
        (player_row == bunny_row + 1 && player_column == bunny_col) ||  // Below
        (player_row == bunny_row && player_column == bunny_col - 1) ||  // Left
        (player_row == bunny_row && player_column == bunny_col + 1))    // Right
    {
        return true;
    }
    return false;
}

void Farm::bunny_spawn() {

    // Guarantee: no bunny ever spawns when probability = 0; needed for unit testing to pass
    if (bunny_spawn_probability <= 0.0) {
        bunny = nullptr;
        return;
    }

    // BUNNY SPAWN LOGIC
    int random_percentage_int = std::rand() % 100; // Gives 0-99
    double probability = static_cast<double>(random_percentage_int) / 100.0; // Gives 0.0 - 0.99

    if (probability <= bunny_spawn_probability) {
        // Only spawn if tile is within farm boundaries (and tile (0,2) is within farm boundaries)
        if (0 < rows && 2 < columns) {
            bunny = new Bunny(0, 2);
        }
    } else {
        bunny = nullptr;
    }
}