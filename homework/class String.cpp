#include "class String.h"


int String::count = 0;

void String::InputStr(char*& temp)
{
	if (temp) {
		delete[] temp;
	}

	short tempsize = 50;
	char* sourse = new char[tempsize];

	cin.getline(sourse, tempsize);
	if (cin.fail()) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	size_t size = strlen(sourse) + 1;
	temp = new char[size];
	strcpy_s(temp, size, sourse);

	delete[] sourse;

}
String::String()
{
	str = new char[80] {"Unknown"};
	count++;
}

String::String(int size)
{
	if (size > 0) {
	str = new char[size] {};
	count++;
	}
	else {
		cout << "String is too short" << endl;
	}
}

String::String(const char* str_user)
{
	size_t size = strlen(str_user) + 1;
	str = new char[size];
	strcpy_s(str,size, str_user);
	count++;
}


String::String(String& a)
{
	cout << "Copy constuct" << endl;
	size_t size = strlen(a.str) + 1;
	str = new char[size];
	for (int i = 0; i < size; i++) {
		str[i] = a.str[i];
	}
	count++;
}

String::~String()
{
	if (str) {
		delete[] str;
		count--;
	}
}

void String::SetStr(const char* str_user)
{
	if (str) {
		delete[] str;
	}

	size_t size = strlen(str_user) + 1;
	str = new char[size];
	strcpy_s(str,size,str_user);

}

void String::SetUserStr()
{
    if (str) {
        delete[] str;
    }

    char* temp = nullptr;
    InputStr(temp);
    str = temp;
}

const char* String::GetStr() const
{
	return str;
}

void String::Output() const {
	if (str) {
		cout << str << endl;
	}
	else {
		cout << "Cant show empty str" << endl;
	}
}


int String::Count()
{
	return count;
}

void String::OutputCount()
{
	cout << "Count: " << count << endl;
}
