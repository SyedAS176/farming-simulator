#include "bunny.hpp"

// Constructor
Bunny::Bunny(int start_row, int start_col)
    : current_row(start_row), current_column(start_col), scared(false) {}

// Getters
int Bunny::get_row() const {
    return current_row;
}

int Bunny::get_column() const {
    return current_column;
}

// Set new position
void Bunny::set_position(int new_row, int new_col) {
    current_row = new_row;
    current_column = new_col;
}

// Scared behavior
void Bunny::scare() {
    scared = true;
}

void Bunny::calm() {
    scared = false;
}

bool Bunny::is_scared() const {
    return scared;
}