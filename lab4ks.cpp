#include <iostream>
using namespace std;
//Объявили структуру 
struct Node{
    char litera = '0';
    int nb = 0;
    Node* next = NULL;
    Node* nextA = NULL;
};


int main() {
    setlocale(LC_ALL, "ru");

    Node* lastLitera = new Node, * const firstLit = lastLitera;
    Node* firstA, * lastA = firstA = firstLit;

    cout << "Введите парy литера – число" << endl;
    cout << "Введите \"0 0\" чтобы перейти к меню" << endl;

    //Для литер ( запоминать порядок их ввода)
    do {
        char letter;
        int number;
        //Вводим пару литера-число
        cin >> letter >> number;

        if (letter == '0' && !number)
            break;

        lastLitera->litera = letter;
        lastLitera->nb = number;

        if (number < firstA->nb) {
            lastLitera->nextA = firstA;
            firstA = lastLitera;
        }
        else
            for (Node* i(firstA); 1; i = i->nextA)
                if (!i->nextA || i->nextA->nb >= number) {
                    if (i == lastLitera)
                        break;

                    if (!i->nextA)
                        lastA = lastLitera;

                    lastLitera->nextA = i->nextA;
                    i->nextA = lastLitera;
                    break;
                }

        lastLitera->next = new Node;
        lastLitera = lastLitera->next;
    } while (1);

    //Для чисел (которые в последствие сортируются в цикле)
    do {
        int numb = 0;

        cout << endl << endl;
        cout << "Меню" << endl;
        cout << "1) Вывод литер в порядке ввода" << endl;
        cout << "2) Вывод чисел в порядке возрастания" << endl;
        cout << "3) Выход из программы" << endl << endl;
        cin >> numb;

        if (numb == 3)
            return 0;

        if (firstLit->litera == '0' && !firstLit->nb)
            continue;

        for (Node* currentLit(firstLit); numb == 1 && currentLit != lastLitera; currentLit = currentLit->next)
            cout << currentLit->litera << ", ";

        for (Node* currentA(firstA); numb == 2; currentA = currentA->nextA)
        {
            cout << currentA->nb << ", ";

            if (currentA == lastA)
                break;
        }
    } while (1);
}