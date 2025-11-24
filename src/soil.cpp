#include "soil.hpp"

std::string Soil::symbol() {
    return ".";
}

void Soil::end_day() {
    // no-op
}

bool Soil::is_mature() {
    return false; // Soil is never harvestable therefore cannot become mature
}

void water() {
    // no-op
}