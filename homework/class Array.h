#pragma once
#include <iostream>
#include <algorithm> 
#include <random> 
using namespace std;
/*
������� 2.
�������� ����� Array (��� ����������� ����� ��������� ����). ����� Array � ��� ����� ������������� �������. ������ ������� ����� ���� ������� � �������� ��������� ��� ����� � ������� ������ �������-�����.

����� ������ ��������� ��������� ������ ����������, ���������� ���������� �������, �������� ������ �������, ����������� ������, ���������� ����������� � ������������ ��������.

����� ������ ��������� ����� ������������� (����������� ����������� ����������), ����������.
*
�������� � ��� ������������ ����� Array ����������� ��������.
����������: 
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

    // ������� ��� ���������� ������� ����������
    void FillRandomArray(int min, int max);

    // ������� ��� ����������� ����������� �������
    void Output() const;

    // ������� ��� ��������� ������� �������
    void Resize(size_t newSize);

    // ������� ��� ���������� �������
    void SortArray();

    // ������� ��� ����������� ������������ ��������
    int Min() const;

    // ������� ��� ����������� ������������� ��������
    int Max() const;

    // ������ ��� ��������� ������� �������
    size_t GetSize() const {
        return size_t();
    }

    // ������ ��� ��������� ������� �������
    void SetSize(size_t newSize);

    // ������ ��� ��������� �������� �������� ������� �� �������
    int GetElement(size_t index) const;

    // ������ ��� ��������� �������� �������� ������� �� �������
    void SetElement(size_t index, int value);



    static int GetCount() {return count;}

    static void OutputCount();
};

void QuickSort(int* arr, size_t left, size_t right);