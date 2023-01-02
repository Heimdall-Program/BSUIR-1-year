#pragma once // защита от двойного подключения заголовочных файлов
#include <iostream> // для работы с консолью (ввод-вывод)
#include <Windows.h>

using namespace std;

// желаете сохранить? 
void canISaveNow(); 
// такого аккаунта нет в системе
void noAccount(); 
//Успешное сохранение
void successSave(); 
// вывод ошибки, если несколько раз введен не тот пароль
void isfalsePassword(string, bool&, int&); 
