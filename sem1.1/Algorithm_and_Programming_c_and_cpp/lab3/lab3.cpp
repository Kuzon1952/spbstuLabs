#include <iostream>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()
#include <cstring>//for strcmp

using namespace std;
/**
 * Практическое занятие №3. Встроенные массивы. Динамическое выделение памяти.
 * Простейшие алгоритмы сортировки и поиска. Сложные указатели.
 */
/**
 * Practical lesson No. 3. Built-in arrays. Dynamic memory allocation.
 * The simplest sorting and searching algorithms. Complex pointers.
 */

int main()
{
    /**
     * Задание 1. Встроенные массивы.
     */
    /**
     * Task 1. Built-in arrays.
     */

    /**
     * Задание 1.1.
     *
     * Объявите трехмерный N*M*K массив и сформируйте значения
     * элементов, указанные на иллюстрации ниже, с помощью инициализации при
     * объявлении.
     * Declare a three-dimensional N*M*K array and configure the values
     * elements shown in the illustration below, using initialization when
     * advertisement.
     *
     *                   |--------|     
     *                 / |3  3  3 |     
     *               |---------|3 |
     *             / | 2  2  2 |3 |
     *            |---------|2 |__|
     *            | 1  1  1 |2 | /
     *            | 1  1  1 |__| 
     *            | 1  1  1 | /
     *            |_________|
     */
    {  
         cout<<"Задание 1.1 : "<<endl; 
         const int N=3, M=3, K=3;
         
         int array[N][M][K]={{{1,1,1},{1,1,1},{1,1,1}},{{2,2,2},{2,2,2},{2,2,2}},{{3,3,3},{3,3,3},{3,3,3}}};//3d array explicit declaration & initialization

         for(int i=0; i<3; i++){
            cout<< "Layer" << i + 1 << " :" << endl;
            for(int j=0; j<3; j++){
               for(int k=0; k<3; k++){
                  cout<< array[i][j][k]<<" ";//output
               }
               cout<<""<<endl;
            }
            cout<<""<<endl;
         }
         cout<<""<<endl;

    }

    /**
     * Задание 1.2.
     *
     * Объявите неинициализированный массив и присвойте значения элементам с
     * помощью кода так, чтобы в итоге получился такой же массив, как в задании
     * 1.1.
     * 
     * Declare an uninitialized array and assign values ​​to the elements with
     * using code so that you end up with the same array as in the task
     * 1.1.
     */
    {  
         cout<<"Задание 1.2 : "<<endl; 
         const int N=3, M=3, K=3;
         
         int array[N][M][K];//declare uninitialized 3d array

         for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
               for(int k=0; k<3; k++){
                  array[i][j][k]=i+1;//assign value based on the layer
               }
            }
         }

         for(int i=0; i<3; i++){
            cout<< "Layer" << i + 1 << " :" << endl;
            for(int j=0; j<3; j++){
               for(int k=0; k<3; k++){
                  cout<< array[i][j][k]<<" ";//output
               }
               cout<<""<<endl;
            }
            cout<<""<<endl;
         }
         cout<<""<<endl;

    }

    /**
     * Задание 1.3.
     *
     * Напишите код, с помощью которого можно найти сумму элементов массива,
     * полученного в задании 1.
     * 
     * Write a code that can be used to find the sum of the elements of an array,
     * obtained in task 1.
     */
    {  
         cout<<"Задание 1.3 : "<<endl; 
         const int N=3, M=3, K=3;
         int sum=0;//for addition of all elements of the array
         
         int array[N][M][K]={{{1,1,1},{1,1,1},{1,1,1}},{{2,2,2},{2,2,2},{2,2,2}},{{3,3,3},{3,3,3},{3,3,3}}};//3d array initialization

         for(int i=0; i<3; i++){
            cout<< "Layer" << i + 1 << " :" << endl;
            for(int j=0; j<3; j++){
               for(int k=0; k<3; k++){
                  cout<< array[i][j][k]<<" ";//output
                  sum += array[i][j][k];//addition of all elements
               }
               cout<<endl;
            }
            cout<<""<<endl;
         }
         cout<< "sum of all elements of the array :" << sum <<endl;
         cout<<""<<endl;

    }

    /**
     * Задание 1.4.
     *
     * Проинициализируйте массив при объявлении следующим образом:
     * Initialize the array upon declaration as follows:
     *
     *                   |--------|     
     *                 / |3  0  0 |     
     *               |---------|0 |
     *             / | 2  0  0 |0 |
     *            |---------|0 |__|
     *            | 1  0  0 |0 | /
     *            | 0  0  0 |__| 
     *            | 0  0  0 | /
     *            |_________|
     *
     * Как это можно сделать наиболее коротким (в смысле количества кода)
     * образом?
     * 
     * How can this be done in the shortest possible way (in terms of the amount of code)
     * way?
     */
    
      {  
         cout<<"Задание 1.4 : "<<endl; 
         const int N=3, M=3, K=3;
         
         int array[N][M][K]={{{1}},{{2}},{{3}}};//3d array initialization implicit and explicit

         for(int i=0; i<3; i++){
            cout<< "Layer" << i + 1 << " :" << endl;
            for(int j=0; j<3; j++){
               for(int k=0; k<3; k++){
                  cout<< array[i][j][k]<<" ";//output
               }
               cout<<""<<endl;
            }
            cout<<""<<endl;
         }
         cout<<""<<endl;

    }
    

    /**
     * Задание 1.5. Инициализация массивов строковыми литералами.
     * 
     * Объявите и проинициализируйте строковыми литералами два массива:
     * двухмерный массив и массив указателей. Поясните разницу в использовании
     * элементов таких массивов.
     * 
     * Task 1.5. Initializing arrays with string literals.
     * 
     * Declare and initialize two arrays with string literals:
     * two-dimensional array and array of pointers. Explain the difference in use
     * elements of such arrays.
     */
    {
      cout<<"Задание 1.5 : "<<endl;
      char twoDArray[2][20]={"paranoid","blackSabbath"};
      //strings are stored in contiguous memory, allowing direct modification but wasting space if string are shorter than the fixed size
      cout<<"elements of the two-d array: ";
      for(int i=0; i<2; i++){
         cout<<twoDArray[i]<<" ";
      }

      cout<<"\nelements of the array of the pointer: ";
      const char* pointerArray[2]={"paranoid","blackSabbath"};
      //stores address of strings, enabilig filexble memory usage and varying string lentgths but does not allow direct modification of string literals
      for(int i=0; i<2; i++){
         cout<< pointerArray[i]<<" ";
      }

      cout<<""<<endl;

    }

    /**
     * Задание 2. Динамическое выделение памяти.
     */

    /**
     * Задание 2.1.
     *
     * Создайте динамический двухмерный массив с размерностями, вычисляемыми в
     * процессе выполнения программы - N*M, эти размерности можно сформировать
     * случайно в некотором диапазоне или ввести с консоли.
     *
     * Задайте значения элементов помощью генератора случайных чисел. 
     *
     * Найдите сумму элементов.
     *
     * Подсказка 1: для генерации случайных чисел используйте функцию
     * стандартной библиотеки - rand() (<cstdlib>).
     *
     * Подсказка 2: На самом деле те значения, которые создаются генератором
     * случайных чисел являются «псевдослучайными», то есть при двух
     * последовательных запусках приложения Вы получаете две одинаковые
     * последовательности значений.
     *
     * Для того чтобы генерируемые "случайные" значения были разными при каждом
     * запуске приложения используйте функции стандартной библиотеки srand()
     * (<cstdlib>) и time() (<ctime>).
     *
     * Функция srand() осуществляет «привязку» начала генерации к указанному в
     * качестве параметра значению.
     *
     * Функция time() задает эту точку отсчета, считывая текущее время.
     */
    /**
 * Task 2. Dynamic Memory Allocation.
 */

