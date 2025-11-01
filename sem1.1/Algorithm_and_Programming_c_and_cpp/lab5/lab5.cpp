/**
 * Практическое занятие №5. "Старые" потоковые функции стандартной библиотеки.
 * Указатели на функции. Структуры.
 */
/**
* Practical lesson No. 5. The "old" streaming functions of the standard library.
 * Pointers to functions. Structures.
 */

#include <iostream>
#include "other.h"
#include <cstdio>
#include <cmath>//for pow()
#include <algorithm>
#include <climits>
#include <cstdlib>//for dynamic memory allocation
#include "matrix.h"

using namespace std;

int main()
{
    /**
     * Задание 1. "Старые" потоковые функции стандартной библиотеки.
     *
     * Эти функции использовались в языке C. Если вы будете писать программы на
     * нем, вам придется использовать их вместо std::cin и std::cout.
     */
    /**
* Task 1. The "old" streaming functions of the standard library.
     *
* These functions were used in the C language. If you write programs in
* it, you will have to use them instead of std::cin and std::cout.
     */
    

    /**
     * Задание 1.1.
     *
     * С помощью функции scanf сформирйуте три коэффициента: A,B,C.
     */
    /**
     *Task 1.1.
     *
     * Using the scanf function, you will generate three coefficients: A, B, C.
     */
    {   
        double A,B,C;//declare variables for the coefficientsq

        getCoefficients(A,B,C);

     }

    /**
     * Задание 1.2.
     *
     * Выведите (красиво!) таблицу значений y=A*x*x + B*x + C при изменении x в
     * диапазоне -2 до +2 с шагом 0.5
     */
    /**
     *Task 1.2.
     *
     * Print (nicely!) a table of values ​​y=A*x*x + B*x + C when x changes in
     * range -2 to +2 in steps of 0.5
     */
    {
        double A,B,C;//coefficients

        printf("enter A, B , C : ");
        scanf("%lf %lf %lf", &A, &B, &C);

        printTable(A, B, C);

    }
    

    /**
     * Задание 2. Указатели на функции.
     */
    /**
     *Task 2. Function pointers.
     */

    /**
     * Задание 2.1. Указатель на функцию. "Калькулятор".
     *
     * Напишите функции:
     * 1. add - принимает два значения double и возвращает сумму этих значений;
     * 2. sub- принимает два значения double и возвращает разность этих
     *    значений;
     * 3. mul - аналогично для умножения;
     * 4. div - аналогично для деления;
     * 5. а для возведения в степень можете использовать функцию стандартной
     *    библиотеки - pow(). 
     *
     * Подсказка 1: прототип функции находится в <cmath>.
     * Подсказка 2: стандартная библиотека предоставляет несколько
     * перегруженных вариантов этой функции, а Вам потребуется сформировать
     * указатель на double pow(double, double).
     *
     * Предоставьте пользователю следующую возможность:
     *
     * - пока пользователь хочет пользоваться услугами вашего калькулятора, он
     *   может вводить два значения и знак операции а вы выводите результат. 
     * - результат получаете посредством вызова соответствующей вашей функции
     *   по указателю.
     * - предусмотрите возможность ввода непредусмотренного знака операции.
     */
    /**
* Task 2.1. Function pointer. "Calculator".
     *
* Write the functions:
* 1. add - takes two double values and returns the sum of these values;
     * 2. sub- takes two double values and returns the difference of these
     * values;
     * 3. mul - similar for multiplication;
     * 4. div - similar for division;
     * 5. and for exponentiation, you can use the standard function
     * libraries - pow(). 
     *
* Hint 1: The prototype of the function is located in <cmath>.
     * Hint 2: The standard library provides several
     * overloaded versions of this function, and you will need to generate
     * pointer to double pow(double, double).
     *
* Provide the user with the following option:
     *
* - as long as the user wants to use the services of your calculator, he
* can enter two values and the operation sign and you output the result. 
     * - you get the result by calling your corresponding function
     * by the pointer.
     * - provide for the possibility of entering an unintended operation sign.
     */
    {
        double (*operation)(double, double);//define a function pointer for operation

        double a, b;
        char op;//console operation

        while(true){
            cout<<"enter optoin (+, -, *, /, ^) or q/Q to quit : ";
            cin>>op;

               if (op == 'q' || op == 'Q') {
                    cout << "exiting the program." << endl;
                    break;//exit the loop if user enters q or Q
               }
               cout<<"enter two nums : ";

                cin>>a>>b;
                cout<<endl;
            switch(op){//seting the operation based on the user's input
                case '+':
                    operation = add;
                    break;

                case '-':
                    operation = sub;
                    break;

                case '*':
                    operation = mul;
                    break;

                case '/':
                    if (b==0){
                         cout<<"enter b > 0"<<endl;
                         continue;
                    }
                    operation = div;
                    break;

                case '^':
                    operation = exponentiate;
                    break;

                default:
                    cout<<"invalid oparetion! try again...."<<endl;
                    continue;
            }
             double result = operation(a, b);

             cout<<"Result : "<<result<<endl;

        }

    }

    /**
     * Задание 2.2. Указатель на функцию в качестве аргумента.
     *
     * Дана заготовка функции сортировки любых объектов - sort.
     *
     * Функция принимает следующие параметры:
     * 1. указатель на первый сортируемый элемент
     * 2. количество сортируемых элементов
     * 3. размер элемента в байтах
     * 4. указатель на функцию перестановки элементов
     * 5. указатель на функцию сравнения элементов
     */
    /**
* Task 2.2. A pointer to a function as an argument.
     *
* A blank of the sorting function for any objects is given - sort.
     *
* The function accepts the following parameters:
     * 1. Pointer to the first sortable element
     * 2. The number of sorted items
     * 3. The size of the element in bytes
     * 4. Pointer to the element permutation function
     * 5. Pointer to the element comparison function
     */

    /**
     * Задание 2.2.1.
     *
     * Напишите функцию перестановки двух целых значений - swap_int, которая
     * принимает два void указателя и меняет значения местами.
     *
     * Напишите функцию сравнения двух целых значений - CmpInt, которая
     * принимает два void указателя и возвращает int результат сравнения:  
     * <0 - первый элемент меньше, чем второй;
     * =0 - равны;
     * >0 - первый элемент больше, чем второй.
     *
     * Используйте эти функции в функции сортировки.
     */
    /**
* Task 2.2.1.
*
* Write a function for permuting two integer values - swap_int, which
     * accepts two void pointers and swaps the values.
     *
* * Write a function comparing two integer values - Cmp Int, which
     * accepts two void pointers and returns the int result of the comparison:
* <0 - the first element is smaller than the second;
     * =0 - equal;
     * >0 - the first element is larger than the second.
     *
* Use these functions in the sorting function.
     */
    {
         int nAr[]={98, 3, 90, 2, 7, 1, 4, 6};//массив для сортировки//array for sorting
         int nTotal=sizeof(nAr)/sizeof(nAr[0]);//количество элементов в массиве 

         /** Печать исходного массива **///number of elements in the array
         cout << "original array: ";
         for (int i=0; i< nTotal; ++i) {
             cout << nAr[i] << " ";
          }

        sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(int), swap_int, cmp_int);
        //reinterpret_cast<char*>(&nAr[0]) converts the first elements add to char* for ptr arithmetic
        //nTotal number of elements
        //sizeof(int) size of each elements in bytes
        //swap_int func ptr for swaping elements
        //cmp_int func ptr for comparing elemtnts

          cout<<endl;
          /** Печать результатов сортировки *//** Printing the sorting results */
          cout << "sorted array: ";
          for (int i = 0; i < nTotal; ++i) {
               cout<<nAr[i]<<" ";
          }
          cout<<endl;
    }

    /**
     * Задание 2.2.2.
     *
     * По аналогии с заданием 2.2.1 напишите функцию swap_double и cmp_double,
     * и вызовите функцию sort для сортировки вещественных значений.
     */
    /**
* Task 2.2.2.
*
* By analogy with task 2.2.1, write the function swap_double and cmp_double,
     * and call the sort function to sort the real values.
     */
     {   double nAr[]={98.4,3.4, 6, 90.6, 2.4, 7.7, 1.4, 4.4, 6.6};  //массив для сортировки//array for sorting
         int nTotal=sizeof(nAr) / sizeof(nAr[0]);         //количество элементов в массиве 

        /** Печать исходного массива *///number of elements in the array
          cout << "original array (double): ";
          for (int i = 0; i < nTotal; ++i) {
               cout << nAr[i] << " ";
          }

        sort(reinterpret_cast<char*>(&nAr[0]), nTotal, sizeof(double), swap_double, cmp_double);
        //reinterpret_cast<char*>(&nAr[0]) converts the first elements add to char* for ptr arithmetic
        //nTotal number of elements
        //sizeof(int) size of each elements in bytes
        //swap_int func ptr for swaping elements
        //cmp_int func ptr for comparing elemtnts

          cout << endl;
        /** Печать результатов сортировки *//** Printing the sorting results */
          cout << "sorted array (double): ";
          for (int i = 0; i < nTotal; ++i) {
               cout << nAr[i] << " ";
          }
          cout << endl;

     }

    /**
     * Задание 2.2.3.
     *
     * По аналогии с 2.2.1 создайте вспомогательные функции - swap_str и
     * cmp_str и вызовите функцию sort для сортировки массива указателей на
     * строки.
     */
    /**
* Task 2.2.3.
*
* By analogy with 2.2.1, create auxiliary functions - swap_str and
* cmp_str and call the sort function to sort an array of pointers to
* strings.
     */

    {
        const char* arStr[] = {"QQQ", "SDF", "ABC"};
        int nTotal=sizeof(arStr) / sizeof(arStr[0]);

          //Print the original array
          cout << "Original array: ";
          for (int i = 0; i < nTotal; ++i) {
               cout << arStr[i] << " ";
          }
          cout << endl;

          // Sort the array of strings using the sort function
          sort(reinterpret_cast<char*>(&arStr[0]), nTotal, sizeof(const char*), swap_str, cmp_str);
          //reinterpret_cast<char*>(&nAr[0]) converts the first elements add to char* for ptr arithmetic
          //nTotal number of elements
          //sizeof(int) size of each elements in bytes
          //swap_int func ptr for swaping elements
          //cmp_int func ptr for comparing elemtnts

          cout << endl;
          
          cout << "Sorted array: ";//print the sorted array
          for (int i = 0; i < nTotal; ++i) {
               cout << arStr[i] << " ";
          }
          cout << endl;
    }

    /**
     * Задание 2.3. Массивы указателей на функцию.
     *
     * Напишите функции для работы с массивом:
     *
     * 1. print_max - печатает максимальный элемент;
     * 2. print_min - печатает минимальный элемент;
     * 3. sort_asc - сортирует по возрастанию и выводит на печать;
     * 4. sort_desc - сортирует по убыванию и выводит на печать.
     *
     * У всех эти функций должна быть одинаковая сигнатура. Объявите, два
     * массива: массив указателей на функции 1-4 и массив указателей на строки
     * с описанием этих функций.
     *
     * Реализуйте меню для пользователя: выведите нумерованный список имен
     * функций (из второго массива), примите от пользователя номер функции,
     * после чего вызовите функцию для какого-нибудь массива.
     */
    /**
* Task 2.3. Arrays of function pointers.
     *
* Write functions for working with an array:
*
* 1. print_max - prints the maximum element;
     * 2. print_min - prints the minimum element;
     * 3. sort_asc - sorts in ascending order and prints;
     * 4. sort_desc - sorts in descending order and prints.
     *
     * * All these functions must have the same signature. Announce two
     * array: an array of pointers to functions 1-4 and an array of pointers to strings
     * with a description of these functions.
     *
     * Implement a menu for the user: output a numbered list of names
     * functions (from the second array), accept the function number from the user,
     * then call the function for some array.
     */
    {
          
          void (*functions[])(int*, int) = {print_max, print_min, sort_asc, sort_desc};//array of function pointers

          const char* descriptions[] = {//array of descriptions
               "Print Maximum Value",
               "Print Minimum Value",
               "Sort in Ascending Order",
               "Sort in Descending Order"
          };

          int arr[7] = {12, 5, 8, 19, 2, 7, 10};
          cout<<"original arr[] : " ;
          for(int i = 0; i < 7; i++){
                cout<<arr[i]<<" ";
          }
          cout<<endl;

          int size=sizeof(arr)/sizeof(arr[0]);
          //User menu
          int choice;
          while (true) {
               cout<<"Menu: Choose an operation:" << endl;
               for (int i = 0; i < 4; i++) {
                    cout << i + 1 << ". " << descriptions[i] << endl;
               }
               cout<<"Enter the function number (1-4) or 0 to exit: ";
               cin >> choice;

               if (choice < 1 || choice > 4) {
                    cout<<"Invalid option! Exiting program." << endl;
                    break;  //if invalid
               }
               //calling the selected function
               functions[choice - 1](arr, size);
          }

    

    }

    /**
     * Задание 2.4. Метод прямоугольников.
     *
     * Напишите функцию integrate, которая бы принимала:
     * 1. указатель на интегрируемую функцию, которая принимает double и
     *    возвращает double;
     * 2. нижнюю границу интегрирования (вещественное число);
     * 3. верхнюю границу интегрирования (вещественное число);
     * 4. количество отрезков, на которых будет вычисляться функция.
     *
     * Функция должна возвращать численное значение определенного интеграла,
     * полученного методом прямоугольников.
     *
     * Проверьте функцию на разных вещественных функциях (линейных, параболах,
     * exp, sin) и сравните полученные результаты с теоретическими.
     */
    /**
* Task 2.4. The rectangle method.
     *
* Write an integrate function that accepts:
     * 1. A pointer to an integrable function that accepts a double and
* returns a double;
     * 2. the lower bound of integration (real number);
     * 3. the upper bound of integration (real number);
     * 4. The number of segments on which the function will be calculated.
     *
* The function must return the numerical value of a certain integral,
     * obtained by the rectangle method.
     *
     * Check the function on different real functions (linear, parabolas,
     * exp, sin) and compare the results obtained with the theoretical ones.
     */
    {
          double a = 2.0, b = 3.0;//a=lower bound and b=upper bound
          
          
          int c = 1000; //define the number of segments

          //intrigrating by using rectangular method
          double result_linear = integrate(linear, a, b, c);
          double result_parabola = integrate(parabola, a, b, c);
          double result_exponential = integrate(exponential, a, b, c);
          double result_sine = integrate(sine, a, b, c);

          cout<<"integral of f(x)=5x+ 3 from"<<a<<" to "<<b<<" is: "<<result_linear << endl;
          cout<<"integral of f(x) =x^2 from" << a << " to " << b << " is: " << result_parabola << endl;
          cout<<"integral of f(x)= e^x from" << a << " to " << b << " is: " << result_exponential << endl;
          cout<<"integral of f(x)=sin(x) from " << a << " to " << b << " is: " << result_sine << endl;
  
    }

    /**
     * Задание 3. Структуры С.
     */
    /**
* Task 3. Structures C.
     */

    /**
     * Задание 3.1. Структура Book.
     */
    /**
* Task 3.1. Book structure.
     */

    /**
     * Задание 3.1.1.
     *
     * Объявите структуру Book, описывающую книгу (автор, заглавие, год
     * издания, цена, категория…).
     *
     * Подумайте: какого типа могут быть поля структуры.
     * Подсказка: объявление структуры рекомендуется выносить в заголовочный
     * файл.
     */
    /**
* Task 3.1.1.
*
* Declare the Book structure describing the book (author, title, year
     * editions, price, category...).
     *
* Think about what type of structure fields can be.
     * Hint: it is recommended to place the structure declaration in the header
     * file.
     */
    {     
           
    Book myBook;

    addBook(myBook, "K. G.", "Russan Language", 2023, 1299, "Russian Language Grammar");//initializing

    displayBook(myBook);

    freeBook(myBook);//calling free memory function

    }

    /**
     * Задание 3.1.2.
     *
     * Создайте разными способами (глобальный, локальный, статический,
     * динамический) экземпляры (объекты) типа Book (без инициализации).
     *
     * Определите - сколько памяти отводит компилятор под каждый такой объект. 
     *
     * Как инициализируются (или не инициализируются) поля структуры?
     *
     * Подумайте: от чего зависит объем выделяемой памяти?
     */
    /**
* Task 3.1.2.
*
* Create in different ways (global, local, static,
     * dynamic) instances (objects) of the Book type (without initialization).
     *
* Determine how much memory the compiler allocates for each such object. 
     *
* How are the fields of the structure initialized (or not initialized)?
     *
* Think about it: what determines the amount of memory allocated?
     */
    {
          
          static Book globalBook;//global instance
    
          Book localBook;//local instance
    
          static Book staticLocalBook;//static local instance
    
          Book* dynamicBook = new Book;//dynamic instance

    // Display memory allocation sizes
    cout<<"Size of global instance: "<<sizeof(globalBook)<<" bytes"<<endl;
    cout<<"Size of local instance: " <<sizeof(localBook)<<" bytes"<<endl;
    cout<<"Size of static local instance: " <<sizeof(staticLocalBook)<<" bytes"<<endl;
    cout<<"Size of dynamic instance: " <<sizeof(*dynamicBook)<<" bytes"<<endl;

    // for global and static instances, the fields of the structure will be initialized to default values.
    // that is, for `int` it will be 0, for `double` it will be 0.0, and for `char` or `string` it will be an empty string "".
    // for local instances, the fields of the structure may contain any values that were previously in memory.
    // that is, it can lead to undefined behavior.
    // for dynamic instances, the fields are not initialized and may contain undefined values.

    //add and display a book
    addBook(*dynamicBook, "Humayun Ahmed", "Himu", 2012, 500.0, "Story");
    displayBook(*dynamicBook);

    //free memory
    freeBook(*dynamicBook);
    delete dynamicBook;
       
    }

    /**
     * Задание 3.1.3. 
     *
     * Заполните поля созданных объектов.
     *
     * Замечание: если для хранения строки используется массив, необходимо
     * предусмотреть "защиту" от выхода за границы массива.
     */
    /**
* Task 3.1.3.
*
* Fill in the fields of the created objects.
     *
* Note: if an array is used to store a string, you must
     * provide "protection" from going beyond the boundaries of the array.
     */
    {
          static Book globalBook; // global instance
          Book localBook;         // local instance
          static Book staticLocalBook; // static local instance
          Book* dynamicBook = new Book; // dynamic instance using new

          addBook(globalBook, "Iradov", "Jadachi pa figike", 1988, 1000.0, "Science");
          addBook(localBook, "George Orwell", "1984", 1949, 500.0, "Dystopia");
          addBook(staticLocalBook, "J.K. Rowling", "Harry Potter", 1997, 750.0, "Fantasy");
          addBook(*dynamicBook, "Isaac Asimov", "Foundation", 1951, 600.0, "Science Fiction");

          //display each book
          cout<<"Global Book:"<<endl;
          displayBook(globalBook);

          cout<<"Local Book:"<<endl;
          displayBook(localBook);

          cout<<"Static Local Book:"<<endl;
          displayBook(staticLocalBook);

          cout<<"Dynamic Book:"<<endl;
          displayBook(*dynamicBook);

          //free dynamic memory
          delete dynamicBook;                

    }

    /**
     * Задание 3.1.4. 
     *
     * Напишите функцию, выводящую на экран реквизиты книги.
     *
     * Подумайте: как эффективнее передавать экземпляр Book в функцию.
     *
     * Для вывода на консоль используйте функцию стандартной библиотеки printf.
     */
    /**
* Task 3.1.4.
*
* Write a function that displays the book details on the screen.
     *
* Think about it: how to efficiently pass a Book instance to a function.
     *
* To output to the console, use the printf function of the standard library.
     */
    {
          static Book globalBook;//global instance
          cout<<"Global Book:"<<endl;
          addBook(globalBook, "Iradov", "Jadachi pa figike", 1988, 1000.0, "Science");
          displayBook(globalBook);

    }

    /**
     * Задание 3.1.5.
     *
     * Напишите функцию для формирования полей структуры. Для ввода используйте
     * функцию стандартной библиотеки scanf.
     *
     * Замечание: неплохо заложить в такую функцию возможность проверки
     * корректности введенного значения, например, год издания не может быть
     * меьше, чем... (год появления письменности), категорию ползователь должен
     * выбирать из существующих, цена не может быть отрицательной...
     *
     * Кроме этого необходимо проверить и ошибки другого рода: программа
     * ожидает число, а пользователь ввел случайно букву.
     */
    /**
* Task 3.1.5.
*
* Write a function to form the fields of the structure. To enter, use
     * the function of the standard scanf library.
     *
* Note: it is not a bad idea to include the possibility of verification in such a function
     * the correctness of the entered value, for example, the year of publication cannot be
     * * less than ... (the year of the appearance of writing), the category the user must
     * choose from existing ones, the price cannot be negative ...
*
* In addition, it is necessary to check for other errors: the program
     * a number is waiting, and the user entered a letter by accident.
     */
    {
          const char* validCategories[]={"literature", "dystopia", "fantasy", "science fiction"};
          size_t categoryCount=sizeof(validCategories)/sizeof(validCategories[0]);

          Book book;
          inputBook(book, validCategories, categoryCount);

          displayBook(book);
    }

    /**
     * Задание 3.2. Матричные операции.
     */
    /**
* Task 3.2. Matrix operations.
     */

    /**
     * Задание 3.2.1. 
     *
     * Задайте структуру Matrix, которая будет преставлять вещественную матрицу
     * размера MxN из линейной алгебры.
     *
     * Это определение и связанные с ними функции определите в отдельной паре
     * файлов: matrix.h и matrix.cpp.
     */
    /**
* Task 3.2.1.
*
* * Set the Matrix structure that will represent the real matrix
     * of the MxN size from linear algebra.
     *
* Define this definition and related functions in a separate pair
     * files: matrix.h and matrix.cpp .
     */
    {
          Matrix mat = createMatrix(3, 3);//dymension of matrix

          setElement(mat, 0, 0, 3.1);//initializing elements
          setElement(mat, 0, 1, 4.8);
          setElement(mat, 0, 2, 7.3);

          cout<<"matrix:"<<endl;//show matrix
          displayMatrix(mat);

          cout<<"\nElement at (1,1): "<<getElement(mat, 1, 1)<<endl;//checking

          deleteMatrix(mat);//free memory
          
    }

    /**
     * Задание 3.2.2.
     *
     * Создайте набор базовых функций для работы с этой структурой:
     *
     * - void m_zero(Matrix *A, int m, int n) - инициализация матрицы размера m
     *   на n нулями;
     * - void m_id(Matrix *A, int n) - инициализация единичной матрицы n на n;
     * - void m_free(Matrix *A) - очистка памяти, используемой для матрицы;
     * - void m_copy(const Matrix *src, Matrix *dst) - копирование данных
     *   матрицы src в матрицу dst.
     * - int m_width(const Matrix *A) - ширина матрицы A;
     * - int m_height(const Matrix *A) - высота матрицы A;
     * - double m_get(const Matrix* A, int i, int j) - получение i,j-того
     *   элемента матрицы;
     * - void m_set(Matrix *A, int i, int j, double value) - установка i,j-того
     *   элемента матрицы.
     */
    /**
* Task 3.2.2.
*
* Create a set of basic functions to work with this structure:
*
* - void m_zero(Matrix *A, int m, int n) - initialization of a matrix of size m
* by n zeros;
     * - void m_id(Matrix *A, int n) - initialization of the unit matrix n by n;
     * - void m_free(Matrix *A) - clearing the memory used for the matrix;
     * - void m_copy(const Matrix *src, Matrix *dst) - copying data
     * src matrices to the DST matrix.
     * - int m_width(const Matrix *A) - width of matrix A;
     * - int m_height(const Matrix *A) - height of matrix A;
     * - double m_get(const Matrix* A, int i, int j) - getting i,j-that
     * matrix element;
     * - void m_set(Matrix *A, int i, int j, double value) - setting i,j-value
     * an element of the matrix.
     */
    {
          Matrix A;
          m_zero(&A, 3, 3);//initializing

          m_set(&A, 0, 0, 5.1);//setting some elements
          m_set(&A, 1, 1, 1.2);
          m_set(&A, 2, 2, 7.3);

          cout<<"Matrix A:"<<endl;
          displayMatrix1(A);

          cout<<"Width: "<<m_width(&A)<<", Height: "<<m_height(&A)<<endl;//getting dimensions

          Matrix B;//coping the matrix
          m_copy(&A, &B);
          cout<<"Copied Matrix B:" <<endl;
          displayMatrix1(B);

          //free memory
          m_free(&A);
          m_free(&B);
     }

    /**
     * Задание 3.2.3.
     *
     * Реализуйте набор операций из линейной алгебры:
     *
     * - int m_add(Matrix *A, const Matrix *B) - если A и B одинакового
     *   размера, то прибавляет к A значения B и возвращает 0; иначе возвращает
     *   1.
     * - void m_neg(Matrix *A) - заменяет все элементы матрицы A на
     *   противоположные.
     * - int m_mult(const Matrix *A, const Matrix *B, Matrix *dst) - умножает
     *   матрицу A на матрицу B и сохраняет результат в dst. Если размеры
     *   матрицы не позволяют умножить матрицы, функция возвращает 1, иначе 0.
     */
    /**
* Task 3.2.3.
*
* Implement a set of operations from linear algebra:
     *
* - int m_add(Matrix *A, const Matrix *B) - if A and B are the same
     * of the size, then adds the values of B to A and returns 0; otherwise it returns
     *   1.
     * - void m_neg(Matrix *A) - replaces all elements of matrix A
with * opposite ones.
     * - int m_mult(const Matrix *A, const Matrix *B, Matrix *dst) - multiplies
     * matrix A to matrix B and stores the result in dst. If the dimensions are
     * matrices do not allow multiplying matrices, the function returns 1, otherwise 0.
     */
    {     
          Matrix A, B, C;

          //initializing matrix A and B
          m_zero(&A, 2, 2);
          m_set(&A, 0, 0, 1.0);
          m_set(&A, 0, 1, 1.0);
          m_set(&A, 1, 0, 1.0);
          m_set(&A, 1, 1, 1.0);

          m_zero(&B, 2, 2);
          m_set(&B, 0, 0, 1.0);
          m_set(&B, 0, 1, 1.0);
          m_set(&B, 1, 0, 1.0);
          m_set(&B, 1, 1, 1.0);

          //add matrices
          if (m_add(&A, &B) == 0) {
               cout<<"after addition matrix A:"<<endl;
               displayMatrix(A);
          } else {
               cout<< "invalid size matrix."<<endl;
          }

          //negate matrix A
          m_neg(&A);
          cout<<"after negation of matrix A:"<<endl;
          displayMatrix(A);

          //mul matrices B and A
          if (m_mult(&B, &A, &C) == 0) {
               cout<<"matrix C (B * A):" <<endl;
               displayMatrix(C);
          } else {
                cout << "invalid matrix cann't be multiplied"<<endl;
          }

          //free memory
          m_free(&A);
          m_free(&B);
          m_free(&C);

    }

    /**
     * Задание 3.2.4.
     *
     * С помощью полученного функционала реализуйте матричное вычисление чисел
     * Фибоначчи. Делается это с помощью такой формулы:
     *
     * /  F[n]  \ = / 1  1 \ * / F[n-1] \
     * \ F[n-1] /   \ 1  0 /   \ F[n-2] /
     *
     * Задайте матрицу в центре и матрицу-вектор с двумя первыми числами
     * Фибоначчи: 1 и 0. Выполняйте эту формулу итеративно и выведите первые 40
     * чисел Фибоначчи.
     */
    /**
* Task 3.2.4.
*
* Use the resulting functionality to implement the matrix calculation of numbers
     * Fibonacci. This is done using the following formula:
     *
     * /  F[n]  \ = / 1  1 \ * / F[n-1] \
     * \ F[n-1] /   \ 1  0 /   \ F[n-2] /
*
* Set the matrix in the center and the matrix vector with the first two numbers
     * Fibonacci: 1 and 0. Follow this formula iteratively and print the first 40
* Fibonacci numbers.
     */
    {
          fibonacci_matrix();
    }

    return 0;
}
