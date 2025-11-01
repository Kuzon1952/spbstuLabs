//task6Deleting.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include "book_catalog.h"

// Function to delete a book by title
void deleteBook(Catalog* catalog, const char* title) {
    bool found = false;
    
    for (size_t i = 0; i < catalog->size; ++i) {
        if (strcmp(catalog->books[i].title, title) == 0) {
            found = true;
            
            // Free memory
            delete[] catalog->books[i].title;
            delete[] catalog->books[i].author;
            delete[] catalog->books[i].genre;
            delete[] catalog->books[i].description;

            // Shift the remaining books
            for (size_t j = i; j < catalog->size - 1; ++j) {
                catalog->books[j] = catalog->books[j + 1];
            }
            
            catalog->size--;
            
            // Reallocate memory
            if (catalog->size < catalog->capacity / 2 && catalog->capacity > 1) {
                size_t newCapacity = catalog->capacity / 2;
                Book* newBooks = new Book[newCapacity];

                for (size_t k = 0; k < catalog->size; ++k) {
                    newBooks[k] = catalog->books[k];
                }

                delete[] catalog->books;
                catalog->books = newBooks;
                catalog->capacity = newCapacity;
            }

            printf("Book with title '%s' deleted successfully.\n", title);
            return;
        }
    }

    if (!found) {
        printf("No book with title '%s' found in the catalog.\n", title);
    }
}

void interactiveDeleteBook(Catalog* catalog) {
    char title[1024];
    
    // Clear the input buffer before reading the title
    while (getchar() != '\n' && getchar() != EOF);  // Clear the input buffer

    printf("Enter the title of the book to delete: ");
    fgets(title, sizeof(title), stdin);  // Read the full line including spaces
    
    // Remove newline character at the end of the string, if it exists
    title[strcspn(title, "\n")] = 0;

    if (strlen(title) == 0) {
        printf("Error: No title provided.\n");
        return;
    }

    deleteBook(catalog, title);
}
