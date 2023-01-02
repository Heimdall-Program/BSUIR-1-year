#include "Accounts.h" 

void programmStart()
{
	SetConsoleCP(1251); // настройка кодировка по умолчанию для ввода
	SetConsoleOutputCP(1251); // настройка кодировка по умолчанию для вывода

	int number_of_accounts = 0;
	getNumberOfAccountsInFile(number_of_accounts); // определение количества аккаунтов в файле
	Accounts* array_of_accounts = new Accounts[number_of_accounts]; // выделение памяти для массива структур
	readFileAccounts(array_of_accounts); // перенос аккаунтов из файла в массив
	array_of_accounts = menuLoginOrRegistration(array_of_accounts, number_of_accounts); // меню авторизации (1 - вход, 2 - регистрация) 
	writeAccountsInFile(array_of_accounts, number_of_accounts); // запись данных в файл 
	delete[] array_of_accounts; // очистка динамической памяти
}

// Определение кол-ва аккаунтов в файле
void getNumberOfAccountsInFile(int& number_of_accounts)
{
	string temp; // временная переменная для считывания данных
	ifstream fin("Accounts.txt", ios::in); // открытие файла для чтения данных 
	if (!fin.is_open()) // если первый запуск (пусто)
	{
		number_of_accounts = 1;
	}// int n = _filelength(_fileno(file)) / sizeof(student);
	else
	{
		int kol = 0;
		while (!fin.eof()) // пока не достигнут конец файла 
		{
			fin >> temp; // считывание данных в переменную temp
			kol++;//подсчёт полей
		}
		number_of_accounts = kol / 4; //По 4 поля на аккаунт
	}
	fin.close(); // закрытие файла 
}

// Перенос аккаунтов из файла в массив
void readFileAccounts(Accounts* arr_of_accounts)
{
	ifstream fin("Accounts.txt", ios::in); // открытие файла для чтения данных
	if (!fin.is_open()) // если файла нет, идет создание аккаунта админа 
	{
		cout << " Аккаунт главного админинстратора: логин/пароль - admin\n";
		arr_of_accounts[0].login = "admin";
		arr_of_accounts[0].password = doHashNow("admin");
		arr_of_accounts[0].role = 2;
		arr_of_accounts[0].access = 1;
	}
	else
	{
		int i = 0; // обнуление переменной
		while (!fin.eof()) // пока не достигнут конец файла
		{
			fin >> arr_of_accounts[i].login >> arr_of_accounts[i].password >>
				arr_of_accounts[i].role >> arr_of_accounts[i].access; // считывание данных из файла в массив
			i++;
		}
	}
	fin.close(); // закрытие файла
}

// Запись аккаунтов в файл
void writeAccountsInFile(Accounts* arr_of_accounts, int number_of_accounts)
{
	ofstream fout("Accounts.txt", ios::out); // открытие файла для записи 
	for (int i = 0; i < number_of_accounts; i++)
	{
		fout << arr_of_accounts[i].login << " " << arr_of_accounts[i].password << " " 
			<< arr_of_accounts[i].role << " " << arr_of_accounts[i].access; // запись данных в файл
		if (i < number_of_accounts - 1) fout << endl; // endl пока не дойдем до последнего аккаунта
	}
	fout.close(); // закрытие файла
}

// Вывод аккаунтов
void showAccounts(Accounts* arr_of_accounts, int number_of_accounts)
{
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n|"
	<< "\t\t\t\t\tСписок аккаунтов                                                |\n"
	<< "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n|"
	<< " №   Логин" << setw(40) << "Пароль в виде хэша" << setw(40) << "Роль" << setw(15) << "Доступ |\n";
	for (int i = 0; i < number_of_accounts; i++)
		cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n| "
		<< i + 1 << ". " << arr_of_accounts[i].login << setw(50) << arr_of_accounts[i].password
		<< setw(30) << arr_of_accounts[i].role << setw(10) << arr_of_accounts[i].access << endl;
	cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n";

}

