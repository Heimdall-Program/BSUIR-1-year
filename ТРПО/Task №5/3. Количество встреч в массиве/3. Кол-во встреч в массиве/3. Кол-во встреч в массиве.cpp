#include <iostream>
#include <math.h>
#include <ctime>
using namespace std;

int* move_right(int size, int* array)
{
    int step, t = 0, i, q, u;
    cout << "\nВведите смещение\n";
    cin>> step;
    while (t != step)
    {
        q = array[0];
        for (i = 0; i < size - 1; i++)
        {
            u = array[i + 1];
            array[i + 1] = q;
            q = u;
        }
        array[0] = q;
        t++;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    return array;
}
int* generateArray(int size)
{
    int left, right;
    cout << "Введите промежуток\n";
    cin >> left >> right;
    int* array = new int[size];
    srand(time(0));
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (right+1) - (right-left);
    }
    return array;
}
char* generateCharArray(int size)
{
    int left, right;
    cout << "Введите промежуток кодов символов\n";
    cin >> left >> right;
    char* charArray = new char[size];
    srand(time(0));
    for (int i = 0; i < size; i++) {
        charArray[i] = rand() % (right + 1) - (right-left);
    }
    return charArray;
}
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}
void printArray(char* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
}
int meetings(int* array, int size, int number)
{
    int meetings = 0;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == number)
            meetings++;
    }
    return meetings;
}
int meetings(char* charArray, int size, char letter)
{
    int amountOfMeetings = 0;
    for (int i = 0; i < size; i++)
    {
        if (charArray[i] == letter)
            amountOfMeetings++;
    }
    return amountOfMeetings;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    string str;
    char symboll;
    int size, number = 0, task;
    cout << "Введите 1, если хотите работать с int, а 2 для char\n";
    cin >> task; 
    cout << "\nВведите кол-во элементов массива\n";
    cin >> size;
    switch (task)
    {
    case 1:
        int* array;
        array = generateArray(size);
        printArray(array, size);
        //cout << "\nВведите число\n";
       // cin >> number;
       // cout << "Число повторений этого числа в массиве= " << meetings(array, size, number);
        move_right(size, array);
        break;
    case 2:
        char* charArray;
        charArray = generateCharArray(size);
        printArray(charArray, size);
        cout << "\nВведите символ\n";
        cin >> symboll;
        cout << "Число повторений этого символа в массиве= " << meetings(charArray, size, symboll);
        break;
        
    }
    return 0;
}