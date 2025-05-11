/**
 * Лабораторная работа №3. Перегрузка операторов, константные методы, битовые
 * поля, объединения.
 *
 * В этой работе и далее предполагается, что вы будете использовать классы,
 * написанные в прошлых работах, и дополнять их по необходимости. Эти классы
 * будут называться по имени без дополнительных указаний, что их надо взять из
 * прошлой работы.
 *
 * Предполагается, что новый классы будут созданы по аналогии с предыдущими
 * работами в отдельных файлах, которые будут включены в сборку.
 *
 * При работе с классами - в учебных целях - нельзя пользоваться контейнерами
 * стандартной библиотеки и нужно следовать принципам инкапсуляции.
 */
 /**
 * Laboratory work No.3. Operator overloading, constant methods, bit methods
 * fields, associations.
 *
 * In this work, it is further assumed that you will use classes
   written in previous works and supplement them as necessary. These classes are
 * they will be called by name without additional instructions that they should be taken from
 * previous work.
 *
 * It is assumed that the new classes will be created by analogy with the previous ones
 * works in separate files that will be included in the build.
 *
 * When working with classes - for educational purposes - containers should not be used
 * the standard library and must follow the principles of encapsulation.
 */

#include <utility>
#include <cassert>
#include <iostream>
#include <iostream>
#include <fstream> 
#include <cstring>//for strlen
#include "mystring.hpp"
#include "matrix.hpp"
#include "shortarray.hpp"
#include "workerdb.hpp"
#include "workerinfo.hpp"
#include "boolarray.h"
#include "basefile.hpp"




using namespace std;

MyString addTxtExtension(const MyString& path) {
    return path + ".txt";//concatenating the string and add .txt extension
}


