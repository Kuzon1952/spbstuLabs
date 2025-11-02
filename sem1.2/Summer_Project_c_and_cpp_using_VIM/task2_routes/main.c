#include <ncurses.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

#include "file_utils.h"

#define FILENAME "routes.db"
#define MAX_ROUTES 100

void input_route_screen(ROUTE *r);
void display_routes(ROUTE *routes, size_t n);
void search_routes(ROUTE *routes, size_t n);

int main() {
    DBHeader header = { .signature = "CHAT", .tx_count = 0 };
    ROUTE *routes = NULL;
    size_t count = 0;

    if (access(FILENAME, F_OK) == -1) {
        initscr();
        printw("No database file found. Creating a new one.\n");
        printw("How many routes do you want to enter? ");
        refresh();

        char input[10];
        getstr(input);
        count = atoi(input);

        routes = malloc(sizeof(ROUTE) * count);
        for (size_t i = 0; i < count; ++i) {
            clear();
            printw("Enter route #%lu:\n", i + 1);
            input_route_screen(&routes[i]);
        }

        write_database(FILENAME, &header, routes, count);
        endwin();
    }

    read_database(FILENAME, &header, &routes);
    count = header.num_structs;

    int choice;
    do {
        initscr();
        clear();
        printw("Route Database\n");
        printw("1. Show all routes\n");
        printw("2. Search by station\n");
        printw("3. Add new route\n");
        printw("4. Exit\n");
        printw("Enter your choice: ");
        refresh();

        char ch[4];
        getstr(ch);
        choice = atoi(ch);
        endwin();

        switch (choice) {
            case 1:
                initscr();
                display_routes(routes, count);
                getch();
                endwin();
                break;
            case 2:
                initscr();
                search_routes(routes, count);
                getch();
                endwin();
                break;
            case 3:
                initscr();
                routes = realloc(routes, sizeof(ROUTE) * (count + 1));
                input_route_screen(&routes[count]);
                count++;
                write_database(FILENAME, &header, routes, count);
                printw("Route added successfully!\n");
                getch();
                endwin();
                break;
        }

    } while (choice != 4);

    free(routes);
    return 0;
}

void input_route_screen(ROUTE *r) {
    printw("Start: ");
    getstr(r->start);
    printw("End: ");
    getstr(r->end);
    printw("Route number: ");
    char buffer[10];
    getstr(buffer);
    r->number = atoi(buffer);
}

void display_routes(ROUTE *routes, size_t n) {
    printw("List of Routes:\n");
    for (size_t i = 0; i < n; ++i) {
        printw("%lu. %s → %s [%d]\n", i + 1, routes[i].start, routes[i].end, routes[i].number);
    }
    printw("Press any key to return.\n");
}

void search_routes(ROUTE *routes, size_t n) {
    char input[50];
    printw("Enter station to search: ");
    getstr(input);
    bool found = false;
    for (size_t i = 0; i < n; ++i) {
        if (strcmp(routes[i].start, input) == 0 || strcmp(routes[i].end, input) == 0) {
            printw("%s → %s [%d]\n", routes[i].start, routes[i].end, routes[i].number);
            found = true;
        }
    }
    if (!found) {
        printw("No matching routes found.\n");
    }
    printw("Press any key to return.\n");
}