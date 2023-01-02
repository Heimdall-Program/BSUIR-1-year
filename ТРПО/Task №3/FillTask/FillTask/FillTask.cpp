#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

void task1();
void square(double, double);
void perimetr(double, double);
void draw_rectangle(double, double);

void task2();
void firstNFibonachi(int);
void factorial(int);

void task3();
void simpleOrCompound(int, int);
void GreatestCommonDivisor(int, int);

void task4();
void toBinaryCode(int);

void task5();
int* createArray();
void chances(int*);

void task1()
{
    cout << "Введите длину и ширину прямоугольника\n";
    double length, width;
    cin >> length >> width;
    perimetr(length, width);
    square(length, width);
    draw_rectangle(length, width);
    
}

void square(double length, double width)
{
    cout << "Площадь прямоугольника = " << length * width << endl;
}

void perimetr(double length, double width)
{
    cout << "Периметр прямоугольника = " << 2 * (length + width) << endl;
}

void draw_rectangle(double length, double width)
{
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= width; j++)
            if ((i == 1) || (i == length) || (j == 1) || (j == width)) cout << "*";
            else cout << " ";
        cout << endl;
    }
}

void task2()
{
    int number;
    cout << "Введите n\n";
    cin >> number;
    firstNFibonachi(number);
    factorial(number);
}

void firstNFibonachi(int n)
{
    long long first_trade = 1, second_trade = 1;
    cout << "Первые " << n << " чисел Фибоначчи:\n";
    cout << first_trade << " " << second_trade << " ";
    for (int i = 3; i <= n; i++)
        if (i % 2 == 1)
        {
            first_trade += second_trade;
            cout << first_trade << " ";
        }
        else
        {
            second_trade += first_trade;
            cout << second_trade << " ";
        }
}

void factorial(int n)
{
    long long fact = 1;
    for (int i = 1; i <= n; i++) fact *= i;
    cout << endl << n << "! = " << fact;
}

void task3()
{
    cout << " Введите два числа \n";
    int first_number, second_number;
    cin >> first_number >> second_number;
    simpleOrCompound(first_number, second_number);
    GreatestCommonDivisor(first_number, second_number);
}
void simpleOrCompound(int first_number, int second_number)
{
    int i, divisors_of_the_first = 0, divisors_of_the_second = 0;
    for (i = 1; i <= sqrt(first_number); i++) if (first_number % i == 0) divisors_of_the_first++;
    for (i = 1; i <= sqrt(second_number); i++) if (second_number % i == 0) divisors_of_the_second++;
        if (divisors_of_the_first == 1)  cout << first_number << " - простое\n";
            else cout << first_number << " - составное\n";
        if (divisors_of_the_second == 1)  cout << second_number << " - простое\n";
            else cout << second_number << " - составное\n";
}

void GreatestCommonDivisor(int first_number, int second_number)
{
    while (first_number != second_number)
        if (second_number > first_number) second_number -= first_number;
            else first_number -= second_number;
    cout << "НОД = " << first_number << endl;
}

void task4()
{
    int number;
    cout << "Введите число " << endl;
    cin >> number;
    toBinaryCode(number);
}

void toBinaryCode(int number)
{
    int binary_code, i;
    binary_code = 0;
    for (i = 0; number > 0; i++)
    {
        binary_code += (number % 2) * pow(10, i);
        number /=2;
    }
    cout << binary_code << endl;
}
void task5()
{
    srand(time(0));
    int* arr = new int[10];
    arr = createArray();
    chances(arr);
}
int* createArray()
{
    int i, number;
    int* arr = new int[10];
    for(i = 0; i < 10; i++) arr[i] = 0;
    for (i = 0; i < 10; i++)
    {
        number = rand() % 10 + 1;
        arr[number - 1]++;
        cout << number << endl;
    }
    return arr;
}

void chances(int*arr)
{
    int i, j;
    cout << "Вероятности:\n";
    for (i = 1; i <= 10; i++)
        cout << i << "  ";
    cout << endl;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
            if (arr[j] >= i + 1) cout << "*  ";
            else cout << "   ";
        cout << endl;
    }
}
int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите номер задания\n";
    int task_number;
    cin >> task_number;
    switch (task_number)
    {
    case 1:task1(); break;
    case 2:task2(); break;
    case 3:task3(); break;
    case 4:task4(); break;
    case 5:task5(); break;
    default:"Нет задания с таким номером\n";
        break;
    }
    return 0;
}