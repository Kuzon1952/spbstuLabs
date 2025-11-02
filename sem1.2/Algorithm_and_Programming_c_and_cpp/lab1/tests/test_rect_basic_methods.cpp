#include <cassert>
#include "../src/rect.hpp"//include the class i'm testesing

int main(){

    Rect r1;//test default constructor
    assert(r1.get_left() == 0);
    assert(r1.get_right() == 0);
    assert(r1.get_top() == 0);
    assert(r1.get_bottom() == 0);

    //constructor with vals
    Rect r2(1, 5, 10, 2);
    assert(r2.get_left() == 1);
    assert(r2.get_right() == 5);
    assert(r2.get_top() == 10);
    assert(r2.get_bottom() == 2);

    //test set_all method
    r2.set_all(3, 8, 12, 4);
    assert(r2.get_left() == 3);
    assert(r2.get_right() == 8);
    assert(r2.get_top() == 12);
    assert(r2.get_bottom() == 4);

    //alternate getter styles
    assert(r2.getLeft() == 3);
    assert(r2.getRight() == 8);
    assert(r2.getTop() == 12);
    assert(r2.getBottom() == 4);



    return 0;//all passed
}