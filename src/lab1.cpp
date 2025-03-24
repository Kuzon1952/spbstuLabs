/**
 * Лабораторная работа №1. Классы и объекты в языке C++: конструкторы,
 * деструкторы, поля и методы. Различные способы применения классов. Сборка
 * проекта и автоматические тесты.
 *Lab Work #1. Classes and Objects in C++: Constructors, Destructors, Fields, and Methods. Various Applications of Classes. Project Build and Automated Testing.
 * 
 * Лабораторные работы 1-3 в этом семестре построены в виде программы на языке
 * C++, в функции main этой программы в комментариях написаны задания, которые
 * необходимо выполнить.
 * Lab Works 1-3 this semester are structured as a C++ program. The main function of this program contains commented instructions with tasks to be completed.
 *
 * Для выполнения задания необходимо выполнить следующее.
 * To fulfill the assignment, the following steps are required:
 *
 * 1. Написать код на языке C++, реализующий требования в задании или написать
 *    в комментариях ответ на поставленный вопрос. Все задания должны быть
 *    реализованы в рамках одной программы, которая должна собираться и работать
 *    без ошибок, если в задании явно не указано обратное.
 * Write C++ code implementing the task requirements or provide answers to questions in comments. 
 * All tasks must be implemented within a single program that compiles and runs without errors unless explicitly stated otherwise.
 * 
 * 2. В написанной программе не должно быть ошибок в работе с памятью: утечек
 *    памяти, чтение или запись вне выделенной памяти, использование памяти
 *    после освобождения. Для этого строго рекомендуется использовать
 *    инструментальные средства, такие как AddressSanitizer, Valgrind, leaks, VLD и
 *    пр.
 * The program must not have memory-related errors: memory leaks, out-of-bounds reads/writes, or use-after-free issues. 
 * Use tools like AddressSanitizer, Valgrind, leaks, VLD, etc., to ensure correctness.
 * 
 * 3. В рамках работ этого семестра мы НЕ используем контейнеры стандартной
 *    библиотеки C++: string, vector, list, map, set, shared_ptr, unique_ptr и
 *    пр. Целью работ в том числе является обучение работе с памятью с помощью
 *    объектов. Задания должны быть выполнены без использования этих или
 *    аналогичных готовых классов.
 * For these assignments, do not use C++ Standard Library containers : string, vector, list, map, set, shared_ptr, unique_ptr, or similar classes. 
 * The goal is to practice manual memory management through custom objects. Implement tasks without relying on these or equivalent pre-built classes.
 *
 * Для этих работ указания будут приведены для следующих инструментов разработки:
 * The following tools are recommended for this work:
 *
 * - компилятор g++;
 * - отладчик gdb;
 * - командная строка bash;
 * - система сборки GNU Make;
 * - библиотека AddressSanitizer для обнаружения утечек памяти.
 *
 * Вы можете использовать другие инструменты (zsh, clang, lldb, CMake, VS и
 * пр.), если они позволяют выполнить задания в полном объёме.
 * You may use alternative tools (e.g., zsh, clang, lldb, CMake, Visual Studio) if they meet the assignment requirements.
 *
 * Перед выполнением работ настоятельно рекомендуется выполнить работы первого
 * семестра, чтобы познакомиться с базовыми конструкциями языка C и с
 * особенностями работы с памятью в языке С, а также получить опыт работы с
 * компилятором и отладчиком.
 * Before starting, it is strongly recommended to complete the first-semester assignments to familiarize yourself with C fundamentals,
 * memory management, and gain experience with compilers and debuggers.
 *
 */

#include <iostream>
#include <cstring>
#include "rect.hpp"
#include "barrel.hpp"
#include "matrix.hpp"
#include "mystring.hpp"
#include "TextWrapper.hpp"


using namespace std;

class C {
    MyString s;
    Rect c;
};

void foo() {
    C c;
    // what will the implicit default constructor do in this case?
    // TODO: check, if the fields of C will be initialized
}

