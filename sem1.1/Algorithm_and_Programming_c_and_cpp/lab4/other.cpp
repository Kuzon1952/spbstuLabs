#include <iostream>
#include "other.h"
#include <cstdio>
#include <cstdarg>//for assert
#include <cassert>
#include <cstdlib>//for random number genaration
#include <ctime>//seeding random number geranation
#include <cstdarg>//for va_list, va_start, va_arg, va_end

using namespace std;


//function for increments 
//what i have to do...
//todo: all i have to do by return type functions in this specfic program
//int
void inc_by_value(int val){
    val += 1;//increment the local copy of the value
    //return val;
}

//function that increments by pointer
void inc_by_pointer(int* val){
    if(val != nullptr){
        *val += 1;//increment the value at the memory location pointed to
    }
}

//function that increments by reference
void inc_by_reference(int& val){
    val += 1;//directly increment the passed variable
}

//function to swap values using pointers
void swap(int* nX, int* nY){
     if(nX != nullptr && nY != nullptr){
          int temp = *nX;
          *nX = *nY;
          *nY = temp;
     }
     else {
          cout<< "error because of nullptr...!"<<endl;
     }
}

//function to swap values using references
void swap(int& nX, int& nY){
     int temp = nX;
     nX = nY;
     nY = temp;
}

//function to find min in a 1d array
int findMin1D(int arr[], int size){
     assert(size > 0);//ensuring that array has at least one element
     int min=arr[0];//initialize min with the first element of the array

     for(int i =1; i< size; ++i){
          if(arr[i]<min){
               min = arr[i];
          }
     }
     return min;
}

//function to find the min. in a 2d c style array
int findMin2D(int** arr, int rows, int cols){
     assert(rows > 0 && cols > 0);//ensuring the dimensions
    int i = 0;
     int min = findMin1D(arr[i], cols);//use function findMin1D to find the min in the first row

     for(int i =1; i<rows; ++i){
          int rowMin = findMin1D(arr[i],cols);//useing min of the current row
          if(rowMin < min){
               min = rowMin;
          }
     }
     return min;
}


int my_str_cmp(const char* str1, const char* str2){
     assert(str1 != nullptr && str2 != nullptr);
     
     int i = 0;
     while (str1[i] != '\0' && str2[i] != '\0'){//cpmpare 
          if(str1[i] < str2[i]){
               return -1;//str1 < str2
          }
          else if(str1[i] > str2[i]){
               return 1;//str1 > str2
          }
          i++;//moving to next charecter
     }

     if(str1[i] == '\0' && str2[i] != '\0'){
          return -1;//end str1 > str2
     }
     else if (str1[i] != '\0' && str2[i] == '\0'){
          return 1;//str1 longer
     }

     return 0; //equal
}

int dayOfYear(int day, int month, int year, int nDayTab[2][12]){ 
    int leapYear;
    if (year % 4 == 0){//checking if it's leap year or not
        if (year % 100 != 0 || year % 400 == 0){
            leapYear = 1;//leap yr
        }
        else{
            leapYear = 0;//not l yr
        }
    }
    else{
        leapYear = 0;//not l yr
    }

    int ordDay = 0;
    for(int i=0; i< month-1; i++){//summing the days before the day
        ordDay += nDayTab[leapYear][i];
    }
    ordDay += day;

    return ordDay;
    
}

Date dayOfMonth ( int ordDay, int year, int nDayTab[2][12]){
    int leapYear;
    if (year % 4 == 0){
        if (year % 100 != 0 || year % 400 == 0){//finding leap yr
            leapYear = 1;
        }
        else{
            leapYear = 0;//not l yr
        }
    }
    else{
        leapYear = 0;//not l yr
    }

    int month = 0;
    while(ordDay > nDayTab[leapYear][month]){//finding current month trough month
        ordDay -= nDayTab[leapYear][month];
        month++;
    }
    // TODO: do not print, but (somehow) return both values to the calling function
    // do it so we can use in "main" function (for example)
    //cout << "day of the month: " << ordDay << ", Month: " << month + 1 << endl;
    Date result;
    result.day =ordDay;
    result.month=month+1;
    return result;
}

