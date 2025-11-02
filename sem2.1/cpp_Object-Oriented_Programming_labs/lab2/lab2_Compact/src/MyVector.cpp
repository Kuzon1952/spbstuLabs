#include <iostream>
#include <cmath>
#include <limits>
#include <cfloat>
#include "MyVector.h"

using namespace std;

Vector::Vector(double c1, double c2) : x(c1), y(c2) {}

Vector::Vector() : x(0), y(0) {}

Vector::Vector(const Vector& other) : x(other.x), y(other.y) {}

Vector::~Vector() {}

void Vector::Move(Vector& v)
{
    x += v.x;
    y += v.y;
}

void Vector::Out() const
{
    cout << "\nVector (" << x << "," << y << ")";
}

double Vector::Area() const
{
    return 0.0;
}

// ... rest of Vector methods remain the same ...
Vector Vector::operator+(const Vector& other) const
{
    return Vector(x + other.x, y + other.y);
}

Vector& Vector::operator=(const Vector& v)
{
    if (this == &v)
        return *this;
        
    x = v.x;
    y = v.y;
    return *this;
}

double Vector::operator!() const
{
    return sqrt(x * x + y * y);
}

bool Vector::operator>(const Vector& other) const
{
    return (!(*this)) > (!other);
}

bool Vector::operator==(const Vector& other) const
{
    return (fabs(x - other.x) < DBL_EPSILON) && 
           (fabs(y - other.y) < DBL_EPSILON);
}

Vector Vector::operator*(double scalar) const
{
    return Vector(x * scalar, y * scalar);
}

Vector operator*(double scalar, const Vector& v)
{
    return v * scalar;
}

double Vector::operator*(const Vector& other) const
{
    return x * other.x + y * other.y;
}