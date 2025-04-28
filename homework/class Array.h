#pragma once
#include <iostream>
#include <algorithm> 
#include <random> 
using namespace std;
/*
Задание 2.
Создайте класс Array (или используйте ранее созданный вами). Класс Array – это класс динамического массива. Размер массива может быть передан в качестве параметра или задан с помощью вызова функции-члена.

Класс должен позволять заполнять массив значениями, отображать содержимое массива, изменять размер массива, сортировать массив, определять минимальное и максимальное значение.

Класс должен содержать набор конструкторов (конструктор копирования обязателен), деструктор.
*
Добавить в уже существующий класс Array конструктор переноса.
Реалізувати: 
+ copy constructor, 
+ copy =,
+ move constructor,
+ move =, 
+ get set, 
+ operator+ overload, 
operator << overload, 
operator >> overload
*/
class Array {
private:
    int* data; 
    size_t size;
    static int count;

public:
    Array() : data(nullptr), size(0) {}
    Array(size_t size);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array();

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;

    friend Array operator+(const Array& a1, const Array& a2);
    friend ostream& operator<<(ostream& os, const Array& array);
    friend istream& operator>>(istream& is, Array& array);

    // Функция для заполнения массива значениями
    void FillRandomArray(int min, int max);

    // Функция для отображения содержимого массива
    void Output() const;

    // Функция для изменения размера массива
    void Resize(size_t newSize);

    // Функция для сортировки массива
    void SortArray();

    // Функция для определения минимального значения
    int Min() const;

    // Функция для определения максимального значения
    int Max() const;

    // Геттер для получения размера массива
    size_t GetSize() const {
        return size_t();
    }

    // Сеттер для изменения размера массива
    void SetSize(size_t newSize);

    // Геттер для получения значения элемента массива по индексу
    int GetElement(size_t index) const;

    // Сеттер для изменения значения элемента массива по индексу
    void SetElement(size_t index, int value);



    static int GetCount() {return count;}

    static void OutputCount();
};

void QuickSort(int* arr, size_t left, size_t right);