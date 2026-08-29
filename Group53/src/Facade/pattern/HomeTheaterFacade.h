#ifndef HOMETHEATERFACADE_H
#define HOMETHEATERFACADE_H

#include "Amplifier.h"
#include "DvdPlayer.h"
#include "Projector.h"
#include "Screen.h"
#include "TheaterLights.h"

class HomeTheaterFacade {
private:
    Amplifier& amp;
    DvdPlayer& dvd;
    Projector& projector;
    Screen& screen;
    TheaterLights& lights;

public:
    HomeTheaterFacade(Amplifier& a, DvdPlayer& d, Projector& p, Screen& s, TheaterLights& l)
        : amp(a), dvd(d), projector(p), screen(s), lights(l) {}

    void watchMovie(const std::string& movie) {
        lights.dim(20);
        screen.down();
        projector.on();
        projector.setInput("DVD");
        dvd.on();
        amp.on();
        amp.setSource("DVD");
        amp.setVolume(10);
        dvd.play(movie);
    }

    void endMovie() {
        dvd.stop();
        amp.off();
        dvd.off();
        projector.off();
        screen.up();
        lights.on();
    }
};

#endif
