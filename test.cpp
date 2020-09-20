#include <iostream>
using namespace std;

struct stud
{
    string name; // имя
    int group; //номер группы
    int grades[5]; //оценки
    int stipend; //стипендия
    stud *next;
};

struct group
{
    stud *begin = NULL; //указатель на начало списка студентов группы
    group* nextgr = NULL; //следующая группа
    int count = 0; //количество студентов в группе
    int num = 0; //номер группы
};

struct idz
{
    int stipend = 0;
    stud *begin = NULL;
    idz *nextgr = NULL;
};

group *beging = NULL;


void idzfunc(group *gr)
{
    idz *beginidz = new idz;
    beginidz->begin = gr->begin;
    beginidz->stipend = gr->begin->stipend;
    idz *idzgr = beginidz;
    while(gr != NULL)
    {
        unsigned int step;
        stud* st = gr->begin;
        while(st != NULL)
        {
            step = st->stipend;
            while(idzgr != NULL)
            {
                stud *idzst = beginidz->begin;
                while(idzst != NULL)
                {
                    if(step == idzgr->stipend)
                    {
                        if(idzst->next == NULL) idzst->next = new stud;
                        idzst->next = st;
                    }
                    idzst = idzst->next;
                }
                idzgr = idzgr->nextgr;
            }
            st = st->next;
        }
        gr = gr->nextgr;
    }

}

void idzfunc(group *gr)
{
    idz *beginidz = new idz;
    beginidz->begin = gr->begin;
    beginidz->stipend = gr->begin->stipend;
    idz *idzgr = beginidz;
    while(gr != NULL)
    {
        stud* st = gr->begin;
        while(st != NULL)
        {
            unsigned int step = st->stipend;
            if(step == idzgr->stipend)
            {
                stud *k = idzgr->begin->next;
                while(k != NULL)
                {
                    k = k->next;
                }
                if(k == NULL) k = new stud;
                k = st;
            }
            st = st->next;
        }
        gr = gr->nextgr;
    }

}


int main()
{
    group *begin;
    getchar();
    cout << "Введите имя: ";
    group *p = new group;
    idzfunc(begin);
}