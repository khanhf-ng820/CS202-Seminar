#include <iostream>
#include <iomanip>
#include "Beverage.h"
#include "DarkRoast.h"
#include "Espresso.h"
#include "HouseBlend.h"
#include "Decaf.h"
#include "Milk.h"
#include "Mocha.h"
#include "Soy.h"
#include "Whip.h"

int main() {
    std::cout << "=== Coffee Shop Order System (Decorator Pattern) ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    // Order 1: Simple Espresso without condiments
    Beverage* drink1 = new Espresso();
    std::cout << "Order 1: " << drink1->getDescription() 
              << " | Total: $" << drink1->cost() << std::endl;
    delete drink1;

    // Order 2: Dark Roast with Milk and Mocha
    Beverage* drink2 = new DarkRoast();
    drink2 = new Milk(drink2);
    drink2 = new Mocha(drink2);
    std::cout << "Order 2: " << drink2->getDescription() 
              << " | Total: $" << drink2->cost() << std::endl;
    delete drink2;

    // Order 3: House Blend with Double Mocha and Whip
    Beverage* drink3 = new HouseBlend();
    drink3 = new Soy(drink3);
    drink3 = new Mocha(drink3);
    drink3 = new Mocha(drink3); // Double Mocha!
    drink3 = new Whip(drink3);
    std::cout << "Order 3: " << drink3->getDescription() 
              << " | Total: $" << drink3->cost() << std::endl;
    delete drink3;

    // Order 4: Decaf with Milk and Soy
    Beverage* drink4 = new Decaf();
    drink4 = new Milk(drink4);
    drink4 = new Soy(drink4);
    std::cout << "Order 4: " << drink4->getDescription() 
              << " | Total: $" << drink4->cost() << std::endl;
    delete drink4;

    std::cout << "\n[Decorator Advantages Demonstrated]:" << std::endl;
    std::cout << "- Condiments dynamically composed at runtime." << std::endl;
    std::cout << "- Easily supports multiple portions of the same topping (Double Mocha)." << std::endl;
    std::cout << "- Extensible: adding new beverages or toppings requires NO edits to existing classes (OCP compliant)." << std::endl;

    return 0;
}
