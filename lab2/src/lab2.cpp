/**
 * Лабораторная работа №2. Массивы объектов, простое наследование, виртуальные
 * функции, применение наследования.
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
 * 
 * * Laboratory work no.2. Arrays of objects, simple inheritance, virtual
 * functions, application of inheritance.
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
 * the standard library and you need to follow the principles of encapsulation.
 */

#include <iostream>
#include <fstream>
#include <cstring>
#include "mystring.hpp"
#include "basefile.hpp"
#include "base32file.hpp"
#include "rlefile.hpp"
#include "rlefile2.hpp"
#include "base32file2.hpp"

using namespace std;

void write_int(BaseFile &file, int n){
     if(n<0){
          char m = '-';
          file.write(&m, 1);
          n = -n;
     }

     while(n > 0){
          char c = n % 10 + '0';
          file.write(&c, 1);
          n /= 10;
     }
}

void write_int(iFile& file, int x) {
     file.write(&x, sizeof(x));
 }

 void foo(RleFile2 &file) {
     char buf[64];
 
     if (!file.can_read()) {
         std::cerr << "Error: File is not open or cannot be read." << std::endl;
         return;//exit if not open
     }
 
     //read the first 64 bytes
     size_t bytes_read = file.read(buf, sizeof(buf));
     std::cout << "processing first 64 bytes: ";
     for (size_t i = 0; i < bytes_read; ++i) {
         std::cout << buf[i];
     }
 
     //reading the next 64 bytes (continuing from the previous leftover data if necessary)
     bytes_read = file.read(buf, sizeof(buf));
     std::cout << "\nProcessing the rest: ";
     for (size_t i = 0; i < bytes_read; ++i) {
         std::cout << buf[i];//process the rest of the data
     }
 }
 
 
 
 
 
 


 

