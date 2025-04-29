//book_catalog.h
#ifndef BOOK_CATALOG_H
#define BOOK_CATALOG_H

#include <cstddef>//for size_t to handle sizes and indexing

struct Book{
    char* title;//ptr to dynamically allocated memory for book title
    char* author;
    int year;
    char* genre;
    char* description;
};

struct Catalog{
    Book* books;//ptr to dynamically allocated memory for books
    size_t size;//current number of books in the catalog
    size_t capacity;//maximum number of books the catalog can hold without resizing
};

//1
void initializeCatalog(Catalog* catalog, size_t capacity);
void addBook(Catalog* catalog, const char* title, const char* author, int year, const char* genre, const char* description);
void displayCatalog(const Catalog* catalog);
void freeCatalog(Catalog* catalog);

//3
void interactiveAddBook(Catalog* catalog);

//4
int compareBooks(const Book* a, const Book* b, int field, bool ascending);
void sortCatalog(Catalog* catalog, int field, bool ascending);
void sortingMenu(Catalog* catalog);

//5
void searchBooks(const Catalog* catalog, const char* criterion, const char* value);
void searchMenu(Catalog* catalog);

//6
void deleteBook(Catalog* catalog, const char* title);
void interactiveDeleteBook(Catalog* catalog);

//7
void modifyBook(Catalog* catalog, const char* title);
void interactiveModifyBook(Catalog* catalog);


//8
void saveCatalogToFile(const Catalog* catalog, const char* filename);
void loadCatalogFromFile(Catalog* catalog, const char* filename);


//additional task
void displayBooksByAuthorAndGenre(const Catalog* catalog);


#endif//BOOK_CATALOG_H


