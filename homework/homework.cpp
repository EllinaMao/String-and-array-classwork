#include <iostream>
#include "class String.h"  

/*
������� 1.
����������� ����� String, ������� � ���������� ����� �������������� ��� ������ �� ��������. ����� ������ ���������:

����������� �� ���������, ����������� ������� ������ ������ 80 ��������;
�����������, ����������� ��������� ������ ������������� �������;
�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������;
����������� �����������.
����� ������ ��������� ������ ��� ����� ����� � ���������� � ������ ����� �� �����.
*/
/*
������� 2.
�������� ����� Array (��� ����������� ����� ��������� ����). ����� Array � ��� ����� ������������� �������. ������ ������� ����� ���� ������� � �������� ��������� ��� ����� � ������� ������ �������-�����.

����� ������ ��������� ��������� ������ ����������, ���������� ���������� �������, �������� ������ �������, ����������� ������, ���������� ����������� � ������������ ��������.

����� ������ ��������� ����� ������������� (����������� ����������� ����������), ����������.


*/
using namespace std;  

int main()  
{  
    // Default constructor  
    String defaultString;  
    cout << "Default String: ";  
    defaultString.Output();  

    // Constructor with size  
    String sizedString(100);  
    cout << "Sized String (100): ";  
    sizedString.Output();  

    // Constructor with user-provided string  
    String userString("Hello, C++!");  
    cout << "User-provided String: ";  
    userString.Output();  

    // Copy constructor  
    String copiedString(userString);  
    cout << "Copied String: ";  
    copiedString.Output();  

    // Set a new string  
    defaultString.SetStr("New String Set!");  
    cout << "Updated Default String: ";  
    defaultString.Output();  

    // Input a string from the user  
    cout << "Enter a string: ";  
    defaultString.SetUserStr();  
    cout << "User Input String: ";  
    defaultString.Output();  

    // Output the count of String objects  
    String::OutputCount();  

    return 0;  
}

