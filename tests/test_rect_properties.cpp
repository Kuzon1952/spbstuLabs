#include <cassert>
#include "../src/rect.hpp"

int main() {
    Rect r(2, 6, 12, 4);//width =4,height= 8

    assert(r.get_width() == 4);
    assert(r.get_height() == 8);
    assert(r.get_square() == 32);

    r.set_width(10);//sets right = left + 10 -> 2 + 10 = 12
    assert(r.get_width() == 10);
    assert(r.get_right() == 12);

    r.set_heigth(6);//sets top = bottom + 6 -> 4 + 6 = 10
    assert(r.get_height() == 6);
    assert(r.get_top() == 10);

    return 0;
}
