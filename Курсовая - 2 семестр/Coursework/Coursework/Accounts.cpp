#include "Accounts.h" 

void programmStart()
{
	SetConsoleCP(1251); // ��������� ��������� �� ��������� ��� �����
	SetConsoleOutputCP(1251); // ��������� ��������� �� ��������� ��� ������

	int number_of_accounts = 0;
	getNumberOfAccountsInFile(number_of_accounts); // ����������� ���������� ��������� � �����
	Accounts* array_of_accounts = new Accounts[number_of_accounts]; // ��������� ������ ��� ������� ��������
	readFileAccounts(array_of_accounts); // ������� ��������� �� ����� � ������
	array_of_accounts = menuLoginOrRegistration(array_of_accounts, number_of_accounts); // ���� ����������� (1 - ����, 2 - �����������) 
	writeAccountsInFile(array_of_accounts, number_of_accounts); // ������ ������ � ���� 
	delete[] array_of_accounts; // ������� ������������ ������
}

// ����������� ���-�� ��������� � �����
void getNumberOfAccountsInFile(int& number_of_accounts)
{
	string temp; // ��������� ���������� ��� ���������� ������
	ifstream fin("Accounts.txt", ios::in); // �������� ����� ��� ������ ������ 
	if (!fin.is_open()) // ���� ������ ������ (�����)
	{
		number_of_accounts = 1;
	}// int n = _filelength(_fileno(file)) / sizeof(student);
	else
	{
		int kol = 0;
		while (!fin.eof()) // ���� �� ��������� ����� ����� 
		{
			fin >> temp; // ���������� ������ � ���������� temp
			kol++;//������� �����
		}
		number_of_accounts = kol / 4; //�� 4 ���� �� �������
	}
	fin.close(); // �������� ����� 
}

// ������� ��������� �� ����� � ������
void readFileAccounts(Accounts* arr_of_accounts)
{
	ifstream fin("Accounts.txt", ios::in); // �������� ����� ��� ������ ������
	if (!fin.is_open()) // ���� ����� ���, ���� �������� �������� ������ 
	{
		cout << " ������� �������� ���������������: �����/������ - admin\n";
		arr_of_accounts[0].login = "admin";
		arr_of_accounts[0].password = doHashNow("admin");
		arr_of_accounts[0].role = 2;
		arr_of_accounts[0].access = 1;
	}
	else
	{
		int i = 0; // ��������� ����������
		while (!fin.eof()) // ���� �� ��������� ����� �����
		{
			fin >> arr_of_accounts[i].login >> arr_of_accounts[i].password >>
				arr_of_accounts[i].role >> arr_of_accounts[i].access; // ���������� ������ �� ����� � ������
			i++;
		}
	}
	fin.close(); // �������� �����
}

// ������ ��������� � ����
void writeAccountsInFile(Accounts* arr_of_accounts, int number_of_accounts)
{
	ofstream fout("Accounts.txt", ios::out); // �������� ����� ��� ������ 
	for (int i = 0; i < number_of_accounts; i++)
	{
		fout << arr_of_accounts[i].login << " " << arr_of_accounts[i].password << " " 
			<< arr_of_accounts[i].role << " " << arr_of_accounts[i].access; // ������ ������ � ����
		if (i < number_of_accounts - 1) fout << endl; // endl ���� �� ������ �� ���������� ��������
	}
	fout.close(); // �������� �����
}

// ����� ���������
void showAccounts(Accounts* arr_of_accounts, int number_of_accounts)
{
	cout << " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n|"
	<< "\t\t\t\t\t������ ���������                                                |\n"
	<< "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n|"
	<< " �   �����" << setw(40) << "������ � ���� ����" << setw(40) << "����" << setw(15) << "������ |\n";
	for (int i = 0; i < number_of_accounts; i++)
		cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n| "
		<< i + 1 << ". " << arr_of_accounts[i].login << setw(50) << arr_of_accounts[i].password
		<< setw(30) << arr_of_accounts[i].role << setw(10) << arr_of_accounts[i].access << endl;
	cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n";

}

