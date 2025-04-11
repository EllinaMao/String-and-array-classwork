#pragma once
#include <iostream>
using namespace std;

/*
Задание 2.
Создайте класс Array (или используйте ранее созданный вами). Класс Array – это класс динамического массива. Размер массива может быть передан в качестве параметра или задан с помощью вызова функции-члена.

Класс должен позволять заполнять массив значениями, отображать содержимое массива, изменять размер массива, сортировать массив, определять минимальное и максимальное значение.

Класс должен содержать набор конструкторов (конструктор копирования обязателен), деструктор.


*/

class Array {
private:
	int* arr = nullptr;
	size_t size = 0;
	void InputArray(int*& temp) const;

	size_t GetSize() const;
	static int count;
	void SetSize(size_t size);
public:
	Array();
	Array(int size);
	Array(const int* arr_user, size_t size);
	Array(const Array& a);
	~Array();
	void SetArray(const int* arr_user, size_t size);
	void SetUserArray();
	const int* GetArray() const;
	void Output() const;
	static int Count();
	static void OutputCount();
	int Min() const;
	int Max() const;
	void Sort();
};

