#ifndef WORKER_DB_HPP
#define WORKER_DB_HPP

#include "mystring.hpp"
#include <map>
#include <stdexcept> // for std::out_of_range

struct WorkerData {
    MyString name;
    int age;

    WorkerData();
    WorkerData(const MyString& n, int a);
};

class WorkerDb {
    
private:
    std::map<MyString, WorkerData> workers;

public:
    class Iterator {
        using MapIter = std::map<MyString, WorkerData>::iterator;
        MapIter iter;
    public:
        Iterator(MapIter it);//constructor taking a map it

        WorkerData& operator*();//get ref to worker data
        WorkerData* operator->();//get ptr to worker data

        const MyString& key() const;//current element

        Iterator& operator++();//prefix++
        bool operator!=(const Iterator& other) const;
    };
    WorkerDb() = default; 
    
    WorkerData& operator[](const MyString& surname);
    //const WorkerData& operator[](const MyString& surname) const;

    Iterator begin();//get it to first elements
    Iterator end();//to end marker
};

#endif // WORKER_DB_HPP