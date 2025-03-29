#include "mystring.hpp"
#include <iostream>
#include <cstring>//for strlen, strcpy, etc.

using namespace std;

void bar() {
    for (int i = 0; i < 100; ++i) {
        MyString s; // allocates 1 byte
        s.read_line(); // frees this 1 byte
        // do something with the string
    }
}

MyString::MyString(){//default constructor
    // TODO: use nullptr for indicating that string is empty

    //str = new char[1];//1 byte for null 
    //str[0]='\0';//empty string
    str= nullptr;
}

MyString::MyString(const char* input_str){//parameterized constructor
    if(input_str){
        str = new char[strlen(input_str) + 1];//memory for string
        strcpy(str, input_str);//copy the input string to the allocated memory
    }
    else{
       // str = new char[1];//in case of a null pointer, allocate an empty string
        //str[0] = '\0';
        str = nullptr;
    }
}

MyString::MyString(const MyString& other){//copy constructor

    // TODO: handle possible nullptr in other
    if(other.str){
        str = new char[strlen(other.str) + 1];//memory for string
        strcpy(str, other.str);
    }
    else{
        str = nullptr;//empty string
    }
    
    //strcpy(str, other.str);//copy the string from the other obj
}

MyString::~MyString(){//destrucgtor for freeing the dynamically allocated memory
    delete[] str;
}

char MyString::get(int i) const{//getting the i-th char of the string
    if(str && i >= 0 &&  i < (int)strlen(str)){
        return str[i];
    }
    else{
        cout<<"index out of bounds"<<endl;
        return '\0';
    }
}

void MyString::set(int i, char c){//set the ith char of the string
    if(str && i >= 0 && i< (int)strlen(str)){
        str[i]=c;

    }
    else{
        cout<<"index of of bounds"<<endl;
    }
}

void MyString::set_new_string(const char* new_str){//replacing string with the new one
    delete[] str;//freeing previously allocated memory
    if(new_str){
        
        str = new char[strlen(new_str) + 1];//allocated new memory
        strcpy(str, new_str);//cpy the string to the allocated memory
    }
    else{
        str = nullptr;
    }
}

void MyString::print() const{//print
    if(str){
        cout<<str<<endl;
    }
    else{
        cout<<"empty string"<<endl;
    }
}

void MyString::read_line(){//reading line form user input and replacing the current string
    char temp[1000];//temp buffer
    cin.getline(temp, 1000);//read the line from standard input
    set_new_string(temp);//replace the current string with the input
}

MyString& MyString::operator=(const MyString& other){//assignment operator
    if(this != &other){//check for self assignment
        delete[] str;//delete the current string
        if(other.str){
            str = new char[strlen(other.str)+1];//allocate memory for the new string
            strcpy(str, other.str);//copy the string form the other obj
        }
        else{
            str = nullptr;
        }
    }
    return *this;
}

const char* MyString::get_data() const {
    return str ? str : "";
}
