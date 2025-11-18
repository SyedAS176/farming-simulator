#include <string>

#include "carrot.hpp"

std::string Carrot::symbol() {
    if(age < sprout_age) {
        return "#"; // Seedling still; tilled soil
    } else if (age < mature_age) {
        return "c"; // Not mature yet
    } else {
        return "C"; // Fully grown plant (harvestable)
    }
}

void Carrot::end_day() {
    age += 1;
}

bool Carrot::is_mature() {
    return age >= mature_age;
}

bool Carrot::is_watered() {
    return age >= sprout_age;
}