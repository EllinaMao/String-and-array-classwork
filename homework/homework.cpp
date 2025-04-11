#include <iostream>
#include "class String.h"  

/*
Задание 1.
Разработать класс String, который в дальнейшем будет использоваться для работы со строками. Класс должен содержать:

Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
Конструктор, позволяющий создавать строку произвольного размера;
Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя;
Конструктор копирования.
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.
*/
/*
Задание 2.
Создайте класс Array (или используйте ранее созданный вами). Класс Array – это класс динамического массива. Размер массива может быть передан в качестве параметра или задан с помощью вызова функции-члена.

Класс должен позволять заполнять массив значениями, отображать содержимое массива, изменять размер массива, сортировать массив, определять минимальное и максимальное значение.

Класс должен содержать набор конструкторов (конструктор копирования обязателен), деструктор.


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

