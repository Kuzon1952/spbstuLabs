#include <iostream>
#include <cstring>
#include <cstdio>
#include "book_catalog.h"

void modifyBook(Catalog* catalog, const char* title) {
    for (size_t i = 0; i < catalog->size; ++i) {
        
        if (strcmp(catalog->books[i].title, title) == 0) {
            printf("Book found. Enter new details or press '0' to keep the current value except year.\n");//use strcmp to match the title with user input

            char buffer[256];

            // modify title
            printf("Enter new title (current: %s): ", catalog->books[i].title);
            fgets(buffer, sizeof(buffer), stdin); //use fgets to handle multi-word input
            buffer[strcspn(buffer, "\n")] = 0;//remove the trailing newline if it exists

            if (strcmp(buffer, "0") != 0 && strlen(buffer) > 0) {
                delete[] catalog->books[i].title;
                catalog->books[i].title = new char[strlen(buffer) + 1];
                strcpy(catalog->books[i].title, buffer);
            }

            //modify author
            printf("Enter new author (current: %s): ", catalog->books[i].author);
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = 0; //remove newline if exists
            if (strcmp(buffer, "0") != 0 && strlen(buffer) > 0) {
                delete[] catalog->books[i].author;
                catalog->books[i].author = new char[strlen(buffer) + 1];
                strcpy(catalog->books[i].author, buffer);
            }

            //modify year
            int newYear;
            while (true) {
                printf("Enter new year (current: %d): ", catalog->books[i].year);
                if (scanf("%d", &newYear) != 1 || newYear < -2600) {
                    printf("Error: Please enter a valid year (>= -2600).\n");
                    while (getchar() != '\n'); // Clear the input buffer
                } else {
                    catalog->books[i].year = newYear;
                    break;  // Exit the loop if a valid year is entered
                }
            }

            //clear the buffer after the number input to avoid issues with fgets calls
            while (getchar() != '\n');//clear any remaining newline characters from the buffer

            //modify genre
            printf("Enter new genre (current: %s): ", catalog->books[i].genre);
            fgets(buffer, sizeof(buffer), stdin);  // Read genre input
            buffer[strcspn(buffer, "\n")] = 0;  // Remove newline if exists
            if (strcmp(buffer, "0") != 0 && strlen(buffer) > 0) {
                delete[] catalog->books[i].genre;
                catalog->books[i].genre = new char[strlen(buffer) + 1];
                strcpy(catalog->books[i].genre, buffer);
            }

            //modify description
            printf("Enter new description (current: %s): ", catalog->books[i].description);
            fgets(buffer, sizeof(buffer), stdin);  // Read description input
            buffer[strcspn(buffer, "\n")] = 0;  // Remove newline if exists
            if (strcmp(buffer, "0") != 0 && strlen(buffer) > 0) {
                delete[] catalog->books[i].description;
                catalog->books[i].description = new char[strlen(buffer) + 1];
                strcpy(catalog->books[i].description, buffer);
            }

            printf("Book updated successfully.\n");
            return;
        }
    }

    printf("No book with title '%s' found in the catalog.\n", title);
}

void interactiveModifyBook(Catalog* catalog) {
    char title[1024];

    //clear the input buffer before reading title
    while (getchar() != '\n' && getchar() != EOF);  // Clear the input buffer

    printf("Enter the title of the book to modify: ");
    fgets(title, sizeof(title), stdin);  // Read the full line including spaces

    //remove newline character if it exists
    title[strcspn(title, "\n")] = 0;

    if (strlen(title) == 0) {
        printf("Error: No title provided.\n");
        return;
    }

    modifyBook(catalog, title);
}





