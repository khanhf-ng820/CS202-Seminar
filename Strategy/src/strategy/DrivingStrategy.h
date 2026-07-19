#ifndef DRIVING_STRATEGY_H
#define DRIVING_STRATEGY_H

#include "RouteStrategy.h"

class DrivingStrategy : public RouteStrategy {
public:
    void buildRoute(const std::string& origin, const std::string& destination) const override {
        std::cout << " -> Mode: DRIVING (Strategy Pattern)\n";
        std::cout << " -> Algorithm: Highway priority, real-time traffic bypass & toll roads.\n";
        std::cout << " -> Estimated Time: 25 mins (18.5 km)\n";
    }
};

#endif
