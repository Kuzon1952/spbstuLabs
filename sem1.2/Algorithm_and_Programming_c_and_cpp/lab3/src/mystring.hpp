#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>

class MyString {
    private:
        char* str;  // Pointer to dynamically allocated memory for the string

    public:
        MyString();//default constructor: empty str
        MyString(const char* input_str);//constructor with a str parameter

        MyString(const MyString& other);//copy constructor
        MyString(MyString&& other) noexcept;//move constructor

        ~MyString();

        char get(int i) const;//get the i-th char of the str
        void set(int i, char c);//set the i-th char of the str
        void set_new_string(const char* new_str);//changing str with a new one
        void print() const; 
        void read_line();//replace the current str with user input

        MyString& operator=(const MyString& other);//copy assignment operator
        MyString& operator=(MyString&& other) noexcept;//move assignment operator

        //concatenation operators
        MyString& operator+=(const MyString& other);//concatenate another MyString
        MyString& operator+=(const char* other);//concatenate const char*
        MyString operator+(const MyString& other) const;//add another MyString
        MyString operator+(const char* other) const;//add const char*

        const char* get_data() const;//get the data of the str

        //comparison operators
        bool operator==(const MyString& other) const; 
        bool operator!=(const MyString& other) const; 
        bool operator<(const MyString& other) const;  
        bool operator<=(const MyString& other) const; 

        bool operator==(const char* other) const; 
        bool operator!=(const char* other) const; 
        bool operator<(const char* other) const; 
        bool operator<=(const char* other) const; 

        //overloaded indexing operator
        char& operator[](int i);  
        const char& operator[](int i) const;

        //overload the << operator for output
        friend std::ostream& operator<<(std::ostream& os, const MyString& s);

        //overload the >> operator for input
        friend std::istream& operator>>(std::istream& is, MyString& s);



};

//non-member operator function for scalar + MyString
MyString operator+(const char* left, const MyString& right);

//non-member function for comparison with const char*
bool operator==(const char* left, const MyString& right);
bool operator!=(const char* left, const MyString& right);
bool operator<(const char* left, const MyString& right);
bool operator<=(const char* left, const MyString& right);

#endif
