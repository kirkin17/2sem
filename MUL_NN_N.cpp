#include <iostream>
using namespace std;
//Прохоренко Кирилл 9371

int ADD_NN_N(int ykaz[], int b) { //N4, Автор - Эвелина Семенова
	int otv = 0; //создается элемент для ответа
	for (int i = 0; i < b; i++) {
		otv = ykaz[i] + otv; //все элементы поочередно складываются
	}
	return otv; //возвращаю ответ
}
int MUL_ND_N(int ykaz[], int b, int ch, int otw[]) { //N6, Автор - Ольга Валерьева
	for (int i = 0; i < b; i++) {
		otw[i] = ykaz[i] * ch;
	}
	return 0;
}

int MUL_Nk_N(int ykaz[], int b, int ch, int otw[]) { //N7, Автор - Ольга Валерьева
	int ch1 = 10; //cоздаем число, на которое будем умножать
	for (int i = 1; i < ch; i++) {
		ch1 *= 10; //считаем 10^k
	}
	MUL_ND_N(ykaz, b, ch1, otw);
	return 0;
}

void MUL_NN_N(int* a, int na, int* b, int nb)
{
    if (na > nb)
    {
        for (int i = na; i >= 0; --i)
        {
            for (int j = nb; j >= 0; --j)
            {
                MUL_ND_N()
            }
        }
    }
}

int main()
{
    using namespace std;
    unsigned int na, nb;
    int* a, *b;

    //input
    cout << "Vvedite kolvo cifr a: ";
    cin >> na;
    a = new int[na];
    for (int i = 0; i < na; i++)
    {   
        cout << "[" << i+1 << "]: "; 
        cin >> a[i];     
    }cout << endl;

    cout << "Vvedite kolvo cifr b: ";
    cin >> nb;
    b = new int[nb];
    for (int i = 0; i < nb; i++)
    { 
        cout << "[" << i+1 << "]: ";    
        cin >> b[i];     
    }cout << endl;
    
    //out
    for (int i = 0; i < na; i++)
    { 
        cout << a[i];    
    } cout << endl;
    for (int i = 0; i < nb; i++)
    { 
        cout << b[i];    
    } cout << endl;

    //mult
    MUL_NN_N(a,na,b,nb);


    //out
    for (int i = 0; i < na; i++)
    { 
        cout << a[i];    
    } cout << endl;
    for (int i = 0; i < nb; i++)
    { 
        cout << b[i];    
    } cout << endl;
}