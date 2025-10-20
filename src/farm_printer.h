#pragma once

class FarmPrinter {
private:
    Farm *farm; //We are storing a pointer to a farm

public:
    FarmPrinter(Farm *farm);
    std::string pp();
};