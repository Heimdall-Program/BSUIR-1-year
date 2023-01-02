#include <iostream>
using namespace std;

double function(double x) {
	return pow(sin(x), 2) - 3 * cos(x);
}

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
			cin.ignore(200, '\n');
		}
		else
			return number;
	}
}

int metod(double a, double b, double eps, double step)
{
	int kol = 0, iter = 0;
	double root;
	for (double x = a; x <= b; x += step)
	{ 
		iter++;
		if (function(x) * function(x + step) < 0)
		{
			kol++;
			do
			{
				root = x - function(x) * step / (function(x) - function(x - step));
				x += eps;
			} while (fabs(root - x) < eps);
			cout << "Корень при значении f(x) = " << root << "\n";
			cout << "Корень найден за " << iter << " операций\n\n";
			iter = 0;
		}
		
	}
	return kol;
}

double metovDiv2(double a, double b, double eps) 
{
	double x, y, y_next, iter = 0;
	y = function(a);
	do {
		iter++;
		x = (a + b) / 2;
		y_next = function(x);
		if (y * y_next > 0)
		{
			a = x;
			y = y_next;
		}
		else b = x;
	} while (fabs(b - a) > eps);
	cout << "Корень при значении f(x) = " << (a + b) / 2 << "\n";
	cout << "Корень найден за " << iter << " операций\n\n";
	iter = 0;
	return (a + b) / 2;
}


int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "a = -7\tb = 3\ny = sin(x)^2 - 3*cos(x)\n\n";
	double x, step, eps, root;
	int a = -7, b = 3, kol_of_roots = 0, kolD = 0;

	cout << "Введите шаг:\n\t>>> ";
	step = inputDouble();
	cout << "Введите точность:\n\t>>> ";
	eps = inputDouble();


	for (x = a; x <= b; x += step)
		cout << "x = " << x << "\t| f(x) = " << function(x) << "\n";
	cout << endl;

	kol_of_roots = metod(a, b, eps, step);
	cout << "\n\n\n";
	while (kolD != kol_of_roots) 
	{
		a = metovDiv2(a, b, eps);
		kolD++;
	}
	cout << "\n\nКорней среди данных значений - " << kol_of_roots << "\n";
	return 0;
}