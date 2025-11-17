#pragma once

#include <string>

#include "plot.hpp"

class Lettuce : public Plot {
private:
    int age = 0;
    int sprout_age = 2;
    int mature_age = 4; // 2 days to maturity after sprout

public:
    std::string symbol() override;
    void end_day() override;
    bool is_mature() override;
};