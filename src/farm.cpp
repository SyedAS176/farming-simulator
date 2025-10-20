#include <string>
#include <vector>

#include "farm.hpp"
#include "soil.h"
#include "plot.h"

Farm::Farm(int rows, int columns) : rows(rows), columns(columns) {
    for(int i = 0; i < rows; i++) {
        std::vector<std::<Plot *> row;
        for(int j = 0; j < columns; j++) {
            Soil *soil = new Soil(); //Creating on the heap
            row.push_back(soil);
        }
        plots.push_back(row);
    }
}

int Farm::number_of_rows() {
    return rows;
}

int Farm::number_of_columns() {
    return columns;
}

std::string Farm::get_symbol(int row, int column) {
    return plots.at(row).at(column)->symbol();
}