#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

string reverse(string line) {
    int i, length = line.size();
    char letter;
    for (i = 0; i < length / 2; ++i) {
        letter = line[i];
        line[i] = line[length - i - 1];
        line[length - i - 1] = letter;
    }
    return line;
}
struct student
{
    string name;
    int age = 0;
    double averageMark = 0;
    int lotOfTests = 0;
};

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
        file >> list[i].name;
        file >> list[i].age;
        file >> list[i].averageMark;
        file >> list[i].lotOfTests;
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
        file << line[i].name << " " << line[i].age << " " << line[i].averageMark << " " << line[i].lotOfTests << endl;
    file.close();
}

int main()
{
    setlocale(LC_ALL,"Russian");
    do
    {
    system("cls");
    int size = 1;
    student* list = readFile("text.txt", size);
    printInFile("text.txt", list, size, ios_base::app);

    fstream file("text.txt");
    file.seekg(0, ios::end);
    cout << "Количество байт - " << file.tellg();
    file.close();

    string line, lines[1025];
    int number_of_lines = 0;
    ifstream input("text.txt", ios::in);  
    while (!input.eof()) 
    {
       getline(input, line);      
       lines[number_of_lines]= reverse(line);
       number_of_lines++;
    }
    input.close(); 

    ofstream output("text.txt", ios::in);
    for (int i = 0; i < number_of_lines-1; i++) output << lines[i] << endl;
    output.close(); 
    } while (_getch() == 32);
    return 0;
}