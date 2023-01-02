#include "Employees.h"
#include "Protection.h"
#include "Signal.h"

// структура работников:  Ф.И.О., отдел, должность, зарплата 
// структура отделов: отдел, количество сотрудников, общая зарплата
// индивидуальное задание: сумма выплат по отделам, средняя зарплата по отделам, вывод сотрудников с зарплатой, ниже введенной

// Меню пользователя
void userMenu()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int number_of_employees = 0;
	getNumberOfEmployeesInFile(number_of_employees); // определение количества сотрудников в файле
	Employees* arr_of_employees = new Employees[number_of_employees]; // выделение памяти для массива структур
	readFileEmployees(arr_of_employees, number_of_employees); // перенос сотрудников из файла в массив 
	arr_of_employees = menuEmployees(arr_of_employees, number_of_employees); // меню сотрудников
	writeFileEmployees(arr_of_employees, number_of_employees); // запись новых данных о в файл
	delete[] arr_of_employees; // очистка динамической памяти
}

// Определение кол-ва сотрудников в файле
void getNumberOfEmployeesInFile(int& number_of_employees)
{
	string temp; // временная переменная для считывания данных
	int kol = 0;
	ifstream fin("Employees.txt", ios::in); // открытие файла для чтения данных
	if (!fin.is_open()) // если файл не создан
		number_of_employees = 1;
	else
	{
		while (!fin.eof()) // пока не достигнут конец файла 
		{
			fin >> temp; // считывание данных по одному полю
			kol++; 
		}
	}
	number_of_employees = kol / 6; //к структуре относятся 6 поля
	fin.close(); // закрытие файла
}

// Перенов данных из файла в массив структур
void readFileEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	ifstream fin("Employees.txt", ios::in); // открытие файла для чтения данных
	if (!fin.is_open()) // если пусто 
	{
		cout << " \nСписок сотрудников пуст!\nДля работы необходимо добавить хотя бы одного!";
		Sleep(2000);
	}
	else // если в файле уже есть сотрудники
	{
		int i = 0;
		while (!fin.eof()) // пока не достигнут конец файла 
		{
			fin >> arr_of_employees[i].name >> arr_of_employees[i].surname >> arr_of_employees[i].patronymic >>
				arr_of_employees[i].department >> arr_of_employees[i].post >> arr_of_employees[i].salary; // считывание данных из файла в массив
			i++;
		}
	}
	fin.close(); // закрытие файла
}

// Запись данных в файл
void writeFileEmployees(Employees* arr_of_employees, int number_of_employees)
{
	ofstream fout("Employees.txt", ios::out); // открытие файла для записи
	for (int i = 0; i < number_of_employees; i++)
	{
		fout << arr_of_employees[i].name << " " << arr_of_employees[i].surname << " " << arr_of_employees[i].patronymic << " " <<
			arr_of_employees[i].department << " " << arr_of_employees[i].post << " " << arr_of_employees[i].salary; // запись данных в файл
		if (i < number_of_employees - 1) // endl пока не дойдем до последнего сотрудника 
			fout << endl;
	}
	fout.close(); // закрытие файла
}

