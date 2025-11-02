#ifndef POINT_HPP
#define POINT_HPP

#include <ostream>

class Point {
private:
    double m_x;
    double m_y;
public:
    //constructors
    Point();//(0,0)
    Point(double x, double y);       
    
    //getter and setter methods
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    
    //equality operator
    bool operator==(const Point& other) const;
    
    //output operator
    friend std::ostream& operator<<(std::ostream& os, const Point& pt);
};

#endif//POINT_HPP
