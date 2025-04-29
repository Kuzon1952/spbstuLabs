#ifndef OTHER_H
#define OTHER_H

//function declarations
void inc_by_value(int val); //increments by value
void inc_by_pointer(int* ptr); //increments by pointer
void inc_by_reference(int& ref); //increments by reference
void swap(int* nX, int* nY);//function to swap values using pointers
void swap(int& nX, int& nY);//function to swap values using references
int findMin1D(int arr[], int size);//function to find min in a 1d array
int findMin2D(int** arr, int rows, int cols);//function to find the min. in a 2d c style array
int my_str_cmp(const char* str1, const char* str2);
struct Date {//struct for day & month
    int day;
    int month;
};
int dayOfYear(int day, int month, int year, int nDayTab[2][12]);//function to calculate the ordinal day of the year from day, month, and year
Date dayOfMonth(int ordDay, int year, int nDayTab[2][12]);//function to calculate the day of the month and the month from the ordinal day and year
bool exists(int* arr, int n, int value);
void add_unique(int*& arr, int& n, int new_value);
void print_array(int* arr, int n);
int sumRecursive(int n);
int encode32(const char *raw_data, int raw_size, char *dst) ;
int decode32(const char *encoded_data, int encoded_size, char *dst);
int encoded32_size(int raw_size);
int encode_and_decode(const char *raw_data, int raw_size, char *encoded_data, char *decoded_data);
void var_args(int num,...);
#define VAR_ARGS(...) var_args(__VA_ARGS__, 0);
int* my_min(int* arr, int size);//finds min val in arr and rtn ptr to it


#endif //OTHER_H