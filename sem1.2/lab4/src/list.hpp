#ifndef LIST_HPP
#define LIST_HPP

#include "node.hpp"
#include <iostream>
#include <cstddef>

class List {
    
private:
    Node Head;
    Node Tail;
    std::size_t m_size;
    
    void display(std::ostream& os) const;//output
    void readFromStream(std::istream& is);//read from file

public:
    List();
    ~List();
    
    //copy constructor
    List(const List& other) = delete;
    List& operator=(const List& other) = delete;
    
    //base methods
    void push_front(const Circle& value);
    void push_back(const Circle& value);
    bool removeFirst(const Circle& value);
    int removeAll(const Circle& value);
    void clear();
    bool isEmpty() const;
    std::size_t size() const;
    
    //access first and last data
    Circle front() const;
    Circle back() const;

    void sortByArea();//sorting

    //friend operators
    friend std::ostream& operator<<(std::ostream& os, const List& list);
    friend std::istream& operator>>(std::istream& is, List& list);
};

#endif//LIST_HPP