int main()
{
    /**
     * Задание 1. Классы. Объявление класса, создание экземпляров класса. Явные
     * и неявные конструкторы и деструкторы. Методы класса и их вызов.
     * Task 1. Classes. Class declaration, creating class instances. Explicit 
     * and implicit constructors and destructors. Class methods and their invocation. 
     */

    /**
     * Задание 1.1. Объявление класса.
     *
     * Создайте новый класс с именем `Rect`. Этот класс должен представлять
     * прямоугольник на двумерной координатной плоскость, стороны которого
     * параллельны осям координат. Такие прямоугольники особенно часто
     * встречаются при разработке графических приложений - любое окно программы
     * является именно таким прямоугольником.
     * Create a class Rect representing an axis-aligned rectangle on a 2D coordinate plane. 
     * The class should have four integer fields for the left, right, top, and bottom boundaries.
     *
     * Обычно классы объявляют в отдельной паре файлов: в заголовочном файле
     * `rect.hpp` объявлют класс и вспомогательные определения (константы,
     * enum'ы и прочее), в файле `rect.cpp` определяют методы класса.
     * Create two files: rect.hpp (header) for the class declaration and rect.cpp (source) for method definitions.
     *
     * Создайте файлы `rect.hpp` и `rect.cpp`, определите в файле `rect.hpp` 
     * класс `Rect` у которого будет 4 целочисленных поля, имеющих смысл 
     * координат левой, правой, верхней и нижней границы прямоугольника.
     * Пока что не объявляйте явно никаких конструкторов или деструкторов.
     * Declare the Rect class in rect.hpp with public integer fields: left, right, top, bottom.
     *
     * Подключите файл `rect.hpp` к этому файлу директивой `include`.
     * Include rect.hpp in your main file (e.g., main.cpp).
     *
     */

    /**
     * Задание 1.2. Неявные (implicit) конструкторы и деструкторы. (Implicit Constructors and Destructors)
     *
     * Раскоментируйте следующий блок кода. С помощью отладчика посмотрите,
     * как были инициализированы поля класса.
     * -Uncomment the following block of code. 
     * -Use a debugger to examine how the class fields are initialized.  
     *
     * Объясните, какой код будет вызываться для объекта при выполнении
     * следующего блока, кто определил этот код, что такой код делает в этом
     * случае и в общем случае.
     * -Explain what code will be executed for the object when this block runs,
     * who defined this code, what this code does in this case, and what it generally does.
     *
     */
    


    {
        cout<<"task1.2\n"<<endl;

        Rect rect;
        //the implicit default constructor leaves the fields uninitialized, resulting in garbage values and 
        //the implicit destructor performs minimal cleanup when the object goes out of scope.
        cout<<endl;
    }

    /**
     * Задание 1.3. Явно определенные конструкторы. Конструктор по умолчанию. (Explicitly Defined Constructors. Default Constructor.)
     *
     * Объявите в файле `rect.hpp` конструктор для класса `Rect`, который бы
     * принимал бы 4 координаты сторон прямоугольника (соответственно полям).
     * Declare a constructor in rect.hpp for the Rect class that accepts four coordinates representing the sides of the rectangle (corresponding to the fields).
     *
     * Объясните ошибку компиляции, которая произошла после добавления
     * конструктора.
     *Explain the compilation error that occurs after adding the constructor.
     *
     * Добавьте конструктор по умолчанию, который заполняет все координаты
     * нулями.
     * Add a default constructor that initializes all coordinates to zero.
     */
    
    {
        cout<<"task1.3\n"<<endl;

        Rect rect(1, 2, 3, 4);

        //after adding the parameterized constructor, found an error 
        //because defining a parameterized constructor suppresses the implicit default constructor.
        cout<<endl;
    }

    /**
     * Задание 1.4. Конструктор копирования. (Copy Constructor)
     *
     * Раскоментируйте блок кода ниже. Какие конструкторы вызываются в коде
     * этого блока? Кто определил эти конструкторы? Что они делают в этом случае 
     * и в общем случае?
     * Comment out the code block below. Which constructors are called in the code
     * this block? Who defined these constructors? What do they do in this case? 
     * and in the general case?
     * 
     */

    { 
        cout<<"task 1.4"<<endl;
        Rect rect1(1, 2, 3, 4);//the parameterized constructor is called here.
        
        Rect rect2 = rect1;//the copy constructor is called here.

        Rect rect3(rect1);//the copy constructor is called here.

        //the parameterized constructor is defined by the programmer
        //initializes the fields of rect1 with provided values 1,2,3,4
        //in this case: parameterized constructor initializes the fields of rect1 by 1,2,3,4
        //and copy constructor copies the values of rect1 gields into rect2 and rect3 

        cout<<endl;
        
    }

    /**
     * Задание 1.5. Деструктор. (The destructor.)
     *
     * Что такое деструктор? Когда он вызывается? Есть ли деструктор в вашем
     * классе `Rect`? Что делает такой деструктор в вашем случае и в общем
     * случае?
     * What is a destructor?
     * When is it called?
     * Does your Rect class currently have a destructor?
     * What does this destructor do in your case and in general?
     *
     * Определите в классе `Rect` деструктор, в котором поставьте отладочную
     * печать. Пронаблюдайте и зафиксируйте в предыдущих заданиях, когда
     * вызывается деструктор.
     * Define a destructor in the Rect class and add a debug print statement inside it.
     * Observe and record when the destructor is called in the previous exercises.
     */

    //a destructor is aspecial member function in c++ that is automatically called when an object goes out of scope or is explicitly destroyed.
    //destructor called in severals senarios like automatic objects, dynamic objects, program termination
    //yes, my Rect class currently have destructor (~Rect)
    //in this case: Rect class only contrains primitive data members, the destructor prints a debug message and it releases resources held bu the object

    /**
     * Задание 1.6. Когда вызываются конструкторы и деструкторы? When Are Constructors and Destructors Called?
     * 
     *
     * Определите явно конструктор копирования в классе `Rect`, который делал
     * бы то же, что и конструктор копирования, определенный неявно.
     * Define an explicit copy constructor in the Rect class that does the same thing as the implicitly defined copy constructor.
     *
     * Добавьте во все конструкторы отладочную печать, которая бы печатала, какой 
     * конструктор вызван и адрес объекта через указатель `this`.
     * Add debug print statements to all constructors that print which constructor was called and the address of the object using the this pointer.
     *
     * Проследите, когда в следующем блоке кода вызываются конструкторы и
     * деструкторы для каждого объекта. Отметьте в комментариях места в коде,
     * где это происходит. Подсчитайте общее количество вызовов конструкторов и
     * деструкторов и объясните это количество.
     * Trace when constructors and destructors are called for each object in the following block of code. 
     * Mark in the comments where this happens in the code. Count the total number of constructor and destructor calls and explain this count.
     */

    {

        cout<<"\ntask 1.6"<<endl;

        Rect r1; //default constructor is called for r1
        Rect *pR = new Rect(1,2,1,2);//parameterized constructor is called pR
        {
            Rect r2(r1);//copy constructor is called for r2
            Rect arRect[2];//default constructor is called for two times because of array
            for(int i = 0; i < 3; i++)
            {
                static Rect r3 (i,i,i,i) ;//parameterized constructor is called for static r3 one time
                Rect r4(*pR);//copy constructor is called for r4
                Rect r5(i,i,i,i);//parameterized constructer is caleed for r5
            }
        }
        delete pR; //destructor is called for pR
        //total constructor calls 12
        //total destructor calls 12
    }

    /**
     * Задание 1.7. Публичные и приватные поля класса. Public and private fields of the class.
     *
     * Сделайте все поля вашего класса приватными. Попробуйте в блоке кода ниже * Make all fields of your class private. Try it in the code block below
     * обратиться к полю напрямую. Объясните ошибку компиляции.   * Access the field directly. Explain the compilation error.
     */

    {
        Rect r1;
        cout<<r1.getLeft()<<endl;// because left is private in Rect to solve this we have to use getter setter methods
    }

    /**
     * Задание 1.8. Инкапсуляция. Методы для доступа к объектам класса. Encapsulation. Methods for accessing objects of the class.
     *
     * Принципы объектно-ориентированного программирования предписывают
     * разделять ответственности разработчиков и пользователей определенной
     * функциональности. Разработчик глубоко разбирается в том, как работает
     * эта функциональность, а пользователь освобожден от этой необходимости и
     * пользуется только публичным интерфейсом, за который несет ответственность
     * разработчик. При этом пользователь рассчитывает *только* на публичный
     * интерфейс, а не на внутреннюю реализацию, что позволяет разработчику
     * поддерживать совместимость только интерфейса, а внутреннюю реализацию
     * менять по своему усмотрению.
     *
     * Например, хранение вещей в доме X организуется мамой, она указывает, где
     * найти определенную вещь и куда ее надо потом положить, и никто кроме нее
     * не знает, где что лежит. Если все члены семьи будут брать и класть вещи,
     * как им хочется, будет хаос. Чтобы его не было, нужно либо всем знать,
     * как именно мама раскладывает вещи (по какой логике), либо проводить все
     * операции через маму. Первый вариант запрещает маме менять логику
     * хранения по своему усмотрению - нужно будет переучивать всех, второй же
     * менее гибкий и более бюрократичный. Какой из них верный - зависит от
     * ситуации, и больше всего это зависит от количества людей в системе. Если
     * с мамой живет только папа, то и первый вариант вполне подходит, а если
     * еще и двузначное количество детей и тетушек, то, вероятно, некая форма
     * бюрократии будет необходима.
     *
     * В этом примере функциональностью является хранение вещей, а публичным
     * интерфейсом - мама. В C++ же функциональность оформляется в виде
     * классов, а публичный интерфейс в виде методов в секции `public`.
     *
     * В этом примере и далее мы будем *предполагать*, что "бюрократичный"
     * вариант является верным и будем реализовать именно его - в первую
     * очередь в учебных целях, - потому что реализовать "первый" вариант
     * всегда легче. Мы будем *все* поля класса помещать в секцию `private`, а
     * доступ к ним будем давать через методы.
     *
     * Итак, добавьте в ваш класс публичные методы `get_left`, `get_right`,
     * `get_top` и `get_bottom`, которые будут возвращать значения координат
     * левой, правой, верхней и нижней стороны прямоугольника соответственно.
     *
     * Добавьте метод `set_all(int left, int right, int top, int bottom)`,
     * который устанавливал значения соответствующих полей.
     *
     * Продемонстрируйте работу этих методов ниже.
     * 
     * /**

     *
     * The principles of object-oriented programming prescribe
     * share the responsibilities of developers and users.
     * Functionality. The developer has a deep understanding of how it works
     * this functionality, and the user is exempt from this need and
     * uses only the public interface for which he is responsible
     * Developer. At the same time, the user is counting *only* on the public
     * the interface rather than the internal implementation, which allows the developer
     * maintain interface compatibility only, and the internal implementation
     * change it at your discretion.
     *
     * For example, the storage of things in house X is organized by mom, she indicates where
     * to find a certain thing and where to put it later, and no one but her
     * doesn't know where everything is. If all family members will take and put things,
     * As they wish, there will be chaos. To avoid it, you either need to know everything.,
     * how exactly does mom arrange things (according to what logic), or spend everything
     * operations through mom. The first option forbids mom to change the logic
     * storage at your discretion - you will need to retrain everyone, the second one is
     * Less flexible and more bureaucratic. Which one is correct depends on
     * the situation, and most of all it depends on the number of people in the system. If
     * only dad lives with mom, then the first option is quite suitable, and if
     * if there are also a double-digit number of children and aunts, then there is probably some form of
     * Bureaucracy will be necessary.
     *
     * In this example, the functionality is storage of things, and the public
     * The interface is mom. In C++, the functionality is designed as
     * classes, and the public interface in the form of methods in the `public` section.
     *
     * In this example and further, we will *assume* that "bureaucratic"
     * the option is correct and we will implement it - first of all
     * the queue is for educational purposes, because to implement the "first" option
     * It's always easier. We will put *all* class fields in the `private` section, and
     * access to them will be given through methods.
     *
     * So, add the public methods `get_left`, `get_right` to your class,
     * `get_top` and `get_bottom`, which will return coordinate values
     * The left, right, top, and bottom sides of the rectangle, respectively.
     *
     * Add the `set_all(int left, int right, int top, int bottom)` method,
     * which set the values of the corresponding fields.
     *
     * Demonstrate how these methods work below.
     
     */

    {
       cout<<"task: 1.8"<<endl;

       Rect r;
       std::cout << r.get_left() << "; " << r.get_right() << '\n';
       r.set_all(1, 2, 3, 4);
       std::cout << r.get_top() << "; " << r.get_bottom() << '\n';
    } 

    /**
     * В литературе, особенно английской, методы часто называют
     * функциями-членами (member-functions), и этот термин предпочтительно
     * использовать в контексте именно C++, а не других объектно-ориентированных
     * языков (Java, Python и др.).
     * In literature, especially English, methods are often called
     * member-functions, and this term is preferred
     * use in the context of C++ specifically, and not other object-oriented languages
     * languages (Java, Python, etc.).
     *
     * Напишите в комментариях, чем функция-член отличается от обычной функции.
     * Write in the comments how the member function differs from the regular function.
     */

     //a <<member function>> is a fuction that is declarecd inside a class and is associated with that class. it has access to the private and protected members of the class.
     //and a <<regular function>> is defind outside any class and does not have access to private or protected members of  a class unless explicitly granted assess.

    /**
     * Задание 1.9. Перегрузка функций и методов. Значение параметров по
     * умолчанию.
     * Overloading functions and methods. The value of the software parameters
     * by default.
     *
     * Добавьте методы в класс `Rect`:
     * - `void inflate(int amount)` - отодвигает каждую из сторон от центра
     *   прямоугольника на величину `amount`;
     * - `void inflate(int dw, int dh)` - отодвигает верхнюю и нижнюю сторону на `dh`,
     *   а левую и правую - на `dw`;
     * - `void inflate(int d_left, int d_right, int d_top, int d_bottom)` - аналогично,
     *   но для каждой стороны отдельно.
     *
     * Реализуйте метод `void move( ? )` со значениями параметров по умолчанию,
     * который осуществляет параллельный перенос по следующей логике: 
     * - `rect.move(1, 2)` перемещает прямоугольник на 1 по оси Х и на 2 по оси Y;
     * - `rect.move(1)` перемещает прямоугольник на 1 по оси X.
     * 
     *  
     *
     * Add methods to the `Rect` class:
     * - `void inflate(int amount)` - moves each side away from the center
     * rectangle by the value of `amount`;
     * - `void inflate(int dw, int dh)' - moves the upper and lower sides to `dh`,
     * and the left and right are on `dw`;
     * - `void inflate(int d_left, int d_right, int d_top, int d_bottom)' - similar,
     * but for each side separately.
     *
     * Implement the `void move( ? )` with default parameter values,
     * which performs parallel transfer according to the following logic: 
     * - `rect.move(1, 2)` moves the rectangle by 1 on the X-axis and by 2 on the Y-axis;
     * - `rect.move(1)` moves the rectangle by 1 on the X-axis.
     
     */
    {
        cout<<"task: 1.9\n function overloading and default parameter vals: "<<endl;
        Rect rect(0,5,5,0);//creating a Rect obj
        cout<<"initial rectangle coordinates:\nLeft:"<<rect.getLeft()<<", Right: "<<rect.getRight()<<", Top: "<<rect.getTop()<<", Bottom: "<<rect.get_bottom()<<endl;

        //inflate the rectangle
        rect.inflate(2);//inflate uniformly
        rect.inflate(3,1);//inflate dw and dh separately
        rect.inflate(1,2,3,4);//inflate each side differently

        //moving the rectangle
        rect.move(3,2);
        rect.move(5);//move only in x direction by 5

        cout<<"final rectangle coordinates:\nLeft:"<<rect.getLeft()<<", Right: "<<rect.getRight()<<", Top: "<<rect.getTop()<<", Bottom: "<<rect.get_bottom()<<endl;


    }

    /**
     * Задание 1.10. Передача объектов в функции и из функции. Passing objects to and from functions.
     *
     * Создайте функцию `Rect bounding_rect(Rect r1, Rect r2)`, которая будет
     * возвращать наименьший прямоугольник, в котором находятся прямоугольники
     * `r1` и `r2`.
     *
     * Создайте функцию `void print_rect(Rect &r)`, которая будет печатать
     * прямоугольник на консоль.
     *
     * Какие конструкторы вызываются при выполнении кода в следующем блоке?
     *  * * Create a function `Reset bounding_rect(Rect r1, Rect r2)` that will
     * return the smallest rectangle containing the rectangles.
     * `r1` and `r2'.
     *
     * Create a function `void print_rect(Rect &r)` that will print
     * rectangle on the console.
     *
     * Which constructors are called when executing the code in the next block?
     */

    {
        // TODO: see (with debugger or couts), which constructor are called and document it here
        // and explain why
        Rect r1(1,4,5,2), r2(3,6,7,1);
        Rect r3 = bounding_rect(r1, r2);
        print_rect(r3);
    }

    /**
     * Задание 1.11. Поля объектов и свойства объектов.  Fields of objects and properties of objects.
     *
     * У нашего прямоугольника как сущности есть много свойств помимо координат
     * сторон, например, ширина, длина и площадь. До этого все свойства
     * прямоугольника однозначно отображались в его поля, однако, это не всегда
     * так.
     *
     * Добавьте в класс `Rect` методы `get_width()`, `get_height()` и
     * `get_square()`, возвращающие ширину, высоту и площадь соответственно,
     * при этом не вводя новых полей в класс.
     *
     * Некоторые из свойств могут быть доступны и на запись: добавьте методы
     * `set_width` и `set_height`, которые будут устанавливать ширину и высоту
     * прямоугольника, не меняя координаты точки с минимальными значениями X и
     * Y.
     *
     * Продемонстрируйте ниже работу этих методов.
     * * Our rectangle as an entity has many properties besides coordinates
     * sides, such as width, length, and area. Before that, all properties
     * the rectangle was clearly displayed in its margins, however, this is not always the case
     * So.
     *
     * Add the `get_width()` methods to the `Rect' class`, `get_height()` and
     * `get_square()`, which return width, height, and area, respectively,
     * without introducing new fields to the class.
     *
     * Some of the properties may also be writable: add methods
     * 'set_width` and `set_height', which will set the width and height
     * of the rectangle without changing the coordinates of the point with the minimum values of X and
     * Y.
     *
     * Demonstrate how these methods work below.
     */
    //initial rectangle properties: 
    //width: 5, Height: 5, area: 25
    //width updated to 10
    //height updated to 13
    //final rectangle properties: 
    //width: 10, Height: 13, area: 130
    {
        cout<<"tasK : 1.11"<<endl;
        Rect rect(2,7,8,3);

        cout<<"initial rectangle properties: \nwidth: "<<rect.get_width()<<", Height: "<<rect.get_height()<<", area: "<<rect.get_square()<<endl;

        rect.set_width(10);
        rect.set_heigth(13);

        cout<<"final rectangle properties: \nwidth: "<<rect.get_width()<<", Height: "<<rect.get_height()<<", area: "<<rect.get_square()<<endl;


    }

    /**
     * Задание 2. Случаи применения объектов.   Use cases of objects. 
     *
     * Объект в языке С++ - инструмент широкого назначения, который может
     * использоваться в самых разных сценариях. Когда эти сценарии смешиваются,
     * это может привести к путанице и логическим ошибкам. В этом задании мы
     * обрисуем *некоторые* сценарии использования объектов.
     * An object in C++ is a general-purpose tool that can
     * can be used in a wide variety of scenarios. When do these scenarios mix?,
     * This can lead to confusion and logical errors. In this assignment, we
     * let's outline *some* scenarios for using objects.
     */

    /**
     * Задание 2.1. Объект как сущность предметной области. The object as the essence of the subject area.
     *
     * При решении задач из реального мира часто используют объекты для
     * моделирования в программе объектов из предметной области. В методах этих
     * объектов содержится логика, отражающая то, как программист моделирует
     * различные действия и отношения с объектами предметной области.
     * When solving problems from the real world, objects are often used for
     * modeling objects from the subject area in the program. In the methods of these
     * objects contain logic that reflects how the programmer models
     * various actions and relationships with the objects of the subject area.
     *
     * Реализуйте класс `Barrel` в файлах `barrel.hpp` и `barrel.cpp`, который
     * реализует сущность бочки в следующей задаче.
     * Implement the `Barrel' class in the `barrel.hpp` and `barrel.cpp `, which
     * implements the essence of the barrel in the following task.
     *
     * Даны две бочки известного объема. В одной бочке в начальный момент
     * времени содержится спирт (96%), в другой – вода. Кружкой емкостью 1л
     * переливаем итеративно содержимое из одной бочки в другую следующим
     * способом: на каждой итерации зачерпнули из первой бочки -> вылили во
     * вторую зачерпнули из второй бочки -> вылили в первую. Требуется
     * определить номер итерации, на которой концентрация спирта в первой бочке
     * станет меньше 50%.
     * Two barrels of known volume are given. In one barrel at the initial moment
     * one contains alcohol (96%), the other contains water. Using a 1L
     * mug, we iteratively pour the contents from one barrel into another as follows
     * method: at each iteration, it was scooped out of the first barrel -> poured into
     * the second one was scooped out of the second barrel -> poured into the first one. Is required
     * determine the iteration number at which the alcohol concentration in the first barrel is
     * it will be less than 50%.
     * 
     *
     * Реализуйте в классе методы, которые позволят псевдокоду в следующем
     * блоке превратиться в настоящий код и решить задачу.
     * Implement methods in the class that will allow the pseudocode in the following
     * You can turn into real code and solve the problem.
     */

    //summing up the problem: 1. we have two barrels
    //i. one contains 96%  alc
    //ii. the other constains water with 0 alc
    //iii. A 1L mug is used to iteratively transfer liq back and forth
    //we have to find: the interation number when the alcohol concentration in the first barrel drops below 50%


    {
        Barrel alch(10,96); // бочка со спиртом 10L barrel with 96% alc
        Barrel water(10,0);// 10L barrel with pure water

        double mug_size = 1.0;//1L mug
        int iteration = 0;

        while(alch.getAlcoholCeoncentration() > 50.0){
            iteration++;
            
            alch.transferFrom(water, mug_size);
            
            water.transferFrom(alch, mug_size);

            cout<<"iteration "<<iteration<<": alc concentration = "<<alch.getAlcoholCeoncentration()<<"% "<<endl;

        }
    cout<<"alc concentration dropped below 50% on iteration :"<<iteration<<endl;
    }


    /**
     * Задание 2.2. Объект как математическая сущность.  An object as a mathematical entity.
     *
     * Часто с помощью объектов реализуют математические сущности и операции с
     * ними, потому что обычно все действия с ними хорошо определены и известны
     * заранее.
     *
     * Реализуйте класс `Matrix` в файлах `matrix.hpp` и `matrix.cpp`, используя
     * код из лабораторной работы №5 прошлого семестра.
     *
     * Реализуйте следующие конструкторы:
     * - `Matrix(int n)` - инициализирует единичную матрицу размера n x n;
     * - `Matrix(int m, int n, double fill_value = 0)` - инициализирует матрицу 
     *   размера m x n, где все элементы будут равны `fill_value`;
     * - конструктор копирования.
     *
     * Реализуйте деструктор и следующие методы:
     * - `double get(int i, int j)` - получить значение элемента;
     * - `void set(int i, int j, double value)` - установить значение элемента;
     * - `int get_height()` и `int get_width()` - получить высоту и ширину
     *   соответственно;
     * - `void negate()` - операция `-A` для матрицы;
     * - `void add_in_place(Matrix &other)` - операция `this += other` для
     *   матрицы;
     * - `Matrix multiply(Matrix &other)` - возвращает результат матричного
     *   умножения.
     *
     * В случае несовместимых размеров матрицы выкиньте исключение с помощью
     * оператора `throw` (подробнее о нем мы будем говорить позже).
     *
     * Реализуйте ниже вычисление чисел Фибоначчи матричным способом с помощью
     * вашего класса, как это было сделано в прошлом семестре.
     * 
     *
     * Objects are often used to implement mathematical entities and operations with
     * them, because usually all actions with them are well defined and known
     * In advance.
     *
     * Implement the `Matrix' class in the `matrix.hpp` and `matrix.cpp `, using
     * The code from last semester's lab work No. 5.
     *
     * Implement the following constructors:
     * - `Matrix(int n)` - initializes a unit matrix of size n x n;
     * - `Matrix(int m, int n, double fill_value = 0)` - initializes the matrix 
     * of size m x n, where all elements will be equal to `fill_value`;
     * - copy constructor.
     *
     * Implement the destructor and the following methods:
     * - `double get(int i, int j)` - get the value of the element;
     * - `void set(int i, int j, double value)` - set the value of the element;
     * - `int get_height()` and `int get_width()` - get height and width
     * accordingly;
     * - `void negate()' - operation `-A` for the matrix;
     * - `void add_in_place(Matrix &other)' - operation `this += other' for
     * Matrices;
     * - `Matrix multiply(Matrix &other)` - returns the result of a matrix
     * multiplications.
     *
     * In case of incompatible matrix sizes, throw an exception using
     * the `throw` operator (we'll talk about it in more detail later).
     *
     * Implement below the calculation of Fibonacci numbers in a matrix way using
     * your class, as it was done last semester.
     */
    //summing up: Matrix class in matrix.hpp and matrix.cpp
    //features: constructors, getter and setter, matrix operations, exception handling, fibonacci calculation

   {
        cout<<"task: 2.2"<<endl;
        Matrix A(3,3,3);
        Matrix B(3,3,6);

        cout<<"matrix A: "<<endl;
        A.print();

        cout<<"matrix B: "<<endl;
        B.print();

        A.add_in_place(B);
        cout<<"A after A += B : "<<endl;
        A.print();

        Matrix C = A.multiply(B);
        cout<<"matrix C: "<<endl;
        C.print();

        //calculation of fibo nubmers
        int n=10;
        cout<<"fibonacci ("<<n<<")using method: ";
        fibonacci(n);
        

    }

    /**
     * Задание 2.3. Объект - обладатель ресурса. The object is the owner of the resource.
     *
     * Ресурсами - динамической памятью, файлами, сетевыми соединениями - нужно
     * управлять, как минимум, нужно не забывать их освобождать, когда они
     * больше не нужны. Для этого часто используют отдельные классы, которые
     * реализуют "грязную" работу по управлению ресурсами, а другие классы уже
     * использую их для реализации логики более высокого уровня.
     *
     * Такие объекты "обладают" ресурсом, это означает, что они и только они
     * ответственны за его освобождение. Это, в свою очередь, означает, что эти
     * объекты обязаны освобождать ресурс, когда объект больше не нужен (в
     * деструкторе) или когда им присваивают другой ресурс.
     *
     * В рамках этого задания необходимо реализовать класс строки, который
     * будет отвечать за динамическую память, на которой располагается эта
     * строка. Создайте класс `MyString` в соответствующих файлах.
     *
     * У класса должны быть конструкторы:
     *
     * - по умолчанию - создает "пустую" строку;
     * - с параметром `const char *` - объект выделяет память под копию этой строки.
     *
     * Добавьте следующие методы:
     * - `char get(int i)` - получение i-того элемента строки;
     * - `void set(int i, char c)` - установка i-того элемента строки;
     * - `void set_new_string(const char *str)` - замена текущего содержимого
     *   на новое;
     * - `void print()` - вывод строки на консоль;
     * - `void read_line()` - замена текущего содержимого строки на строку, считанную
     *   с консоли (неопределенного размера).
     *
     * Постарайтесь реализовать эти операции без выделения лишней памяти.
     * Продемонстрируйте ниже использование этого класса.
     *  Resources - dynamic memory, files, network connections - are needed
     * to manage, at a minimum, you need to remember to release them when they
     *are no longer needed. To do this, they often use separate classes that
     * implement the "dirty" work of resource management, while other classes already
     * I use them to implement higher-level logic.
     *
     * Such objects "possess" a resource, which means that they and only they
     * Responsible for his release. This, in turn, means that these
     * objects are required to release the resource when the object is no longer needed (in
     * the destructor) or when they are assigned another resource.
     *
     * As part of this assignment, you need to implement a string class that
     * will be responsible for the dynamic memory on which this memory is located.
     * line. Create a 'myString` class in the appropriate files.
     *
     * A class must have constructors:
     *
     * - by default - creates an "empty" row;
     * - with the `const char *` parameter, the object allocates memory for a copy of this string.
     *
     * Add the following methods:
     * - `char get(int i)` - getting the ith element of the string;
     * - `void set(int i, char c)` - setting the ith element of the string;
     * - `void set_new_string(const char *str)' - replacing the current content
     * to a new one;
     * - `void print()' - line output to the console;
     * - `void read_line()` - replacing the current contents of a line with a line that has been read
     * from the console (of undetermined size).
     *
     * Try to implement these operations without allocating extra memory.
     * Demonstrate the use of this class below.
     
     */

    {
        cout<<"task: 2.3"<<endl;

        MyString s1;//using default constructor
        cout<<"empty string s1: ";
        s1.print();

        MyString s2("it is working");//creating MyString obj with a string
        cout<<"sting s2: ";
        s2.print();

        MyString s3=s2;//createing MySting obj by copying s2
        cout<<"copy string s3: ";
        s3.print();

        s3.set(0, 't');//modifying string s3
        cout<<"modying string s3: ";
        s3.print();

        s1.set_new_string("new string for s1");//setting new string for  s1
        cout<<"new sting s1: ";
        s1.print();

        cout<<"enter a new string for s1: ";
        s1.read_line();
        cout<<"updated string s1: ";
        s1.print();

    }
   

    /**
     * Проверьте, что ваша строка корректно работает в следующих ситуациях.
     */

     {
        MyString s1;
        MyString s2 = s1;
        MyString s3("This is my string");
        MyString s4 = s3;
    } 

    /**
     * Задание 2.4. Объект-алгоритм. The algorithm object.
     *
     * Частой практикой является разделение больших сложных функций на
     * несколько маленьких и простых функций, однако, иногда бывает сложно это
     * сделать, так как код на протяжении всех функции использует много общих
     * переменных. В таких случаях создают класс, полями которого делают эти
     * переменные, а функции становятся методами этого класса.
     * It is common practice to divide large complex functions into
     * several small and simple functions, however, sometimes it can be difficult.
     * do this because the code throughout the function uses many common
     * variables. In such cases, they create a class whose fields make these
     * variables, and the functions become methods of this class.
     *
     * Реализуйте ваш алгоритм переноса текста по словам из лабораторной работы
     * №3 прошлого семестра в виде такого объекта. Полями класса должны
     * являться переменные, которые объявлены вне циклов и используются внутри
     * них. Все логические условия (например, "строка закончилась") или
     * атомарные действия (например, "вывести содержимое буфера строки")
     * реализуйте методами класса.
     *  Implement your text transfer algorithm based on the words from the lab
     * No. 3 of the last semester in the form of such an object. The fields of the class must be
     * be variables that are declared outside of loops and used internally
     * them. Implement all logical conditions (for example, "the string has ended") or
     * atomic actions (for example, "output the contents of the string buffer")
     * using class methods.
     *
     *
     * Примерное использование класса приведено ниже.
     * The approximate usage of the class is given below.
     */

    {
        
        std::cout << "task 2.4" << std::endl;

        int line_width = 40;
        MyString input;
        input.read_line();

        TextWrapper wrapper(input, line_width);
        wrapper.wrapText();       
        wrapper.printWrapped();//display bubble
    }

    /**
     * Задание 3. Сборка проекта, Make-файлы.
     */

    /**
     * Задание 3.1. Создание Make-файла для сборки. Creating a Makefile for Building the Project
     *
     * Для выполнения задания в вашей среде Linux (WSL для Windows) вам
     * понадобится программа `make`. Проверьте, установлена ли она с помощью
     * команды `make --version`, если такой программы нет, установите ее (sudo
     * apt install make).
     * To complete this task in your Linux environment (or WSL if you're using Windows), you will need the make utility.
     * 
     *
     * Создайте файл с названием `Makefile`. В нем вы будете определять цели
     * сборки и необходимые шаги для сборки программы. Например, для сборки
     * отладочной версии вашей программы вам нужно выполнить вызвать программу
     * `g++` с нужными параметрами. Для этого в Makefile'е нужно указать цель и
     * шаги, например:
     * Create a file named Makefile. In it, you will define build targets and the commands needed to compile your program.
     * For example, to build a debug version of your program, you need to call the g++ compiler with the appropriate flags.
I    * n the Makefile, specify a target and the build steps, like this:
     * ```
     * debug.out:
     *     g++ -g -o debug.out main.cpp rect.cpp barrel.cpp matrix.cpp my_string.cpp text_wrapper.cpp
     * ```
     *
     * Обратите внимание, что в Makefile используются символы TAB вместо пробелов.
     *
     * После этого можно запустить сборку командой `make debug.out`, вторым
     * параметром передается имя цели.
     * After that, you can build your program using the command:
     * make debug.out
     * The second argument is the target name from the Makefile.
     */

    /**
     * Задание 3.2. Переиспользование целей. Reusing Targets
     *
     * При определении цели вы можете указать цели, которые необходимо
     * выполнить сначала, а указанные шаги будут выполнены после. Например,
     * определим цель для запуска отладчика с нашей отладочной сборкой:
     * When defining a target in a Makefile, you can specify other targets that need to be built first. 
     * The commands for the current target will be executed after those dependencies are built.
     * ```
     * debug: debug.out
     *     gdb debug.out
     * ```
     *
     * Теперь при выполнении цели `debug` сначала будет выполнена цель
     * `build_debug`, а только потом команда `gdb debug.out`.
     * Make will first execute the debug.out target to build the program (if needed), 
     * and only after that will it run the gdb debug.out command.
     */

    /**
     * Задание 3.3. Структура проекта. Project Structure
     *
     * Хорошей практикой является разделять файлы разного назначения по разным
     * директориям: файлы исходного кода помещаются в папку `src` (source), исполняемые
     * файлы и промежуточные результаты сборки помещаются в папку `build` (или `out`),
     * Makefile обычно находится в корневой директории проекта.
     *
     * Приведите вашу директорию в такой вид и поправьте команду сборки.
     * It is considered good practice to organize files by their purpose into separate folders:
     * Place source code files (e.g., .cpp, .hpp) into a folder named src/ (short for source).

     * Place compiled output files (like executables and .o object files) into a folder named build/ (or sometimes out/).

     * The Makefile typically stays in the root directory of the project.
     */

    /**
     * Задание 3.4. Частичная пересборка. Partial Rebuild
     *
     * Целью использования Make-файлов является частичная пересборка: с помощью
     * этой системы сборки можно перекомпилировать только те файлы, которые
     * изменились с прошлой сборки. Чтобы это работало, нужно чтобы каждый .cpp 
     * файл собирался в отдельный .o файл. Например, определим такое правило для
     * сборки файла `rect.cpp`:
     * The purpose of using Makefiles is to enable partial (incremental) rebuilds: with this build
     * system, you can recompile only those files that have changed since the last build.
     * To make this work, each .cpp file must be compiled into its own .o object file.
     *
     * ```
     * build/rect.o: src/rect.cpp src/rect.hpp
     *     g++ -g -c -o build/rect.o src/rect.cpp
     * ```
     *
     * Цель `build/rect.o` будет выполняться, если файла `build/rect.o` нет или
     * если файлы `src/rect.cpp` и `src/rect.hpp` были изменены после сборки
     * файла `build/rect.o`.
     *
     * Создайте правила для сборки файлов `build/my_string.o`, `build/barrel.o`
     * и `build/text_wrapper.o`. После этого создайте правило для сборки
     * отладочной сборки:
     *
     * ```
     * build/debug.out: build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o src/main.cpp
     *    g++ -g -o build/debug.out src/main.cpp build/rect.o build/my_string.o build/barrel.o build/text_wrapper.o
     * ```
     *
     * Обновите цель `debug`, чтобы она использовала цель `build/debug.out`.
     *
     * Убедитесь в том, что при изменении отдельных файлов программы происходит
     * частичная компиляция только нужных файлов.
     */

    /**
     * Задание 3.5*. Делаем Make-файл удобнее. Making the Makefile More Convenient
     *
     * Ознакомьтесь c документацией к программе `make` [1] (как минимум,
     * прочитайте раздел 2) и воспользуйтесь рекомендованными практиками для
     * того, чтобы сделать ваш Make-файл удобнее. Опишите в комментариях, что
     * вы сделали.
     * Read the documentation for the make utility [1] (at least read Section 2) and apply the
     * recommended best practices to make your Makefile more convenient and maintainable.
     * In your Makefile, add comments explaining what improvements or changes you made.
     *
     * 1: https://www.gnu.org/software/make/manual/html_node/index.html
     */

    /**
     * Задание 3.6. Проверка утечек памяти. Memory Leak Detection
     *
     * Сделайте цель `build/leaks.out`, в которой будет собираться версия
     * программы для проверки утечек памяти, и цель `leaks`, где на вход
     * программе `build/leaks.out` будет подаваться файл с пользовательским
     * вводом для вашей программы.
     * Create a Makefile target named build/leaks.out, which builds a version of your program
     * specifically for checking memory leaks.
     * Also create a target named leaks, where the program build/leaks.out is executed with a
     * file containing simulated user input for your program.
     * 
     */

    /**
     * Задание 4. Автоматическое тестирование программы. Automatic testing of the program.
     *
     * Для проверки правильности работы отдельных частей большой программы
     * часто пишут модульные тесты (unit tests). Эти тесты являются отдельным
     * исполняемым кодом, которые не включается в основную программу, а идет
     * "сбоку". Самым простым вариантом модульного теста является программа,
     * которая делает различные проверки с вашим модулем, после чего возвращает
     * 0, если тест пройден, или не 0, если тест провален.
     * 
     *
     * To check the correct operation of individual parts of a large program
     * unit tests are often written. These tests are separate
     * executable code that is not included in the main program, but is running
     * "sideways". The simplest version of the unit test is the program,
     * which does various checks with your module, and then returns
     * 0 if the test is passed, or not 0 if the test is failed.
     */

    /**
     * Задание 4.1. Проверка простых методов класса Rect. Checking simple methods of the Rect class.
     *
     * Создайте директорию `tests` и файл `tests/test_rect_basic_methods.cpp`.
     * В этом файле создайте функцию `main`, в которой проверьте, что после
     * использования разных конструкторов и метода `set_all` методы `get_left`,
     * `get_right`, `get_bottom` и прочее возвращают правильные результаты.
     *
     * Проверки можно делать с помощью макроса `assert` из файла `cassert`
     * стандартной библиотеки. После всех проверок функция `main` должна
     * возвращать 0.
     *
     * Создайте цель для сборки файла `build/test_rect_basic_methods.out`
     * и проверьте вручную, что все тесты проходятся.
     * 
     * * Create the `tests` directory and the `tests/test_rect_basic_methods.cpp `.
     * In this file, create the `main` function, in which you check that after
     * using different constructors and the 'set_all` method of the 'get_left` method,
     * `get_right`, `get_bottom` and others return the correct results.
     *
     * Checks can be done using the `assert' macro from the `cassert` file
     * The standard library. After all the checks, the `main` function should
     * return 0.
     *
     * * Create a target for building the file `build/test_test_basic_methods.out`
     * and check manually that all tests are passed.
     */

    /**
     * Задание 4.2. Проверка других функций. Checking other functions.
     *
     * Создайте файл `tests/test_rect_properties.cpp`, в котором проверьте, что 
     * методы `get_width`, `get_height`, `get_square`, `set_width` и `set_height`
     * работают, как ожидается.
     *
     * Создайте файл `tests/test_rect_operations.cpp`, в котором проверьте, что 
     * методы `move` и `inflate` работают, как нужно.
     *
     * Создайте файл `tests/test_bounding_rect.cpp`, в котором проверьте на 
     * нескольких случаях, что функция `bounding_rect` работает, как ожидается.
     * Обратите внимание, что пользователь может перепутать "лево" и "право"
     * при вводе, аналогично - "верх" и "низ". Обработайте эту ситуацию и 
     * добавьте тест для проверки этого случая.
     *      *
     * Create a file `tests/test_rect_properties.cpp `, in which check that 
     * methods `get_width`, `get_height`, `get_square`, `set_width` and `set_height`
     * work as expected.
     *
     * Create a file `tests/test_rect_operations.cpp `, in which check that 
     * The `move` and `inflate` methods work as needed.
     *
     * Create a file `tests/test_bounding_rect.cpp `, in which check for 
     * there are several cases where the `bounding_rect` function works as expected.
     * Please note that the user may confuse "left" and "right"
     * when entering, similarly - "top" and "bottom". Handle this situation and 
     * Add a test to verify this case.
     */

    /**
     * Задание 4.3. Запуск всех тестов. Running all tests.
     *
     * Создайте цели для сборки всех тестов из задания 4.1 и 4.2. Создайте цель
     * `test`, в которой будут запускаться все тесты из этих заданий.
     *
     * Проверьте, что все тесты проходятся при помощи команды `make test`.
     * * Create goals for building all the tests from Tasks 4.1 and 4.2. Create a goal
     * `test`, in which all the tests from these tasks will be run.
     *
     * Check that all tests are running using the 'make test` command.
     */

    /**
     * Задание 4.4*. Рефакторинг. Refactoring.
     *
     * Когда код хорошо покрыт тестами, можно попробовать как-то улучшить его
     * внутреннее убранство. Посмотрите внимательно на реализацию класса `Rect`
     * и постарайтесь сделать ее "красивее" - убрать лишние повторения кода,
     * длинные функции и тд. Этот процесс называется *рефакторингом*
     * (переработкой).
     *
     * После каждого изменения убеждайтесь, что тесты все еще проходятся.
     * When the code is well covered by tests, you can try to improve it somehow.
     * Interior decoration. Take a close look at the implementation of the `Rect` class
     * and try to make it "prettier" by removing unnecessary repetitions of the code.,
     * Long functions and so on. This process is called refactoring.*
     * (by recycling).
     *
     * After each change, make sure that the tests are still running.
     */


    /**
     * Задание 5. Сюжетный поворот. Plot twist.
     *
     * Представим, что после раунда обсуждения с коллегами вы решили, что для
     * некоторых целей не очень удобно прямоугольник левой, правой, нижней и верхней
     * границей, а гораздо удобнее хранить координаты левой нижней точки, а также
     * высоту и ширину.
     *
     * Измените реализацию класса `Rect` соответствующим образом, оставляя в
     * комментариях старую реализацию.
     *
     * Убедитесь, что тесты все еще проходятся.
     *
     * Отметьте, какие части программы вам пришлось поменять. Если вы правильно
     * пользовались инкапсуляцией, то все изменения должны были произойти
     * *только* внутри класса, а остальные части программы (в частности,
     * функция `bounding_rect`) должны были остаться без изменений.
     *
     * Если вы провели хороший рефакторинг в задании 4.4, то изменений должно
     * было быть не так много.
     * Imagine that after a round of discussion with colleagues, you decide that for
     * for some purposes, the rectangle of the left, right, bottom and top is not very convenient
     * the border, and it is much more convenient to store the coordinates of the lower left point, as well as
     * Height and width.
     *
     * Change the implementation of the `Rect` class accordingly, leaving in
     * comments on the old implementation.
     *
     * Make sure that the tests are still running.
     *
     * Please indicate which parts of the program you had to change. If you are correct
     * if you used encapsulation, then all the changes should have happened.
     * *only* inside the class, and the rest of the program (in particular,
     * the `bounding_rect` function) should have remained unchanged.
     *
     * If you have done a good refactoring in task 4.4, then there should be changes
     * It shouldn't have been so much.
     */

    return 0;
}
