#include "Signal.h"

void canISaveNow() // ������ ���������? 
{
	cout << "\n������� ����������\n"
	" �� ������ ��������� ��������������� ������.\n"
	" 1 - ���������\n 2 - �� ���������\n\t>>> ";
}

void noAccount() // ������ �������� ��� � �������
{
	cout << "\n\n ������ ���� ��� � ���� ������!\n";
	Sleep(1000);
	system("cls");
}

void successSave()
{
	cout << "\n ����� ������ ������� ���������!\n";
	Sleep(2000);
	system("cls");
}

// ������� �� ������ flag � amount ����� ��� ����������� � �������� ���������  (���������� true, 3)
void isfalsePassword(string TempLogin, bool& flagPassword, int& amount) // ���� ��������� ��� ������ �� ��� ������, �� ��������� ��������� �� ������
{
	amount--; // ��������� ���������� �������; ���� amount ������ �� 0, �� ������������� ���� while
	system("cls");
	cout << "\n �������� ������!\n ������� ��������: " << amount << "\n\n �����: " << TempLogin;
	if (amount == 0)
	{
		cout << "\n �� ��������� ���������� ���������� �������! ��������� �����.\n";
		Sleep(2000);
		system("cls");
		flagPassword = false; // ���������� �������� false, ����� ���������� ����
	}
}
