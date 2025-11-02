#ifndef BARREL_HPP
#define BARREL_HPP

#include <iostream>

class Barrel{
    private:
    double volume;
    double alcohol;

    public:
    //constructor
    Barrel(double v, double alc_percent);

    //getters
    double getAlcoholCeoncentration() const;
    double getVolume() const;
    double getAlcohol() const;

    //transfer function
    void transferFrom(Barrel &other, double amount);

};


#endif //BARREL_HPP