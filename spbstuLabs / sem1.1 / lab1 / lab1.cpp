/**
 * Практическое занятие №1. Базовые типы данных, операторы языка, простой
 * ввод-вывод.
 *
 * В результате выполнения данной работы слушатель получает много мелких, но
 * необходимых для дальнейшей работы навыков, поэтому задание построено как
 * последовательность закомментированных блоков, которые требуется
 * последовательно раскомментировать, отвечая при этом на поставленные вопросы.
 *
 * Необходимое программное обеспечение:
 *
 * - Unix-совместимая командная строка (для Windows необходимо установить WSL);
 * - ком0пилятор g++, отладчик gdb (для установки в командной строке:
 *   `apt update; apt install gcc g++ gdb`)
 * - любимый текстовый редактор.
 *
 * Примерная последовательность действий при отладке проекта:
 * 1. наберите (исправьте, раскомментируйте нужный фрагмент) исходный текст
 *    программы;
 * 2. скомпилируйте программу (в командной строке: `g++ -g lab1.cpp`);
 * 3. запустите отладчик (в командной строке `gdb ./a.out`);
 * 4. в отладчике установите точку останова на нужной строке (например, 
 *    `break 55` для 55 строки или `b 55` - так короче) и начните выполнение 
 *    программы (`run` или `r`).
 * 5. выведите значение интересующей переменной (`print cByte` или `p cByte`)
 *    или добавьте переменную для постоянного отслеживания (`watch cByte`).
 * 6. Переходите к следующей точке останова (`c`) или к следующей строке (`n`).
 */

#include  <iostream>

int nTwin = 1; /*global variable and we can access it from anywhere 
                of this program even inside from a function but 
                for that we have to use :: oparetor to to call the 
                global variable */
namespace TwinSpace { int nTwin = 2; }//our this nTwin belongs to TwinSpace variable

