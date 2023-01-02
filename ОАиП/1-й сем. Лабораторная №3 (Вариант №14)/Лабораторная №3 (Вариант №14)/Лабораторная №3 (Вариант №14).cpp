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
		double left, right, step, summ, i, y, r, raz;
		int n, j;
		cout << "Введите начальное значение(a)\n";
		left = inPut();
		cout << "Введите конечное значение(b)\n";
		right = inPut();
		while (left > right)
		{
			cout << "\nНачальное значение должно быть меньше конечного\n";
			cout << "Введите начальное значение(a)\n";
			left = inPut();
			cout << "Введите конечное значение(b)\n";
			right = inPut();
		}
		cout << "Введите шаг(h)\n";
		step = inPut();
		cout << "Введите n\n";
		n = inPut();
		for (i = left; i <= right; i += step)
		{
			r = i;
			summ = i;
			y = (exp(i) - exp(-i)) / 2;
			for (j = 1; j <= n; j++) {
				r *= (i * i) / (2 * j * (2 * j + 1));
				summ += r;
			}
			raz = abs(summ - y);
			cout << "x = " << i << " y = " << y << " S = " << summ << "S - y = " << raz << endl;
		}
		cout << "\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
}
