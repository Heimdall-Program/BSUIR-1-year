#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите длину и ширину прямоугольника\n";
    double length, width;
    cin >> length >> width;
    cout << "Периметр прямоугольника = " << 2 * (length + width) << endl;
    cout << "Площадь прямоугольника = " << length * width << endl;
    int i, j;
    for (i = 1; i <= length; i++)
    {
        for (j = 1; j <= width; j++)
            if ((i == 1) || (i == length) || (j == 1) || (j == width)) cout << "*";
            else cout << " ";
        cout << endl;
    }
}