#include "Signal.h"

void canISaveNow() // хотите сохранить? 
{
	cout << "\nПроцесс сохранения\n"
	" Вы можете сохранить отсортированные данные.\n"
	" 1 - сохранить\n 2 - не сохранять\n\t>>> ";
}

void noAccount() // такого аккаунта нет в системе
{
	cout << "\n\n Такого поля нет в базе данных!\n";
	Sleep(1000);
	system("cls");
}

void successSave()
{
	cout << "\n Новые данные успешно сохранены!\n";
	Sleep(2000);
	system("cls");
}

// передаём по адресу flag и amount чтобы они обновлялись в основной программе  (изначально true, 3)
void isfalsePassword(string TempLogin, bool& flagPassword, int& amount) // если несколько раз введен не тот пароль, то выводится сообщение об ошибке
{
	amount--; // уменьшаем количества попыток; если amount дойдет до 0, то останавливаем цикл while
	system("cls");
	cout << "\n Неверный пароль!\n Попыток осталось: " << amount << "\n\n Логин: " << TempLogin;
	if (amount == 0)
	{
		cout << "\n Вы превысили количество допустимых попыток! Повторите позже.\n";
		Sleep(2000);
		system("cls");
		flagPassword = false; // возвращаем значение false, чтобы остановить цикл
	}
}
