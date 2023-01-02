#include <cmath>
#include <iostream>
#include <conio.h>
using namespace std;

int recurs(int x, int n);
int inPut();

int recurs(int x, int n)
{
	if (n == 1) return x;
	if (n % 2 == 0)
		return pow(x, n / 2) * pow(x, n / 2);
	else return x * recurs(x, n - 1);
}
int inPut()
{
	int number;
	while (!(cin >> number))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите численное значение!\n";
	}
	return number;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	do
	{
		system("cls");
		cout << "Нахождение x^n\n";
		int n, x, i, check = 1;
		cout << "Введите x = ";
		x = inPut();
		cout << "Введите n = "; 
		n = inPut();
		cout << "Ответ через рекурсивную функцию - " << recurs(x, n);
		for (i = 1; i <= n; i++) check *= x;
		cout << "\nОтвет через обычную функцию - " << check;
		cout << "\n\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
	setlocale(LC_ALL, "Russian");
	return 0;
}

