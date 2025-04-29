//task6Deleting.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include "book_catalog.h"

void displayBooksByAuthorAndGenre(const Catalog* catalog){
    char author[256], genre[256];  // fixed-size buffers

    printf("Enter the author's name ('0' to skip): ");
    scanf(" %255[^\n]", author);

    printf("Enter the genre ('0' to skip): ");
    scanf(" %255[^\n]", genre);

    bool found = false; // flag to check if any books match

    // If both author and genre are "0", we shouldn't display any books.
    if (strcmp(author, "0") == 0 && strcmp(genre, "0") == 0) {
        printf("\nNo books found because both author and genre are skipped.\n");
        return; // Exit the function early
    }

    // Iterate over all books in the catalog
    for (size_t i = 0; i < catalog->size; ++i) {
        const Book& book = catalog->books[i];

        // Check if the book matches the author and/or genre
        bool matchesAuthor = (strcmp(author, "0") == 0 || strcmp(book.author, author) == 0);
        bool matchesGenre = (strcmp(genre, "0") == 0 || strcmp(book.genre, genre) == 0);

        // If the book matches the author and/or genre, display it
        if (matchesAuthor && matchesGenre) {
            printf("\nBook Found:\n");
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Year: %d\n", book.year);
            printf("Genre: %s\n", book.genre);
            printf("Description: %s\n", book.description);
            found = true;
        }
    }

    // If no matches were found, display a message
    if (!found) {
        printf("\nNo books found matching the given author and/or genre.\n");
    }
}

