#ifndef NAVIGATOR_NAIVE_H
#define NAVIGATOR_NAIVE_H

#include <iostream>
#include <string>

enum class TransportMode {
    DRIVING,
    WALKING,
    PUBLIC_TRANSIT
};

class Navigator {
private:
    TransportMode mode;

public:
    Navigator(TransportMode m = TransportMode::DRIVING) : mode(m) {}

    void setMode(TransportMode m) {
        mode = m;
    }

    void buildRoute(const std::string& origin, const std::string& destination) {
        std::cout << "Calculating route from " << origin << " to " << destination << "...\n";
        
        if (mode == TransportMode::DRIVING) {
            std::cout << " -> Mode: DRIVING\n";
            std::cout << " -> Finding fastest highway route & avoiding toll booth queues.\n";
            std::cout << " -> Estimated Time: 25 mins (18.5 km)\n";
        } 
        else if (mode == TransportMode::WALKING) {
            std::cout << " -> Mode: WALKING\n";
            std::cout << " -> Finding pedestrian footpaths, crosswalks & park shortcuts.\n";
            std::cout << " -> Estimated Time: 3 hours 40 mins (16.2 km)\n";
        } 
        else if (mode == TransportMode::PUBLIC_TRANSIT) {
            std::cout << " -> Mode: PUBLIC TRANSIT\n";
            std::cout << " -> Checking bus schedules, subway transfers & train lines.\n";
            std::cout << " -> Estimated Time: 45 mins (Bus #4 -> Line 2 Metro)\n";
        } 
        else {
            std::cout << " -> Error: Unknown transport mode!\n";
        }
    }
};

#endif
