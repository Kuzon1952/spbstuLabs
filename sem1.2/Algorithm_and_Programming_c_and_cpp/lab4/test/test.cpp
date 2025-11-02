#include "../src/list.hpp"
#include <iostream>

using namespace std;

bool testPushBackAndFront() {
    List list;
    Circle c1(Point(0,0), 1.0); 
    Circle c2(Point(1,1), 2.0); 
    
    //empty list
    cout << "initial list is empty:" << endl;
    cout << list << endl;

    list.push_back(c1);//add c1 to the back
    cout << "after push_back(c1):" << endl;
    cout << list << endl;//print 

    list.push_front(c2);//add c2 to the front
    cout << "after push_front(c2):" << endl;
    cout << list << endl;//print

    //checking size is 2
    if (list.size() == 2) {
        cout << "test passed...! (list size = 2)" << endl;
        return true;
    } else {
        cout << "test failed...! (expected size = 2, got size = " << list.size() << ")" << std::endl;
        return false;
    }
}

int main() {
    bool result = testPushBackAndFront();
    
    if (result) {
        cout << "test passed...!" << std::endl;
    } else {
        cout << "test failed...!" << std::endl;
    }

    return 0;
}
