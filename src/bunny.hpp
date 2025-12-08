#pragma once

class Bunny {
private:
    int current_row = 0;
    int current_column = 1;
    bool scared = false;

public:
    // Constructor
    Bunny(int start_row, int start_column);

    // Accessor Methods
    int get_current_row();
    int get_current_column();

    // Mutator methods
    void set_position(int new_row, int new_column);
};