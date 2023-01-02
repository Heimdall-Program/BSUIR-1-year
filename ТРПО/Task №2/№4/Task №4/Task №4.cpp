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
    case 12: case 1: case 2: cout << "Зима\n"; break;
    case 3: case 4: case 5: cout << "Весна\n"; break;
    case 6: case 7: case 8: cout << "Лето\n"; break;
    case 9: case 10: case 11: cout << "Осень\n"; break;
    default: cout << "Нет месяца с таким номером";
        break;
    }
    return 0;
}
