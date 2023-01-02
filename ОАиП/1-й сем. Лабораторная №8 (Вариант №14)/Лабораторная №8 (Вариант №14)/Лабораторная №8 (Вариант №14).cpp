#include <conio.h>
#include<io.h>
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <iomanip>
using namespace std;

//«r»	Режим открытия файла для чтения.Файл должен существовать.
//«w»	Режим создания пустого файла для записи.Если файл с таким именем уже существует его содержимое стирается, и файл рассматривается как новый пустой файл.
//«a»	Дописать в файл.Операция добавления данных в конец файла. Файл создается, если он не существует.
//«r + »	Режим открытия фала для обновления чтения и записи.Этот файл должен существовать.
//«w + »	Создаёт пустой файл для чтения и записи.Если файл с таким именем уже существует его содержимое стирается, и файл рассматривается как новый пустой файл.
//«a + »	Открыть файл для чтения и добавления данных.Все операции записи выполняются в конец файла, защищая предыдущее содержания файла от случайного изменения.Вы можете изменить позицию(FSEEK, перемотка назад) внутреннего указателя на любое место файла только для чтения, операции записи будет перемещать указатель в конец файла, и только после этого дописывать новую информацию.Файл создается, если он не существует.
struct student;
void printStruct(student& info);
int inputIntValue();
double inputDoubleValue();
int numberGroupDefense();
int inputOfMark();
void Creating();
void view();
void filling(int& size);
void indTask();
void editing();
void deleting();
void sort();
void sortSurname();
void sortNumberOfGroup();
void sortAverage();


struct student
{
    struct
    {
        char surname[12];
        char name[12];
        char patronymic[12];
    };
    int year = 0;
    int number_of_group;
    struct
    {
        int math_mark;
        int informatic_mark;
        int chemistry_mark;
    };
    double average;
};

