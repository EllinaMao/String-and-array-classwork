#include "class String.h"

//
int String::count = 0;

void String::InputStr(char*& temp) const
{
	if (temp) {
		delete[] temp;
	}

	size_t tempsize = InputSize();
	char* sourse = new char[tempsize];

	cout << "Enter a string: ";
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

size_t String::InputSize() const
{
	size_t size = 0;
	cout << "Enter expected size(its can be bigger, but cant be smaller)" << endl;
	cin >> size;
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return size;
}

String::String()
{
	str = new char[8] {"Unknown"};
	count++;
}

String::String(size_t size) {
	if (size > 0) {
		str = new char[size] {};
	}
	else {
		str = new char[8] {"Unknown"};
		cout << "String is too short" << endl;
	}
	count++;
}


String::String(const char* str_user) {
	size_t size = strlen(str_user) + 1;
	str = new char[size];
	strcpy_s(str, size, str_user);
	count++;
}


String::String(const String& a)
{
	cout << "Copy constuct" << endl;
	size_t size = strlen(a.str) + 1;
	str = new char[size];
	strcpy_s(str, size, a.str);
	count++;
}

String::String(String&& a) noexcept
{
	str = a.str;
	a.str = nullptr;
}

String& String::operator=(const String& a)
{
	if (str) {
		delete[] str;
	}

	cout << "Copy constuct =" << endl;
	size_t size = strlen(a.str) + 1;
	str = new char[size];
	strcpy_s(str, size, a.str);
	count++;
	return *this;
}

String& String::operator=(String&& a) noexcept
{
	if (str) {
		delete[] str;}
	str = a.str;
	a.str = nullptr;
	return *this;
}

String String::operator+(const String& other) const
{
	size_t size1 = this->GetSize();
	size_t size2 = other.GetSize();
	size_t newSize = size1 + size2 + 1; 

	String newStr(newSize);

	// Copy the first string
	if (this->str && size1 > 0) {
		strcpy_s(newStr.str, newSize, this->str);
	}
	else {
		newStr.str[0] = '\0'; 
	}

	// Append the second string
	if (other.str && size2 > 0) {
		strcat_s(newStr.str, newSize, other.str);
	}

	return newStr; 
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



ostream& operator<<(ostream& os, const String& s)
{
	os << s.str << endl;
	return os;
}

istream& operator>>(istream& is, String& s)
{
	if (s.str) {
		delete[] s.str;
	}

	size_t tempsize = s.InputSize();
	char* sourse = new char[tempsize];

	cout << "Enter a string: ";
	is.getline(sourse, tempsize); // ���������� ����� is ������ cin
	if (is.fail()) {
		is.clear();
		is.ignore(numeric_limits<streamsize>::max(), '\n');
	}

	size_t size = strlen(sourse) + 1;
	s.str = new char[size];
	strcpy_s(s.str, size, sourse);

	delete[] sourse;

	return is;
}

