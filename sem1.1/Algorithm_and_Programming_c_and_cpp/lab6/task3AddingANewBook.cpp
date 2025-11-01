
//task3AddingANewBook.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include "book_catalog.h"

void interactiveAddBook(Catalog* catalog) {
    char tempBuffer[1024];//tempbuffer for input
    int year;

    //get title
    printf("Enter the title of the book: ");
    scanf(" %[^\n]", tempBuffer);//fixed to read until newline
    char* title = new char[strlen(tempBuffer) + 1];
    strcpy(title, tempBuffer);

    //get author
    printf("Enter the author of the book: ");
    scanf(" %[^\n]", tempBuffer);
    char* author = new char[strlen(tempBuffer) + 1];
    strcpy(author, tempBuffer);

    printf("Enter the year of publication: ");
    while (true) {
        if (scanf("%d", &year) != 1) { // Check if the input is a valid integer
            while (getchar() != '\n'); // Clear invalid input from buffer
            printf("Invalid input. Please enter a valid year (>= -2600): ");
        } else if (year >= -2600) {
            break; // Valid year, exit loop
        } else {
            printf("Invalid year. Enter a valid year (>= -2600): ");
        }

    }

    getchar();//consume the newline left by scanf

    //get genre
    printf("Enter the genre of the book: ");
    scanf(" %[^\n]",tempBuffer);
    char* genre = new char[strlen(tempBuffer) + 1];
    strcpy(genre, tempBuffer);

    //get description
    printf("Enter a short description of the book: ");
    scanf(" %[^\n]", tempBuffer);
    char* description = new char[strlen(tempBuffer) + 1];
    strcpy(description, tempBuffer);

    addBook(catalog, title, author, year, genre, description);//add the new book to the catalog

    //free the temporary dynamic memory
    delete[] title;
    delete[] author;
    delete[] genre;
    delete[] description;

    printf("*****Book added successfully*****\n");
}
