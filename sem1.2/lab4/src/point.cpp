#include "point.hpp"

//default constructor
Point::Point() : m_x(0.0), m_y(0.0) { }

//parameterized constructor
Point::Point(double x, double y) : m_x(x), m_y(y) { }

//getter and setter methods
double Point::getX() const { return m_x; }
double Point::getY() const { return m_y; }

void Point::setX(double x) { m_x = x; }
void Point::setY(double y) { m_y = y; }

//equality operator
bool Point::operator==(const Point& other) const {
    return (m_x == other.m_x && m_y == other.m_y);
}

//output operator for Point
std::ostream& operator<<(std::ostream& os, const Point& pt) {
    os << "(" << pt.m_x << ", " << pt.m_y << ")";
    return os;
}
