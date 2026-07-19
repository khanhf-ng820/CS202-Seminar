#ifndef BICYCLING_STRATEGY_H
#define BICYCLING_STRATEGY_H

#include "RouteStrategy.h"

class BicyclingStrategy : public RouteStrategy {
public:
    void buildRoute(const std::string& origin, const std::string& destination) const override {
        std::cout << " -> Mode: BICYCLING (Newly Added Strategy! - OCP Compliant)\n";
        std::cout << " -> Algorithm: Dedicated bike lanes, elevation elevation profile optimization & flat routes.\n";
        std::cout << " -> Estimated Time: 50 mins (17.1 km)\n";
    }
};

#endif
