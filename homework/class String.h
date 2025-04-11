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

*/
class String {
private:
	char* str = nullptr;
	static int count;
	void InputStr(char*& temp) const;
	size_t GetSize() const;

public:
	String();
	String(int size);
	String(const char* str_user);
	String(const String& a);
	~String();


	void SetStr(const char* str_user);
	void SetUserStr();

	const char* GetStr()const;

	void Output()const;

	static int Count();

	static void OutputCount();






};
