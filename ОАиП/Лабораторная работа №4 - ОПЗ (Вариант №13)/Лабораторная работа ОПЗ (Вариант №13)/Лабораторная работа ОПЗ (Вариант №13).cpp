#include <iostream>
#include <conio.h>

using namespace std;

struct opz
{
	char info;
	opz* next;
};

opz* create(opz*, char);
opz* Exit(opz*, char*);
int priority(char);
double inputDouble();
void ReversePolishNotation(char*, char*, opz*);
double getAnswer(char*, opz*);
void defense(char*);
void dell(opz**);

opz* create(opz* top, char data)
{
	opz* t = new opz;
	t->info = data;
	t->next = top;
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
	case '^': return 4;
	case '*': case '/': return 3;
	case '-': case '+': return 2;
	case '(': return 1;
	}
	return 0;
}

double inputDouble()
{
	double number;
	while (!(cin >> number))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите положительное численное значение!\n";
	}
	return number;
}

void ReversePolishNotation(char* input, char* translate, opz* top) {
	int i = 0, j = 0;
	opz* t;
	top = NULL;
	char symbol;
	while (input[i] != '\0')
	{
		if (input[i] == ')')
		{
			while ((top->info) != '(') {
				top = Exit(top, &symbol);
				if (!top)
					symbol = '\0';
				translate[j++] = symbol;
				//cout << symbol << "\t";
			}
			t = top;
			top = top->next;
			delete t;
		}
		if (input[i] >= 'a' && input[i] <= 'z') 
			translate[j++] = input[i];
		if (input[i] == '(') 
			top = create(top, input[i]);
		if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^')
		{
			while (top != NULL && priority(top->info) >= priority(input[i]))
			{
				top = Exit(top, &symbol);
				translate[j++] = symbol;
			}
			top = create(top, input[i]);
		}
		i++;
	}
	while (top != NULL) {
		top = Exit(top, &symbol);
		translate[j++] = symbol;
	}
	translate[j] = '\0';
}

double getAnswer(char* translate, opz* top)
{
	char ch1, ch2, chr = 'z', symbol;
	double answer, Start1, Start2, mas[40] = { 7.6, 4.8, 3.5, 9.1, 0.2 };
	top = NULL;
	cout << "\nЗначения в варианте №13:";
	for (int i = 0; i < 5; i++)
	{
		symbol = 'a' + i;
		cout << "\n\t" << symbol << " = " << mas[i];
	}
	cout << "\nВведите 1, если желаете ввести свои значения,\n\t Для дефолтных - любой другой символ\n\t";
	symbol = _getch();
	if (symbol == '1') {
		cout << "\n\nВведите ваши значения:\n";
		for (int i = 0; i < 5; i++) {
			symbol = 'a' + i;
			cout << "\n\t" << symbol << " = ";
			mas[i] = inputDouble();
		}
		for (int i = 0; i < 5; i++)
		{
			symbol = 'a' + i;
			cout << "\n\t" << symbol << " = " << mas[i];
		}
	}
	for (int i = 0; i < strlen(translate); i++)
	{
		symbol = translate[i];
		if (symbol >= 'a' && symbol <= 'z') top = create(top, symbol);
		else {
			top = Exit(top, &ch1);
			top = Exit(top, &ch2);
			Start1 = mas[ch1 - 97];
			Start2 = mas[ch2 - 97];
			switch (symbol)
			{
			case '+': answer = Start2 + Start1; break;
			case '-': answer = Start2 - Start1; break;
			case '*': answer = Start2 * Start1; break;
			case '/': answer = Start2 / Start1; break;
			case '^': answer = pow(Start2, Start1); break;
			}
			mas[chr - 97] = answer;			top = create(top, chr);
			chr--;
		}
	}
	return answer;
}

void defense(char* input) {
	int i = 0;
	char symbol;
	while (true)
	{
		symbol = _getch();
		if (symbol == 13) break;
		if ((symbol >= 'a' && symbol <= 'e') ||
			symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
			symbol == '^' || symbol == '(' || symbol == ')')
		{
			input[i] = symbol;
			cout << input[i];
			i++;
		}
	}
}

void dell(opz** top)
{
	opz* t;
	while (*top != NULL)
	{
		t = *top;
		*top = (*top)->next;
		delete t;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	opz* top = NULL;
	cout << "Введите формулу:\nФормула из варианта: a/(b+c–d*e)\n";
	char input[50], translate[50];
	double answer;
	defense(input);
	ReversePolishNotation(input, translate, top);
	cout << "\nОбратная Польская Запись:" << translate << "\t";
	answer = getAnswer(translate, top);
	cout << "\nОтвет:" << answer << endl;
	dell(&top);
}