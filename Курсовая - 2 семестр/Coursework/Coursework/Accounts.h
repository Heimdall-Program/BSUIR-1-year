#pragma once // защита от двойного подключения заголовочных файлов
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Protection.h" 
#include "Signal.h"
#include "makeHashFromPassword.h"
#include <Windows.h>

using namespace std;

struct Accounts
{
	string login;
	string password;
	int role = 0; // 0 - пользователь, 1 - администратор 
	int access = 0; // 0 - неактивирован, 1 - активирован 
};

void programmStart();
void getNumberOfAccountsInFile(int&); // определение количества аккаунтов в файле
void readFileAccounts(Accounts*); // чтение (перенос) аккаунтов из файла в массив
void writeAccountsInFile(Accounts*, int); // запись аккаунтов в файл
void showAccounts(Accounts*, int); // вывод аккаунтов на экран
Accounts* resizeOfArray(Accounts*, int&, int); // перевыделение памяти
void addAccount(Accounts*, int&); // добавление аккаунта в массив
void newAccount(Accounts*, int&); //без кол-ва попыток
void delAccounts(Accounts*, int&); // удаление аккаунтов 
Accounts* menuLoginOrRegistration(Accounts*, int&); // меню авторизации (вход/регистрация) 
void checkLoginPassword(Accounts*, int&); // проверка логина и пароля 
void checkRole(Accounts*, int&, int); // проверка роли
void adminMenu(Accounts*, int&); // меню администратора
void adminMenuOfAdminAccounts(Accounts*, int&); // управление аккаунтами 
void userMenu(); // меню пользователя
