#ifndef CIRCLE_H
#define CIRCLE_H

// Include Shape first (base class)
#include "Shape.h"
// Then include Vector (used as member)
#include "MyVector.h"

class Circle : public Shape
{
private:
    Vector ptCntr;
    double R;

public:
    Circle();
    Circle(double centerX, double centerY, double radius);
    Circle(const Vector& center, double radius);
    ~Circle();
    
    void Move(Vector& v) override;
    void Out() const override;
    double Area() const override;
};

#endif // CIRCLE_H