#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int number, dv, i;

    cout << "Введите число " << endl;
    cin >> number;
    dv = 0;
    for (i = 0; number > 0; i++)
    {
        dv += (number % 2) * pow(10, i);
        number = number / 2;
    }
    cout << dv << endl;
    return 0;
}