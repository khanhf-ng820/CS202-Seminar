#include "Navigator.h"
#include "DrivingStrategy.h"
#include "WalkingStrategy.h"
#include "PublicTransitStrategy.h"
#include "BicyclingStrategy.h"

int main() {
    DrivingStrategy driving;
    WalkingStrategy walking;
    PublicTransitStrategy transit;
    BicyclingStrategy bicycling;

    // Context instantiated with initial strategy
    Navigator navigator(&driving);

    std::cout << "=== Strategy Pattern Navigation App ===\n\n";

    std::cout << "[Trip 1: Morning Commute by Car]\n";
    navigator.buildRoute("Home", "Downtown Office");

    std::cout << "\n[Trip 2: Lunch Break Walking]\n";
    navigator.setStrategy(&walking);
    navigator.buildRoute("Downtown Office", "City Park");

    std::cout << "\n[Trip 3: Evening Commute via Metro]\n";
    navigator.setStrategy(&transit);
    navigator.buildRoute("City Park", "Home");

    std::cout << "\n[Trip 4: Weekend Fitness Ride - New Strategy added without modifying Navigator!]\n";
    navigator.setStrategy(&bicycling);
    navigator.buildRoute("Home", "Riverside Bike Trail");

    return 0;
}