/**
 * Task 2.1.
 *
 * Create a dynamic two-dimensional array with dimensions determined during
 * the execution of the program - N*M. These dimensions can be generated
 * randomly within a certain range or entered from the console.
 *
 * Set the values of the elements using a random number generator.
 *
 * Find the sum of the elements.
 *
 * Hint 1: To generate random numbers, use the standard library function
 * rand() (<cstdlib>).
 *
 * Hint 2: In fact, the values generated by the random number generator are
 * "pseudorandom," which means that two consecutive runs of the application
 * will produce the same sequence of values.
 *
 * To ensure that the generated "random" values are different each time the
 * application runs, use the standard library functions srand()
 * (<cstdlib>) and time() (<ctime>).
 *
 * The srand() function "seeds" the start of generation with the specified
 * parameter value.
 *
 * The time() function sets this starting point by reading the current time.
 */

{

   cout<<"Задание 2.1 : "<<endl;

   srand(static_cast<unsigned>(time(0)));//time(0) gives us current time and srand() for random number and also we are doing cast because of we cant use negative numbers

   int N, M, sum=0;

   cout<<"enter the number of rows: ";
   cin>>N;
   cout<<""<<endl;
   cout<<"enter the number of cols: ";
   cin>>M;
   cout<<""<<endl;

   //dyamically allocate the 2d array
   int** array = new int* [N];//allocate rows

   for(int i =0; i<N; i++){//for cols
      array[i]=new int[M];//allocate collums for each row
   }

   cout<<"\n2D array: "<<endl;
   for(int i=0;i<N; i++){
      for(int j=0; j<M; j++){
         array[i][j]= rand() % 100;//random num between 0 to 99
         cout<<array[i][j] << " ";//print all elements
         sum += array[i][j];
      }
      cout<<endl;
   }
   cout<<"Sum of all elements of the array: "<< sum << endl;

   //deallocate the dynamically allocated memory
   for(int i=0; i<N; i++){
      delete[] array[i];//free each row
   }
   delete[] array;//free the array of pointers
   
   cout<<""<<endl;

}


    /**
     * Задание 2.2.
     *
     * В сформированном массиве отсортируйте каждую строку по убыванию
     * значений. Используйте сортировку "выбором".
     */
    /**
 * Task 2.2.
 *
 * In the created array, sort each row in descending order.
 * Use "selection sort" for sorting.
 */
{

   cout<<"Задание 2.2 : "<<endl;

   srand(static_cast<unsigned>(time(0)));//time(0) gives us current time and srand() for random number and also we are doing cast because of we cant use negative numbers

   int N, M, sum=0;

   cout<<"enter the number of rows: ";
   cin>>N;
   cout<<""<<endl;
   cout<<"enter the number of cols: ";
   cin>>M;
   cout<<""<<endl;

   //dyamically allocate the 2d array
   int** array = new int* [N];//allocate rows

   for(int i =0; i<N; i++){//for cols
      array[i]=new int[M];//allocate collums for each row
   }

   cout<<"\n2D array: "<<endl;
   for(int i=0;i<N; i++){
      for(int j=0; j<M; j++){
         array[i][j]= rand() % 100;//random num between 0 to 99
         cout<<array[i][j] << " ";//print all elements
         sum += array[i][j];
      }
      cout<<endl;
   }
   cout<<"Sum of all elements of the array: "<< sum << endl;

   cout<<"shorting each row in decending order using selection short: "<<endl;
   for(int i=0; i<N; i++){
      for(int j=0; j< M-1; j++){//M-1 because current element with the remaining elements in the row to find max value
         int maxIndex=j;
         for(int k=j+1; k<M;k++){
            if(array[i][k]>array[i][maxIndex]){
               maxIndex=k;
            }
         }
         if(maxIndex != j){
            int temp = array[i][j];
            array[i][j]=array[i][maxIndex];
            array[i][maxIndex]=temp;
         }

      }
   }

   cout<< "Shorted 2d Array: "<<endl;
   for(int i=0; i<N; i++){
      for(int j=0; j<M; j++){
         cout<<array[i][j]<<" ";
      }
      cout<<endl;
   }

   //deallocate the dynamically allocated memory
   for(int i=0; i<N; i++){
      delete[] array[i];//free each row
   }
   delete[] array;//free the array of pointers
   
   cout<<""<<endl;



}


    /**
     * Задание 2.3.
     *
     * Объявите одномерный массив размерностью N. 
     *
     * Сформируйте значение i-ого элемента одномерного массива  равным среднему
     * значению элементов i-ой строки двухмерного массива.
     */
    /**
 * Task 2.3.
 *
 * Declare a one-dimensional array of size N.
 *
 * Set the value of the i-th element of the one-dimensional array equal to the
 * average value of the elements of the i-th row of the two-dimensional array.
 */
{
      cout<<"Задание 2.3 : "<<endl;

      int N,M;
      cout<<"enter the number of rows(N): ";
      cin>>N;
      cout<<"enter the number of cols(M): ";
      cin>>M;

      int** twoDArray = new int* [N];//declare 2d array dynamically
      for(int i=0; i<N; ++i){
         twoDArray[i]=new int [M];
      }

      double* oneDArray = new double[N];//declare a 1d Array for store row avg
      
      cout<<"enter elements of the 2darray row by row: "<< endl;//input from consolde for 2d array
      for(int i=0; i<N; ++i){
         for(int j=0; j<M; ++j){
            cin>> twoDArray[i][j];
         }
      }

      for(int i =0; i<N; ++i){//caculating avg row by row
         double sum =0;
         for(int j=0; j<M; ++j){
            sum += twoDArray[i][j];
         }
         oneDArray[i]=sum/M;
      }

      cout<<"One-dimentional array with row avg: "<<endl;// output 1d array
      for(int i =0; i<N ; ++i){
         cout<<oneDArray[i]<< " ";
      }


      cout<<endl;

      for(int i= 0; i<N; ++i){//free dynamically allocated memory
         delete[] twoDArray[i];
      }
      delete[] twoDArray;
      delete[] oneDArray;

      cout<<endl;

   
}

    /**
     * Задание 2.4. 
     *
     * Убедитесь, что вся выделенная память очищена.
     *
     * Чтобы убедиться в этом, скомпилируйте программу с включенной проверкой
     * утечек памяти - с ключом `-fsanitize=address`:
     *
     * `gcc <ваши обычные флаги> -fsanitize=address lab3.cpp`
     *
     * Если после выполнении программы выдаются сообщения об утечках, это
     * означает, что где-то не удалена выделенная память.
     */
    /**
 * Task 2.4.
 *
 * Make sure that all allocated memory is freed.
 *
 * To verify this, compile the program with memory leak detection enabled using
 * the `-fsanitize=address` flag:
 *
 * `gcc <your usual flags> -fsanitize=address lab3.cpp`
 *
 * If, after running the program, messages about memory leaks appear, it means
 * that some allocated memory was not freed.
 * **/

