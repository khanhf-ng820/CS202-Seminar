#include "Amplifier.h"
#include "DvdPlayer.h"
#include "Projector.h"
#include "Screen.h"
#include "TheaterLights.h"

int main() {
    Amplifier amp;
    DvdPlayer dvd;
    Projector projector;
    Screen screen;
    TheaterLights lights;

    // Client must orchestrate every step manually
    lights.dim(20);
    screen.down();
    projector.on();
    projector.setInput("DVD");
    dvd.on();
    amp.on();
    amp.setSource("DVD");
    amp.setVolume(10);
    dvd.play("The Matrix");

    std::cout << "\n--- Movie is playing ---\n\n";

    // Client must undo everything manually
    dvd.stop();
    amp.off();
    dvd.off();
    projector.off();
    screen.up();
    lights.on();

    return 0;
}
