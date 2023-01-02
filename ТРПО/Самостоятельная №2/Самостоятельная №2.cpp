#include <iostream>
#include <time.h>
#include <iomanip>
#include <conio.h>
using namespace std;

void task1();
void task2();
void task3();
void task4();
void task5();

int* generateAndPrintArray(int);
void findNumber(int*, int);
void differensOfTwo(int*, int);
int* littleGenerateAndPrintArray(int);
void maxSequence(int*, int);
int** generateMatrix(int**, int);
void printMatrix(int**, int);
int** MainTransposition(int**, int);
int** anotherTransposition(int**, int);
int** generateAndPrintMatr(int**, int);
void findMaxDist(int**, int);

void task1()
{
    int n;
    cout << "Введите количество элементов массива\n";
    cin >> n;
    int* arr = generateAndPrintArray(n);
    findNumber(arr, n);
}
void task2()
{
    int n;
    cout << "Введите количество элементов массива\n";
    cin >> n;
    int* arr = generateAndPrintArray(n);
    differensOfTwo(arr, n);

}
void task3()
{
    int n;
    cout << "Введите количество элементов массива\n";
    cin >> n;
    int* arr = littleGenerateAndPrintArray(n);
    maxSequence(arr, n);
}
void task4()
{
    cout << "Введите количество строк/столбцов матрицы\n";
    int n, i;
    cin >> n;
    using ptr = int*;
    ptr* matr = new int* [n];
    for (i = 0; i < n; i++)
        matr[i] = new int[n];
    matr = generateMatrix(matr, n);
    matr = MainTransposition(matr, n);
    matr = anotherTransposition(matr, n);
}
void task5()
{
    int count, i;
    cout << "Введите количество точек\n";
    cin >> count;
    int** matrOfXY = new int* [count];
    for (i = 0; i < count; i++)
        matrOfXY[i] = new int[2];
    matrOfXY = generateAndPrintMatr(matrOfXY, count);
    findMaxDist(matrOfXY, count);
}

int* generateAndPrintArray(int count)
{
    int* arr = new int[count];
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand() % 21 - 10;
        cout << arr[i] << setw(5);
    }
    return arr;
}
void findNumber(int* arr, int n)
{
    int i, number;
    cout << "\nВведите число\n";
    cin >> number;
    for (i = 0; i < n; i++)
        if (arr[i] == number)
        {
            cout << "Первое число равному нему стоит на позиции #" << i + 1;
            return;
        }
    cout << "В массиве данного числа нет\n";

}
void differensOfTwo(int* arr, int n)
{
    cout << "\nВсе числа в массиве, которые меньше разности двух предыдущих: \n";
    for (int i = 2; i < n; i++)
        if (arr[i] < (arr[i - 2] - arr[i - 1])) cout << arr[i] << " ";
}
int* littleGenerateAndPrintArray(int count)
{
    int* arr = new int[count];
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand() % 3 - 1;
        cout << arr[i] << " ";
    }
    return arr;
}
void maxSequence(int* arr, int n)
{
    int i, j, maxKol = 0, kol;
    for (i = 0; i < n; i++)
    {
        kol = 0;
        for (j = i; j < n; j++)
            if (arr[i] == arr[j]) kol++;
            else break;
        if (kol > maxKol) maxKol = kol;
    }
    cout << "\nДлина наибольшей последовательности одинаковых чисел, идущих подряд = " << maxKol;
}
int** generateMatrix(int** matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr[i][j] = rand() % 201 - 100;
    printMatrix(matr, n);
    return matr;
}
void printMatrix(int** matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(5) << matr[i][j];
        cout << endl;
    }
}
int** MainTransposition(int** matr, int n)
{
    cout << "Транспорация по главной диагонали:\n";
    int i, j, save = 0;
    for (i = 0; i < n; i++)
        for (j = i; j < n; j++)
        {
            save = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = save;
        }
    printMatrix(matr, n);
    return matr;
}
int** anotherTransposition(int** matr, int n)
{
    cout << "Транспорация по побочной диагонали:\n";
    int i, j, save;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; ++j)
        {
            save = matr[i][j];
            matr[i][j] = matr[n - j - 1][n - i - 1];
            matr[n - j - 1][n - i - 1] = save;
        }
    printMatrix(matr, n);
    return matr;
}
int** generateAndPrintMatr(int** matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matr[i][j] = rand() % 6 - 2;
            cout << matr[i][j] << setw(5);
        }
        cout << endl;
    }
    return matr;
}
void findMaxDist(int** matr, int n) {
    double distance, max = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
        {
            distance = sqrt(pow(matr[i][0] - matr[j][0], 2) + pow(matr[i][1] - matr[j][1], 2));
            if (max < distance) max = distance;
        }
    cout << "\nМаксимальное расстояние между точками = " << max;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    do
    {
        system("cls");
        cout << "Введите номер задания (1-5)\n";
        int taskNumber;
        cin >> taskNumber;
        switch (taskNumber)
        {
        case 1: task1(); break;
        case 2: task2(); break;
        case 3: task3(); break;
        case 4: task4(); break;
        case 5: task5(); break;
        default: cout << "Нет задания с таким номером\n"; break;
        }
        cout << "\n\nНажмите пробел, если хотите продолжить, иначе любой другой символ\n";
    } while (_getch() == 32);
}

