#include <iostream>
using namespace std;

int main()
{
    double a = 1, b = 1, n;
    long long fact = 2;
    setlocale(LC_ALL, "Russian");
    cout << "Введите n\n";
    cin >> n;
    cout << "Первые " << n << " чисел Фибоначчи:\n";
    cout << a << " " << b << " ";
    for (int i = 3; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            a += b;
            cout << a << " ";
        }
        else
        {
            b += a;
            cout << b << " ";
        }
        fact *= i;
    };
    cout << endl << n << "! = " << fact;
}
