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
    (*a).ch = ch;
    (*a).number = number;
}

unit* getnextpoint(unit* a)
{
    return (*a).next;
}

bool compare(unit* a, unit* b) // 1 если первое меньше
{
    if ((*a).number < (*b).number) return 1;
    else return 0;
}

void sort(unit* a, unit* b) //a - это текущий, b - первый, тоесть минимальный в списке
{
    (*a).nextup = b;
    b = a;
}


int main()
{
    unit* frstinput; //указатель на первый элемент для связи в порядке ввода
    unit* frstup; //указатель на 1 эл для связи больший эл
    unit* point; //бегающий указатель
    unit* pointup; //указатель на больший элемент
    char ch;
    int num;
    
    
    cout << "Введите последовательность \"литера цифра\" (через пробел):\n";
    cout << "Например \"g 11\"\n";
    cin >> ch >> num;
    if (ch == '0' && num == 0) return 0; //если сразу же вводим 0 0
    point = new unit;
    newunit(ch,num,point);
    frstinput = point;
    frstup = point;
    pointup = point;
    while (1)
    {
        if (compare(point,frstup))
        {
            (*point).nextup = frstup;
            frstup = point;
        }
        if compare(point,)
        {
            (point).nextup = 
        }
        //cout << comparefrstsmin(point,frstup) << "\n";
        cin >> ch >> num;
        if (ch == '0' && num == 0)
        {
            (*point).next = NULL;
            break;
        }
        (*point).next = new unit;
        point = (*point).next;
        newunit(ch,num,point);
    }

    //Меню
    unsigned short menu = -1;
    while(menu!=0)
    {
        cout << "1. Вывод литер в порядке ввода\n2. Вывод чисел в порядке возрастания\n0. Выход из программы\n";
        cin >> menu;
            switch (menu)
            {
            case 1:
                //system("clear");
                cout << "1. Вывод литер в порядке ввода\n";
                point = frstinput;
                while(point != NULL)
                {
                cout << (*point).ch << " " << (*point).number << "\n";
                point = (*point).next;
                //cout << "Нажмите любую клавишу для продолжения...\n";
                }  
                menu = -1;
                break;          
            case 2:
                //system("clear");
                cout << "2. Вывод чисел в порядке возрастания\n";
                point = frstup;
                while(point != NULL)
                {
                cout << (*point).ch << " " << (*point).number << "\n";
                point = (*point).nextup;
                }
                menu = -1;         
                break;            
            case 0:
                break;            
            default:
                cout << "Вы ошиблись, такого пункта нет!\n";
                break;
            }
    }
}