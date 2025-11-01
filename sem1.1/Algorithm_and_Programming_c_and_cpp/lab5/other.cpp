#include "other.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>//for strcmp
#include <algorithm>
#include <climits>
#include <cstdlib>//for dynamic memory allocation


using namespace std;
//1.1
void getCoefficients(double &A, double &B, double &C) {
    printf("enter A, B, C: ");
    scanf("%lf %lf %lf", &A, &B, &C);
    printf("You have entered: A=%.2f, B=%.2f, C=%.2f\n", A, B, C);
}
//1.2
void printTable(double A, double B, double C){
	double x,y;

	printf("\n%-8s %-8s\n", "x", "y = A*x^2 + B*x + C");//printing table header
	printf("-----------------------------\n");

	for(x=-2.0; x<=2.0; x+= 0.5){
		y=(A * x * x) + (B * x) + C;//calculating y for each x
		printf("%-8.2f %-8.2f\n", x, y);//printing the value of x and y
	}
}
//2.1
double add(double a, double b){
    return a + b;
}

double sub(double a, double b){
    return a - b;
}

double mul(double a, double b){
    return a * b;
}

double div(double a, double b){
    if (b == 0) {
        cout << "error: division by zero is not allowed." << endl;
        return 0;
    }
    return a / b;
}

double exponentiate(double a, double b) {
    return pow(a, b);//using the standard pow function from <cmath>
}


//2.2.1
void swap_int(void* p1, void* p2){   
    int* int1 = reinterpret_cast<int*>(p1);//casting void* to int*
    int* int2 = reinterpret_cast<int*>(p2);

    int temp = *int1;
    *int1 = *int2;//copy the sec int to first
    *int2 = temp;//assign the saved val to sec
}

int cmp_int(void* p1, void* p2){
    int* int1 = reinterpret_cast<int*>(p1);//cast void* to int*
    int* int2 = reinterpret_cast<int*>(p2);//cast void* to int*

    if (*int1 < *int2) {
        return -1;//*int1 is smaller than *int2
    } 
    else if (*int1 > *int2) {
        return 1;//*int1 is larger than *int2
    } 
    else {
        return 0;//*int1 is equal to *int2
    }
}

void sort(char* pcFirst, int nNumber, int size, void (*Swap)(void*, void*), int (*Compare)(void*, void*)){
    //char* poFirst ptr to the first element to the arr;
    //int nNumber number of elements in the arr;
    //int size size of each element in bytes;
    //void (*swap)(void*, void*) pointer to the function that swaps two elements;
    //int (*compare)(void*, void*)pointer to a function that compares two elements;
    int i;

    for(i=1; i<nNumber; i++)
        for(int j=nNumber-1; j>=i; j--)
        {
            char* pCurrent = pcFirst+j*size;// pointer to current element
            char* pPrevious = pcFirst+(j-1)*size;// pointer to previous element
            if((*Compare)( pPrevious, pCurrent ) > 0){//требуется
                                                //переставить
                (*Swap)( pPrevious, pCurrent );
            }
        }
}
//{98, 3, 90, 2, 7, 1, 4, 6}
//{3, 98, 90, 2, 7, 1, 4, 6}
//{3, 90, 98, 2, 7, 1, 4, 6}
//............................


//2.2.2
//define the swap and compare functions for double
void swap_double(void* p1, void* p2) {
    double* double1 = reinterpret_cast<double*>(p1);
    double* double2 = reinterpret_cast<double*>(p2);

    double temp = *double1;
    *double1 = *double2;
    *double2 = temp;
}

int cmp_double(void* p1, void* p2) {
    double* double1 = reinterpret_cast<double*>(p1);
    double* double2 = reinterpret_cast<double*>(p2);

    if (*double1 < *double2) {
        return -1;  //*double1 is smaller than *double2
    } else if (*double1 > *double2) {
        return 1;   //*double1 is larger than *double2
    } else {
        return 0;   //*double1 is equal to *double2
    }
}

//2.2.3
//function to swap two C-style strings
void swap_str(void* p1, void* p2) {
    const char** str1 = static_cast<const char**>(p1);//cast void* to const char**
    const char** str2 = static_cast<const char**>(p2); //cast void* to const char**

    const char* temp = *str1;// temp store
    *str1 = *str2;//swaping the pointers
    *str2 = temp; 
}

//function to compare two C-style strings using strcmp
int cmp_str(void* p1, void* p2) {
    const char* str1 = *reinterpret_cast<const char**>(p1);//cast void* to const char*
    const char* str2 = *reinterpret_cast<const char**>(p2); //cast void* to const char*

    return strcmp(str1, str2);  //return the result of strcmp
}

