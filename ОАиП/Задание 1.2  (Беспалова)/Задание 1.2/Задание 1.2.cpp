#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
using namespace std;

struct storage
{
	char name[10];
	int amount;
	double cost;
};

storage* enteringInformation(storage*, int);
int inputIntegerValue();
void showStorage(storage*, int);

storage* enteringInformation(storage* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ":\n";
		cout << "\n  Введите название товара:\t";
		cin >> (arr + i)->name;
		cout << "\n  Введите кол-во единиц товара:\t";
		cin >> (arr + i)->amount;
		cout << "\n  Введите цену  единицы товара:\t";
		cin >> (arr + i)->cost;
		cout << endl;
	}
	return arr;
}

void showStorage(storage* arr, int n)
{
	system("cls");
	cout << "Наименование товара -------- Кол-во ед. товара ------- Цена товара ---" << endl;
	for (int i = 0; i < n; i++)
		cout << i + 1 << ":" << setw(11) << (arr + i)->name << setw(27) << (arr + i)->amount << setw(24) << (arr + i)->cost << endl;
}

void indTask(storage* arr, int n)
{
	cout << "Наименование товара -------- Кол-во ед. товара ------- Цена товара ---" << endl;
	cout << "\nТовары, стоимость которых превышает 1000р:\n";
	for (int i = 0; i < n; i++)
		if ((arr + i)->cost > 1000)
			cout << i + 1 << ":" << setw(11) << (arr + i)->name << setw(27) << (arr + i)->amount << setw(24) << (arr + i)->cost << endl;
	cout << "\nТовары, общее кол-во которых больше 10 и меньше 100:\n";
	for (int i = 0; i < n; i++)
		if ((arr + i)->amount > 10 && (arr + i)->amount < 100)
			cout << i + 1 << ":" << setw(11) << (arr + i)->name << setw(27) << (arr + i)->amount << setw(24) << (arr + i)->cost << endl;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	do
	{
		int n;
		cout << "Введите кол - во видов товара: ";
		n = inputIntegerValue();
		storage* arr = new storage[n];
		arr = enteringInformation(arr, n);
		cout << "\nИтого на складе хранится:\n";
		showStorage(arr, n);
		cout << "\nИндивидуальное задание\n";
		indTask(arr, n);
		cout << "\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
}

int inputIntegerValue() {

	const int MAX_lENGHT = 15;
	char str[MAX_lENGHT];
	bool flag = false;

	while (!flag)
	{
		cin >> str;
		flag = true;
		for (int i = 0; str[i] != '\0'; i++)
			if ((str[i] < '0' || str[i] > '9'))
			{
				cout << "Неправильный формат ввода! Попробуй ещё раз...\n";
				flag = false;
				break;
			}
	}
	return atoi(str);
}