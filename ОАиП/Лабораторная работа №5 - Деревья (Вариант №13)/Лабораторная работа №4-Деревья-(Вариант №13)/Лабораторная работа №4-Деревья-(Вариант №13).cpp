#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct tree
{
	string info;
	int key = 0;
	tree *left, *right;
};

struct stack
{
	string FIO;
	int ID = 0;
};


void branch(tree**, stack);
void addBranch(tree**, stack);
void view(tree*, int);
void searchKey(tree*, int);
void removeBranch(tree**, int);
void indTask(tree*, int&);
void preOrder(tree*);
void postOrder(tree*);
void removeTree(tree*);
void sortByGrowthKey(tree*);
void makeBalanse(tree**, int, int, stack*);
void sort(stack*, int);
tree* maxKey(tree*);
tree* minKey(tree*);
int elementNumber(tree*);
int storeTree(tree*, int, stack*);
void makeBalance(tree**, int, int, stack*);
void protection(int, int, int&);

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


int storeTree(tree* top, int pos, stack* elements)
{
	if (top) 
	{
		pos = storeTree(top->left, pos, elements);

		elements[pos].FIO = top->info;
		elements[pos].ID = top->key;
		pos++;
		pos = storeTree(top->right, pos, elements);
	}
	return pos;
}


void addBranch(tree** value, stack Human)
{
	tree* t = NULL;
	tree* prev = NULL;
	if (*value == NULL)
	{
		branch(value, Human);
		memset(&Human, 0, sizeof(stack));
	}
	else
	{
		t = *value;
		prev = *value;
		while (t != NULL)
		{
			prev = t;
			if (t->key == Human.ID)
			{
				cout << "Такой ID уже существует: " << Human.ID << endl;
				system("pause");
				system("cls");
				return;
			}
			else
			{
				if (Human.ID > t->key)
				{
					t = t->right;
				}
				else
				{
					t = t->left;
				}
			}
		}
	}
	branch(&t, Human);
	if (prev) 
	{
		if (Human.ID > prev->key)
		{
			prev->right = t;
		}
		else
		{
			prev->left = t;
		}
	}
	memset(&Human, 0, sizeof(stack));
}

void view(tree* t, int high)
{
	if (t) 
	{
		view(t->right, high + 3);
		for (int i = 0; i < high; i++)
			cout << " ";
		cout << t->key << endl;
		view(t->left, high + 3);
	}
}

void branch(tree** value, stack Human)
{
	bool prov = true;
	if (*value == NULL) prov = false;
	tree* t = new tree;
	t->info = Human.FIO;
	t->key = Human.ID;
	t->left = t->right = NULL;
	if (prov == false) (*value) = t;
	memset(&Human, 0, sizeof(stack));
}


void searchKey(tree* t, int k)
{
	if (t) {
		if (k > t->key) searchKey(t->right, k);
		else if (k < t->key) searchKey(t->left, k);
		else {
			cout << "Id = " << t->key << "\nFIO = " << t->info << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	else
	{
		cout << "Вершины с таким ID в дереве нет\n";
		system("pause");
		system("cls");
	}
}


void removeBranch(tree** value, int key) 
{
	tree* Del, * Prev_Del, * R, * Prev_R;
	Del = (*value);
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key) 
	{
		Prev_Del = Del;
		if (Del->key > key) Del = Del->left;
		else Del = Del->right;
	}
	if (Del == NULL) 
	{
		cout << " Вершины с таким ID в дереве нет.\n";
		system("pause");
		//system("cls");
		return;
	}
	if (Del->right == NULL) R = Del->left;
	else
		if (Del->left == NULL) R = Del->right;
		else {
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL) 
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del) R->right = Del->right;
			else 
			{
				R->right = Del->right;
				Prev_R->right = NULL;
				R->left = Prev_R;
			}
		}
	if (Del == (*value)) (*value) = R;
	else
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R;
		else Prev_Del->right = R;
	delete Del;
}


void indTask(tree* t, int& number)
{
	cout << "\nОбмен местами информационной части наибольшей и наименьшей вершин\n";
	swap(maxKey(t)->info, minKey(t)->info);
}


int elementNumber(tree* tree) 
{//подсчёт количества элементов в дереве
	if (tree->left == NULL && tree->right == NULL) return 1;
	int left, right;
	if (tree->left != NULL) 
	{
		left = elementNumber(tree->left);
	}
	else left = 0;
	if (tree->right != NULL)
	{
		right = elementNumber(tree->right);
	}
	else right = 0;
	return left + right + 1;
}


