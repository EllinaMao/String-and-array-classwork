#include "array.h"

int Array::count = 0;

Array::Array()
{
	size = 0;
	arr = nullptr;
	count++;
}

Array::Array(int size1)
{
	if (size1 > 0) {
		size = size1;
		arr = new int[size];
		for (size_t i = 0; i < size; i++) {
			arr[i] = 0;
		}
	}
	else {
		cout << "Array is too short" << endl;
	}
	count++;
}

Array::Array(const int* arr_user, size_t size1)
{
	if (size1 > 0) {
		size = size1;
		arr = new int[size];
		for (size_t i = 0; i < size; i++) {
			arr[i] = arr_user[i];
		}
	}
	else {
		cout << "Array is too short" << endl;
	}
	count++;
}

Array::Array(const Array& a)
{
	cout << "Copy constuct" << endl;
	size = a.size;
	arr = new int[size];
	for (size_t i = 0; i < size; i++) {
		arr[i] = a.arr[i];
	}
	count++;
}
void Array::InputArray(int*& temp) const
{
	if (temp) {
		delete[] temp;
	}
	size_t tempsize = GetSize();
	int* sourse = new int[tempsize];
	cout << "Enter " << tempsize << " numbers: ";
	for (size_t i = 0; i < tempsize; i++) {
		cin >> sourse[i];
	}
	temp = new int[tempsize];
	for (size_t i = 0; i < tempsize; i++) {
		temp[i] = sourse[i];
	}
	delete[] sourse;
}

void Array::SetArray(const int* arr_user, size_t size1)
{
	if (arr) {
		delete[] arr;
	}
	if (size1 > 0) {
		size = size1;
		arr = new int[size];
		for (size_t i = 0; i < size; i++) {
			arr[i] = arr_user[i];
		}
	}
	else {
		cout << "Array is too short" << endl;
	}
}


const int* Array::GetArray() const
{
	return arr;
}

void Array::Output() const
{
	if (arr) {
		cout << "Array: ";
		for (size_t i = 0; i < size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else {
		cout << "Array is empty" << endl;
	}
}

int Array::Count()
{
	return count;
}
void Array::OutputCount()
{
	cout << "Count of objects: " << count << endl;
}
int Array::Min() const
{
	if (arr) {
		int min = arr[0];
		for (size_t i = 1; i < size; i++) {
			if (arr[i] < min) {
				min = arr[i];
			}
		}
		return min;
	}
	else {
		cout << "Array is empty" << endl;
		return 0;
	}
}

int Array::Max() const
{
	if (arr) {
		int max = arr[0];
		for (size_t i = 1; i > size; i++) {
			if (arr[i] > max) {
				max = arr[i];
			}
		}
		return max;
	}
	else {
		cout << "Array is empty" << endl;
		return 0;
	}
}

void Array::Sort()
{
	if (arr) {
		for (size_t i = 0; i < size - 1; i++) {
			for (size_t j = 0; j < size - i - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	else {
		cout << "Array is empty" << endl;
	}
}

Array::~Array()
{
	if (arr) {
		delete[] arr;
		count--;
	}
}

size_t Array::GetSize() const
{
	size_t size = 0;
	cout << "Enter expected size(its can be bigger, but cant be smaller)" << endl;
	cin >> size;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return size;
}
