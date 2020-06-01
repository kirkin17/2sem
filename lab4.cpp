#include <iostream>
using namespace std;

struct unit
{
    char ch;
    int num; 
    unit* next;     //ук на след эл
    unit* nextmore; //указатель на больший элемент

};

int newunit(char ch, int num, unit* a)
{
    a = new unit;
    (*a).ch = ch;
    (*a).num = num;
}

int main()
{
    unsigned short menu = -1;
    unit* p; //указатель на первый элемент для связи в порядке ввода
    unit* n; //указатель на 1 эл для связи больший эл
    unit* k; //бегающий указатель
    p = n;
    k = p;
    cout << "Введите последовательность \"литера цифра\" (через пробел):\n";
    while (1)
    {
        char ch;
        int num;
        cin >> ch >> num;
        if (ch == '0' && num == 0) break;
        newunit(ch,num,k);
    }    
    while(menu!=0)
    {
        cout << "1. Вывод литер в порядке ввода\n2. Вывод чисел в порядке возрастания\n0. Выход из программы\n";
        cin >> menu;
        while (cin >> menu)
        {
            switch (menu)
            {
            case 1:

                break;            
            case 2:
                
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