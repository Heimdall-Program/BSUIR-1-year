#include "Protection.h"

int protection(int a, int b, int& n)
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
	return n; // возвращение значения переменной
}


// Ввод пароля
string inputPassword()
{
	string password;
	int ch = 0;
	while (true)
	{
		ch = _getwch(); // для определения кода нажатой клавиши 

		if (ch == 13) // чтобы enter не добавился к паролю (13 - код клавиши enter)
			break; // остановка цикла после удачного ввода (нажатие enter)
		else
			if (ch == 8) // 8 - код клавиши backspace
			{
				cout << (char)8 << ' ' << (char)8; // cмещение курсора влево, затем замена на пробел, затем ещё раз смещение курсора 
				if (!password.empty()) // если строка не пуста, то можно удалять; если пусто, то ничего не делаем
					password.erase(password.length() - 1); // метод string для удаления одного символа 
			}
			else
			{
				cout << "*"; // вывод звездочки 
				password += (char)ch; // добавляем к строке password символ 
			}
	}
	return password;
}
