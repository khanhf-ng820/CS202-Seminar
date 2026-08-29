#include <iostream>
#include <iomanip>
#include "Beverage.h"

int main() {
    std::cout << "=== Coffee Shop Order System (Naive: Boolean Flags) ===" << std::endl;
    std::cout << std::fixed << std::setprecision(2);

    // Order 1: Simple Espresso
    Beverage order1(BeverageType::ESPRESSO);
    std::cout << "Order 1: " << order1.getDescription() 
              << " | Total: $" << order1.cost() << std::endl;

    // Order 2: Dark Roast with Milk and Mocha
    Beverage order2(BeverageType::DARK_ROAST);
    order2.setMilk(true);
    order2.setMocha(true);
    std::cout << "Order 2: " << order2.getDescription() 
              << " | Total: $" << order2.cost() << std::endl;

    // Order 3: House Blend with all toppings
    Beverage order3(BeverageType::HOUSE_BLEND);
    order3.setMilk(true);
    order3.setSoy(true);
    order3.setMocha(true);
    order3.setWhip(true);
    std::cout << "Order 3: " << order3.getDescription() 
              << " | Total: $" << order3.cost() << std::endl;

    std::cout << "\n[Problems with naive approach]:" << std::endl;
    std::cout << "- Cannot have double mocha (boolean flag is only true/false)." << std::endl;
    std::cout << "- Adding new condiments requires modifying Beverage base class (violates OCP)." << std::endl;
    std::cout << "- Tea or iced drinks would inherit irrelevant condiment flags (whip, mocha)." << std::endl;

    return 0;
}
