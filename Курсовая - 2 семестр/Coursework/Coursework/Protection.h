#pragma once // защита от двойного подключения заголовочных файлов
#include <iostream> // для работы с консолью (ввод-вывод)

using namespace std;

int protection(int a, int b, int& n); // защита от букв и чисел (от a до b) с переменной n 
string inputPassword(); // ввод пароля