// Добавление аккаунта 
void addAccount(Accounts* arr_of_accounts, int& number_of_accounts)
{
	system("cls"); // очищение экрана консоли
	cout << "\nПроцесс регистрации";
	cout << "\n Введите логин: ";
	string temporary_login, temporary_password, repeat_temporary_password; // временные переменные
	bool flag_login = true, flag_password = true, flag_check_password = true; // флаги для регулирования циклов 
	cin >> temporary_login; // ввод временного логина
	int amount = 3, i; // количество попыток

	while (flag_login) // проверка, есть ли в базе такой логин 
	{
		int kol = 0;
		for (i = 0; i < number_of_accounts; i++)
			if (temporary_login != arr_of_accounts[i].login) 
				kol++;
			else // если найден такой же логин 
			{
				system("cls");
				cout << "\n Аккаунт с логином " << temporary_login << " уже существует!\n Введите другой логин!\n\t>>> ";
				cin >> temporary_login; // ввод логина заново 
				break;
			}
		
		if (kol == number_of_accounts)
			flag_login = false; // если ошибок нет, то меняем флаг для выхода из цикла
	}

	arr_of_accounts[number_of_accounts - 1].login = temporary_login; // запись логина; -1 так как индексация с 0 
	cout << "\nFAO:Пароль должен содержать 4 и более символов.\n";
	while (flag_password) // пока true; пароль
	{
		cout << " Введите пароль: ";
		temporary_password = inputPassword(); // ввод пароля 
		while (flag_check_password) //минимальное требование к паролю
			if (temporary_password.size() < 4) // если пароль меньше 4 символов, то выводим ошибку
			{
				cout << "\n\n Пароль меньше 4 символов!\n Повторите ввод: ";
				temporary_password = inputPassword(); // ввод пароля заново 
			}
			else
				flag_check_password = false; // если ошибок нет, то выходим из цикла 
		cout << "\n Введите пароль повторно: ";
		repeat_temporary_password = inputPassword(); // для повторного ввода пароля  
		if (temporary_password == repeat_temporary_password) // если пароли совпали 
		{
			arr_of_accounts[number_of_accounts - 1].password = doHashNow(temporary_password); // запись пароля 
			successSave();
			flag_password = false; // выход из цикла записи пароля 
		}
		else
			isfalsePassword(temporary_login, flag_password, amount); // в Signal; вывод ошибки, если несколько раз введен не тот пароль
	}
	arr_of_accounts[number_of_accounts - 1].role = 0; // роль - пользователь  
	arr_of_accounts[number_of_accounts - 1].access = 0; // аккаунт деактивирован 
}

