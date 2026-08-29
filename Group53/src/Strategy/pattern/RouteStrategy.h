#ifndef ROUTE_STRATEGY_H
#define ROUTE_STRATEGY_H

#include <string>
#include <iostream>

// Strategy Interface
class RouteStrategy {
public:
    virtual ~RouteStrategy() = default;
    virtual void buildRoute(const std::string& origin, const std::string& destination) const = 0;
};

#endif