// ���������� �������� 
void addAccount(Accounts* arr_of_accounts, int& number_of_accounts)
{
	system("cls"); // �������� ������ �������
	cout << "\n������� �����������";
	cout << "\n ������� �����: ";
	string temporary_login, temporary_password, repeat_temporary_password; // ��������� ����������
	bool flag_login = true, flag_password = true, flag_check_password = true; // ����� ��� ������������� ������ 
	cin >> temporary_login; // ���� ���������� ������
	int amount = 3, i; // ���������� �������

	while (flag_login) // ��������, ���� �� � ���� ����� ����� 
	{
		int kol = 0;
		for (i = 0; i < number_of_accounts; i++)
			if (temporary_login != arr_of_accounts[i].login) 
				kol++;
			else // ���� ������ ����� �� ����� 
			{
				system("cls");
				cout << "\n ������� � ������� " << temporary_login << " ��� ����������!\n ������� ������ �����!\n\t>>> ";
				cin >> temporary_login; // ���� ������ ������ 
				break;
			}
		
		if (kol == number_of_accounts)
			flag_login = false; // ���� ������ ���, �� ������ ���� ��� ������ �� �����
	}

	arr_of_accounts[number_of_accounts - 1].login = temporary_login; // ������ ������; -1 ��� ��� ���������� � 0 
	cout << "\nFAO:������ ������ ��������� 4 � ����� ��������.\n";
	while (flag_password) // ���� true; ������
	{
		cout << " ������� ������: ";
		temporary_password = inputPassword(); // ���� ������ 
		while (flag_check_password) //����������� ���������� � ������
			if (temporary_password.size() < 4) // ���� ������ ������ 4 ��������, �� ������� ������
			{
				cout << "\n\n ������ ������ 4 ��������!\n ��������� ����: ";
				temporary_password = inputPassword(); // ���� ������ ������ 
			}
			else
				flag_check_password = false; // ���� ������ ���, �� ������� �� ����� 
		cout << "\n ������� ������ ��������: ";
		repeat_temporary_password = inputPassword(); // ��� ���������� ����� ������  
		if (temporary_password == repeat_temporary_password) // ���� ������ ������� 
		{
			arr_of_accounts[number_of_accounts - 1].password = doHashNow(temporary_password); // ������ ������ 
			successSave();
			flag_password = false; // ����� �� ����� ������ ������ 
		}
		else
			isfalsePassword(temporary_login, flag_password, amount); // � Signal; ����� ������, ���� ��������� ��� ������ �� ��� ������
	}
	arr_of_accounts[number_of_accounts - 1].role = 0; // ���� - ������������  
	arr_of_accounts[number_of_accounts - 1].access = 0; // ������� ������������� 
}

