#ifndef NAVIGATOR_STRATEGY_H
#define NAVIGATOR_STRATEGY_H

#include "RouteStrategy.h"

// Context Class
class Navigator {
private:
    const RouteStrategy* strategy;

public:
    Navigator(const RouteStrategy* initialStrategy = nullptr) : strategy(initialStrategy) {}

    void setStrategy(const RouteStrategy* newStrategy) {
        strategy = newStrategy;
    }

    void buildRoute(const std::string& origin, const std::string& destination) const {
        std::cout << "Calculating route from " << origin << " to " << destination << "...\n";
        if (strategy) {
            strategy->buildRoute(origin, destination);
        } else {
            std::cout << " -> Error: No routing strategy set!\n";
        }
    }
};

#endif
