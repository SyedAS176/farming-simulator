#include <string>

#include "spinach.hpp"

std::string Spinach::symbol() {
    if(age < sprout_age) {
        return "#"; // Seedling still; tilled soil
    } else if (age < mature_age) {
        return "s"; // Sproutling
    } else {
        return "S"; // Fully grown plant (harvestable)
    }
}

void Spinach::end_day() {
    if (watered) {
        age += 2;
    } else {
        age += 1;
    }
    watered = false;
}

bool Spinach::is_mature() {
    return age >= mature_age;
}

void Spinach::water() {
    watered = true;
}