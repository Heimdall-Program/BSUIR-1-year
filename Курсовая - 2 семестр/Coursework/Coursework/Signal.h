#pragma once // ������ �� �������� ����������� ������������ ������
#include <iostream> // ��� ������ � �������� (����-�����)
#include <Windows.h>

using namespace std;

// ������� ���������? 
void canISaveNow(); 
// ������ �������� ��� � �������
void noAccount(); 
//�������� ����������
void successSave(); 
// ����� ������, ���� ��������� ��� ������ �� ��� ������
void isfalsePassword(string, bool&, int&); 
