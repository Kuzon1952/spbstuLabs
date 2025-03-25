//refactorized
#include "rect.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Rect::Rect(): left(0),right(0),top(0),bottom(0){//default constructor explicitly initializing
    //cout<<"explicit constructor called "<<this<<endl;
    
};

Rect::Rect (int l, int r, int t, int b) {//constructor with parameters
    //cout<<"parameterized constructor called "<<this<<endl;
    this->left=l;
    this->right=r;
    this->top=t;
    this->bottom=b;
};

Rect::Rect(const Rect& other){//copy constructor
    //cout<<"copy constructor called "<<this<<endl;
    left = other.left;
    right = other.right;
    top = other.top;
    bottom = other.bottom;
    
};


Rect::~Rect(){//default destructor
    //cout<<"default destructor called "<<this<<endl;

};


//getter methods
int Rect::getLeft() const {return left;}
int Rect::getRight() const { return right; }
int Rect::getTop() const { return top; }
int Rect::getBottom() const { return bottom; }

//setter methods
void Rect::setLeft(int l) {left = l;}
void Rect::setRight(int r) { right = r; }
void Rect::setTop(int t) { top = t; }
void Rect::setBottom(int b) { bottom = b; }


//setter methods for all
void Rect::set_all(int l, int r, int t, int b){
    left=l;
    right=r;
    top=t;
    bottom=b;
   // cout<<"values updated thorugh setAll() "<<endl;
}

//overloading
void Rect::inflate(int amount){
    left -= amount;
    right += amount;
    top += amount;
    bottom -= amount;
    cout<<"rectangle inflated uniformly by "<<amount<<endl;
}

void Rect::inflate(int dw, int dh){
    left -= dw;
    right += dw;
    top += dh;
    bottom -= dh;
    cout<<"rectangle inflated by ("<<dw<<", "<<dh<<")"<<endl;
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom){
    left -= d_left;
    right += d_right;
    top += d_top;
    bottom -= d_bottom;
    cout<<"rectangle inflated by left: "<<d_left
        <<", right: "<<d_right
        <<", top: "<<d_top
        <<", bottom: "<<d_bottom<<endl;
}

void Rect::move(int dx, int dy){//move method with default vals
    left += dx;
    right += dx;
    top += dy;
    bottom += dy;
    cout<<"rectangle moved by ("<<dx <<", "<<dy<<")"<<endl;
}

//function to return the bounding rectangle of two rectangles
Rect bounding_rect(Rect r1, Rect r2){
    //cout<<"function boinding_rect called"<<endl;

    int new_left = (r1.get_left() < r2.get_left()) ? r1.get_left():r2.get_left();
    int new_right = (r1.get_right() < r2.get_right()) ? r1.get_right():r2.get_right();
    int new_top = (r1.get_top() < r2.get_top()) ? r1.get_top():r2.get_top();
    int new_bottom = (r1.get_bottom() < r2.get_bottom()) ? r1.get_bottom():r2.get_bottom();

    return Rect(new_left, new_right, new_top, new_bottom);

}

void print_rect(const Rect &r){
    cout<<"rectangle : \nLeft="<<r.get_left()<<", right="<<r.get_right()<<", top="<<r.get_top()<<", bottom="<<r.get_bottom()<<endl;


}

int Rect::get_width() const{
    return right - left;
}

int Rect::get_height() const{
    return top - bottom;
}

int Rect::get_square() const{
    return get_width() * get_height();
}

void Rect::set_width(int new_width){
    if(new_width>0){
        right = left + new_width;
        cout<<"width updated to "<<new_width<<endl;
    }
    else{
        cout<<"error: width must be +ve"<<endl;
    }
}

void Rect::set_heigth(int new_height){
    if(new_height>0){
        top = bottom + new_height;
        cout<<"height updated to "<<new_height<<endl;
    }
    else{
        cout<<"error: width must be +ve"<<endl;
    }
}
