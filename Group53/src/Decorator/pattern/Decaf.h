#ifndef DECAF_H
#define DECAF_H

#include "Beverage.h"

// Concrete Component: Decaf
class Decaf : public Beverage {
public:
    std::string getDescription() const override {
        return "Decaf Coffee";
    }

    double cost() const override {
        return 20.0;
    }
};

#endif // DECAF_H
