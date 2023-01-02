#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <io.h>
#include <limits>
#pragma warning(disable : 4996)

using namespace std;
//«r»	Режим открытия файла для чтения.Файл должен существовать.
//«w»	Режим создания пустого файла для записи.Если файл с таким именем уже существует его содержимое стирается, и файл рассматривается как новый пустой файл.
//«a»	Дописать в файл.Операция добавления данных в конец файла. Файл создается, если он не существует.
//«r + »	Режим открытия фала для обновления чтения и записи.Этот файл должен существовать.
//«w + »	Создаёт пустой файл для чтения и записи.Если файл с таким именем уже существует его содержимое стирается, и файл рассматривается как новый пустой файл.
//«a + »	Открыть файл для чтения и добавления данных.Все операции записи выполняются в конец файла, защищая предыдущее содержания файла от случайного изменения.Вы можете изменить позицию(FSEEK, перемотка назад) внутреннего указателя на любое место файла только для чтения, операции записи будет перемещать указатель в конец файла, и только после этого дописывать новую информацию.Файл создается, если он не существует.

struct train
{
    struct //дата выезда
    {
        int date;
        int month;
        int year;
    };
    char destination[35]; //пункт назначения
    struct //время отправления
    {
        int min_time;
        int hours;
    };
    int number_of_places;//число свободных мест
};

int protection(int a, int b, int& n)
{
    while (true)
    {
        cin >> n; // ввод нужной переменной 
        while ((!cin) || (cin.get() != '\n')) // буквы 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\n Значение должно быть числом! Пожалуйста, повторите ввод\n\t>>> ";
            cin >> n;
        }
        if (n >= a && n <= b) break; // диапазон чисел
        cout << "\n Введенное число выходит за допустимый предел!\n\t[от " << a << " до " << b << "]\nПожалуйста, повторите ввод\n\t>>> ";
    }
    return n; // возвращение значения переменной
}

int protection(int, int, int&);
void printStruct(train& structura);
void filling(int& size, FILE* file);
void view(FILE* file);
void creating(FILE* file);
void quicksort(FILE* file);
void simpleselectionSort(FILE* file);
void linearSearch(FILE* file);
void indTask(FILE* file);
void binarySearch(FILE* file);
void swap(train* a, train* b);

void swap(train* a, train* b)
{
    train temp = *a;
    *a = *b;
    *b = temp;
}

void quicksort(FILE* file)
{
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(train);
    train* arr = new train[n];
    fread(arr, sizeof(train), n, file);
    fclose(file);
    train pivot, temp;
    
    file = fopen("text.txt", "wb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        delete[]arr;
        return;
    }
    fwrite(arr, sizeof(train), n, file);
    fclose(file);
    delete[]arr;
}

void printStruct(train& current)
{
    cout << current.date << "." << current.month << "." << current.year
        << "\t" << current.destination
        << "\t\t\t" << current.min_time << ":" << current.hours << "\t\t\t" << current.number_of_places;
}

void filling(int& size, FILE* file)
{
    system("cls");
    file = fopen("text.txt", "a");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    cout << "Введите количество поездов:\n\t>>> ";
    cin >> size;
    train current;
    for (int i = 0; i < size; i++)
    {
        cout << "Введите дату выезда:\n"
            << "\nВведите день выезда:\n\t>>> ";
        protection(1, 31, current.date);
        cout << "\nВведите месяц выезда:\n\t>>> ";
        protection(1, 12, current.month);
        cout << "Введите год выезда:\n\t>>> "; //интегрировать года
        protection(2000, 2024, current.year);

        cout << "Введите пункт назначения:\n\t>>> ";
        cin >> current.destination;

        cout << "\nВведите время отправления (часы)\n\t>>> ";
        protection(0, 23, current.hours);
        cout << "Введите время отправления (минуты):\n\t>>> ";
        protection(0, 59, current.min_time);

        cout << "Введите кол-во свободных мест\n\t>>> ";
        protection(0, 100, current.number_of_places);

        fwrite(&current, sizeof(train), 1, file);
    }
    fclose(file);
}

void view(FILE* file)
{
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    train current;
    cout << "Дата выезда\tПункт назначения\tВремя отправления\tЧисло свободных мест\n";
    while (fread(&current, sizeof(train), 1, file))
        printStruct(current);
    fclose(file);
    cout << "\n";
}

void creating(FILE* file)
{
    system("cls");
    file = fopen("text.txt", "wb");
    if (file == NULL)
    {
        cout << "Не удалось создать файл\n";
        return;
    }
    else
        cout << "Файл был успешно создан\n";
    fclose(file);

}

void simpleselectionSort(FILE* file)
{
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(train);
    train* arr = new train[n];
    fread(arr, sizeof(train), n, file);
    fclose(file);
    int min, i, j;
    bool flag = false;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
            if (strcmp(arr[j].destination, arr[min].destination) < 0)
                min = j;
        swap(&arr[i], &arr[min]);
    }
    file = fopen("text.txt", "wb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    fwrite(arr, sizeof(train), n, file);
    fclose(file);
    delete[]arr;
}

