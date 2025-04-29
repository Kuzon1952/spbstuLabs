
//task1Book_Capacity.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include "book_catalog.h"

using namespace std;

void initializeCatalog(Catalog* catalog, size_t capacity){//function to initialize the catalog

    catalog -> size=0;//initialize to 0 because no books yet
    catalog -> capacity=capacity;//set the initial capacity of the catalog
    catalog -> books= new Book[catalog->capacity];//dynamically allocate memory for books

    for(size_t i = 0; i < (catalog->capacity); ++i){//initialize each book in the catalog with the null ptr
        catalog -> books[i].title = nullptr;
        catalog -> books[i].author = nullptr;
        catalog -> books[i].genre = nullptr;
        catalog -> books[i].description = nullptr;
        
    }

}


void addBook(Catalog* catalog, const char* title, const char* author, int year, const char* genre, const char* description){//function to add a book to the catalog
    
    if(catalog->size == catalog->capacity){//catalog needs resizing or not
        size_t newCapacity = static_cast<size_t>(catalog->capacity * 1.5);//increase capacity by 1.5x
        Book* newBooks = new Book[newCapacity];

        for(size_t i = 0; i < catalog->size; ++i){//copy existing books to the new array
            newBooks[i] = catalog->books[i];
        }

        delete[] catalog->books;//free memory
        catalog->books = newBooks;//update the catalog to use the new array
        catalog->capacity = newCapacity;//update the capacity
    }

    Book& newBook = catalog->books[catalog->size];//get a reference to the new book slot
    newBook.title = new char[strlen(title) + 1];//allocate memory for the title
    strcpy(newBook.title, title);//copy the title to the allocated memory

    newBook.author = new char[strlen(author) + 1];
    strcpy(newBook.author, author);

    newBook.year = year;

    newBook.genre = new char[strlen(genre) + 1];
    strcpy(newBook.genre, genre);

    newBook.description = new char[strlen(description) + 1];
    strcpy(newBook.description, description); 

    catalog->size++;//increment the size of the catalog
}


void displayCatalog(const Catalog* catalog){//display
    if(catalog->size == 0) {//check if the catalog is empty or not
        printf("catalog is empty.\n");
        return;
    }

    
    for(size_t i = 0; i < catalog->size; ++i){
        
        const Book& book = catalog->books[i];//get a reference to the current book

        printf("\nBook %zu:\n", i + 1);
        printf("Title: %s\n", book.title);
        printf("Author: %s\n", book.author);
        printf("Year: %d\n", book.year);
        printf("Genre: %s\n", book.genre); 
        printf("Description: %s\n", book.description); 
    }
}


void freeCatalog(Catalog* catalog){//free memory 
    for(size_t i = 0; i < catalog->size; ++i){
        delete[] catalog->books[i].title; 
        delete[] catalog->books[i].author; 
        delete[] catalog->books[i].genre; 
        delete[] catalog->books[i].description; 
    }

    delete[] catalog->books;//free memory for the book array
    catalog->books = nullptr;//ptr to null
    catalog->size = 0;//reset size to 0
    catalog->capacity = 0;//reset capacity to 0
}










