#include <iostream>
using namespace std;


int main() 
{
    char b;
    printf("Введите символ: ");
    
    for (int i = 0; i < 8; i++) 
    {
        printf("%c", (b & 0x80) ? '1' : '0');
        b <<= 1;
    }
}