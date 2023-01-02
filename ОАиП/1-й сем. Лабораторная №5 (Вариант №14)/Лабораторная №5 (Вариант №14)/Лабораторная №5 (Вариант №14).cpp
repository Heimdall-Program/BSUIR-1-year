#include <iostream>
#include <cmath>
#include <time.h>
#include <conio.h>
using namespace std;

double inPut()
{
    int number;
    while (!(cin >> number))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Введите целочисленное значение!\n";
    }
    return number;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    do
    {
        system("cls");
        int choise, n, i, sum = 0;
        cout << "Ввведите количество элементов массива\n";
        n = inPut();
        int* array = new int[n];
        cout << "Введите 0, если хотите вручную ввести элементы,\nВведите 1, если хотите заполнить массив случайными числами\n";
        choise = inPut();
        switch (choise)
        {
        case 0:
            cout << "Введите элементы массива\n";
            for (i = 0; i < n; i++)
                array[i] = inPut();
            break;
        default:
            cout << "Это не 0, и не 1, поэтому массив заполняется случайными числами\n";
        case 1:
            for (i = 0; i < n; i++)
            {
                array[i] = rand() % 4 - 2;
                cout << array[i] << " ";
            }
            break;
        }
        for (i = 0; i < n; i++)
            if (array[i] == 0) break;
        if (i == n)
        {
            cout << "\nВ массиве нет нулей";
            return 1;
        }
        if (i == n - 1)
        {
            cout << "\nНоль - последний элемент массива";
            return 2;
        }
        for (i = i; i < n; i++)
            sum += abs(array[i]);
        cout << "\nСумма модулей элементов после первого 0 = " << sum;
        delete[]array;
        cout << "\nНажмите пробел, если хотите запустить программу заново\n";
    } while (_getch() == 32);
    return 0;
}
