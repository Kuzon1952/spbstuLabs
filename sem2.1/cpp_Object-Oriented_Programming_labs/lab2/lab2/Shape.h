#ifndef SHAPE_H
#define SHAPE_H

// Forward declaration to break circular dependency
class Vector;

class Shape
{
protected:
    static int Count;
int x;

public:
    static Shape* shapes[1000];
    Shape();
    virtual ~Shape();
    
    // Use forward declared Vector
    virtual void Move(Vector& v) = 0;
    virtual void Out() const = 0;
    virtual double Area() const = 0;
    
    static void PrintCount();
    static int GetCount();

};

#endif // SHAPE_H