#include "Employees.h"
#include "Protection.h"
#include "Signal.h"

// ��������� ����������:  �.�.�., �����, ���������, �������� 
// ��������� �������: �����, ���������� �����������, ����� ��������
// �������������� �������: ����� ������ �� �������, ������� �������� �� �������, ����� ����������� � ���������, ���� ���������

// ���� ������������
void userMenu()
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
	int number_of_employees = 0;
	getNumberOfEmployeesInFile(number_of_employees); // ����������� ���������� ����������� � �����
	Employees* arr_of_employees = new Employees[number_of_employees]; // ��������� ������ ��� ������� ��������
	readFileEmployees(arr_of_employees, number_of_employees); // ������� ����������� �� ����� � ������ 
	arr_of_employees = menuEmployees(arr_of_employees, number_of_employees); // ���� �����������
	writeFileEmployees(arr_of_employees, number_of_employees); // ������ ����� ������ � � ����
	delete[] arr_of_employees; // ������� ������������ ������
}

// ����������� ���-�� ����������� � �����
void getNumberOfEmployeesInFile(int& number_of_employees)
{
	string temp; // ��������� ���������� ��� ���������� ������
	int kol = 0;
	ifstream fin("Employees.txt", ios::in); // �������� ����� ��� ������ ������
	if (!fin.is_open()) // ���� ���� �� ������
		number_of_employees = 1;
	else
	{
		while (!fin.eof()) // ���� �� ��������� ����� ����� 
		{
			fin >> temp; // ���������� ������ �� ������ ����
			kol++; 
		}
	}
	number_of_employees = kol / 6; //� ��������� ��������� 6 ����
	fin.close(); // �������� �����
}

// ������� ������ �� ����� � ������ ��������
void readFileEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	ifstream fin("Employees.txt", ios::in); // �������� ����� ��� ������ ������
	if (!fin.is_open()) // ���� ����� 
	{
		cout << " \n������ ����������� ����!\n��� ������ ���������� �������� ���� �� ������!";
		Sleep(2000);
	}
	else // ���� � ����� ��� ���� ����������
	{
		int i = 0;
		while (!fin.eof()) // ���� �� ��������� ����� ����� 
		{
			fin >> arr_of_employees[i].name >> arr_of_employees[i].surname >> arr_of_employees[i].patronymic >>
				arr_of_employees[i].department >> arr_of_employees[i].post >> arr_of_employees[i].salary; // ���������� ������ �� ����� � ������
			i++;
		}
	}
	fin.close(); // �������� �����
}

// ������ ������ � ����
void writeFileEmployees(Employees* arr_of_employees, int number_of_employees)
{
	ofstream fout("Employees.txt", ios::out); // �������� ����� ��� ������
	for (int i = 0; i < number_of_employees; i++)
	{
		fout << arr_of_employees[i].name << " " << arr_of_employees[i].surname << " " << arr_of_employees[i].patronymic << " " <<
			arr_of_employees[i].department << " " << arr_of_employees[i].post << " " << arr_of_employees[i].salary; // ������ ������ � ����
		if (i < number_of_employees - 1) // endl ���� �� ������ �� ���������� ���������� 
			fout << endl;
	}
	fout.close(); // �������� �����
}

