#pragma once

#include <string>

#include "plot.hpp"

class Spinach : public Plot {
private:
    int age = 0;
    int sprout_age = 2; // 2 days to sprout
    int mature_age = 5; // 3 days to maturity after sprout
    bool watered = false;

public:
    std::string symbol() override;
    void end_day() override;
    bool is_mature() override;
    void water() override;
};