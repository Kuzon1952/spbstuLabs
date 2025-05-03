#include "workerdb.hpp"
#include <iostream>

//workerData implementation
WorkerData::WorkerData() : age(0) {}
WorkerData::WorkerData(const MyString& n, int a) : name(n), age(a) {}

//iterator constructor
WorkerDb::Iterator::Iterator(MapIter it) : iter(it) {}

//iterator operations
WorkerData& WorkerDb::Iterator::operator*() { 
    return iter->second;
}

WorkerData* WorkerDb::Iterator::operator->() { 
    return &iter->second;//value
}

const MyString& WorkerDb::Iterator::key() const { 
    return iter->first;//key
}

WorkerDb::Iterator& WorkerDb::Iterator::operator++() {
    ++iter; 
    return *this;
}

bool WorkerDb::Iterator::operator!=(const Iterator& other) const { 
    return iter != other.iter; 
}


WorkerData& WorkerDb::operator[](const MyString& surname) { 
    return workers[surname];  
}

// begin/end iterators
WorkerDb::Iterator WorkerDb::begin() { 
    return Iterator(workers.begin());  
}

WorkerDb::Iterator WorkerDb::end() { 
    return Iterator(workers.end()); 
}