void printStruct(student& info)
{
    cout << info.surname << setw(15)
        << info.name << setw(15)
        << info.patronymic << setw(15)
        << info.year << setw(10)
        << info.number_of_group << setw(10)
        << info.math_mark << setw(10)
        << info.informatic_mark << setw(10)
        << info.chemistry_mark << setw(10)
        << info.average << endl;
}
int inputIntValue()
{
    while (true)
    {
        int number;
        cin >> number;
        if (cin.fail())
        {
            cout << "Некорректный ввод, введите целое число!\n";
            cin.clear();
            cin.ignore(100, '\n');
        }
        else
            return number;
    }
}
double inputDoubleValue()
{
    while (true)
    {
        double number;
        cin >> number;
        if (cin.fail())
        {
            cout << "Некорректный ввод, введите число!\n";
            cin.clear();
            cin.ignore(100, '\n');
        }
        else
            return number;
    }
}
int numberGroupDefense()
{
    char s[100];
    cin >> s;
    return atoi(s);
}
int inputOfMark()
{
    int number;
    while (!(cin >> number) || number < 0)
    {
        cin.clear();//идентификатор ошибки;
        while (cin.get() != '\n'); //cin.get ожидает ввода пользователем
        cout << "Введите положительное численное значение!\n";
    }
    return number;
}
void Creating()
{
    FILE* file;
    int check;
    cout << "При создании файла будут удалены все данные, вы уверены что желаете это сделать?\nВведите 1, если желаете продолжить, иначе любое другое значение\n";
    check = inputIntValue();
    if (check == 1) 
    { 
        cout << "Создание нового файла успешно отменено\n";
        return; 
    }
    file = fopen("text.txt", "w");
    if (file == NULL)
    {
        cout << "Не удалось создать файл\n";
        return;
    }
    else
        cout << "Файл успешно создан\n";
    fclose(file);
}
void view()
{
    FILE* file;
    cout << "\n";
    file = fopen("text.txt", "r");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    student list;
    int kol = 1;
    cout << "Фамилия   |   Имя   |   Отчество   | Год рождения | Номер группы | Оценки по мат, информ и физ | Средний балл\n";
    while (fread(&list, sizeof(student), 1, file))
    {
        cout << kol << ") ";
        kol++;
        printStruct(list);
    }
    fclose(file);
}
void filling(int& size)
{
    FILE* file;
    file = fopen("text.txt", "at");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    cout << "Введите количество студентов\n";
    size = inputIntValue();
    student list;
    bool flag = true;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите фамилию\n";
        cin >> list.surname;
        cout << "Введите имя\n";
        cin >> list.name;
        cout << "Введите отчество\n";
        cin >> list.patronymic;
        cout << "Введите год рождения\n";
        list.year = inputIntValue();
        cout << "\n\nВведите номер группы студента\n";
        do {
            list.number_of_group = numberGroupDefense();
            if (list.number_of_group > 999999 || list.number_of_group < 9999) flag = false;
            else break;
            cout << "\nВы ввели неверное значение группы, попробуйте ещё раз\n";
        } while (flag == false);
        cout << "Введите оценку по математике\n";
        while (list.math_mark > 10 || list.math_mark < 0)
        {
            list.math_mark = inputOfMark();
            if (list.math_mark > 10 || list.math_mark < 0)
                cout << "\nТакой оценки в нашей стране нет в нашей базе, попробуйте еще раз\n";
        }
        cout << "Введите оценку по информатике\n";
        while (list.informatic_mark > 10 || list.informatic_mark < 0)
        {
            list.informatic_mark = inputOfMark();
            if (list.informatic_mark > 10 || list.informatic_mark < 0)
                cout << "\nТакой оценки в нашей стране не бывает)Поробуйте еще раз\n";
        }
        cout << "Введите оценки по химии\n";
        while (list.chemistry_mark > 10 || list.chemistry_mark < 0)
        {
            list.chemistry_mark = inputOfMark();
            if (list.chemistry_mark > 10 || list.chemistry_mark < 0)
                cout << "\nТакой оценки в нашей стране не бывает)Поробуйте еще раз\n";
        }
        list.average = (list.math_mark + list.informatic_mark + list.chemistry_mark) / 3.0;
        fwrite(&list, sizeof(student), 1, file);
    }
    fclose(file);
}
void indTask()
{
    int group_number, kol = 1;
    double need_average;
    cout << "Вывод анкетных данных студентов интересующей вас группы, имеющих средний балл выше введенного с клавиатуры\n";
    FILE* file;
    file = fopen("text.txt", "rt");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    student list;
    cout << "Введите номер группы\n";
    group_number = inputIntValue();
    cout << "Введите средний балл\n";
    need_average = inputDoubleValue();
    cout << "Фамилия   |   Имя   |   Отчество   | Год рождения | Номер группы | Оценки по мат, информ и физ | Средний балл\n";
    while (fread(&list, sizeof(student), 1, file))
        if (list.number_of_group == group_number && list.average > need_average)
        {
            printStruct(list);
            kol++;
        }
    if (kol == 0) cout << "\nНет студентов данной группы со средним баллом больше ввелённого\n";
    fclose(file);
}
void editing()
{
    FILE* file;
    student list;
    int number, task_number, marks;
    file = fopen("text.txt", "r+");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int kol = 1;
    cout << "Фамилия   |   Имя   |   Отчество   | Год рождения | Номер группы | Оценки по мат, информ и физ | Средний балл\n";
    while (fread(&list, sizeof(student), 1, file))
    {
        cout << kol << ") ";
        kol++;
        printStruct(list);
    }
    cout << "Введите номер студента, информацию у которого вы хотите изменить\n";
    number = inputIntValue() - 1;
    fseek(file, sizeof(student) * number, SEEK_SET);
    cout << "Что вы хотите изменить\n1.Фамилию\n2.Имя\n3.Отчество\n4.Год рождения\n5.Номер группы\n3. Оценки по предметам\n";
    task_number = inputIntValue();
    switch (task_number)
    {
        case 1:
        {
            cout << "Введите новую фамилию\n";
            cin >> list.surname;
            fwrite(&list, sizeof(list.surname), 1, file);
            break;
        }
        case 2:
        {
            cout << "Введите новое имя\n";
            cin >> list.name;
            fwrite(&list, sizeof(list.name), 1, file);
            break;
        }
        case 3:
        {
            cout << "Введите новое отчество\n";
            cin >> list.patronymic;
            fwrite(&list, sizeof(list.patronymic), 1, file);
            break;
        }
        case 4:
        {
            cout << "Введите новый год рождения\n";
            list.year = inputIntValue();
            fwrite(&list, sizeof(list.year), 1, file);
            break;
        }
        case 5:
        {
            cout << "Введите новый номер группы\n";
            list.number_of_group = inputIntValue();
            fwrite(&list, sizeof(list.number_of_group), 1, file);
            break;
        }
        case 6:
        {
            cout << "Выберите по какому предмету вы хотите изменить оценку (1.По математика\n 2.По информатике\n 3.По химии)\n";
            marks = inputIntValue();
            switch (marks)
            {
                case 1:
                {
                    cout << "Введите новую оценку по математике\n";
                    list.math_mark = inputIntValue();
                    list.average = (list.math_mark + list.informatic_mark + list.chemistry_mark) / 3.0;
                    fwrite(&list, sizeof(student), 1, file);
                    break;
                }
                case 2:
                {
                    cout << "Введите новую оценку по информатике\n";
                    list.informatic_mark = inputIntValue();
                    list.average = (list.math_mark + list.informatic_mark + list.chemistry_mark) / 3.0;
                    fwrite(&list, sizeof(student), 1, file);
                    break;
                }
                case 3:
                {
                    cout << "Введите новую оценку по химии\n";
                    list.chemistry_mark = inputIntValue();
                    list.average = (list.math_mark + list.informatic_mark + list.chemistry_mark) / 3.0;
                    fwrite(&list, sizeof(student), 1, file);
                    break;
                }
                default:
                    cout << "Нет предмета с таким номером\n";
            }
        }
        default:
            cout << "Некорректный выбор\n";
    }
    fclose(file);
    view();
}
void deleting()
{
    FILE* file;
    view();
    file = fopen("text.txt", "r+");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int number;
    cout << "Введите номер студента, информацию о котором вы хотите удалить\n";
    number = inputIntValue();
    student list;
    int size = sizeof(student);
    fseek(file, sizeof(student) * number, SEEK_SET);
    while (fread(&list, sizeof(student), 1, file))
    {
        fseek(file, -size, SEEK_CUR);
        fwrite(&list, sizeof(student), 1, file);
        fseek(file, size, SEEK_CUR);
    }
    _chsize(_fileno(file), _filelength(_fileno(file)) - size);//возвращает дескриптор на файл
    fclose(file);
    cout << "\nСтудент успешно удалён\n";
}
void sort()
{
    int type_sort;
    view();
    cout << "Выберите по чём сортировать\n1.По фамилии\n2.По номеру группы\n3.По среднем баллу\n";
    type_sort = inputIntValue();
    switch (type_sort)
    {
        case 1:
        {
            sortSurname();
            break;
        }
        case 2:
        {
            sortNumberOfGroup();
            break;
        }
        case 3:
        {
            sortAverage();
            break;
        }
        default:
            cout << "Вы ввели некорректное значение\n";
    }
}
void sortSurname()
{
    FILE* file;
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(student), i, j, letter;
    student* list = new student[n];
    fread(list, sizeof(student), n, file);
    fclose(file);
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            for (letter = 0; letter < 13; letter++)
                if (list[i].surname[letter] > list[j].surname[letter])
                {
                    student trade;
                    trade = list[j];
                    list[j] = list[i];
                    list[i] = trade;
                }
    file = fopen("text.txt", "wb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    fwrite(list, sizeof(student), n, file);
    fclose(file);
    view();
    delete[]list;
}
void sortNumberOfGroup()
{
    FILE* file;
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(student), i, j;
    student* arr = new student[n];
    fread(arr, sizeof(student), n, file);
    fclose(file);
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i].number_of_group > arr[j].number_of_group)
            {
                student trade;
                trade = arr[j];
                arr[j] = arr[i];
                arr[i] = trade;
            }
    file = fopen("text.txt", "wb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    fwrite(arr, sizeof(student), n, file);
    fclose(file);
    view();
    delete[]arr;
}
void sortAverage()
{
    FILE* file;
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(student), i, j;
    student* arr = new student[n];
    fread(arr, sizeof(student), n, file);
    fclose(file);
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (arr[i].average < arr[j].average)
            {
                student trade;
                trade = arr[j];
                arr[j] = arr[i];
                arr[i] = trade;
            }
    file = fopen("text.txt", "wb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    fwrite(arr, sizeof(student), n, file);
    fclose(file);
    view();
    delete[]arr;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    do
    {
        system("cls");
        int task_number, size = 0;
        cout << "1. Создать файл\n2. Просмотреть файл\n3. Добавить данные в файл\n4. Индивидуальное задание\n5. Редактирование файла\n6. Удаление данных о студенте\n7. Сортировка данных в файле\n8. Закрытие программы\n";
        task_number = inputIntValue();
        switch (task_number)
        {
            case 1:
            {
                Creating();
                break;
            }
            case 2:
            {
                view();
                break;
            }
            case 3:
            {
                filling(size);
                break;
            }
            case 4:
            {
                indTask();
                break;
            }
            case 5:
            {
                editing();
                break;
            }
            case 6:
            {
                deleting();
                break;
            }
            case 7:
            {
                sort();
                break;
            }
            case 8:
            {
                cout << "Программа успешно завершена\n";
                return 1;
            }
            default:
                cout << "Вы ввели некорректное значение\n";
        }
        cout << "\nНажмите пробел, если желаете продолжить\n";
    } while (_getch() == 32);
}