// Меню работы с сотрудниками 
Employees* menuEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	bool flag = true; // для остановки цикла 
	while (flag)
	{
		system("cls");
		showEmployees(arr_of_employees, number_of_employees);
		cout << "\n\n\tРабота с сотрудниками:\n"
			<< " 1. Добавить сотрудников\n"
			<< " 2. Редактировать информацию о сотруднике\n"
			<< " 3. Удалить сотрудника\n"
			<< " 4. Индивидуальное задание\n"
			<< " 5. Сортировка данных\n"
			<< " 6. Поиск\n"
			<< " 0. Назад\n\t>>> ";
		int kod;
		protection(0, 6, kod); // защита от ввода букв и диапазон от 0 до 6
		switch (kod)
		{
		case 1: // добавление новых сотрудников 
			int kol;
			cout << "Сколких сотрудников вы желаете добавить?\n";
			protection(1, 5, kol); // защита от ввода букв, диапазон от 1 до 5
			while (kol != 0)
			{ 
				cout << "Добавление нового сотрудника:\n";
				arr_of_employees = reallocationForEmployees(arr_of_employees, number_of_employees, number_of_employees + 1); // перераспределение памяти, т.к. мы добавляем сотрудников 
				addEmployees(arr_of_employees, number_of_employees); // функция добавления
				kol--; 
				//!выход на любом этапе
			}
			break;
		case 2: // редактирование информации о сотрудниках 
			editEmployees(arr_of_employees, number_of_employees);
			break;
		case 3: // удаление 
			delEmployees(arr_of_employees, number_of_employees);
			break;
		case 4: // индивидуальное задание
			menuIndTask(arr_of_employees, number_of_employees);
			break;
		case 5: // cортировка 
			arr_of_employees = menuSortEmployees(arr_of_employees, number_of_employees);
			break;
		case 6: // поиск
			menuFindEmployees(arr_of_employees, number_of_employees);
			break;
		case 0:
			system("cls");
			flag = false;
			break;
		}
	}
	return arr_of_employees;

}

// Вывод списка сотрудников
void showEmployees(Employees* arr_of_employees, int number_of_employees)
{
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n| "
	<< "\t\t\t\t\t\tСписок сотрудников                                            |\n"
	<< "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n| "
	<< "№  Фамилия" << setw(20) << "Имя" << setw(20) << "Отчество" << setw(20) << "Отдел" << setw(20) << "Должность" << setw(20) << "Зарплата |\n";

	for (int i = 0; i < number_of_employees; i++)
	{
		cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n| "
		<< i+1 << ". " << arr_of_employees[i].surname <<
			setw(20) << arr_of_employees[i].name <<
			setw(20) << arr_of_employees[i].patronymic <<
			setw(20) << arr_of_employees[i].department <<
			setw(20) << arr_of_employees[i].post <<
			setw(15) << arr_of_employees[i].salary << endl;
	}
	cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n";
}

// Ресайз массива 
Employees* reallocationForEmployees(Employees* arr_of_employees, int& number_of_employees, int m)
{
	Employees* temp_arr = new Employees[m]; // выделение памяти под массив структур 
	for (int i = 0; i < number_of_employees; i++) // перенос старых данных
	{
		temp_arr[i].name = arr_of_employees[i].name;
		temp_arr[i].surname = arr_of_employees[i].surname;
		temp_arr[i].patronymic = arr_of_employees[i].patronymic;
		temp_arr[i].department = arr_of_employees[i].department;
		temp_arr[i].post = arr_of_employees[i].post;
		temp_arr[i].salary = arr_of_employees[i].salary;
	}
	delete[]arr_of_employees; // удаление старых данных 
	number_of_employees = m; // обновление количества сотрудников 
	arr_of_employees = temp_arr; // перенос информации 
	return arr_of_employees;
}

// Добавление нового сотрудника
void addEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	cout << "\nДобавление нового сотрудника\n";
	cout << " Введите фамилию: ";
	cin >> arr_of_employees[number_of_employees - 1].surname;
	cout << " Введите имя: ";
	cin >> arr_of_employees[number_of_employees - 1].name;
	cout << " Введите отчество: ";
	cin >> arr_of_employees[number_of_employees - 1].patronymic;
	cout << " Введите отдел: ";
	cin >> arr_of_employees[number_of_employees - 1].department;
	cout << " Введите должность: ";
	cin >> arr_of_employees[number_of_employees - 1].post;
	cout << " Введите зарплату: ";
	protection(0, 10000, arr_of_employees[number_of_employees - 1].salary);
	successSave();
}

