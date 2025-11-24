#pragma once

#include <string>

#include "plot.hpp"

class BrusselsSprouts : public Plot {
private:
    int age = 0;
    int sprout_age = 5; // 2 days to sprout
    int mature_age = 15; // 10 days to maturity after sprout
    bool watered = false;

public:
    std::string symbol() override;
    void end_day() override;
    bool is_mature() override;
    void water() override;
};