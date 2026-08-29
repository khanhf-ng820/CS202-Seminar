#ifndef BEVERAGE_H
#define BEVERAGE_H

#include <iostream>
#include <string>

enum class BeverageType {
    DARK_ROAST,
    ESPRESSO,
    HOUSE_BLEND,
    DECAF
};

class Beverage {
private:
    BeverageType type;
    std::string description;
    bool milk;
    bool soy;
    bool mocha;
    bool whip;

public:
    Beverage(BeverageType t = BeverageType::HOUSE_BLEND)
        : type(t), milk(false), soy(false), mocha(false), whip(false) {
        switch (type) {
            case BeverageType::DARK_ROAST:
                description = "Dark Roast Coffee";
                break;
            case BeverageType::ESPRESSO:
                description = "Espresso";
                break;
            case BeverageType::HOUSE_BLEND:
                description = "House Blend Coffee";
                break;
            case BeverageType::DECAF:
                description = "Decaf Coffee";
                break;
        }
    }

    std::string getDescription() const {
        std::string desc = description;
        if (milk)  desc += ", Milk";
        if (soy)   desc += ", Soy";
        if (mocha) desc += ", Mocha";
        if (whip)  desc += ", Whip";
        return desc;
    }

    void setMilk(bool m)   { milk = m; }
    void setSoy(bool s)    { soy = s; }
    void setMocha(bool m)  { mocha = m; }
    void setWhip(bool w)   { whip = w; }

    bool hasMilk() const  { return milk; }
    bool hasSoy() const   { return soy; }
    bool hasMocha() const { return mocha; }
    bool hasWhip() const  { return whip; }

    double cost() const {
        double totalCost = 0.0;
        switch (type) {
            case BeverageType::DARK_ROAST:
                totalCost = 30.0;
                break;
            case BeverageType::ESPRESSO:
                totalCost = 35.0;
                break;
            case BeverageType::HOUSE_BLEND:
                totalCost = 25.0;
                break;
            case BeverageType::DECAF:
                totalCost = 20.0;
                break;
        }

        if (hasMilk())  totalCost += 5.0;
        if (hasSoy())   totalCost += 6.0;
        if (hasMocha()) totalCost += 8.0;
        if (hasWhip())  totalCost += 4.0;

        return totalCost;
    }
};

#endif // BEVERAGE_H