// Редактирование информации о сотруднике
void editEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	system("cls");
	showEmployees(arr_of_employees, number_of_employees); // вывод сотрудников на экран
	string temp; // временная строка для фамилии 
	bool flag = true;
	int i = 0;
	cout << "\n Введите фамилию сотрудника, чьи данные хотите изменить: ";
	cin >> temp;
	while (flag && i < number_of_employees) // цикл для поиска фамилии (пока true и пока не перебрали всех сотрудников)
		if (temp == arr_of_employees[i].surname) // если найдено совпадение, цикл останавливается 
			flag = false;
		else i++;// иначе поиск продолжается 
	if (flag) // если совпадений не найдено 
		noAccount(); // вывод сообщения о том, что учетной записи с такой фамилией нет
	else // если найдено совпадение, то после цикла while спрашивается, что нужно изменить 
	{
		cout << "\nРедактирование данных о сотруднике\n"
		<< " 1. Изменить фамилию\n"
		<< " 2. Изменить имя\n"
		<< " 3. Изменить отчество\n"
		<< " 4. Изменить отдел\n"
		<< " 5. Изменить должность\n"
		<< " 6. Изменить зарплату\n"
		<< " 0. Назад\n\t>>> ";

		int kod;
		protection(0, 6, kod);
		switch (kod)
		{
		case 1:
			cout << "\nВведите новую фамилию сотрудника: ";
			cin >> arr_of_employees[i].surname;
			successSave();
			break;
		case 2:
			cout << "\nВведите новое имя сотрудника: ";
			cin >> arr_of_employees[i].name;
			successSave();
			break;
		case 3:
			cout << "\nВведите новое отчество сотрудника: ";
			cin >> arr_of_employees[i].patronymic;
			successSave();
			break;
		case 4:
			cout << "\nВведите новый отдел сотрудника: ";
			cin >> arr_of_employees[i].department;
			successSave();
			break;
		case 5:
			cout << "\nВведите новую должность сотрудника: ";
			cin >> arr_of_employees[i].post;
			successSave();
			break;
		case 6:
			cout << "\nВведите новую зарплату сотрудника: ";
			protection(0, 10000, arr_of_employees[i].salary);
			successSave();
			break;
		case 0:  
			break;
		}
	}
}

// Удаление сотрудника
void delEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	string surname_for_delete;
	cout << "\nВведите фамилию сотрудника, которого хотите удалить: ";
	cin >> surname_for_delete;
	int i = 0;
	bool flag = true;
	while (flag && i < number_of_employees) // цикл для поиска нужного аккаунта 
		if (arr_of_employees[i].surname == surname_for_delete)
			flag = false; // eсли аккаунт найден, флаг изменяется и цикл останавливается 
		else // если нет, поиск продолжается
			i++;

	if (flag) // если аккаунт не найден 
		noAccount(); // вывод сообщения о том, что такой учетной записи нет
	else // если аккаунт найден 
	{
		int del = 0;
		cout << " Вы действительно хотите удалить сотрудника с фамилией " << arr_of_employees[i].surname << "?" << endl;
		cout << " Удаленные данные не подлежат восстановлению!\n";
		cout << " 1 - да\n 2 - нет\n\t>>> ";
		protection(1, 2, del);
		if (del == 1)
		{
			for (int j = i; j < number_of_employees - 1; j++) // i - номер аккаунта, смещение в конец удаленного аккаунта
				arr_of_employees[j] = arr_of_employees[j + 1];
			number_of_employees--; // уменьшение количества сотрудников
			successSave();
		}
		else
			cout << " Удаление отменено\n";
	}
}


//Индивидуальное задание
void menuIndTask(Employees* arr_of_employees, int number_of_employees)
{
	cout << "\nИндивидуальное задание\n";
	cout << " 1. Сотрудники с зарплатой < введенной\n";
	cout << " 2. Информация по отделам\n";
	cout << " 0. Назад\n\t>>> ";

	int kod;
	protection(0, 2, kod);
	switch (kod)
	{
	case 1:
		indTaskLessSalary(arr_of_employees, number_of_employees); 
		system("pause");
		break;
	case 2:
		indTaskDepartments(arr_of_employees, number_of_employees); 
		system("pause");
		break;
	case 0:
		break;
	}
}

