#include <iostream>
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
    stud *current;
    stud *next = NULL; //следующий в списке группы
    group *nextgr = NULL; //следующая группа
    int count = 0; //количество студентов в группе
    int num; //номер группы
};

string inputname()
{
    string name;
    getline(cin, name);
    return name;
}

void newstud(group *p)
{
    p->current = new stud;
    p->current->name = inputname();
}

void putingroup(group *gr, stud *st)
{
    stud *k;
    while(gr->next != NULL)
    {
        if(gr->next == NULL)
        gr->next = st;
        k = gr->next;
    }
}

int main()
{
    getchar();
    cout << "Введите имя: ";
    group *p = new group;
    newstud(p);

    cout << p->current->name;
}