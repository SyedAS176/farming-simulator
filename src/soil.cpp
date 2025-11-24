#include "soil.hpp"

std::string Soil::symbol() {
    return ".";
}

void Soil::end_day() {
    // no-op
}

bool Soil::is_mature() {
    return false; // Soil is never harvestable
}

void water() {
    // no-op
}