
#include "workerinfo.hpp"
#include <iostream>


void print_db(WorkerDb& db) {
   
    for (auto it = db.begin(); it != db.end(); ++it) {
        //using key() and -> operators 
        std::cout << it.key() << " -> " << it->name << '\n';
    }
}


double get_avg_age(WorkerDb& db) {
    double total = 0.0;
    int count = 0;
    
    
    for (auto it = db.begin(); it != db.end(); ++it) {
        total += it->age;
        count++;
    }
    
    return count > 0 ? total / count : 0.0;
}