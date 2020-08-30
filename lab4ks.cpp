#include <iostream>
using namespace std;

struct unit
{
    char ch = '0';
    int num = 0;
    unit* next = NULL;
    unit* nextup = NULL;
};


int main() 
{
    setlocale(LC_ALL, "ru");
    unit* lastch = new unit;
    unit* frstinput = lastch;
    unit* frstup;
    unit* lastnum = frstup = frstinput;

    cout << "Введите последовательность \"литера цифра\" (через пробел):\n";
    cout << "Например \"g 11\"\n";
    cout << "Признак окончания \"0 0\"\n";

    do
    {
        char letter;
        int number;
        cin >> letter >> number;
        if (letter == '0' && !number) break;
        lastch->ch = letter;
        lastch->num = number;

        if (number < frstup->num)
        {
            lastch->nextup = frstup;
            frstup = lastch;
        }
        else
            for (unit* i(frstup); 1; i = i->nextup)
                if (!i->nextup || i->nextup->num >= number)
                {
                    if (i == lastch) break;
                    if (!i->nextup) lastnum = lastch;
                    lastch->nextup = i->nextup;
                    i->nextup = lastch;
                    break;
                }
        lastch->next = new unit;
        lastch = lastch->next;
    } 
    while (1);

    do {
        int menu = 0;

        cout << endl;
        cout << "Меню\n";
        cout << "1) Вывод литер в порядке ввода\n";
        cout << "2) Вывод чисел в порядке возрастания\n";
        cout << "3) Выход из программы\n";
        cin >> menu;
        cout << endl;

        if (menu == 3) return 0;
        if (frstinput->ch == '0' && !frstinput->num) continue;
        for (unit* pointch(frstinput); menu == 1 && pointch != lastch; pointch = pointch->next)
        {
            cout << pointch->ch << " ";
        }
        for (unit* pointnum(frstup); menu == 2; pointnum = pointnum->nextup)
        {
            cout << pointnum->num << " ";
            if (pointnum == lastnum) break;
        }
    } 
    while (1);
}