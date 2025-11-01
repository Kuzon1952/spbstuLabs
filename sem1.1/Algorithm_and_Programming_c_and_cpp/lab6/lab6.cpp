#include <iostream>
#include <cstdio>
#include <cstring>
#include "book_catalog.h"

using namespace std;

/**
 * Практическое занятие №6. Консольное приложение.
 *
 * Темы:
 * - динамический массив структур,
 * - добавление, чтение, изменение и удаление структур,
 * - поиск,
 * - сортировка,
 * - сохранение данных в файл и чтение данных из файла,
 * - обработка ошибок пользовательского ввода,
 * - работа с функциями семейства printf и scanf,
 * - функциональная и модульная декомпозиция программы.
 *
 * Отдельные задания в этой работе не нужно выполнять последовательно, в этой
 * работе задания скорее являются требованиями к тому, что ваша программа должна
 * делать.
 *
 * Обратите внимание на следующие указания.
 *
 * 1. Для ввода и вывода данных из консоли и файлов *необходимо* использовать
 *    фукцнии семейства printf и scanf.
 * 2. Ваша программа должна быть оформлена в виде нескольких файлов исходного
 *    кода, каждый из которых реализует набор функций, относящихся к одной теме.
 * 3. В результате работы программы не должно быть утечек памяти.
 * 4. Для каждой функциональности приложения у пользователя должен быть консольный 
 *    интерфейс (см. ниже). Этот интерфейс должен быть устойчив к человеческим ошибкам
 *    (например, если пользователь выбрал несуществующий пункт меню или ввел букву 
 *    вместо числа).
 * 5. Вам необходимо выполнить индивидуальное задание, которое закодировано на странице
 *    http://13633.mooo.com/file/att.html. Напротив вашей фамилии указан тип сортировки,
 *    который вам нужно реализовать и дополнительное задание по номеру:
 *    1) вывести все книги данного автора и/или данного жанра, автор и жанр вводится 
 *       пользователем;
 *    2) найти книгу с самым маленьким годом издания после заданного пользователем года;
 *    3) найти наиболее популярный жанр книг среди книг картотеки;
 *    4) найти минимальный, максимальный, средний (арифметически) и средний в смысле 
 *       медианы год издания книги среди книг в картотеке;
 *    5) найти книги с самым длинным и самым коротким названием.
 * 
 * Консольный интерфейс главного меню может выглядеть примерно так:
 *
 * ```
   Добро пожаловать в библиотеку! Выберите действие:
   1. Распечатать библиотеку.
   2. Добавить книгу.
   ...
   0. Выход из программы.
  
   Ваше действие: _
 * ```
 */
/**
 * Practical Session #6. Console Application.
 *
 * Topics:
 * - dynamic array of structures,
 * - adding, reading, modifying, and deleting structures,
 * - searching,
 * - sorting,
 * - saving data to a file and reading data from a file,
 * - handling user input errors,
 * - working with printf and scanf family functions,
 * - functional and modular decomposition of the program.
 *
 * Individual tasks in this work do not need to be performed sequentially;
 * instead, these tasks represent the requirements your program must fulfill.
 *
 * Pay attention to the following instructions:
 *
 * 1. For input and output of data from the console and files, it is *mandatory*
 *    to use the printf and scanf family functions.
 * 2. Your program should be structured as multiple source code files, each
 *    implementing a set of functions related to a specific topic.
 * 3. The program must not have any memory leaks. 
 * 4. Each functionality of the application must have a console interface (see below).
 *    This interface must be robust against user errors (e.g., if the user selects a
 *    non-existent menu item or enters a letter instead of a number).
 * 5. You need to complete an individual task that is encoded on the webpage
 *    http://13633.mooo.com/file/att.html. Next to your surname, the type of sorting
 *    you need to implement and an additional task are specified:
 *    1) Display all books by a given author and/or of a given genre, with the author
 *       and genre entered by the user;
 *    2) Find the book with the earliest publication year after a year specified
 *       by the user;
 *    3) Find the most popular genre among the books in the catalog;
 *    4) Find the minimum, maximum, average (arithmetic mean), and median
 *       publication years of the books in the catalog;
 *    5) Find the books with the longest and shortest titles.
 *
 * The console interface of the main menu could look something like this:
 *
 * ```
   Welcome to the library! Choose an action:
   1. Print the library.
   2. Add a book.
   ...
   0. Exit the program.
  
   Your action: _
 * ```
 */

