#include <iostream>
#include "class String.h"  
#include "class Array.h"  

using namespace std;  

int main()  
{    

    String defaultString;
    cout << "Default String: ";
    defaultString.Output();


    String sizedString(10);
    cout << "Sized String (10): ";
    sizedString.Output();


    String userString("Hello, C++!");
    cout << "User-provided String: ";
    userString.Output();


    String copiedString(userString);
    cout << "Copied String: ";
    copiedString.Output();


    defaultString.SetStr("New String Set!");
    cout << "Updated Default String: ";
    defaultString.Output();


    defaultString.SetUserStr();
    cout << "User Input String: ";
    defaultString.Output();


    String movedString = move(userString);
    cout << "Moved String: ";
    movedString.Output();

    String s1("Hello, ");
    String s2("World!");

    String s3 = s1 + s2;

    cout << "Concatenated String: " << s3;

    String::OutputCount();

    ////task 2

    Array arr1(5);
    arr1.FillRandomArray(1, 100);
    cout << "Array 1 (randomly filled): " << arr1 << endl;

    Array arr2(3);
    arr2.FillRandomArray(50, 150);
    cout << "Array 2 (randomly filled): " << arr2 << endl;

    Array arr3 = arr1 + arr2;
    cout << "Array 3 (arr1 + arr2): " << arr3 << endl;


    arr3.Resize(10);
    cout << "Array 3 after resizing to 10: " << arr3 << endl;

    arr3.SortArray();
    cout << "Array 3 after sorting: " << arr3 << endl;

    cout << "Min value in Array 3: " << arr3.Min() << endl;
    cout << "Max value in Array 3: " << arr3.Max() << endl;

    Array arr4(4);
    cin >> arr4;
    cout << "Array 4: " << arr4 << endl;

    Array::OutputCount();


    return 0;  
}

