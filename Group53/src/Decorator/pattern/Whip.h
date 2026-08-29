#ifndef WHIP_H
#define WHIP_H

#include "CondimentDecorator.h"

// Concrete Decorator: Whip
class Whip : public CondimentDecorator {
public:
    Whip(Beverage* bev) : CondimentDecorator(bev) {}

    std::string getDescription() const override {
        return beverage->getDescription() + ", Whip";
    }

    double cost() const override {
        return beverage->cost() + 4.0;
    }
};

#endif // WHIP_H
