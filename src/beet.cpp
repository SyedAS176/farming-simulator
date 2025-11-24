#include <string>

#include "beet.hpp"

std::string Beet::symbol() {
    if(age < sprout_age) {
        return "#"; // Seedling still; tilled soil
    } else if (age < mature_age) {
        return "b"; // Sproutling
    } else {
        return "B"; // Fully grown plant (harvestable)
    }
}

void Beet::end_day() {
    if (watered) {
        age += 2;
    } else {
        age += 1;
    }
    watered = false;
}

bool Beet::is_mature() {
    return age >= mature_age;
}

void Beet::water() {
    watered = true;
}

int Beet::get_age() {
    return age;
}