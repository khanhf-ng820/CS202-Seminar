#include "HomeTheaterFacade.h"

int main() {
    Amplifier amp;
    DvdPlayer dvd;
    Projector projector;
    Screen screen;
    TheaterLights lights;

    HomeTheaterFacade facade(amp, dvd, projector, screen, lights);

    facade.watchMovie("The Matrix");
    std::cout << "\n--- Movie is playing ---\n\n";
    facade.endMovie();

    return 0;
}
