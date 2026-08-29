#ifndef HOUSEBLEND_H
#define HOUSEBLEND_H

#include "Beverage.h"

// Concrete Component: House Blend
class HouseBlend : public Beverage {
public:
    std::string getDescription() const override {
        return "House Blend Coffee";
    }

    double cost() const override {
        return 25.0;
    }
};

#endif // HOUSEBLEND_H
