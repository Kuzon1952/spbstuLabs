#ifndef MYSTRING_HPP
#define MYSTRING_HPP
 
#include <iostream>
class MyString{
    private:
    char* str;//ptr to dynamically allocated memory for the string

    public:
    MyString();//default constructor:empty string
    MyString(const char* input_str);//constructor with a string parameter

    MyString(const MyString& other);//copy constructor

    ~MyString();

    char get(int i) const;// get the i th char of the string
    void set(int i, char c);//set the i th char of the string
    void set_new_string(const char* new_str);//changing string with a new one
    void print() const;//print the string
    void read_line();//replace the currect string with user input

    MyString& operator=(const MyString& other);//assignment operator

    const char* get_data() const;


};

#endif
