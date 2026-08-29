#ifndef SOY_H
#define SOY_H

#include "CondimentDecorator.h"

// Concrete Decorator: Soy
class Soy : public CondimentDecorator {
public:
    Soy(Beverage* bev) : CondimentDecorator(bev) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Soy";
    }

    double cost() const override {
        return beverage->cost() + 6.0;
    }
};

#endif // SOY_H
