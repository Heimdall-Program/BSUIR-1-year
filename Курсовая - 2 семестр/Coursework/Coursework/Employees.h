#pragma once // защита от двойного подключения заголовочных файлов
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


struct Employees 
{
	struct {
		string name;
		string surname;
		string patronymic;
	};
	string department;
	string post; //должность
	int salary;
};

struct Departments
{
	string Name; 
	int Employees = 0;
	int TotalSalary = 0;
	double averageSalary = 0;
};

// Работа с базой данных сотруников
void userMenu(); // меню пользователя 
void getNumberOfEmployeesInFile(int&); // определение количества сотрудников в файле
void readFileEmployees(Employees*, int&); // чтение (перенос) аккаунтов из файла в массив
void writeFileEmployees(Employees*, int); // запись сотрудников в файл
Employees* menuEmployees(Employees*, int&); // меню сотрудников
void showEmployees(Employees*, int); // вывод сотрудников на экран 
Employees* reallocationForEmployees(Employees*, int&, int); // перевыделение памяти		
void addEmployees(Employees*, int&); // добавление сотрудников
void editEmployees(Employees*, int&); // редактирование информации о сотрудниках
void delEmployees(Employees*, int&); // удаление сотрудников 

// Индивидуалное заданеи
void menuIndTask(Employees*, int); // выбор индивидуального задания
void indTaskLessSalary(Employees*, int); // инд.1:  вывод сотрудников с зарплатой, меньше введенной с клавиатуры
void indTaskDepartments(Employees*, int); // инд.2: информация по отделам: общая зарплата, средняя зарплата
Departments* indTask_Resize(Departments*, int&, int); // инд.2 - перевыделение памяти 

// Сортировки
Employees* menuSortEmployees(Employees*, int); // выбор сортировки
Employees* sortSurname(Employees*, int); // сортировка по фамилиям 
Employees* sortDepartment(Employees*, int); // сортировка по отделам
Employees* sortSalary(Employees*, int); // сортировка по зарплате

// Поиск информации
void menuFindEmployees(Employees*, int); // выбор поиска
void findSurname(Employees*, int); // поиск по фамилии
void findPosition(Employees*, int); // поиск по должности
void findMaxSalary(Employees*, int); // поиск по максимальной зарплате
void showFind(Employees*, int, int); // функция вывода поиска
