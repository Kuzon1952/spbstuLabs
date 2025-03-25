//refactorized
#include "rect.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

Rect::Rect() : x(0), y(0), width(0), height(0){//default constructor explicitly initializing
    //cout<<"explicit constructor called "<<this<<endl;
    
};
	// TODO: migrate from (left, right, top, bottom) to (x, y, width, height) model
    // without changing anything public in rect and anything outside rect (e.g. your tests)
    // tests must still pass without changing them

Rect::Rect (int l, int r, int t, int b) {//constructor with parameters
    //cout<<"parameterized constructor called "<<this<<endl;
    x = l;//this->left=l;
    y = b; //this->right=r;
    width = r -l;//this->top=t;
    height = t -b;//this->bottom=b;
};

Rect::Rect(const Rect& other){//copy constructor
    //cout<<"copy constructor called "<<this<<endl;
    //left = other.left;
    //right = other.right;
    //top = other.top;
    //bottom = other.bottom;
    x = other.x;
    y = other.y;
    width = other.width;
    height = other.height;
    
};


Rect::~Rect(){//default destructor
    //cout<<"default destructor called "<<this<<endl;

};


//getter methods
int Rect::getLeft() const {return x;}//{return left;}
int Rect::getRight() const {return x + width;}//{ return right; }
int Rect::getTop() const {return y + height;}//{ return top; }
int Rect::getBottom() const {return y;}//{ return bottom; }

//getter methods
int Rect::get_left() const { return getLeft(); }//left
int Rect::get_right() const { return getRight(); }//right
int Rect::get_top() const { return getTop(); }//top
int Rect::get_bottom() const { return getBottom(); }//bottom

// Setters
void Rect::setLeft(int l) {
    int right = getRight();
    x = l;
    width = right - x;
}

void Rect::setRight(int r) {
    width = r - x;
}

void Rect::setTop(int t) {
    height = t - y;
}

void Rect::setBottom(int b) {
    int top = getTop();
    y = b;
    height = top - y;
}


//setter methods for all
void Rect::set_all(int l, int r, int t, int b){
    
    x = l;//left=l;
    y = b;//right=r;
    width = r - l;//top=t;
    height = t - b;//bottom=b;
   // cout<<"values updated thorugh setAll() "<<endl;
}

//overloading
void Rect::inflate(int amount){
    x -= amount;//left -= amount;
    y -= amount;//right += amount;
    width += 2 * amount;//top += amount;
    height += 2 * amount;//bottom -= amount;
    cout<<"rectangle inflated uniformly by "<<amount<<endl;
}

void Rect::inflate(int dw, int dh){
    x -= dw;//left -= dw;
    y -= dh;//right += dw;
    width += 2 * dw;//top += dh;
    height += 2 * dh;//bottom -= dh;
    cout<<"rectangle inflated by ("<<dw<<", "<<dh<<")"<<endl;
}

void Rect::inflate(int d_left, int d_right, int d_top, int d_bottom){
    x -= d_left;//left -= d_left;
    y -= d_bottom;//right += d_right;
    width += d_left + d_right;//top += d_top;
    height += d_top + d_bottom;//bottom -= d_bottom;
    cout<<"rectangle inflated by left: "<<d_left
        <<", right: "<<d_right
        <<", top: "<<d_top
        <<", bottom: "<<d_bottom<<endl;
}

void Rect::move(int dx, int dy){//move method with default vals
    x += dx;
    y += dy;
    //left += dx;
    //right += dx;
    //top += dy;
    //bottom += dy;
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
    return width;//right - left;
}

int Rect::get_height() const{
    return height;//top - bottom;
}

int Rect::get_square() const{
    return width*height; //get_width() * get_height();
}

void Rect::set_width(int new_width){
    if(new_width>0){
        width = new_width;//right = left + new_width;
        cout<<"width updated to "<<new_width<<endl;
    }
    else{
        cout<<"error: width must be +ve"<<endl;
    }
}

void Rect::set_heigth(int new_height){
    if(new_height>0){
        height = new_height;//top = bottom + new_height;
        cout<<"height updated to "<<new_height<<endl;
    }
    else{
        cout<<"error: width must be +ve"<<endl;
    }
}
