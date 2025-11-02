#ifndef MYSTRING_H
#define MYSTRING_H

class MyString
{
private:
	char* m_pStr;		// Элемент данных класса (адрес строки)
public:
    MyString ();
	MyString (char* s);	// Объявление конструктора
	MyString(const MyString& other);

    ~MyString();		// Объявление деструктора
	
	MyString& operator=(const MyString& other);

	void Copy (char* s);
	char* GetString();	// Объявление метода (accessor)
	int GetLength();	// Объявление метода (длина строки)



};

#endif
