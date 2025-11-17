#include <string>

#include "lettuce.hpp"

std::string Lettuce::symbol() {
    if(age < sprout_age) {
        return "#"; // Seedling still; tilled soil
    } else if (age < mature_age) {
        return "t"; // Not mature yet
    } else {
        return "T"; // Fully grown plant (harvestable)
    }
}

void Lettuce::end_day() {
    age += 1;
}

bool Lettuce::is_mature() {
    return age >= mature_age;
}