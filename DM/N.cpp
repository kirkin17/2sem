#include "N.h" //все люди из группы 9371
#include <iostream>
using namespace std;

void VVOD_N(int ykaz[], int b) { // Автор - Ченская Ольга
	//ввод самого массива и проверка на натуральное
	for (int i = 0; i < b; i++) { // пользователем вводится число
		cout << "Введите число №" << i + 1 << " : ";
		cin >> ykaz[i];
		while (ykaz[i] < 0) { //если число не целое, пользователь должен ввести заново
			cout << "Введенное число не является натуральным.\n";
			cout << "Введите число №" << i + 1 << " : ";
			cin >> ykaz[i];
		}
	}
}

int VVOD_n(int b) { // Автор - Ченская Ольга
	//для случая, когда нужно больше чем одно число
	cout << "Сколько чисел вы введете?\n";
	cin >> b;
	while (b < 2) {
		cout << "Данную функцию нельзя использовать только с одним числом.\n";
		cout << "Сколько чисел вы введете? ";
		cin >> b;
	}
	return b;
}

void COM_NN_D(int ykaz[], int b, int otw[]) { //N1, Автор - Эвелина Семенова
	for (int i = 0; i < b; i++)
		ykaz[i] = abs(ykaz[i]);
	for (int i = 0; i < b-1; i++) {
		if (ykaz[i] > ykaz[i + 1]) { //сравнивает первое и второе числа по порядку
			otw[i] = 2; //первое больше второго
		}
		else if (ykaz[i] == ykaz[i + 1]) { 
			otw[i] = 0; //числа равны
		}
		else {
			otw[i] = 1; //второе больше первого
		}
	}
}

void NZER_N_B(int ykaz[], int b, int otw[]) { //N2, Автор - Ольга Валерьева
	for (int i = 0; i < b; i++) {
		if (ykaz[i] != 0)
			otw[i] = 1; //число не равно нулю
		else
			otw[i] = 0; //число равно нулю
	}
}

void ADD_1N_N(int ykaz[], int b) { //N3, Автор - Кондратюк Ксения
	for (int i = 0; i < b; i++) {
		ykaz[i] += 1; //прибавление единицы к каждому элементу
	}
}

int ADD_NN_N(int ykaz[], int b) { //N4, Автор - Эвелина Семенова
	int otv = 0; //создается элемент для ответа
	for (int i = 0; i < b; i++) {
		otv += ykaz[i]; //все элементы поочередно складываются
	}
	return otv; //возвращаю ответ
}

void SUB_NN_N(int ykaz1[], int b1, int otw2[], int otw1[]) { //N5, Автор - Эвелина Семенова
	COM_NN_D(ykaz1, b1, otw1); //используется массив для определения большего числа
	for (int i = 0; i < b1; i++) {
		if (otw1[i] == 0) 
			otw2[i] = 0; //так как разность между равными числами в любом случае равна нулю, то можно сразу приравнять к нулю
		if (otw1[i] == 2)
			otw2[i] = ykaz1[i] - ykaz1[i+1];
		if (otw1[i] == 1)
			otw2[i] = ykaz1[i+1] - ykaz1[i];
	}
}

void MUL_ND_N(int ykaz[], int b, int ch) { //N6, Автор - Ольга Валерьева
	for (int i = 0; i < b; i++) {
		ykaz[i] *= ch; //каждый элемент массива умножаю на число
	}
}

void MUL_Nk_N(int ykaz[], int b, int ch) { //N7, Автор - Ольга Валерьева
	int ch1 = 10; //cоздаем число, на которое будем умножать
	for (int i = 1; i < ch; i++) {
		ch1 *= 10; //считаем 10^k
	}
	MUL_ND_N(ykaz, b, ch1);
}

int MUL_NN_N(int ykaz[], int b) { //N8, Автор - 
	int otv = 0; //создается элемент для ответа
	for (int i = 0; i < b; i++) {
		otv *= ykaz[i]; //все элементы поочередно меремножаются
	}
	return otv; //возвращаю ответ
}

void SUB_NDN_N(int ykaz[], int b, int otw[], int otw2[]) { //N9, Автор - 
	COM_NN_D(ykaz, b, otw);
	for (int i = 0; i < b - 1; i++) {
		if (otw[i] == 2) {
			cout << "Разность числа №" << i + 1 << " и №" << i + 2 << " неотрицательна. Введите число, на которое хотите умножить №" << i + 2 << "\n";
			cin >> otw2[i];
			ykaz[i + 1] *= otw2[i];
		}
		ykaz[i] = ykaz[i] - ykaz[i + 1];
	}
}

void DIV_NN_Dk(int n, int b[], int a[], int c[]) { //N10, Автор - Надя Баринова
	//a[i]- массиви из чисел 0,1,2 из COM_NN_D             
	//с[i]- массив для найденых чисел
	int eba = 1;                         //b[i]- массив чисел на входе
	COM_NN_D(b, n, a);					 //n- кол-во пар
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] == 2) || (a[i] == 0))  {
			eba *= 10;
			c[i] = b[i] / (b[i + 1] * eba);
			eba /= 10;
		}
		if (a[i] == 1) {
			c[i] = b[i + 1] / (b[i] * eba);
		}
		eba *= 10;
	}
	for (int i = 0; i < n - 1; i++) {
		while (c[i] > 9) {
			c[i] /= 10;
		}
	}
}

void DIV_NN_N(int n, int b[], int a[], int c[], int d[]) {//N11, Автор - Надя Баринова
	//d[i] - для остатков
	COM_NN_D(b, n, a);
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] == 2) || (a[i] == 0)) {
			c[i] = b[i] / (b[i + 1]);
			d[i] = b[i] % (b[i + 1]);
		}
		if (a[i] == 1) {
			c[i] = b[i + 1] / (b[i]);
			d[i] = b[i + 1] % (b[i]);
		}

	}
}
void MOD_NN_N(int n, int b[], int a[], int c[], int d[]) {//N12, Автор - Надя Баринова
	DIV_NN_N(n, b, a, c, d);
}
