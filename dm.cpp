#include <iostream>
using namespace std;

int main()
{
    unsigned int a,b,x,y;
    unsigned short int t;
    cin >> t; //кол-во наборов
    for(unsigned short int i = 0; i < t; i++)
    {
        unsigned short int n;
        cin >> a; //первое число
        cin >> b; //второе число число
        if (a == b) continue;
        if (a > b) 
        {
            if ((a - b)%2 == 0) { a = a - b; n++; continue; }
            else { a = a - ((a-b)+1); a = a + 1; }
        }
    }
    cout << n;
}