bool exists(int* arr, int n, int value){// value esists int the array or not
    for(int i = 0; i < n; ++i){
        if (arr[i] == value){
            return true;
        }
    }
    return false;
}

void add_unique(int*& arr, int& n, int new_value){// adding unique value to the array
    if(!exists(arr, n, new_value)){
       
        int* new_arr = new int[n+1];
        for(int i = 0; i< n; ++i){
            new_arr[i] = arr[i];
        }
        new_arr[n] = new_value;
        delete[] arr;
        arr = new_arr;
        n++;
    }
}

void print_array(int* arr, int n){//function to print array
    for(int i = 0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int sumRecursive(int n){//1,3,6,10,15
    if (n==1){
        return 1;
    }
    else{
        return (n + sumRecursive(n-1));
    }
}

const char table[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ1234";//32 chars


int encode32(const char *raw_data, int raw_size, char *dst) {// function to encode data into Base32-like encoding
    if (raw_data == nullptr || dst == nullptr || raw_size < 0) {
        return 1; //invalid input
    }

    int bit_count = 0;
    unsigned int buffer = 0; // fuffer to accumulate 5 bits at a time
    int idx = 0; // index for storing encoded characters

    for (int i = 0; i < raw_size; ++i) {
        buffer = (buffer << 8) | (unsigned char)raw_data[i]; // add next byte to buffer
        bit_count += 8;

        
        while (bit_count >= 5) {
            int index = (buffer >> (bit_count - 5)) & 31; // extract 5 bits
            dst[idx++] = table[index];  // map to character in table
            bit_count -= 5;
        }
    }

    
    if (bit_count > 0) {// if there are any leftover bits, pad with zeros and add the corresponding character
        dst[idx++] = table[0]; // Padding with 'A'
    }

    dst[idx] = '\0'; 
    return 0;
}


int decode32(const char *encoded_data, int encoded_size, char *dst) {// function to decode Base32-like encoding
    if (encoded_data == nullptr || dst == nullptr || encoded_size < 0) {
        return 1; 
    }

    unsigned int buffer = 0;
    int bit_count = 0;
    int idx = 0;

    for (int i = 0; i < encoded_size; ++i) {
        char c = encoded_data[i];
        int value = -1;

        
        for (int j = 0; j < 32; ++j) {// find the index of the character in the table
            if (table[j] == c) {
                value = j;
                break;
            }
        }

        if (value == -1) return 1; //invalid

        buffer = (buffer << 5) | value; // add the 5-bit value to the buffer
        bit_count += 5;

        if (bit_count >= 8) {
            dst[idx++] = (buffer >> (bit_count - 8)) & 0xFF; //process 8 bits into a byte
            bit_count -= 8;
        }
    }

    dst[idx] = '\0'; // null-terminate the decoded string
    return 0; 
}

// function to calculate the size of the encoded data
int encoded32_size(int raw_size) {
    return ((raw_size * 8 + 4) / 5); // calculate the size of the encoded data
}


int encode_and_decode(const char *raw_data, int raw_size, char *encoded_data, char *decoded_data) {//encode and decode
    int encoded_size = encoded32_size(raw_size);

    if (encode32(raw_data, raw_size, encoded_data) != 0) {
        return 1; // encoding failed
    }

    if (decode32(encoded_data, encoded_size, decoded_data) != 0) {
        return 2; //decoding failed
    }

    return 0; 
}

#define VAR_ARGS(...) var_args(__VA_ARGS__, 0);

void var_args(int num, ...) {
    va_list args;//to store the arg
    va_start(args, num);//initialize va_list 

    int count = 0;

    cout << "Args: ";
    while (num != 0) {
        cout << num << " "; 
        count++;            
        num = va_arg(args, int); // get the next argument
    }
    va_end(args);//clean up 

    cout << endl;
    
}

int* my_min(int* arr, int size) {//finds min val in arr and rtn ptr to it
    if (size == 0) return nullptr;//if nullptr
    
    int* minPtr = arr;//first is min initially
    
    //find the min val
    for (int i = 1; i < size; ++i) {
        if (arr[i] < *minPtr) {
            minPtr = &arr[i];//update the ptr to the new minimum value
        }
    }
    
    return minPtr;//ptr to the min val
}