{
   //g++ -o test2.4 -fsanitize=address lab3.cpp
   //there is no memory leak
}

   
   
    /**
     * Задание 3.
     */

    /**
     * Задание 3.1. Онлайн-упорядочивание.
     *
     * Напишите фрагмент кода, который вводит N целых чисел с помощью потока
     * ввода в объявленный Вами встроенный одномерный массив, каждый раз
     * упорядочивая полученное значение по возрастанию.
     *
     * Дайте оценку количества сравнений и перестановок при вводе всех чисел
     * относительно N.
     *
     * Постарайтесь, чтобы и сравнений, и перестановок было не больше, чем
     * k*N^2, где k - некоторое число.
     */
    /**
* Task 3.1. Online ordering.
     *
* Write a piece of code that enters N integers using a stream
     * input into the built-in one-dimensional array you have declared, each time
     * ordering the resulting value in ascending order.
     *
* Give an estimate of the number of comparisons and permutations when entering all the numbers
     * relative to N.
     *
* Try to have no more comparisons and permutations than
* k*N^2, where k is a certain number.
     */
    
    {
      cout<<"Задание 3.1 : "<<endl;
      int N;
      cout<<"enter the numver of elements (N) : ";
      cin>>N;

      int arr[N];//1d array

      int com = 0;//counting comparisons
      int swaps = 0;//counting swaps

      for(int i=0; i<N; i++){//input and at the same time sorting
         cout<<"enter number: "<<(i+1)<<" : ";
         cin>>arr[i];
         for(int j=i; j>0; --j){
            com++;
            if(arr[j] < arr[j-1]){
               swap(arr[j],arr[j-1]);
               swaps++;
            }
            else{
               break;//stop when order maintrained
            }
         }

      }

      cout<<"Sorted array: "<<endl;
      for(int i=0; i<N; ++i){
         cout<<arr[i]<<" ";
      }
      cout<<endl;

      cout<<"Total comparisons : "<<com<<endl;
      cout<<"total swaps: "<<swaps<<endl;
      cout<<endl;


    }

    /**
     * Задание 3.2. Простой поиск.
     *
     * Модифицируйте предыдущее задание следующим образом:очередное значение
     * вводится в массив только при условии, что там еще такого нет (то есть
     * дубли игнорируются).
     */
    /**
* Task 3.2. Simple search.
     *
* Modify the previous task as follows:the next value
     * is entered into the array only if there is no such thing there yet (that is
     * duplicates are ignored).
     */
    {    
      cout<<"Задание 3.2 : "<<endl;
      
      int N;
      cout<<"enter the number of elements : ";
      cin>>N;

      int* arr= new int[N];//1d array
      int count = 0;//to track the current size of the array
      int com = 0;//counting comparisons
      int swaps = 0;//counting swaps

      for(int i=0; i<N; ++i){
         cout<<"enter number: "<<i+1<<" : ";
         int temp;
         cin>>temp;
         
         //check for duplicates
         bool isDuplicate = false;
         for(int j=0; j < count; ++j){
            com++;
            if(arr[j] == temp){
               isDuplicate = true;
               break;
            }
         }
      

         //if not a duplicate, add and sort
         if(!isDuplicate){
            arr[count]=temp;
            for(int j = count; j>0; --j){
               com++;
               if(arr[j]<arr[j-1]){
                  swap(arr[j],arr[j-1]);
                  swaps++;
               }
               else{
                  break;//stop counting
               }
            }
            count++;
         }
         else{
            cout<<"Duplicate ignore"<<endl;
         }
     }

     cout<<"sorted array without deplicates: " << endl;
      for(int i=0;i<count; ++i){
         cout<<arr[i]<<" ";

     }
     cout<< endl;
     cout<<"total comparisons: "<<com<<endl;
     cout<<"total swaps: "<<swaps<<endl;

     delete[] arr;//free dynamically allocated memory
     cout<<endl;

     
     
     }

     
    /**
     * Задание 4. Сортировка строк.
     *
     * С помощью данной заготовки напишите программу, которая:
     *
     * 1. вводит строки с клавиатуры с помощью cin>>... в объявленный Вами
     *    двухмерный встроенный массив 5*80 элементов типа char; признаком конца
     *    ввода является символ * (то есть строка - "*") или заполнение массива
     *    (больше свободных строк нет);
     * 2. сортирует строки в алфовитном порядке и выводит на экран.
     *
     * Пояснение: крайне не рекомендуется для сортировки сложных объектов
     * физически перемещать их в памяти. Намного эффективнее завести массив
     * указателей на соответствующие строки и перемещать только указатели.
     *
     * Подсказка: для лексиграфического сравнения строк пользуйтесь функцией
     * стандартной библиотеки strcmp(...), заголовочный файл <string>.
     */
    /**
* Task 4. Sorting rows.
     *
* Using this blank, write a program that:
     *
* 1. Enters lines from the keyboard using cin>>... on the day you announced
     * two-dimensional built-in array of 5*80 char elements; a sign of the end
     * the input is the character * (that is, the string is "*") or the filling of the array
     * (there are no more free lines);
     * * 2. Sorts the strings in alphabetical order and displays them on the screen.
     *
* Explanation: It is highly discouraged for sorting complex objects
     * physically move them in memory. It is much more efficient to create an array
     * pointers to the corresponding lines and move only the pointers.
     *
     * * Hint: for lexicographic string comparison, use the function
     * the standard library strcmp(...), header file <string>.
     */

    {
      cout<<"Задание 4 : "<<endl;
        /** Определите необходимые значения как константы */
        /** Define the required values as constants */

        // STOP_STRING  -  "*"  //признак "прекратить ввод"
        // M  -  80 //максимальный размер одной строки
        // N  -  10 //максимальное количество строк в массиве
        // STOP_STRING - "*" //flag for "stop typing"
         // M - 80 //maximum size of one line
        // N - 10 //maximum number of rows in the array

         //const for maximum string length , arr, stop string
        const int M =80;//max size of line
        const int N =10;//max num of rows in the arr
        const char STOP_STRING[] = "*";

        /** 
         * Объявите двухмерный массив с именем cBuffer типа char и размерностью
         * N*M.
         */
        /** 
         * * Declare a two-dimensional array named buffer of type char and dimension
         * N*M.
         */
        char cBuffer[N][M]={0};//declare a 2d arr to store strings

        /**
         * Объявите массив (с именем cPointers) указателей на строки
         * размерностью N.
         *//**
* Declare an array (named cPointers) of pointers to strings
         * dimension N.
         */
        char* cPointers[N]={nullptr};//declare a arr of ptr to strings


        /** 
         * Цикл ввода строк:
         * 1. выведите приглашение для ввода; 
         * 2. пока не введена строка STOP_STRING или не заполнен весь массив; 
         */
        /** 
         * Line entry cycle:
* 1. Print the prompt to enter; 
         * 2. until the STOP_STRING string is entered or the entire array is filled in; 
         */
        int nIndex = 0;// tracking number of line enters

         while (nIndex < N){
            /** ввод строки в массив cBuffer: */
            /** entering a string into the buffer array: ***/

            cout<<"enter string" << nIndex + 1 <<"or * to stop";
            cin.getline(cBuffer[nIndex],M);//read a line into the current row in cBuffer
                                    
            /** если введена строка - признак окончания, то выйти из цикла */
            /** if a line is entered indicating the end, then exit the loop */

            if (strcmp(cBuffer[nIndex], STOP_STRING)==0){//checking if the stop was entered
               break;
            }

            /** Присвойте элементу массива cPointers с индексом nIndex */
            /** Assign a cPointers array element with the nIndex index */

            /** указатель на строку с номером nIndex в массиве cBuffer */
            /*pointer to the string with the nIndex number in the buffer array */

            cPointers[nIndex] = cBuffer[nIndex];
            nIndex++;

        }


        /** Выдать диагностику о том, что прием строк завершен.*/
        /** Issue a diagnostic that the line acceptance is completed.*/

        /**
         * Теперь сортируем строки.
         *
         * Необходимо использовать сортировку строк по методу "всплывающего
         * пузырька" в порядке возрастания. 
         *
         * На каждой итерации - промежуточная печать отсортированных строк.
         */
        /**
         * Now we sort the rows.
         *
         * It is necessary to use row sorting by the "pop-up" method
         * bubbles" in ascending order. 
         *
         * At each iteration - intermediate printing of sorted rows.
         */

         //bubble sort for sorting strings in alphabetical order
         for(int i=0; i<nIndex-1; ++i){//outer loop for passes
            for(int j=0; j<nIndex -i-1; ++j){
               //compare strings using strcmp
               if( strcmp(cPointers[j], cPointers[j+1]) >0){
                  //swap pointers if strings are out of order
                  char* temp = cPointers[j];
                  cPointers[j]=cPointers[j+1];
                  cPointers[j+1]=temp;
               }
            }

            //print sorted rows after each pass
            cout<<"after pass "<<i+1<<endl;
            for(int k= 0; k<nIndex; ++k){
               if(cPointers[k]){
                  cout<<cPointers[k]<<endl;
               }
            }

         }

         //print the final sorted strings
         cout<<"sorted strings: "<<endl;
         for(int i=0; i<nIndex;++i){
            if(cPointers[i]){
               cout<< cPointers[i]<<endl;
            }
         }
         cout<<endl;

    }

