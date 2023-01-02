#include <iostream>
#include <time.h>
using namespace std;

struct stack
{
	int info;
	stack* next;
};

void view(stack* value);
stack* create_Add(stack* value, int in);
stack* indTask(stack* value);
void sort(stack* value);
void deleteStack(stack** value);
void protection(int a, int b, int& n);

void protection(int a, int b, int& n)
{
	while (true)
	{
		cin >> n; // ввод нужной переменной 
		while ((!cin) || (cin.get() != '\n')) // буквы 
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n Значение должно быть числом! Пожалуйста, повторите ввод\n\t>>> ";
			cin >> n;
		}
		if (n >= a && n <= b) break; // диапазон чисел
		cout << "\n Введенное число выходит за допустимый предел!\n\t[от " << a << " до " << b << "]\nПожалуйста, повторите ввод\n\t>>> ";
	}
}

stack* create_Add(stack* top, int in)
{
	stack* t = new stack;
	t->info = in;
	t->next = top;
	return t;
}

void view(stack* top)
{
	while (top != NULL)
	{
		cout << top->info << "\t";
		top = top->next;
	}
	cout << endl;
}

stack* indTask(stack* top)
{
	cout << "\n\tВ созданном списке определить первое максимальное значение и удалить его\n";
	stack* p = top;
	stack* max = top;
	
		while (p->next != NULL)
		{
			p = p->next;
			if (p->info > max->info)
			{
				max = p;
			}

		}
		if (max == top)
		{
			top = max->next;

		}
		else
		{
			p = top;
			while (p->next != max)
				p = p->next;
			p->next = max->next;
		}
		delete max;
		return top;
}
void deleteStack(stack** value)
{
	stack* t;
	while (*value != NULL)
	{
		t = *value;
		*value = (*value)->next;
		delete t;
	}
}

void sort(stack* value)
{
	cout << "Ваш стэк\n";
	view(value);
	stack* t = NULL, * i;
	int trade;
	do
	{
		for (i = value; i->next != t; i = i->next)
			if (i->info < i->next->info)
			{
				trade = i->info;
				i->info = i->next->info;
				i->next->info = trade;
			}
		t = i;
	} while (value->next != t);
	cout << "Отсортированный стэк\n";
	view(value);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	int task, num, size, i;
	int input = 0;
	bool flag = false;
	stack* top = NULL;
	while (flag == false)
	{
		cout << "\n 1. Создание стэка(удаление текущего)\n 2. Добавление элементов\n 3. Просмотр"
			<<"\n 4. Индивидуальное задание\n 5. Сортировка стэка\n 6. Выход из программы\n\t>>> ";
		protection(1, 6, task);
		switch (task)
		{
		case 1:
			cout << "Стэк создан"; 
			deleteStack(&top); 
		case 2:
			system("cls");

			cout << "\n\t1 - ввести вручную\n\t2 - воспользоваться рандомом\n\t\t>>> ";
			protection(1, 2, input);
			switch (input)
			{
			case 1:
				cout << "\tВведите размер стэка (или кол-во добавляемых элементов)\n\t\t>>> ";
				protection(1, 20, size);
				for (i = 0; i < size; i++)
				{
					cout << "\nВведите элемент:\t";
					protection(-10000, 10000, num);
					top = create_Add(top, num);
				}
				break;
			case 2:
				cout << "\tВведите размер стэка (или кол-во добавляемых элементов)\n\t\t>>> ";
				protection(1, 500, size);
				for (i = 0; i < size; i++)
				{
					
					num = rand() % 101 - 50;
					cout << num << '\t';
					top = create_Add(top, num);
				}
				break;
			}
		
			view(top);
			break;
		case 3:
			system("cls");
			if (!top)
			{
				cout << "Стэк пуст\n";
				break;
			}
			view(top);
			break;
		case 4:
			system("cls");
			cout << "\n\tИзначальный стек:\n\t";
			view(top);
			if (!top)
			{
				cout << "\nСтэк пуст\n";
				break;
			}
			top = indTask(top);
			cout << "\n\tCтек после удаления максимального:\n\t";
			view(top);
			break;
		case 5:
			system("cls");
			if (!top)
			{
				cout << "Стэк пуст\n";
				break;
			}
			sort(top);
			break;
		case 6:
			deleteStack(&top);
			flag = true;
			break;
		}
	}
}