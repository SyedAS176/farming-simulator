#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if(age < mature_age) {
        return "v"; // Not mature yet
    } else {
        return "V"; // Fully grown plant (harvestable)
    }
}

void Carrot::end_day() {
    age += 1;
}

bool Carrot::is_mature() {
    return age >= mature_age;
}