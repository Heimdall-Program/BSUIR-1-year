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
        str = figure + str;
    }
    return str;
}
string toString(int number, int repeats)
{
    char figure;
    int degree,leftNumber, code;
    string str = "";
    for (int i = 0; i < repeats; i++)
    {
        leftNumber = number;
        degree = 0;
        while (leftNumber >= 10)
        {
            leftNumber /= 10;
            degree++;
        }
        code = leftNumber;
        number -= pow(10,degree) * leftNumber;
        figure = code + 48;
        str +=figure;
    }
    return str;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    double number;
        int countOfRepeats;
        cout << "Введите число\n";
        cin >> number;
        cout << "Введите количество символов на вывод\n";
        cin >> countOfRepeats;
        int degree = 0, check = abs(number);
        while(check>0)
        {
            if ((check < 100) and (check > 9) and (check % 10 == 0)) degree++;
            check /= 10;
            degree++;
        }
        if (countOfRepeats >= degree) 
        {
            str = toString(number);
        }
        else str = toString(number, countOfRepeats);
        if (number < 0) str = '-' + toString(fabs(number), countOfRepeats);
        cout <<"Строка:\n" << str;
    return 0;
}