#include "Z.h" //все люди из группы 9371
#include "N.h"
#include <iostream>
using namespace std;

void COM_NN_D2(int ykaz[], int b, int otw[], int l[]) { //Автор - Эвелина Семенова
	for (int i = 0; i < b; i++) {
		if (ykaz[i] < 0) {
			ykaz[i] = abs(ykaz[i]);
			l[i] = 1; //тут минус
		}
		else l[i] = 0; //нет минуса
	}
	for (int i = 0; i < b - 1; i++) {
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
int ABS_Z_N(int ykaz[], int b) { //Z1 Автор - Кондратюк Ксения
	for (int i = 0; i < b; i++)
		ykaz[i] = abs(ykaz[i]);

	return 0;
}
int POZ_Z_D(int ykaz[], int b, int zn[]) { //Z2 Автор - Кондратюк Ксения
	for (int i = 0; i < b; i++) {
		if (ykaz[i] < 0)
			zn[i] = 1; //минус
		else if (ykaz[i] == 0)
			zn[i] = 0; //ноль
		else if (ykaz[i] > 0)
			zn[i] = 2; //плюс
	}
	return 0;
}

int MUL_ZM_Z(int ykaz[], int b) { //Z3 Автор - Алиса Сажина
	for (int i = 0; i < b; i++) {
		ykaz[i] *= (-1);
	}
	return 0;
}
int TRANS_N_Z(int ykaz[], int b) { //Z4 Автор - Алиса Сажина
	return 0; //натуральное число равно целому
}
int TRANS_Z_N(int ykaz[], int b, int otw[]) { //Z5 Автор - Алиса Сажина
	/*for (int i = 0; i < b; i++) {
		if (ykaz[i] < 0) {
			ykaz[i] *= (-1);
			otw [i] = 0;
		}
		else if (ykaz[i] == 0)
			otw[i] = 1;
		else otw[i] = 0;
	}*/
	return 0; //целое неотрицательного равно натуральному
}
int ADD_ZZ_Z(int ykaz[], int b) {//Z6, Автор - Ольга Валерьева
	int add = 0;
	for (int i = 0; i < b; i++) {
		add = ykaz[i] + add;
	}
	return add;
}

int SUB_ZZ_Z(int ykaz[], int ykaz2[]) { //Z7, Автор - Ольга Валерьева
	int add = 0;
	add = ykaz[0] - ykaz2[0];
	return add;
}
int MUL_ZZ_Z(int ykaz[], int b) { // Z8, Автор - Кирилл Прохоренко
	int otv = 0; //создается элемент для ответа
	for (int i = 0; i < b; i++) {
		otv *= ykaz[i]; //все элементы поочередно меремножаются
	}
	return otv; //возвращаю ответ
}
void DIV_ZZ_Z(int n, int b[], int a[], int c[], int d[], int l[]) { // Z9, Автор - Надя Баринова + Эвелина Семенова
	//d[i] - для остатков
	COM_NN_D2(b, n, a, l);
	for (int i = 0; i < n - 1; i++) {
		if ((a[i] == 2) || (a[i] == 0)) {
			c[i] = b[i] / (b[i + 1]);
			d[i] = b[i] % (b[i + 1]);
		}
		if (a[i] == 1) {
			c[i] = b[i + 1] / (b[i]);
			d[i] = b[i + 1] % (b[i]);
		}
		for (int i = 0; i < n - 1; i++) {
			if ((l[i] == 1) && ((l[i + 1] == 0))) {
				c[i] *= -1;
				d[i] *= -1;
			}
			if ((l[i] == 0) && ((l[i + 1] == 1))) {
				c[i] *= -1;
			}
			if ((l[i] == 1) && ((l[i + 1] == 1))) {
				d[i] *= -1;
			}
		}
	}
}
void MOD_ZZ_Z(int n, int b[], int a[], int c[], int d[], int l[]) { // Z10, Автор - Надя Баринова + Эвелина Семенова
	DIV_ZZ_Z(n, b, a, c, d, l);
}
