#include <iostream>
#include <cmath>
using namespace std;

typedef double (*function)(double, double, double);

double inputDouble();
int protection(int, int, int&);
double func(double);
double leftRectanglMethod(double, double, double);
double trapezoidalMethod(double, double, double);
double simpsonsMethod(double, double, double);
double Emetod(function, double, double, double);

double inputDouble()
{
	double number;
	while (true)
	{
		cin >> number;
		if (cin.fail() || number < 0)
		{
			cout << "Некорректный ввод, введите положительно число\n";
			cin.clear();
			cin.ignore(100, '\n');
		}
		else
			return number;
	}
}


int protection(int a, int b, int& n)
{
	while (true)
	{
		cin >> n;
		while ((!cin) || (cin.get() != '\n'))
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n Значение должно быть числом! Пожалуйста, повторите ввод\n\t>>> ";
			cin >> n;
		}
		if (n >= a && n <= b) break;
		cout << "\n Введенное число выходит за допустимый предел!\n\t[от " << a << " до " << b << "]\nПожалуйста, повторите ввод\n\t>>> ";
	}
	return n;
}

double func(double x)
{
	return sin(x) * sin(x) - 3 * cos(x);
}

double leftRectanglMethod(double a, double b, double n)
{
	double h = (b - a) / n, integral = 0.0;
	for (int i = 0; i <= n - 1; i++)	// 3n<<
		integral += h * func(a + i * h);
	return integral;
}

double trapezoidalMethod(double a, double b, double n)
{
	double h = (b - a) / n, integral = func(a) + func(b);
	for (int i = 1; i <= n - 1; i++)//????
		integral += 2 * func(a + i * h);
	integral *= h / 2;
	return integral;
}

double simpsonsMethod(double a, double b, double n)
{
	double h = (b - a) / n, integral = func(a) + func(b);
	int k;
	for (int i = 1; i <= n - 1; i++)
	{
		k = 2 + 2 * (i % 2);
		integral += k * func(a + i * h);
	}
	integral *= h / 3;
	return integral;
}

double Emetod(function fun, double a, double b, double eps)
{
	int number = 10, i = 0;
	double diff, integral;
	do
	{
		i++;
		diff = fabs(fun(a, b, number * i) - fun(a, b, number * (i + 1)));
	} while (diff > eps);
	cout << "\n\tЧисло разбиений для метода средних = " << number * (i + 1) << '\n';
	return integral = fun(a, b, number);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "\n\ta = 1\tb = 7\n\ty = sin(x)^2 - 3*cos(x)\n\n";
	int a = 1, b = 7, number_of_divisions, n;
	double step, eps;
	cout << "\tВведите:\n\t1 - для вычисления интеграла по введённому кол-ву разбиений\n\t2 - для вычисления интеграла с определённой точностью\n\t\t>>> ";
	protection(1, 2, n);
	switch (n)
	{
	case 1:
		cout << "\n\tВведите кол-во разбиений:\n\t\t>>> ";
		number_of_divisions = inputDouble();
		cout << "\n\n\tИнтеграл по методу средних = " << leftRectanglMethod(a, b, number_of_divisions)
			<< "\n\tИнтеграл по методу трапеций = " << trapezoidalMethod(a, b, number_of_divisions)
			<< "\n\tИнтеграл по методу Симпсона = " << simpsonsMethod(a, b, number_of_divisions)
			<< '\n';
		break;
	case 2:
		cout << "\n\tВведите точность:\n\t\t>>> ";
		eps = inputDouble();
		cout << "\n\n\tИнтеграл по методу средних = " << Emetod(leftRectanglMethod, a, b, eps)
			<< "\n\tИнтеграл по методу трапеций = " << Emetod(trapezoidalMethod, a, b, eps)
			<< "\n\tИнтеграл по методу Симпсона = " << Emetod(simpsonsMethod, a, b, eps)
			<< '\n';
		break;
	}
		return 0;
}





/*
void rectangleMethod(double step, int number_of_divisions, int a)
{
	cout << "\nПо формуле средних:\n";
	double integral = 0;
	for (double i = 0; i < number_of_divisions; i++)
		integral += step * function(a + step * (i - 0.5));
	cout << "Интеграл = " << integral << "\n";
}

void trapezoidalMethod(double step, int number_of_divisions, int a, int b)
{
	cout << "\nПо формуле трапеций\n";
	double integral = 0;
	integral = step * (function(a) + function(b)) / 2.0;
	for (int i = 1; i <= number_of_divisions - 1; i++)
		integral += step * function(a + step * i);
	cout << "Интеграл = " << integral << "\n";
}

void simpsonsMethod(double step, int number_of_divisions, int a, int b)
{
	cout << "\nПо формуле Симпсона\n";
	double integral = 0;
	integral = step * (function(a) + function(b)) / 6.0;
	for (double i = 0; i < number_of_divisions; i++)
		integral += 4.0 / 6.0 * step * function(a + step * (i - 0.5));
	for (int i = 0; i < number_of_divisions - 1; i++)
		integral += +2.0 / 6.0 * step * function(a + step * i);
	cout << "Интеграл = " << integral << "\n";
}
*/
