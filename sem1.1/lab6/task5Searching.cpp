//task5searching.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include "book_catalog.h"

// Function to search books based on a criterion
void searchBooks(const Catalog* catalog, const char* criterion, const char* value) {
    bool found = false;
    
    // Search through the catalog
    for (size_t i = 0; i < catalog->size; ++i) {
        const Book& book = catalog->books[i];

        // Compare based on the criterion
        if ((strcmp(criterion, "title") == 0 && strcmp(book.title, value) == 0) ||
            (strcmp(criterion, "author") == 0 && strcmp(book.author, value) == 0) ||
            (strcmp(criterion, "genre") == 0 && strcmp(book.genre, value) == 0)) {
            
            // If a match is found, print the details
            printf("\nBook Found:\n");
            printf("Title: %s\n", book.title);
            printf("Author: %s\n", book.author);
            printf("Year: %d\n", book.year);
            printf("Genre: %s\n", book.genre);
            printf("Description: %s\n", book.description);
            found = true;
        }
    }

    // If no match was found, inform the user
    if (!found) {
        printf("\nNo books found matching the criterion '%s' with value '%s'.\n", criterion, value);
    }
}

// Function to display the search menu and handle user input
void searchMenu(Catalog* catalog) {
    int choice;  // Variable to store user's choice
    char value[1024];  // Temporary buffer for the search value

    while (true) {  // Infinite loop to keep the menu running until the user exits
        // Display the search options menu
        printf("\nSearch for a book by:\n");
        printf("1. Title\n");
        printf("2. Author\n");
        printf("3. Genre\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid choice. Please enter a valid option (1-4): ");
            while (getchar() != '\n'); // Clear input buffer
        }

        if (choice == 4) {  // Exit the menu if the user chooses option 4
            printf("Exiting search menu...\n");
            break;  // Exit the loop and return from the function
        }

        // Prompt for the search value based on the selected criterion
        if (choice == 1) {
            printf("Enter the title of the book to search for: ");
        } else if (choice == 2) {
            printf("Enter the author name to search for: ");
        } else if (choice == 3) {
            printf("Enter the genre name to search for: ");
        }
        
        scanf(" %[^\n]", value);  // Read a line of input (including spaces)

        // Determine the search criterion and call the search function
        if (choice == 1) {
            searchBooks(catalog, "title", value);
        } else if (choice == 2) {
            searchBooks(catalog, "author", value);
        } else if (choice == 3) {
            searchBooks(catalog, "genre", value);
        }
    }
}