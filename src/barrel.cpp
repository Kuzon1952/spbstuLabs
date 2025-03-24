#include "barrel.hpp"
#include <iostream>

using namespace std;

Barrel::Barrel(double v, double alc_percent):volume(v){
    alcohol = (alc_percent/100.0) * volume;//cvt % to liters

}

double Barrel::getAlcoholCeoncentration() const {
    return (alcohol/volume) * 100.0;
}

double Barrel::getVolume() const {
    return volume;
}

double Barrel::getAlcohol() const {
    return alcohol;
}

void Barrel::transferFrom(Barrel &other, double amount){
    if(amount>other.volume){
        amount=other.volume;//cant transfer
    }
    double alcoholTransferred= (other.alcohol/other.volume)*amount;//calculation of transferred alc

    other.alcohol -= alcoholTransferred;//update both barrels
    other.volume -= amount;

    this->alcohol += alcoholTransferred;
    this->volume += amount;
}