void linearSearch(FILE* file)
{
    system("cls");
    int key;
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(train), i;
    train* arr = new train[n];
    fread(arr, sizeof(train), n, file);
    cout << "Введите необходимое число свободных мест\n\t>>> ";
    protection(0, 100, key);
    bool flag = false;
    for (i = 0; i < n; i++)
            if (arr[i].number_of_places == key)
            { 
                flag = true;
                cout << "Дата выезда\tПункт назначения\tВремя отправления\tЧисло свободных мест\n";
                printStruct(arr[i]);
            }

    if (flag == false)
            cout << "\nНет поездов с введённым количеством свободных мест\n\n";
    delete[]arr;
    fclose(file);
    system("pause");
}

void indTask(FILE* file)
{
    simpleselectionSort(file);
    cout << "\nНеобходимо зарезервировать m мест до города N на k-й день недели с временем отправления поезда не позднее t часов.\n";
    int count = 0;
    char bochka[9] = "г. Минск";
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(train);
    train* arr = new train[n];
    fread(arr, sizeof(train), n, file);
    bool flag = false;
    for (int i = 0; i < n; i++)
        if (arr[i].number_of_places >= 8.5)
        {
            for (int bukva = 0; bukva < 8; bukva++)
                if (arr[i].destination[bukva] == bochka[bukva])
                    flag = true;
                else
                {
                    flag = false;
                    break;
                }
            if (flag)
            {
                count++;
                cout << "\nИскомый пункт назначения:";
                cout << arr[i].destination << endl;
            }
        }
    
    if (count == 0)
    {
        cout << "Нету пунктов назначения удовлетворяющих критериям поиска\n";
        return;
    }
    else
        cout << "Количество пунктов назначения удовлетворяющих критериям:\t" << count << endl;
    delete[]arr;
    fclose(file);
}

void binarySearch(FILE* file)
{
    system("cls");
    char key[100];
    simpleselectionSort(file);
    file = fopen("text.txt", "rb");
    if (file == NULL)
    {
        cout << "Не удалось открыть файл\n";
        return;
    }
    int n = _filelength(_fileno(file)) / sizeof(train);
    train* arr = new train[n];
    fread(arr, sizeof(train), n, file);
    cout << "Введите пункт назначения\n";
    cin.ignore(100, '\n');
    cin.clear();
    cin.getline(key, 101);
    int left = 0, right = n - 1, pivot = 0, count = 0;
    bool flag = false;
    while (left <= right)
    {
        pivot = (left + right) / 2;
        if (strcmp(arr[pivot].destination, key) == 0)
            flag = true;
        else
        {
            flag = false;
            count++;
        }
        if (strcmp(arr[pivot].destination, key) < 0)
            left = pivot + 1;
        else
            right = pivot - 1;
        if (flag)
        {
            cout << "Дата выезда\tПункт назначения\tВремя отправления\tЧисло свободных мест\n";
            printStruct(arr[pivot]);
            return;
        }
        if (count == n - 1)
            break;
    }
    if (flag == false)
    {
        cout << "Искомый студент не найден\n";
        return;
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    cout << "\n\n\nВ кассе имеется информация о поездах на ближайшую неделю:\n"
        << " дата выезда, пункт назначения, время отправления, число свободных мест.\n"
        << " Необходимо зарезервировать m мест до города N на k - й день недели с временем отправления поезда не позднее t часов.\n"
        << " Вывести время отправления или сообщение о невозможности выполнить заказ.\n" 
        << " Ключ : число свободных мест.\n\n\n";
    system("pause");
    FILE* file = NULL;
    int num, size = 0;
    bool end = false;
    do   
    {
        system("cls");
        cout << "Данные в файле :\n";
        view(file);
        cout << "\nВыберите, что вы хотите сделать с файлом\n"
            << " 1. Создать\n 2. Добавить данные\n 3. Линейный поиск\n 4. Пузырьковая сортировка\n"
            << " 5. Индивидуальное задание\n"
            << " 6. QuickSort\n 7. Бинарный поиск\n 0. Выход\n\t>>> ";
        protection(0, 7, num);
        switch (num)
        {
        case 1:
        {
            creating(file);
            break;
        }
        case 2:
        {
            filling(size, file);
            break;
        }
        case 3:
        {
            linearSearch(file);
            break;
        }
        case 4:
        {
            simpleselectionSort(file);
            view(file);
            break;
        }
        case 5:
        {
            indTask(file);
            break;
        }
        case 6:
        {
            system("cls");
            quicksort(file);
            view(file);
            break;
        }
        case 7:
            system("cls");
            binarySearch(file);
            break;
        case 0:
        {
            end = true;
            break;
        }
        default:
            cout << "Вы ввели некорректное значение, повторите ввод\n";
        }    
    } while (end == false);
    return 0;
}