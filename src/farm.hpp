#pragma once

#include <string>
#include <vector>
#include "plot.h"

class Farm {
private:
    int rows;
    int columns;
    std::vector<std::vector<std::Plot *>> plots;

public:
    Farm(int rows, int columns);
    int number_of_rows();
    int number_of_columns();
    std::string get_symbol(int row, int column);
};