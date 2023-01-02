#include <iostream>
#include <iomanip>
#include "Matr.h"
using namespace std;

int** generateMatrix(int lines, int columns)
{
    int i, j;
    int** matr = new int* [lines];
    for (i = 0; i < lines; i++)
        matr[i] = new int[columns];
    srand(time(0));
    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++)
            matr[i][j] = rand() % 1001 - 500;
    return (matr);
}

void printMatrix(int lines, int columns, int** matr)
{
    int i, j;
    for (i = 0; i < lines; i++)
    {
        for (j = 0; j < columns; j++)
            cout << setw(5) << matr[i][j] << ' ';
            cout << endl;
    }
}

void deleteMatrix(int lines, int** matr)
{
    for (int i = 0; i < lines; i++)
        delete[]matr[i];
    delete[]matr;
}
int summMatrix(int lines, int columns, int** matr)
{
    int i, j, summ = 0;
    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++)
        {
            summ += matr[i][j];
        }
        
    return(summ);
}
int** multiplicateMatrix(int lines, int columns, int secondColumns, int** matr1, int** matr2, int** matr3)
{
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < secondColumns; j++)
            matr3[i][j] = 0;
    for (int i = 0; i < lines; i++)
        for (int j = 0; j < secondColumns; j++)
            for (int t = 0; t < columns; t++)
                matr3[i][j] += matr1[i][t] * matr2[t][j];
    return(matr3);
}

int* generateAndPrintArray(int count)
{
    int* arr = new int[count];
    srand(time(0));
    for (int i = 0; i < count; i++)
    {
        arr[i] = rand() % 1001 - 500;
        cout << arr[i] << " ";
    }
    return(arr);
}

int* sortArray(int* arr, int lot)
{
    int t;
    for (int i = 0; i < lot - 1; i++)
        for (int j = i + 1; j < lot; j++)
            if (arr[i] > arr[j])
            {
                t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
    return (arr);
}

void searchMedian(int* arr, int count)
{
    int i, j, k;
    deleteDuplicates(count, arr);
    arr = sortArray(arr, count);
    cout << endl;
    cout << "Медиана = " << arr[count / 2];
}

void deleteDuplicates(int& count, int* arr)
{
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (arr[i] == arr[j])
            {
                for (int k = j; k < count - 1; k++)
                    arr[k] = arr[k + 1];
                count--;
            }
}
int* matrixToArray(int lines, int columns, int** matr)
{
    int i, j, * arr;
    arr = generateAndPrintArray(columns * lines);
    for (i = 0; i < lines; i++)
        for (j = 0; j < columns; j++)
            arr[i + j] = matr[i][j];
    return (arr);
}

int main()
{
    setlocale(LC_ALL,"Ru");
    cout << "Введите номер задания(1-5)\n";
    int taskNumber;
    cin >> taskNumber;
    switch (taskNumber)
    {
    case 1:
        int  linesCount, columnsCount, ** matrix;
        cout << "Введите количество строк и столбцов\n";
        cin >> linesCount >> columnsCount;
        matrix = generateMatrix(linesCount,columnsCount);
        printMatrix(linesCount, columnsCount, matrix);
        deleteMatrix(linesCount, matrix);
        break;
    case 2:
        int  summ;
        cout << "Введите количество строк и столбцов\n";
        cout << "Для работы с массивом, кол-во строк должно быть равным 1\n";
        cin >> linesCount >> columnsCount;
        matrix = generateMatrix(linesCount, columnsCount);
        printMatrix(linesCount, columnsCount, matrix);
        summ = summMatrix(linesCount, columnsCount, matrix);
        cout << "Сумма = " << summ;
        cout << "\nСреднее значение = " << (double)summ/(linesCount*columnsCount) << endl;
        deleteMatrix(linesCount, matrix);
        break;
    case 3:
        int  secondLinesCount, secondColumnsCount, ** secondMatrix, **finalMatrix;
        cout << "Введите количество строк и столбцов первой матрицы\n";
        cin >> linesCount >> columnsCount;
        matrix = generateMatrix(linesCount, columnsCount);
        printMatrix(linesCount, columnsCount, matrix);
        cout << "Введите количество строк и столбцов второй матрицы\n" << endl;
        cin >> secondLinesCount >> secondColumnsCount;
        secondMatrix = generateMatrix(secondLinesCount, secondColumnsCount);
        printMatrix(secondLinesCount, secondColumnsCount, secondMatrix);  
        finalMatrix = generateMatrix(linesCount, secondColumnsCount);     
        if (columnsCount == secondLinesCount)
        {
            
            finalMatrix = multiplicateMatrix(linesCount, columnsCount, secondColumnsCount, matrix, secondMatrix, finalMatrix);
            cout << "Результат перемножения двух матриц:\n";
            printMatrix(linesCount, secondColumnsCount, finalMatrix);
        }
        else cout << "Такие матрицы перемножить невозможно";
        deleteMatrix(linesCount, matrix);
        deleteMatrix(secondLinesCount, secondMatrix);
        deleteMatrix(linesCount, finalMatrix);
        break;
    case 4:
        cout << "Введите кол-во элементов массива\n";
        int count, *array;
        cin >> count;
        array = generateAndPrintArray(count);
        searchMedian(array, count);
        delete[]array;
        break;
    case 5:
        cout << "Введите количество строк и столбцов матрицы\n";
        cin >> linesCount >> columnsCount;
        matrix = generateMatrix(linesCount, columnsCount);
        printMatrix(linesCount, columnsCount, matrix);
        cout << "Матрица в виде массива:\n";
        array = matrixToArray(linesCount, columnsCount, matrix);
        array = sortArray(array, linesCount * columnsCount);
        cout <<"\nМедиана = " << array[(columnsCount * linesCount) / 2];
        delete[]array;
        deleteMatrix(linesCount, matrix);
        break;
    default: cout << "\nНужно было ввести номер от 1 до 5";
        break;
    }
}