//2.3
void print_max(int* arr, int size) {//function to print the maximum element
    int max_val = INT_MIN;
    for (int i = 0; i < size; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }
    cout<<"Maximum value: "<<max_val<<endl;
}

void print_min(int* arr, int size) {//function to print the minimum element
    int min_val = INT_MAX;
    for (int i = 0; i < size; i++){
        if (arr[i]<min_val) {
            min_val = arr[i];
        }
    }
    cout<<"Minimum value: "<<min_val<<endl;
}

void sort_asc(int* arr, int size) {//function to sort the array in ascending order and print
    sort(arr, arr + size);//sort the array in ascending order; arr+size ptr to the element just past the last elemnt of the arr
    cout<<"Sorted array (ascending): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void sort_desc(int* arr, int size) {//function to sort the array in descending order and print
    sort(arr, arr + size, greater<int>());//sort the array in descending order;greater<int>() is comparing func that ensures sorting in descending order
    cout<<"Sorted array (descending): ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//2.4
double integrate(double (*func)(double), double a, double b, int c){//function to intrigrate using rectangular method
    double step1 = (b - a) / c;//step1 size
    double sum = 0.0;


    for (int i = 0; i < c; ++i) {//summing the areas
        double x = a + i * step1; //rectangle area
        sum += func(x);
    }

    return sum * step1; //mul buy the widh of intrigal to get the total areas
}

double linear(double x) {
    return 5 * x + 3;
}

double parabola(double x) {
    return x * x;
}

double exponential(double x) {
    return exp(x);
}

double sine(double x) {
    return sin(x);
}

//3.1.1 and 3.1.2

void copyCString(char*& destination, const char* source) {//copy string
    size_t length = 0;
    while(source[length] != '\0') {
        ++length;
    }
    destination = (char*)malloc(length + 1);
    for (size_t i = 0; i < length; ++i) {
        destination[i] = source[i];
    }
    destination[length] = '\0';
}

void addBook(Book& book, const char* author, const char* title, int year, float price, const char* category) {//function to add book
    copyCString(book.author, author);
    copyCString(book.title, title);
    copyCString(book.category, category);

    book.year = year;
    book.price = price;
}

void displayBook(const Book& book){
    printf("Book Details:\n");
    printf("Author: %s\n", book.author);
    printf("Title: %s\n", book.title);
    printf("Year: %d\n", book.year);
    printf("Price: %.2f\n", book.price);
    printf("Category: %s\n", book.category);
}

void freeBook(Book& book){//free memory
    free(book.author);
    free(book.title);
    free(book.category);
}

//3.1.5
bool isValidYear(int year) {
    const int earliestYear =-2600;
    return year > earliestYear;
}

bool isValidPrice(double price) {
    return price >= 0.0;
}

bool isValidCategory(const char* category, const char* validCategories[], size_t categoryCount) {
    for (size_t i = 0; i< categoryCount; ++i) {
        if (strcmp(category, validCategories[i]) == 0) {
            return true;
        }
    }
    return false;
}
void inputBook(Book& book, const char* validCategories[], size_t categoryCount) {
    
    printf("enter author: ");//console input
    scanf(" %[^\n]", book.author);//reads input until a newline

    printf("enter title: ");//console input
    scanf(" %[^\n]", book.title);

    printf("enter year of publication: ");//console input
    while (true) {
        if(scanf("%d", &book.year)!=1){
            printf("invalid input! please input vaid num ");
            scanf("%*s");//clear invalid input
        }
        else if (scanf("%d", &book.year) != 1 || book.year<-2600) {
            printf("invalid year. enter a valid year (>= -2600): ");
        } else {
            break;
        }
    }

    printf("enter price: ");//console input
    while (true) {
        if(scanf("%f", &book.price)!=1){
            printf("invalid input! please input vaid num ");
            scanf("%*f");//clear invalid input
        }
        else if (scanf("%f", &book.price) != 1 || book.price < 0) {
            printf("invalid price. enter a non-negative price: ");
        } else {
            break;
        }
    }

    printf("Enter category (Valid options: ");//console input
    for (size_t i = 0; i < categoryCount; ++i) {
        printf("%s%s", validCategories[i], i < categoryCount - 1 ? ", " : "");
    }
    printf("): ");
    
    while (true){//checking category
        scanf(" %[^\n]", book.category);
        bool isValid = false;
        for (size_t i = 0; i < categoryCount; ++i) {
            if (strcmp(book.category, validCategories[i]) == 0) {
                isValid = true;
                break;
            }
        }
        if (isValid) {
            break;
        } else {
            printf("invalid category. please enter a valid category: ");
        }
    }
}

























