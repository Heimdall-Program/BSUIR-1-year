#include <iostream> 
#include <conio.h> 
#include <cmath> 
using namespace std;

struct queue
{
    double info;
    queue* next, * prev;
};

void protection(int a, int b, int& n);
int NumberOfElements(queue* top);
queue* InStack(queue* top, int data);
queue* OutStack(queue* top, int* out);
void InStack_Finish(queue* top, int data);
void InStack_Finish(queue* top, int data);
queue* DelFull(queue* top);
queue* DelFromStart(queue* top, int n);
queue* DelFromFinish(queue* top, int n);
void ViewFinish(queue* top);
void ViewBegin(queue* top);
queue* deleteHalf(queue* top);
queue* IndTask(queue* top);
queue* New_Stack();


void protection(int a, int b, int& n)
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
}

int NumberOfElements(queue* top) { 
    int n = 0;
    while (top) {
        top = top->next;
        n++;
    }
    return n;
}
queue* InStack(queue* top, int data) { 
    queue* t = new queue;
    t->info = data;
    t->next = top;
    t->prev = nullptr;
    if (top) top->prev = t;
    return t;
}
queue* OutStack(queue* top, int* out) {  //Получение инфоомации из вершины стека с извлечением 
    queue* t = top;
    *out = top->info;
    top = top->next;
    if (top) 
        top->prev = nullptr;
    delete t;
    return top;
}
void InStack_Finish(queue* top, int data) {
    queue* t = new queue;
    while (top->next) 
        top = top->next;
    t->info = data;
    t->next = NULL;
    t->prev = top;
    top->next = t;
}
queue* InStack_Start(queue* top, int data) {
    queue* t = new queue;
    t->info = data;
    t->prev = NULL;
    t->next = top;
    top->prev = t;
    return t;
}
queue* DelFull(queue* top) { //полная очистка
    queue* t;
    while (top)
    {
        t = top;
        top = top->next;
        delete t;
    }
    return top;
}
queue* DelFromStart(queue* top, int n) {
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    if (top) 
    {
        queue* t;
        int kol = NumberOfElements(top), i;
        if (n > kol) {
            cout << "\nВ стеке нет столько элементов!\nОчередь очищена полность\n";
            n = kol;
        }
        for (i = 0; i < n; i++) {
            t = top;
            top = top->next;
            if (top) top->prev = NULL;
            delete t;
        }
    }
    return top;
}
queue* DelFromFinish(queue* top, int n) { 
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    queue* t, * end = NULL;
    int kol = NumberOfElements(top);
    while (top->next) 
        top = top->next;
    if (n > kol) 
    {
        cout << "\nВ стеке нет столько элементов!\nОчередь очищена полность.\n";
        n = kol;
    }
    for (int i = 0; i < n; i++) 
    {
        t = top;
        top = top->prev;
        if (top) 
            top->next = NULL;
        else  return 0;
        delete t;
    }
    while (top->prev) top = top->prev;
    return top;
}
void ViewFinish(queue* top) 
{
    cout << "Список с конца:\n";
    if (top) 
    {
        while (top->next) top = top->next;
        while (top)
        {
            cout << top->info << "\t";
            top = top->prev;
        }
    }
}
void ViewBegin(queue* top) 
{
    cout << "Список с начала:\n";
    while (top) {
        cout << top->info << "\t";
        top = top->next;
    }
}
queue* deleteHalf(queue* top) 
{
    cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
    int n = NumberOfElements(top), inf, del = 0;
    if (n % 2 == 0) del++;
    queue* new_element = NULL;
    while (top) 
    {
        top = OutStack(top, &inf);
        if (n % 2 == del) new_element = InStack(new_element, inf);
        n--;
    }
    queue* new_stack = NULL;
    while (new_element) 
    {
        new_element = OutStack(new_element, &inf);
        new_stack = InStack(new_stack, inf);
    }
    return new_stack;
}

