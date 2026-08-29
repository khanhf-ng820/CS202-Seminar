#ifndef PROJECTOR_H
#define PROJECTOR_H

#include <iostream>

class Projector {
public:
    void on() { std::cout << "Projector: on\n"; }
    void off() { std::cout << "Projector: off\n"; }
    void setInput(const std::string& source) {
        std::cout << "Projector: input set to " << source << "\n";
    }
};

#endif
