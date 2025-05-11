#include "workerdb.hpp"
#include <iostream>
using namespace std;


WorkerData::WorkerData(const MyString& n, int a) : name(n), age(a){}

WorkerDb::WorkerDb() : size(0), capacity(2) {
    data = new Entry[capacity];
}

WorkerDb::~WorkerDb() {
    delete[] data;
}

void WorkerDb::ensure_capacity() {//ensures space for more workers
    if (size >= capacity) {
        capacity *= 2;
        Entry* new_data = new Entry[capacity];
        for (size_t i = 0; i < size; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
    }
}

WorkerData& WorkerDb::operator[](const MyString& surname) {// add or retrieves by surname
    for (size_t i = 0; i < size; ++i) {
        if (data[i].key == surname)
            return data[i].value;
    }

    ensure_capacity();
    data[size].key = surname;
    data[size].value = WorkerData();
    ++size;
    return data[size - 1].value;
}

WorkerDb::Iterator WorkerDb::begin() {// retrun to  first ele
    return Iterator(data);
}

WorkerDb::Iterator WorkerDb::end() {// past last ele
    return Iterator(data + size);
}

WorkerDb::Iterator::Iterator(Entry* p) : ptr(p) {}

WorkerData& WorkerDb::Iterator::operator*() {
    return ptr->value;
}

WorkerData* WorkerDb::Iterator::operator->() {
    return &ptr->value;
}

WorkerDb::Iterator& WorkerDb::Iterator::operator++() {
    ++ptr;
    return *this;
}

WorkerDb::Iterator WorkerDb::Iterator::operator++(int) {
    Iterator temp = *this;
    ++ptr;
    return temp;
}

bool WorkerDb::Iterator::operator==(const Iterator& other) const {
    return ptr == other.ptr;
}

bool WorkerDb::Iterator::operator!=(const Iterator& other) const {
    return ptr != other.ptr;
}

MyString WorkerDb::Iterator::key() const {
    return ptr->key;
}

void print_workers(WorkerDb& db) {
    for (auto it = db.begin(); it != db.end(); ++it) {
        cout << "Key: " << it.key().get_data()
             << ", Name: " << it->name.get_data()
             << ", Age: " << it->age << endl;
    }
}

double get_average_age(WorkerDb& db) {
    int total = 0;
    int count = 0;

    for (auto it = db.begin(); it != db.end(); ++it) {
        total += it->age;
        ++count;
    }

    return count == 0 ? 0.0 : static_cast<double>(total) / count;
}