queue* IndTask(queue* top) 
{
    system("cls");
    if (top->next == NULL)
    {
        cout << "\n\tВ очереди остался один элемент\n";
        return top;
    }
        queue* max = top;
        queue* t = top;
        while (t->next != NULL)
        {
            t = t->next;
            if (t->info > max->info)
                max = t;

        }
        cout << "\nМаксимальный элемент = " << max->info << endl;
        if (max->next != NULL)
        {
            if (max->prev != NULL)
            {
                t = max->prev;
                t->next = max->next;
                max->next->prev = t;

            }
            else
            {
                top = top->next;
                top->prev = NULL;

            }
        }
        else
        {
            t = max->prev;
            t->next = NULL;
        }
        delete max;
        return top;
    
}
queue* New_Stack() {
    queue* begin = NULL, * end = NULL, * t;
    int n, in;
    cout << "\n\tВведите кол-во элементов:\n\t\t>>> ";
    protection(1, 15, n);
    t = new queue;
    cout<< "\n\tЭлемент = ";
    protection(-10000, 10000, in); 
    t->info = in;
    t->next = t->prev = begin;
    begin = end = t;
    for (int i = 1; i < n; i++) 
    {
        t = new queue;
        cout << "\n\tЭлемент = ";
        protection(-10000, 10000, in);
        t->info = in;
        t->next = NULL;
        t->prev = end;
        end->next = t;
        end = t;
    }
    return begin;
}

int main() {
    setlocale(LC_ALL, "Russian");
    queue* top = New_Stack();
    cout << "Введенный вами список:\n";
    ViewBegin(top);
    cout << endl;
    ViewFinish(top);
    int elements, i, check;
    while (true) 
    {
        if (top == NULL) {
            system("cls");
            cout << "\nОчередь пуста!\n\t1 - продолжить работу\n\t2 - завершить работу.\n\t\t>>> ";
            queue* begin;
            protection(1, 2, check);
            switch (check) 
            {
            case 1:
                begin = New_Stack();
                top = begin;
                ViewBegin(top);
                cout << endl;
                ViewFinish(top);
                break;
            case 2:
                return 0;
            }
        }
        cout << "\n\n1 - добавить n элементов\n2 - Удаление элементов на нечётных местах"
            << "\n3 - удалить n элементов\n4 - Индивидуальное задание\n0 - завершить работу\n";
        protection(0, 4, check);
        switch (check) 
        {
        case 1:
            system("cls");
            int n;
            cout << "\n\tВведите сколько элементов вы желатете добавить:\n\t\t>>> ";
            protection(1, 15, elements);
            cout << "\nВыберите, куда вы хотите добавить элементы:\n1 - В начало\nИначе - В конец\n";
            switch (_getch()) {
            case '1':
                for (i = 0; i < elements; i++) {
                    cout << "\n\tЭлемент =";
                    protection(-10000, 10000, n);
                    top = InStack_Start(top, n);
                }
                cout << "\nРезультат добавления:\n";
                ViewBegin(top);
                cout << endl;
                ViewFinish(top);
                break;
            default:
                for (i = 0; i < elements; i++) {
                    cout << "\n\tЭлемент =";
                    protection(-10000, 10000, n);
                    InStack_Finish(top, n);
                }
                cout << "\nРезультат добавления:\n";
                ViewBegin(top);
                cout << endl;
                ViewFinish(top);
                break;
            }
            break;
        case 2:
            if (top == NULL)
            {
                cout << "Очередь пуста\n";
                break;
            }
            cout << "\nУдаление элементов на нечётных позициях";
            top = deleteHalf(top);
            cout << "\nРезультат извлечения:\n";
            ViewBegin(top);
            cout << endl;
            ViewFinish(top);
            break;
        case 3:
            if (top == NULL)
            {
                cout << "Очередь пуста\n";
                break;
            }
            system("cls");
            int Some;
            cout << "\n\tВведите сколько элементов вы желатете удалить:\n\t\t>>> ";
            protection(1, 10, Some);
            cout << "Выберите, с какого места удалить:\n1 - С начала\nИначе - С конца\n";
            switch (_getch()) {
            case '1':
                cout << "Результат удаления:\n";
                top = DelFromStart(top, Some);
                if (top) 
                {
                    ViewBegin(top);
                    cout << endl;
                    ViewFinish(top);
                }
                break;
            default:
                cout << "Результат удаления:\n";
                top = DelFromFinish(top, Some);
                if (top) {
                    ViewBegin(top);
                    cout << endl;
                    ViewFinish(top);
                }
                break;
            }
            break;
        case 4:
            if (top == NULL)
            {
                cout << "Очередь пуста\n";
                break;
            }
            cout << "\nУдаление максимального элемента";
            top = IndTask(top);
            cout << "\nРезультат извлечения:\n";
            ViewBegin(top);
            cout << endl;
            ViewFinish(top);
            break;
        case 0:
            top = DelFull(top);
            return 0;
        }
    }
}