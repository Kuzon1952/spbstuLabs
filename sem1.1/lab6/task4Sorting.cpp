//task4Sorting.cpp
#include <iostream>
#include <cstring>
#include <cstdio>
#include "book_catalog.h"


int compareBooks(const Book* a, const Book* b, int field, bool ascending){//comparing two books
    int result = 0;//variable to store the comparison result

    switch (field) {
        case 1://compare titlesn
            result = strcmp(a->title, b->title);
            break;
        case 2://compare authors
            result = strcmp(a->author, b->author);
            break;
        case 3://compare years
            result = a->year - b->year;
            break;
        case 4://compare genres
            result = strcmp(a->genre, b->genre);
            break;
        case 5:
            return -1;
            return 0;
        default:
            printf("Invalid field for sorting.\n");
            return 0;//invalid field returns 0
    
    }

    return ascending ? result : -result;//reverse result for descending order
}

//function to sort the catalog based on the selected field and order
void sortCatalog(Catalog* catalog, int field, bool ascending) {
    for(size_t i = 0; i < catalog->size - 1; ++i) {//outer loop for bubble sort
        for(size_t j = 0; j < catalog->size - i - 1; ++j){//inner loop to compare adjacent books
            if(compareBooks(&catalog->books[j], &catalog->books[j + 1], field, ascending) > 0){
                //swap books if they are in the wrong order
                Book temp = catalog->books[j];
                catalog->books[j] = catalog->books[j + 1];
                catalog->books[j + 1] = temp;
            }
        }
    }

    printf("Catalog sorted successfully!\n");
}

//function to display a sorting menu for user interaction
void sortingMenu(Catalog* catalog){
    int field;//variable to store the user's choice of field
    char order;//variable to store the user's choice of sorting order

    //sisplay the sorting options
    printf("Choose a field to sort by:\n");
    printf("1. Title\n");
    printf("2. Author\n");
    printf("3. Year\n");
    printf("4. Genre\n");
    printf("5. Exit\n");
    printf("Enter your choice (1-5): ");

    while(scanf("%d", &field) != 1 || field < 1 || field > 5){//validate input for field
        printf("Invalid choice. Please enter a valid option (1-5): ");
        while (getchar() != '\n'); //clear input buffer
    }

    // Exit if user selects 5
    if (field == 5) {
        printf("Exiting sorting menu.\n");
        return; // Exit the loop and return from sortingMenu
    }

    //ask for sorting order
    printf("Choose sorting order (a for ascending, d for descending): ");
    while (scanf(" %c", &order) != 1 || (order != 'a' && order != 'd')) {//validate input for order
        printf("Invalid choice. Please enter 'a' for ascending or 'd' for descending: ");
        while (getchar() != '\n');//clear input buffer
    }

    //call the sort function with user choices
    sortCatalog(catalog, field, (order == 'a'));
}
