#include <iostream>
#include <time.h>
#include <conio.h>
using namespace std;

double inPut()
{
	int number;
	while (!(cin >> number))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите целочисленное значение!\n";
	}
	return number;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	do
	{
		system("cls");
		int i, j, rows, columns, choice;
		cout << "Введите количество строк и столбцов\n";
		rows = inPut();
		columns = inPut();
		int** matr = new int* [rows];
		for (i = 0; i < rows; i++)
			matr[i] = new int[columns];
		cout << "Введите  1, если вы хотите вручную ввести элементы массива,\nВведите 0, если хотите сделать их случайными\n";
		choice = inPut();
		switch (choice)
		{
		default:
			cout << "\nВы ввели иное значение, взяты случайные элементы массива\n";
		case 0:
			for (i = 0; i < rows; i++)
			{
				for (j = 0; j < columns; j++)
				{
					matr[i][j] = rand() % 1001 - 500;
					cout << matr[i][j] << " ";
				}
				cout << endl;
			}
			break;
		case 1:
			for (i = 0; i < rows; i++)
			{
				for (j = 0; j < columns; j++)
					matr[i][j] = inPut();
				cout << endl;
			}
			break;
		}
		cout << endl;
		int ind1 = 0, ind2 = 0;
		for (i = 0; i < rows; i++)
			for (j = 0; j < columns; j++)
			{
				if (matr[i][j] > matr[ind1][j]) ind1 = i;
				if (matr[i][j] < matr[ind2][j]) ind2 = i;
			}
		if (ind1 == ind2)
		{
			cout << "\nМаксимальный и минимальный элементы находятся в одной строке\n";
			return 1;
		}
		cout << "\n Результат преобразований:\n";
		int trade;
		for (j = 0; j < columns; j++)
		{
			trade = matr[ind1][j];
			matr[ind1][j] = matr[ind2][j];
			matr[ind2][j] = trade;
		}
		for (i = 0; i < rows; i++)
		{
			for (j = 0; j < columns; j++)
				cout << matr[i][j] << " ";
			cout << endl;
		}
		delete[]matr;
		cout << "\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
	return 0;
}