// ИНД.1: Вывод сотрудников с зарплатой < введённой
void indTaskLessSalary(Employees* arr_of_employees, int number_of_employees) // c зарплатой, меньше указанной 
{
	cout << "\nВведите зарплату: ";
	int salary, kol = 1;
	protection(0,10001,salary);
	cout << "\nВывод сотрудников с зарплатой < введённой:\n";

	for (int i = 0; i < number_of_employees; i++)
		if (arr_of_employees[i].salary < salary) // если зарплата меньше введенной, то выводится информация о сотруднике 
		{
			cout << "\n" << kol << "-й сотрудник:";
			showFind(arr_of_employees, number_of_employees, i);
			kol++;
		}
}

// ИНД.2: Информация по отделам: общая и средняя зарплата 
void indTaskDepartments(Employees* arr_of_employees, int number_of_employees)
{
	system("cls");
	int number_of_departments = 0, i = 0 , j, same = 0;
	string department_names[20]; // выделение памяти
	department_names[0] = arr_of_employees[0].department;
	while (i != number_of_employees)
	{
		for (i = 0; i < number_of_employees; i++)
		{ 
			same = 0;
			for (j = 0; j <= number_of_departments; j++)
				if (department_names[j] == arr_of_employees[i].department)
					same++;
			if (same == 0)
			{
				number_of_departments++;
				department_names[number_of_departments] = arr_of_employees[i].department;
			//	cout << "\t" << department_names[number_of_departments] << "\t\n";
				break;
			}
		}
	}
	number_of_departments++;
	department_names[number_of_departments] = arr_of_employees[i-1].department;
	cout << "\nКоличество отделов - \t" << number_of_departments << "\n";
	Departments* arr_of_departments = new Departments[number_of_departments + 1];
	for (j = 0; j <= number_of_departments; j++)
		arr_of_departments[j].Name = department_names[j];
	for (i = 0; i < number_of_employees; i++)
		for (j = 0; j < number_of_departments; j++)
			if (arr_of_departments[j].Name == arr_of_employees[i].department)
			{
				arr_of_departments[j].Employees++;
				arr_of_departments[j].TotalSalary += arr_of_employees[i].salary;
			}
	for (i = 0; i < number_of_departments; i++)
	{
		cout << " Отдел: " << arr_of_departments[i].Name
			<< "\n Сотрудников в отделе: " << arr_of_departments[i].Employees
			<< "\n Суммарная зарплата сотрудников: " << arr_of_departments[i].TotalSalary
			<< "\n Средняя зарплата: " << double(arr_of_departments[i].TotalSalary / arr_of_departments[i].Employees) << "\n\n";
	}
	delete[]arr_of_departments; // удаление информации после использования 
}

// ИНД.2: Ресайз массива структур 
Departments* indTask_Resize(Departments* arr_of_departments, int& number_of_departments, int m)
{

	Departments* temp_arr = new Departments[m];
	for (int i = 0; i < number_of_departments,i<m; i++) // перенос информации
	{
		temp_arr[i].Name = arr_of_departments[i].Name;
		temp_arr[i].Employees = arr_of_departments[i].Employees;
		temp_arr[i].TotalSalary = arr_of_departments[i].TotalSalary;
	}

	delete[]arr_of_departments; // удаление старого массива 
	number_of_departments = m; // обновление размера  
	arr_of_departments = temp_arr; // перенос информации
	return arr_of_departments; // возвращение обновленных данных
}

// Выбор сортировки 
Employees* menuSortEmployees(Employees* arr_of_employees, int number_of_employees)
{
	int kod;
	cout << "\nМеню выбора сортировки:\n"
	<< "\n 1. Отсортировать по фамилии"
	<< "\n 2. Отсортировать по отделу"
	<< "\n 3. Отсортировать по зарплате"
	<< "\n 0. Назад\n\t>>> ";

	protection(0, 3, kod);
	switch (kod)
	{
	case 1: 
		arr_of_employees = sortSurname(arr_of_employees, number_of_employees); 
		break;
	case 2: 
		arr_of_employees = sortDepartment(arr_of_employees, number_of_employees); 
		break;
	case 3: 
		arr_of_employees = sortSalary(arr_of_employees, number_of_employees); 
		break;
	case 0:
		break;
	}
	return arr_of_employees;
}

