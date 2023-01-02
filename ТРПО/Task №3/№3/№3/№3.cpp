#include <iostream>                
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << " Введите два числа \n";
    int a, b, i, e = 0, f = 0;
    cin >> a >> b;
    for (i = 1; i <= sqrt(a); i++) if (a % i == 0) e++;
    for (i = 1; i <= sqrt(b); i++) if (b % i == 0) f++;
    if (e == 1)  cout << a << " - простое\n";
        else cout << a << " - составное\n";
    if (f == 1)  cout << b << " - простое\n";
        else cout << b << " - составное\n";

    while (a != b)
        if (b > a) b -= a;
        else a -= b;
    
    cout << "НОД = " << a << endl;
    return 0;
}