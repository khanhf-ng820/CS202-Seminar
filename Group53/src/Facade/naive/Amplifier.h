#ifndef AMPLIFIER_H
#define AMPLIFIER_H

#include <string>
#include <iostream>

class Amplifier {
public:
    void on() { std::cout << "Amplifier: on\n"; }
    void off() { std::cout << "Amplifier: off\n"; }
    void setSource(const std::string& source) {
        std::cout << "Amplifier: source set to " << source << "\n";
    }
    void setVolume(int level) {
        std::cout << "Amplifier: volume set to " << level << "\n";
    }
};

#endif
