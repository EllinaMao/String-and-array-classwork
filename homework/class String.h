#pragma once
#include <iostream>
using namespace std;
/*
Задание 1.
Разработать класс String, который в дальнейшем будет использоваться для работы со строками. Класс должен содержать:

Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
Конструктор, позволяющий создавать строку произвольного размера;
Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя;
Конструктор копирования.
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.

*/
class String {
private:
	char* str = nullptr;
	static int count;
	void InputStr(char*& temp);


public:
	String();
	String(int size);
	String(const char* str_user);
	String(String& a);
	~String();


	void SetStr(const char* str_user);
	void SetUserStr();

	const char* GetStr()const;

	void Output()const;

	static int Count();

	static void OutputCount();






};