/*
    /**
     * Задание 5. Динамические строки.
     *
     * Реализуйте задание №4, используя не встроенные, а динамические массивы
     * (массив?). Так как строки могут быть разной длины, эффективным решением
     * было бы отводить под каждую строку ровно столько байтов, сколько
     * требуется для ее хранения.
     *
     * Реализуйте это задание так, чтобы пользователь мог ввести строку любой
     * длины (которая помещается в память компьютера - читайте: неограниченной
     * длины).
     *
     * При этом необходимые параметры (количество строк) сформируйте с помощью
     * потока ввода.
     */
    /**
* Task 5. Dynamic strings.
     *
* Implement task #4 using dynamic arrays instead of embedded ones
     * (array?). Since the strings can be of different lengths, an effective solution is
     * it would be better to allocate exactly as many bytes for each line as
     * required for its storage.
     *
* Implement this task so that the user can enter any string
     * length (which fits into computer memory - read: unlimited
     * length).
     *
* At the same time, form the necessary parameters (number of rows) using
     * Input stream.
     */

    {
      cout<<"Задание 5 : "<<endl;
        int nStringNumber;

        cout << "Enter number of lines: ";
        cin >> nStringNumber;

         char** lines = new char*[nStringNumber]; //alocatting the array of pointer for the string
        /** Цикл ввода строк: */

        for (int i = 0; i < nStringNumber; ++i) {
            char temp[1000];
            // read line with unknown size with dynamic reallocation
            cout<<"enter line " << i + 1 <<" : ";
            // ok for now, but use C arrays for this semester
            cin.getline(temp, 1000);

            //allocationg exact memory for each string
            int length = strlen(temp+1);
            lines[i]= new char[length];

            strcpy(lines[i], temp);
        }
        /** Line entry loop: */

        /** 
         * Цикл сортировки строк по методу "всплывающего пузырька" в порядке
         * возрастания кода первого символа.
         */
        /** 
         * The row sorting cycle using the "pop-up bubble" method is in order
         * increasing the code of the first character.
         */

        //bubble sort for sorting strings in alphabetical order
         for(int i=0; i<nStringNumber-1; ++i){//outer loop for passes
            for(int j=0; j<nStringNumber -i-1; ++j){
               //comparing strings using strcmp
               if( strcmp(lines[j], lines[j+1]) >0){
                  //swap pointers if strings are out of order
                  char* temp = lines[j];
                  lines[j]=lines[j+1];
                  lines[j+1]=temp;
               }
            }

            //print sorted rows after each pass
            cout<<"after pass "<<i+1<<endl;
            for(int k= 0; k<nStringNumber; ++k){
               
                  cout<<lines[k]<<endl;
               
            }

         }

         //print the final sorted strings
         cout<<"sorted strings: "<<endl;
         for(int i=0; i<nStringNumber;++i){
            
               cout<< lines[i]<<endl;
            
         }

         
         

        /** Освобождение занятой памяти */
        /** Freeing up occupied memory */
         for(int i=0; i< nStringNumber; ++i){
            delete[] lines[i];
         }       
         delete[] lines;
       
        cout<<endl;

    }

    /** 
     * Задание 6. Работа со строками.
     *
     * Реализуйте следующую программу. Пользователь вводит строку (любого
     * размера), после чего пользователю выводится на консоль следующее
     * изображение, где его ввод помещен в "speech bubble":
     *
     *  _____________________________________
     * / Here user input is shown. This line \ 
     * \ must be at most 40 characters long. /
     *  ------------------------------------
     *     \
     *      \
     *        /\_/\  (
     *       ( ^.^ ) _)
     *         \"/  (
     *       ( | | )
     *      (__d b__)
     *
     *  При этом длина строки в "облачке" должна быть не более 40 символов, при
     *  этом слова должны переноситься аккуратно. Это означет, что не должно
     *  быть переносов в центре слова (если только это слово не больше 40
     *  символов).
     *
     *  Дизайн облачка и ASCII-арт допустимо поменять по усмотрению.
     *
     *  Подсказка: обратите внимание на конкатенацию строковых литералов в
     *  языке С, это позволит задавать подобные рисунки так, чтобы они
     *  адекватно выглядели в коде.
     */
    /**
 * Task 6. Working with Strings.
 *
 * Implement the following program. The user inputs a string (of any size), 
 * after which the following image is displayed on the console, where the 
 * user's input is placed inside a "speech bubble":
 *
 *  original input: "Here user input is shown. This line must be at most 40 characters long."
 *  _____________________________________
 * / Here user input is shown. This line \ 
 * \ must be at most 40 characters long. /
 *  ------------------------------------
 *     \
 *      \
 *        /\_/\  (
 *       ( ^.^ ) _)
 *         \"/  (
 *       ( | | )
 *      (__d b__)
 *
 * The length of the string inside the "bubble" should not exceed 40 characters, 
 * and words should be wrapped carefully. This means that there should not be 
 * line breaks in the middle of a word (unless the word itself is longer than 
 * 40 characters).
 *
 * The design of the bubble and ASCII art can be changed at your discretion.
 *
 * Hint: pay attention to the concatenation of string literals in the C 
 * language, as this will help in creating such drawings to look adequately 
 * formatted in the code.
 */
   { 
      cout << "Задание 6 : " << endl;

      const int maxLineLength = 40;//max length for each line inside the speech bubble

      // Dynamically allocate memory for user input
      const int maxInputLength = 10000;//maximum length of input
      char* consoleInput = new char[maxInputLength];// pointer for dynamic user input
      char** wrappedLines = nullptr;// pointer to dynamically allocated array of lines
      int lineCount = 0;//variable to track the number of lines

      cout << "enter words: ";
      cin.getline(consoleInput, maxInputLength);

      int length = strlen(consoleInput);
      int startIndex = 0;

      //without breaking words
      int maxLines = (length / maxLineLength) + 1;
      wrappedLines = new char*[maxLines];//dynamically allocate memory for each line

      //max line
      char* currentLine = new char[maxLineLength + 1]; // Temporary buffer for each line
      int currentLineLength = 0; // Keep track of the current line length

      while (startIndex < length) {
         int wordLength = 0;

         //finding the length of next word
         while (startIndex + wordLength < length && consoleInput[startIndex + wordLength] != ' ') {
               wordLength++;
         }

         //if console word exceeds the line length, to next line
               if (currentLineLength + wordLength + (currentLineLength > 0 ? 1 : 0) > maxLineLength) {
               // save current line
               currentLine[currentLineLength] = '\0';
               wrappedLines[lineCount] = new char[currentLineLength + 1];
               strcpy(wrappedLines[lineCount], currentLine);
               lineCount++;

               //starting a new line
               currentLineLength = 0;
         }

         //adding the word to the current line
         if (currentLineLength > 0) {
               currentLine[currentLineLength++] = ' ';//space between words
         }
         strncpy(currentLine + currentLineLength, consoleInput + startIndex, wordLength);
         currentLineLength += wordLength;

         //move to the next word
         startIndex += wordLength;

         //skip over the space if it exists
         if (startIndex < length && consoleInput[startIndex] == ' ') {
               startIndex++;
         }
      }

      //add the last line
      if (currentLineLength > 0) {
         currentLine[currentLineLength] = '\0';
         wrappedLines[lineCount] = new char[currentLineLength + 1];
         strcpy(wrappedLines[lineCount], currentLine);
         lineCount++;
      }

      //find the longest line length (for bubble width calculation)
      int bubbleWidth = 0;
      for (int i = 0; i < lineCount; ++i) {
         int len = strlen(wrappedLines[i]);
         if (len > bubbleWidth) {
               bubbleWidth = len;
         }
      }

      cout << " ";
      for (int i = 0; i < bubbleWidth + 2; ++i) {//print the top border of the bubble

         cout << "_";
      }
      cout << endl;

         for (int i = 0; i < lineCount; ++i) {//print each line inside the bubble

         cout << "/ "; //left border
         cout << wrappedLines[i];

         int padding = bubbleWidth - strlen(wrappedLines[i]);//ensure that bubbleWidth characters before the closing border
         for (int j = 0; j < padding; ++j) {
               cout << " "; // padding with spaces
         }
         cout << " \\" << endl; //right border
      }

      //print the bottom border of the bubble
      cout <<" ";
      for (int i = 0; i< bubbleWidth + 2; ++i) {
         cout << "-";
      }
      cout << endl;

      //print the ASCII art for the bubble tail and cat
      cout << "     \\ " << endl;
      cout << "      \\ " << endl;
      cout << "        /\\_/\\  (" << endl;
      cout << "       ( ^.^ ) _)" << endl;
      cout << "         \\\"/  (" << endl;
      cout << "       ( | | )" << endl;
      cout << "      (__d b__)" << endl;

      delete[] consoleInput;//free dynamically allocated memory
      for (int i = 0; i < lineCount; ++i) {
         delete[] wrappedLines[i];
      }
      delete[] wrappedLines; //free the wrappedLines array
      delete[] currentLine; //free the temporary buffer for lines


   }

  

    /** 
     * Задание 7. Сложные указатели.
     *
     * Объявление и использование указателей на многомерные массивы.
     * Проинициализируйте трехмерный массив double dArray[4][3][3] так, как
     * показано на рисунке и напишите фрагмент кода, который меняет местами
     * значения элементов четных и нечетных слоев:
     *
     *  было:                |--------|     
     *                     / |4  4  4 |     
     *                   |--------| 4 | 
     *                 / |3  3  3 | 4 | 
     *               |---------|3 |   |
     *             / | 2  2  2 |3 | /
     *            |---------|2 |__|
     *            | 1  1  1 |2 | /
     *            | 1  1  1 |__| 
     *            | 1  1  1 | /
     *            |_________|
     *
     *  стало:               |--------|     
     *                     / |3  3  3 |     
     *                   |--------| 3 | 
     *                 / |4  4  4 | 3 | 
     *               |---------|4 |   |
     *             / | 1  1  1 |4 | /
     *            |---------|1 |__|
     *            | 2  2  2 |1 | /
     *            | 2  2  2 |__| 
     *            | 2  2  2 | /
     *            |_________|
     */
    /** 
     * Task 7. Complex pointers.
     *
* Declaring and using pointers to multidimensional arrays.
     * Initialize the three-dimensional array double dArray[4][3][3] as follows
     * shown in the picture and write a piece of code that swaps
     * values of elements of even and odd layers:
     *
* it was:                    |--------|     
     *                     / |4  4  4 |     
     *                   |--------| 4 | 
     *                 / |3  3  3 | 4 | 
     *               |---------|3 |   |
     *             / | 2  2  2 |3 | /
     *            |---------|2 |__|
     *            | 1  1  1 |2 | /
     *            | 1  1  1 |__| 
     *            | 1  1  1 | /
     *            |_________|
     *
* it became:                 |--------|     
     *                     / |3  3  3 |     
     *                   |--------| 3 | 
     *                 / |4  4  4 | 3 | 
     *               |---------|4 |   |
     *             / | 1  1  1 |4 | /
     *            |---------|1 |__|
     *            | 2  2  2 |1 | /
     *            | 2  2  2 |__| 
     *            | 2  2  2 | /
     *            |_________|
     */

    {
      cout<<"Задание 7 : "<<endl;
            /** 
             * Замечание: НЕ НУЖНО МОДИФИЦИРОВАТЬ ВЫРАЖЕНИЯ СПРАВА ОТ ЗНАКА
             * РАВЕНСТВА!!! 
             */
            /** 
             * Note: YOU DO NOT NEED TO MODIFY THE EXPRESSIONS TO THE RIGHT OF THE SIGN
             * EQUALITY!!! 
             */
        
        {
    
    double dArray[4][3][3] = {//initializing the 3d arr
        {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}}, {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}}, {{3, 3, 3}, {3, 3, 3}, {3, 3, 3}}, {{4, 4, 4}, {4, 4, 4}, {4, 4, 4}}  };

   
    cout << "before swapping:" << endl;//before swaping output
    for (int i = 0; i < 4; ++i) {
        cout << "Layer " << i << ":" << endl;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout << dArray[i][j][k] << " ";//output
            }
            cout << endl;
        }
        cout << endl;
    }

     // ... =  dArray[i];
    // ... =  dArray[i+1];
    /** переставляем местами элементы i-того и i+1-ого слоев */
   /** rearranging the elements of the i-th and i+1st layers */

    //rearanging even / or layer
    for (int i = 0; i < 3; i += 2) { // i = 0, 2 (even layers)
        double (*layerEven)[3] = dArray[i];     // pointing to the i-th layer
        double (*layerOdd)[3] = dArray[i + 1]; // pointing to the i+1-th layer

        // swaping elements of the i-th and (i+1)-th layers
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                double temp = layerEven[j][k];
                layerEven[j][k] = layerOdd[j][k];
                layerOdd[j][k] = temp;
            }
        }
    }

    // after swapping
    cout << "after swapping:" << endl;
    for (int i = 0; i < 4; ++i) {
        cout << "Layer " << i << ":" << endl;
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout << dArray[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    
}
    }
    
    /**
     * Задание 7.
     */

    /**
     * Задание 7.1.
     *
     * Объявите двухмерный встроенный массив элементов типа char.
     *
     * Сформируйте значения элементов массива с помощью генератора случайных
     * чисел таким образом, чтобы в массиве были только символы '*' и '_'.
     *
     * В каждой строке "сдвиньте звездочки" в начало строки, например:
     * было - '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
     * стало: '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
     * и распечатайте массив по строкам.
     *
     * При этом оцените количество операций, которое требуется для обработки
     * одной строки относительно длины этой строки.
     *
     * Постарайтесь решить эту задачу так, чтобы требовалось не более k*N 
     * операций, где N - длина строки, k - некое фиксированное число.
     */
    /**
 * Task 7.
 */

