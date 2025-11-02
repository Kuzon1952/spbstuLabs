#include <cmath> // математические функции (Mathematical functions)
#include <locale.h>	// функции, устанавливающие национальные кодировки символов (Functions that set national (local) character encodings)
#include <iostream>	// Эта - часть библиотеки STL (Standard Template Library)
#include <limits> // Полезные константы (Usefull constant)
#include <float.h> // limits and const for floating-point types
#include <climits> // limits and const for integer types
#include <bitset>

using namespace std; // Обеспечивает видимость имен STL(Standard Template Library)

#define stop __asm__("nop") // Эта макроподстановка упрощает установку точек останова (This macro substitution simplifies setting breakpoints)
int n;	 // Глобальная переменная. По умолчанию она обнуляется. (Global variable. Automatically initialized to zero)

namespace space	 // В пространстве имен - space (Inside namespace -"space")
{
	int n = 1;	 // Объявлена переменная n
}				 // space определяет область видимости этой переменной (The namespace defines the visibility (scope) of this variable)


int  main()
{
	

	// Выполняя программу по шагам, следите за значениями переменных  и интерпретируйте результат, объясняя себе
	// наблюдаемые значения. Обратите внимание на разную интерпретацию отладчиком  signed и unsigned типов данных.
	char c = 'A'; // 65 'A' 0x41 ASCII
	// В комментарии справа полезно проставить десятичное символьное и шестнадцатиричное 
	// значения переменной после выполнения указанной строки. Вы должны видеть их в окне Autos.
	// g++ -std=c++17 -O0 -g lab1.cpp -o lab1 (debug command)
	// g++ -D_DEBUG -g lab1.cpp -o lab1
	// 

	c = 0x42; // 66 'B' 0x42
	c = -1;	// -1 'я' 0xff
	c = CHAR_BIT; // Размер переменной типа char (<climits> usually 8 bits in a char)
	stop;

	// В комментариях напишите результат, возвращаемый оператором sizeof для
	// переменной типа wchar_t (ее размер)
	wchar_t cw = L'Ф'; // 1060 L'Ф' unicode wide char type for other languages like Russian, Bengali, Chinese, etc.
	size_t ns = sizeof(cw); // 4

	unsigned char uc = 0x41; // A
	uc = 'B'; // 0x42
	uc = -127; // 256 - 127 = 129 8421 1101001  0x81 
	stop;

	int i = 1; 
	i = -1; 
	stop;

	unsigned int ui = 1;
	ui = -1; // 4294967295 0xffffffff

	short s = 0xffff; // -1 65535 but short max is 32767 (short 2 bytes) Здесь compiler генерирует warning. Измените код, чтобы убрать warning
	s = short(0xffff); // -1 c style cast
	s = 1;

	//==== Измените код, чтобы убрать warning
	unsigned short us = 0xffff; // 65535 as unsigned 0 to 65535
	us = 5;

	long l = 0xffffffff; // 4294967295 8 bytes
	l = -128; //  0xffffffffffffff80

	l = FLT_MAX_EXP; // 128 max base 2 in float 	// Все эти константы вы должны найти в файле limits (float.h) и объяснить их смысл по комментариям
	l = DBL_MAX_EXP; // 1024 max base 2 in double

	l = FLT_MANT_DIG; // 24 number of base 2 in float 
	l = DBL_DIG; // 15 decimal degits for precision in dobule

	l = FLT_MANT_DIG; // 24 
	l = DBL_MANT_DIG; // 53

	float f = -12.56f;	 // Здесь warning. Уберите его. Без суффикса f число автоматически double.
	f = -1.e-27f;

	f = FLT_MAX; // 3.40282347e+38
	f = FLT_MIN; // 1.17549435e-38

	double d = 0.1234567890123456789123456789; // 0.12345678901234568 only 15 or 16 digits
	d = -0.123456789012345e+306; // -1.2345678901234499e+305
	d = DBL_MAX; // 1.7976931348623157e+308 max
	d = DBL_MIN; // 2.2250738585072014e-308 min
	d = DBL_EPSILON; // 2.2204460492503131e-16 Самая маленькая разность между двумя пер-ми типа double // -- Самая маленькая разность между двумя пер-ми типа double -- Это наименьшее положительное число ε такое, что: 1.0 + ε ≠ 1.0 //x1 - x2 < E

	uc = ~3; // 255-3=252 (0000 0000 to 1111 1111) Побитовое отрицание
	i = ~0; // -1
	stop;
	// Раннее (при компиляции) или неявное приведение типов данных
	// Объясните те значения, которые вы наблюдаете в окне Autos. Определите порядок выполения присваиваний.
	d = f = i = s = c = 1 / 3; // c=0,s=0,i=0,f=0.0,d=0.0
	c = s = i = f = d = 100 / 3; // d=33.0,f=33.0,i=33,s=33,c=33
	c = s = i = f = d = 10 / 3; // d=3.0,f=3.0,i=3,s=3,c=3
	c = s = i = f = d = 1 / 3.; //  d≈0.3333333333, f≈0.33333334, i=0, s=0, c=0
	// Assignment happens from left to right; int / int = int; 1 / 3. returns double.

	// Пример "небрежного" использования неявного приведения типов.	 Объясните результаты.
	i = 256;
	c = i; // 0 because data loss as it is 0 to 255

	uc = 255;
	unsigned char u = 2, sum = uc + u; // 255 + 2 = 257 mod 256 = 1
	stop;

	// Явное приведение типов	Объясните разницу результатов в строках (3) и (4)
	i = 100;
	f = d = i / 3; // (3) d = 33, f = 33
	f = d = (double)i / 3; // (4) d = 33.333333333333336, f = 33.3333321
	f = d = double(i) / 3; // (4) d = 33.333333333333336, f = 33.3333321
	f = d = static_cast<double>(i) / 3;		// (4) d = 33.333333333333336, f = 33.3333321
	stop;

	// Область действия, область видимости и время существования. В этом фрагменте фигурируют четыре
	//  переменных с одним и тем же именем n.  Одна - глобальная, вторая определена в своем пространстве имен,
	// третья - локальная внутри функции main(), четвертая - локальная внутри блока. 
	//  Обратите внимание, что глобальная переменная и та, что в пространстве имен space - объявлены вне функции main()
	// Определите, к какой из четырех переменных идет обращение, cформулируйте область действия и область видимости
	// каждой переменной. Для выполнения задания рекомендуется пользоваться  закладкой "Watches" или "Locals" окна
	// "Autos". Подсказка: В окно "Watches" можно поместить сразу все переменные (n, ::n, и space::n)
// Scope, visibility, and lifetime. In this fragment, there are four
// variables with the same name n. One is global, the second is defined in its own namespace,
// the third is local inside the main() function, and the fourth is local inside a block.
// Note that the global variable and the one in the namespace space are declared outside the main() function.
// Determine which of the four variables is being accessed, formulate the scope, visibility, 
// and lifetime of each variable. To complete the task, it is recommended to use the “Watches” or “Locals” tab 
// of the “Autos” window. Hint: You can add all variables at once to the Watches window 
// (n, ::n, and space::n).

	n = 100; // global ::n
	space::n = 200; // space ::n
	n++; // global ::n= 101
	int n;	// new local n	//Где живет эта переменная ?
	n = 10; // local n = 10
	::n++; // global ::n 102

	{				//  Начало блока
		int n;	// Эта переменная живет внутри блока
		n = -1;
		n++; // 0
		::n++; // global ::n = 103
		space::n++; // space ::n =201
	}		// Конец блока
	n--; // local n 9
	::n--; // global ::n 102 
	space::n--; // space ::n 200

	// Спецификатор класса памяти - static Выполняя задание по шагам, обратите внимание на  разное поведение
	// переменных nLoc и nStat
	{
	Again:
		int outer;
		for (int i = 0; i < 5; i++)
		{
			static int nStat;  // статическая переменная, инициализируется один раз, без static программа работала бы бесконечно
			{
				int nLoc = 0;  // nLoc - локальная переменная из блока, создается и уничтожается при каждом входе/выходе из блока
				nLoc++; // всегда 1	
				nStat++;  // 1 2 3 4 5 6 7 8 9 10
			}
			outer = nStat;
		}
		if (outer < 10) // 10 < 10 false and exit
			goto Again;
	}
	//nStat = 
	// Перечисления - enum. Обратите внимание на явную и неявную инициализацию констант
	enum RANK
	{
		One, //0 implicit 
		Two,//1
		Three,//2
		Four,//3
		Jack = 6, // explicit
		Queen, // 7
		Ace = Queen + 3, // 10
		Joker = 20
	};
	typedef RANK RANG;

	RANG r = Jack; // 6
	if (r == Jack) // true
		r = Queen; // r = 7

	if (r == Queen) // ture
	{
		// Любой целочисленной переменной можно присвоить enum-переменную 
		int i = r; // i = 7
		r = RANK(i++); //r = RANK(7) = Queen, then i becomes 8	// Обратное преобразование надо указывать явно
		i = r; // i = 7
		r = RANK(++i); // i becomes 8, then r = RANK(8)
		i = r; // i = 8
	}
	RANK rr = Ace; // 10
	stop;
	//	Логический тип bool.	Выполняя задание по шагам, следите за значениями переменной b
	{
		int n = 127;
		bool b = n != 0; // n = true and b = true
		b = n == 0; // n = false and b = false
		b = n > 0; // n = true and b = true
		b = n <= 0; // n = false and b = false
		b = n > 1; // n = true and b = true
        b = -2;
		int num = static_cast<int>(b); // true = 1
		if (b) // if the condition is ture and it is true
			cout << "\n\t My flag is: true" << "   or: " << b << "\n\t Conversion to int: " << num << endl;
		b = n == num; // n = false and b = false
		cout << "\n\t Now the flag is: false" << "   or: " << b; // 0
	}

	//	Модификатор const
	const double pi = acos(-1.); // pi = 3.1416... at runtime
	double space_permiability = 4.e-7 * pi;		//	Магнитная проницаемость пустоты
	const int dozen = 12;
	int var = dozen; // var = 12 copy const allowed

	//	Раскомментируйте следующую строчку и объясните ошибку компиляции (l-value означает left value)
//	dozen = 1; //because of const ; const is not assignable , only initalizable
	//	Директивы условной трансляции. Объясните значение, которое принимает переменная version.
	//	Что нужно сделать для того, чтобы результат был другим?
#define _MSVER311
	const char* version;
#if defined _MSVER400
	version = "version 4.00";
#elif defined _MSVER311
	version = "version 3.11";
#else
	version = "version Unknown";
#endif

	cout << endl << version; // version 3.11
	stop;

	//В окне ClassView или Solution Explorer поставьте фокус на имя проекта дайте команду Project/Properties.
	//	В диалоге Property Pages щелкните на папке Configuration Properties, убедитесь, что в разделе Code Generation
	//	установлена константа компиляции _DEBUG. Создайте директивы препроцессора и код С++, которые
	//	в зависимости от действующей конфигурации проекта (_DEBUG или NDEBUG) выводят соответствующее
	//	сообщение. Измените конфигурацию проекта (в диалоге Property Pages) и проверьте ваш код.
	//	Чтобы изменить конфигурацию пользуйтесь кнопкой Configuration Manager

// In the ClassView or Solution Explorer window, focus on the project name and choose Project → Properties.
// In the Property Pages dialog, click the folder Configuration Properties and make sure that in the
// Code Generation section, the compilation constant _DEBUG is set.
// Create preprocessor directives and C++ code that, depending on the current project configuration
// (_DEBUG or NDEBUG), outputs the corresponding message.
// Change the project configuration (in the Property Pages dialog) and test your code.
// To change the configuration, use the Configuration Manager button.
	#ifdef _DEBUG
    	cout << "Debug configuration is active" << endl;
    	cout << "Debugging features are enabled" << endl;
    #elif defined(NDEBUG)
    	cout << "Release configuration is active" << endl; 
    	cout << "Optimizations are enabled, debugging disabled" << endl;
	#else
    	cout << "Unknown configuration" << endl;
	#endif
	//	Простейшие циклы. Объясните суть происходящего. 
	{
		// Цикл while надо использовать, когда неизвестно количество итераций (повторений) цикла. // The while loop should be used when the number of iterations (repetitions) is unknown.
		cout << "\n\nGradually eat out all the units:\n\n";
		unsigned short us = 0xff;//255 1111 1111
		while (us)// us != 0
		{
			cout << hex << us << endl;
			us &= us - 1; // 11111111 11111110 11111100 11111000 ... 00000000
		}
		cout << hex << us << "\nDone\n";
		// Цикл for надо использовать, когда известно количество итераций и/или есть код подготовки. 
		// Подсказка: odd - нечетое, even - четное.
		// The for loop should be used when the number of iterations is known and/or there is initialization code.
		// Hint: odd – odd number, even – even number.//i & 1

		cout << "\n\nShow even-odd:\n\n";
		for (int i = 0; i < 10; i++)
		{
			if (4 & 3) // 0100 & 0011 = 0
				cout << i << " - odd\n";
			else
				cout << i << " - even\n";
		}
		// для четных чисел (тех у кого 0 на конце) побитовое И i & 1 будет false для нечетных true
		
		// Когда нужно использовать цикл do-while? do-while executes its body at least once, even if the condition is false after the first iteration. 
		// It’s useful for menu-like or input-retry behavior, where we always need to ask the user at least once.
		char c = ' ';
		do
		{
			if (c == 'a')
				cout << "\nAction is a delegate type in C#";
			else if (c == 'b')
				cout << "\nbreak is one of the 'leave' statements in all C-like languages";
			else if (c == 'c')
				cout << "\ncontinue is a 'go on' statement in all C-like languages";
			else if (c == 'd')
				cout << "\ndo-while is a rarely used loop statement in all C-like languages";
			else
				cout << "\nPlease read the rules of this loop";
			cout << "\n\nEnter chars: a, b, c, d (q - to quit):\n\n";
			cin >> c;
			if (c == 'q')
				cout << "\nI am going to leave the loop\n";
		} while (c != 'q');
		stop;
	}
// Здесь показано интерактивное меню, которое должно выполниться хотя бы один раз,
// чтобы показать пользователю варианты и попросить ввести выбор.
// Цикл do-while используется, потому что условие выхода (c != 'q')
// проверяется после выполнения тела цикла.
// Поэтому меню выполнится минимум один раз, и пользователь обязательно его увидит.

	//	Логические условные операторы и циклы. Функция y = f(x) задана графиком
	//	Напишите фрагмент кода, который с шагом 0.1 вычисляет y = f(x)  и выводит в консольное окно значения x и y. 
	//	  y
	//	  | 
	//	 2|__________
	//	  |         /\
	//	  |        /  \
	//	  |       /    \
	//	  |______/      \__________  x
	//	  0      1   2   3
	//	 Реалируйте 2 варианта этого алгоритма:   1. Используйте операторы if	 2. Используйте тернарные операции    ? :

	//	Напишите фрагмент, который с помощью for и switch реализует следующую логику. Если пользователь ввел:
	//	символ 'a',   ваш алгоритм выводит  "Ok" (в кавычках)
	//	символ 'b',   ваш алгоритм выводит  Bell (alert - звуковой сигнал)
	//	символ 'с',   ваш алгоритм выводит  число, которое равно количеству введенных символов
	//	символ 'Esc', ваш алгоритм выводит  "to quit use 'q'"
	//	символ 'q',   ваш алгоритм выводит  "Bye" и выходит из цикла ввода

	//	Побитовые операции:  |, &, ~, ^ и сдвиги >>, <<
	//	Поменяйте местами байты переменной flags и выведите результат в консолное окно unsigned short flags = 0xaabb;
	//	Ваш код

	//	Для вывода в шестнадцатеричном виде используйте  cout <<"\n bits = " << hex << flags;
	//	В переменной unsigned char byte = 0x26; 
        //      - установите в единицу 3-й бит (счет от нуля). Выведите результат.
	//	- инвертируйте два младших бита. Выведите результат. 
        //      - обнулите 4 младших бита. Выведите результат.
	//	cout <<endl << hex << flags << endl<<dec<<flags;    
	cout << "\n\n";
// Logical conditional operators and loops. The function y = f(x) is given by the graph.
// Write a code fragment that, with a step of 0.1, calculates y = f(x)
// and prints the values of x and y to the console window.
//
//      y
//      |
//    2 |__________
//      |         /\
//      |        /  \
//      |       /    \
//      |______/      \__________  x
//      0      1   2   3
//
// Implement two versions of this algorithm:
//   Use if statements
	for (double x = 0; x <= 3.1; x += 0.1){
			double y = 0;
			if (x >= 0 && x <= 1) {
				y = 0;
			} else if( x > 1 && x < 2){
				y = 2*x - 2;
			} else if ( x == 2){
				y = 2;
			} else if ( x > 2 && x < 3){
				y = 6 - (2*x);
			} else if ( x >= 3){
				y = 0;
			}
			cout << "x = " << x << ", y = " << y << endl;
		}
//   Use the ternary operator ? :
	for (double x = 0; x <= 3.1; x += 0.1) {
			double y = (x >= 0 && x <= 1) ? 0 : (x > 1 && x < 2) ? 2*x - 2 : (x == 2) ? 2 : (x > 2 && x < 3) ? 6 - (2*x) : (x >= 3) ? 0 : 0;
			cout << "x = " << x << ", y = " << y << endl;
		}

// Write a fragment that, using for and switch, implements the following logic:
// If the user entered:
//   character 'a'   → your algorithm prints  "Ok" (in quotes)
//   character 'b'   → your algorithm triggers a Bell (alert sound)
//   character 'c'   → your algorithm prints the number equal to the count of entered characters
//   character 'Esc' → your algorithm prints  "to quit use 'q'"
//   character 'q'   → your algorithm prints  "Bye" and exits the input loop
	int count = 0;
	bool shouldExit = false;

	for (char c; !shouldExit; ) {
		cout << "Enter character: ";
		cin >> c;
		count++;
		
		switch(c) {
			case 'a':
				cout << "\"Ok\"" << endl;
				break;
			case 'b':
				cout << '\a' << endl;

				break;
			case 'c':
				cout << "Count: " << count << endl;
				break;
			case 27: // ESC ASCII 27
				cout << "to quit use 'q'" << endl;
				break;
			case 'q':
				cout << "Bye" << endl;
				shouldExit = true;
				break;
			default:
				cout << "Unknown command" << endl;
		}
	}
//	Побитовые операции:  |, &, ~, ^ и сдвиги >>, <<
//	Поменяйте местами байты переменной flags и выведите результат в консолное окно
	
// Bitwise operations:  |, &, ~, ^ and shifts >>, <<
// Swap the bytes of the variable flags and print the result to the console window
     short flags = 0xaabb;

	cout << "Original : 0x" << hex << flags << endl;
    
    unsigned char high_byte = (flags >> 8) & 0x00FF;//0xaa
    unsigned char low_byte = flags & 0xFF;//0xbb
    
    unsigned short swapped_flags = (low_byte << 8) | high_byte;
    
    cout << "Swapped :  0x" << hex << swapped_flags << endl;
//	Для вывода в шестнадцатеричном виде используйте  cout <<"\n bits = " << hex << flags;
//	В переменной unsigned char byte = 0x26; 

	unsigned char byte = 0x26; //0010 0110 //38
	cout << "Original: 0x" << hex << (int)byte << " = " << bitset<8>(byte) << endl;
//  - установите в единицу 3-й бит (счет от нуля). Выведите результат.
    //Set bit #3
    byte = byte | (1 << 3);//0010 0110
	                       //0000 1000
						//=  0010 1110

    cout << "Set bit 3: 0x" << hex << (int)byte << "= " << bitset<8>(byte) << endl;
//	- инвертируйте два младших бита. Выведите результат. 
    //Invert 2 least significant bits
    byte = byte ^ 0x03;//0010 1110
					   //0000 0011
					//=  0010 1101

    cout << "Invert 2 LSBs: 0x" << hex << (int)byte << " = " << bitset<8>(byte) << endl;
//      - обнулите 4 младших бита. Выведите результат.
    //Clear 4 least significant bits
    byte = byte & 0xF0;//0010 1101
					   //1111 0000
					//=  0010 0000
    cout << "Clear 4 LSBs: 0x" << hex << (int)byte << " = " << bitset<8>(byte) << endl;

	cout << endl << hex << flags << endl << dec << flags;


}	// Конец функции main()
