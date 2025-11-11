#pragma once

#include <string>

#include "plot.hpp"

class Carrot : public Plot {
private:
    int age = 0;
    int mature_age = 1;
    bool is_watered = false;

public:
    std::string symbol() override;
    void end_day() override;
    bool is_mature() override;
    int get_age();
    void water();
};