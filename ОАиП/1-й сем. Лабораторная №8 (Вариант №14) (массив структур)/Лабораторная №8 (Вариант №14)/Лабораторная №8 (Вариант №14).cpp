#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h>
using namespace std;

//Распечатать анкетные данные студентов интересующей вас группы, имеющих средний балл выше введенного с клавиатуры.
struct student
{
	struct
	{
		string surname;
		string name;
		string patronymic;
	};
	int year = 0;
	int number_of_group;
	struct
	{
		int math_mark;
		int informatic_mark;
		int chemistry_mark;
	};
	double average_ball;
};
student* createStruct(int  number)
{
	student* list = new student[number];
	for (int i = 0; i < number; i++)
	{
		cout << "Введите фамилию, имя и отчество\n";
		cin >> list[i].surname >> list[i].name >> list[i].patronymic;
		cout << "Введите год рождения\n";//нужна защита
		cin >> list[i].year;
		cout << "Введите номер группы\n";//нужна защита
		cin >> list[i].number_of_group;
		cout << "Введите оценки по математике, информатике и химии\n";//нужна защита int 1-10
		cin >> list[i].math_mark >> list[i].informatic_mark >> list[i].chemistry_mark;
		list[i].average_ball = (double)(list[i].math_mark + list[i].informatic_mark + list[i].chemistry_mark) / 3;
	}
	return list;
}
student* delStudent(int  number, int size, student* arr)
{
	for (int i = number - 1; i < size - 1; i++) arr[i] = arr[i + 1];
	return arr;
}
void printStruct(student* arr, int  number)
{
	cout << "Фамилия/Имя/Отчество|Год рождения|Номер группы|Оценки по математике, информатике и химии|Средний балл\n";
	for (int i = 0; i < number; i++)
		cout << i + 1 << ") " << arr[i].surname << " "
		<< arr[i].name << " "
		<< arr[i].patronymic << " "
		<< arr[i].year << "     "
		<< arr[i].number_of_group << "     "
		<< arr[i].math_mark << "     "
		<< arr[i].informatic_mark << "     "
		<< arr[i].chemistry_mark << "     "
		<< arr[i].average_ball << endl;
}
void printStruct(student* list, int  number, double average, int group)
{
	int i, kol = 0;
	cout << "Фамилия/Имя/Отчество|Год рождения|Номер группы|Оценки по математике, информатике и химии|Средний балл\n";;
	for (i = 0; i < number; i++)
		if (list[i].average_ball >= average && list[i].number_of_group == group)
		{
			cout << i + 1 << ") "
				<< list[i].surname << " "
				<< list[i].name << " "
				<< list[i].patronymic << " "
				<< list[i].year << "     "
				<< list[i].number_of_group << "     "
				<< list[i].math_mark << "     "
				<< list[i].informatic_mark << "     "
				<< list[i].chemistry_mark << "                  "
				<< list[i].average_ball << endl;
			kol++;
		}
	if (kol == 0) cout << "\nУчеников из данной группы со средним баллом больше введённого нет\n";
}
student* resizeArray(int& oldSize, int newSize, student* list)
{
	if (oldSize == newSize) return list;
	student* newArray = new student[newSize];
	oldSize = newSize < oldSize ? newSize : oldSize;
	for (int i = 0; i < oldSize; i++) newArray[i] = list[i];
	oldSize = newSize;
	delete[] list;
	return newArray;
}
student* readFile(string fileName, int& size)
{
	ifstream file(fileName);
	if (!file.is_open()) return nullptr;
	size <= 0 ? size = 10 : size = size;
	student* list = new student[size];
	int i = 0;
	while (!file.eof())
	{
		if (i == size) list = resizeArray(size, size + 1, list);
		file >> list[i].surname;
		file >> list[i].name;
		file >> list[i].patronymic;
		file >> list[i].year;
		file >> list[i].number_of_group;
		file >> list[i].math_mark;
		file >> list[i].informatic_mark;
		file >> list[i].chemistry_mark;
		file >> list[i].average_ball;
		i++;
	}
	list = resizeArray(size, i - 1, list);
	file.close();
	return list;
}
void printInFile(string fileName, student* line, int size, int openMode)
{
	ofstream file(fileName, openMode);
	if (!file.is_open()) return;
	for (int i = 0; i < size; i++)
		file << line[i].surname << " " << line[i].name << " " << line[i].patronymic << " " << line[i].year
		<< " " << line[i].number_of_group << " " << line[i].math_mark << " " << line[i].informatic_mark << " " << line[i].chemistry_mark << " " << line[i].average_ball << endl;
	file.close();
}

void newfile()
{
	int number, check; //нужна защита
	cout << "Создание нового файла(все прошлые данные будут удалены)\n";
	cout << "Если вы хотите сохранить данные файла, введите 1, иначе любое другое число\n";
	cin >> check;
	if (check == 1) return;
	cout << "Введите количество студентов\n";
	cin >> number;//нужна защита
	student* arr = createStruct(number);
	printStruct(arr, number);
	printInFile("text.txt", arr, number, ios_base::out);
}
void checkFile()
{
	cout << "Список студентов:\n";
	int size = 1;
	student* list = readFile("text.txt", size);
	printStruct(list, size);
}
void correctFile()
{

	int size = 1, choise;
	student* list = readFile("text.txt", size);
	printStruct(list, size);
	cout << "\nВведите 1, если вы хотите добавить новых студентов\nВведите 2, если хотите удалить кого-либо из старых\n";
	cin >> choise;

	if (choise == 1)
	{
		int kol;
		cout << "Скольких студентов вы хотите добавить?\n";
		cin >> kol;
		student* list = createStruct(kol);
		printInFile("text.txt", list, kol, ios_base::app);
	}
	else 
		if (choise == 2)
		{
			int del;
			cout << "Введите номер студента, которого вы хотите удалить\n";
			cin >> del;
			list = delStudent(del, size, list);
			printInFile("text.txt", list, size - 1, ios_base::out);
			cout << "Студент #" << del << " успешно удалён!\n";
		}
			else cout << "Вы ввели неверное значение\n";
}
int indTask()
{
	double average;
	int group, kol, size = 1, i;
	student* list = readFile("text.txt", size);
	cout << "Введите номер интересующей вас группы\n";
	cin >> group;
	for (i = 0; i < size; i++)
		if (list[i].number_of_group == group) break;
	if (i == size)
	{
		cout << "\nНет группы с таким номером!\n";
		return 2;
	}
	cout << "Введите средний балл\n";
	cin >> average;

	printStruct(list, size, average, group);

}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);     
	do {
		system("cls");
		cout << "Введите 1, чтобы создать новый файл\nВведите 2, чтобы создать просмотреть файл\nВведите 3, чтобы откорректировать файл\nВведите 4, чтобы выполнить индивидуальное задание\n";
		int number_of_quest;
		cin >> number_of_quest; //нужна защита
		switch (number_of_quest)
		{
		case 1:
			newfile();
			break;
		case 2:
			checkFile();
			break;
		case 3:
			correctFile();
			break;
		default:
			cout << "Вы ввели некорректное значение, поэтому выполняется индивидуальное задание\n";
		case 4:
			indTask();
			break;
		}
		cout << "\nНажмите пробел, если хотите продолжить\n";
	} while (_getch() == 32);
}