int main() {
     {
          {

               iFile* innerFile = new RleFile("./data/data.txt", "r"); 
               if (!innerFile) {
                   std::cerr << "failed to open file!" << std::endl;
                   return 1; 
               }
           
               RleFile2 file(innerFile);//wrap 
           
               //call foo to process the file content
               foo(file);
           
               delete innerFile;  // clean up the inner file object
           
               
           }
     }
 
    /**
     * Задание 1. Массивы объектов класса. Arrays of objects of the class.
     */

    /**
     * Задание 1.1. Массив объектов. An array of objects.
     *
     * Объявите и проинициализируйте массив ar из объектов типа MyString.
     * Выведите элементы массива на консоль.
     * * Declare and initialize an ar array of objects of the myString type.
     * Output the array elements to the console.
     */

    {
          cout<<"task: 1.1"<<endl;
         //MyString ar[3] = { MyString("My String"), MyString("is "), MyString("working...") };
         //MyString ar[3] = { "My String", " is ", " working..." };

         MyString ar[5] = { "My String", "is", "working..." };

         for(int i = 0; i < 5 ; i++) {
             ar[i].print();
         }
    }

    /**
     * Замените размер массива с 3 на 5, не меняя список инициализаторов.
     *
     * Чем были инициализированы последние 2 элемента? Какие значения могут
     * стоять в списке инициализаторов - в вашем случае и в общем случае?
     * * Change the size of the array from 3 to 5 without changing the initializer list.
     *
* How were the last 2 elements initialized?
-> The last 2 elements were initialized using the default constructor, resulting in str = nullptr.
    *
* What values can should I be on the initializer list - in your case and in the general case?
-> in my case, the initializer list contains c-stings,which my class handles via a parameterrized constructor.
-> in general case, initializer lists can include objs created using parameterized constructor, default constructor, or copy constructor.
    * 
    */

    /**
     * Задание 1.2. Массив указателей на объекты.
     *
     * Объявите и проинициализируйте массив arPtr из трех указателей на объекты
     * типа MyString. Выведите элементы массива на консоль.
     * * Task 1.2. An array of pointers to objects.
     *
* Declare and initialize an arPtr array of three pointers to objects
     * of the myString type. Print the array elements to the console.
     */
    {
          
          cout<<"\ntask: 1.2"<<endl;
     
          //declare and initialize an array of 3 pointers to MyString objs
          MyString* arPtr[3];

          arPtr[0] = new MyString("My String");
          arPtr[1] = new MyString("is ");
          arPtr[2] = new MyString("working...");
     
   
          for(int i = 0; i < 3 ; i++) {
               arPtr[i]->print();
          }
     
          //delete[] arPtr;
          for(int i = 0; i < 3 ; i++) {
               delete arPtr[i];
          }
    }

    /**
     * Задание 2. Простое наследование. Аргументы конструктора, передаваемые в
     * базовый класс.
     * * Task 2. Simple inheritance. Constructor arguments passed to
     * Base class.
     */

    /**
     * Задание 2.1. Базовый класс.
     *
     * Создайте класс BaseFile, который будет реализовывать работу с файлами с
     * помощью стандартных средств C (cstdio).
     *
     * Класс должен иметь 3 конструктора: первый - конструктор по умолчанию,
     * второй должен принимать путь к файлу и параметры для открытия (как в
     * fopen), третий должен принимать готовый указатель FILE*.
     *
     * Считается, что этот класс *обладает* своим ресурсом - открытым файлом.
     * Что должно быть в дестукторе этого класса?
     *
     * Добавьте следующие методы:
     * - bool is_open() - возвращает true, если файл успешно открыт;
     * - bool can_read() - возвращает true, если из файла можно считать данные;
     * - bool can_write() - возвращает true, если в файл можно записать данные;
     * - size_t write_raw(const void *buf, size_t n_bytes) - записывает
     *   указанное количество байт в файл и возвращает количество байт, которое
     *   удалось записать;
     * - size_t read_raw(void *buf, size_t max_bytes) - читает доступные данные
     *   в буфер, но не более указанного количества и возвращает количество
     *   байт, которое удалось считать;
     * - long tell() - возвращает текущий сдвиг файла (см. функцию ftell);
     * - bool seek(long offset) - устанавливает сдвиг файла (см. функцию fseek)
     *   и возвращает true, если операция успешна.
     *
     * Добавьте также методы `read` и `write`, которые в этом классе будут
     * делать буквально то же, что `read_raw` и `write_raw`, они понадобятся нам
     * позже.
     *
     * Проверьте работу этого класса.
     * * Task 2.1. Base class.
     *
* Create a BaseFile class that will implement working with files from
     * using standard C tools (cstdio).
     *
* A class must have 3 constructors: the first one is the default constructor.,
     * the second one should take the path to the file and the parameters to open it (as in
*fopen), the third one should take the ready FILE pointer*.
     *
* This class is considered to have its own resource, an open file.
     * What should be in the destructor of this class?
->the destructor of the BaseFile class should close the file if it's strill open. If i dont close the file,
->i might lose data or cause memory leaks.
     *
* Add the following methods:
     * - bool is_open() - returns true if the file is successfully opened;
     * - bool can_read() - returns true if data can be read from the file;
     * - bool can_write() - returns true if data can be written to the file;
     * - size_t write_raw(const void *buf, size_t n_bytes) - writes
     * the specified number of bytes in the file and returns the number of bytes that
     * managed to record;
     * - size_t read_raw(void *buf, size_t max_bytes) - reads available data
     * to the buffer, but not more than the specified amount and returns the amount
     * the byte that was counted;
     * - long tell() - returns the current file offset (see ftell function);
     * - bool seek(long offset) - sets the file offset (see the fseek function)
* and returns true if the operation is successful.
     *
* Add also the `read` and `write` methods, which in this class will be
     * do literally the same thing as `read_raw` and `write_raw`, we will need them.
     * later.
     *
* Check the operation of this class.
     */
    {
          cout<<"\ntask: 2.1"<<endl;
         
          BaseFile file("data/task2.1.txt", "w");//creating a BaseFile object and open a file for writing
          
          if(file.is_open()){//checking the file is open or not
              
               const char* message = "i am writing a message...and everything is ok\n";//printing to the console

               size_t bytesWritten = file.write_raw(message, strlen(message));
               if (bytesWritten != strlen(message)) {
                    cout<<"error: not all bytes were written to the file."<<endl;
               }
               
               file.close();
          }
          
          else{//checking the file is open or not
     
               cout<<"file not open for writing"<<endl;
          }
          
          BaseFile readFile("data/task2.1.txt", "r");//creating a BaseFile obj and open a file for reading
          
          if(readFile.is_open()){//checking the file is open or not
               
               char buffer[100];
               
               size_t bytesRead = readFile.read_raw(buffer, sizeof(buffer) - 1);//1 to 99 and last one for '\0'
               if (bytesRead == 0) {
                    cout << "error: no data" << endl;
                }
               
               buffer[bytesRead] = '\0';
               
               cout << "Read from file: " << buffer << endl;
               
               readFile.close();

          }
          
          else{
               cout<<"file not open"<<endl;
          }

          

  

    }

    /**
     * Задание 2.2. Производные классы.
     *
     * Производный класс *наследуется* от базового класса и каким-то образом
     * расширяет его функциональность, при это все еще умея все, что умеет
     * базовый класс.
     *
     * Реализуйте следующие производные классы от класса BaseFile. Производные
     * классы нужно унаследовать так, чтобы пользователю были все еще доступны
     * методы базового класса. Каким образом нужно унаследовать класс для этого?
     * Как еще можно унаследовать класс?
     *
     * Производные классы могут располагаться в том же файле, где и базовый
     * класс.
     *
     * В производных классах добавьте необходимые конструкторы, которые будут
     * вызывать конструктор базового класса.
     *
     * Проверьте работу производных классов.
     * * Task 2.2. Derived classes.
     *
* The derived class *inherits* from the base class and somehow
     * extends its functionality while still being able to do everything it can
     * Base class.
     *
* * Implement the following derived classes from the Base File class. Derivatives
     * classes need to be inherited so that they are still accessible to the user.
     * methods of the base class.\
     *  How do I need to inherit a class for this?
-> class Derived : public BaseFile { ... }; this will allow me the derived class to access all public and protected members
of the base class. it will also allow me to use the base class methods in the derived class.

     * How else can I inherit a class?
-> class Derived : protected BaseFile { ... }; this will allow me to access the base class methods in the derived class,
 but not outside of it.
* Derived classes can be located in the same file as the base class.
     * class.
     *
* In the derived classes, add the necessary constructors that will
     * call the base class constructor.
     *
* Check the operation of the derived classes.
     */

    /**
     * Задание 2.2.1. Base32 кодировщик/декодировщик.
     *
     * Создайте производный класс Base32File, который будет проводить при
     * записи кодировку-декодировку данных, по алгоритму, который вы
     * реализовали в лабораторной работе №4 прошлого семестра.
     *
     * Переопределите методы `read` и `write`, которые будут проводить чтение из
     * файла с декодировкой и запись в файл с кодировкой соответственно.
     *
     * Добавьте возможность пользователю передать в конструктор таблицу
     * кодировки, по умолчанию используется таблица "A..Z1..6".
     * * Task 2.2.1. Base32 encoder/decoder.
     *
     * * Create a derived Base 32 File class that will
encode and decode data using the algorithm that you use when writing
     * implemented in laboratory work No. 4 of the last semester.
     *
* Redefine the `read` and `write` methods that will read from
     * a decoded file and writing to an encoded file, respectively.
     *
* Add the ability for the user to pass a table to the constructor
     * encodings, the default table is "A..Z1..6".
     */
    {
     const char* message = "closing time, every new beginning comes from some other beginning's end....";//message to encode and save
    
     cout<<"original message: " << message << endl;//

     Base32File b32f("data/base32_test.txt", "w");//creating an obj of Base32File to write data to file

     //encode and write to file
     b32f.write(message, strlen(message));
     b32f.close();
     cout<<"encoded and written to file: " << message << endl;

     //display the encoded message
     ifstream file("data/base32_test.txt");
     if(file.is_open()){
          string encoded_data;
          getline(file, encoded_data);
          file.close();
          cout<<"encoded data: " << encoded_data << endl;
     }
     else{
          cout<<"error opening file"<<endl;
     }

     //decode and read from file
     Base32File b32f_read("data/base32_test.txt", "r");     
     char buffer[100];
     b32f_read.read(buffer, sizeof(buffer) - 1);
     b32f_read.close();
     cout<<"decoded data: " << buffer << endl;

     //check
     if(strcmp(message,buffer) == 0){
          cout<<"data is same"<<endl;
     }
     else{
          cout<<"data is not same"<<endl;
     }
}
 
 

    /**
     * Задание 2.2.2. RLE-сжатие.
     *
     * Создайте производный класс RleFile, который будет проводить побайтовое
     * сжатие при помощи алгоримта RLE (для простоты можно реализовать
     * неэффективный алгоритм, где последовательности без повторений отдельно
     * не кодируются).
     *
     * Переопределите методы `read` и `write`, которые будут проводить чтение из
     * файла с извлечением сжатой информации и запись в файл со сжатием
     * соответственно.
     *
     * Проверьте сжатие/извлечение на примере какого-нибудь ASCII-арта,
     * например, котенка из лабораторной №3 прошлого семестра. Посмотрите,
     * получилось ли добиться уменьшения размера хранимых данных.
     * * Task 2.2.2. RLE compression.
     *
* Create a derived RleFile class that performs byte-by-byte
     * * compression using the RLE algorithm (for simplicity, you can implement
     * an inefficient algorithm where sequences without repetitions are separated
     * * not quoted).
     *
* Redefine the `read` and `write` methods that will read from
     * a file with compressed information extraction and writing to a compressed file
     * accordingly.
     *
* Check the compression/extraction using an example of some ASCII art.,
     * for example, a kitten from laboratory No. 3 last semester. Look,
     * has it been possible to reduce the size of the stored data?
->run-length encoding. it has been possible to reduce the size of the strored data but only if the input data contains repeated characters.
->possible: "aaabbbccc" -> "3a3b3c"
     */
     {
          const char* path = "data/rle_text  .txt"; 

   //       const char input[] = "/\\\\_/\\\\  (\n"
    //"               ( ^.^ ) _)\n"
    //"                \\\"/  (\n"
    //"               ( | | )\n"
    //"              (__d b__)\n";
          const char input[] = "aabbbdddassss";

          size_t size = strlen(input);

          //w (compress  )
          RleFile writer(path, "wb");
          writer.write(input, size);

          long compressedSize = writer.tell();//size of the compressed data
          if (compressedSize < 0) {  
               cout << "error: failed to retrieve compressed size." << endl;
               return 1;
          }

          writer.close();

          cout << "Original size: " << size << endl;
          cout << "Compressed size: " << compressedSize << endl;

          //r (decompress)
          char output[1000] = {0};
          RleFile reader(path, "rb");
          reader.read(output, 1000);
          reader.close();

          cout << "Original:      " << input << endl;
          cout << "Decompressed:  " << output << endl;
     }


    /**
     * Задание 2.3. Конструкторы и деструкторы базового и производного классов.
     *
     * Установите отладочную печать в конструкторах и деструкторах каждого
     * класса из этого задания. Создайте локальные объекты производных классов,
     * отметьте, в каком порядке вызываются конструкторы и деструкторы при
     * инициализации и деинициализации этих классов.
     * * Task 2.3. Constructors and destructors of base and derived classes.
     *
* Set the debug seal in the constructors and destructors of each
     * The class from this assignment. Create local objects of derived classes,
     * note the order in which constructors and destructors are called during
initialization and de-initialization of these classes.
     */

    /**
     * Задание 2.4. Ранее связывание.
     *
     * На основе данной заготовки напишите код, который запишет в файл строковое
     * представление целого числа. Вы должны использовать один и тот же код для
     * всех файлов, меняя только имя объекта (bf / b32f / rf), в который идет
     * запись.
     * * Task 2.4. Early binding.
     *
* Based on this blank, write a code that will write a string value to the file.
     * Integer representation. You should use the same code for
     * all files, changing only the name of the object (bf /b32f /rf) that goes to
     * Recording.
     */

     {
          BaseFile bf("data/basefile_test.txt", "w");
          Base32File b32f("data/base32file_test.txt", "w");
          RleFile rf("data/rlefile_test.txt", "w");

          int n = 123456;//basefile
          if (n < 0) { 
               char m = '-';
               bf.write(&m, 1);
               n = -n;
          }
          while (n > 0) {
               char digit = n % 10 + '0';
               bf.write(&digit, 1);
               n /= 10;
          }

          n = 123456;
          if (n < 0) { 
               char m = '-';
               b32f.write(&m, 1);
               n = -n;
          }
          while (n > 0) {
               char digit = n % 10 + '0';
               b32f.write(&digit, 1);
               n /= 10;
          }

          n = 123456;
          if (n < 0) { 
               char m = '-';
               rf.write(&m, 1);
               n = -n;
          }
          while (n > 0) {
               char digit = n % 10 + '0';
               rf.write(&digit, 1);
               n /= 10;
          }
    } 

    /**
     * Задание 2.5. Передача объекта по ссылке / указателю.
     *
     * Прошлое задание выглядит странновато - зачем повторять код три раза?
     * Хорошо бы сделать функцию, которая примет объект файла и число, и
     * выполнит эти действия.
     *
     * Реализуйте функцию `write_int(BaseFile &file, int n)`, которая будет
     * принимать ссылку на файл и число, которое нужно будет напечатать.
     *
     * Принцип наследования предписывает, что везде, где можно использовать
     * базовый класс, можно использовать производный класс. Проверьте, можно
     * ли вызвать функцию, передав в нее объект класса Base32File и RleFile.
     *
     * Имеет ли вызов этой функции для производного класса тот же результат,
     * что и код, который вы написали выше? Почему?
     * * Task 2.5. Passing an object by reference / pointer.
     *
* The previous assignment looks a bit strange - why repeat the code three times?
     * It would be nice to make a function that accepts a file object and a number, and
* * perform these actions.
     *
* * Implement the function `write_int(Base File &file, int n)`, which will be
     * accept the link to the file and the number to be printed.
     *
* The principle of inheritance prescribes that wherever it is possible to use
     * base class, you can use a derived class. Check if you can
     * * whether to call the function by passing an object of the Base 32 File and RleFile class to it.
     *
* Does calling this function for a derived class have the same result?,
-> inheritance has used here by the function write_int. calling  the funciton write_int for derived classes may produce different results.
-> if they override the function. without override the funciton write_int, the result will be same as the base class.
     * what about the code you wrote above? Why?
-> produced the same result for all files (bf, b32f, rf) because it called .write() directly on each object. inheritance was not used. as it's not overrdidden in the derived classes, the result is same as the base class.
     */
    {
          cout<<"\ntask: 2.5"<<endl;
          BaseFile bf("data/basefile_test.txt", "w");
          Base32File b32f("data/base32file_test.txt", "w");
          RleFile rf("data/rlefile_test.txt", "w");

          int n = 123456;

          write_int(bf, n);
          write_int(b32f, n);
          write_int(rf, n);

          bf.close();
          b32f.close();       
          rf.close();
          cout<<"written to file"<<endl;

    }


    /**
     * Задание 2.6. Виртуальные функции, позднее связывание.
     *
     * Объявите функции read и write в базовом классе *виртуальными*. Что это
     * означает? Как изменился размер объектов классов BaseFile, Base32File и
     * RleFile? Почему?
     *
     * Как изменилось поведение при вызове функции `write_int` для производных
     * классов? Почему?
     * * Task 2.6. Virtual functions, late binding.
     *
* Declare the read and write functions in the base class *virtual*. What is it means?
->using virtual in a base class means that the derived classes can override the function and provide their 
->own implementation at runtime(late binding). enables runtime polymorphism and allowing to use basefile ref to call overridden methods in derived classes.
     *  How has the size of the BaseFile, Base32File, and  RleFile class objects changed? Why?
->the size of the objects has increased because a vtable pointer is added to each object to support virtual functions.
     *
* How the behavior changed when calling the function `write_int' for derivatives Classes? Why?
->the behavior of  write_int() has changed because it now use late binding(runtime polymorphism). this change happens because of the vtable ptr.
->which ensures teh correct method is called depending on the objs real type at runtime.
     */

    /**
     * Задание 2.7. Виртуальный деструктор.
     *
     * В следующем блоке кода добавьте удаление динамической памяти.
     *
     * Какой деструктор при этом вызывается? Почему? К каким проблемам это может
     * привести?
     *
     * Исправьте эту ситуацию.
     * * Task 2.7. Virtual destructor.
     *
     * In the next block of code, add dynamic memory deletion.
     *
     * Which destructor is called in this case?why?
->only basefile destructor is called. because the derived class destructors are not virtual.
->after fixing:both the base class and derived class destructors are called. 
     * Why?
->because the basefile class defines its destructor as virtual. then, drived class destructors called first then base class destructor.
     * What problems can this lead to?
->memory leads, resource leads, and undefined behavior
     * 
     *
     * Fix this situation.
     */

     {
          cout<<"task 2.7"<<endl;
          BaseFile *files[] = { //pointer arr: pointing to the first element of the array
              new BaseFile("data/basefile_test.txt", "w"), 
              new RleFile("data/rlefile_test.txt", "w"), 
              new Base32File("data/base32file_test.txt", "w") 
          };

          for (int i = 0; i < 3; ++i) {
              files[i]->write("Hello!", 6);
          }

          for (int i = 0; i < 3; ++i) {
              delete files[i];//deleting the objects
          }
    } 

    /**
     * Задание 2.8. Массив объектов производных классов.
     *
     * Раскомментируйте следующий блок и объясните, почему:
     * а) не возникает ошибок при компиляции;
     * б) возникают ошибки при выполнении.
     *
     * Этот пример показывает очень плохую практику, которая приводит к ошибкам;
     * для создания массива объектов производного класса и используйте массив
     * указателей на базовый класс, как это было сделано выше. Реализуйте ту же
     * логику, используя массив указателей на объекты базового класса.
     * * Task 2.8. An array of objects of derived classes.
     
* * Comment on the following block and explain why:
     * a) no compilation errors occur;
->auto implicit upcasting a base32file can be treated as a basefile. arr like new base32file[2] return a ptr to the first element 
->of the arr and assignning this to a basefile is legal.
     * b) errors occur during execution.
->although the code compoiles, it leads to undefined behavior becasue at runtime due to the inccorrect memory deletion.
     * This example shows a very bad practice that leads to errors.;
     * to create an array of objects of a derived class and use an array
     * pointers to the base class, as described above. Implement the same
     * logic using an array of pointers to objects of the base class.
     */

    {
         //BaseFile *base_files = new BaseFile[2] { BaseFile("base1.txt","w"), BaseFile("base2.txt","w") };
         //BaseFile *b32_files = new Base32File[2] { Base32File("base32file1.txt","w"), Base32File("base32file2.txt","w") };
         BaseFile *base_files[2] = { new BaseFile("data/base1.txt","w"), new BaseFile("data/base2.txt","w") };
         BaseFile *b32_files[2] = { new Base32File("data/base32file1.txt","w"), new Base32File("data/base32file2.txt","w") };

         //for (int i = 0; i < 2; ++i) {
           //  base_files[i].write("Hello!", 6);
           //  b32_files[i].write("Hello!", 6);
         //}
         for(int i = 0; i < 2; ++i) {
             base_files[i]->write("Hello!", 6);
             b32_files[i]->write("Hello!", 6);
         }
         //delete [] base_files;
         //delete [] b32_files;
         for(int i = 0; i < 2; ++i) {
             delete base_files[i];
             delete b32_files[i];
         }
    }  

    /**
     * Задание 3. Чисто виртуальные функции. Интерфейсы. Композиция классов.
     *
     * Наследование позволяет довольно просто переиспользовать данные и логику
     * других классов, однако зачастую этот механизм недостаточно гибкий для
     * полноценного переиспользования.
     *
     * Например, сможем ли мы в получившейся иерархии классов реализовать
     * одновременно и кодирование в base32, и сжатие при записи данных в файл?
     * Или сможем ли мы вместо записи в файл на диске делать запись в строковый
     * буфер в памяти?
     *
     * При дальнейшем рассмотрении окажется, что при помощи наследования мы
     * крепко *связали* логику преобразования данных с записью в конкретный
     * файл. Далее мы рассмотрим один из способов разделения такой логики.
     * * Task 3. Purely virtual functions. Interfaces. Composition of classes.
     *
* Inheritance makes it quite easy to reuse data and logic.
     * other classes, but often this mechanism is not flexible enough for
     * full-fledged reuse.
     *
* For example, will we be able to implement in the resulting class hierarchy
     * both base32 encoding and compression when writing data to a file?
->nope! we cannot implement both base32 encoding and compression in the same class hierarchy. because inheritance creates a tight and rigid structure.
->To combine multiple features like encoding and compression, we would need to create a separate class 
->for every possible combination, which is inefficient and unscalable.
     * Or can we write to a string format instead of writing to a file on disk?
->nope! with the current inheritance-based design, we cannot easily write to a string format. 
->The base class (`BaseFile`) is tightly coupled with file operations using FILE pointers, 
->making it impossible to redirect the output to a string without creating a completely separate class.
     * a buffer in memory?
->since the logic is built around file streams (`FILE*`), we cannot directly support writing to 
->an in-memory buffer. To support different output targets like memory buffers or network streams, 
->we need to decouple the logic using interfaces and composition instead of inheritance.
     * Upon further examination, it turns out that with the help of inheritance, we
     * tightly * linked* the logic of data conversion to a record in a specific
     * file. Next, we will look at one of the ways to separate such logic.
     */

    /**
     * Задание 3.1. Абстрактный базовый класс, чисто виртуальные функции.
     *
     * Первая проблема в нашей реализации - все наследники BaseFile будут всегда
     * обязаны непосредственно писать в файл на диске. Чтобы избавиться от этой
     * необходимости, стоит сделать базовый класс *абстрактным* в том смысле,
     * что у него не будет полей связанных с конкретным способом писать в файл.
     *
     * Создайте класс `IFile`, в котором не будет полей, но будут методы
     * `can_read`, `can_write`, `read` и `write` с такими же сигнатурами, как и
     * классе `BaseFile`. Что именно будут делать эти методы? Класс `IFile` не
     * может знать, поскольку логику этих методов будут определять наследники.
     * В этом классе эти методы не имеют реализации, и они должны быть объявлены
     * *чисто виртуальными*.
     *
     * Какие ограничения накладывает на класс наличие чисто виртуального метода?
     *
     * Получается, что в классе `IFile` есть только чисто виртуальные методы, и
     * единственная цель такого класса - определять, что должны уметь делать его
     * наследники. Совокупность действий, которые можно сделать с объектом,
     * называется его *интерфейсом*, и такие классы тоже часто называются
     * интерфейсами, отсюда берется приставка "I" в имени класса.
     *
     * Унаследуйте класс `BaseFile` от класса `IFile` и измените функцию
     * `write_int`, чтобы она работала с произвольным наследником `IFile`.
     *
     * Убедитесь, что в программе выше ничего не сломалось.
     * * Task 3.1. Abstract base class, purely virtual functions.
     *
* The first problem in our implementation is that all BaseFile heirs will always be there
     * must write directly to the file on the disk. To get rid of this
     * if necessary, it is worth making the base class *abstract* in the sense of,
     * that it won't have fields related to a specific way to write to a file.
     *
* Create an `iFile` class with no fields, but methods.
     * `can_read`, `can_write', `read` and `write' with the same signatures as
     * the `BaseFile' class. What exactly will these methods do? The `iFile' class is not
     * may know, because the logic of these methods will be determined by the heirs.
     * In this class, these methods have no implementation, and they must be declared
     * * purely virtual*.
     *
     * What restrictions does the presence of a purely virtual method impose on the class?
->A class with a purely virtual method cannot be instantiated. i can only create objects of derived classes that implement the pure virtual method.

* It turns out that the `iFile` class has only purely virtual methods, and
* the only purpose of such a class is to determine what it should be able to do.
     * heirs. A set of actions that can be done with an object,
     * is called its *interface*, and such classes are also often called
     * interfaces, hence the prefix "I" in the class name.
     *
* Inherit the `BaseFile` class from the `iFile` class and change the function
     * `write_int', so that it works with an arbitrary descendant of `iFile'.
     *
* Make sure that nothing is broken in the program above.
     */
    {
          cout<<"\ntask: 3.1"<<endl;
          BaseFile bf("data/basefile_test.txt", "w");
          Base32File b32f("data/base32file_test.txt", "w");
          RleFile rf("data/rlefile_test.txt", "w");

          int n = 123456;

          write_int(bf, n);
          write_int(b32f, n);
          write_int(rf, n);

          bf.close();
          b32f.close();       
          rf.close();
          cout<<"written to file"<<endl;
      
     }

    /**
     * Задание 3.2. Композиция вместо наследования.
     *
     * Реализуйте классы `Base32File2` и `RleFile2`, которые будут унаследованы
     * от класса `IFile` и в конструкторе будут получать другой объект `IFile`,
     * чьи функции они будут использовать вместо функций базового класса.
     *
     * Объекты получают объект `IFile` в виде указателя на динамически
     * выделенную память, и они ответственны за ее очищение.
     *
     * Использование объектом другого объекта в качестве поля называется
     * *композицией*.
     *
     * Проверьте, что используемые ниже объекты работают так же, как объекты
     * классов `Base32File` и `RleFile`.
     * * Task 3.2. Composition instead of inheritance.
     *
* Implement the classes `Base32File2` and `RleFile2', which will be inherited
     * another `iFile` object will be received from the `iFile` class and in the constructor.,
     * whose functions they will use instead of the functions of the base class.
     *
* Objects receive an `iFile` object as a pointer to dynamically
     * allocated memory, and they are responsible for cleaning it.
     *
* An object's use of another object as a field is called
     * * by composition*.
     *
     * Check that the objects used below work the same as the objects
     * The `Base32File` and `RleFile` classes.
     */

     {
        Base32File2 b32f(new BaseFile("data/b32_comp.txt", "w" ));
        RleFile2 rf(new Base32File("data/rle_comp.txt", "w" ));
        write_int(b32f, 123456);
        write_int(rf, 123456);
     } 

    /**
     * Задание 3.3. Больше композиции!
     *
     * Не реализовывая больше никаких классов, соорудите объект-наследник IFile,
     * который будет при вызове метода `write` два раза кодировать в base32,
     * после чего применять сжатие RLE и только после этого писать в файл.
     * * Task 3.3. More composition!
     *
* Without implementing any more classes, build an iFile inheritor object,
     * which will encode in base32 twice when calling the `write` method,
* then apply RLE compression and only then write to the file.
     */

     {
          cout <<"\ntask: 3.3"<<endl;
      
          iFile* file = new Base32File2(//1st base32 encode
                            new Base32File2(//2nd base32 encode
                                new RleFile2(//rLE compress
                                    new BaseFile("data/task3.3_output.txt", "w")//final output
                                )
                            )
                        );
      
          write_int(*file, 123456);//write through the entire chain
      
          delete file;//cleans up all layers
      
          cout << "written using base32 → base32 → RLE → file" << std::endl;
      }
      

    return 0;
}