/*
TODO:
1. `Search for the book` - enter criterion by number (menu)
2.  Display error - why user input (year, for example) is invalid
3. `Delete a book` - read all line (currently only first word is read)
4. Add a build for program only with the last step - where all the functions are available
*/
int main() {
    //additional task
    {
        printf("\n***** additional task *****\n");
        int choice = 0;

        Catalog catalog; 

        initializeCatalog(&catalog, 5);
        
        //adding books to the catalog
        addBook(&catalog, "Russian Language", "K. G. Ovcenokov", 2023, "Leterature", "Russian for beginners.");
        addBook(&catalog, "Himu", "Humayun Ahmed", 2005, "Story", "Himu and Rupa love story.");
        addBook(&catalog, "The Prophet", "Khalil Zibran", 1984, "Moral", "Spiritual.");

        char userInput;
        bool isCatalogFreed = false;
        bool exitProgram = false;

        while(!exitProgram){
            printf("\nMenu:\n");
            printf("1. Add a new book\n");
            printf("2. Display catalog\n");
            printf("3. Sort catalog\n");
            printf("4. Search for a book\n");
            printf("5. Delete a book\n");
            printf("6. Modify a book\n");
            printf("7. Save catalog to a file\n");
            printf("8. Load catalog from a file\n");
            printf("9. Display books by author and/or genre\n");
            printf("0. Exit\n");
            printf("Choose an option (1 to 0): ");

            scanf(" %c", &userInput);


            switch (userInput) {
                case '1'://add a new book
                    if (!isCatalogFreed) {
                        interactiveAddBook(&catalog);
                    } else {
                        printf("Error: Catalog has been freed. Cannot add new books.\n");
                    }
                    break;
                case '2'://print the catalog
                    if (!isCatalogFreed) {
                        printf("\nCatalog Contents:\n\n");
                        displayCatalog(&catalog);
                    } else {
                        printf("Error: Catalog has been freed. Cannot display books.\n");
                    }
                    break;
                case '3'://sort the catalog
                    if (!isCatalogFreed) {
                        sortingMenu(&catalog);
                    } else {
                        printf("Error: Catalog has been freed. Cannot sort books.\n");
                    }
                    break;
                case '4'://search for a book
    
                    if (!isCatalogFreed) {
                        // Call searchMenu function which handles all the logic for searching
                        searchMenu(&catalog);
                    } else {
                        printf("Error: Catalog has been freed. Cannot search for books.\n");
                    }
                    break;
                case '5': { // delete a book
                    if (!isCatalogFreed) {
                        // Call the interactive function to delete a book
                        interactiveDeleteBook(&catalog);
                    } else {
                        printf("Error: Catalog has been freed. Cannot delete books.\n");
                    }
                    break;
                }
                case '6':  // Modify a book
                    if (!isCatalogFreed) {
                        interactiveModifyBook(&catalog);  // Pass the pointer to catalog
                    } else {
                        printf("Error: Catalog has been freed. Cannot modify books.\n");
                    }
                    break;

                case '7': {
                    char filename[256];
                    printf("Enter file name to save the catalog: ");
                    scanf(" %255s", filename);
                    saveCatalogToFile(&catalog, filename);
                    break;
                }
                case '8': {
                        char filename[256];
                        printf("Enter file name to load the catalog: ");
                        scanf(" %255s", filename);
                        loadCatalogFromFile(&catalog, filename);
                        break;
                }

                case '9'://display books by author and/or genre
                    
                    displayBooksByAuthorAndGenre(&catalog);
                    
                    break;

                case '0'://exit
                    if (!isCatalogFreed) {
                        freeCatalog(&catalog);
                        isCatalogFreed = true;
                        printf("Catalog resources freed. Exiting the program. Goodbye!\n");
                    } else {
                         printf("Catalog has already been freed. Exiting the program...!\n");
                    }
                    exitProgram = true;//set flag to exit loop
                    break;
                default:
                    printf("Invalid option. Please choose a valid option (1-10).\n");
                    break;
            }
        }

    }

    return 0;
}

//g++ -fsanitize=address lab6.cpp  task1Book_Catalog.cpp task3AddingANewBook.cpp task4Sorting.cpp task5Searching.cpp task6Deleting.cpp task7Modifying.cpp task8WritingReading.cpp additionalTask.cpp -o test3.4
    /**
     * Задание 1. Создание «картотеки» книг.
     * «Картотека» — это динамический массив структур.
     * Реализуйте структуру, которая хранит информацию о книгах:
     * название, автор, год издания, жанр, краткое описание.
     *
     * Важно! Массив должен быть динамическим, то есть его размер
     * будет увеличиваться по мере добавления книг. Для этого
     * нужно использовать динамическое выделение памяти с
     * последующим расширением массива по мере необходимости.
     * Старайтесь не выделять память слишком часто,
     * чтобы не ухудшить производительность, используйте стратегию
     * "перераспределения" с увеличением массива на определенный коэффициент
     * (например, на 1.5x).
     *
     * Пользователь должен иметь возможность выполнять следующие действия:
     * 
     * 1. Распечатать содержимое картотеки.
     * 2. Добавить новую книгу.
     * 3. Удалить книгу по названию.
     * 4. Изменить информацию о книге (например, изменить описание).
     * 5. Сохранить текущее содержимое картотеки в файл.
     * 6. Загрузить содержимое картотеки из файла.
     * 7. Действие по вашему варианту.
     * 8. Выйти из программы.
     */
