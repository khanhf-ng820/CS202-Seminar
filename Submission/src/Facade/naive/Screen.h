#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>

class Screen {
public:
    void down() { std::cout << "Screen: lowered\n"; }
    void up() { std::cout << "Screen: raised\n"; }
};

#endif
