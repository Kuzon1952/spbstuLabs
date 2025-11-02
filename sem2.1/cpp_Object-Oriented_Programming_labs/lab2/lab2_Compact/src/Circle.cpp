#include <iostream>
#include <cmath>
#include "Circle.h"

using namespace std;

Circle::Circle() : ptCntr(0, 0), R(0) {}

Circle::Circle(double centerX, double centerY, double radius)
    : ptCntr(centerX, centerY), R(radius) {}

Circle::~Circle() {}

void Circle::Move(Vector& v)
{
    ptCntr = ptCntr + v;
}

void Circle::Out() const
{
     cout << "\nCircle (center: " << ptCntr.GetX() << "," << ptCntr.GetY() << ", radius: " << R << ")";
}

double Circle::Area() const
{
    return M_PI * R * R;
}