#include "class Array.h"
int Array::count = 0;

Array::Array(size_t size) : size(size) {
    data = new int[size]();
    count++;
}

Array::Array(const Array& other) : size(other.size) {
    data = new int[size];
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    count++;
}


Array::Array(Array&& other) noexcept : size(other.size) {
   data = other.data;
   other.data = nullptr;
   other.size = 0;
}

Array::~Array()
{
    if (data) {
        delete[] data;
    }
    size = 0;
    count--;
}

Array& Array::operator=(const Array& other) {
    if (this == &other) {
        return *this;
    }
    if (data) {
        delete[] data;
    }
    size = other.size;
    data = new int[size];

    // Copy elements  
    for (size_t i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
    count++;
    return *this;
}

Array& Array::operator=(Array&& other) noexcept
{
    if (this == &other) {
        return *this;
    }
    if (data) {
        delete[] data;
    }

    data = other.data;
    size = other.size;
    other.data = nullptr;
    other.size = 0;
}

void Array::FillRandomArray(int min, int max)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    for (size_t i = 0; i < size; ++i) {
        data[i] = dist(gen);
    }
}

void Array::Output() const
{
    for (size_t i = 0; i < size; ++i) {
        cout << data[i] << " ";
    }
    cout << endl;
}

void Array::Resize(size_t newSize) 
{
    int* newData = new int[newSize]();

    size_t minSize = (newSize < size) ? newSize : size;
    for (size_t i = 0; i < minSize; ++i) {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    size = newSize;
}

void Array::SortArray() {
    QuickSort(data, 0, (size - 1));
}

int Array::Min() const  
{  
   if (!data || size == 0) {  
       return -1;  
   }  

   int minValue = data[0];

    for (size_t i = 1; i < size; ++i) {  
       if (data[i] < minValue) {  
           minValue = data[i];  
       }  
   }  

   return minValue;  
}

int Array::Max() const
{
    if (!data || size == 0) {
        return -1;
    }

    int maxValue = data[0];

    for (size_t i = 1; i < size; ++i) {
        if (data[i] > maxValue) {
            maxValue = data[i];
        }
    }

    return maxValue;
}

void Array::SetSize(size_t newSize)  
{  
   Resize(newSize);  
}

void Array::SetElement(size_t index, int value)
{
    if (!data || index >= size)
    {
        return;
    }
    data[index] = value;
}

void Array::OutputCount()
{
    cout << "Count of arrays is: " << count << endl;
}

int Array::GetElement(size_t index) const  
{  
   if (!data || index >= size) {  
       return 0;
   }  
   return data[index];  
}


Array operator+(const Array& a1, const Array& a2) {
    Array summ(a1.size + a2.size);

    // Копируем элементы из первого массива
    for (size_t i = 0; i < a1.size; ++i) {
        summ.data[i] = a1.data[i];
    }

    // Копируем элементы из второго массива
    for (size_t i = 0; i < a2.size; ++i) {
        summ.data[a1.size + i] = a2.data[i];
    }

    return summ;
}

ostream& operator<<(ostream& os, const Array& array)
{
    os << "[";
    for (size_t i = 0; i < array.size; ++i) {
        os << array.data[i];
        if (i < array.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

istream& operator>>(istream& is, Array& array) {
    cout << "Enter " << array.size << " elements: ";
    for (size_t i = 0; i < array.size; ++i) {
        is >> array.data[i];
    }
    return is;
}

void QuickSort(int* arr, size_t left, size_t right) {
    if (left >= right) return;
    int pivot = arr[(left + right) / 2];

    size_t i = left;
    size_t j = right;

    while (i <= j) {
        while (arr[i] < pivot) ++i;
        while (arr[j] > pivot) --j;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    QuickSort(arr, left, j);
    QuickSort(arr, i, right);
}