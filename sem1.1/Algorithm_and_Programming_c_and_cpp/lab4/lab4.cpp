/**
 * Практическое занятие №4. Функции. Объявление, определение, вызов. Передача
 * параметров. Возвращение значения.
 */
/**
* Practical lesson #4. Functions. Declaration, definition, call. Passing
* parameters. Returning a value.
*/
#include <iostream>
#include "other.h"
#include <cstdio>
#include <cstdarg>//for assert
#include <cstdlib>//for random number genaration
#include <ctime>//seeding random number geranation
#include <cstdarg>//for


// g++ -g other.cpp lab4.cpp
using namespace std;

int main()
{
    /**
     * Задание 1. Ссылки.
     *
     * Объявите ссылку на тип double. Посредством ссылки измените значение.
     */
    /**
* Task 1. References.
*
* Declare a reference to type double. Change the value via the reference.
*/

    {
        double val = 7.9;//declare a dauble variable

        double& ref = val;//declare a reference to the double variable

        cout<<"initial value : " << val << endl;//7.9

        ref = 18.6;//changing the value via referencing

        cout<< "updated value via reference : " << val << endl;//18.6


    }

    /**
     * Раскомментируйте следующую строку. 
     *
     * Объясните, почему возникает ошибка? Что следует сделать, чтобы
     * компилятор не выдавал ошибки?
     */
    /**
* Uncomment the following line.
*
* Explain why the error occurs? What should be done to prevent the
* compiler from giving errors?
*/
    {
        // int &ref = 1;
        const int &ref = 1;//a reference must always refer to a valid memory location of an exiting variable. here, this reference to bind to the rvalue 1

        cout<<"reference to rvalue: "<<ref <<endl;//1
        
    }

    /**
     * Ниже задан указатель `pc`, задайте ссылку на этот указатель. 
     *
     * Посредством ссылки измените:
     * 1. значение по адресу;
     * 2. сам адрес.
     */
    /**
* Below is a `pc` pointer, set a reference to that pointer.
*
* By reference, change:
* 1. the value at the address;
* 2. the address itself.
*/

    {
        char c='A';//original character variable
        char d='B';//another char to demonstrate address change
        char* pc = &c;//pointer to c

        char*& refToPtr = pc;//create a reference to the pointer

        *refToPtr = 'Z';//modify the value at the address

        cout<<"value pc after modification: "<< *pc << endl;//Z

        refToPtr = &d;
        
        cout<<"value pc after the address change: "<< *pc << endl;//B

    }

    /**
     * Задание 2. Передача параметров в функцию.
     */
    /**
* Task 2. Passing parameters to a function.
*/

    /**
     * Задание 2.1.
     *
     * Объявите и определите три функции, которые увеличивают заданное с
     * помощью параметра значение на 1:
     *
     * 1. функция inc_by_value() - в нее аргумент передается по значению;
     * 2. функция inc_by_pointer() - в нее аргумент передается по указателю;
     * 3. функция inc_by_reference() - в нее аргумент передается по ссылке.
     *
     * Поместите объявления этих функций в заголовочный файл `other.h`, а их
     * определение в `other.cpp`.
     */
    /**
* Task 2.1.
*
* Declare and define three functions that increase the value specified by
* the parameter by 1:
*
* 1. inc_by_value() function - the argument is passed to it by value;
* 2. inc_by_pointer() function - the argument is passed to it by pointer;
* 3. inc_by_reference() function - the argument is passed to it by reference.
*
* Place the declarations of these functions in the `other.h` header file, and their
* definition in `other.cpp`.
*/

    //Замечание: объявления функций принято помещать в заголовочный файл
    //Note: It is common practice to place function declarations in a header file
    {
        /** 
         * Значение этой переменной должно быть увеличено с помощью каждой из
         * функций на единицу.
         */
        /**
* The value of this variable must be increased by one by each of the
* functions.
*/
        int val = 6;

        cout <<"initial value : "<<val << endl;

        //call by the value
        inc_by_value(val);
        cout<<"after inc_by_value: "<< val <<endl;

        //call by the pointer
        inc_by_pointer(&val);
        cout<<"after inc_by_pointer: "<< val <<endl;

        //call by the reference
        inc_by_reference(val);
        cout<<"after inc_by_reference: "<< val <<endl;


    }

    /**
     * Задание 2.2. Передача параметров c помощью указателя и по ссылке.
     * Перегруженные имена функций.
     *
     * Создайте функцию (функции) swap(), которая меняет значения переменных nX
     * и nY местами:
     *
     * 1. Функция должна принимать два указателя на int, оперируя с которыми
     *    менять значения переменных в вызывающей программе. 
     * 2. Функция должна принимать две ссылки на int. 
     *
     * Проверьте правильность с помощью приведенного ниже фрагмента.
     */
    /**
* Task 2.2. Passing parameters by pointer and by reference.
* Overloaded function names.
*
* Create a function (functions) swap() that swaps the values ​​of the variables nX
* and nY:
*
* 1. The function must accept two pointers to int, and use them to
* swap the values ​​of the variables in the calling program.
* 2. The function must accept two references to int.
*
* Check the correctness using the fragment below.hj
*/

    {
        int nX = 1;
        int nY = -10;

        /** поменяли местами значения nX и nY с помощью указателей на nX и nY */
        /** swapped the values ​​of nX and nY using pointers to nX and nY */
        cout<<"before swap (by pointer) : nX = "<< nX << ", nY = "<< nY << endl;
        swap(&nX, &nY);//calling function using pointer
        cout<<"after swap (by pointer): nX = "<< nX << ", nY = "<< nY << endl;

        /** а теперь обратно с помощью ссылок на nX и nY */
        /** and now back using references to nX and nY */
        cout<<"before swap (by ref): nX = "<< nX << ", nY = "<< nY << endl;   
        swap(nX, nY);//calling function using reference
        cout<<"after swap (by ref) : nX = "<< nX << ", nY = "<< nY << endl;

        
    }

    /**
     * Задание 3. Указатели на массивы в качестве аргументов.
     */
    /**
     * Task 3. Pointers to arrays as arguments.
     */

    /**
     * Задание 3.1. Поиск минимума в массиве.
     *
     * Напишите следующие функции для поиска минимума в целочисленном массиве:
     *
     * 1. Для поиска в одномерном массиве.
     * 2. Для поиска в двумерном динамическом массиве (массиве указателей).
     *
     * Что надо передать в такую функцию кроме самого массива?
     *
     * Постарайтесь использовать во второй функции первую, чтобы не повторять
     * логику.
     */
    /**
     *Task 3.1. Finding the minimum in an array.
     *
     * Write the following functions to find the minimum in an integer array:
     *
     * 1. To search in a one-dimensional array.
     * 2. To search in a two-dimensional dynamic array (array of pointers).
     *
     * What should be passed to such a function besides the array itself?
     * ans: 1d array: the array itself and size
     * 2d array: 2d array number of rows and cols
     *
     * Try to use the first function in the second function so as not to repeat
     * logic.
     */
    {
        /** Задайте массивы для проверки и проверьте результат работы функции */

        /** 
         * Покажите, как можно использовать эту функцию для встроенных
         * двумерных массивов.
         */
        /** Set arrays to check and check the result of the function */

        /** 
         * Show how this function can be used for built-in
         * two-dimensional arrays.
         */
        int arr1D[]={19,7,3,5,2,4,5};
        int size1D = sizeof(arr1D)/sizeof(arr1D[0]);
        int min1D = findMin1D(arr1D, size1D);
        cout<<"min in 1D array: " << min1D << endl;

        int rows = 3, cols = 3;
        int** arr2D = new int*[rows];

        for(int i = 0; i< rows; ++i){
            arr2D[i] = new int[cols];
        } 

        arr2D[0][0] = 23; arr2D[0][1] = 34; arr2D[0][2] = 34;
        arr2D[1][0] = 3; arr2D[1][1] = 4; arr2D[1][2] = 5;
        arr2D[2][0] = 34; arr2D[2][1] = 55; arr2D[2][2] = 4;

        int min2D = findMin2D(arr2D, rows, cols);
        cout<<"min in 2d arr : " << min2D << endl;

        for(int i=0; i<rows; ++i){
          delete[] arr2D[i];
        }
        delete[] arr2D;

    }

    /**
     * Задание 3.2. Сравнение строк.
     *
     * Напишите функцию сравнения двух строк - my_str_cmp().
     *
     * Функция должна принимать два указателя на сравниваемые строки.
     *
     * Функция должна возвращать отрицательное значение, если первая строка
     * лексиграфически меньше второй, 0 - если они равны и положительное
     * значение, если первая строка больше второй.
     *
     * Вспомните, что признаком конца строки является нулевой байт.
     */
    /**
     *Task 3.2. String comparison.
     *
     * Write a function for comparing two strings - my_str_cmp().
     *
     * The function must accept two pointers to the strings being compared.
     *
     * The function must return a negative value if the first row
     * lexigraphically less than the second, 0 - if they are equal and positive
     * value if the first line is greater than the second.
     *
     *Remember that the end of string is a null byte.
     */

    {
     
        /** Создайте две строки для сравнения */
        /** Create two strings to compare */
        const char str1[]="cola";
        const char str2[]="limon";

        /** Вызовите функцию сравнения */
        /** Call the comparison function */
        int result = my_str_cmp(str1, str2);
        
        /** Выведите результат сравнения с помощью cout */
        /** Print the result of the comparison using cout */
        cout<<"result : " << result<<endl;
          

    }

    /**
     * Задание 3.3. Типизация параметров и проверка предварительных условий.
     */
    /**
     *Task 3.3. Typing parameters and checking preconditions.
     */

    /**
     * Задание 3.3.1.
     *
     * При передаче данных по ссылке или по указателю хорошим тоном является
     * указывать, собирается ли функция менять данные по этим адресам или нет,
     * с помощью константности указателя (вспоминаем лабораторную №2).
     *
     * Задайте в заданиях 3.1 и 3.2 те указатели, которые используются только
     * на чтение, константными.
     */
    /**
     *Task 3.3.1.
     *
     * When passing data by reference or by pointer, it is good practice to
     * indicate whether the function is going to change data at these addresses or not,
     * using pointer constancy (remember laboratory No. 2).
     *
     * Set in tasks 3.1 and 3.2 those pointers that are used only
     * for reading, constant.
     */
     {
          const char str1[] = "new year is comming and i'm far from home"; 
          const char str2[] = "i am missing my family";
          int result = my_str_cmp(str1, str2);

          cout<<"result : " << result <<endl;

          int arr1D[]={1,2,4,5,6};
          int size1D = sizeof(arr1D)/sizeof(arr1D[0]);
          int min1D = findMin1D(arr1D, size1D);
          cout<< " min in 1D arr: " << min1D << endl;
     }

    /**
     * Задание 3.3.2.
     *
     * К сожалению, система типов языка С (как впрочем и других языков)
     * недостаточно выразительна, чтобы с помощью типов передаваемых параметров
     * выразить ожидания функции по поводу входных данных. Поэтому внутри
     * функций бывает необходимо устанавливать дополнительные проверки.
     *
     * Например, в функциях из задания 3.1 вы, вероятно, передавали в качестве
     * аргумента размер массива и, так же вероятно, что результат выполнения
     * функции не будет иметь смысла, если этот размер меньше 1.
     *
     * Для служебных функций - то есть таких функций, которые используются вами
     * же и вашими коллегами - хорошим тоном является с помощью макроса
     * `assert` из заголовочного файла `cassert`. Для других функций необходимо
     * сигнализовать об ошибке более вдумчиво.
     *
     * Добавьте проверку положительности размера в функции из задания 3.1 и
     * посмотрите, что будет, если в функцию передать некорректное значение.
     *
     * Соберите вашу программу для релиза (с директивой NDEBUG) и выполните код
     * с некорректными значениям. Объясните полученные результаты.
     */
    /**
* Task 3.3.2.
*
* Unfortunately, the type system of the C language (as well as other languages)
* is not expressive enough to use the types of transmitted parameters
     * express the expectations of the function about the input data. Therefore, inside
     * Sometimes it is necessary to install additional checks.
     *
* For example, in the functions from Task 3.1, you probably passed as
     * the argument is the size of the array and it is also likely that the result of the execution
     * functions will not make sense if this size is less than 1.
     *
     * For service functions - that is, such functions that are used by you
     * the same as your colleagues - it is good form to use a macro
     * `assert` from the header file `cassert'. For other functions, it is necessary
     * Signal an error more thoughtfully.
     *
* Add a size positivity check to the functions from Task 3.1 and
* see what happens if an incorrect value is passed to the function.
     *
* Assemble your program for release (with the NDEBUG directive) and execute the code
     * with incorrect values. Explain the results obtained.
     * ans: in the debug mode the assert function checks if the conditionis are true at runtime if an assertioin fails, the program will terminate immediately with an error massage indicating failed
     * g++ -DNDEBUG -o lab4 lab4.cpp
./lab4

     */
    {     
        int arr1D[]={19,7,3,5,2,4,5};
        //int arr1D[]={};
        // int size1D = 0;
        int size1D = sizeof(arr1D)/sizeof(arr1D[0]);
        int min1D = findMin1D(arr1D, size1D);
        cout<<"min in 1D array: " << min1D << endl;

        int rows = 3, cols = 3;
        int** arr2D = new int*[rows];
        for(int i = 0; i< rows; ++i){
          arr2D[i] = new int[cols];
        } 
        arr2D[0][0] = 23; arr2D[0][1] = 34; arr2D[0][2] = 34;
        arr2D[1][0] = 3; arr2D[1][1] = 4; arr2D[1][2] = 5;
        arr2D[2][0] = 34; arr2D[2][1] = 55; arr2D[2][2] = 4;

        int min2D = findMin2D(arr2D, rows, cols);
        cout<<"min in 2d arr : " << min2D << endl;

        for(int i=0; i<rows; ++i){
          delete[] arr2D[i];
        }
        delete[] arr2D;


    }
    
    /**
     * Задание 4. Ссылки в качестве параметров. Передача указателя на
     * встроенный массив в качестве параметра функции.
     *
     * Напишите две взаимодополняющие друг друга функции:
     *
     * 1.  ... day_of_year(...) - преобразует день месяца (число,месяц и год
     *    задаются в качестве параметров) в порядковый день года (возвращаемое
     *    значение);
     * 2. ... day_of_month(...) - функция преобразует порядковый день года в день
     *    месяца (принимает год и порядковый день года в качестве параметров и
     *    должна сформировать день месяца и номер месяца и каким-то образом
     *    сообщить эти значения вызывающей процедуре).
     *
     * Проверьте работоспособность обеих функций с помощью следующего
     * фрагмента.
     */
    /**
* Task 4. Links as parameters. Passing a pointer to the
* embedded array as a function parameter.
     *
* Write two complementary functions:
*
* 1. ... day_of_year(...) - converts the day of the month (date, month and year
     * set as parameters) on the ordinal day of the year (returned
     * value);
     * 2. ... day_of_month(...) - the function converts the ordinal day of the year to a day
     * month (takes the year and the ordinal day of the year as parameters and
     * must form the day of the month and the number of the month and somehow
     * report these values to the calling procedure).
     *
* Check the functionality of both functions using the following
     * a fragment.
     */

    {
        /**
         * В процессе вычислений Вам придется учитывать "високосный -
         * невисокосный" год.
         *
         * Для этого предлагается в каждую функцию в качестве одного из
         * параметров передавать данные приведенного ниже двухмерного массива
         * nDayTab.
         */


        /**
* In the calculation process, you will have to take into account the "leap -
* non-leap" year.
         *
* To do this, it is proposed in each function as one of
         * * parameters to transmit data from the two-dimensional array below
         * nDayTab.
         */
        int nDayTab[2][12] = {
            {31,28,31,30,31,30,31,31,30,31,30,31}, //невисокосный год //not leap year
            {31,29,31,30,31,30,31,31,30,31,30,31}};  //високосный год//leap year

          int day = 11, month =9, year = 2003;

        /** Вызов функции DayOfYear */
        /** Calling the dayOfYear function */
        int ordDay = dayOfYear(day, month, year, nDayTab);
        cout<< "ordinal day of the yr : "<< ordDay << endl;

        /** Проверка результата обратной функцией DayOfMonth */
        /** Checking the result with the inverse dayOfMonth function */
        Date result = dayOfMonth(ordDay, year, nDayTab);
        cout<<"day of the month : "<<result.day<<", Month : "<<result.month<<endl;


    }

    /**
     * Задание 5. 
     *
     * Создайте одномерный динамический массив, заполните его значениями.
     *
     * Напишите функцию add_unique, которая добавляет в массив новое значение
     * только при условии, что такого значения в массиве еще нет. 
     *
     * Для проверки напишите функцию print_array, которая выводит значения всех
     * элементов на экран.
     *
     * Ваша функция должна работать в следующем фрагменте кода.
     */
    /**
* Task 5. 
     *
* Create a one-dimensional dynamic array, fill it with values.
     *
* Write the add_unique function, which adds a new value to the array
     * only if there is no such value in the array yet. 
     *
* To check, write the print_array function, which outputs the values of all
     * items on the screen.
     *
* Your function should work in the following code snippet.
     */

    {
        srand(time(0));
        int n = 5; // сформируйте значение n
        int *arr = new int[n]; // создайте тут массив размера n
        
        /** заполнение случайными значениями */
        for (int i = 0; i < n; ++i) {
            arr[i] = rand() % 10;
        }

        for (int i = 0; i < 100; ++i) {
            int new_value;
            // new_value = ...; // случайное значение
            new_value = new_value % 10; // 0 to 9
            /** вызов функции добавления в массив */
            add_unique(arr, n, new_value);//add if unique  
        }
        
        /** печать массива на экран */
        print_array(arr, n);

        /**
         * Тут должно быть не более 10 + n элементов, так как во втором цикле
         * могут быть получены только 10 разных вариантов.
         */


        delete[] arr;
    }

    /**
     * Задание 6. Рекурсивные функции.
     *
     * Напишите рекурсивную функцию вычисления суммы первых N натуральных
     * чисел.
     */
    /**
     * Задание 6. Рекурсивные функции.
     *
     * Напишите рекурсивную функцию вычисления суммы первых N натуральных
     * чисел.
     */
    /**
     *Task 6. Recursive functions.
     *
     * Write a recursive function to calculate the sum of the first N natural numbers
     * numbers.
     */
    /**
     *Task 6. Recursive functions.
     *
     * Write a recursive function to calculate the sum of the first N natural numbers
     * numbers. 
     * if 5, 5+...+1 =15
     */
     {
          int n;
          cout<<"enter number: ";
          cin>>n;

          cout<<"sum of the first "<<n<<" natural numbers: "<<sumRecursive(n)<<endl;

     }

    /**
     * Задание 7. Кодирование-декодирование информации. Обработка ошибок.
     *
     * Напишите набор функций, которые будут осуществлять кодировку-декодировку
     * информации из "сырых" байтов в ограниченный набор из 32 печатаемых
     * символов из таблицы {A, B, C, ..., Z, 1, 2, 3, 4}. Делается это
     * следующим образом: данная последовательность байтов разделяется на части
     * по 5 бит (если делится неровно - заполняем нулями). Каждая пятерка битов
     * переводится в целое число от 0 до 31 и по этому индексу выбирается
     * символ в таблице.
     *
     * Например, два байта 0x1E47 будут закодированы так:
     *
     * 1. запишем в двоичном виде и разделим на пятерки (дополнив нулями): 
     *    0001 1110 0100 0111 -> 00011 11001 00011 10000
     * 2. каждую пятерку переведем в число:
     *    00011 11001 00011 10000 -> 3 25 3 16
     * 3. Для каждого числа подставим символ из таблицы:
     *    3 25 3 16 -> DZDQ
     *
     * Таким образом из двух байт, которые могут принимать любые значения, мы
     * получили 4 символа из английского алфавита (и нескольких цифр), которые
     * можно, например, напечатать на экран.
     *
     * Напишите семейство функций, которые бы реализовали такое преобразование:
     *
     * 1. int encoded32_size(int raw_size) - функция, которая вычисляет размер
     *    закодированных данных при размере оригинальных данных `raw_size`.
     *
     * 2. int decoded32_size(int encode_size) - функция, обратная первой.
     *
     * 3. int encode32(const char *raw_data, int raw_size, char *dst) - 
     *    функция кодирует "сырые" байты `raw_data` размером `raw_size` и
     *    записывает результат в буфер `dst`; предполагается, что по адресу
     *    `dst` уже выделена память; функция возвращает 0 при удачном
     *    выполнении и возвращает 1, если какой-то из переданных аргументов
     *    имеет недопустимое значение.
     *
     * 4. int decode32(const char *encoded_data, int encoded_size, char *dst) -
     *    функция, обратная третьей; возвращает 0 при успешном декодировании,
     *    1 при недопустимом значении аргументов; 2 при недопустимом символе в
     *    `encoded_data` (не из таблицы).
     *
     * Проверьте правильность работы функций: закодируйте строки разной длины,
     * после чего декодируйте их. Декодированные строки должны совпадать с
     * изначальными.
     */
    /**
* Task 7. Encoding-decoding of information. Error handling.
     *
* Write a set of functions that will perform encoding-decoding
     * information from "raw" bytes to a limited set of 32 printable
     * characters from the table {A, B, C, ..., Z, 1, 2, 3, 4}. This is being done
     * as follows: this byte sequence is divided into parts
     * 5 bits each (if divided unevenly, fill with zeros). Every five bits
     * is converted to an integer from 0 to 31 and selected by this index
     * a symbol in the table.
     *
     * For example, two bytes 0x1E47 will be encoded like this:
     *
* 1. write it in binary form and divide it into fives (adding zeros):
* 0001 1110 0100 0111 -> 00011 11001 00011 10000
* 2. we will convert every five into a number:
     *    00011 11001 00011 10000 -> 3 25 3 16
     * 3. For each number, substitute a symbol from the table:
     *    3 25 3 16 -> DZDQ
     *
* Thus, out of two bytes that can take any value, we
     * received 4 characters from the English alphabet (and several digits), which
     * you can, for example, print to the screen.
     *
* Write a family of functions that would implement such a transformation:
     *
* 1. int encoded32_size(int raw_size) is a function that calculates the size
     * encoded data at the size of the original data `raw_size'.
     *
* 2. int decoded32_size(int encode_size) is the inverse function of the first one.
     *
     * 3. int encode32(const char *raw_data, int raw_size, char *dst) - 
     * the function encodes raw raw_data bytes with the size of raw_size and
     * writes the result to the `dst` buffer; it is assumed that at
     * `dst` has already been allocated memory; the function returns 0 if successful
     * execution and returns 1 if any of the passed arguments
     * has an invalid value.`
     *
* 4. int decode32(const char *encoded_data, int encoded_size, char *dst) -
* function inverse of the third; returns 0 on successful decoding,
     * 1 for an invalid argument value; 2 for an invalid character in
     * `encoded_data' (not from the table).
     *
* Check the correctness of the functions: encode strings of different lengths,
     * then decode them. The decoded strings must match with
     * the original ones.
     */
     { 

    const char raw_data[] = "bangladesh";  
    int raw_size = sizeof(raw_data) - 1;  // size of raw data (excluding null terminator)


    int encoded_size = encoded32_size(raw_size);//calculte the encode size


    char encoded_data[encoded_size + 1];  //arr to store encoded data
    char decoded_data[raw_size + 1];  //arr to store decoded data

    // call the encode_and_decode function and check the return value
    int result = encode_and_decode(raw_data, raw_size, encoded_data, decoded_data);

    // Output 
    if (result == 0) {
        cout << "original: " << raw_data << endl;
        cout << "encoded: " << encoded_data << endl;
        cout << "decoded: " << decoded_data << endl;
    } else if (result == 1) {
        cout << "dncoding failed!" << endl;
    } else if (result == 2) {
        cout << "decoding failed!" << endl;
    }


     }

    /**
     * Задание 8. Функции и макросы с переменным числом параметров.
     */
    /**
     * Задание 8. Функции и макросы с переменным числом параметров.
     */

    /**
     * Задание 8.1.
     *
     * Напишите функцию var_args, которая принимает переменное число аргументов
     * типа int и выводит на печать число принятых параметров и их значения.
     *
     * Функция должна работать с помощью макросов va_start, va_arg и va_end.
     *
     * Признаком конца списка является нулевое значение.
     */
    /**
* Task 8.1.
*
* Write a var_args function that takes a variable number of arguments
     * of the int type and prints the number of accepted parameters and their values.
     *
* The function should work using macros va_start, va_arg and va_end.
     *
* The end of the list is indicated by a zero value.
     */
    {
        int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
        var_args(nN1, 0);//arg 1
        var_args(nN1, nN2, 0);//arg 2
        var_args(nN1, nN2, nN3, nN4, nN5, 0);//arg 3
    }

    /**
     * Задание 8.1.
     *
     * Задайте макрос VAR_ARGS с переменным числом параметров, который будет
     * вызывать функцию var_args с параметрами макроса, но подставлять в конец
     * 0. Таким образом эту функцию можно будет вызывать без нуля в конце.
     */
    /**
* Task 8.1.
*
* Set the VAR_ARGS macro with a variable number of parameters, which will be
     * call the var_args function with macro parameters, but substitute at the end
     * 0. Thus, this function can be called without a zero at the end.
     */

    {
        int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
        VAR_ARGS(nN1); 
        VAR_ARGS(nN1, nN2); 
        VAR_ARGS(nN1, nN2, nN3, nN4, nN5); 
        
    }

    /**
     * Задание 9. Возвращение адреса.
     *
     * Напишите функцию, которая находит минимальное значение в массиве, таким
     * образом, чтобы ее вызов можно было использовать слева от знака
     * равенства: 
     *
     * `*my_min(параметры) = 0;`
     */
    /**
* Task 9. Return the address.
     *
* Write a function that finds the minimum value in the array in such
a way that its call can be used to the left of the sign
     * Equality: 
     *
* `** `*my_mind(parameters) = 0;`
     */
    {
     int arr[] = {5, 2, 3, 1};
     int size = sizeof(arr)/sizeof(arr[0]);

     //using the function to find the minimum value's address and modify it
     *my_min(arr, size) = 0;//set the minimum value to 0

     //print the modified array
     for(int i= 0; i <size; ++i) {
        cout<<arr[i] << " ";
    }
    cout <<endl;



    }

    return 0;
}