// ��������� ������ ��������
void changeAccounts(Accounts* arr_of_accounts, int number_of_accounts) // ������������� � ���������; ��� ������ 
{
	string temp_login; // ������ ��� �������� ������
	bool flag = true;
	int i = 0, q = 1;
	cout << "\n ������� ����� ��������, ������� ������ ��������: ";
	cin >> temp_login;

	while (flag && i < number_of_accounts) // ���� ��� ������ ������� �������� 
		if (temp_login == arr_of_accounts[i].login)
		{

			if (arr_of_accounts[i].role == 0)
			{
				flag = false;
			}
			else 
				if (arr_of_accounts[i].role == 1)
					{
						cout << " ��� �������������� ������ �������������� ��������� ������� ������� �������� ��������������"
							<<"\n ��� ������������� ������ ������� ������� ������ �������� ��������������!\n\t>>> ";
						string pass;
						pass = inputPassword();
						if (doHashNow(pass) == arr_of_accounts[0].password) flag = false;
					}// ���� ������ ���������� �����, flag �������� �� false
				else if (arr_of_accounts[i].role == 2)
				{
					cout << "\n\t\t������!\n � ��� ��� ���� ��� ����� ��������!\n���������� � ���������� ��������������!";
					Sleep(2000);
					system("cls");
					q=0;
					break;
				}
		}
		else 
			i++; // ���� �� ����� ������ ������ ������� 

	if (flag) // ���� ��� �������� 
		noAccount(); // ����� ��������� � ���, ��� ������ �������� ��� � �������
	else // ���� ������� ������, ����������, ��� ����� ��������
	{
		int kod;
		cout << "\n�������������� ������ ��������:"
		<< "\n 1. �������� �����"
		<< "\n 2. �������� ������"
		<< "\n 3. �������� ����"
		<< "\n 4. �������� ������� �������"
		<< "\n 0. �����\n\t\t>>> ";

		protection(0, 4, kod); // ������ �� ����� ���� � �������� ����� �� 0 �� 4
		switch (kod)
		{
		case 1: // ��������� ������ 
			cout << "\n ������� ����� �����: ";
			cin >> arr_of_accounts[i].login;
			cout << "\n\n ����� ����� ������� �������!";
			Sleep(2000);
			system("cls");
			break;
		case 2: // ��������� ������ 
			cout << "\n ������� ����� ������: ";
			cin >> arr_of_accounts[i].password;
			arr_of_accounts[i].password = doHashNow(arr_of_accounts[i].password);
			cout << "\n\n ����� ������ ������� �������!";
			Sleep(2000);
			system("cls");
			break;
		case 3: // ��������� ���� 
			if (arr_of_accounts[i].role == 1) // 1- �������������, 0 - ������������ 
			{
				arr_of_accounts[i].role = 0;
				cout << "\n ���� ������������ ������� �������� �� ������������!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
			else 
			{
				arr_of_accounts[i].role = 1; 
				cout << "\n ���� ������� �������� �� ��������������!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
		case 4: // ��������� ������ �������
			if (arr_of_accounts[i].access == 1) // ���� ������� ����������� 
			{
				arr_of_accounts[i].access = 0; // �������������
				cout << "\n ������� ������� �������������!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
			else // ���� ������� �������������
			{
				arr_of_accounts[i].access = 1; // ��������� 
				cout << "\n ������� ������� �����������!\n\n";
				Sleep(2000);
				system("cls");
				break;
			}
		}
	}
}

// ����
Accounts* menuLoginOrRegistration(Accounts* arr_of_accounts, int& number_of_accounts)
{
	int kod;
	bool flag = true;
	while (flag)
	{
		cout << "    ������� ����:"
		<< "\n 1. ���� � �������"
		<< "\n 2. �����������"
		<< "\n 0. �����\n\t>>> ";
		protection(0, 2, kod);
		switch (kod)
		{
		case 1: // ���� � ������� 
			checkLoginPassword(arr_of_accounts, number_of_accounts); // �������� ������ ��� ����� 
			break;

		case 2: // ����������� �������� 
			arr_of_accounts = resizeOfArray(arr_of_accounts, number_of_accounts, number_of_accounts + 1); // ������������� ������
			addAccount(arr_of_accounts, number_of_accounts); // ���������� ��������
			break;

		case 0:
			flag = false;
			break;
		}
	}
	return arr_of_accounts;
}

// ������� � �������
void checkLoginPassword(Accounts* arr_of_accounts, int& number_of_accounts)
{
	bool find_login = false, error_login = true, flag_password = true, flag = true;
	int login_index, amount = 3;
	string temp_login, temp_password;

	while (!find_login) // ���� ��� ������ ������ 
	{
		cout << "\n ������� �����: ";
		cin >> temp_login; // ���� ������ 
		for (int i = 0; i < number_of_accounts; i++)
			if (temp_login == arr_of_accounts[i].login) // ���� ����� ����� ���������� 
			{
				login_index = i; // ���������� ������ 
				find_login = true; // ������� �� ����� �.�. ����� �����
				error_login = false; // ��������� ��������� ������
			}
		if (error_login) // ���� ����� �� ������
		{
			system("cls");
			amount--; // ���� ����� �������� �����, �� ��������� ���������� �������
			cout << "\n ������� � ������� " << temp_login << " �� ���������!\n";
			cout << " ������� ��������: " << amount << endl;

			if (amount == 0) // ���� �������� 0, �� ������� �� ����� 
			{
				cout << "\n ���������� ����� ������� ����� ����. ���������� �����.\n";
				Sleep(2000);
				system("cls");
				find_login = true;
				flag_password = false; // ���������� ���������� �����
			}
		}
	}
	amount = 3; // ��������� ���������� �������
	while (flag_password)
	{
		cout << " ������� ������: ";
		temp_password = inputPassword(); // ���� ������ 
		if (doHashNow(temp_password) == arr_of_accounts[login_index].password) // ���� ������ �������
		{
			if (arr_of_accounts[login_index].access) // ���� ������� ������� 1 (true), ��������� ����
				checkRole(arr_of_accounts, number_of_accounts, arr_of_accounts[login_index].role); // �������� ���� (���������, ��� �����)
			else // ���� 0 (false), ������ ������� ������������� 
			{
				cout << "\n ������! ������ ������� �������������. �������� ���������.\n\n";
				Sleep(2000);
				system("cls");
			}
			flag_password = false;
		}
		else // ������ �� ������ 
			isfalsePassword(temp_login, flag_password, amount); // ����� ������, ���� ��������� ��� ����� �������� ������
	}
}

// ������ �������
Accounts* resizeOfArray(Accounts* arr_of_accounts, int& number_of_accounts, int new_number_of_accounts) // m ��������� �������� �� 1 ������ 
{
	Accounts* temp_arr = new Accounts[new_number_of_accounts]; // ��������� ������

	for (int i = 0; i < number_of_accounts; i++)// ������� ������ ������ 
	{
		temp_arr[i].login = arr_of_accounts[i].login;
		temp_arr[i].password = arr_of_accounts[i].password;
		temp_arr[i].role = arr_of_accounts[i].role;
		temp_arr[i].access = arr_of_accounts[i].access;
	}

	delete[]arr_of_accounts; // �������� ������� ������� ��������
	number_of_accounts = new_number_of_accounts; // ���������� ���������� � ����������
	arr_of_accounts = temp_arr; // ������� ���������� 

	return arr_of_accounts; 
}

// �������� ���� ������������
void checkRole(Accounts* arr_of_accounts, int& number_of_accounts, int role)
{
	switch (role)
	{
	case 0:
		system("cls");
		cout << " �� �������������� ��� ������������.\n";
		userMenu(); // ���� ������������ 
		break;
	case 1:
		system("cls");
		cout << " �� �������������� ��� �������������.\n\n";
		adminMenu(arr_of_accounts, number_of_accounts); // ���� ��������������
		break;
	case 2: 
		system("cls");
		cout << " �� �������������� ��� ������� �������������.\n\n";
		adminMenu(arr_of_accounts, number_of_accounts); // ���� ��������������
		break;
	}

}

// ���� ��������������
void adminMenu(Accounts* arr_of_accounts, int& number_of_accounts)
{
	int kod;
	bool flag = true;
	while (flag)
	{
		cout << "\t���� ��������������";
		cout << "\n 1. ������ � ����������";
		cout << "\n 2. ������ � ������������";
		cout << "\n 0. ����� �� ������� ������\n\t>>> ";

		protection(0, 2, kod);
		switch (kod)
		{
		case 1: // ������ � ����������
			system("cls");
			adminMenuOfAdminAccounts(arr_of_accounts, number_of_accounts); // ���� ��� ���������� ���������� 
			break;

		case 2: // ������ � ������������
			system("cls");
			userMenu();
			break;

		case 0:
			system("cls");
			flag = false; // ����� �� �����
			break;
		}
	}

}

// ���� ��������������, ������ � ����������
void adminMenuOfAdminAccounts(Accounts* arr_of_accounts, int& number_of_accounts)
{
	int kod;
	bool flag = true;
	while (flag)
	{
		system("cls");
		showAccounts(arr_of_accounts, number_of_accounts);
		cout << "\n������ � ����������:"
			//<<"\n 1. �������� �������"
		<< "\n 1. ������������� ������ ��������"
		<< "\n 2. ������� �������"
		<< "\n 0. �����\n\t>>> ";

		protection(0, 2, kod);
		switch (kod)
		{
	/* case 1:
			arr_of_accounts = resizeOfArray(arr_of_accounts, number_of_accounts, number_of_accounts + 1); // ������������� ������
			newAccount(arr_of_accounts, number_of_accounts);
			break;
			*/
		case 1: // �������������� ���������
			changeAccounts(arr_of_accounts, number_of_accounts);
			break;

		case 2: // �������� ��������
			delAccounts(arr_of_accounts, number_of_accounts);
			break;

		case 0: // ����� �� ����� while
			flag = false;
			system("cls");
			break;
		}
	}
}
/*
void newAccount(Accounts* arr_of_accounts, int& number_of_accounts) //��� ���-�� �������
{
	system("cls"); // �������� ������ �������
	cout << "\n���������� ������ �������� ���������������"
	<< "\n ������� �����: ";
	string temporary_login, temporary_password, repeat_temporary_password; // ��������� ����������
	bool flag_login = true, flag_password = true, flag_check_password = true; // ����� ��� ������������� ������ 
	cin >> temporary_login; // ���� ���������� ������
	int  i; 

	while (flag_login) // ��������, ���� �� � ���� ����� ����� 
	{
		int kol = 0;
		for (i = 0; i < number_of_accounts; i++)
			if (temporary_login != arr_of_accounts[i].login)
				kol++;
			else // ���� ������ ����� �� ����� 
			{
				system("cls");
				cout << "\n ������� � ������� " << temporary_login << " ��� ����������!\n ������� ������ �����!\n\t>>> ";
				cin >> temporary_login; // ���� ������ ������ 
				break;
			}

		if (kol == number_of_accounts)
			flag_login = false; // ���� ������ ���, �� ������ ���� ��� ������ �� �����
	}
	arr_of_accounts[number_of_accounts - 1].login = temporary_login; // ������ ������; -1 ��� ��� ���������� � 0 
	cout << "\nFAO:������ ������ ��������� 4 � ����� ��������.\n";
	while (flag_password) // ���� true; ������
	{
		cout << " ������� ������: ";
		temporary_password = inputPassword(); // ���� ������ 
		while (flag_check_password) //����������� ���������� � ������
			if (temporary_password.size() < 4) // ���� ������ ������ 4 ��������, �� ������� ������
			{
				cout << "\n\n ������ ������ 4 ��������!\n ��������� ����: ";
				temporary_password = inputPassword(); // ���� ������ ������ 
			}
			else
				flag_check_password = false; // ���� ������ ���, �� ������� �� ����� 
		cout << "\n ������� ������ ��������: ";
		repeat_temporary_password = inputPassword(); // ��� ���������� ����� ������  
		if (temporary_password == repeat_temporary_password) // ���� ������ ������� 
		{
			arr_of_accounts[number_of_accounts - 1].password = doHashNow(temporary_password); // ������ ������ 
			successSave();
			flag_password = false; // ����� �� ����� ������ ������ 
		}
		else
		{
			 // � Signal; ����� ������, ���� ��������� ��� ������ �� ��� ������
			system("cls");
			cout << "\n �������� ������!";
			cout << "\n\n �����: " << temporary_login;
			if (0 == 0)
			{
				cout <<"\n �� ��������� ���������� ���������� �������!��������� �����.\n";
				Sleep(2000);
				system("cls");
				flag_password = false; // ���������� �������� false, ����� ���������� ����
			}
		}
		
	}
	cout << "������� ���� ��������:\n1 - �������������\t0 - ������������\n\t>>> ";
	protection(0,1, arr_of_accounts[number_of_accounts - 1].role);
	cout << "������� ������� �������\n1 - ����� ����� � �������\t0 - ������� ������������\n\t>>> ";
	protection(0, 1, arr_of_accounts[number_of_accounts - 1].access);
}
*/
// �������� ��������
void delAccounts(Accounts* arr_of_accounts, int& number_of_accounts)
{
	string login_for_deleting; // ��� ������ ��������, ������� ����� ������� 
	cout << "\n ������� ����� ��������, ������� ������ �������: ";
	cin >> login_for_deleting;
	int i = 0, del = 0;
	bool flag = true;

	while (flag && i < number_of_accounts)
	{
		if (arr_of_accounts[i].login == login_for_deleting) // ����� �������� 
			flag = false; // ���� ������� ������, �� ������� �� ����� 
		else
			i++;
	}

	if (flag) // ���� �������� ��� 
		noAccount();
	else // ���� ������� ����������
	{
		if (arr_of_accounts[i].role == 2) // ������ �� �������� �������� ������ 
		{
			cout << "\n\t\t������!\n � ��� ��� ���� ��� ����� ��������!\n���������� � ���������� ��������������!";
			Sleep(2000);
			system("cls"); 
		}
		else if (arr_of_accounts[i].role == 1)
		{
			cout << "��� ������������� ������ ������� ������� ������ �������� ��������������!\n\t>>> ";
			string pass;
			pass = inputPassword();
			if (doHashNow(pass) == arr_of_accounts[0].password)
			{
				cout << " �� ������������� ������ ������� ������� " << arr_of_accounts[i].login << "?\n"
					<< " ��������� ������ �� �������� ��������������!\n"
					<< " 1 - ��" << "\n 2 - ���" << "\n\t>>>: ";
				protection(1, 2, del);
				if (del == 1)
				{
					for (int j = i; j < number_of_accounts - 1; j++) // i - ����� ��������; c������� � ����� ���������� ��������
						arr_of_accounts[j] = arr_of_accounts[j + 1];
					number_of_accounts--; // ���������� ���������� ��������� 
					successSave();
				}
				else
					cout << " �������� ��������!\n";
			}
			else
			{
				cout << "\n\t\t������!\n ������ �������!\n���������� � ���������� ��������������!";
				Sleep(2000);
				system("cls");
			}
		}
		else
		{
			cout << " �� ������������� ������ ������� ������� " << arr_of_accounts[i].login << "?\n"
				<< " ��������� ������ �� �������� ��������������!\n"
				<< " 1 - ��" << "\n 2 - ���" << "\n\t>>>: ";
			protection(1, 2, del);
			if (del == 1)
			{
				for (int j = i; j < number_of_accounts - 1; j++) // i - ����� ��������; c������� � ����� ���������� ��������
					arr_of_accounts[j] = arr_of_accounts[j + 1];
				number_of_accounts--; // ���������� ���������� ��������� 
				successSave();
			}
			else
				cout << " �������� ��������!\n";
		}
	}
}