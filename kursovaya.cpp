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
    stud* next = NULL; //следующий в списке группы
    group* nextgr = NULL; //следующая группа
    int count = 0; //количество студентов в группе
    int num; //номер группы
};

string inputname()
{
    string name;
    cin.ignore(256, '\n');
    getline(cin, name);
    return name;
}

void inputstudent(group *begingroup)
{
    stud *p = new stud;
    system("clear");
    cout << "Введите ФИО студента: ";
    p->name = inputname();
    cout << "Введите номер группы: ";
    int group;
    cin >> group;
    p->group = group;
    if (begingroup == NULL)//////////////////////////////////////////////////////////////////////////////////////////////
    {

    }
    cout << "Введите оценки: ";
    int grades[5];
    for(int i = 0; i < 5; i++)
    {
        printf("[%d]. ", i + 1);
        cin.ignore(256, '\n');
        cin >> grades[i];
        p->grades[i] = grades[i];
    }
    cout << "Введите размер стипендии: ";
    int stipend;
    cin.ignore(256, '\n');
    cin >> stipend;
    p->stipend = stipend;
}

void newstudentkeyboard(group *current)
{
    current->current = new stud;
    if (current->begin == NULL)
    {
        current->begin = current->current;
    }

    system("clear");
    cout << "Введите ФИО студента: ";
    current->current->name = inputname();
    cout << "Введите номер группы: ";
    int group;
    cin >> group;
    current->current->group = group;
    current->num = group;
    cout << "Введите оценки: ";
    int grades[5];
    for(int i = 0; i < 5; i++)
    {
        printf("[%d]. ", i + 1);
        cin.ignore(256, '\n');
        cin >> grades[i];
        current->current->grades[i] = grades[i];
    }
    cout << "Введите размер стипендии: ";
    int stipend;
    cin.ignore(256, '\n');
    cin >> stipend;
    current->current->stipend = stipend;
}

void outputkeyboard(group *p)
{
    system("clear");
    while (p != NULL)
    {
        while(p->current != NULL)
        {
            cout << "Группа: " << p->num << endl;
            cout << "\tФИО:" << p->current->name << endl;
            cout << "\tГруппа: " << p->current->group << endl;
            cout << "\tСтипендия: " << p->current->stipend << endl;
            cout << "\tОценки:\n";
            for (int i = 0; i < 5; i++)
            {
                cout << "\t\t" << i + 1 << ". " << p->begin->grades[i] << endl;
            }
            p->current = p->next;
        }
        p = p->nextgr;        
    }
    cout << "\n\nДля продолжения нажмите enter...\n";
    cin.ignore(256, '\n');
    getchar();
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int menu;

    group *current, *begin, *p; //сразу создаем указатели для создания хотя бы одной группы
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
            newstudentkeyboard(current);
        }
        if (menu == 2)
        {
            outputkeyboard(begin);
        }
    }
    while (menu != 0);
    return 0;
}