int main()
{   

    /**
     * Задание 1. Работа с отладчиком. Базовые типы данных. Литералы.
     *
     * Выполняя программу по шагам, следите за значениями переменных и
     * интерпретируйте результат (помните, что количество байт, отводимых под
     * int, системо-зависимо).
     *
     * Обратите внимание на разную интерпретацию отладчиком signed и unsigned
     * целых типов данных, а также на внутреннее представление отрицательных
     * целых чисел.
     */
    /**
     * Task 1. Working with the debugger. Basic data types. Literals.
     *
     * While executing the program step by step, monitor the values of variables and interpret the result
     * (remember that the number of bytes allocated for int is system-dependent).
     *
     * Pay attention to how the debugger interprets signed and unsigned integer types, as well as the internal representation of negative integers.
     */
    
    char cByte = 'A'; //65 'A'; 65 in ASCII, output: A beacuse type char

    cByte = 0x42; //66 'B'; initialized hexa value, 66 in ASCII, output B because type char 

    cByte = 66;//66 'B'; initialized decimal value, again output B because type char

    cByte = -1;//-1 '\377'; -1 signed char, '\377' in octal, output unknwon


    unsigned char ucByte = 0x41; //65 'A': i-zed hexa value, 65 in ASCII, output A because type char    

    ucByte = 'B';//66 'B';66 in ASCII, output B 

    ucByte = -1; //255 '\377'; here -1 initialized as 255 because unsigned char can't be negative
    
    ucByte = -15; //255? TODO: check if result will indeed be 255
                  //241 '\361': here -1 initialized as 241 because unsigned range 0 to 255 and we are initializing negative so 255-14 = 241

    int iInt = 0xffffffff; //-1; 

    unsigned int uiInt = 0xffffffff; //4294967295 ;because unsigned and 2^32 bit's
    

    float fFloat = 1.f;  //1 

    double dDouble = 1.; //1
    

    /**
     * Выполните фрагмент, приведенный далее. В комментариях отразите, что
     * реально заносится в переменную. Объясните разницу между этим значением и
     * инициализатором.
     */
    /**
     * Execute the following fragment. In the comments, reflect what is actually stored in the variable. 
     * Explain the difference between this value and the initializer.
     */

    double d = 0.1234567890123456789123456789;
    //0.12345678901234568; here some values are missing because double store limitation
    float  f = 0.1234567890123456789123456789; 
    //0.123456791; here also because float store limitation

    d = 1.; //1 ;
    d = 0.999999999999999999999999999999999;  //1; here it stored 1 because limitaion of degit and the value is so close to 1

    /**
     * В комментариях напишите результат, возвращаемый оператором sizeof для
     * переменной типа wchar_t (ее размер)
     */
    /**
     * In the comments, write the result returned by the sizeof operator for the wchar_t variable (its size).
     */

    wchar_t cw = L'Ф'; 
    size_t n = sizeof(cw); //n = 4

    /**
     * Задание 2a. Неявное приведение типов данных. 
     *
     * Объясните разницу результата при выполнении (1) и (2): Покажите явно
     * (напишите в коде) преобразования, которые неявно выполняет компилятор
     */
     /**
     * Task 2a. Implicit type conversion.
     *
     * Explain the difference in the result when executing (1) and (2): Explicitly show (write in the code) the conversions that the compiler implicitly performs.
     */

    iInt = 1;
    double dDouble1 = iInt / 3;     // (1)0 ; because int is divided by int and stored in double
    double dDouble2 = iInt / 3.;    // (2)0.33333333333333331 : int is devisible by double(3.) that's why fractional value stored in dDouble2

    /**
     * Ассоциативность операторов.
     *
     * Синтаксис языка C допускает "цепочечное" присваивание (как в строках (1)
     * и (2)). Посмотрев результаты выполнения строк (1) и (2) (значения
     * переменных dDouble, fFloat, nInt, sShort, cByte), определите порядок
     * выполнения присваиваний при цепочечной записи и объясните результат.
     *
     * Расставьте скобки, явно определяющие порядок выполнения, как это сделал
     * бы компилятор. Объясните (в комментариях) предупреждения (warnings)
     * компилятора.
     */
     /**
     * Operator associativity.
     *
     * C language syntax allows "chain" assignments (as in lines (1) and (2)). 
     * By looking at the results of executing lines (1) and (2) (the values of the variables dDouble, fFloat, nInt, sShort, cByte), 
     * determine the order of assignment operations during chain assignment and explain the result.
     *
     * Place parentheses that explicitly define the order of execution as the compiler would. 
     * Explain (in comments) the compiler warnings.
     */


    short sShort;
    dDouble = fFloat = iInt = sShort = cByte = 3.3 / 3; // (1)1 ; right to left
    
    cByte = sShort = iInt = fFloat = dDouble = 3.3 / 3; // (2)1 ;right to left

    /**
     * Ниже Вам дан пример "небрежного" использования неявного приведения
     * типов, что может привести к нежелательным результатам - объясните (в
     * комментариях), к каким?
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор.
     */
    /**
     * Below is an example of "careless" use of implicit type conversions, which can lead to undesired results - 
     * explain (in comments) what those results are.
     *
     * Write explicitly the conversions that the compiler performs implicitly.
     */

    iInt = 258;
    cByte = iInt; //1 ; because char is 1 byte = 8 bits, 2^8 = 256, 257 % 256 = 1; that's why cByte holds 1

    unsigned char cN1 = 255, cN2 = 2, cSum;
    cSum = cN1 + cN2; //1; 255 + 2 = 257 % 256 = 1 same as before

    /**
     * Сравните предыдущую строчку с приведенной ниже. 
     *
     * Объясните (в комментариях), почему в следующей строке не происходит
     * выход за разрядную сетку
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор
     */
    /**
     * Compare the previous line with the one below.
     *
     * Explain (in comments) why there is no overflow in the following line.
     *
     * Write explicitly the conversions that the compiler performs implicitly.
     */

    int iSum = cN1 + cN2; //257 ;because cN1 and cN2 unsigned and the range is correct  (0 to 255), 255 + 2 = 257 which is stored in variable type int

    /**
     * Напишите, почему при сложении одинаковых значений (одинаковых в двоичной
     * системе) в строках (1) и (2) получаются разные результаты.
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор и
     * объясните, что при этом происходит.
     */
     /**
     * Explain why adding the same values (in binary) in lines (1) and (2) results in different outcomes.
     *
     * Write explicitly the conversions that the compiler performs implicitly and explain what happens.
     */

    char c1 = 0xff, c2 = 2;// c1 = -1 because signed and c2 = 2
    unsigned char uc1 = 0xff, uc2 = 2; // uc1 = 255 and uc2 = 2 all positive because unsigned
    int iSum1 = c1 + c2;   //(1)-1 + 2 = 1
    int iSum2 = uc1 + uc2; //(2)255 + 2 = 257

    
    /**
     * Задание 2b. Явное приведение типов данных.
     *
     * Проинтерпретируйте результат (значения переменной dDouble) в строке (3).
     *
     * Напишите явно преобразования, которые неявно выполняет компилятор.
     */
    /**
     * Task 2b. Explicit type conversion.
     *
     * Interpret the result (the value of the variable dDouble) in line (3).
     *
     * Write explicitly the conversions that the compiler performs implicitly.
     */

    int nTmp = 100, nn = 3;
    dDouble = 3.3 + nTmp / nn; // (3) 36.299999999999997 : here some data we loss when we was doing dividation because it was int / int

    /**
     * Получите результат без потери точности с помощью оператора явного
     * приведения типа.
     */
    /**
     * Obtain the result without loss of precision using explicit type conversion.
     */


    double dDouble3 = 3.3 + static_cast<double>(nTmp) / nn;   // (4) 36.633333333333333 : there is no data loss here because we changed our data type int to dauble


    
    /**
     * Задание 3. Область действия, область видимости и время существования
     * переменных.
     *
     * В этом фрагменте фигурируют четыре переменных с одним и тем же именем
     * nTwin - одна глобальная, вторая определена в своем пространстве имен,
     * (определены выше в начале модуля) третья - локальная внутри функции
     * main(), четвертая - вложенная локальная внутри блока. 
     *
     * В данном задании требуется в выделенных местах фрагмента определить, к
     * какой из четырех переменных идет обращение, а также факт существования и
     * видимости для всех четырех, заполнив приведенные в задании таблицы.
     *
     * Для выведения информации в отладчике можно воспользоваться командой 
     * `info locals`, которая выведет локальные переменные в функции main(),
     * и командой `watch nTwin` или `wacth ::nTwin` для отслеживания значений
     * переменных.
     */
    /**
     * Task 3. Scope and visibility of variables.
     *
     * In this fragment, there are four variables with the same name nTwin - 
     * one global, the second defined in its own namespace, the third is local inside the main() function,
     * and the fourth is nested local inside a block.
     *
     * In this task, you need to determine which of the four variables is being referenced at the highlighted points,
     * as well as the fact of existence and visibility for all four, filling out the provided tables in the assignment.
     *
     * For output in the debugger, you can use the command `info locals` which outputs local variables in the main() function, 
     * and the command `watch nTwin` or `watch ::nTwin` to monitor the values of the variables.
     */

    // :: global scope resolution operator
    nTwin = 100; // global nTwin
    TwinSpace::nTwin = 300;// namespace variable
    nTwin++; // global nTwin and value is 100 + 1 = 101

    int nTwin; // Local variable inside main()
    nTwin = 200;  // local nTwin = 200
    ::nTwin++;  // now global nTwin = 102, global nTwin, using the "::" operator
    {
        // TODO: check what variable will be referenced by name `nTwin` here, if we comment next line
        
        //int nTwin; // Block-scoped variable (local to this block)
        nTwin = -1; //now, this nTwin will be initialized local nTwin which is inside main().
        // block-scoped nTwin, not the one in main()
        ::nTwin++; //global nTwin, now global nTwin = 103
        TwinSpace::nTwin++; //namespace variable, now TwinSpace::nTwin = 301
    }

    nTwin--;// local nTwin inside main(), now nTwin = 199


    /**
     * Задание 4. Спецификатор класса памяти - static.
     *
     * 1. Для каждой итерации цикла напишите значения пременных nLocal# и
     *    nStatic#.
     * 2. Напишите, когда выполняется инициализация обеих переменных.
     * 3. Поясните (в комментарии) разницу между способом инициализации
     *    переменных nStatic1 и nStatic2 и поясните побочный эффект, влияющий 
     *    на переменную nLocal2.
     */
    /**
     * Task 4. Static storage class specifier.
     *
     * 1. For each iteration of the loop, write the values of the variables nLocal# and nStatic#.
     * 2. Write when both variables are initialized.
     * 3. Explain (in the comments) the difference between the initialization methods of the variables nStatic1 and nStatic2 and explain the side effect that affects the variable nLocal2.
    
     */

    for (int i = 0; i < 3; i++)
    {
        static int nStatic1 = 100;//in this code nStatic1 will be initialized one time because of static
        int nLocal1 = 100;//it will be initialized 100 for each iteration;101,101,101
        int nLocal2 = 200;//it will be initialized 200 for each iteration;201,201,201
        static int nStatic2 = nLocal2++ * 2;//initialized once;401,402,403
        nStatic1++;
        nStatic2++;
        nLocal1++;
//side effect of nLocal12: post increment of nLocal2 occour's nLocal2 to be incremented immediately after it's value is used; 201; reinitialized 200 and again 201
// nStatic1 = 101,102,103
// nLocal1 = 101,101,101
// nLocal2 = 201,201,201 (post increment)
// nStatic2 = 401, 402, 403    
    }

    /**
     * Напишите:
     * 1. как изменилось поведение пременной nStatic1?
     * 2. как эта переменная _инициализирована_?
     */
    /**
     * Write:
     * 
     * 1. How has the behavior of the variable nStatic1 changed?
     * 2. How is this variable initialized?
     */

    for (int i = 0; i < 3; i++)
    {
        static int nStatic1;
        nStatic1 = 100;// here explicitly re-initialized to 100 // assigned, not re-initialized
        int nLocal1 = 100;
        nStatic1++; //101,101,101; initalized only once because of staic; then nStaic1 = 100 explicitly re-initialized; each interation it becoming 100+1 = 101;
        nLocal1++; //101,101,101;
    }


    /**
     * Задание 5. Перечисления - enum.
     *
     * Обратите внимание на явную и неявную инициализацию констант. 
     *
     * Выполняя задание по шагам, следите за значениями, которые принимает
     * переменная myColors.
     */
    /**
     * Task 5. Enumerations - enum.
     *
     * Pay attention to the explicit and implicit initialization of constants.
     *
     * While completing the task step by step, monitor the values assigned to the variable myColors.
     */

    enum eColors
    {
        BLACK, //0
        BLUE, //1
        GREEN, //2
        RED=5, //5 because explicit
        YELLOW, //6
        WHITE=RED+4 //5 + 4 = 9
    };
    
    eColors myColors; //объявление переменной типа eColors ( Declaring a variable of type eColors)
    myColors = BLACK;
    myColors = BLUE;
    myColors = GREEN;
    myColors = RED;
    myColors = YELLOW;
    myColors = WHITE;

    int nnn = BLACK; //любой целочисленной переменной можно присвоить
                     //значение из списка инициализирующих значений
                     //Any integer variable can be assigned a value 
                     //from the list of initializers


    //Именованные константы можно использовать в выражениях:
    nnn = BLUE | YELLOW; //1 + 6 = 7

    /**
     * Раскомментируйте следующую строку и обратите внимание на ошибку при
     * компиляции.
     *
     * Модифицируйте выражение таким образом, чтобы компилятор не выдывал
     * ошибки.
     */
    /**
     * Uncomment the following line and note the compilation error.
     *
     * Modify the expression so that the compiler does not produce an error.
     */


    myColors = static_cast<eColors>(1); //casting

    /**
     * Выполните следующее присваивание НЕ меняя перечисление и тип переменной
     * myColors.
     */
    /**
     * Execute the following assignment WITHOUT changing the enum or the type of the variable myColors.
     */


    myColors = static_cast<eColors>(123); //casting
 

    /**
     * Задание 6.1 Логический тип bool.
     *
     * Выполняя задание по шагам, следите за значениями переменной b и
     * интерпретируйте результат. 
     *
     * Напишите эти значения в комментариях.
     */
     /**
     * Task 6.1. Logical type bool.
     *
     * While completing the task step by step, monitor the values of the variable b and interpret the result.
     *
     * Write these values in the comments.
     */

    int nNumber = 1;
    bool b = (nNumber != 0); //1
    b = (nNumber == 0); //0
    b = (nNumber > 0); //1
    b = (nNumber > 1); //0
    b = 5; //1, any non-zero value assigned to a bool is considered true

    /**
     * Вы всегда можете преобразовать логическое значение к целому явно или
     * компилятор может это сделать самостоятельно (неявно).
     *
     * Обратите внимание: как интерпретирует значения логических переменных
     * компилятор?
     */
    /**
     * You can always explicitly convert a boolean value to an integer, or the compiler can do it implicitly.
     *
     * Note how the compiler interprets the values of logical variables.
     */



    int tmp =  b + 1; //2

  

    /**
     * Задание 6.2.
     *
     * В Григорианском календаре (которым мы все пользуемся) високосный год
     * определяется по следующему алгоритму: високосным является каждый
     * четвертый год, но каждый сотый високосным не является, при этом каждый
     * 400-й год все таки високосный. Т.е. 1823 - не високосный, 1824 -
     * високосный, 1900 - не високосный, 2000 - високосный.
     *
     * Напишите фрагмент кода, такой что логическая переменная isLeapYear
     * принимает значение true, если год, заданный переменной year -
     * високосный. Проверьте значение в отладчике.
     *
     * Указание: в этом задании нельзя использовать операторы if-else, switch и
     * тернарный оператор; необходимо написать логическое выражение в одну
     * строку.
     */
    /**
     * Task 6.2.
     *
     * In the Gregorian calendar (which we all use), a leap year is determined by the following algorithm:
     * A leap year occurs every fourth year, but every hundredth year is not a leap year, unless it is also divisible by 400.
     * For example, 1823 is not a leap year, 1824 is a leap year, 1900 is not a leap year, and 2000 is a leap year.
     *
     * Write a code fragment where the logical variable isLeapYear is set to true if the year stored in the variable year is a leap year. Check the value in the debugger.
     *
     * Hint: In this task, you are not allowed to use if-else statements, switch, or ternary operators; you must write a logical expression in one line.
     */

    {
        int year = 1823;//f because 1823 % 4 != 0
        // year = 1824;t
        // year = 1900;f
        // year = 2000;t

        bool isLeapYear = (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
        std::cout << "isLeapYear : " << isLeapYear;
    }
   
  
    /**
     * Задание 7. Модификатор const и переменные.
     *
     * Раскомментируйте следующие две строчки и объясните (в комментариях)
     * ошибки при компиляции.
     */
    /**
     * Task 7. Const modifier and variables.
     *
     * Uncomment the following two lines and explain (in comments) the compilation errors.
     */


    {
        const int nN = 1; // because constant must be initialized at diclaration
        //  nN = 1; constant don't support modification
    }

    std::cout << "Task 8 : \n"<< std::endl;
    /**
     * Задание 8. Потоки ввода и вывода C++.
     *
     * Напишите фрагмент кода, который бы с помощью объектов потока std::cin и
     * std::cout делал бы следующее:
     *
     * 1. Выводил бы на экран номер задания.
     * 2. Считывал целое число.
     * 3. Считывал символ.
     * 4. Выводил пользователю введенный им символ.
     * 5. Выводил пользователю введенное им целое число.
     *
     * При этом добавьте в места, где от пользователя ожидается ввод,
     * соответствующие приглашения ко вводу (например, `Введите целое число: `). 
     */
    /**
     * Task 8. C++ Input and Output Streams.
     *
     * Write a code fragment that uses std::cin and std::cout objects to do the following:
     *
     * 1. Output the task number to the screen.
     * 2. Read an integer.
     * 3. Read a character.
     * 4. Output the entered character to the user.
     * 5. Output the entered integer to the user.
     * Additionally, add appropriate input prompts for the user (e.g., "Enter an integer:").
     */

    {
        int iInt;
        char iChar;

        std :: cout << "Task 8: C++ Input and Output Streams\n";

        std::cout << "enter an interger : ";
        std::cin >> iInt;// taking input int

        std::cout << "enter an character : ";
        std::cin >> iChar;//taking input char

        std::cout << "you have entered the character : " << iChar << std::endl;
        std::cout << "you have entered the integer : " << iInt << std::endl;
    }

    /**
     * Задание 9. Логические условные операторы и операторы отношения.
     */
    /**
     * Task 9. Logical conditional operators and relational operators.
     */
     std::cout << "Task 9.1 : \n"<< std::endl;
    /**
     * Задание 9.1. 
     *
     * Напишите фрагмент кода, который переводит код символа, хранящийся в
     * переменной ch в противоположный регистр.
     *
     * Требуется предусмотреть проверку ситуации, когда пользователь ввел цифру
     * или нажал другую клавишу, которой символ не соответствует.
     *
     * Подсказка: работаем только с символами английского алфавита, для
     * которого в таблице кодов ASCII код каждой буквы нижнего регистра на 0x20
     * больше кода соответствующей буквы верхнего регистра.
     */
    /**
    * Write a code fragment that converts the code of the character stored in the variable ch to the opposite case.
     *
     * Ensure that the situation where the user enters a number or another key that is not an alphabet character is handled.
     *
     * Hint: Only work with English alphabet characters, for which the ASCII code of each lowercase letter is 0x20 more than the corresponding uppercase letter.
     */


    {
        char ch;

        std::cout << "enter a character : ";
        std::cin >> ch;

        if ( ch >= 'a' && ch <= 'z'){
            ch = ch - 0x20;
            std::cout << "the opposite character is : "<< ch << std:: endl;

        }
        else if (ch >= 'A' && ch <= 'Z'){
            ch = ch + 0x20;
            std::cout << "the opposite character is : "<< ch << std:: endl;

        }
        else {
            std::cout << "the entered character is not an alphabetic character."<< std::endl;

        }
        /** Тут сформируйте значение переменной ch с помощью потока ввода. */
        /** Form the value of the variable ch using the input stream. */
        
        /** Тут измените регистр. */
         /** Change the case. */

        /** Тут вывели получившийся символ пользователю. */
        /** Output the resulting character to the user. */
    }

     std::cout << "Task 9.2 : \n"<< std::endl;
    /**
     * Задание 9.2. 
     *
     * Напишите фрагмент кода, который реализует с помощью if (if/else)
     * следующую логику: если x меньше или равен 0, y=0, если x больше 0 но
     * меньше 1, то y=x, если x больше или равен 1, то y=1.
     *
     * Подумайте: какого типа должны или могут быть x и y?
     */
    /*
    * Write a code fragment that implements the following logic using if (if/else):
     * If x is less than or equal to 0, set y=0; if x is greater than 0 but less than 1, set y=x; if x is greater than or equal to 1, set y=1.
     *
     * Think about: What type should or could x and y be?
     */
    {
        double x, y; // x, y will be double or float

        if (x <= 0) {
            y = 0;
        } 
        else {
            if (x < 1) {
                y = x;
            }    
            else {
                y = 1;
            }
        }       
    std::cout << "x = " << x << ", y = " << y << std::endl;
    }


    std::cout << "Task 9.3 : \n"<< std::endl;
    /**
     * Задание 9.3 
     *
     * Напишите фрагмент кода, который реализует с помощью switch следующую
     * логику: в переменной cInput типа char дано значение символа, введенного
     * любым способом.
     *
     * Если введен символ 'y' (т.е. yes) в любом регистре, то присвоить
     * переменной у значение переменной x.
     *
     * Если введен символ 'n' (т.е. no) в любом регистре, то присвоить
     * переменной у значение (x * 2).
     *
     * Если любой другой симол, то вывести сообщение об ошибке.
     */
    /**
     * Task 9.3 
     *
     * Write a code fragment that implements the following logic using a switch statement:
     * In the variable cInput of type char, the user enters a character.
     *
     * If the character 'y' (yes) is entered in any case, assign the value of x to y.
     *
     * If the character 'n' (no) is entered in any case, assign the value (x * 2) to y.
     *
     * If any other character is entered, output an error message.
     */

    {
        char cInput;
        double x, y;

        std::cout << "enter a value for x : " ;
        std::cin >> x;

        std::cout << "enter a character 'y' or 'n' : ";
        std::cin >> cInput;
         
        switch (cInput)
        {
        case 'y':
            
        case 'Y':
            y = x;
            std::cout << "the value of y is : "<< y << std:: endl;
            break;
        case 'n':
            
        case 'N':
            y = x * 2;
            std::cout << "the value of y is : "<< y << std:: endl;
            break;
        default:
            std::cout << "Error, input is not correct. enter y or n "<< std::endl;
            break;
        }
    }

    
    /**
     * Задание 10. Циклы.
     */
    /**
     * Task 10. Loops.
     */
    std::cout << "Task 10.1 : \n"<< std::endl;
    /**
     * Задание 10.1.
     *
     * Напишите фрагмент кода, который реализует с помощью for следующую
     * логику: найти сумму заданного диапазона целых чисел.
     *
     * Введите границы с помощью потока ввода или с помощью средств отладки. 
     *
     * Предусмотрите защиту от ввода нижней границы больше, чем верхней.
     */
    /**
     * Task 10.1.
     * Write a code fragment that uses a for loop to calculate the sum of a given range of integers.
     * Input the range boundaries using the input stream or debugging tools.
     * Ensure that the lower boundary is not greater than the upper boundary.
     */


    {
        /** сформироыать границы диапазона */
        /** Form the range boundaries */

        /** проверить корректность значений */
        /** Check the correctness of values */
        
        /** вычислить сумму */
        /** Calculate the sum */

        /** проверить в отладчике значение */
        /** Check the value in the debugger */
        
        int lowerBoundary, upperBoundary, sum = 0;

        std::cout << "enter the lower boundary : ";
        std::cin >> lowerBoundary;
        std::cout << "enter the upper boundary : ";
        std::cin >> upperBoundary;

        if (lowerBoundary > upperBoundary) {
            
            std::cout << "lower boundary is greater than upper boundary. swapping the values. " << std::endl;
            std::swap(lowerBoundary, upperBoundary);// using swap

        }
        for (int i = lowerBoundary; i <= upperBoundary; ++i){
            sum += i;

        }
        std::cout << "Sum : " << sum << std:: endl;
       
    }
    std::cout << "Task 10.2 : \n"<< std::endl;
    /**
     * Задание 10.2. 
     *
     * Напишите фрагмент кода, который реализует с помощью do-while следующую
     * логику: на каждой итерации цикла ввести с консоли целое значение и
     * покинуть цикл, если значение удовлетворяет условию: значение больше или
     * равно 10 и четное.
     */
     /**
     * Task 10.2. 
     *
     * Write a code fragment that uses a do-while loop with the following logic: 
     * On each iteration, input an integer from the console and exit the loop if the value is greater than or equal to 10 and even.
     */

    {
        
        int input;

        do {
            std::cout << "enter an integer : ";
            std::cin >> input;
        }
        while (!(input >= 10 && input % 2 == 0));//when condision is ture it will stop the loop

            std::cout << "exit the loop, the entered value is : " << input << std::endl; 
        

    }

    std::cout << "Task 10.3 : \n"<< std::endl;
    /**
     * Задание 10.3. 
     *
     * Напишите фрагмент кода, который реализует с помощью while следующую логику: 
     *
     * 1. исходно int x = 0; 
     * 2. на каждой итерации x = x + 1, sum = sum + 1 / x;
     * 3. необходимо найти значение x, при котором sum > 1.7.
     */
    /**
     * Task 10.3. 
     *
     * Write a code fragment that implements the following logic using a while loop:
     *
     * 1. Initially, int x = 0;
     * 2. On each iteration, increment x by 1, and sum = sum + 1 / x;
     * 3. Find the value of x at which sum > 1.7.
     */


    {
        int x = 0;//1,2,3
        double sum = 0.0;

        while (sum <= 1.7){
            x++;
            sum = sum + 1.0 / x; //(1/1)+(1/2)+(1/3)
        }

        std::cout << "the value of x when sum > 1.7 is : " << x << std::endl;

    }

    std::cout << "Task 10.4 : \n"<< std::endl;
    /**
     * Задание 10.4.
     *
     * Раскомментируйте следующий блок кода, который считает сумму 10
     * последовательных натуральных чисел, начиная со 120. 
     *
     * Объясните логические ошибки в нем и исправьте их.
     */
     /**
     * Task 10.4.
     *
     * Uncomment the following block of code, which calculates the sum of 10 consecutive natural numbers starting from 120.
     *
     * Explain the logical errors in it and fix them.
     */

    {
        // char start = 120, sum = 0; because of char, range of char is -128 to 127 for signed but 
        //we are adding(120,121) more than 127 so it's overflowed. So we should change our variable type 
        //char to int 
        int start = 120, sum = 0;
        for (int n = start; n < start + 10; ++n) {
            sum += n;//120+121+...+129=1245
        }
         std::cout << "the sum of 10 consecutive natural numbers starting from " << start << " is: " << sum << std::endl;
    }

    return 0; /** код завершения приложения */
}

