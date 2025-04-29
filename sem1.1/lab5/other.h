#ifndef OTHER_H
#define OTHER_H

#include <string>


void getCoefficients(double &A, double &B, double &C);

void printTable(double A, double B, double C);

double add(double a, double b);
double sub(double a, double b);
double mul(double a, double b);
double div(double a, double b);
double exponentiate(double a, double b);

void sort(char* pcFirst, int nNumber, int size, void (*Swap)(void*, void*), int (*Compare)(void*, void*));

void swap_int(void* p1, void* p2);
int cmp_int(void* p1, void* p2);

void swap_double(void* p1, void* p2);
int cmp_double(void* p1, void* p2);

void swap_str(void* p1, void* p2);
int cmp_str(void* p1, void* p2);

void print_max(int* arr, int size);
void print_min(int* arr, int size);
void sort_asc(int* arr, int size);
void sort_desc(int* arr, int size);

double integrate(double (*func)(double), double a, double b, int c);
double linear(double x);
double parabola(double x);
double exponential(double x);
double sine(double x);

struct Book {
    char* author;//c style dynamic memory string
    char* title;//c style dynamic memory string
    int year;       
    float price;    
    char* category;//c style dynamic memory string 
};
void copyCString(char*& destination, const char* source);
void addBook(Book& book, const char* author, const char* title, int year, float price, const char* category);
void displayBook(const Book& book);
void freeBook(Book& book);

bool isValidYear(int year);
bool isValidPrice(double price);
bool isValidCategory(const char* category, const char* validCategories[], size_t categoryCount);
void inputBook(Book& book, const char* validCategories[], size_t categoryCount);


#endif //OTHER_H