#ifndef DARKROAST_H
#define DARKROAST_H

#include "Beverage.h"

// Concrete Component: Dark Roast
class DarkRoast : public Beverage {
public:
    std::string getDescription() const override {
        return "Dark Roast Coffee";
    }

    double cost() const override {
        return 30.0;
    }
};

#endif // DARKROAST_H
