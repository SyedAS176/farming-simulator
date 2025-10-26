#include "player.hpp"

int Player::row() {
    return current_row;
}

int Player::column() {
    return current_column;
}

void Player::move_right() {
    int new_columnR = current_column + 1;       // Storing the desired row for moving right
    if (in_bounds(current_row, new_columnR)) {  // Making sure the movement is not out of bounds
        current_column = new_columnR;           // Allows you to move right
    }
}

void Player::move_left() {
    int new_columnL = current_column - 1;       // Storing the desired row for moving left
    if (in_bounds(current_row, new_columnL)) {  // Making sure the movement is not out of bounds
        current_column = new_columnL;           // Allows you to move left
    }
}

void Player::move_up() {
    int new_rowU = current_row - 1;             // Storing the desired row for moving up
    if (in_bounds(new_rowU, current_column)) {  // Making sure the movement is not out of bounds
        current_row = new_rowU;                 // Allows you to move up
    }
}

void Player::move_down() {
    int new_rowD = current_row + 1;             // Storing the desired row for moving down
    if (in_bounds(new_rowD, current_column)) {  // Making sure the movement is not out of bounds
        current_row = new_rowD;                 // Allows you to move down
    }
}

bool Player::in_bounds(int new_row, int new_column) {
    return (new_row >= 0 && new_row < 5 && new_column >= 0 && new_column < 5);
}