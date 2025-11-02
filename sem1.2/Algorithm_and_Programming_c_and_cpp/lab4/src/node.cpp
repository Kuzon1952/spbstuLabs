#include "node.hpp"

//default constructor
Node::Node() : pPrev(nullptr), pNext(nullptr), m_data() { }

//constructor prev and next
Node::Node(Node* prev, Node* next, const Circle& data) : pPrev(prev), pNext(next), m_data(data) {
    if (prev) prev->pNext = this;
    if (next) next->pPrev = this;
}

//destructor unlinks 
Node::~Node() {
    if (pPrev) pPrev->pNext = pNext;
    if (pNext) pNext->pPrev = pPrev;
   
}
