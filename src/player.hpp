#pragma once

class Player {
private:
    int current_row = 0;
    int current_column = 0;

public:
    // Getter methods
    int row();
    int column();

    // Movement methods
    void move_right();
    void move_left();
    void move_up();
    void move_down();
};