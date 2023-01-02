#include <iostream>
using namespace std;

string toString(int number)
{
    char figure; 
    int code; 
    string str = "";
    while (number > 0)
    {
        code = number % 10;
        number /= 10;
        figure = code + 48;
        str = figure+str;
    }
    return str;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    int number;
        cout << "Введите число\n";
        cin >> number;
        str = toString(abs(number));
        if (number < 0) str = '-' + str;
        cout << "Строка:\n" << str;
    return 0;
}