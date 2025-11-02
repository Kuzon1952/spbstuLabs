#ifndef MYVECTOR_H
#define MYVECTOR_H

// Include Shape first since Vector inherits from it
#include "Shape.h"

class Vector : public Shape
{
private:
    double x, y;

public:
    Vector(double c1, double c2);
    Vector();
    Vector(const Vector& other);
    ~Vector();
    
    // Override Shape virtual functions
    void Move(Vector& v) override;
    void Out() const override;
    double Area() const override;
    
    // Original Vector operations
    Vector operator+(const Vector& other) const;
    Vector& operator=(const Vector& v);
    double operator!() const;
    bool operator>(const Vector& other) const;
    bool operator==(const Vector& other) const;
    

    Vector operator*(double scalar) const;
    double operator*(const Vector& other) const;
    
    double GetX() const { return x; }
    double GetY() const { return y; }
};
     Vector operator*(double scalar, const Vector& v);

#endif // MYVECTOR_H