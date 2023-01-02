#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    int month;
    cout << "Введите месяц\n";
    cin >> month;
    switch (month)
    {
    case 1:
        cout << "Январь\n"; break;
    case 2:
        cout << "Февраль\n"; break;
    case 3:
        cout << "Март\n"; break;
    case 4:
        cout << "Апрель\n"; break;
    case 5:
        cout << "Май\n"; break;
    case 6:
        cout << "Июнь\n"; break;
    case 7:
        cout << "Июль\n"; break;
    case 8:
        cout << "Август\n"; break;
    case 9:
        cout << "Сентябрь\n"; break;
    case 10:
        cout << "Октябрь\n"; break;
    case 11:
        cout << "Ноябрь\n"; break;
    case 12:
        cout << "Декабрь\n"; break;
    default:
        break;
    }
    return 0;
}
