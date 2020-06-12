#include <iostream>
using namespace std;

struct unit
{
    char ch;
    int number; 
    unit* next;     //ук на след эл
    unit* nextup;   //указатель на больший элемент

};

void newunit(char ch, int number, unit* a)
{
    //a = new unit;
    (*a).ch = ch;
    (*a).number = number;
    //(*a).next = NULL;
    //(*a).nextup = NULL;
}

unit* getnextpoint(unit* a)
{
    return (*a).next;
}

bool comparefrstsmin(unit* a, unit* b) //сравнивает числа у текущего указателя и предыдущего (1 - текущее значение меньше, чем предыдущее)
{
    if ((*a).number < (*b).number) return 1;
    else return 0;
}

void sort(unit* a, unit* b) //a - это текущий, b - первый, тоесть минимальный в списке
{
    (*b).nextup = (*a).nextup;
}


int main()
{
    unit* frstinput; //указатель на первый элемент для связи в порядке ввода
    unit* frstup; //указатель на 1 эл для связи больший эл
    unit* point; //бегающий указатель
//    unit* minpoint; //указатель на минимальный эл
    unit* pointup; //указатель на больший элемент
    frstinput = point;
    frstup = point;
    char ch;
    int num;
    
    
    cout << "Введите последовательность \"литера цифра\" (через пробел):\n";
    cout << "Например \"g 11\"\n";
    cin >> ch >> num;
    while (1)
    {
        if (ch == '0' && num == 0)
        {
            point = NULL;
            break;
        }
        point = new unit;
        newunit(ch,num,point);
        if (comparefrstsmin(point,frstup)) 
        {
            sort(point,frstup);
        }
        point = getnextpoint(point);
        cin >> ch >> num;
    }

    //Меню
    unsigned short menu = -1;
    while(menu!=0)
    {
        cout << "1. Вывод литер в порядке ввода\n2. Вывод чисел в порядке возрастания\n0. Выход из программы\n";
        cin >> menu;
        while (cin >> menu)
        {
            switch (menu)
            {
            case 1:
                cout << "1. Вывод литер в порядке ввода\n";
                point = frstinput;
                while((*point).next != NULL)
                {
                cout << (*point).ch << " " << (*point).number << "\n";
                point = (*point).next;
                break;
                }            
            case 2:
                cout << "2. Вывод чисел в порядке возрастания\n";
                point = frstup;
                while((*point).next != NULL)
                {
                cout << (*point).ch << " " << (*point).number << "\n";
                point = (*point).nextup;
                //break;
                }            
                break;            
            case 0:
                break;            
            default:
                cout << "Вы ошиблись, такого пункта нет!\n";
                break;
            }
        }
    }
}