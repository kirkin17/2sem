#include <iostream>
#include "ncursesw/ncurses.h"

using namespace std;


void system()
{
	int num;
	cout << "Введите систему счисления:" << endl;
	cin >> num;
	cout << endl;
}



void unsigned_int()
{
	unsigned int U_Int;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Int;
	for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; --i)
	{
		num = (U_Int & (1 << i));
		cout << num;
	}
}

void signed_int()
{
	int Int;
	bool num;
	cout << "Введите число" << endl;
	cin >> Int;
	for (int i = sizeof(int) * 8 - 1; i >= 0; --i)
	{
		num = (Int & (1 << i));
		cout << num;
	}
}

void signed_short_int()
{
	short Short;
	bool num;
	cout << "Введите число" << endl;
	cin >> Short;
	for (int i = sizeof(short) * 8 - 1; i >= 0; --i)
	{
		num = (Short & (1 << i));
		cout << num;
	}
}

void signed_long_int()
{
	long Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> Long;
	for (int i = sizeof(long) * 8 - 1; i >= 0; --i)
	{
		num = (Long & (1 << i));
		cout << num;
	}
}

void unsigned_long_int()
{
	unsigned long U_Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Long;
	for (int i = sizeof(unsigned long) * 8 - 1; i >= 0; --i)
	{
		num = (U_Long & (1 << i));
		cout << num;
	}
}

void unsigned_short_int()
{
	unsigned short U_Short;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Short;
	for (int i = sizeof(unsigned short) * 8 - 1; i >= 0; --i)
	{
		num = (U_Short & (1 << i));
		cout << num;
	}
}

void signed_longlong_int()
{
	long long Long_Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> Long_Long;
	for (int i = sizeof(long long) * 8 - 1; i >= 0; --i)
	{
		num = (Long_Long & (1 << i));
		cout << num;
	}
}

void unsigned_longlong_int()
{
	unsigned long long U_Long_Long;
	bool num;
	cout << "Введите число" << endl;
	cin >> U_Long_Long;
	for (int i = sizeof(unsigned long long) * 8 - 1; i >= 0; --i)
	{
		num = (U_Long_Long & (1 << i));
		cout << num;
	}
}


void unsigned_char()
{
	char Unsigned_Char;
	bool num;
	cout << "Введите символ" << endl;
	cin >> Unsigned_Char;
	for (int i = sizeof(char) * 8 - 1; i >= 0; --i)
	{
		num = (Unsigned_Char & (1 << i));
		cout << num;
	}
}

void signed_char()
{
	signed char Signed_Char;
	bool num;
	cout << "Введите символ" << endl;
	cin >> Signed_Char;
	for (int i = sizeof(signed char) * 8 - 1; i >= 0; --i)
	{
		num = (Signed_Char & (1 << i));
		cout << num;
	}
}





int menu()
{
	int c;

	cout << endl << "1. Начало" << endl << "2. Выход" << endl;
	do
	{
		c = getch();
	} 
	while (!((c == '0') && (c == '2')));
	/*cin >> c;*/
	switch (c) {
	case '1':
		int c1;
		cout << endl << "1) Int" << endl << "2) Char" << endl << "3) Float" << endl << "4) Double" << endl;
		do
		{
			c1 = getch();
		} while (!((c1 > '0') && (c1 < '5')));
		/*cin >> c1;*/
		switch (c1)
		{
		case '1':
			int c3;
			cout << endl << "1) Signed" << endl << "2) Unsigned" << endl;
			do
			{
				c3 = getch();
			} while (!((c3 > '0') && (c3 < '3')));
			/*cin >> c3;*/
			switch (c3) {
			case '1':
				int c4;
				cout << endl << "1) Long" << endl << "2) Short" << endl << "3) Обычный " << endl << "4) Long long" << endl;
				do
				{
					c4 = getch();
				} while (!((c4 > '0') && (c4 < '5')));
				/*cin >> c4;*/
				switch (c4) {
				case '1':
					signed_long_int();
					break;
				case '2':
					signed_short_int();
					break;
				case '3':
					signed_int();
					break;
				case '4':
					signed_longlong_int();
					break;
				}
				break;
			case '2':
				int c5;
				cout << endl << "1) Long" << endl << "2) Short" << endl << "3) Обычный" << endl << "4) Long long" << endl;
				do
				{
					c5 = getch();
				} while (!((c5 > '0') && (c5 < '5')));
				/*cin >> c5;*/
				switch (c5) {
				case '1':
					unsigned_long_int();
					break;
				case '2':
					unsigned_short_int();
					break;
				case '3':
					unsigned_int();
					break;
				case '4':
					unsigned_longlong_int();
					break;
				}
				break;
			}
			break;
		case '2':
			int c6;
			cout << endl << "1) Signed" << endl << "2) Unsigned" << endl;
			do
			{
				c6 = getch();
			} while (!((c6 > '0') && (c6 < '3')));
			/*cin >> c6;*/
			switch (c6) {
			case '1':
				signed_char();
				break;
			case '2':
				unsigned_char();
				break;
			}
			break;
		case '3':
			int c7;
			cout << endl << "1) Long" << endl << "2) Обычный" << endl;
			do
			{
				c7 = getch();
			} while (!((c7 > '0') && (c7 < '3')));
			/*cin >> c6;*/
			switch (c7) {
			case '1':
				/*long_float();*/
				break;
			case '2':
				/*float();*/
				break;
			}
			break;
		case '4':
			int c8;
			cout << endl << "1) Long" << endl << "2) Обычный" << endl;
			do
			{
				c8 = getch();
			} while (!((c8 > '0') && (c8 < '3')));
			/*cin >> c6;*/
			switch (c8) {
			case '1':
				/*long_double();*/
				break;
			case '2':
				/*double();*/
				break;
			}
			break;
		}
		break;
	case '2':
		break;
	}
	cout << endl;
	return 0;
}

bool contin()
{
	cout << "\nДля продолжения нажмите enter...\n";
	getch();
	return 1;
}

int main()
{
	setlocale(LC_ALL, "rus");
	//initscr();
	do
	{
		menu();
	} while (contin());
	system("pause");
	//endwin();
}