#include <string>

#include "lettuce.hpp"

std::string Lettuce::symbol() {
    if(age < sprout_age) {
        return "#"; // Seedling still; tilled soil
    } else if (age < mature_age) {
        return "l"; // Sproutling
    } else {
        return "L"; // Fully grown plant (harvestable)
    }
}

void Lettuce::end_day() {
    if (watered) {
        age += 2;
    } else {
        age += 1;
    }
    watered = false;
}

bool Lettuce::is_mature() {
    return age >= mature_age;
}

void Lettuce::water() {
    watered = true;
}