#include "Protection.h"

int protection(int a, int b, int& n)
{
	while (true)
	{
		cin >> n; // ���� ������ ���������� 
		while ((!cin) || (cin.get() != '\n')) // ����� 
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "\n �������� ������ ���� ������! ����������, ��������� ����\n\t>>> ";
			cin >> n;
		}
		if (n >= a && n <= b) break; // �������� �����
		cout << "\n ��������� ����� ������� �� ���������� ������!\n\t[�� " << a << " �� " << b << "]\n����������, ��������� ����\n\t>>> ";
	}
	return n; // ����������� �������� ����������
}


// ���� ������
string inputPassword()
{
	string password;
	int ch = 0;
	while (true)
	{
		ch = _getwch(); // ��� ����������� ���� ������� ������� 

		if (ch == 13) // ����� enter �� ��������� � ������ (13 - ��� ������� enter)
			break; // ��������� ����� ����� �������� ����� (������� enter)
		else
			if (ch == 8) // 8 - ��� ������� backspace
			{
				cout << (char)8 << ' ' << (char)8; // c������� ������� �����, ����� ������ �� ������, ����� ��� ��� �������� ������� 
				if (!password.empty()) // ���� ������ �� �����, �� ����� �������; ���� �����, �� ������ �� ������
					password.erase(password.length() - 1); // ����� string ��� �������� ������ ������� 
			}
			else
			{
				cout << "*"; // ����� ��������� 
				password += (char)ch; // ��������� � ������ password ������ 
			}
	}
	return password;
}
