#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

struct stud
{
    string name; // имя
    int group; //номер группы
    int grades[5]; //оценки
    int stipend; //стипендия
};

struct group
{
    stud *begin = NULL; //указатель на начало списка студентов группы
    stud *current = NULL;
    int count = 0; //количество студентов в группе
    int num; //номер группы
    stud* next = NULL; //следующий в списке группы
};

string inputname()
{
    string name;
    getline(cin, name);
    return name;
}

void newstudent(group *current)
{
    current->current = new stud;
    system("clear");
    cout << "Введите ФИО студента: ";
    string name;
    name = inputname();
    current->current->name = name;
    cout << "Введите номер группы: ";
    int group;
    cin >> group;
    current->current->group = group;
    cout << "Введите оценки: ";
    int grades[5];
    for(int i=0; i < 5; i++)
    {
        printf("[%d]. ", i + 1);
        cin >> grades[i];
        current->current->grades[i] = grades[i];
    }
    cout << "Введите размер стипендии: ";
    int stipend;
    cin >> stipend;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int menu;

    group *current, *begin, *p; //сразу создаем указатели для создания хотя бы одной группы и студента
    current = new group;
    begin = current;

    do
    {
        system("clear");
        cout << "Меню" << endl << " 1. Ввести данные о студенте с клавиатуры" << endl;
        cout << " 2. Вывести список студентов на экран" << endl;
        cout << " 3. Ввести данные о студентах из файла (\"in.txt\")" << endl;
        cout << " 4. Вывести список студентов в файл (\"out.txt\")" << endl;
        cout << " 5. Изменить данные о студенте" << endl;
        cout << " 6. Удалить студента" << endl;
        cout << " 7. Удалить группу" << endl;
        cout << " 8. Вывести студентов, сгруппированных по размеру стипендии(ИДЗ)" << endl;
        cout << " 0. Выход" << endl;
        cin >> menu;
        if (menu == 1)
        {
            newstudent(current);
        }
        if (menu == 2)
        {
            p = begin;
            while (p != NULL)
            {
                cout << "Группа " << p->num << endl;
                cout << "\tФИО:" << p->begin->name << endl;
                cout << "\tГруппа: " << p->begin->group << endl;
                cout << "\tСтипендия: " << p->begin->stipend << endl;
                cout << "\tОценки:\n";
                for (int i = 0; i < 5; i++)
                {
                    cout << "\t" << i + 1 << ". " << p->begin->grades[i] << endl;
                }
                
            }
        }
    }
    while (menu != 0);
    return 0;
}