#include<iostream>
using namespace std;

int MUL_ND_N(int* ykaz, int an, int ch) { //N6, Автор - Ольга Валерьева
	int otw;
//    otw = new int[an];
    for (int i = 0; i < an; i++) {
		otw += (ykaz[i]*(10*(an-i-1))) * ch;
	}
    std::cout << otw;   
//    ykaz = otw;
//    for (int i = 0; i < an; i++)
//    { 
//        std::cout << otw;    
//    } std::cout << endl;
	return 0;
}



int main()
{
    using namespace std;
    unsigned int an, bn;
    int* a, *b;

    //input
    cout << "Vvedite kolvo cifr a: ";
    cin >> an;
    a = new int[an];
    for (int i = 0; i < an; i++)
    {   
        cout << "[" << i+1 << "]: "; 
        cin >> a[i];     
    }cout << endl;

    cout << "Vvedite kolvo cifr b: ";
    cin >> bn;
    b = new int[bn];
    for (int i = 0; i < bn; i++)
    { 
        cout << "[" << i+1 << "]: ";    
        cin >> b[i];     
    }cout << endl;
    
    //out
    for (int i = 0; i < an; i++)
    { 
        cout << a[i];    
    } cout << endl;
    for (int i = 0; i < bn; i++)
    { 
        cout << b[i];    
    } cout << endl;

    //mult
    MUL_ND_N(a,an,bn);


    //out
    for (int i = 0; i < an; i++)
    { 
        cout << a[i];    
    } cout << endl;
    for (int i = 0; i < bn; i++)
    { 
        cout << b[i];    
    } cout << endl;
}





















int ADD_NN_N(int a[], int an, int b[], int bn) { //N4, Автор - Эвелина Семенова
	int otv = 0; //создается элемент для ответа
	for (int i = 0; i < b; i++) {
		otv = ykaz[i] + otv; //все элементы поочередно складываются
	}
	return otv; //возвращаю ответ
}

int MUL_ND_N(int ykaz[], int b, int ch) { //N6, Автор - Ольга Валерьева
	int* otw;
    otw = new int[b];
    for (int i = 0; i < b; i++) {
		otw[i] += ykaz[i] * ch;
	}
    ykaz = otw;
    delete[] otw;
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