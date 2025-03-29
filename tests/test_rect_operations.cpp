#include <cassert>
#include "../src/rect.hpp"

int main() {
    Rect r(1, 3, 6, 2);

    r.move(2, 2);//shift by(2, 2)

    
    assert(r.get_left() == 3);
    assert(r.get_right() == 5);
    assert(r.get_top() == 8);
    assert(r.get_bottom() == 4);

    r.inflate(1);//expand by 1 on all sides
    assert(r.get_left() == 2);
    assert(r.get_right() == 6);
    assert(r.get_top() == 9);
    assert(r.get_bottom() == 3);

    return 0;
}
