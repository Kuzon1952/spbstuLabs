#include "circle.hpp"

//default constructor
Circle::Circle() : m_center(Point(0.0, 0.0)), m_radius(0.0) { }

//parameterized constructor
Circle::Circle(double x, double y, double r) : m_center(Point(x, y)), m_radius(r) { }

// .. with Point center
Circle::Circle(const Point& center, double r) : m_center(center), m_radius(r) { }

//getter and setter methods
double Circle::getRadius() const {
     return m_radius; }

void Circle::setRadius(double r) {
         m_radius = r; }

Point Circle::getCenter() const {
     return m_center; }

void Circle::setCenter(const Point& center) {
     m_center = center; }

//compute area
double Circle::area() const {
    return PI * m_radius * m_radius;
}

//compares center and radius
bool Circle::operator==(const Circle& other) const {
    return m_radius == other.m_radius && m_center == other.m_center;
}

//output 
std::ostream& operator<<(std::ostream& os, const Circle& c) {
    os << "circle (center = " << c.m_center << ", radius = " << c.m_radius 
       << ", area=" << c.area() << ")";
    return os;
}

//format: x y radius
std::istream& operator>>(std::istream& is, Circle& c) {
    double x, y, r;
    if (!(is >> x >> y >> r)) {
        return is;
    }
    c.m_center = Point(x, y);//x,y for center 
    c.m_radius = r;//for radi
    return is;
}
