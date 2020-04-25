#include <iostream>
using namespace std;
//Весь модуль Q сделала Настя Баринова, 9371
int RED_Q_Q(int ch, int zn) {//ch - числитель,zn-знаменатель
    int NOD, c = 0, z = 0;


    if (ch < 0) {
        c = ch;
        ch = ch * (-1);
    }
    else
        c = ch;
    if (zn < 0) {
        z = zn;
        zn = zn * (-1);
    }
    else
        z = zn;
    while (ch && zn)
        if (ch >= zn)
            ch %= zn;
        else
            zn %= ch;
    if (zn != 0) {
        NOD = zn;
    }
    else NOD = ch;
    c /= NOD;
    z /= NOD;

    cout << c << '/' << z;
    return 0;
}
int INT_Q_B(int ch, int zn) {
    if (ch % zn == 0) cout << "Да";
    else cout << "Нет";
    return 0;
}
int TRANS_Z_Q(int ch) {
    int zn;
    zn = 1;
    cout << ch << '/' << zn;
    return 0;
}
int TRANS_Q_Z(int ch, int zn) {
    if (zn == 1) {
        cout << ch;
    }
    else cout << "Не верная функция или знаменатель";
    return 0;
}
int ADD_QQ_Q(int n, int ch2[], int zn2[]) {//n-сколько дробей всего
    int sum = 0, sum1 = 0;
    int del = 1;

    for (int i = 0; i < n; i++) {
        sum = ch2[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                sum *= zn2[j];

            }
        }
        sum1 += sum;
        sum = ch2[i];
        del *= zn2[i];

    }
    if (sum1 % del == 0) {
        cout << sum1 / del;
    }
    else
        RED_Q_Q(sum1, del);

    return 0;

}
int SUB_QQ_Q(int n, int ch2[], int zn2[]) {
    int sum = 0, sum1 = 0;
    int del = 1;

    for (int i = 0; i < n; i++) {
        sum = ch2[i];
        for (int j = 0; j < n; j++) {
            if (j != i) {
                sum *= zn2[j];
            }
        }
        if (i == 0)
            sum = sum * (-1);
        sum1 -= sum;
        sum = ch2[i];
        del *= zn2[i];

    }
    if (sum1 % del == 0) {
        cout << sum1 / del;
    }
    else {
        RED_Q_Q(sum1, del);
    }

    return 0;

}
int MUL_QQ_Q(int n, int ch2[], int zn2[]) {
    int c = 1, z = 1;
    for (int i = 0; i < n; i++) {
        c *= ch2[i];
        z *= zn2[i];
    }
    if (c % z == 0) {
        cout << c / z;
    }
    else {
        RED_Q_Q(c, z);
    }
    return 0;

}
int DIV_QQ_Q(int n, int ch2[], int zn2[]) {
    int c = ch2[0], z = zn2[0], d = 0;
    for (int i = 1; i < n; i++) {
        d = ch2[i];
        ch2[i] = zn2[i];
        zn2[i] = d;
        c *= ch2[i];
        z *= zn2[i];

    }
    if (c % z == 0) {
        cout << c / z;
    }
    else {
        RED_Q_Q(c, z);
    }
    return 0;

}
/*int main()
{
    setlocale(LC_ALL, "ru");
    int ch1, zn1, n;
    cin >> n;
    int* ch2 = new int[n];
    int* zn2 = new int[n];
    //cin >> ch1 >> zn1;
    for (int i = 0; i < n; i++) {
        cin >> ch2[i] >> zn2[i];
    }
    //TRANS_Q_Z(ch1, zn1);
    DIV_QQ_Q(n, ch2, zn2);
}*/


