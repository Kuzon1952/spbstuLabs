#pragma once
#include "mystring.hpp"

struct WorkerData {
    MyString name;
    int age = 0;
    MyString position;

    WorkerData() = default;
   
    WorkerData(const MyString& n, int a); 
};

class WorkerDb {// dynamic database using a raw arr
private:
    struct Entry {
        MyString key;
        WorkerData value;
    };

    Entry* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void ensure_capacity();//checking capacity

public:
    WorkerDb();
    ~WorkerDb();

    WorkerData& operator[](const MyString& surname);//by surname

    class Iterator {
    private:
        Entry* ptr;
    public:
        Iterator(Entry* p);

        WorkerData& operator*();
        WorkerData* operator->();

        Iterator& operator++();
        Iterator operator++(int);

        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;

        MyString key() const;
    };

    Iterator begin();
    Iterator end();
};

void print_workers(WorkerDb& db);
double get_average_age(WorkerDb& db);
