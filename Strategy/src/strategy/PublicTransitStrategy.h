#ifndef PUBLIC_TRANSIT_STRATEGY_H
#define PUBLIC_TRANSIT_STRATEGY_H

#include "RouteStrategy.h"

class PublicTransitStrategy : public RouteStrategy {
public:
    void buildRoute(const std::string& origin, const std::string& destination) const override {
        std::cout << " -> Mode: PUBLIC TRANSIT (Strategy Pattern)\n";
        std::cout << " -> Algorithm: Bus timetable sync, metro transfers & minimum walking distance.\n";
        std::cout << " -> Estimated Time: 45 mins (Bus #4 -> Line 2 Metro)\n";
    }
};

#endif
