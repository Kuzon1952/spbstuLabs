#ifndef ROUTE_H
#define ROUTE_H

#define MAX_NAME_LEN 50

typedef struct {
    char start[MAX_NAME_LEN];
    char end[MAX_NAME_LEN];
    int number;
} ROUTE;

#endif