/**
 * Практическое занятие №2. Побитовые операторы. Директивы препроцессора.
 * Указатели.
 * Practical Session No. 2: Bitwise Operators. Preprocessor Directives.
 * Pointers.
 */

#include <iostream>

#include <cmath>

using namespace std;


int main() {
    /**
     * Задание 1. Побитовая арифметика (and, or, xor, not), сдвиги.
     * Task 1. Bitwise Arithmetic (and, or, xor, not), Shifts.
     */

    /**
     * Задание 1.1.
     *
     * Задайте значение переменной `y`, например, с помощью потока ввода.
     *
     * 1. С помощью побитовых операторов и операторов сдвига выведите значение
     *    переменной `y` на консоль в двоичном виде.
     * 2. Сделайте то же, но пропустив незначащие нули.
     *
     * Например, если `y == 9`, то должно получиться
     * 1. `0 0 0 0 ... 0 0 1 0 0 1` (количество двоичных цифр зависит от
     *    платформы).
     * 2. `1 0 0 1`.
     *
     * Что выведет ваша программа, если ввести отрицательное число? Объясните
     * этот результат.
     */
    /**
    * Task 1.1.
    *
    * Assign a value to the variable `y`, for example, using input from the console.
    *
    * 1. Using bitwise operators and shift operators, output the value of the
    *    variable `y` on the console in binary form.
    * 2. Do the same, but this time omit leading zeros.
    *
    * For example, if `y == 9`, the output should be:
    * 1. `0 0 0 0 ... 0 0 1 0 0 1` (the number of binary digits depends on
    *    the platform).
    * 2. `1 0 0 1`.
    *
    * What will your program output if you enter a negative number? Explain
    * this result.
    */

    {
        cout << "task 1.1 : " << endl;

        cout << "enter a value for y (cvt to Binary): ";
        int y;
        cin >>y;
        int OsBit = sizeof(int) * 8;

        cout << "Binary : ";
        for (int i= OsBit -1; i >=0; i--){ // TODO: print all bits, and calculate number of bits based on size of int at compile time
            cout << ((y>>i) & 1);//bitwise and
            if(i%4==0 && i!=0){//space after 4bits
                cout <<" ";
            }
        }
        cout<<""<<endl;

        cout << "omit leading 0's : ";
        int temp=OsBit;
        for (int i=OsBit-1; i>= 0; i--){//finding the position of 1
            if((y>>i)&1){
                temp=i;
                break;
            }
        }

        if (temp== 8){
            cout << "0"<<endl;
        }
        else{
            for(int i =temp; i>=0; i--){//printing without omit zero's
                cout<<((y>>i) & 1);
            }
        }
        /*when i enter a negative value like -5, i get 11111011. the program
        showing -5's representation using two's complement.for negative number
        output always start with 1 because of signed bit.*/

    }

    /**
     * Задание 1.2.
     *
     * Дана целая переменная `y`, задайте ее значение, например, с помощью
     * потока ввода.
     *
     * В рамках одного цикла "сдвиньте" все единицы в переменной `y` вправо,
     * обновив тем самым значение этой переменной.
     *
     * Например:
     * было:  0100 1111 0000 0000 0110 1111 0000 0010
     * стало: 0000 0000 0000 0000 0000 1111 1111 1111
     *
     * Выведите переменную на экран в двоичном виде до преобразования и после,
     * используя код из задания 1.1.
     */
    /**
     *Task 1.2.
     *
     * Given an integer variable `y`, set its value, for example, using
     * input stream.
     *
     * Within one loop, "shift" all the ones in the variable `y` to the right,
     * thereby updating the value of this variable.
     *
     * For example:
     * was: 0100 1111 0000 0000 0110 1111 0000 0010
     * became: 0000 0000 0000 0000 0000 1111 1111 1111
     *
     * Print the variable in binary form before and after conversion,
     * using the code from task 1.1.
     */

    {
        cout << "\ntask 1.2" << endl;

        cout <<"enter a value for y (cvt to Binary): ";
        int y;
        cin >> y;//if 4

        int OsBit = sizeof(int) * 8;
        cout << "Binary : ";
        for (int i= OsBit -1; i >=0; i--){
            cout << ((y>>i) & 1);//bitwise and
            if(i==4 && i!=0){//space after 4bits
                cout <<" ";
            }
        }

        int temp = 0;//how many one's we have = 3
        for(int i=0; i<8; i++){
            if((y>>i)&1){//finding 1 using bitwise and
                temp++;
            }
        }

        int tempY=0;//for printing all 1's to the right=0000 0111
        for(int i=0; i<temp; i++){
            tempY = (tempY<<1)|1;//Lsd=1
        }
        cout<<""<<endl;

        cout<<"shiftig all 1's to the right :";
        for(int i=OsBit-1; i>=0; i--){
            cout<<((tempY>>i)&1);
            if(i%4==0 && i!=0){
                cout<<" ";//for space after 4 bits
            }
        }

    }

    /**
     * Задание 1.3.
     *
     * Дана целая переменная `y`, задайте ее значение.
     *
     * Напишите код, который с помощью побитовых операций:
     *
     * 1. вычислит `y * 2^n`, где целое `n` (0 <= n < 16) задается отдельно;
     * 2. проверит, делится ли `y` на 2, проверит, делится ли `y` на 4;
     * 3. вычислит целую часть логорифма `y` по основанию 2.
     */
    /**
     *Task 1.3.
     *
     * Given an integer variable `y`, set its value.
     *
     * Write code that, using bitwise operations:
     *
     * 1. will calculate `y * 2^n`, where the integer `n` (0 <= n < 16) is specified separately;
     * 2. will check if `y` is divisible by 2, will check if `y` is divisible by 4;
     * 3. will calculate the integer part of the logarithm `y` in base 2.
     */

    {
        cout<<"\ntask 1.3: "<<endl;
        int y,n;
        cout<<"enter a int value for y:";
        cin>>y;
        cout<<"enter a int value for n (0 <=n <16):";
        cin>>n;

        cout<<"1. ";
        int rslt= y<<n;
        cout<<"y*2^"<<n<<"="<<rslt<<endl;//left shifting int by n positions is equivalent to multiplying the int by 2^n

        cout<<"2. ";
        if((y&1)==0){//1 because lsb of 2 must be 0
            cout<<"y is divisible by 2"<<endl;
        }
        else{
            cout<<"y is not devisible by 2"<<endl;
        }
        if((y&3)==0){//3 because lsb of 4 must be 00
            cout<<"y is divisible by 4"<<endl;
        }
        else{
            cout<<"y is not devisible by 4"<<endl;
        }

        cout<<"3. ";
        int l2y= -1;//when while loops begins l2y incrimented -1 to 0
        int tmpY=y;

        while(tmpY>0){
            tmpY >>=1;// rifht shifting tmpY untill 0=y
            l2y++;
        }
        cout << "Int part of log2(y)="<<l2y<<endl;

    }

    /**
     * Задание 1.4.
     *
     * Какие операции следует применить к заданному ниже операнду sNum для
     * того, чтобы переменная sRes приняла требуемое значение? Каждую побитовую
     * операцию можно использовать только 1 раз.
     *
     * Замечание: значения подобраны таким образом, что в каждом случае
     * достаточно использовать один оператор (и при необходимости маску).
     */
    /**
     *Task 1.4.
     *
     * What operations should be applied to the sNum operand given below to
     * so that the sRes variable takes the required value? Every bit
     * operation can be used only 1 time.
     *
     *Note: the values ​​are selected in such a way that in each case
     * it is enough to use one operator (and, if necessary, a mask).
     */

    {

        short sNum = 0x8008;//binary=1000 0000 0000 1000
        short sRes;//not more than one time

        /** sRes == 0x7ff7 //binary=0111 1111 1111 0111*/
        sRes=~sNum;//not operation to get 0x7ff7

        /** sRes == 0x8ff8 //binary=1000 1111 1111 1000*/
        sRes= sNum| 0x0ff0;//or operation,0000 1111 1111 0000

        /** sRes == 0x0008 //binary=0000 0000 0000 1000*/
        sRes=sNum &0x0008;//and operation,0000 0000 0000 1000
        

        /** sRes == 0x7f08 //binary=0111 1111 0000 1000*/
        sRes =sNum^ 0xff00;//xor operation,1111 1111 0000 0000
        

        /** sRes == 0xf001 //binary=1111 0000 0000 0001*/
        sRes =sNum>>3;//right shift by 3
        
        /** sRes == 0x0010 //binary=0000 0000 0001 0000*/
        sRes= sNum<<1;//left shift by 1
        
    }


    /**
     * Задание 2. Директивы препроцессора.
     */
    /**
 * Task 2. Preprocessor directives.
 */

    /**
     * Задание 2.1. Использование "математических" макросов стандартной
     * библиотеки.
     *
     * В заголовочном файле <cmath> (который в свою очередь включает старый
     * файл math.h) определены часто используемые математические константы,
     * например M_PI. Воспользуйтесь этой константой для вычисления длины
     * окружности.
     */
    /**
     *Task 2.1. Using standard "mathematical" macros
     * libraries.
     *
     * In the <cmath> header file (which in turn includes the old
     * file math.h) frequently used mathematical constants are defined,
     * for example M_PI. Use this constant to calculate the length
     * circles.
     */

    {
        cout << "\ntask 2.1:"<<endl;
        float radius;
        cout<<"enter radius of the circle:";
        cin>>radius;

        float circumference= 2* M_PI *radius;//using library cmath
        cout<<"circumference of the circle is: "<< circumference<< endl;
    }

    /**
     * Задание 2.2. Макросы с параметрами.
     */
    /**
     *Task 2.2. Macros with parameters.
     */

    /**
     * Задание 2.2.1.
     *
     * Напишите свою макроподстановку LENGHT которая вычисляет длину
     * окружности.
     */

    /**
     *Task 2.2.1.
     *
     * Write your own LENGHT macro substitution that calculates the length
     * circles.
     */
    

    {
        cout<<"\ntask 2.2.1: "<<endl;
        #define LENGHT(r)(2*M_PI*(r))
        /** Протестируйте написанный макрос для следующих ситуаций */
        /** Test the written macro for the following situations */

        float l1 = LENGHT(1 + 2); // должно быть 18.8495...(working)
        cout<<"LENGHT(1+2)="<<l1<<endl;

        float l2 = 1 / LENGHT(2); // должно быть 0.07957...(working)
        cout<<"LENGTH(2)="<<l2<<endl;

    }

    /**
     * Задание 2.2.2.
     *
     * Определите макрос MAX(A, B) для вычисления б'ольшего значения из двух.
     */
    /**
     *Task 2.2.2.
     *
     * Define a macro MAX(A, B) to calculate the larger of the two.
     */

    {
        /**
         * Используйте макрос следующим образом. Следите за изменением значений
         * переменных k, i, j. Объясните результат.
         *
         * Постарайтесь убрать побочные эффекты.
         *
         * Отметьте случаи, когда избежать побочных эффектов невозможно.
         */
        /**
         * Use the macro as follows. Watch the values ​​change
         * variables k, i, j. Explain the result.
         *
         * Try to eliminate side effects.
         *
         * Note cases when side effects cannot be avoided.
         */
        
        #define MAX(A,B) ((A)>(B)?(A):(B))//condition?(ternary) true:false
        
        int i = 10, j = 12, k;
        k = MAX(i, j);//12
        k = MAX(j, i) * 2;//24
        k = MAX(j, i+3);//13

        k = MAX(i--, j++);//13, i=9,j=14
        /*here the side effects occur. i-- and j++ causes i to decrement once,
        and j++ causes j to increment twice. k =13, i=9 but j=14. 
        }*/

    }

    /**
     * Задание 2.2.3.
     *
     * Определите макрос EXCHANGE(X, Y)  для перестановки двух объектов типа
     * int в памяти местами.
     *
     * Проверьте для приведенного фрагмента.
     *
     * Подумайте, что будет делать макроподстановка, если переставляемые
     * значения разного типа???
     */
    /**
     *Task 2.2.3.
     *
     * Define a macro EXCHANGE(X, Y) to swap two objects of type
     * int in memory in places.
     *
     *Check for the snippet provided.
     *
     * Consider what macro substitution will do if the permutations
     * values ​​of different types???
     */

    {
        cout<<"\ntask 2.2.3: "<<endl;
        #define EXCHANGE(x, y){int tmp=x;x=y;y =tmp;}

        int x1=1,y1= -1;
        EXCHANGE(x1,y1); // x1 = -1, y1 = 1
        cout<<"x1="<<x1<<",y1 ="<<y1<<endl;

        int x2=100,y2 =-100;
        EXCHANGE(x2, y2); // x2 = -100, y2 = 100
        cout<<"x2= " <<x2<<",y2= " <<y2 <<endl;
        /*if we try to use EXCHANGE macro with values of different types
        like int, double ,float it can cause unexpected behavior or it can
        loss of data because the int declaration of temp doesn't math if we
        declire another data types*/
    }

    /**
     * Задание 2.3. Директивы условной трансляции.
     *
     * Выполняя следующий фрагмент, посмотрите, какое значение принимает
     * переменная iNN.
     *
     * Что нужно сделать для того, чтобы результат был равен 0? 1? 2?
     */
    /**
     *Task 2.3. Conditional translation directives.
     *
     * When executing the following snippet, see what value it takes
     * variable iNN.
     *
     * What needs to be done to ensure that the result is 0? 1? 2?
     */

    {
        cout<<"\ntask 2.3: "<<endl;
        int iNN;
#if defined NNN && defined MMM
        iNN = 0;
        /*if we wirite #define NNN and #define MMM
        then iNN =0;*/
#elif defined MMM
        iNN = 1;
        /*if we wirite  #define MMM
        then iNN =1;*/
#elif defined NNN
        iNN = 2;/*if we wirite #define NNN
        then iNN =2;*/

#else
        iNN = -1;/*if we dont write anything  #define MMM
        nor #define NNN then iNN =-1;*/
#endif

    cout <<"iNN: "<<iNN<<endl;
    }

    /**
     * Задание 2.4. Задание директив при сборке.
     *
     * При сборке программы компилятором можно установить необходимые
     * макроподстановки с помощью ключа `-D`. Например, чтобы при сборке
     * была определена директива `A` без значения и директива `B` со значением
     * `1`, надо добавить следующие ключи к команде сборки: `-D A -D B=1`.
     * Таким образом команда сборки будет выглядеть примерно так:
     *
     * `gcc -g -D A -D B=1 lab2.cpp`
     *
     * Уберите из кода определения макросов NNN и MMM из прошлого задания и
     * приведите команды компиляции, которые заставят переменную iNN принять
     * нужное значение.
     *
     * Проверьте их работоспособность.
     */
    /**
* Task 2.4. Setting directives during assembly.
     *
* When building a program with the compiler, you can install the necessary
     * macro substitutions using the `-D` key. For example, so that when assembling
     * directive `A` without value and directive `B` with value has been defined
     * `1`, add the following keys to the build command: `-D A -D B=1'.
     * So the build command will look something like this:
     *
     * `gcc -g -D A -D B=1 lab2.cpp`
     * g++ -g -D MMM lab2.cpp -o test1.4//(for this program in this pc)
     *
* Remove the definitions of the NNN and MMM macros from the previous task from the code and
     * provide compilation commands that will force the iNN variable to accept
     * the desired value.
     *
* Check their performance.
     */

    /**
     * Задание 2.5. Сборки "DEBUG" и "RELEASE". Предопределенные макросы
     * компилятора.
     *
     * При отладке удобно выводить дополнительную информацию, которая может
     * мешать в итоговой (релизной) версии программы.
     *
     * Существует стандартный макрос, который принято устанавливать при
     * релизной сборке - `NDEBUG`.
     *
     * С помощью макроса NDEBUG и предопределенных макросов выведите на консоль
     * для отладочной версии информацию о том, что это отладочная сборка, о
     * дате сборки, о имени файла, имени функции и строки. Для релизной сборки
     * такая информация не должна выводиться.
     *
     * Для защиты работы соберите две версии программы: отладочную и итоговую.
     * Чтобы собрать итоговую версию в другом исполняемом файле, используйте
     * ключ компилятора `-o`, примерно так:
     *
     * `gcc <ваши опции> -o release.out lab2.cpp`
     */
    /**
* 2.5 is set. Collections "DEBUG" and"RELEASE". Predefined macros
     * the compiler.
     *
* When debugging, it is convenient to output additional information that can
     * interfere with the final (release) version of the program.
     *
* There is a standard macro that needs to be installed at
* * release build ` ' DEBUG`.
     *
* * Using the DEBUG macro and predefined macros, output to the console
* for the debug version information that this is a debug build, about
     * Build date, file name, function name and string. For the release build
     * Such information should not be displayed.
     *
* To protect your work, assemble two versions of the program: debugging and final.
     * To build the final version in another executable file, use
     * the compiler key is ` - o`, for example:
*
* 'gcc <your options> - o release.out lab2.cpp `
g++ -DDEBUG -g -o debug_build.out lab2.cpp




     */
     {
        cout<<"\ntask 2.5: "<<endl;
    // output debug info(predefined macros)
    #if defined(DEBUG)
        cout<<"debug build:-\n";
        cout<< "build date:-" << __DATE__ << "\n";
        cout <<"build time:-" << __TIME__ << "\n";
        cout <<"file name:-"<< __FILE__ << "\n";
        cout<<"function name:"<< __func__ << "\n";
        
    #else
        cout << "release build...(worked)\n";
    #endif

    
    }


    /**
     * Задание 3.Заголовочные файлы. Директива #include.
     */

    /**
     * Задания 3.1.
     *
     * Создайте и подключите к проекту два заголовочных файла 1.h и 2.h.
     *
     * В каждом заголовочном файле объявите перечисление с одинаковыми именами
     * констант, но сопоставьте именованным константам разные значения,
     * например:
     *
     * - 1.h - enum MyEnum{My1, My2, My3};//0,1,2
     * - 2.h - enum MyEnum{My1=5, My2, My3};
     *
     * С помощью директив условной трансляции в DEBUG-версии пользуйтесь
     * значениями констант из 1.h, а в RELEASE-версии значениями констант из
     * 2.h.
     *
     * Замечание: заголовочные файлы принято подключать в верхней части файла,
     * до любых функций (хотя правила компиляции не запрещают подключить их
     * тут).
     */
    /**
* Task 3. Header files. The #include directive.
     */

    /**
     * Tasks 3.1.
*
* Create and connect two header files 1.h and 2.h to the project.
     *
     * Declare an enumeration with the same names in each header file
     * constants, but assign different values to named constants,
     * for example:
     *
     * - 1.h - enum MyEnum{My1, My2, My3};//0,1,2
     * - 2.h - enum MyEnum{My1=5, My2, My3};//5,6,7
     *
* Using conditional translation directives in the DEBUG version, use
     * the values of constants from 1.h, and in the RELEASE version the values of constants from
* 2.h.
*
* Note: header files are usually attached at the top of the file,
     * before any functions (although the compilation rules do not prohibit connecting them
* here).
g++ -DDEBUG -o debug_version.out lab2.cpp
g++ -o release_version.out lab2.cpp

     */
    cout<<"\ntask 3.1: "<<endl;
#if defined(DEBUG)
    #include "1.h"//1.h debug version 
#else
    #include "2.h"//2.h release version
#endif

    MyEnum value=My2;
    cout<< "value of My2 : "<< value <<endl;


    /**
     * Задание 4. Указатели.
     */

    /**
     * Задание 4.1.
     *
     * Объявите объекты разных типов и проинициализируйте их.
     *
     * Объявите указатели соответствующих типов и проинициализируйте их
     * адресами заданных объектов.
     *
     * Выполняя задание, с помощью отладчика посмотрите, какие значения будут
     * присвоены переменным-указателям и на что эти указатели "указывают".
     */
    /**
* Task 4. Pointers.
     */

    /**
     * Task 4.1.
     *
     * Declare objects of different types and initialize them.
     *
* Declare pointers of the appropriate types and initialize them
     * addresses of the specified objects.
     *
* When completing a task, use the debugger to see what values will be
     * assigned to pointer variables and what these pointers "point to".
     */

    {
        cout<<"\ntask 4.1: "<<endl;
        //initializing different types of data
        int i=7;
        double d=10.9;
        char c='A';
        float f=15.5f;
        string s="Bangladesh";

        //pointer holding address of data; referencing
        int* iPtr = &i;//int pointer, holding the address of i
        cout<<"iPtr "<<iPtr<<endl;//adds of i: 0x7ffee2fbac1c
        double* dPtr =&d;//double pointer, holding the address of d 
        char* cPtr = &c;//double pointer, holding the address of c
        float* fPtr = &f;//float pointer, holding the address of f
        string* sPtr= &s;//string pointer, holding the address of s
    }

    /**
     * Задание 4.2.
     *
     * Объявите указатель на тип char и проинициализируйте его адресом
     * строкового литерала. Присвойте переменной типа char значение любого
     * элемента строки.
     *
     * Проверьте - возможно ли присвоить какое-либо значение по адресу,
     * задаваемому указателем?
     */
    /**
     *Task 4.2.
     *
     * Declare a pointer to type char and initialize it with the address
     * string literal. Assign a variable of type char to any value
     * line element.
     *
     * Check if it is possible to assign any value to the address
     * specified by the pointer?
     */

    {
        cout<<"\ntask 4.2: "<<endl;
        const char* cPtr = "I miss my family";
        char anotherCharPter = cPtr[4];
        cout<<"anotherCharPter: "<<&cPtr[4]<<endl;
        //cPtr[0]='i'; //error
        /*no, it is not possible to modify the charecters of a string literal through  a pointer because
        of using canst char* to point to a string and explicitly tells the compiler that to pointed data 
        should not be changed*/

    }

    /**
     * Задание 5. Арифметика указателей. Операция разыменования указателя.
     *
     * Выполните следующий код по строчкам в отладчике, проследите за
     * изменением значений указателей и значений объектов, на которые они
     * указывают.
     *
     * Интерпретируте наблюдаемые результаты.
     */
    /**
     *Task 5. Pointer arithmetic. Pointer dereference operation.
     *
     * Execute the following code line by line in the debugger, watch for
     * changing the values ​​of pointers and the values ​​of objects to which they
     * indicate.
     *
     * Interpret observed results.
     */
    {
        cout<<"\ntask 5: "<<endl;
        int nAr[3] ={1,3};//array with 3 ints index {1,3,0}
        int* pn = &nAr[0];//pointing first index element;Referencing
        (*pn)++;    //increment nAr[0] of pn 1 to 2;dereferencing
        pn++;   //move pointing to nAr[1] is 3;ptr aritmetic

        char cAr[] = {'A', 'B', 'C', 'D'};// array of char
        char *pc = &cAr[0];//pointing cAr[0]=A;referencing
        (*pc) = (*pc) + 5;  //A+5=F;ptr aritmetic
        pc = pc + 3;    // move pc to cAr[3]=D 

        double dAr[3]={1.0,2.0};//array with e doubles indexs{1.0,2.0,0.0}
        double *pd1 = &dAr[0];//pointing address of dAr[0]
        double *pd2 = pd1;//pd2 aslo point to pd1
        (*pd2) += 2;//*pd2= *pd2 +2 = 1.0 + 2 =3.0
        pd2 += 2;//pd2= pd2 + 2 ; index move to index 2= dAr[2]
        /** Объясните результат выполнения операции вычитания двух указателей */
        /** Explain the result of subtracting two pointers */
        pd1 = &dAr[0];//pointing index0=dAr[0]
        pd2 = &dAr[1];//pointing index1=dAr[1]
        int nNumber = pd2 - pd1;//subtracting pd1 from pd2
        /*pd1 points to dAr[0] and pd2 points to dAr[1]
        so pd2 - pd1 is 1.*/


        /**
         * Сравните указатели pd2 и pd1 и с помощью cout выведите результаты
         * сравнения.
         */
        /**
         * Compare pointers pd2 and pd1 and use cout to print the results
         * comparisons.
         */
        if (pd2>pd1){
            cout<< "pd2 > pd1"<< endl;
        }
        else if (pd2<pd1){
            cout<< "pd2 < pd1"<< endl;
        }
        else{
            cout<< "pd2= pd1"<<endl;
        }
    }
/*
    /**
     * Задание 6. Явное преобразование указателя.
     *
     * Иногда возникает необходимость одни и те же данные интерпретировать
     * по-разному, например, целое можно представить как совокупность четырех
     * байтов и работать с каждым байтом по отдельности. Для этого нужно иметь
     * возможность "указывать" как на целое, так и на байт.
     *
     * Следовательно, возникает необходимость явного преобразования указателя.
     *
     * Подсказка: для правильной интерпретации этого задания воспользуйтесь
     * возможностями отладчика представлять данные в интересующем Вас виде (в
     * данном случае - в шестнадцатеричном) - для этого можно использовать
     * команду print (p) с указанием шестнадцетиричного формата: `p/x`.
     */
    /**
     * Task 6. Explicit pointer conversion.
     *
     * Sometimes there is a need to interpret the same data
     * in different ways, for example, the whole can be represented as a combination of four
     * bytes and work with each byte separately. To do this you need to have
     * the ability to "point" to both an integer and a byte.
     * * Therefore, there is a need for explicit pointer conversion.
     *
     * Hint: to correctly interpret this task, use
     * debugger capabilities to present data in the form you are interested in (in
     * in this case - in hexadecimal) - for this you can use
     * print (p) command specifying hexadecimal format: `p/x`.
     */

    {
        unsigned int nObject = 0x55667788;//nObject unsigned  izitialized hex val
        unsigned int* pnObject = &nObject;//pnObject is a pointer to nObject holding adds 
        unsigned char* pucObject;//pointer to unsigned char , which is pointing to individual bytes
        char cc; //cc store values from pucObject

        /**
         * Раскомментировав следующую строчку кода, обратите внимание на
         * сообщение компилятора - он не считает преобразование "легальным"
         * (безопасным)
         */
        /**
         * After uncommenting the following line of code, pay attention to
         * compiler message - it does not consider the conversion "legal"
         * (safe)
         */

        //pucObject = static_cast<unsigned char*>(pnObject);
        /*not compiling because static_cast does not allow conversion between
        pointers of unrelated types unsigned int to unsigned char*/

        /**
         * А такое преобразование - целиком на совести программиста. Его можно
         * применять, только четко представляя себе результат преобразования.
         */
        /**
         * And such a transformation is entirely on the conscience of the programmer. It can be
         * apply only with a clear understanding of the result of the transformation.
         */
        pucObject=(unsigned char*)pnObject;

        /** Проследите за значениями переменной `cc`. Объясните результаты. */
        /** Monitor the values ​​of the `cc` variable. Explain the results. */
        cc = pucObject[0];//0x88 = 136
        cc = pucObject[1];//0x77=119
        cc = pucObject[2];//0x66= 102
        cc = pucObject[3];//0x55=85

        /**
         * Выполните следующие строки, наблюдая за значениями следующих
         * выражений: `cc`, `p` и `*p`.
         *
         * Зафиксируйте и интерпретируйте результаты.
         */
        /**
         * Execute the following lines, observing the values ​​of the following
         * expressions: `cc`, `p` and `*p`.
         *
         * Record and interpret results.
         */
        cc = *(pucObject++);//value stored 136; pointing 0x77 because of post increment
        cc = (*pucObject)++;//vlaue stored 119; incremented to 120; pointing 0x77

        cc = ++*(pucObject);//value stored 121; preincrement ; pointing 0x78
        cc = *(++pucObject);//0x66=102
    }

    /**
     * Задание 7. Void-указатель.
     */

    /**
     * Задание 7.1.
     *
     * Выполняя задание, посмотрите - какие значения присваиваются
     * void-указателю.
     *
     * Обратите внимание: средствами отладчика вы не можете посмотреть
     * значения, на которые "указывает" void-указатель.
     */
    /**
     *Task 7.1.
     *
     * While completing the task, look at what values ​​are assigned
     * void pointer.
     *
     * Please note: you cannot view using the debugger
     * values ​​that the void pointer “points to”.
     */
    {
        void *pVoid;//it can holds any data types address
        int nObject3 = 5;
        char cObject3 = 'A';
        int *pInt = &nObject3;  //holding the address of nObject3
        pVoid = &nObject3;//assign address of nObject3
        pVoid = &cObject3;//reassigned address of cObject3
        pVoid = pInt;//pointing to an int again

        /**
         * Прежде, чем раскомментировать следующую строчку, вспомните: что
         * нужно сделать, чтобы выражение стало корректным?
         */
        /**
         *Before you uncomment the next line, remember:
         * what needs to be done to make the expression correct?
         * answer: to make the expression correct, we need to cast the void*
         * pointer back to the appropriate pointer type int*
         */
        pInt=static_cast<int*>(pVoid);

    }

    /**
     * Что нужно сделать для того, чтобы следующее закомментированное выражение
     * стало корректным?
     * What needs to be done to ensure that the following commented out expression
     * is now correct?
     * В закоментированной строке необходимо объявить void-указатель.
     * In the commented line you must declare a void pointer.
     */
    {
        const int n = 1;
        const void* pVoid = &n;//now it can point any types of data because of void
    }

    /**
     * Задание 7.2.
     *
     * При выполнении следующего фрагмента посмотрите, какие неприятности могут
     * Вас ожидать при явном приведении типа void-указателя, который в момент
     * времени (1) указывает на double, к типу указателя на int (2).
     */
    /**
     *Task 7.2.
     *
     * When performing the following fragment, see what troubles can occur
     * You should expect this when explicitly casting the type of a void pointer, which at the moment
     * time(1) points to double, to pointer type to int(2).
     */

    {
        cout<<"task 7.2: "<<endl;
        double dObject3 = 33.33;
        void* pVoid = &dObject3;  //(1) Assigning the address of a double

        //int nTmp = *(static_cast<int*>(pVoid) );

        double dTmp = *(static_cast<double*>(pVoid));  // Cast void* to double* and dereference
        int nTmp = static_cast<int>(dTmp); // Cast the double value to int (truncating the decimal part)

        cout << "The double value is: " <<dTmp<<endl;  // Output: 33.33
        cout << "The int value after casting is: "<< nTmp<<endl;  // Output: 33
    }

    /**
     * Задание 8. Модификатор const.
     */
    /**
     *Task 8. Modifier const.
     */

    /**
     * Задание 8.1.
     *
     * В каждом из заданий объявите указатель требуемого вида.
     *
     * Посредством каждого указателя попробуйте:
     *
     * - получить значение по адресу;
     * - записать новое значение по адресу;
     * - модифицировать указатель.
     */
    /**
     *Task 8.1.
     *
     * In each task, declare a pointer of the required type.
     *
     * For each pointer, try:
     *
     * - get the value by address;
     * - write a new value to the address;
     * - modify the pointer.
     */

    /**
     * Задание 8.1.1. Указатель является константой.
     */
    /**
     *Task 8.1.1. The pointer is a constant.
     */

    {
        cout<<"task 8.1.1: "<<endl;
        int n1= 15;
        int n2=35;
        int* const pC = &n1;//pC is pointer const that holding int n1 address
        //const pointer itself cant be edited to point another address after anitialized,
        //but we can edit the value at the address it point to.

        cout << "*n1 without editing: " << *pC << endl;// output 15

        *pC = 100;
        cout<< "n1 after editing: "<<*pC<< endl;//output 100

        //pC = &n2;
        /*cant be reassigned to point to a diff variable after initialization
        can edit the value at the address it points to*/

    }

    /**
     * Задание 8.1.2. Указываемое значение является константой.
     */
    /**
     *Task 8.1.2. The specified value is a constant.
     */

    {
        cout<<"task 8.1.2: "<<endl;
        //declare a const int
        const int n1 =42;
        const int n2 =60;

        const int* pC = &n1;//pC point to a const int
        cout<<"point to n1 : "<<*pC<<endl;//output 42

        //*pC = 50;//it will cause an error because here value is const

        pC =&n2;//modifing pointer
        cout<<"re pointing to n2 : "<<*pC<<endl;//output 60

        /*the pointer pC point to a cost int , meaning we cant change the value
        at the address it points to but we can change pC points to , allowing to
        point to different constant values*/

    }

    /**
     * Задание 8.1.3. И указатель, и указываемое значение являются константами.
     */
    /**
     *Task 8.1.3. Both the pointer and the value being pointed to are constants.
     */

    {
        cout<<"task 8.1.3: "<<endl;
        const int n1 = 42;
        const int n2 = 30;

        const int* const pC =&n1;// here pC is const pointer to a const int
        cout<< "const int const pointer to n1 : "<<*pC<<endl;

         //*pC =57;//pC is a pointer to a const int(cant be edited)
         //pC =n2;//pC is a const pointer

    }

    /**
     * Задание 8.2. Указатель на переменную, объявленную с ключевым словом
     * const.
     *
     * Объявите указатель и проинициализируйте его выражением - `&nN`.
     */
    /**
     *Task 8.2. Pointer to a variable declared with the keyword
     * const.
     *
     * Declare a pointer and initialize it with the expression - `&nN`.
     */

    {
        const int nN= 1;// variable nN is const
        const int* pN=&nN;// pN is a pointer to a const int, pointing to nN
        cout<<"pN point to nN : "<<*pN<<endl;//output 1

        //*pN =1;error  because nN is const

        const int nN1 = 20;
        pN =&nN1;
        cout<<"now pN is point to nN1: " << *pN<< endl;//nN1=20



    }

    /**
     * Задание 9. Указатели на указатели.
     */
    /**
     *Task 9. Pointers to pointers.
     */

    {
        int n = 1;

        /**
         * Объявите указатель pn и проинициализируйте его так, чтобы он
         * "указывал" на n.
         */
        /**
         * Declare a pn pointer and initialize it so that it
         * "pointed" to n.
         */
        int* pn=&n;//pn is a pointer to n


        /**
         * Объявите указатель ppn и проинициализируйте его так, чтобы он
         * "указывал" на pn.
         */
        /**
         * Declare a ppn pointer and initialize it so that it
         * "pointed" to pn.
         */
        int** ppn =&pn;


        /**
         * Объявите указатель pppn и проинициализируйте его так, чтобы он
         * "указывал" на ppn.
         */
        /**
         * Declare a pppn pointer and initialize it so that it
         * "pointed" to ppn.
         */
        int*** pppn=&ppn;

        /**
         * С помощью указателей pn, ppn и pppn получите значение объекта n и
         * присвойте его m.
         *//**
         * Using the pn, ppn and pppn pointers, get the value of object n and
         * assign it to m.
         */

        int m = ***pppn;
        cout<<"n :"<<n<<endl;//ouptut 1
        cout<<"m :"<<m<<endl;//output 1
    }
    return 0;
}