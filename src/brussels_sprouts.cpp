#include <string>

#include "brussels_sprouts.hpp"

std::string BrusselsSprouts::symbol() {
    if(age < sprout_age) {
        return "#"; // Seedling still; tilled soil
    } else if (age < mature_age) {
        return "bs"; // Sproutling
    } else {
        return "BS"; // Fully grown plant (harvestable)
    }
}

void BrusselsSprouts::end_day() {
    if (watered) {
        age += 2;
    } else {
        age += 1;
    }
    watered = false;
}

bool BrusselsSprouts::is_mature() {
    return age >= mature_age;
}

void BrusselsSprouts::water() {
    watered = true;
}

int BrusselsSprouts::get_age() {
    return age;
}