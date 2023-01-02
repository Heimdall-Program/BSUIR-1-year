#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double invest(double, double, int);
double inputDouble();
int inputInt();

double invest(double sum, double percent, int years)
{
	if (years == 0) return sum;
	return (1 + percent / 100) * invest(sum, percent, years - 1);
}

double bank(double summ, double percent, int years)
{
	if (years == 0) return summ;
	return (1 + percent/100) * bank(summ, percent, years - 1);
}


double inputDouble()
{
	double number;
	do {
		cout << "\n  Введите численное значение >= 0!\n\t>>> ";
		while (!(cin >> number))
		{
			cin.clear();
			while (cin.get() != '\n');
		}
	} while (number < 0);
	return number;
}
int inputInt()
{
	int number;
	do {
		cout << "\n  Введите численное значение >= 0!\n\t>>> ";
		while (!(cin >> number))
		{
			cin.clear();
			while (cin.get() != '\n');

		}
	} while (number < 0);
	return number;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	do
	{
		system("cls");
		cout << "Нахождение величины вклада по истечению n периодов\n";
		int years;
		double sum, percent, check;
		cout << " Введите начальную сумму: ";
		sum = inputDouble();
		cout << " Введите сколько % выплачивается в год по вкладу: ";
		percent = inputDouble();
		cout << " Введите через сколько лет заберут вклад: ";
		years = inputInt();
		cout << " Ответ через рекурсивную функцию - " << invest(sum, percent, years);
		cout << " Ответ через рекурсивную функцию (bank) - " << bank(sum, percent, years);

		check = sum * pow(1 + percent / 100, years);
		cout << "\n Ответ через обычную функцию - " << check;

		cout << "\n\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
}