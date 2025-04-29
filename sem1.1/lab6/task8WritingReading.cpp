//task6Deleting.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include "book_catalog.h"


void saveCatalogToFile(const Catalog* catalog, const char* filename){//function to save the catalog to a file
    FILE* file = fopen(filename, "w");
    if(!file){
        printf("Error: Could not open file '%s' for writing.\n", filename);
        return;
    }

    fprintf(file, "%zu\n", catalog->size);//write the number of books
    for (size_t i = 0; i < catalog->size; ++i) {
        const Book& book = catalog->books[i];
        fprintf(file, "%s\n%s\n%d\n%s\n%s\n", book.title, book.author, book.year, book.genre, book.description);
    }

    fclose(file);
    printf("Catalog saved to file '%s' successfully.\n", filename);
}

void loadCatalogFromFile(Catalog* catalog, const char* filename){//function to load catalog from a file (with memory leak prevention)
    FILE* file = fopen(filename, "r");
    if (file == nullptr) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    size_t numBooks;
    if (fscanf(file, "%zu\n", &numBooks) != 1) {
        printf("Error: Invalid file format.\n");
        fclose(file);
        return;
    }


    for (size_t i = 0; i < catalog->size; ++i){//free previously allocated memory before loading new data
        delete[] catalog->books[i].title;
        delete[] catalog->books[i].author;
        delete[] catalog->books[i].genre;
        delete[] catalog->books[i].description;
    }

    
    delete[] catalog->books;//resize catalog to fit the number of books in the file
    catalog->size = numBooks;
    catalog->books = new Book[catalog->size];

    for (size_t i = 0; i < numBooks; ++i) {
        Book& book = catalog->books[i];

        book.title = new char[256];
        book.author = new char[256];
        book.genre = new char[256];
        book.description = new char[256];

        fscanf(file, "%255[^\n]\n", book.title); //read title
        fscanf(file, "%255[^\n]\n", book.author);
        fscanf(file, "%d\n", &book.year);         
        fscanf(file, "%255[^\n]\n", book.genre);  
        fscanf(file, "%255[^\n]\n", book.description);
    }

    fclose(file);
    printf("Catalog loaded from %s\n", filename);

    displayCatalog(catalog);
}