// ���� ������ � ������������ 
Employees* menuEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	bool flag = true; // ��� ��������� ����� 
	while (flag)
	{
		system("cls");
		showEmployees(arr_of_employees, number_of_employees);
		cout << "\n\n\t������ � ������������:\n"
			<< " 1. �������� �����������\n"
			<< " 2. ������������� ���������� � ����������\n"
			<< " 3. ������� ����������\n"
			<< " 4. �������������� �������\n"
			<< " 5. ���������� ������\n"
			<< " 6. �����\n"
			<< " 0. �����\n\t>>> ";
		int kod;
		protection(0, 6, kod); // ������ �� ����� ���� � �������� �� 0 �� 6
		switch (kod)
		{
		case 1: // ���������� ����� ����������� 
			int kol;
			cout << "������� ����������� �� ������� ��������?\n";
			protection(1, 5, kol); // ������ �� ����� ����, �������� �� 1 �� 5
			while (kol != 0)
			{ 
				cout << "���������� ������ ����������:\n";
				arr_of_employees = reallocationForEmployees(arr_of_employees, number_of_employees, number_of_employees + 1); // ����������������� ������, �.�. �� ��������� ����������� 
				addEmployees(arr_of_employees, number_of_employees); // ������� ����������
				kol--; 
				//!����� �� ����� �����
			}
			break;
		case 2: // �������������� ���������� � ����������� 
			editEmployees(arr_of_employees, number_of_employees);
			break;
		case 3: // �������� 
			delEmployees(arr_of_employees, number_of_employees);
			break;
		case 4: // �������������� �������
			menuIndTask(arr_of_employees, number_of_employees);
			break;
		case 5: // c��������� 
			arr_of_employees = menuSortEmployees(arr_of_employees, number_of_employees);
			break;
		case 6: // �����
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

// ����� ������ �����������
void showEmployees(Employees* arr_of_employees, int number_of_employees)
{
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n| "
	<< "\t\t\t\t\t\t������ �����������                                            |\n"
	<< "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n| "
	<< "�  �������" << setw(20) << "���" << setw(20) << "��������" << setw(20) << "�����" << setw(20) << "���������" << setw(20) << "�������� |\n";

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

// ������ ������� 
Employees* reallocationForEmployees(Employees* arr_of_employees, int& number_of_employees, int m)
{
	Employees* temp_arr = new Employees[m]; // ��������� ������ ��� ������ �������� 
	for (int i = 0; i < number_of_employees; i++) // ������� ������ ������
	{
		temp_arr[i].name = arr_of_employees[i].name;
		temp_arr[i].surname = arr_of_employees[i].surname;
		temp_arr[i].patronymic = arr_of_employees[i].patronymic;
		temp_arr[i].department = arr_of_employees[i].department;
		temp_arr[i].post = arr_of_employees[i].post;
		temp_arr[i].salary = arr_of_employees[i].salary;
	}
	delete[]arr_of_employees; // �������� ������ ������ 
	number_of_employees = m; // ���������� ���������� ����������� 
	arr_of_employees = temp_arr; // ������� ���������� 
	return arr_of_employees;
}

// ���������� ������ ����������
void addEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	cout << "\n���������� ������ ����������\n";
	cout << " ������� �������: ";
	cin >> arr_of_employees[number_of_employees - 1].surname;
	cout << " ������� ���: ";
	cin >> arr_of_employees[number_of_employees - 1].name;
	cout << " ������� ��������: ";
	cin >> arr_of_employees[number_of_employees - 1].patronymic;
	cout << " ������� �����: ";
	cin >> arr_of_employees[number_of_employees - 1].department;
	cout << " ������� ���������: ";
	cin >> arr_of_employees[number_of_employees - 1].post;
	cout << " ������� ��������: ";
	protection(0, 10000, arr_of_employees[number_of_employees - 1].salary);
	successSave();
}

// �������������� ���������� � ����������
void editEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	system("cls");
	showEmployees(arr_of_employees, number_of_employees); // ����� ����������� �� �����
	string temp; // ��������� ������ ��� ������� 
	bool flag = true;
	int i = 0;
	cout << "\n ������� ������� ����������, ��� ������ ������ ��������: ";
	cin >> temp;
	while (flag && i < number_of_employees) // ���� ��� ������ ������� (���� true � ���� �� ��������� ���� �����������)
		if (temp == arr_of_employees[i].surname) // ���� ������� ����������, ���� ��������������� 
			flag = false;
		else i++;// ����� ����� ������������ 
	if (flag) // ���� ���������� �� ������� 
		noAccount(); // ����� ��������� � ���, ��� ������� ������ � ����� �������� ���
	else // ���� ������� ����������, �� ����� ����� while ������������, ��� ����� �������� 
	{
		cout << "\n�������������� ������ � ����������\n"
		<< " 1. �������� �������\n"
		<< " 2. �������� ���\n"
		<< " 3. �������� ��������\n"
		<< " 4. �������� �����\n"
		<< " 5. �������� ���������\n"
		<< " 6. �������� ��������\n"
		<< " 0. �����\n\t>>> ";

		int kod;
		protection(0, 6, kod);
		switch (kod)
		{
		case 1:
			cout << "\n������� ����� ������� ����������: ";
			cin >> arr_of_employees[i].surname;
			successSave();
			break;
		case 2:
			cout << "\n������� ����� ��� ����������: ";
			cin >> arr_of_employees[i].name;
			successSave();
			break;
		case 3:
			cout << "\n������� ����� �������� ����������: ";
			cin >> arr_of_employees[i].patronymic;
			successSave();
			break;
		case 4:
			cout << "\n������� ����� ����� ����������: ";
			cin >> arr_of_employees[i].department;
			successSave();
			break;
		case 5:
			cout << "\n������� ����� ��������� ����������: ";
			cin >> arr_of_employees[i].post;
			successSave();
			break;
		case 6:
			cout << "\n������� ����� �������� ����������: ";
			protection(0, 10000, arr_of_employees[i].salary);
			successSave();
			break;
		case 0:  
			break;
		}
	}
}

// �������� ����������
void delEmployees(Employees* arr_of_employees, int& number_of_employees)
{
	string surname_for_delete;
	cout << "\n������� ������� ����������, �������� ������ �������: ";
	cin >> surname_for_delete;
	int i = 0;
	bool flag = true;
	while (flag && i < number_of_employees) // ���� ��� ������ ������� �������� 
		if (arr_of_employees[i].surname == surname_for_delete)
			flag = false; // e��� ������� ������, ���� ���������� � ���� ��������������� 
		else // ���� ���, ����� ������������
			i++;

	if (flag) // ���� ������� �� ������ 
		noAccount(); // ����� ��������� � ���, ��� ����� ������� ������ ���
	else // ���� ������� ������ 
	{
		int del = 0;
		cout << " �� ������������� ������ ������� ���������� � �������� " << arr_of_employees[i].surname << "?" << endl;
		cout << " ��������� ������ �� �������� ��������������!\n";
		cout << " 1 - ��\n 2 - ���\n\t>>> ";
		protection(1, 2, del);
		if (del == 1)
		{
			for (int j = i; j < number_of_employees - 1; j++) // i - ����� ��������, �������� � ����� ���������� ��������
				arr_of_employees[j] = arr_of_employees[j + 1];
			number_of_employees--; // ���������� ���������� �����������
			successSave();
		}
		else
			cout << " �������� ��������\n";
	}
}


//�������������� �������
void menuIndTask(Employees* arr_of_employees, int number_of_employees)
{
	cout << "\n�������������� �������\n";
	cout << " 1. ���������� � ��������� < ���������\n";
	cout << " 2. ���������� �� �������\n";
	cout << " 0. �����\n\t>>> ";

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

// ���.1: ����� ����������� � ��������� < ��������
void indTaskLessSalary(Employees* arr_of_employees, int number_of_employees) // c ���������, ������ ��������� 
{
	cout << "\n������� ��������: ";
	int salary, kol = 1;
	protection(0,10001,salary);
	cout << "\n����� ����������� � ��������� < ��������:\n";

	for (int i = 0; i < number_of_employees; i++)
		if (arr_of_employees[i].salary < salary) // ���� �������� ������ ���������, �� ��������� ���������� � ���������� 
		{
			cout << "\n" << kol << "-� ���������:";
			showFind(arr_of_employees, number_of_employees, i);
			kol++;
		}
}

// ���.2: ���������� �� �������: ����� � ������� �������� 
void indTaskDepartments(Employees* arr_of_employees, int number_of_employees)
{
	system("cls");
	int number_of_departments = 0, i = 0 , j, same = 0;
	string department_names[20]; // ��������� ������
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
	cout << "\n���������� ������� - \t" << number_of_departments << "\n";
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
		cout << " �����: " << arr_of_departments[i].Name
			<< "\n ����������� � ������: " << arr_of_departments[i].Employees
			<< "\n ��������� �������� �����������: " << arr_of_departments[i].TotalSalary
			<< "\n ������� ��������: " << double(arr_of_departments[i].TotalSalary / arr_of_departments[i].Employees) << "\n\n";
	}
	delete[]arr_of_departments; // �������� ���������� ����� ������������� 
}

// ���.2: ������ ������� �������� 
Departments* indTask_Resize(Departments* arr_of_departments, int& number_of_departments, int m)
{

	Departments* temp_arr = new Departments[m];
	for (int i = 0; i < number_of_departments,i<m; i++) // ������� ����������
	{
		temp_arr[i].Name = arr_of_departments[i].Name;
		temp_arr[i].Employees = arr_of_departments[i].Employees;
		temp_arr[i].TotalSalary = arr_of_departments[i].TotalSalary;
	}

	delete[]arr_of_departments; // �������� ������� ������� 
	number_of_departments = m; // ���������� �������  
	arr_of_departments = temp_arr; // ������� ����������
	return arr_of_departments; // ����������� ����������� ������
}

// ����� ���������� 
Employees* menuSortEmployees(Employees* arr_of_employees, int number_of_employees)
{
	int kod;
	cout << "\n���� ������ ����������:\n"
	<< "\n 1. ������������� �� �������"
	<< "\n 2. ������������� �� ������"
	<< "\n 3. ������������� �� ��������"
	<< "\n 0. �����\n\t>>> ";

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

// ���������� �� �������
Employees* sortSurname(Employees* arr_of_employees, int number_of_employees)
{
	Employees* temp_arr = new Employees[number_of_employees]; // ��������� ������ 
	for (int i = 0; i < number_of_employees; i++) // ������� ����������
	{
		temp_arr[i].name = arr_of_employees[i].name;
		temp_arr[i].surname = arr_of_employees[i].surname;
		temp_arr[i].patronymic = arr_of_employees[i].patronymic;
		temp_arr[i].department = arr_of_employees[i].department;
		temp_arr[i].post = arr_of_employees[i].post;
		temp_arr[i].salary = arr_of_employees[i].salary;

	}
	cout << "\n���������� �� �������\n";

	for (int i = 0; i < number_of_employees - 1; i++)  // ���������� �� � �� � 
		for (int j = 0; j < number_of_employees - i - 1; j++) // ��������� �� ���� ��� 
			if (temp_arr[j].surname > temp_arr[j + 1].surname) // ��������� �� ASCII
				swap(temp_arr[j], temp_arr[j + 1]); // ������ �������
	//strcmp(temp_arr[j].surname.c_str(), temp_arr[j + 1].surname.c_str()) > 0);
	showEmployees(temp_arr, number_of_employees); // ����� �����������

	int temp; // ��������� ���������� 
	canISaveNow(); // ���������? 

	protection(1, 2, temp);
	switch (temp)
	{
	case 1: // ���������� (���������� ������� �������) 
		delete[]arr_of_employees;
		arr_of_employees = temp_arr;
		break;
	case 2: // �� ��������� 
		delete[] temp_arr; // �������� ����������������� ������� 
		break;
	}
	return arr_of_employees;
}

// ���������� �� ������
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

	cout << "\n ���������� �� ������:\n";

	for (int i = 0; i < number_of_employees - 1; i++) // ��� ������������ 1-�� ���������, �� � ������� 0, ���������� �� � �� �
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

// ���������� �� ��������
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

	cout << "\n ���������� �� ��������\n\n";
	for (int i = 0; i < number_of_employees - 1; i++) // �� ������� � ������� (�� �����������) 
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


// ����� 
void menuFindEmployees(Employees* arr_of_employees, int number_of_employees)
{
	cout << "\n\t����� ����������\n"
	<< "\n 1. ����� �� �������"
	<< "\n 2. ����� �� ���������"
	<< "\n 3. ����� ���������� � ������������ ���������"
	<< "\n 0. �����\n\t>>> ";

	int kod;
	protection(0, 3, kod);

	switch (kod)
	{
	case 1: 
		findSurname(arr_of_employees, number_of_employees); 
		break; // ����� �� �������
	case 2: 
		findPosition(arr_of_employees, number_of_employees); 
		break; // ����� �� ��������� 
	case 3: 
		findMaxSalary(arr_of_employees, number_of_employees); 
		break; // ����� �� ������������ �������� 
	case 0: 
		break; // ����� 
	}
}

// ����� �� �������
void findSurname(Employees* arr_of_employees, int number_of_employees)
{
	string FindSurname; // ������ ��� ����� �������  
	bool flag = true;
	cout << "\n\t����� ����������� �� �������\n";
	cout << "\n ������� ������� ��� ������: ";
	cin >> FindSurname;
	for (int i = 0; i < number_of_employees; i++)
		if (FindSurname == arr_of_employees[i].surname) // ���� ������� �������, �� ����� 
		{
			showFind(arr_of_employees, number_of_employees, i);
			flag = false; // ���������� ���������� if
		}
	if (flag)
		noAccount(); // ����� ���������, ��� ����� ������� ��� � �������
}

// ����� �� ���������
void findPosition(Employees* arr_of_employees, int number_of_employees)
{
	string SearchPosition; // ������ ��� ����� ��������� 
	cout << "\n\t����� ����������� �� ���������\n";
	cout << "\n ������� ��������� ��� ������: ";
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

// ����� �� ������������ ��������
void findMaxSalary(Employees* arr_of_employees, int number_of_employees)
{
	cout << "\n\t����� ���������� � ���������� ���������\n";
	int maxSalary = 0;
	for (int i = 0; i < number_of_employees; i++)

		if (maxSalary < arr_of_employees[i].salary) // ���� ������� �������� ������ 
			maxSalary = arr_of_employees[i].salary; // �� �������� ���������� �����������
	for (int i = 0; i < number_of_employees; i++) // ����� ��������� ����� ��� ��������
		if (arr_of_employees[i].salary == maxSalary) // �������� ���������� ��������� � ������������ ���������
			showFind(arr_of_employees, number_of_employees, i); // �����

}

// ����� ���������� � ����������
void showFind(Employees* arr_of_employees, int number_of_employees, int i)
{
	cout << "\n �.�.�.: " << arr_of_employees[i].surname << " " << arr_of_employees[i].name << " " << arr_of_employees[i].patronymic
	<< "\n �����: " << arr_of_employees[i].department << "\n ���������: " << arr_of_employees[i].post << "\n ��������: " << arr_of_employees[i].salary << "\n";
}