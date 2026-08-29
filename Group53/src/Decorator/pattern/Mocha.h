#ifndef MOCHA_H
#define MOCHA_H

#include "CondimentDecorator.h"

// Concrete Decorator: Mocha
class Mocha : public CondimentDecorator {
public:
    Mocha(Beverage* bev) : CondimentDecorator(bev) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Mocha";
    }

    double cost() const override {
        return beverage->cost() + 8.0;
    }
};

#endif // MOCHA_H
