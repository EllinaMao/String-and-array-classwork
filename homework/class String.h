#pragma once
#include <iostream>
using namespace std;
/*
������� 1.
����������� ����� String, ������� � ���������� ����� �������������� ��� ������ �� ��������. ����� ������ ���������:

����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
�����������, ����������� ��������� ������ ������������� �������;
�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������;
����������� �����������.
����� ������ ��������� ������ ��� ����� ����� � ���������� � ������ ����� �� �����.
*
�������� � ��� ������������ ����� String ����������� ��������.
����������:
+ copy constructor,
+copy =,
+move constructor,
+move =,
+get set,
+ operator+ overload,
+ operator << overload,
+ operator >> overload
*/
class String {
private:
	char* str = nullptr;
	static int count;
	void InputStr(char*& temp) const;
	size_t InputSize() const;

public:
	String();
	String(size_t size);
	String(const char* str_user);
	String(const String& a);
	String(String&& a) noexcept;

	String& operator =(const String& a);
	String& operator =(String&& a) noexcept;
	
	String operator+(const String& s) const;

	friend ostream& operator<<(ostream& os, const String& s);
	friend istream& operator>>(istream& is, String& s);

	~String();


	void SetStr(const char* str_user);
	void SetUserStr();

	const char* GetStr()const;
	size_t GetSize() const {return str ? strlen(str) : 0;}

	void Output()const;
	static int Count();

	static void OutputCount();

};