// Сортировка по фамилии
Employees* sortSurname(Employees* arr_of_employees, int number_of_employees)
{
	Employees* temp_arr = new Employees[number_of_employees]; // выделение памяти 
	for (int i = 0; i < number_of_employees; i++) // перенос информации
	{
		temp_arr[i].name = arr_of_employees[i].name;
		temp_arr[i].surname = arr_of_employees[i].surname;
		temp_arr[i].patronymic = arr_of_employees[i].patronymic;
		temp_arr[i].department = arr_of_employees[i].department;
		temp_arr[i].post = arr_of_employees[i].post;
		temp_arr[i].salary = arr_of_employees[i].salary;

	}
	cout << "\nСортировка по фамилии\n";

	for (int i = 0; i < number_of_employees - 1; i++)  // сортировка от А до Я 
		for (int j = 0; j < number_of_employees - i - 1; j++) // отступаем на один шаг 
			if (temp_arr[j].surname > temp_arr[j + 1].surname) // сравнение по ASCII
				swap(temp_arr[j], temp_arr[j + 1]); // меняет местами
	//strcmp(temp_arr[j].surname.c_str(), temp_arr[j + 1].surname.c_str()) > 0);
	showEmployees(temp_arr, number_of_employees); // вывод сотрудников

	int temp; // временная переменная 
	canISaveNow(); // сохранять? 

	protection(1, 2, temp);
	switch (temp)
	{
	case 1: // сохранение (обновление старого массива) 
		delete[]arr_of_employees;
		arr_of_employees = temp_arr;
		break;
	case 2: // не сохранять 
		delete[] temp_arr; // удаление отсортированнвого массива 
		break;
	}
	return arr_of_employees;
}

// Сортировка по отделу
Employees* sortDepartment(Employees* arr_of_employees, int number_of_employees)
{

	Employees* arr_new = new Employees[number_of_employees];
	for (int i = 0; i < number_of_employees; i++)
	{
		arr_new[i].name = arr_of_employees[i].name;
		arr_new[i].surname = arr_of_employees[i].surname;
		arr_new[i].patronymic = arr_of_employees[i].patronymic;
		arr_new[i].department = arr_of_employees[i].department;
		arr_new[i].post = arr_of_employees[i].post;
		arr_new[i].salary = arr_of_employees[i].salary;

	}

	cout << "\n Сортировка по отделу:\n";

	for (int i = 0; i < number_of_employees - 1; i++) // для пользователя 1-ый сотрудинк, но в массиве 0, сортировка от А до Я
		for (int j = 0; j < number_of_employees - i - 1; j++)
			if (arr_new[j].department > arr_new[j + 1].department) // ASCII 
				swap(arr_new[j], arr_new[j + 1]);

	showEmployees(arr_new, number_of_employees);

	int temp;
	canISaveNow();

	protection(1, 2, temp);
	switch (temp)
	{
	case 1:
		delete[]arr_of_employees;
		arr_of_employees = arr_new;
		break;
	case 2:
		delete[] arr_new;
		break;
	}
	return arr_of_employees;
}

