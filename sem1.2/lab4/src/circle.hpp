#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "point.hpp"
#include <ostream>
#include <istream>

class Circle {
private:
    Point m_center;
    double m_radius;
public:
    static constexpr double PI = 3.141592653589793;
    
    //constructors
    Circle();                                   
    Circle(double x, double y, double r);       
    Circle(const Point& center, double r);
    
    //getter and setter methods
    double getRadius() const;
    void setRadius(double r);
    Point getCenter() const;
    void setCenter(const Point& center);
    
    //calculating area
    double area() const;
    
    //equality operator
    bool operator==(const Circle& other) const;
    
    //output and input operators
    friend std::ostream& operator<<(std::ostream& os, const Circle& c);
    friend std::istream& operator>>(std::istream& is, Circle& c);
};

#endif//CIRCLE_HPP