void preOrder(tree* value) 
{
	if (value) {
		cout << value->key << " " << value->info << endl;
		preOrder(value->left);
		preOrder(value->right);
	}
}


void postOrder(tree* value)
{
	if (value) {
		postOrder(value->left);
		postOrder(value->right);
		cout << value->key << " " << value->info << endl;
	}
}


void sortByGrowthKey(tree* value)
{
	if (value) {
		sortByGrowthKey(value->left);
		cout << value->key << " " << value->info << endl;
		sortByGrowthKey(value->right);
	}
}

void removeTree(tree* t) 
{
	if (t != NULL) 
	{
		removeTree(t->left);
		removeTree(t->right);
		delete t;
	}
}

void makeBalanse(tree** p, int n, int k, stack* a) 
{
	if (n == k) 
	{
		*p = NULL;
		return;
	}
	else {
		int m = (n + k) / 2;
		*p = new tree;
		(*p)->info = a[m].FIO;
		(*p)->key = a[m].ID;
		makeBalanse(&(*p)->left, n, m, a);
		makeBalanse(&(*p)->right, m + 1, k, a);
	}
}

void sort(stack* a, int n)
{
	stack t;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if ((a[i]).ID > (a[j]).ID)
			{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}

tree* maxKey(tree* t) {

	while (t->right != NULL) 
	{
		t = t->right;
	}
	return t;
}

tree* minKey(tree* t) {

	while (t->left != NULL) {
		t = t->left;
	}
	return t;
}


void makeBalance(tree** p, int n, int k, stack* a) {

	if (n == k) 
	{
		*p = NULL;
		return;
	}
	else {

		int m = (n + k) / 2;
		*p = new tree;
		(*p)->key = a[m].ID;
		(*p)->info = a[m].FIO;

		makeBalance(&(*p)->left, n, m, a);
		makeBalance(&(*p)->right, m + 1, k, a);
	}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n, choose, inf_part, i;
	string fio;
	tree* value = NULL;
	cout << "\n\tВведите количество вершин:\n\t\t>>> "; 
	protection(1, 10, n);
	stack* element = new stack[n], * Add = new stack;
	for (i = 0; i < n; i++) {
		cout << "\n\tID = ";
		protection(-10000, 10000, Add->ID);
		cout << "\n\tFIO = ";
		getline(cin, Add->FIO);
		addBranch(&value, *Add);
		system("cls");
	}
	while (true)
	{
		system("cls");
		cout << "\n\t 1. Создать дерево\n\t 2. Просмотр\n\t 3. Добавить вершину\n\t 4. Поиск по ID"
			<< "\n\t 5. Удалить вершину\n\t 6. Индивидуальное задание\n\t 7. Просмотр прямым обходом\n\t 8. Просмотр обратным обходом"
			<< "\n\t 9. Просмотр в порядке возрастания ключа\n\t 10. Сбалансировать дерево\n\t 0. Выход\n\t\t>>> ";
		protection(0, 10, choose);
		switch (choose)
		{
		case 1:
			cout << "\n\tВведите количество вершин: ";
			protection(1, 15, n);
			for (i = 0; i < n; i++) 
				addBranch(&value, element[i]);
			break;

		case 2:
			view(value, 3);
			system("pause");
			break;
		case 3:
			cout << "Id = ";
			protection(-10000, 10000, Add->ID);
			cout << "FIO = ";
			getline(cin, Add->FIO);
			system("cls");
			addBranch(&value, (*Add));
			break;
		case 4:
			cout << "\tВведите Id: ";
			protection(-10000, 10000, inf_part);
			searchKey(value, inf_part);
			break;
		case 5:
			cout << "\tВведите Id: ";
			protection(-10000, 10000, inf_part);
			removeBranch(&value, inf_part);
			break;
		case 6:
			inf_part = 0;
			indTask(value, inf_part);
			cout << "\tЧтобы увидеть результат выберите пункт 7-9\n";
			system("pause");
			break;
		case 7:
			preOrder(value);
			system("pause");
			break;
		case 8:
			postOrder(value);
			system("pause");
			break;
		case 9:
			sortByGrowthKey(value);
			system("pause");
			break;
		case 10:
			if (value == NULL)
			{
				cout << "В дереве нет вершин!\n"; 
				break;
			}
			else
			{
				tree* t;
				int k;
				t = value;
				k = elementNumber(t);
				stack* a = new stack[k];
				int pos = 0;
				storeTree(value, pos, a);
				makeBalance(&value, 0, k, a);
				delete[]a;
				break;
			}
			system("pause");
			break;
		case 0: 
			removeTree(value); 
			return 0;
		}
	}
}


