#include "list.hpp"
#include <utility>//for std::swap
#include <fstream>

//list constructor
List::List() : m_size(0) {//head and tails with empty list
    
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    Head.pPrev = nullptr;
    Tail.pNext = nullptr;
}

//destructor
List::~List() {
    clear();// clear all nodes and reset list
    
}

//add element to the front
void List::push_front(const Circle& value) {
    //new node after Head
    new Node(&Head, Head.pNext, value);
    m_size++;
}

//add elements to tail 
void List::push_back(const Circle& value) {
    //new node before tail
    new Node(Tail.pPrev, &Tail, value);
    m_size++;
}

//remove the first occurrence of a Circle equal to value
bool List::removeFirst(const Circle& value) {
    Node* current = Head.pNext;
    while (current != &Tail) {
        if (current->m_data == value) {
            //found a match and remove this node
            Node* toDelete = current;
            current = current->pNext;
            delete toDelete;
            m_size--;
            return true;
        }
        current = current->pNext;
    }
    return false;//not found
}

//remove all occurrences of a Circle equal to value
int List::removeAll(const Circle& value) {
    int count = 0;
    Node* current = Head.pNext;
    while (current != &Tail) {
        if (current->m_data == value) {
            Node* toDelete = current;
            current = current->pNext;
            delete toDelete;
            m_size--;
            count++;
            continue;
        }
        current = current->pNext;
    }
    return count;
}

//clear list
void List::clear() {
    Node* current = Head.pNext;
    while (current != &Tail) {
        Node* toDelete = current;
        current = current->pNext;
        delete toDelete;
        m_size--;
    }
    //after loop, Head.next is Tail, Tail.prev is Head 
    Head.pNext = &Tail;
    Tail.pPrev = &Head;
    m_size = 0;
}

//check if list is emty
bool List::isEmpty() const {
    return m_size == 0;
}

//get the number of elements in the list
std::size_t List::size() const {
    return m_size;
}

//get first ele
Circle List::front() const {
    if (isEmpty()) {
        return Circle();
    }
    return Head.pNext->m_data;
}

//get last ele
Circle List::back() const {
    if (isEmpty()) {
        return Circle();
    }
    return Tail.pPrev->m_data;
}

//sorting by area
void List::sortByArea() {//bubble sort alm.
    if (isEmpty() || Head.pNext->pNext == &Tail) {
        //zero or one element, nothing to sort
        return;
    }
    bool swapped;
    do {
        swapped = false;
        Node* current = Head.pNext;
        while (current->pNext != &Tail) {
            Node* nextNode = current->pNext;
            if (current->m_data.area() > nextNode->m_data.area()) {
                std::swap(current->m_data, nextNode->m_data);
                swapped = true;
            }
            current = nextNode;
        }
    } while (swapped);
}

//output the list to stream 
void List::display(std::ostream& os) const {
    Node* current = Head.pNext;
    while (current != &Tail) {
        os << current->m_data;
        if (current->pNext != &Tail) {
            os << std::endl;
        }
        current = current->pNext;
    }
}

//read circles from stream into list
void List::readFromStream(std::istream& is) {
    clear();
    Circle temp;
    while (is >> temp) {
        push_back(temp);
    }
}

//output operator for List
std::ostream& operator<<(std::ostream& os, const List& list) {
    list.display(os);
    return os;
}

//input operator for List
std::istream& operator>>(std::istream& is, List& list) {
    list.readFromStream(is);
    return is;
}
