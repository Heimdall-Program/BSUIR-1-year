#include <iostream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int number;
    cin >> number;
    if (number % 2 == 1) cout << "Число " << number << " - нечётное";
        else cout << "Число " << number << " - чётное";
}
