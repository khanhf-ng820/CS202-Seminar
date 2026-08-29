#ifndef THEATERLIGHTS_H
#define THEATERLIGHTS_H

#include <iostream>

class TheaterLights {
public:
    void dim(int level) {
        std::cout << "Theater Lights: dimmed to " << level << "%\n";
    }
    void on() { std::cout << "Theater Lights: on\n"; }
};

#endif
