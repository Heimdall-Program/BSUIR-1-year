#pragma once // ������ �� �������� ����������� ������������ ������
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
	string post; //���������
	int salary;
};

struct Departments
{
	string Name; 
	int Employees = 0;
	int TotalSalary = 0;
	double averageSalary = 0;
};

// ������ � ����� ������ ����������
void userMenu(); // ���� ������������ 
void getNumberOfEmployeesInFile(int&); // ����������� ���������� ����������� � �����
void readFileEmployees(Employees*, int&); // ������ (�������) ��������� �� ����� � ������
void writeFileEmployees(Employees*, int); // ������ ����������� � ����
Employees* menuEmployees(Employees*, int&); // ���� �����������
void showEmployees(Employees*, int); // ����� ����������� �� ����� 
Employees* reallocationForEmployees(Employees*, int&, int); // ������������� ������		
void addEmployees(Employees*, int&); // ���������� �����������
void editEmployees(Employees*, int&); // �������������� ���������� � �����������
void delEmployees(Employees*, int&); // �������� ����������� 

// ������������� �������
void menuIndTask(Employees*, int); // ����� ��������������� �������
void indTaskLessSalary(Employees*, int); // ���.1:  ����� ����������� � ���������, ������ ��������� � ����������
void indTaskDepartments(Employees*, int); // ���.2: ���������� �� �������: ����� ��������, ������� ��������
Departments* indTask_Resize(Departments*, int&, int); // ���.2 - ������������� ������ 

// ����������
Employees* menuSortEmployees(Employees*, int); // ����� ����������
Employees* sortSurname(Employees*, int); // ���������� �� �������� 
Employees* sortDepartment(Employees*, int); // ���������� �� �������
Employees* sortSalary(Employees*, int); // ���������� �� ��������

// ����� ����������
void menuFindEmployees(Employees*, int); // ����� ������
void findSurname(Employees*, int); // ����� �� �������
void findPosition(Employees*, int); // ����� �� ���������
void findMaxSalary(Employees*, int); // ����� �� ������������ ��������
void showFind(Employees*, int, int); // ������� ������ ������
