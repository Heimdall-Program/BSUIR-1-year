#include <iostream>
#include <conio.h>
using namespace std;

struct opz
{
	char info;
	opz* next;
};

opz* Create(opz*, char);
opz* Exit(opz*, char*);
void fillInArr(char*, int*);
int defense(char*, int*);
void ReversePolishNotation(char*, char*, opz*);
double getAnswerFromOpz(char*, char* in, opz*, int, int);
void clearMemory(opz**);

opz* Create(opz* p, char data)
{
	opz* t = new opz;
	t->info = data;
	t->next = p;
	return t;
}

opz* Exit(opz* top, char* data)
{
	opz* t = top;
	*data = t->info;
	top = top->next;
	delete t;
	return top;
}

int priority(char symbol)
{
	switch (symbol)
	{
	case '^':
		return 4;
	case '*':
	case '/':
		return 3;
	case '-':
	case '+':
		return 2;
	case '(':
		return 1;
	}
	return 0;
}

int defense(char* in, int* lenght)
{
	bool flag;
	int countOperation = 0, countOfLetter = 0, index1 = 0, index2 = 0, check, i;
	for (i = 0; i < *lenght; i++)
	{
		check = in[i];
		flag = false;
		if (in[i] == '(')
		{
			index1 = i;
			for (int j = index2 + 1; j < *lenght; j++)
			{
				if (in[j] == ')')
				{
					flag = true;
					index2 = j;
					break;
				}
			}
			if (flag == false)
			{
				cout << "\tВ выражении нет закрывающей скобки!\n";
				exit(0);
			}
		}

		if (in[i] == ')' && i != index2)
		{
			for (int j = i; j >= 0; j--)

				if (in[j] == '(' && j != index1)
				{
					flag = true;
					index1 = j;
					index2 = i;
				}

			if (flag == false)
			{
				cout << "\tВ выражении нет открывающей скобки!\n";
				exit(0);
			}
		}
		if (in[i] == '+' || in[i] == '-' || in[i] == '*' || in[i] == '/' || in[i] == '^')
		{
			countOperation++;
			if (in[i + 1] == '+' || in[i + 1] == '-' || in[i + 1] == '*' || in[i + 1] == '/' || in[i + 1] == '^')
			{
				cout << "\tВы ввели два знака подряд!\n";
				exit(0);
			}
		}

		if (in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/' && in[i] != '(' && in[i] != ')' && in[i] != '^')
		{
			countOfLetter++;
			if (in[i + 1] != '+' && in[i + 1] != '-' && in[i + 1] != '*' && in[i + 1] != '/' && in[i + 1] != '(' && in[i + 1] != ')' && in[i + 1] != '^' && in[i + 1] != '\0')
			{
				cout << "\tВы ввели две буквы подряд\n";
				exit(0);
			}
		}
		if (in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/' && in[i] != '(' && in[i] != ')' && in[i] != '^' && (in[i] < 'a' || in[i] >'z'))
		{
			cout << "\tОбнаружен недопустимый символ\n\tИспользуются только строчные буквы английского алфавита, арифметические операции и скобки\n";
			exit(0);
		}
		if (in[i] != '+' && in[i] != '-' && in[i] != '*' && in[i] != '/' && in[i] != '(' && in[i] != ')' && in[i] != '^')
			if (in[i + 1] == '(')
			{
				cout << "\tОтсутствует знак операции между переменной и скобкой\n";
				exit(0);
			}

		if (in[i] == ')' && in[i + 1] != '\0')
			if (in[i + 1] != '+' && in[i + 1] != '-' && in[i + 1] != '*' && in[i + 1] != '/' && in[i + 1] != '^' && in[i + 1]!=')')
			{
				cout << "\tНе обнаружен знак операции между скобкой и переменной\n";
				exit(0);
			}
	}
	if (in[i - 1] == '+' || in[i - 1] == '-' || in[i - 1] == '*' || in[i - 1] == '/' || in[i - 1] == '^')
	{
		cout << "\tВыражение не может заканчиваться знаком\n";
		exit(0);
	}
	if (countOfLetter == 1 || countOfLetter == 0)
	{
		cout << "\tНедостаточное количество переменных, ОПЗ не имеет смысла\n";
		exit(0);
	}
	return countOperation;
}

void fillInArr(char* in, int* lenght)
{
	int i = 0;
	while (true)
	{
		in[i] = _getch();
		if (in[i] == 13)
		{
			in[i] = '\0';
			break;
		}
		if (in[i] == 8)
		{
			i--;
			cout << "\b \b";
		}
		else
		{
			cout << in[i];
			i++;
		}


	}
	*lenght = i;
}

void ReversePolishNotation(char* input, char* translate, opz* top) 
{
	int i = 0, j = 0;
	opz* t;
	top = NULL;
	char symbol;
	while (input[i] != '\0')
	{
		if (input[i] == ')')
		{
			while (top->info != '(')
			{
				top = Exit(top, &symbol);
				if (!top)
					symbol = '\0';

				translate[j++] = symbol;
			}
			t = top;
			top = top->next;
			delete t;
		}
		if (input[i] >= 'a' && input[i] <= 'z')
			translate[j++] = input[i];

		if (input[i] == '(')
			top = Create(top, input[i]);

		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^')
		{
			while (top != NULL && priority(top->info) >= priority(input[i]))
			{
				top = Exit(top, &symbol);
				translate[j++] = symbol;
			}
			top = Create(top, input[i]);
		}
		i++;
	}
	while (top != NULL)
	{
		top = Exit(top, &symbol);
		translate[j++] = symbol;
	}
	translate[j] = '\0';
}

double getAnswerFromOpz(char* translate, char* input, opz* top, int lenght, int countOperation)
{
	top = NULL;
	char letter, ch1, ch2, symbol, kol = 26 + countOperation + 96;
	double answer, Start1, Start2;
	double* arr = new double[26 + countOperation];
	for (int i = 0; i < 26; i++)
		arr[i] = NULL;

	for (int i = 0; i < lenght; i++)
		if (input[i] != '+' && input[i] != '-' && input[i] != '*' && input[i] != '/' && input[i] != '(' && input[i] != ')' && input[i] != '^')
		{
			letter = input[i];
			if (arr[letter - 97] == 0)
				while (true)
				{
					cout << "\tВведите значение переменной " << letter << " = ";
					cin >> arr[letter - 97];
					if (!cin)
					{
						cout << "\tВведите число!\n\t\t>>> ";
						cin.clear();
						cin.ignore(1000, '\n');
					}
					else
						break;
				}
		}

	for (int i = 0; i < strlen(translate); i++)
	{
		symbol = translate[i];
		if (symbol >= 'a' && symbol <= 'z') top = Create(top, symbol);
		else 
		{
			top = Exit(top, &ch1);
			top = Exit(top, &ch2);
			Start1 = arr[ch1 - 97];
			Start2 = arr[ch2 - 97];
			switch (symbol)
			{
			case '+': 
				answer = Start2 + Start1; 
				break;
			case '-': 
				answer = Start2 - Start1;
				break;
			case '*': 
				answer = Start2 * Start1;
				break;
			case '/':
				if (Start1 == 0)
				{
					cout << "На ноль делить нельзя, посчитать это мы не можем\n";
					delete[] arr;
					clearMemory(&top);
					exit(0);
				}
				answer = Start2 / Start1;
				break;
			case '^': 
				answer = pow(Start2, Start1); 
				break;
			}
			arr[kol - 97] = answer;
			top = Create(top, kol);
			kol--;
		}
	}
	delete[] arr;
	return answer;
}

void clearMemory(opz** p)
{
	opz* t;
	while (*p != NULL)
	{
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	opz* top = NULL;
	int lenght = 0, operations = 0;
	cout << "\n\tФормула из варианта №13: a/(b+c–d*e)\n\tВведите формулу:\n\t\t>>> ";
	char input[50], translate[50];
	double answer;
	fillInArr(input, &lenght);
	cout << '\n';
	operations = defense(input, &lenght);
	ReversePolishNotation(input, translate, top);
	cout << "\n\tОбратная Польская Запись:" << translate << '\n';
	answer = getAnswerFromOpz(translate, input, top, lenght, operations);
	cout << "\n\tОтвет:" << answer << '\n';
	clearMemory(&top);
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
	; ;; ;;; ;;;; ;;;;; ;;;;;; ;;;;; ;;;; ;;; ;; ;
}