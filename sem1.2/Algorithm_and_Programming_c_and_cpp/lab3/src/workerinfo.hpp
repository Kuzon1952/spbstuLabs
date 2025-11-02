#ifndef WORKER_INFO_HPP
#define WORKER_INFO_HPP

#include "workerdb.hpp"

//function to print all workers in the database
void print_db(WorkerDb& db);

//function to calculate average age of workers
double get_avg_age(WorkerDb& db);

#endif