// Сортировка по зарплате
Employees* sortSalary(Employees* arr_of_employees, int number_of_employees)
{

	Employees* arr_new = new Employees[number_of_employees];
	for (int i = 0; i < number_of_employees; i++)
	{
		arr_new[i].name = arr_of_employees[i].name;
		arr_new[i].surname = arr_of_employees[i].surname;
		arr_new[i].patronymic = arr_of_employees[i].patronymic;
		arr_new[i].department = arr_of_employees[i].department;
		arr_new[i].post = arr_of_employees[i].post;
		arr_new[i].salary = arr_of_employees[i].salary;

	}

	cout << "\n Сортировка по зарплате\n\n";
	for (int i = 0; i < number_of_employees - 1; i++) // от меньшей к большей (по возрастанию) 
		for (int j = 0; j < number_of_employees - i - 1; j++)
			if (arr_new[j].salary > arr_new[j + 1].salary)
				swap(arr_new[j], arr_new[j + 1]);

	showEmployees(arr_new, number_of_employees);

	int temp;
	canISaveNow();

	protection(1, 2, temp);
	switch (temp)
	{
	case 1:
		successSave();
		delete[]arr_of_employees;
		arr_of_employees = arr_new;
		break;
	case 2:
		delete[] arr_new;
		successSave();
		break;
	}
	return arr_of_employees;
}


// Поиск 
void menuFindEmployees(Employees* arr_of_employees, int number_of_employees)
{
	cout << "\n\tПоиск информации\n"
	<< "\n 1. Найти по фамилии"
	<< "\n 2. Найти по должности"
	<< "\n 3. Найти сотрудника с максимальной зарплатой"
	<< "\n 0. Назад\n\t>>> ";

	int kod;
	protection(0, 3, kod);

	switch (kod)
	{
	case 1: 
		findSurname(arr_of_employees, number_of_employees); 
		break; // поиск по фамилии
	case 2: 
		findPosition(arr_of_employees, number_of_employees); 
		break; // поиск по должности 
	case 3: 
		findMaxSalary(arr_of_employees, number_of_employees); 
		break; // поиск по максимальной зарплате 
	case 0: 
		break; // выход 
	}
}

// Поиск по фамилии
void findSurname(Employees* arr_of_employees, int number_of_employees)
{
	string FindSurname; // строка для ввода фамилии  
	bool flag = true;
	cout << "\n\tПоиск сотрудников по фамилии\n";
	cout << "\n Введите фамилию для поиска: ";
	cin >> FindSurname;
	for (int i = 0; i < number_of_employees; i++)
		if (FindSurname == arr_of_employees[i].surname) // если фамилия найдена, то вывод 
		{
			showFind(arr_of_employees, number_of_employees, i);
			flag = false; // отключение следующего if
		}
	if (flag)
		noAccount(); // вывод сообщения, что такой фамилии нет в системе
}

// Поиск по должности
void findPosition(Employees* arr_of_employees, int number_of_employees)
{
	string SearchPosition; // строка для ввода должности 
	cout << "\n\tПоиск сотрудников по должности\n";
	cout << "\n Введите должность для поиска: ";
	cin >> SearchPosition;
	bool flag = true;
	for (int i = 0; i < number_of_employees; i++)
		if (arr_of_employees[i].post == SearchPosition)
		{
			showFind(arr_of_employees, number_of_employees, i);
			flag = false;
		}
	if (flag)
		noAccount();
}

// Поиск по максимальной зарплате
void findMaxSalary(Employees* arr_of_employees, int number_of_employees)
{
	cout << "\n\tПоиск сотрудника с наибольшей зарплатой\n";
	int maxSalary = 0;
	for (int i = 0; i < number_of_employees; i++)

		if (maxSalary < arr_of_employees[i].salary) // если найдена зарплата больше 
			maxSalary = arr_of_employees[i].salary; // то значение переменной обновляется
	for (int i = 0; i < number_of_employees; i++) // какой сотрудник имеет это зарплату
		if (arr_of_employees[i].salary == maxSalary) // зарплата сотрудника сверяется с максимальным значением
			showFind(arr_of_employees, number_of_employees, i); // вывод

}

// Вывод информации о сотруднике
void showFind(Employees* arr_of_employees, int number_of_employees, int i)
{
	cout << "\n Ф.И.О.: " << arr_of_employees[i].surname << " " << arr_of_employees[i].name << " " << arr_of_employees[i].patronymic
	<< "\n Отдел: " << arr_of_employees[i].department << "\n Должность: " << arr_of_employees[i].post << "\n Зарплата: " << arr_of_employees[i].salary << "\n";
}