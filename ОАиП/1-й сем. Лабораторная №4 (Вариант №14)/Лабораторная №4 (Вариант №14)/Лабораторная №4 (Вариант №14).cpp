#include <iostream>
#include <cmath>
#include <iomanip>
#include <conio.h>
using namespace std;

double inputDoubleValue();
typedef double (*function)(double, double, int&);
void outPut(function, double, double, double, double);
double y(double, double, int&);
double s(double, double, int&);
double diff(double, double, int&);

double inputDoubleValue()
{
	while (true)
	{
		double number;
		cin >> number;
		if (cin.fail())
		{
			cout << "Некорректный ввод, введите число!\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
			return number;
	}
}
double inputDoublePlusValue()
{
	while (true)
	{
		double number;
		cin >> number;
		if (cin.fail() || number <= 0)
		{
			cout << "Некорректный ввод, введите число!\n";
			cin.clear();
			cin.ignore(200, '\n');
		}
		else
			return number;
	}
}
void outPut(function fun, double a, double b, double h, double eps)
{
	int n = 0;
	double sum = 0;
	for (double x = a; x < b; x += h)
	{
		sum = fun(x, eps, n);
		cout << x << setw(15) << sum << setw(12) << n << endl;
	}
}

double y(double x, double eps, int& k)
{
	return (exp(x) - exp(-x)) / 2;
}

double s(double x, double eps, int& n)
{
	double a = 1, r, summ = 1;
	r = x;
	n = 1;
	while (fabs(r) > eps)
	{
		r *= (x * x) / (2 * n * (2 * n + 1));
		summ += r;
		n++;
	}
	return summ;
}

double diff(double x, double eps, int& n)
{
	double a = 1, r, sum = 1, Y;
	Y = (exp(x) - exp(-x)) / 2;
	r = x;
	n = 1;
	while (fabs(r) > eps)
	{
		r *= (x * x) / (2 * n * (2 * n + 1));
		sum += r;
		n++;
	}
	return fabs(Y - sum);
}
int main()
{
	setlocale(LC_ALL, "Russian");
	do
	{
		system("cls");
		double a, b, step, eps, trade = 0;
		cout << "Введите промежуток a, b:\n";
		a = inputDoubleValue();
		b = inputDoubleValue();
		if (a > b)
		{
			cout << "Введённое вами начальное значение больше конечного, переменные обменялись значениями\n";
			trade = a;
			a = b;
			b = trade;
			cout << "a = " << a << "\nb = " << b << "\n";
		}
		cout << "Введите шаг:\n";
		step = inputDoublePlusValue();
		cout << "Введите погрешность eps:\n";
		eps = inputDoublePlusValue();

		cout << "n - количество итераций\n";
		for (int i = 0; i < 13; i++)cout << "_ ";
		cout << endl;
		cout << "x" << setw(15) << "Y(x)" << setw(15) << "n\n";
		outPut(y, a, b, step, eps);

		for (int i = 0; i < 13; i++)cout << "_ ";
		cout << endl;
		cout << "x" << setw(15) << "S(x)" << setw(15) << "n\n";
		outPut(s, a, b, step, eps);

		for (int i = 0; i < 13; i++)cout << "_ ";
		cout << endl;
		cout << "x" << setw(15) << "|Y(x) - S(x)|" << setw(15) << "n\n";
		outPut(diff, a, b, step, eps);

		cout << "\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
}