/**
 * Task 7.1.
 *
 * Declare a two-dimensional built-in array of elements of type `char`.
 *
 * Fill the array elements using a random number generator such that the array
 * contains only the characters '*' and '_'.
 *
 * In each row, "shift the asterisks" to the beginning of the row, for example:
 * before: '*' '_' '_' '*' '*' '_' '*' '_' '*' '_'
 * after:  '*' '*' '*' '*' '*' '_' '_' '_' '_' '_'
 * and print the array row by row.
 *
 * Estimate the number of operations required to process one row relative to
 * the length of the row.
 *
 * Try to solve this problem so that it requires no more than `k * N` operations,
 * where `N` is the length of the row, and `k` is some fixed number.
 */

    

   {  
         cout<<"Задание 7.1 : "<<endl;
         {
            const int rows = 4;  // rows
            const int cols = 9; // columns

            
            char arr[rows][cols];//2d array

            // random number generator
            srand(time(0));

            // initializing the array with random '*' and '_'
            cout << "before shifting :" << endl;
            for (int i = 0; i < rows; ++i) {
               for (int j = 0; j < cols; ++j) {
                     arr[i][j] = (rand() % 2 == 0) ? '*' : '_'; // randomly assigning by even or odd '*' or '_'
                     cout << "'" << arr[i][j] << "' "; // print the initial array
               }
               cout << endl;
         }

         // shifting * beginning of each row
         for (int i = 0; i < rows; ++i) {
            int index = 0; // index to place the next '*'

            
            for (int j = 0; j < cols; ++j) {//moving all * to the begining
                  if (arr[i][j] == '*') {
                     arr[i][index++] = '*';
                  }
            }

            
            while (index < cols) {//remaining with '_'
                  arr[i][index++] = '_';
            }
         }

         
         cout << "\nafter shifting asterisks:" << endl;
         for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                  cout << "'" << arr[i][j] << "' ";
            }
            cout << endl;
         }

      
      }

   }

    /**
     * Задание 7.2.
     *
     * Модифицируйте предыдущее задание следующим способом: После заполнения
     * массива с помощью генератора случайных чисел "сдвиньте" звездочки по
     * столбцам вниз и распечатайте результат.
     */
    /**
 * Task 7.2.
 *
 * Modify the previous task in the following way: After filling the array
 * using the random number generator, "shift" the asterisks down in each column
 * and print the result.
 */
 {
   cout<<"Задание 7.2 : "<<endl;
   const int rows = 4;  // rows
   const int cols = 9; // columns

   char arr[rows][cols];//2D array


   // random number generator
   srand(time(0));

    // initializing the array with random '*' and '_'
   cout << "before shifting symbols:" << endl;
   for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
         arr[i][j] = (rand() % 2 == 0) ? '*' : '_'; // randomly assigning by even or odd '*' or '_'
         cout << "'" << arr[i][j] << "' "; // printing the initial array
                 }
      cout << endl;
    }

    
    for (int j = 0; j < cols; ++j) {//shifting symbol by colum
        int index = rows - 1; //'*' from the bottom row

        
        for (int i = rows - 1; i >= 0; --i) {//mvoing all * to the botton of the colum
            if (arr[i][j] == '*') {
                arr[index--][j] = '*';
            }
        }

        
        while (index >= 0) {//remaining celles column with '_'
            arr[index--][j] = '_';
        }
    }


    cout << "\nAfter shifting asterisks:" << endl;//after shifting
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "'" << arr[i][j] << "' ";
        }
        cout << endl;
    }

}



    return 0;
    

}
