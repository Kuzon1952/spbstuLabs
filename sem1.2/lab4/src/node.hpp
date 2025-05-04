#ifndef NODE_HPP
#define NODE_HPP

#include "circle.hpp"
#include <cstddef>

class List;//friendship

class Node {
    friend class List;
private:
    Node* pPrev;
    Node* pNext;
    Circle m_data;
public:
    Node(); 
    Node(Node* prev, Node* next, const Circle& data);
    ~Node();
};

#endif // NODE_HPP
