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
	do
	{
		system("cls");
		double x, function;
		int function_number;
		cout << "Введите z\n";
		x = inPut();
		if (x > 0)
		{
			x = sqrt(x);
			cout << "Выполняется первое условие, поэтому x = z^(1/2)\n";
		}
		else
		{
			x = 3 * x + 1;
			cout << "Выполняется второе условие, поэтому x = 3z + 1\n";
		}
		cout << "Выберите функцию: \n #1 - 2x \n #2 - x*x \n #3 - x/3 \n";
		function_number = inPut();
		switch (function_number)
		{
		case 1: function = 2 * x; cout << "f(х) = 2x\n"; break;
		case 2: function = x * x; cout << "f(х) = x*x\n"; break;
		case 3:  function = x / 3; cout << "f(х) = x/3\n"; break;
		default:cout << "Вы ввели неверное значение, поэтому взята первая функция\n";
			function = 2 * x; cout << "f(х) = 2x\n"; break;
		}
		cout << "y = " << 2 * cos(3 * function) + sin(x / 5) + 4 * exp(x);
		cout << "\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
	return 0;
}
