#ifndef DVDPLAYER_H
#define DVDPLAYER_H

#include <string>
#include <iostream>

class DvdPlayer {
public:
    void on() { std::cout << "DVD Player: on\n"; }
    void off() { std::cout << "DVD Player: off\n"; }
    void play(const std::string& movie) {
        std::cout << "DVD Player: playing \"" << movie << "\"\n";
    }
    void stop() { std::cout << "DVD Player: stopped\n"; }
    void eject() { std::cout << "DVD Player: ejected\n"; }
};

#endif
