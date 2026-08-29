#ifndef ESPRESSO_H
#define ESPRESSO_H

#include "Beverage.h"

// Concrete Component: Espresso
class Espresso : public Beverage {
public:
    std::string getDescription() const override {
        return "Espresso";
    }

    double cost() const override {
        return 35.0;
    }
};

#endif // ESPRESSO_H
