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
        cout << "allocated memory for MyString: " << strlen(input_str) + 1 << " bytes." << endl;
        strcpy(str, input_str);//copy the input string to the allocated memory
    }
    else{
        //str = new char[1];//in case of a null pointer, allocate an empty string
        //str[0] = '\0';cout << "Allocated memory for MyString: " << strlen(input_str) + 1 << " bytes." << endl;
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
    if (str) {
        delete[] str;//free memory
        cout << "freed memory for MyString." << endl;
    }
}

char MyString::get(int i) const{//getting the i-th char of the str
    if(str && i >= 0 &&  i < (int)strlen(str)){
        return str[i];
    }
    else{
        cout<<"index out of bounds"<<endl;
        return '\0';
    }
}

void MyString::set(int i, char c){//set the ith char of the str
    if(str && i >= 0 && i< (int)strlen(str)){
        str[i]=c;

    }
    else{
        cout<<"index of of bounds"<<endl;
    }
}

void MyString::set_new_string(const char* new_str){//replacing str with the new one
    delete[] str;//freeing previously allocated memory
    if(new_str){
        
        str = new char[strlen(new_str) + 1];//allocated new memory
        strcpy(str, new_str);//cpy the str to the allocated memory
    }
    else{
        str = nullptr;
    }
}

void MyString::print() const{
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

MyString& MyString::operator+=(const MyString& other) {//overload the += operator for MyString
    if (other.str) {
        size_t new_size = strlen(str ? str : "") + strlen(other.str) + 1;
        char* new_str = new char[new_size];

        if (str) {
            strcpy(new_str, str);
        }
        strcat(new_str, other.str);

        delete[] str;
        str = new_str;
    }
    return *this;
}


MyString& MyString::operator+=(const char* other) {//overload the += operator for const char*
    if (other) {
        size_t new_size = strlen(str ? str : "") + strlen(other) + 1;
        char* new_str = new char[new_size];

        if (str) {
            strcpy(new_str, str);
        }
        strcat(new_str, other);

        delete[] str;
        str = new_str;
    }
    return *this;
}


MyString MyString::operator+(const MyString& other) const {//overload the + operator for MyString
    MyString result(*this);
    result += other;
    return result;
}


MyString MyString::operator+(const char* other) const {//overload the + operator for const char*
    MyString result(*this);
    result += other;
    return result;
}

const char* MyString::get_data() const {
    return str ? str : "";
}


MyString operator+(const char* left, const MyString& right) {//non-member function for operator + with const char* on the left
    MyString result(left);
    result += right;
    return result;
}
MyString::MyString(MyString&& other) noexcept : str(other.str) {
    other.str = nullptr;//source obj empty  
    cout << "moved memory for MyString." << endl;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] str;
        str = other.str;//steal the data from the other object
        other.str = nullptr;//make the other object empty
        cout << "moved memory for MyString." << endl;
    }
    return *this;
}

bool MyString::operator==(const MyString& other) const {
    return strcmp(str, other.str) == 0; //compare str lexi
}

bool MyString::operator!=(const MyString& other) const {
    return strcmp(str, other.str) != 0; //compare str for inequality
}

bool MyString::operator<(const MyString& other) const {
    return strcmp(str, other.str) < 0; //less than
}

bool MyString::operator<=(const MyString& other) const {
    return strcmp(str, other.str) <= 0; //less than or equal
}

bool MyString::operator==(const char* other) const {
    return strcmp(str, other) == 0; //compare with a const char*
}

bool MyString::operator!=(const char* other) const {
    return strcmp(str, other) != 0; //compare with a const char*
}

bool MyString::operator<(const char* other) const {
    return strcmp(str, other) < 0; //lexicographically less than
}

bool MyString::operator<=(const char* other) const {
    return strcmp(str, other) <= 0; //lexicographically less than or equal
}

//non-member functions for comparison with const char*
bool operator==(const char* left, const MyString& right) {
    return strcmp(left, right.get_data()) == 0;
}

bool operator!=(const char* left, const MyString& right) {
    return strcmp(left, right.get_data()) != 0;
}

bool operator<(const char* left, const MyString& right) {
    return strcmp(left, right.get_data()) < 0;
}

bool operator<=(const char* left, const MyString& right) {
    return strcmp(left, right.get_data()) <= 0;
}

//indexing operator (non-const version)
char& MyString::operator[](int i) {
    if (i < 0 || i >= static_cast<int>(strlen(str))) {
        throw out_of_range("index out of range");
    }
    return str[i];//return reference to the i-th character
}

//indexing operator (const version) for const objects
const char& MyString::operator[](int i) const {
    if (i < 0 || i >= static_cast<int>(strlen(str))) {
        throw out_of_range("index out of range");
    }
    return str[i];//return const reference to the i-th character
}

//overloading the << operator for MyString
ostream& operator<<(ostream& os, const MyString& s) {
    
    os << s.get_data();
    return os;
}

//overloading the >> operator for MyString
std::istream& operator>>(std::istream& is, MyString& s) {
    char buffer[1000];//buffer to hold the input

    //read a line from the input stream
    is.getline(buffer, sizeof(buffer));//read until newline
    s.set_new_string(buffer);//set the str in MyString obj

    return is; 
}
