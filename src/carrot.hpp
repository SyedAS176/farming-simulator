#pragma once

#include <string>

#include "plot.hpp"

class Carrot : public Plot {
private:
    int age = 0;
    int sprout_age = 1; // 1 day to sprout
    int mature_age = 2; // 1 day to maturity after sprout
    bool watered = false;

public:
    std::string symbol() override;
    void end_day() override;
    bool is_mature() override;
    void water() override;
    int get_age();
};