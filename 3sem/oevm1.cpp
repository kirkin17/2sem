#include <iostream>
using namespace std;



void numbersint()
{
    system("clear");
    cout << "Выберите систему счисления:\n\n";
    cout << "1. 10\n";
    cout << "2. 16\n";
    cout << "3. 8\n";
    cout << "4. 2\n";
    cout << "0. Назад\n\n";
    cout << "Выберите: ";
    int menu;
    while (1)
    {
		cin >> menu;
		if (cin.good() && menu >= 0 && menu <= 4) break;
		cin.clear();
		cin.ignore(100, '\n');
        system("clear");
        cout << "Выберите систему счисления:\n\n";
        cout << "1. 10\n";
        cout << "2. 16\n";
        cout << "3. 8\n";
        cout << "4. 2\n";
        cout << "0. Назад\n\n";
        cout << "Выберите: ";
	}
    if (menu == 1)
    {
        system("clear");
        int b;
        cout << "Введите число: ";
        while (1)
        {
		    scanf("%d", b);
		    if (cin.good()) break;
		    cin.clear();
		    cin.ignore(100, '\n');
            system("clear");
            cout << "Введите число: ";
	    }
        for (int i = 0; i < 32; i++) 
        {
            printf("%c", (b & 0x80000000) ? '1' : '0');
            b <<= 1;
        }
        
    }

    if (menu == 2)
    {

    }

    if (menu == 3)
    {

    }


    if (menu == 0) return;
    cout << endl << endl;
    cout << "\nДля продолжения нажмите enter...\n";
    cin.ignore(256, '\n');
    getchar();   
}

void symbol()
{
    system("clear");
    char b;

    cout << "Введите символ: ";
    while (1)
    {
		cin >> b;
		if (cin.good()) break;
		cin.clear();
		cin.ignore(100, '\n');
        system("clear");
        cout << "Введите символ: ";
	}
    for (int i = 0; i < 8; i++) 
    {
        printf("%c", (b & 0x80) ? '1' : '0');
        b <<= 1;
    }
    cout << endl << endl;
    cout << "\nДля продолжения нажмите enter...\n";
    cin.ignore(256, '\n');
    getchar();
}


int main() 
{
    int menu;
    do
    {
        system("clear");
        cout << "[Вывод в двоичном коде]\n\n";
        cout << "Меню:\n";
        cout << "1. Целочисленные числа(int)\n";
        cout << "2. Символы(char)\n";
        cout << "3. Вещественные числа()\n";

        cout << "0. Выход\n\n";
        cout << "Выберите: ";
        
        
        while (1)
        {
		    cin >> menu;
		    if (cin.good() && menu >= 0 && menu <= 3) break;
		    cin.clear();
		    cin.ignore(100, '\n');
            system("clear");
            cout << "[Вывод в двоичном коде]\n\n";
            cout << "Меню:\n";
            cout << "1. Целочисленные числа(int)\n";
            cout << "2. Символы(char)\n";
            cout << "3. Вещественные числа()\n";

            cout << "0. Выход\n\n";
            cout << "Выберите: ";
	    }
        if (menu == 1)
        {
            numbersint();
        }
        if (menu == 2)
        {
            symbol();
        }
    }
    while (menu != 0);
    
}