#pragma once // ������ �� �������� ����������� ������������ ������
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
	int role = 0; // 0 - ������������, 1 - ������������� 
	int access = 0; // 0 - �������������, 1 - ����������� 
};

void programmStart();
void getNumberOfAccountsInFile(int&); // ����������� ���������� ��������� � �����
void readFileAccounts(Accounts*); // ������ (�������) ��������� �� ����� � ������
void writeAccountsInFile(Accounts*, int); // ������ ��������� � ����
void showAccounts(Accounts*, int); // ����� ��������� �� �����
Accounts* resizeOfArray(Accounts*, int&, int); // ������������� ������
void addAccount(Accounts*, int&); // ���������� �������� � ������
void newAccount(Accounts*, int&); //��� ���-�� �������
void delAccounts(Accounts*, int&); // �������� ��������� 
Accounts* menuLoginOrRegistration(Accounts*, int&); // ���� ����������� (����/�����������) 
void checkLoginPassword(Accounts*, int&); // �������� ������ � ������ 
void checkRole(Accounts*, int&, int); // �������� ����
void adminMenu(Accounts*, int&); // ���� ��������������
void adminMenuOfAdminAccounts(Accounts*, int&); // ���������� ���������� 
void userMenu(); // ���� ������������
