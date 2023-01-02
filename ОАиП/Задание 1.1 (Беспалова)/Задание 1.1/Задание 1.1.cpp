#include <iostream>
#include <math.h>
#include <ctime>
#include <conio.h>
using namespace std;

int inputInt();
void generationArray(int* arr, int n);
void fillArray(int* arr, int size);
void showArray(int* arr, int n);
void sumAndNum(int* arr, int size, int &sum, int *kol);

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	do
	{
		system("cls");
		int n, choice, sum = 0, kol = 0;
		do
		{
			cout << "Введите размер массива\t";
			n = inputInt();
		} while (n < 1);
		int* array = new int[n];
		do
		{
			cout << "Выбери вариант ввода массива (1 - с клавиатуры, 2 - случайное заполнение)\n";
			choice = inputInt();
		} while (choice < 1 || choice > 2);

		if (choice == 1)
		{ 
			fillArray(array, n); 
		}
		else generationArray(array, n);
		cout << "\nМассив:\n";
		showArray(array, n);
		cout << endl;
		sumAndNum(array, n, sum, &kol);
		cout << "\n\tСумма элементов массива, которые > 10 и < 100 = " << sum << "\n\tИх количество - " << kol;
		delete[] array;
		cout << "\n\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
}

int inputInt()
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

void generationArray(int* arr, int n) 
{
	for (int i = 0; i < n; i++)
		*(arr + i) = rand() % 101 - 50;
}

void fillArray(int* arr, int size) 
{
	for (int i = 0; i < size; i++)
		*(arr + i) = inputInt();
}

void showArray(int* arr, int n) 
{
	for (int i = 0; i < n; i++)
		cout << *(arr + i) << " ";
	cout << endl;
}

void sumAndNum(int* arr, int n, int &sum, int *kol)
{
	for (int i = 0; i < n; i++)
		if (*(arr + i) > 10 && *(arr + i) < 100)
		{
			sum += *(arr + i);
			*kol += 1;
		}
}
