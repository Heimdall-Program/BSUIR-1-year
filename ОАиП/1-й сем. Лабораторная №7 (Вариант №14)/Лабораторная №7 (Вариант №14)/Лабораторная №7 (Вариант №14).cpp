#include <iostream>
#include <conio.h>
using namespace std;
// Дана строка, состоящая из слов, разделенных пробелами. 
// Вывести на экран порядковый номер слова максимальной длины и номер позиции строки с которой оно начинается.

int main()
{
    setlocale(LC_ALL, "Russian");
    do
    {
        system("cls");
        int i, j, length = 1, kol, max_kol = 0, position = 0, number_of_pos_word = 0, number_of_word = 0;
        cout << "Введите строку, состоящую из слов\n";
        char* line = new char[1025];
        line[0] = 32;
        while (true)
        {
            line[length] = _getch();
            if (line[length] == 13) break;
            if ((line[length] >= 'a' && line[length] <= 'z') || (line[length] >= 'A' && line[length] <= 'Z') || (line[length] == 32))
            {
                cout << line[length];
                length++;
            }
        }

        for (i = 0; i < length - 1; i++)
            if (line[i] == 32)
            {
                kol = 0;
                if (line[i] == 32 && line[i + 1] != 32) number_of_word++;
                for (j = i + 1; j < length; j++)
                    if (line[j] != 32) kol++;
                    else break;
                if (kol > max_kol)
                {
                    number_of_pos_word = number_of_word;
                    max_kol = kol;
                    position = i + 1;
                }
            }
        cout << "\nПорядковый номер слова максимальной длины - " << number_of_pos_word << "\nПозиция с которой оно начинается - " << position;
        cout << "\nДанное слово: ";
        for (i = position; i < position + max_kol + 1; i++) cout << line[i];
        delete[]line;
        cout << "\nНажмите пробел, если хотите ввести новую строку\n";
    } while (_getch() == 32);
}
