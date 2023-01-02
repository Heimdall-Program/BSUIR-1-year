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

void task1()
{
    int a, k, number, q = 0;
    cout << "Введите число\n";
    cin >> number;
    if (number == 0) 
    {
        cout << 0 << endl;
        return;
    }
    if (number < 0) // number<0?
    {
        number *= -1;
        q++;
    }
    k = 0; a = number;
    while (a > 0) //подсчёт кол-ва разрядов
    {
        k++; 
        a = a / 10;
    }; 
    if (q == 1)
        cout << "-" << endl;
    while (k > 0) //вывод чисел от "сотен к десяткам"
    {
        cout << trunc(number / pow(10, k - 1)) << endl;//ыфыод левого разряда
        number = number - trunc(number / pow(10, k - 1)) * pow(10, k - 1);
        k--;
    }
 
}
void task2()
{
    int number_of_month;
    cout << "Введите номер дня недели\n";
    cin >> number_of_month;
    switch (number_of_month)
    {  
        case 1:
            cout << "Понедельник"; 
            break;
        case 2:
            cout << "Вторник"; 
            break;
        case 3:
            cout << "Среда"; 
            break;
        case 4:
            cout << "Четверг"; 
            break;
        case 5:
            cout << "Пятница"; 
            break;
        case 6:
            cout << "Суббота"; 
            break;
        case 7:
            cout << "Воскресенье"; 
            break;
        default:
            cout << "Нет дня недели с таким номером"; 
            break;
    }
}
void task3()
{
    int a, k = 0, number, q = 0, ind, g = 0;
    cout << "Введите число и сколько его первых символов нужно вывести\n";
    cin >> number >> ind;
    if (number == 0) // number=0?
    {
        cout << 0 << endl;
        return;
    }
    if (number < 0) // number<0?
    {
        number *= -1;
        q++;
    }
    a = number;
    while (a > 0) //подсчёт кол-ва разрядов
    {
        k++; 
        a /= 10;
    };    
    if (q == 1) 
        cout << "-" << endl;
    while (k > 0) //вывод чисел от "сотен к десяткам"
    {

        cout << trunc(number / pow(10, k - 1));//Вывод левого разряда
        number = number - trunc(number / pow(10, k - 1)) * pow(10, k - 1);
        k--;
        g++; 
        if (g == ind)
        {
            break;
        };
    }


}
void task4()//без подсчёта объёмов
{
    int a, b, c, x, y, z;
    cout << " Введите длину, ширину и высоту отверстия\n";
    cin >> a >> b >> c;
    cout << " Введите длину, ширину и высоту параллелепипеда\n";
    cin >> x >> y >> z;

    if ((a >= z && b >= y) || (a >= z && b >= x) || (a >= x && b >= y) || (b >= z && a >= y) || (b >= z && a >= x) || (b >= x && a >= y))
        cout << " Возможно вместить параллелепипед в данное отверстие\n";
    else
        cout << " Невозможно вместить параллелепипед в данное отверстие\n";
}
void task5()
{
    int password[4], i, j, k, q;
    char symbol;
    cout << "\nПароль сгенерирован:\n";
    for (i = 0; i < 4; i++)
    {
        symbol = 48 + rand() % ((48 + 1) - 57);
        password[i] = symbol-48;
        cout << password[i] << " "; 
    }
    cout << "\nПароль подобран:\n";
    for (i = 0; i < 10; i++)
        for (j = 0; j < 10; j++)
            for (k = 0; k < 10; k++)
                for (q = 0; q < 10; q++)
                {
                    if ((password[0] == i) && (password[1] == j) && (password[2] == k) && (password[3] == q))
                        cout << password[0] << password[1] << password[2] << password[3];
                }
}



int main()
{
    //Задания сделаны в начале сентября, код местами кривой, но рабочий.
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

