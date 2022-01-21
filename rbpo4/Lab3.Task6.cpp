#include <iostream>
#include <windows.h>

import Task1;
import Task2;
import Task3;
import Task4;
import Task5;

using namespace std;
using namespace RBPO::Lab3;

void showTasks();

int choiceTask = 0;
int x;
int n;
double e;

int main()
{
    // Делаем возможным вывод русских символов в консоль
    SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
    SetConsoleOutputCP(1251); // установка кодовой страницы win-cp 1251 в поток вывода

    do
    {
        // Очищаем консоль
        system("cls");
        cout << "Введите номер задания (1-5), или 0 для выхода: \n";
        cin >> choiceTask;
        if (choiceTask == 0)
            break;
        else if (choiceTask > 0 && choiceTask <= 5)
        {
            cout << "Введите параметры X, N и Epsilon через пробел: \n";
            cin >> x >> n >> e;
            showTasks();
        }
        else
            continue;
    } while (choiceTask != 0);

    return 0;
}


void showTasks()
{
    switch (choiceTask)
    {
    case 1:
        cout << "Используется пространство имен RBPO::Lab3::Task1\n";
        cout << "Результат вычисления f1(x)=:" << Task1::f1(x) << endl;
        cout << "Результат вычисления f2(x)=:" << Task1::f2(x) << endl;
        cout << "Результат вычисления f3(x)=:" << Task1::f3(x, n) << endl;
        cout << "Результат вычисления f4(x)=:" << Task1::f4(x, e) << endl;
        system("pause");
        break;
    case 2:
        cout << "Используется пространство имен RBPO::Lab3::Task2\n";
        cout << "Результат вычисления f1(x)=:" << Task2::f1(x) << endl;
        cout << "Результат вычисления f2(x)=:" << Task2::f2(x) << endl;
        cout << "Результат вычисления f3(x)=:" << Task2::f3(x, n) << endl;
        cout << "Результат вычисления f4(x)=:" << Task2::f4(x, e) << endl;
        system("pause");
        break;
    case 3:
        cout << "Используется пространство имен RBPO::Lab3::Task3\n";
        cout << "Результат вычисления f1(x)=:" << Task3::f1(x) << endl;
        cout << "Результат вычисления f2(x)=:" << Task3::f2(x) << endl;
        cout << "Результат вычисления f3(x)=:" << Task3::f3(x, n) << endl;
        cout << "Результат вычисления f4(x)=:" << Task3::f4(x, e) << endl;
        system("pause");
        break;
    case 4:
        cout << "Используется пространство имен RBPO::Lab3::Task4\n";
        cout << "Результат вычисления f1(x)=:" << Task4::f1(x) << endl;
        cout << "Результат вычисления f2(x)=:" << Task4::f2(x) << endl;
        cout << "Результат вычисления f3(x)=:" << Task4::f3(x, n) << endl;
        cout << "Результат вычисления f4(x)=:" << Task4::f4(x, e) << endl;
        system("pause");
        break;
    case 5:
        cout << "Используется пространство имен RBPO::Lab3::Task5\n";
        cout << "Результат вычисления f1(x)=:" << Task5::f1(x) << endl;
        cout << "Результат вычисления f2(x)=:" << Task5::f2(x) << endl;
        cout << "Результат вычисления f3(x)=:" << Task5::f3(x, n) << endl;
        cout << "Результат вычисления f4(x)=:" << Task5::f4(x, e) << endl;
        system("pause");
        break;
    default:
        break;
    }
}