#include "Navigator.h"

int main() {
    Navigator navigator(TransportMode::DRIVING);

    std::cout << "=== Naive Navigation App ===\n\n";

    std::cout << "[Trip 1: Morning Commute]\n";
    navigator.buildRoute("Home", "Downtown Office");

    std::cout << "\n[Trip 2: Lunch Break Walk]\n";
    navigator.setMode(TransportMode::WALKING);
    navigator.buildRoute("Downtown Office", "City Park");

    std::cout << "\n[Trip 3: Evening Commute via Metro]\n";
    navigator.setMode(TransportMode::PUBLIC_TRANSIT);
    navigator.buildRoute("City Park", "Home");

    return 0;
}
