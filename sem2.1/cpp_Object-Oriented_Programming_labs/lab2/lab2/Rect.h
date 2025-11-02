#ifndef RECT_H
#define RECT_H

// Include Shape first (base class)
#include "Shape.h"
// Then include Vector (used as member)
#include "MyVector.h"

class Rect : public Shape
{
private:
    Vector ptLT;
    Vector ptRB;

public:
    Rect();
    Rect(const Vector& topLeft, const Vector& bottomRight);
    Rect(double left, double top, double right, double bottom);
    ~Rect();
    
    // Override Shape virtual functions
    void Move(Vector& v) override;
    void Out() const override;
    double Area() const override;
    
    // Inflate methods
    void Inflate(double delta = 1.0);
    void Inflate(double deltaX, double deltaY);
    void Inflate(double left, double top, double right, double bottom);
};

#endif // RECT_H