// Изменение данных аккаунта
void changeAccounts(Accounts* arr_of_accounts, int number_of_accounts) // корректировки в аккаунтах; для админа 
{
	string temp_login; // строка для внесения логина
	bool flag = true;
	int i = 0, q = 1;
	cout << "\n Введите логин аккаунта, который хотите изменить: ";
	cin >> temp_login;

	while (flag && i < number_of_accounts) // цикл для поиска нужного аккаунта 
		if (temp_login == arr_of_accounts[i].login)
		{

			if (arr_of_accounts[i].role == 0)
			{
				flag = false;
			}
			else 
				if (arr_of_accounts[i].role == 1)
					{
						cout << " Для редактирования данных администратора требуется уровень доступа главного администратора"
							<<"\n Для подтверждения уровня доступа введите пароль главного администратора!\n\t>>> ";
						string pass;
						pass = inputPassword();
						if (doHashNow(pass) == arr_of_accounts[0].password) flag = false;
					}// если найден подходящий логин, flag меняется на false
				else if (arr_of_accounts[i].role == 2)
				{
					cout << "\n\t\tОшибка!\n У вас нет прав для этого действия!\nОбратитесь к системному администратору!";
					Sleep(2000);
					system("cls");
					q=0;
					break;
				}
		}
		else 
			i++; // пока не будет найден нужный аккаунт 

	if (flag) // если нет аккаунта 
		noAccount(); // вывод сообщения о том, что такого аккаунта нет в системе
	else // если аккаунт найден, спрашиваем, что нужно изменить
	{
		int kod;
		cout << "\nРедактирование данных аккаунта:"
		<< "\n 1. Изменить логин"
		<< "\n 2. Изменить пароль"
		<< "\n 3. Изменить роль"
		<< "\n 4. Изменить уровень доступа"
		<< "\n 0. Назад\n\t\t>>> ";

		protection(0, 4, kod); // защита от ввода букв и диапазон чисел от 0 до 4
		switch (kod)
		{
		case 1: // изменение логина 
			cout << "\n Введите новый логин: ";
			cin >> arr_of_accounts[i].login;
			cout << "\n\n Новый логин успешно сохранён!";
			Sleep(2000);
			system("cls");
			break;
		case 2: // изменение пароля 
			cout << "\n Введите новый пароль: ";
			cin >> arr_of_accounts[i].password;
			arr_of_accounts[i].password = doHashNow(arr_of_accounts[i].password);
			cout << "\n\n Новый пароль успешно сохранён!";
			Sleep(2000);
			system("cls");
			break;
		case 3: // изменение роли 
			if (arr_of_accounts[i].role == 1) // 1- администратор, 0 - пользователь 
			{
				arr_of_accounts[i].role = 0;
				cout << "\n Роль пользователя успешно изменена на пользователя!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
			else 
			{
				arr_of_accounts[i].role = 1; 
				cout << "\n Роль успешно изменена на администратора!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
		case 4: // изменение уровня доступа
			if (arr_of_accounts[i].access == 1) // если аккаунт активирован 
			{
				arr_of_accounts[i].access = 0; // деактивирация
				cout << "\n Аккаунт успешно деактивирован!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
			else // если аккаунт деактивирован
			{
				arr_of_accounts[i].access = 1; // активация 
				cout << "\n Аккаунт успешно активирован!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
		}
	}
}

// Меню
Accounts* menuLoginOrRegistration(Accounts* arr_of_accounts, int& number_of_accounts)
{
	int kod;
	bool flag = true;
	while (flag)
	{
		cout << "    Главное меню:"
		<< "\n 1. Вход в аккаунт"
		<< "\n 2. Регистрация"
		<< "\n 0. Выход\n\t>>> ";
		protection(0, 2, kod);
		switch (kod)
		{
		case 1: // вход в аккаунт 
			checkLoginPassword(arr_of_accounts, number_of_accounts); // проверка данных для входа 
			break;

		case 2: // регистрация аккаунта 
			arr_of_accounts = resizeOfArray(arr_of_accounts, number_of_accounts, number_of_accounts + 1); // перевыделение памяти
			addAccount(arr_of_accounts, number_of_accounts); // добавление аккаунта
			break;

		case 0:
			flag = false;
			break;
		}
	}
	return arr_of_accounts;
}

// Заходим в аккаунт
void checkLoginPassword(Accounts* arr_of_accounts, int& number_of_accounts)
{
	bool find_login = false, error_login = true, flag_password = true, flag = true;
	int login_index, amount = 3;
	string temp_login, temp_password;

	while (!find_login) // цикл для поиска логина 
	{
		cout << "\n Введите логин: ";
		cin >> temp_login; // ввод логина 
		for (int i = 0; i < number_of_accounts; i++)
			if (temp_login == arr_of_accounts[i].login) // если такой логин существует 
			{
				login_index = i; // запоминаем индекс 
				find_login = true; // выходим из цикла т.к. нашли логин
				error_login = false; // отключаем следующую запись
			}
		if (error_login) // если логин не найден
		{
			system("cls");
			amount--; // если ввели неверный логин, то уменьшаем количество попыток
			cout << "\n Аккаунт с логином " << temp_login << " не обнаружен!\n";
			cout << " Попыток осталось: " << amount << endl;

			if (amount == 0) // если значение 0, то выходим из цикла 
			{
				cout << "\n Количество ваших попыток равно нулю. Попробуйте позже.\n";
				Sleep(2000);
				system("cls");
				find_login = true;
				flag_password = false; // отключение следующего цикла
			}
		}
	}
	amount = 3; // обновляем количество попыток
	while (flag_password)
	{
		cout << " Введите пароль: ";
		temp_password = inputPassword(); // ввод пароля 
		if (doHashNow(temp_password) == arr_of_accounts[login_index].password) // если пароль подошел
		{
			if (arr_of_accounts[login_index].access) // если уровень доступа 1 (true), проверяем роль
				checkRole(arr_of_accounts, number_of_accounts, arr_of_accounts[login_index].role); // проверка роли (проверяем, кто зашел)
			else // если 0 (false), значит аккаунт деактивирован 
			{
				cout << "\n Ошибка! Данный аккаунт деактивирован. Ожидайте активации.\n\n";
				Sleep(2000);
				system("cls");
			}
			flag_password = false;
		}
		else // пароль не совпал 
			isfalsePassword(temp_login, flag_password, amount); // вывод ошибки, если несколько раз ввели неверный пароль
	}
}

// Ресайз массива
Accounts* resizeOfArray(Accounts* arr_of_accounts, int& number_of_accounts, int new_number_of_accounts) // m принимает значение на 1 больше 
{
	Accounts* temp_arr = new Accounts[new_number_of_accounts]; // выделение памяти

	for (int i = 0; i < number_of_accounts; i++)// перенос старых данных 
	{
		temp_arr[i].login = arr_of_accounts[i].login;
		temp_arr[i].password = arr_of_accounts[i].password;
		temp_arr[i].role = arr_of_accounts[i].role;
		temp_arr[i].access = arr_of_accounts[i].access;
	}

	delete[]arr_of_accounts; // удаление старого массива структур
	number_of_accounts = new_number_of_accounts; // обновление информации о количестве
	arr_of_accounts = temp_arr; // перенос информации 

	return arr_of_accounts; 
}

// Проверка роли пользователя
void checkRole(Accounts* arr_of_accounts, int& number_of_accounts, int role)
{
	switch (role)
	{
	case 0:
		system("cls");
		cout << " Вы авторизовались как пользователь.\n";
		userMenu(); // меню пользователя 
		break;
	case 1:
		system("cls");
		cout << " Вы авторизовались как администратор.\n\n";
		adminMenu(arr_of_accounts, number_of_accounts); // меню администратора
		break;
	case 2: 
		system("cls");
		cout << " Вы авторизовались как главный администратор.\n\n";
		adminMenu(arr_of_accounts, number_of_accounts); // меню администратора
		break;
	}

}

// Меню администратора
void adminMenu(Accounts* arr_of_accounts, int& number_of_accounts)
{
	int kod;
	bool flag = true;
	while (flag)
	{
		cout << "\tМеню администратора";
		cout << "\n 1. Работа с аккаунтами";
		cout << "\n 2. Работа с сотрудниками";
		cout << "\n 0. Выход из учетной записи\n\t>>> ";

		protection(0, 2, kod);
		switch (kod)
		{
		case 1: // работа с аккаунтами
			system("cls");
			adminMenuOfAdminAccounts(arr_of_accounts, number_of_accounts); // меню для управления аккаунтами 
			break;

		case 2: // работа с сотрудниками
			system("cls");
			userMenu();
			break;

		case 0:
			system("cls");
			flag = false; // выход из цикла
			break;
		}
	}

}

// Меню администратора, работа с аккаунтами
void adminMenuOfAdminAccounts(Accounts* arr_of_accounts, int& number_of_accounts)
{
	int kod;
	bool flag = true;
	while (flag)
	{
		system("cls");
		showAccounts(arr_of_accounts, number_of_accounts);
		cout << "\nРабота с аккаунтами:"
			//<<"\n 1. Добавить аккаунт"
		<< "\n 1. Редактировать данные аккаунта"
		<< "\n 2. Удалить аккаунт"
		<< "\n 0. Назад\n\t>>> ";

		protection(0, 2, kod);
		switch (kod)
		{
	/* case 1:
			arr_of_accounts = resizeOfArray(arr_of_accounts, number_of_accounts, number_of_accounts + 1); // перевыделение памяти
			newAccount(arr_of_accounts, number_of_accounts);
			break;
			*/
		case 1: // редактирование аккаунтов
			changeAccounts(arr_of_accounts, number_of_accounts);
			break;

		case 2: // удаление аккаунта
			delAccounts(arr_of_accounts, number_of_accounts);
			break;

		case 0: // выход из цикла while
			flag = false;
			system("cls");
			break;
		}
	}
}
/*
void newAccount(Accounts* arr_of_accounts, int& number_of_accounts) //без кол-ва попыток
{
	system("cls"); // очищение экрана консоли
	cout << "\nДобавление нового аккаунта администратором"
	<< "\n Введите логин: ";
	string temporary_login, temporary_password, repeat_temporary_password; // временные переменные
	bool flag_login = true, flag_password = true, flag_check_password = true; // флаги для регулирования циклов 
	cin >> temporary_login; // ввод временного логина
	int  i; 

	while (flag_login) // проверка, есть ли в базе такой логин 
	{
		int kol = 0;
		for (i = 0; i < number_of_accounts; i++)
			if (temporary_login != arr_of_accounts[i].login)
				kol++;
			else // если найден такой же логин 
			{
				system("cls");
				cout << "\n Аккаунт с логином " << temporary_login << " уже существует!\n Введите другой логин!\n\t>>> ";
				cin >> temporary_login; // ввод логина заново 
				break;
			}

		if (kol == number_of_accounts)
			flag_login = false; // если ошибок нет, то меняем флаг для выхода из цикла
	}
	arr_of_accounts[number_of_accounts - 1].login = temporary_login; // запись логина; -1 так как индексация с 0 
	cout << "\nFAO:Пароль должен содержать 4 и более символов.\n";
	while (flag_password) // пока true; пароль
	{
		cout << " Введите пароль: ";
		temporary_password = inputPassword(); // ввод пароля 
		while (flag_check_password) //минимальное требование к паролю
			if (temporary_password.size() < 4) // если пароль меньше 4 символов, то выводим ошибку
			{
				cout << "\n\n Пароль меньше 4 символов!\n Повторите ввод: ";
				temporary_password = inputPassword(); // ввод пароля заново 
			}
			else
				flag_check_password = false; // если ошибок нет, то выходим из цикла 
		cout << "\n Введите пароль повторно: ";
		repeat_temporary_password = inputPassword(); // для повторного ввода пароля  
		if (temporary_password == repeat_temporary_password) // если пароли совпали 
		{
			arr_of_accounts[number_of_accounts - 1].password = doHashNow(temporary_password); // запись пароля 
			successSave();
			flag_password = false; // выход из цикла записи пароля 
		}
		else
		{
			 // в Signal; вывод ошибки, если несколько раз введен не тот пароль
			system("cls");
			cout << "\n Неверный пароль!";
			cout << "\n\n Логин: " << temporary_login;
			if (0 == 0)
			{
				cout <<"\n Вы превысили количество допустимых попыток!Повторите позже.\n";
				Sleep(2000);
				system("cls");
				flag_password = false; // возвращаем значение false, чтобы остановить цикл
			}
		}
		
	}
	cout << "Введите роль аккаунта:\n1 - администратор\t0 - пользователь\n\t>>> ";
	protection(0,1, arr_of_accounts[number_of_accounts - 1].role);
	cout << "Введите уровень доступа\n1 - может войти в систему\t0 - аккаунт деативирован\n\t>>> ";
	protection(0, 1, arr_of_accounts[number_of_accounts - 1].access);
}
*/
// Удаление аккаунта
void delAccounts(Accounts* arr_of_accounts, int& number_of_accounts)
{
	string login_for_deleting; // для логина аккаунта, который хотим удалить 
	cout << "\n Введите логин аккаунта, который хотите удалить: ";
	cin >> login_for_deleting;
	int i = 0, del = 0;
	bool flag = true;

	while (flag && i < number_of_accounts)
	{
		if (arr_of_accounts[i].login == login_for_deleting) // поиск аккаунта 
			flag = false; // если аккаунт найден, то выходим из цикла 
		else
			i++;
	}

	if (flag) // если аккаунта нет 
		noAccount();
	else // если аккаунт существует
	{
		if (arr_of_accounts[i].role == 2) // защита от удаления аккаунта админа 
		{
			cout << "\n\t\tОшибка!\n У вас нет прав для этого действия!\nОбратитесь к системному администратору!";
			Sleep(2000);
			system("cls"); 
		}
		else if (arr_of_accounts[i].role == 1)
		{
			cout << "Для подтверждения уровня доступа введите пароль главного администратора!\n\t>>> ";
			string pass;
			pass = inputPassword();
			if (doHashNow(pass) == arr_of_accounts[0].password)
			{
				cout << " Вы действительно хотите удалить аккаунт " << arr_of_accounts[i].login << "?\n"
					<< " Удаленные данные не подлежат восстановлению!\n"
					<< " 1 - да" << "\n 2 - нет" << "\n\t>>>: ";
				protection(1, 2, del);
				if (del == 1)
				{
					for (int j = i; j < number_of_accounts - 1; j++) // i - номер аккаунта; cмещение в конец удаленного аккаунта
						arr_of_accounts[j] = arr_of_accounts[j + 1];
					number_of_accounts--; // уменьшение количества аккаунтов 
					successSave();
				}
				else
					cout << " Удаление отменено!\n";
			}
			else
			{
				cout << "\n\t\tОшибка!\n Пароль неверен!\nОбратитесь к системному администратору!";
				Sleep(2000);
				system("cls");
			}
		}
		else
		{
			cout << " Вы действительно хотите удалить аккаунт " << arr_of_accounts[i].login << "?\n"
				<< " Удаленные данные не подлежат восстановлению!\n"
				<< " 1 - да" << "\n 2 - нет" << "\n\t>>>: ";
			protection(1, 2, del);
			if (del == 1)
			{
				for (int j = i; j < number_of_accounts - 1; j++) // i - номер аккаунта; cмещение в конец удаленного аккаунта
					arr_of_accounts[j] = arr_of_accounts[j + 1];
				number_of_accounts--; // уменьшение количества аккаунтов 
				successSave();
			}
			else
				cout << " Удаление отменено!\n";
		}
	}
}