int main() {

    /**
     * Задание 1. Перегрузка операторов.
     */

    /**
     * Задание 1.1. Оператор присваивания.
     *
     * Перегрузите оператор присваивания для классов `MyString` и `Matrix`.
     * Ожидается, что оператор присваивания работает так же, как конструктор
     * копирования. 
     *
     * Проверьте корректность работы оператора в следующих блоках кода.
     */
    /**
* Task 1. Operator overload.
     */

    /**
     * Assignment 1.1. Assignment operator.
     *
* Overload the assignment operator for the `myString` and `Matrix` classes.
     * The assignment operator is expected to work in the same way as the constructor
     * copying. 
     *
* Check that the operator is working correctly in the following code blocks.
     */

    {
        cout<<"\ntask 1.1"<<endl;
        MyString s1("AAA"), s2;
        s2 = s1;
        s1 = "CCC";
        s2 = MyString("tmp");
        s1 = s1;
        s1.print();
        s2.print();
    }

    {
        cout<<"\ntask 1.1"<<endl;
        Matrix m1(10), m2(10, 2);
        m1 = m2;
        m2 = Matrix(3, 4, 1.0);
        m1 = m1;
        m1.print(); 
        m2.print();
    }

    /**
     * Задание 1.2. Перегрузка арифметических операторов. Перегрузка методами и
     * глобальными функциями.
     */

    /**
     * Задание 1.2.1. Составное присваивание.
     *
     * Для класса `Matrix` перегрузите следующие операторы методом класса:
     * - `+=` и `-=` с объектом класса `Matrix`;
     * - `*=` и `/=` со значением double.
     *
     * Такие операторы не должны менять правый операнд. При наличии недопустимых
     * аргументов выкиньте какое-нибудь исключение.
     *
     * Ваши операторы должны работать в следующем блоке кода.
     */
    /**
* Task 1.2. Overloading arithmetic operators. Overloading with methods and
     * Global functions.
     */

    /**
     * Task 1.2.1. Compound assignment.
     *
* For the `Matrix` class, overload the following operators with the class method:
* - `+=` and `-=` with an object of the `Matrix` class;
     * - `*=` and `/=` with the double value.
     *
* Such operators should not change the right operand. If there are unacceptable
     * arguments, throw some kind of exception.
     *
* Your operators should work in the following code block.
     */

    {
        cout<<"\ntask 1.2.1"<<endl;
        Matrix m1(4), m2(4, 4, 1);
        m2 += m1;
        m2 -= m1 += m1;
        m1 *= 2;
        m2 /= 3;
        cout<<"matrix m1 after operations: "<<endl;
        m1.print();
        cout<<"matrix m2 after operations: "<<endl;
        m2.print();
    } 

    /**
     * Задание 1.2.2. Бинарные операторы.
     *
     * Для класса `Matrix` перегрузите следующие операторы методом класса:
     * - `+` и `-` с объектом класса `Matrix`;
     * - `*` с объектом класса `Matrix`;
     * - `*` и `/` со значением double.
     *
     * Эти операторы не должны изменять ни левый, ни правый операнд и возвращать
     * новое значение.
     */
    /**
* Task 1.2.2. Binary operators.
     *
* For the `Matrix` class, overload the following operators with the class method:
* - `+` and `-` with an object of the `Matrix` class;
     * - `*` with an object of the `Matrix` class;
     * - `*` and `/` with the double value.
     *
* These operators should not change either the left or right operand and return
     * new value.
     */

    {
        cout<<"\ntask 1.2.2"<<endl;
        Matrix m1(4), m2(4, 4, 1);
        Matrix m3 = (m1 + m2) * m1 * 4 / 2 - m2;

        cout<<"matrix m3 after operations: "<<endl;
        m3.print();
    } 

    /**
     * Задание 1.2.3. Перегрузка глобальными функциями.
     *
     * Перегрузите оператор `*` для операндов `double` и `Matrix` глобальной
     * функцией.
     *
     * Перегрузите унарный оператор `-` для класса `Matrix` с помощью глобальной
     * функции.
     *
     * Какую из этих функций нельзя перегрузить методом класса? Почему?
     */
    /**
* Task 1.2.3. Overloading with global functions.
     *
* Overload the `*` operator for the `double` and `Matrix` operands.
     * function.
     *
* * Overload the unary operator `-` for the class `Matrix' using the global
     * Functions.
     *
* Which of these functions cannot be overloaded with a class method? Why?
->the unary neg operator - cannot be overloaded with a class method. because unary operator s are typically overloaded as global functions, they only need one operand. 
*/
    {   
        cout<<"\ntask 1.2.3"<<endl;
        Matrix m1(3, 3, 2.0);
        Matrix neg = -m1;
        Matrix scaled = 2.5 * m1;

        neg.print();
        scaled.print();


    }

    /**
     * Задание 1.2.4. Операторы для строки.
     *
     * Перегрузите операторы `+` и `+=` для класса `MyString`, где в качестве
     * правого операнда будет `MyString` или `const char *`. Сложение в этом 
     * случае должно выполнять конкатенацию строк.
     *
     * Ваши операторы должны работать в следующем блоке кода.
     */
    /**
* Task 1.2.4. Operators for a string.
     *
* Overload the operators `+` and `+=` for the 'myString` class, where as
     * the right operand will be `myString` or `const char *`. The addition in this 
     * the case must perform string concatenation.
     *
* Your operators should work in the following code block.
     */

    {
        MyString s1("abc"), s2("def"), s3;
        s1 += s2 += "111";
        s2 += "222" + s1 + "333";
        s3 += s3;
        s1.print();
        s2.print();
        s3.print();
    } 

    /**
     * Задание 1.3. Move-семантика.
     *
     * Перегрузите move-оператор присваивания и move-конструктор для классов
     * `MyString` и `Matrix`. В этих операторах нужно "забирать" данные из
     * правого операнда, а не копировать. При этом правый операнд должен
     * становиться "пустым".
     *
     * С помощью отладчика или отладочной печати отследите, сколько раз в
     * следующем блоке происходит выделение динамической памяти, - до реализации
     * move-оператора/конструктора и после.
     *
     * 
     **
* Task 1.3. Move-semantics.
     *
* Overload the move assignment operator and the move constructor for classes
     * `myString` and `Matrix'. In these operators, you need to "take" data from
     * the right operand, not copy. In this case, the right operand must
     * * becomes "empty".
     *
* Use the debugger or debug print to track how many times
dynamic memory is allocated in the * next block, before implementation
     * move-operator/constructor and after.

->before:mystring: memory is allocated 3 times. once for s1, once for s2,ans once for the new val of s1 after the assign.
Matrix memory is allocated 2 times. once for m1 and once for m2.
->Mystring move operations will not cause memory allocations during s2 = std::move(s1) since it simply transfer ownership of memory. 
Matrix move operations will also not cause new memrory allocations during m2 = std::move(m1)as the ownership of memory is transferred from m1 to m2, and m1 becomes "empty".
     
     */

    {
        cout<<"\n task 1.3"<<endl;
        MyString s1("abc");
        MyString s2 = s1 + "ccc";
        s1 = "abc" + s2;
        s2 = std::move(s1);

        Matrix m1(4), m2 = m1 + m1;
        m1 = m2 * m1;
        m2 = std::move(m1);
    } 

    /**
     * Задание 1.4. Операторы сравнения.
     *
     * Реализуйте для класса `MyString` операторы сравнения `==`, `!=`, `<`,
     * `<=` для сравнения с объектами `MyString` и `const char *`.
     *
     * Операторы должны сравнивать строки лексиграфически.
     */
    /**
* Task 1.4. Comparison operators.
     *
* * Implement comparison operators for the `String' class `==`, `!=`, `<`,
     * `<=` for comparison with the objects `myString` and `const char *`.
     *
     * * Operators must compare strings lexicographically.
     */

    {
        cout<<"\ntask 1.4"<<endl;
        MyString s1("abc"), s2("ab"), s3 = s1;
        assert(s2 < s1);//ab is less than abc
        assert(s1 == s3);//abc = abc
        assert(s1 != s2);//abc is not equal to ab
        assert(s1 <= s3);//abc is equal to abc , so it is less than or equal
        
        assert("ab" == s2);//ab is equal to s2
        assert("aba" < s1);//aba is lexicographicallly less than abc
        assert("aba" <= s3);//aba is lexi... less than abc so it's less than or equal
    } 

    /**
     * Задание 1.5. Оператор индексирования.
     *
     * Перегрузите оператор индексирования для класса `MyString`, который
     * возвращает ссылку на i-тый символ. Если индекс выходит за границы
     * массива, киньте какое-нибудь исключение.
     */
    /**
* Task 1.5. Indexing operator.
     *
* Overload the indexing operator for the `myString` class, which
     * returns a reference to the ith character. If the index goes beyond the boundaries
     * Please throw some kind of exception.
     */

    {   cout<<"\ntask 1.5"<<endl;

        MyString s1("abc");
        cout << "before modification:" << endl;
        s1.print();//print before changes

        s1[0] = s1[1] = 'd';
        s1[0] = s1[1] = 'd';
        cout << "after modification:" << endl;
        s1.print();
    
    } 

    /**
     * Задание 1.6. Операторы ввода и вывода с потоками стандартной библиотеки.
     *
     * Реализуйте для класса `MyString` операторы `<<`, который позволит
     * выводить строку в поток вывода `std::ostream`.
     *
     * Реализуйте для класса `MyString` оператор `>>`, который позволит вводить
     * строку до первого переноса строки из потока ввода `std::istream`.
     *
     * Проверьте работу этих операторов на следующем примере.
     */
    /**
* Task 1.6. Input and output operators with streams of the standard library.
     *
* Implement the `<<` operators for the `myString` class, which will allow
     * output a string to the output stream `std::ostream'.
     *
* Implement the `>>` operator for the `myString` class, which will allow you to enter
     * a line before the first line break from the input stream `std::istream'.
     *
* Check the operation of these operators using the following example.
     */

    {
        MyString s("123");//initialize MyString with "123"
        cout << "this is my string: '" << s << "'\n";//output the str

        cout << "enter your string: ";//taking input and storing to s
        cin >> s;
        cout << "your string: '" << s << "'\n";//output form s
    }

    /**
     * Задание 2. Константные методы.
     *
     * Объявите все методы (в том числе перегруженные операторы), которые не
     * должны менять объект, для которого они были вызваны, константными.
     *
     * После этого следующая функция должна собираться:
     *
     * MyString addTxtExtension(const MyString &path) { return path + ".txt"; }
     */
    /**
* Task 2. Constant methods.
     *
* Declare all methods (including overloaded operators) that do not
     * must change the object for which they were called to be constant.
     *
* After that, the following function should be built:
*
* * myString adds the Txt extension(const Qstring &path) { returns the path + ".txt"; }
     */
    {      cout << "\ntask 2" << std::endl;

           MyString fileName("file");
           MyString newFileName = addTxtExtension(fileName);
    
           cout <<"new file name: " << newFileName << std::endl;
    
        
           std::ofstream out("data/task2_mystring.txt");
           if (out.is_open()) {
               out << newFileName << std::endl;
               out.close();
               cout << "saved to data/task2_mystring.txt" << std::endl;
           } 
           else {
               cerr << "error: Could not open file to write." << std::endl;
            }
    }


    /**
     * Задание 3. Объединения и битовые поля.
     */

    /**
     * Задание 3.1. Динамический массив.
     *
     * Реализуйте класс ShortArray, который будет хранить динамический массив
     * элементов типа short, количество выделенной памяти (size_t) и количество
     * элементов массива (size_t).
     *
     * Реализуйте для этого класса конструкторы и операторы, которые посчитаете
     * нужными, оператор `[]`, а также методы:
     * - `void push(short new_val)` - для добавления элемента в конец массива;
     * - `short pop()` - для удаления и возвращения элемента из конца массива;
     * - `size_t size() const` - возвращает размер массива;
     * - `void resize(size_t new_size, short fill_value = 0)` - изменение
     *    размера массива, при увеличении размера массив заполняется значением
     *    `fill_value`.
     * 
     * Продемонстрируйте ниже работу класса.
     */
     /**
     * Task 3. Unions and bit fields.
     */

    /**
     * Task 3.1. Dynamic array.
     *
     * Implement the ShortArray class, which will store a dynamic array
     * elements of the short type, the amount of allocated memory (size_t) and the number of
     * array elements (size_t).
     *
     * Implement the constructors and operators for this class that you consider
     * necessary, the operator `[]`, as well as the methods:
     * - `void push(short new_val)' - to add an element to the end of the array;
     * - `short pop()' - to remove and return an element from the end of the array;
     * - `size_t size() const' - returns the size of the array;
     * - `* - `void resize(size_t new_size, short full_value = 0)` - change
     * the size of the array, as the size increases, the array is filled with the value
     *    `fill_value`.
     * 
     * Demonstrate the work of the class below.
     */

     {
        cout<<"\ntask 3.1 "<<endl;
        ShortArray arr;

        arr.push(7);//pushing
        arr.push(14);
        arr.push(21);

        cout<<"arr after pushing : ";//0,7,14,21
        for(size_t i = 0; i<arr.size() ; ++i){
            cout<<arr[i]<< " ";
        }
        cout<<endl;

        arr.resize(6,99);

        cout<<"array after resize(6,99): ";//0,7,14,21,99,99
        for(size_t i = 0; i < arr.size(); ++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        short last = arr.pop();
        cout<<"popped element: "<< last<<endl;//99

        cout<<"final array: ";//0,7,14,21,99
        for(size_t i = 0; i< arr.size(); ++i){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";



     }

    /**
     * Задание 3.2. Объединения.
     *
     * Есть проблема: даже для самого маленького массива будет
     * выделена динамическая память. Однако, размер у такой структуры может
     * быть, например, 24 байта, что вмещает встроенный массив из 12 элементов.
     *
     * С помощью объединений в языке С мы можем интерпретировать одни и те же
     * данные по разному. Поля динамического массива { short *, size_t, size_t }
     * мы можем воспринимать как массив short.
     *
     * Используя объединения, реализуйте хранение элементов массива прямо в
     * памяти, отведенной под этот класс, если массив туда помещается.
     * По каким признаком вы можете различить хранится ли память динамически или
     * она встроена в класс?
     *
     * Рассчитайте допустимый размер массива через оператор sizeof. Проверьте,
     * что объем памяти, занимаемой классом не увеличилась.
     *
     * Продемонстрируйте, что все методы работают верно для обоих способов
     * хранения памяти.
     */
    /**
* Task 3.2. Associations.
     *
* There is a problem: even for the smallest array there will be
     * Dynamic memory is allocated. However, the size of such a structure may
     * be, for example, 24 bytes, which accommodates an embedded array of 12 elements.
     *
* Using joins in C, we can interpret the same
     * Data in different ways. Dynamic array fields { short *, size_t, size_t }
     * we can think of it as a short array.
     *
* Using joins, implement the storage of array elements directly in
     * the memory allocated to this class, if the array fits there.
     * * By what criteria can you distinguish whether memory is stored dynamically or
* is it embedded in a class?
-> size(if array exceeds goto dynamically allocated)
-> pointer(if data stored in a pointer it's dynamic, if it's in a fixed size array it's embedded)
-> memory size(the class size increases with dynamically allocation)

*
* Calculate the allowed size of the array using the sizeof operator. Check it out,
     * that the amount of memory occupied by the class has not increased.
     *
* Demonstrate that all methods work correctly for both methods
     * Storage of memory.
     */

    {   
        
        cout << "task 3.2\n";

        ShortArray arr;

        //less than 12 will be inline
        for (short i = 0; i < 10; ++i) {
            arr.push(i * 2);
        }

        cout << "inline array content: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        //switch to dynamic
        arr.push(100);
        arr.push(200);
        arr.push(300); 

        cout << "after pushing beyond inline capacity:\n";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";

        arr.resize(20, 99);//test resizing down
        cout << "after resize(20, 10): ";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << "\n";

    }

    /**
     * Задание 3.3. Выравнивание и битовые поля.
     *
     * Для того, чтобы различить, используется ли динамическая память, можно
     * использовать последний бит адреса динамически выделенного массива. Из-за
     * того, что используется тип short, этот адрес всегда будет делиться на 2
     * из-за выравнивания адресов. Таким образом, если самый младший бит будет
     * равен 1, то мы можем быть уверены, что динамическая память не
     * используется.
     *
     * С помощью битовых полей получите доступ к этому биту, а остальную часть
     * байта, в котором он находится, интерпретируйте как размер массива.
     *
     * Добейтесь, чтобы ваш класс работал, как в пункте 3.2, при этом его размер
     * был бы равен `sizeof(short *) + 2 * sizeof(size_t)`.
     */
    /**
* Task 3.3. Alignment and bit fields.
     *
* In order to distinguish whether dynamic memory is being used, you can
     * use the last bit of the address of the dynamically allocated array. Because of
     * the fact that the short type is used, this address will always be divisible by 2
     * due to address alignment. So if the lowest bit is
     * is equal to 1, then we can be sure that the dynamic memory is not
     * used.
     *
* Use the bit fields to access this bit, and the rest of the
     * interpret the byte in which it is located as the size of the array.
     *
* Make sure that your class works as described in paragraph 3.2, while its size
     * would be equal to `sizeof(short *) + 2 * sizeof(size_t)`.
     */
    {
        
        ShortArray arr;

        arr.push(7);
        arr.push(14);
        arr.push(21);

        
        cout << "array after pushing elements: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout<<endl;

        //resize the array and fill with 99
        arr.resize(6, 99);

        
        cout << "array after resize(6, 99): ";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout<<endl;

        //pop the last element from the array
        short last = arr.pop();
        cout << "popped element: " << last << std::endl;

        
        cout << "final array: ";
        for (size_t i = 0; i < arr.size(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

    }

    /**
     * Задание 4. Ассоциативный массив. Итератор. Операторы инкремента.
     */

    /**
     * Задание 4.1. Ассоциативный массив.
     *
     * Создайте класс `WorkerDb`, который будет хранить базу данных рабочих
     * некой организации в виде ассоциативного массива. В таком массиве индексом
     * является не номер элемента, а какое-то другое значение. В этом случае -
     * фамилия сотрудника. В самом же массиве будет храниться структура с
     * информацией о работнике.
     *
     * Реализуйте для этого класса оператор `[]`, который будет по фамилии
     * возвращать ссылку на данные работника. Если такого работника еще нет,
     * то запись для этого работника создается.
     *
     * Используйте для хранения строковых данных ваш класс MyString.
     */
    /**
* Task 4. Associative array. The iterator. Increment operators.
     */

    /**
     * Task 4.1. Associative array.
     *
     * * Create a `Worker' class that will store a database of workers
     * an organization in the form of an associative array. In such an array, the index is
     * is not an item number, but some other value. In this case
, * the employee's last name. The array itself will contain a structure with
     * information about the employee.
     *
* Implement the operator `[]` for this class, which will be by last name
     * return a link to the employee's data. If there is no such employee yet,
* then a record is created for this employee.
     *
* Use your myString class to store string data.
     */

    {
        cout<<"\ntask 4.1"<<endl;
        WorkerDb db;
        db["Ivanov"] = WorkerData("Ivan", 34);
        db["Petrov"] = WorkerData("Petr", 43);
        cout << "Ivanov's name = " << db["Ivanov"].name << "\n";
        cout << "Petrov's age = " << db["Petrov"].age << "\n";
        cout<<endl;
    }

    /**
     * Задание 4.2. Итератор.
     *
     * На практике воспользоваться таким классом будет довольно сложно, потому
     * что чтобы получить информацию о работниках, нужно откуда-то знать их
     * фамилии (ключи в массиве).
     *
     * Чтобы решить такую проблему, часто используют паттерн *итератор*.
     * Объект-контейнер (у нас - WorkerDb) умеет возвращать объект, который
     * перебирает его элементы. Для обычного массива в С таким объектом является
     * указатель, однако, сам по себе указатель не содержит информации, когда
     * элементы массива закончатся. Поэтому в пару к указателю, который
     * указывает на элементы (`begin`), добавляют указатель, который будет
     * обозначать, что элементы закончены (`end`):
     * 
* Task 4.2. Iterator.
     *
* In practice, it will be quite difficult to use such a class, because
     * that in order to get information about employees, you need to know their
last names from somewhere (keys in the array).
     *
* To solve this problem, the *iterator* pattern is often used.
     * The container object (our WorkerDb) is able to return an object that
     * iterates through its elements. For a regular array in With such an object is
     * the pointer, however, the pointer itself does not contain information when
     * the array elements will run out. Therefore, in addition to the pointer, which
     * points to the elements (`begin`), add a pointer that will
     * indicate that the elements are finished (`end`):
     *
     * ```
     * int arr[] = {1, 2, 3, 4, 5};
     *
     * for (int *begin = arr, *end = arr + sizeof(arr) / sizeof(arr[0]);
     *      begin != end;
     *      ++begin)
     *  {
     *      std::cout << *begin << ' ';
     *  }
     *
     * ```
     *
     * В языке C++ наследуется эта идиома: объекты-контейнеры возвращают
     * объект-итератор методами `begin()` и `end()`. Для итератора определены
     * операторы `==`, `!=`, префиксный и постфиксный `++`, а также операторы
     * разыменования `*` и `->`. Также часто итераторы копируются (оператор
     * `=`).
     *
     * Реализуйте для вашего класса `WorkerDb` итератор, который при
     * разыменовании будет возвращать ссылку на `WorkerData`, а также иметь
     * метод `key()`, который будет возвращать ключ для этих данных
     * (фамилию). Итераторы допускается объявлять дружественными для
     * класса-контейнера.
     *
     * Проверьте ниже работу итератора.
     * * In C++, this idiom is inherited: container objects return
     * The iterator object is defined by the `begin()` and `end()` methods.
     * operators `==`, `!=`, prefix and postfix `++`, as well as operators
     * dereference of `*` and `->'. Iterators are also often copied (the operator
     * `=`).
     *
* Implement an iterator for your `WorkerDb` class, which, when
* dereferencing, will return a reference to `WorkerData', and also have
     * the `key()` method that will return the key for this data
     * (last name). Iterators can be declared friendly to
     * the container class.
     *
* Check the operation of the iterator below.
     */

    { 
        cout<<"\ntask 4.2"<<endl;
        WorkerDb db;
        db["Ivanov"] = WorkerData("Ivan", 34);
        db["Petrov"] = WorkerData("Petr", 43);
        for (auto it = db.begin(); it != db.end(); ++it)
        {
            cout << it.key() << " -> " << it->name << '\n';
        }
    }

    /**
     * Задание 4.3. Работа "прикладного программиста".
     *
     * Не меняя класс `WorkerDb`, напишите функцию `print_db(WorkerDb&)`,
     * которая будет печатать базу данных работников на консоль, и функцию
     * `double get_avg_age(WorkerDb&)`, которая будет подсчитывать средний
     * возраст сотрудников. Эти функции не должны быть дружественными классу
     * `WorkerDb`.
     */
    /**
* Assignment 4.3. The work of an "application programmer".
     *
* Without changing the `WorkerDb' class, write the `print_db(WorkerDb&)` function,
     * which will print the employee database to the console, and the function
     * `double get_avg_age(WorkerDb&)`, which will calculate the average
     * the age of the employees. These functions don't have to be class-friendly.
     * `WorkerDb`.
     */
    {
        cout<<"\ntask 4.3"<<endl;
        WorkerDb db;
        db["Ivanov"] = WorkerData("Ivan", 34);
        db["Petrov"] = WorkerData("Petr", 44);
        
        print_db(db);
        
        cout << "Average age: " << get_avg_age(db) << '\n';
    

    }

    /**
     * Задание 5. Неявно определенные операторы. Удаление операторов.
     *
     * Проверьте, определен ли оператор присваивания для класса `BaseFile` из
     * работы 2? Что он делает? Имеется ли смысл в таком операторе?
     *
     * Явно удалите оператор присваивания и конструктор копирования ключевым
     * словом `delete`, но определите их move-аналоги в этом классе.
     * Продемонстрируйте их работу.
     */
    /**
* Task 5. Implicitly defined operators. Deleting operators.
     *
-> Check whether the assignment operator is defined for the `Base File` class from  2 jobs? 
= the compiler implicitly defines an assignment operator for classes that don’t explicitly declare one.

-> What is he doing?
= the default assignment operator would simply copy the file_ptr and
= mode values from one BaseFile object to another. it can lead problems like double free, dangling ptr.

->Does such an operator make sense?
= no. the default assignment operator doesn’t make sense for a class managing resources like file pointers.
= Copying resources like file pointers can result in resource management problems.
     
     * Explicitly remove the assignment operator and copy constructor.
     * the word `delete', but define their move counterparts in this class.
     * Demonstrate their work.
     */
    

     /*{
          
          BaseFile file1("file1.txt", "w");
          BaseFile file2("file2.txt", "w");

          // attempt to assign one BaseFile object to another
          file2 = file1;//issues because file2 and file1 will both hold the same file pointer  
          
          //fixed file in tests
     
     }*/

    /**
     * Задание 6. Оператор неявного приведения типа.
     *
     * Реализуйте класс `BoolArray`, представляющий динамический массив
     * логических значений (тип bool). В наивной реализации (`new bool[n]`) есть
     * проблема: каждая переменная типа bool занимает 1 байт, то есть 8 бит, в
     * то время как она могла бы занимать 1 бит.
     *
     * Реализуйте этот класс таким образом, чтобы каждое значение значений
     * действительно занимало 1 бит (точнее сказать, чтобы n значений занимали
     * не более ceil(n / 8), где ceil - целая часть числа с округлением вверх).
     *
     * Класс должен поддерживать следующее поведение:
     */
    /**
* Task 6. The operator of implicit type conversion.
     *
* * Implement the `Bool Array` class, which represents a dynamic array
     * Boolean values (type bool). In the naive implementation (`new bool[n]`) there is
     * problem: each variable of type bool occupies 1 byte, that is, 8 bits,
while it could occupy 1 bit.
     *
* Implement this class in such a way that each value of the values
     * really took up 1 bit (more precisely, so that n values occupied
     * no more than ceil(n / 8), where ceil is the integer part of the number rounded up).
     *
     * The class must support the following behavior:
     */
   
    

    {
        cout<<"\ntask 6"<<endl;
        /// Создается массив из 10 значений false  Create a BoolArray with 10 elements, all initialized to false
        BoolArray ar1(10);

        /// Создается массив из 5 значений true Create a BoolArray with 5 elements, all initialized to true
        BoolArray ar2(5, true);

        /// Создается независимая копия `ar2` Create an independent copy of ar2
        BoolArray ar3(ar2);

        /// 4 и 6 элементу (нумерация с 0) устанавливаются заданное значение Set elements 4 and 6 to true
        ar1[4] = ar1[6] = true;

        /// Над полученными значениями выполняем логические операции Perform logical operations
        ar1[2] = (!ar1[6] && ar1[8] || (ar1[0] != true));

        /// Выведем массив на печать Print array in [0, 1] format
        std::cout << "[";
        for (int i = 0; i < ar1.size(); ++i) {
            if (i > 0) std::cout << ", ";
            std::cout << ar1[i];
        }
        std::cout << "]\n";

        /// Выведем массив на печать по-другому Print indices of true values
        std::cout << "[";
        for (int i = 0, printed = 0; i < ar1.size(); ++i) {
            if (ar1[i]) {
                if (printed++ > 0) std::cout << ", ";
                std::cout << i;
            }
        }
        std::cout << "]\n";


       /// Метод `resize` изменяет размер массива. Если новый размер больше, то
       /// новые значения дополняются заданным значением (по умолчанию false). Если
       /// новый размер меньше, то конец массива отбрасывается.
       /// The `resize` method changes the size of the array. If the new size is larger, then
       /// new values are supplemented with the specified value (false by default). 
       // If the new size is smaller, then the end of the array is discarded.

        ar1.resize(12, true);
        /// выведите массив на печать

        //...
        std::cout << "array after resizing to 12 with true: ";
        ar1.print();

        ar1.resize(4, true);
        /// выведите массив на печать снова

        //...
        std::cout << "array after resizing to 4 with true: ";
        ar1.print();

    } 

	return 0;
}
