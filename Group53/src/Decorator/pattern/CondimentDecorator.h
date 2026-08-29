#ifndef CONDIMENT_DECORATOR_H
#define CONDIMENT_DECORATOR_H

#include "Beverage.h"

// Base Decorator
class CondimentDecorator : public Beverage {
protected:
    Beverage* beverage;

public:
    CondimentDecorator(Beverage* bev) : beverage(bev) {}

    virtual ~CondimentDecorator() {
        delete beverage;
    }
};

#endif // CONDIMENT_DECORATOR_H
