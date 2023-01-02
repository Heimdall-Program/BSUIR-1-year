#include <iostream>
#include <conio.h>
using namespace std;

void sorti(char* str, int length)
{
	int i, ind1 = -1, ind2 = 0, max_length = 1, number_of_words = 0;

	for (i = 0; i <= length; i++)
		if (str[i] == ' ' || str[i] == '\0')
		{
			number_of_words++;
			ind2 = ind1 + 1;
			ind1 = i;
			if (ind1 - ind2 >= max_length)
				max_length = ind1 - ind2;
		}

	char** newStr = new char* [number_of_words];
	for (i = 0; i < number_of_words; i++)
		newStr[i] = new char[max_length];									
	str[length] = ' ';

	int k = 0, j = 0;
	for (i = 0; i < number_of_words; i++)
		for (j = 0; j < max_length + 1; j++)
		{
			newStr[i][j] = str[k++];
			if (newStr[i][j] == ' ')
			{
				while (j < max_length + 1) newStr[i][j++] = ' ';
				break;
			}
		}

	char* word;
	int l;

	for (i = 0; i < number_of_words - 1; i++)
	{
		word = newStr[i];
		l = i;

		for (k = i + 1; k < number_of_words; k++)
			for (j = 0; j < max_length; j++)
			{
				if (newStr[k][j] < newStr[l][j])
				{
					word = newStr[k];
					l = k;
				}
				if (newStr[k][j] == newStr[l][j]) continue;
				break;
			}
		if (l == 0) continue;
		newStr[l] = newStr[i];
		newStr[i] = word;
	}
	cout << "\nСлова в алфавитном порядке:\n";
	for (i = 0; i < number_of_words; i++)
	{
		for (j = 0; j < max_length; j++) cout << newStr[i][j];
		cout << endl;
	}
	delete[]newStr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	do
	{
		system("cls");
		char str[128], letter;
		int length = 0;
		cout << "Введите строку:\n";
		while (true)
		{
			letter = _getch();
			if (letter == 13) break;
			if ((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z') || (letter == ' ' && str[length - 1] != ' '))
			{
				str[length] = letter;
				cout << str[length];
				length++;
			}
		}
		if (str[length - 1] != ' ')  str[length] = '\0';
		cout << endl;
		sorti(str, length);

		cout << "\nНажмите пробел, если хотите запустить программу заново\n";
	} while (_getch() == 32);
}
