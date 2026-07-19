#ifndef WALKING_STRATEGY_H
#define WALKING_STRATEGY_H

#include "RouteStrategy.h"

class WalkingStrategy : public RouteStrategy {
public:
    void buildRoute(const std::string& origin, const std::string& destination) const override {
        std::cout << " -> Mode: WALKING (Strategy Pattern)\n";
        std::cout << " -> Algorithm: Pedestrian footpaths, crosswalk safety & park shortcuts.\n";
        std::cout << " -> Estimated Time: 3 hours 40 mins (16.2 km)\n";
    }
};

#endif
