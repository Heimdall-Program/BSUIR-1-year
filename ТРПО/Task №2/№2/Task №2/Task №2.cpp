#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    int abc, a, b, c;
    double average;
    cin >> abc;
    if (abc > 99)
    {
        a = abc / 100;
        b = (abc - a * 100) / 10;
        c = abc - a * 100 - b * 10;
        average = (double)(a + b + c) / 3;
        cout << average;
    }
    else
    {
        a = abc / 10;
        b = (abc - a * 10);
        average = (double)(a + b) / 2;
        cout << average;
    }
    return 0;
}