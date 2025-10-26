#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if(age == 0) {
        return "v";
    } else {
        return "V";
    }
}

void Carrot::end_day() {
    age += 1;
}