/**
 * Task 1: Creating a "book catalog."
 * The "catalog" is a dynamic array of structures.
 * Implement a structure to store information about books:
 * title, author, year of publication, genre, and a short description.
 *
 * Important! The array must be dynamic, meaning its size
 * should increase as books are added. For this,
 * you need to use dynamic memory allocation and expand the array
 * as needed. Try not to allocate memory too frequently,
 * as this can reduce performance. Use a "reallocation" strategy
 * with a growth factor (e.g., 1.5x) to increase the array size.
 *
 * The user should be able to perform the following actions:
 * 
 * 1. Print the contents of the catalog.
 * 2. Add a new book.
 * 3. Delete a book by its title.
 * 4. Modify the information about a book (e.g., update the description).
 * 5. Save the current contents of the catalog to a file.
 * 6. Load the contents of the catalog from a file.
 * 7. Perform an action based on your variant.
 * 8. Exit the program.
 */





    /**
     * Задание 2. Печать картотеки.
     *
     * Реализуйте печать картотеки на экран по запросу пользователя.
     */
    /**
 * Task 2: Printing the catalog.
 *
 * Implement functionality to print the catalog to the screen upon user request.
 */

        



    /**
     * Задание 3. Добавление новой книги.
     *
     * Реализуйте для пользователя возможность добавлять новые книги с заполнением полей
     * книги в интерактивном режиме.
     *
     * При этом необходимо обработать некорректный пользовательский ввод.
     */
    /**
 * Task 3: Adding a new book.
 *
 * Implement functionality that allows the user to add new books by filling in 
 * the book's fields in an interactive mode.
 *
 * Make sure to handle invalid user input appropriately.
 */




    /**
     * Задание 4. Сортировка книг.
     *
     * Реализуйте возможность сортировать картотеку по одному из полей по выбору
     * пользователя. Учтите сортировку по возрастанию и убыванию.
     *
     * Учтите, что сортировка должна быть стабильное, то есть менять порядок
     * книг с одинаковыми значениями критерия.
     *
     * Алгоритм сортировки должен быть выбран согласно вашему варианту.
     *
     * Задание со * (опционально): реализуйте сортировку по нескольким полям.
     */
    /**
 * Task 4: Sorting books.
 *
 * Implement functionality to sort the catalog by a field chosen by the user. 
 * Support both ascending and descending order sorting.
 *
 * Ensure that the sorting is stable, meaning the relative order of books 
 * with identical criteria values should remain unchanged.
 *
 * The sorting algorithm should be chosen based on your assigned variant.
 *
 * Optional (*) Task: Implement sorting by multiple fields.
 */



    /**
     * Задание 5. Поиск книг.
     *
     * Реализуйте поиск книг по одному из критериев:
     * - по названию книги,
     * - по автору,
     * - по жанру.
     */
    /**
 * Task 5: Searching for books.
 *
 * Implement functionality to search for books based on one of the following criteria:
 * - by title,
 * - by author,
 * - by genre.
 */



    /**
     * Задание 6. Удаление книги.
     *
     * Реализуйте удаление книги из картотеки. При этом следите, чтобы память
     * освобождалась корректно и, когда книг останется меньше, чем выделено памяти,
     * перевыделите память.
     *
     * Задание со * (опционально): реализуйте "отмену" последних k-операций.
     */
    
    /**
 * Task 6: Deleting a book.
 *
 * Implement functionality to delete a book from the catalog. Ensure that memory
 * is properly freed, and when the number of books becomes smaller than the allocated
 * memory, reallocate the memory accordingly.
 *
 * Optional (*) Task: Implement an "undo" feature for the last k operations.
 */
  


    /**
     * Задание 7. Изменение книги.
     *
     * Реализуйте изменение полей уже добавленной книги. При этом так же, как и при 
     * добавлении книги, обработайте ошибки.
     */
    /**
 * Task 7: Modifying a book.
 *
 * Implement functionality to modify the fields of an already added book. 
 * As with adding a book, handle errors appropriately.
 */

    /**
     * Задание 8. Запись в файл и чтение из файла.
     *
     * Реализуйте сохранение картотеки в файл и чтение из него. При этом сделайте 
     * возможность пользователю выбрать файл для чтения и записи.
     *
     * Обработайте ошибки связанные с выбором несуществующего файла или файла с 
     * неверным форматом.
     */
    /**
 * Task 8: Writing to and reading from a file.
 *
 * Implement functionality to save the catalog to a file and read from it. 
 * Allow the user to choose the file for reading and writing.
 *
 * Handle errors related to selecting a non-existent file or a file with an invalid format.
 */





