#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if(age < sprout_age) {
        return "#"; // Seedling still; tilled soil
    } else if (age < mature_age) {
        return "c"; // Sproutling
    } else {
        return "C"; // Fully grown plant (harvestable)
    }
}

void Carrot::end_day() {
    if (watered) {
        age += 2;
    } else {
        age += 1;
    }
    watered = false;
}

bool Carrot::is_mature() {
    return age >= mature_age;
}

void Carrot::water() {
    watered = true;
}

int Carrot::get_age() {
    return age;
}