#include <iostream>
#include "Rect.h"

using namespace std;

Rect::Rect() : ptLT(0, 0), ptRB(0, 0) {}

Rect::Rect(const Vector& topLeft, const Vector& bottomRight) 
    : ptLT(topLeft), ptRB(bottomRight) {}

Rect::Rect(double left, double top, double right, double bottom)
    : ptLT(left, top), ptRB(right, bottom) {}

Rect::~Rect() {}

void Rect::Move(Vector& v)
{
    ptLT = ptLT + v;
    ptRB = ptRB + v;
}

void Rect::Out() const
{
    cout << "\nRect (" << ptLT.GetX() << "," << ptLT.GetY() << "," << ptRB.GetX() << "," << ptRB.GetY() << ")";
}

double Rect::Area() const
{
    double width = ptRB.GetX() - ptLT.GetX();
    double height = ptRB.GetY() - ptLT.GetY();
    return width * height;
}

void Rect::Inflate(double delta)
{
    ptLT = Vector(ptLT.GetX() - delta, ptLT.GetY() - delta);
    ptRB = Vector(ptRB.GetX() + delta, ptRB.GetY() + delta);
}

void Rect::Inflate(double deltaX, double deltaY)
{
    ptLT = Vector(ptLT.GetX() - deltaX, ptLT.GetY() - deltaY);
    ptRB = Vector(ptRB.GetX() + deltaX, ptRB.GetY() + deltaY);
}

void Rect::Inflate(double left, double top, double right, double bottom)
{
    ptLT = Vector(ptLT.GetX() - left, ptLT.GetY() - top);
    ptRB = Vector(ptRB.GetX() + right, ptRB.GetY() + bottom);
}