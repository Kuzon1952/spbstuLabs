#include <iostream>
#include <cassert>
#include "../src/rect.hpp"

using namespace std;

int main() {
    
    Rect r1(2, 6, 9, 4);//l=2, r=6, t=9, b=4
    Rect r2(3, 7, 10, 5);//l=3, r=7, t=10, b=5

    //calling bounding_rect function
    Rect result = bounding_rect(r1, r2);

    //expecting smallest left, smallest bottom, smallest right, smallest top
    assert(result.get_left() == 2);
    assert(result.get_right() == 6);     
    assert(result.get_top() == 9);       
    assert(result.get_bottom() == 4);

    cout << "bounding_rect test passed...!"<<endl;
    return 0;
}
