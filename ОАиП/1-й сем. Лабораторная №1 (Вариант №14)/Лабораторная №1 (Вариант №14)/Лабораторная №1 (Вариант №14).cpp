#include <iostream>
#include <cmath>
#include <conio.h>
using namespace std;

double inPut()
{
	double number;
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
	long double a, b, c, x, y, z;
	do
	{
		system("cls");
		cout << "Введите x\n"; x = inPut();
		cout << "Введите y\n"; y = inPut();
		cout << "Введите z\n"; z = inPut();

		a = pow(y, x + 1) / (pow(abs(y - 2), double(1 / 3)) + 3);
		b = (x + y / 2) / (2 * abs(x + y));
		c = pow(x + 1, -1 / sin(z));
		cout << "g = " << a + b * c;
		cout << "\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
	return 0;
}
