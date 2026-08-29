#ifndef MILK_H
#define MILK_H

#include "CondimentDecorator.h"

// Concrete Decorator: Milk
class Milk : public CondimentDecorator {
public:
    Milk(Beverage* bev) : CondimentDecorator(bev) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Milk";
    }

    double cost() const override {
        return beverage->cost() + 5.0;
    }
};

#endif // MILK_H
