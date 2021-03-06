/*Представляем вашему вниманию калькулятор - Mathkiller!
             ∧＿∧
            （｡･ω･｡)つ━☆・* 。
            ⊂　　 ノ 　　・゜ + .
              しーＪ　  　°。 + *´¨)
                             .• ´¸.•* ´¨) ¸.•* ¨)
                                (¸.•´(¸.•’ *
*/
#include <iostream>
#include "N.h"
#include "Z.h"
#include "Q.h"
//#include "P.h"
using namespace std;

int main()
{// ---> Главное меню | Main Menu <---
    setlocale(LC_ALL, "Russian");
    int chooseMM, chooseMN, n, privet, n2,  x, en, enN, chN, k;
    //chooseMM - выбор главного меню; chooseMN - выбор любого подменю; n - колво чисел в массиве; privet - счетчик приветов (бюджет - один привет 
    //на человека); х - вывод ответа; 
    chooseMM = chooseMN = en = enN = privet = n = 0;
    while (en == 0) {
        chN = 0; //удерживатель в меню
        if (privet == 0) {
            cout << "Вас приветствует калькулятор Mathkiller.\n\n";
            privet++;
        }
        cout << "\n====== Разделы ======\n" << "\n1. Натуральные числа и ноль.\n"
            << "2. Целые числа.\n" << "3. Рациональная числа.\n"
            << "4. Справка.\n" << "5. Выход.\n" << "\nВыберите раздел:\n";
        cin >> chooseMM;
        system("cls");
        switch (chooseMM) {
        case 1:
            //---> Меню натуральных чисел <---
            while (chN == 0) {
                cout << "\n\n====== Натуральные числа и ноль ======\n" << "\n1. Сравнение натуральных чисел.\n" << "2. Проверка на ноль.\n"
                    << "3. Добавление 1 к натуральному числу.\n" << "4. Сложение натуральных чисел.\n" << "5. Вычитание из большего числа меньшего или равного.\n"
                    << "6. Умножение натурального числа на цифру.\n" << "7. Умножение натурального числа на 10^k.\n"
                    << "8. Умножение натуральных чисел.\n" << "9. Вычитание из натурального другого, умноженного на цифру для случая с неотрицательным результатом.\n"
                    << "10. Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k.\n"
                    << "11. Частное от деления большего натурального числа на меньшее или равное натуральное с остатком.\n"
                    << "12. Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком.\n" << "13. НОД натуральных чисел.[X]\n"
                    << "14. НОК натуральных чисел[X].\n" << "15. Назад.\n" << "\nВыберите желаемую функцию:\n";
                cin >> chooseMN;
                while ((chooseMN <= 0) || (chooseMN > 15)) {
                    cout << "Введено неверное число. Попробуйте снова.\n";
                    cin >> chooseMN;
                }
                system("cls");
                if (chooseMN == 1) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n - 1];
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    COM_NN_D(n_chisla, n, n_otvet);
                    for (int i = 0; i < n - 1; i++) {
                        if (n_otvet[i] == 2)
                            cout << "Число №" << i + 1 << " больше числа №" << i + 2 << "\n";
                        if (n_otvet[i] == 1)
                            cout << "Число №" << i + 2 << " больше числа №" << i + 1 << "\n";
                        if (n_otvet[i] == 0)
                            cout << "Число №" << i + 1 << " равно числу №" << i + 2 << "\n";
                    }
                    delete[] n_chisla;
                    delete[] n_otvet;
                }
                if (chooseMN == 2) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n];
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    NZER_N_B(n_chisla, n, n_otvet);
                    for (int i = 0; i < n; i++) {
                        if (n_otvet[i] == 1)
                            cout << "Число №" << i + 1 << " не равно нулю.\n";
                        if (n_otvet[i] == 0)
                            cout << "Число №" << i + 1 << " равно числу нулю.\n";
                    }
                    delete[] n_chisla;
                    delete[] n_otvet;
                }
                if (chooseMN == 3) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    ADD_1N_N(n_chisla, n);
                    for (int i = 0; i < n; i++) {
                        cout << "Число №" << i + 1 << " теперь равно: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                }
                if (chooseMN == 4) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    x = ADD_NN_N(n_chisla, n);
                    cout << "Сумма всех чисел равна: " << x;
                    delete[] n_chisla;
                }
                if (chooseMN == 5) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n - 1]; //массив полученных чисел
                    int* n_otvet2 = new int[n - 1]; //массив для определения большего и вывода ответа
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    SUB_NN_N(n_chisla, n, n_otvet, n_otvet2);
                    for (int i = 0; i < n-1; i++) {
                        if ((n_otvet2[i] == 2) || (n_otvet2[i] == 0))
                            cout << "Из числа №" << i+1 << " вычли число №" << i + 2 << " и получилось: " << n_otvet[i] << "\n";
                        else
                            cout << "Из числа №" << i+2 << " вычли число №" << i+1 << " и получилось: " << n_otvet[i] << "\n";
                    }
                    delete[] n_chisla;
                    delete[] n_otvet;
                    delete[] n_otvet2;
                }
                if (chooseMN == 6) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    VVOD_N(n_chisla, n);
                    cout << "Введите цифру, на которую хотите умножить числа.\n";
                    cin >> x;
                    //само решение + вывод//
                    MUL_ND_N(n_chisla, n, x);
                    for (int i = 0; i < n; i++) {
                        cout << "Число №" << i + 1 << " теперь равно: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                }
                if (chooseMN == 7) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    VVOD_N(n_chisla, n);
                    cout << "Введите степень для числа 10.\n";
                    cin >> k;
                    //само решение + вывод//
                    MUL_Nk_N(n_chisla, n, k);
                    for (int i = 0; i < n; i++) {
                        cout << "Число №" << i + 1 << " теперь равно: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                }
                if (chooseMN == 8) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    x = MUL_NN_N(n_chisla, n);
                    cout << "После перемножения всех чисел получилось: " << x;
                    delete[] n_chisla;
                }
                if (chooseMN == 9) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n]; // введенный пользователем масси и выводимый ответ
                    int* n_otvet = new int[n - 1]; //массив для определения, когда умножали
                    int* n_otvet2 = new int[n - 1]; // массив чисел, на которые умножаются числа в случае неотрицательного ответа
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    SUB_NDN_N(n_chisla, n, n_otvet, n_otvet2);
                    for (int i = 0; i < n - 1; i++) {
                        if ((n_otvet[i] == 2))
                            cout << "Из числа №" << i + 1 << " вычли число №" << i + 2 << ", умноженное на " << n_otvet2[i] << ", и получилось: " << n_chisla[i] << "\n";
                        else
                            cout << "Из числа №" << i + 1 << " вычли число №" << i + 2 << " и получилось: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                    delete[] n_otvet;
                    delete[] n_otvet2;
                }
                if (chooseMN == 10) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n - 1];//массив из чисел для COM_NN_D
                    int* n_otvet1 = new int[n - 1];//массив для ответов
                    VVOD_N(n_chisla, n);
                    //само решение + вывод//
                    DIV_NN_Dk(n, n_chisla, n_otvet, n_otvet1);
                    for (int i = 0; i < n - 1; i++) {
                        cout << "Первая цифра деления " << i+1 << "-й пары равна: " << n_otvet1[i] << "\n";
                    }
                }
                if (chooseMN == 11) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n - 1];//массив из чисел для COM_NN_D
                    int* n_otvet1 = new int[n - 1];//массив для ответов
                    int* n_otvet2 = new int[n - 1];//остатки
                    for (int i = 0; i < n; i++) { // пользователем вводится число
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                        while (n_chisla[i] <= 0) { //если число не целое, пользователь должен ввести заново
                            cout << "Введенное число не является натуральным или делитель будет равен нулю.\n";
                            cout << "Введите число №" << i + 1 << " : ";
                            cin >> n_chisla[i];
                        }
                    }
                    //само решение + вывод//
                    DIV_NN_N(n, n_chisla, n_otvet, n_otvet1, n_otvet2);
                    for (int i = 0; i < n - 1; i++) {
                        if (n_otvet2[i] == 0)
                            cout << "Частное от " << i + 1 << "-й пары равно: " << n_otvet1[i] << "\n";
                        else cout << "Частное от " << i + 1 << "-й пары равно: " << n_otvet1[i] << '*' << n_otvet2[i] << '/' << n_chisla[i] << "\n";
                    }
                }
                if (chooseMN == 12) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n - 1];//массив из чисел для COM_NN_D
                    int* n_otvet1 = new int[n - 1];//массив для ответов
                    int* n_otvet2 = new int[n - 1];//остатки
                    for (int i = 0; i < n; i++) { // пользователем вводится число
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                        while (n_chisla[i] <= 0) { //если число не целое, пользователь должен ввести заново
                            cout << "Введенное число не является натуральным или делитель будет равен нулю.\n";
                            cout << "Введите число №" << i + 1 << " : ";
                            cin >> n_chisla[i];
                        }
                    }
                    //само решение + вывод//
                    MOD_NN_N(n, n_chisla, n_otvet, n_otvet1, n_otvet2);
                    for (int i = 0; i < n - 1; i++) {
                        cout << "Остаток от " << i + 1 << "-й пары равен: " << n_otvet2[i] << "\n";
                    }
                }
                if (chooseMN == 13) {
                }
                if (chooseMN == 14) {
                }
                if (chooseMN == 15) { //выход из подменю
                    chN++;
                }
            }
            break;
        case 2:
            //---> Меню целых чисел <---
            while (chN == 0) {
                cout << "\n\n====== Целые числа ======\n" << "\n1. Абсолютная величина числа.\n" << "2. Определение положительности числа.\n"
                    << "3. Умножение целого на (-1).\n" << "4. Преобразование натурального в целое.\n" << "5. Преобразование целого неотрицательного в натуральное.\n"
                    << "6. Сложение целых чисел.\n" << "7. Вычитание целых чисел.\n" << "8. Умножение целых чисел.\n" 
                    << "9. Частное от деления большего целого числа на меньшее или равное натуральное с остатком.\n"
                    << "10. Остаток от деления большего целого числа на меньшее или равное натуральное с остатком.\n"
                    << "11. Назад.\n" << "\nВыберите желаемую функцию:\n";
                cin >> chooseMN;
                while ((chooseMN <= 0) || (chooseMN > 11)) {
                    cout << "Введено неверное число. Попробуйте снова.\n";
                    cin >> chooseMN;
                }
                system("cls");
                if (chooseMN == 1) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                    }
                     //само решение + вывод//
                    ABS_Z_N(n_chisla, n);
                    for (int i = 0; i < n; i++) {
                        cout << "Абсолютная величина числа №" << i + 1 << " равна: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                }
                if (chooseMN == 2) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    int* n_znak = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                    }
                    //само решение + вывод//
                    POZ_Z_D(n_chisla, n, n_znak);
                    for (int i = 0; i < n; i++) {
                        if (n_znak[i] == 1)
                            cout << "Число №" << i + 1 << " отрицательное.\n";
                        if (n_znak[i] == 0)
                            cout << "Число №" << i + 1 << " равно нулю.\n";
                        if (n_znak[i] == 2)
                            cout << "Число №" << i + 1 << " положительное.\n";
                    }
                    delete[] n_chisla;
                    delete[] n_znak;
                }
                if (chooseMN == 3) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                    }
                    //само решение + вывод//
                    MUL_ZM_Z(n_chisla, n);
                    for (int i = 0; i < n; i++) {
                        cout << "Число №" << i + 1 << " теперь равно: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                }
                if (chooseMN == 4) {
                    //ввод//
                    cout << "Сколько натуральных чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                        while (n_chisla[i] <= 0) {
                            cout << "Введенное число не является натуральным.\n";
                            cout << "Введите число №" << i + 1 << " : ";
                            cin >> n_chisla[i];
                        }
                    }
                    TRANS_N_Z(n_chisla, n);
                    for (int i = 0; i < n; i++) {
                        cout << "Число №" << i + 1 << " теперь целое, и равно: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                }
                if (chooseMN == 5) {
                    //ввод//
                    cout << "Сколько целых чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    //int* n_otvet = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                        while (n_chisla[i] <= 0) {
                            cout << "Введенное число является отрицательным.\n";
                            cout << "Введите число №" << i + 1 << " : ";
                            cin >> n_chisla[i];
                        }
                    }
                    // TRANS_Z_N(n_chisla, n, n_otvet);
                    for (int i = 0; i < n; i++) {
                        /*if (n_otvet[i] == 0)
                            cout << "Число №" << i + 1 << " теперь натуральное, и равно: " << n_chisla[i] << "\n";
                        else cout << "Число №" << i + 1 << " равно нулю и не может стать натуральным.\n";*/
                        cout << "Число №" << i + 1 << " теперь натуральное, и равно: " << n_chisla[i] << "\n";
                    }
                    delete[] n_chisla;
                }
                if (chooseMN == 6) {
                    //ввод//
                    cout << "Сколько чисел вы введете?\n";
                    cin >> n;
                    int* n_chisla = new int[n];
                    //int* n_otvet = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                    }
                    x = ADD_ZZ_Z(n_chisla, n);
                    cout << "Сумма чисел равна: " << x << "\n";
                }
                if (chooseMN == 7) {
                    //ввод//
                    int* n_chisla1 = new int[1];
                    int* n_chisla2 = new int[1];
                    cout << "Ведите число, из которого хотите вычесть другое.\n";
                    cin >> n_chisla1[0];
                    cout << "Ведите число, которое хотите вычесть из предыдущего.\n";
                    cin >> n_chisla2[0];
                    x = SUB_ZZ_Z(n_chisla1, n_chisla2);
                    cout << "Разность чисел равна: " << x << "\n";
                }
                if (chooseMN == 8) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    for (int i = 0; i < n; i++) { // пользователем вводится число
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                    }
                    //само решение + вывод//
                    x = MUL_ZZ_Z(n_chisla, n);
                    cout << "После перемножения всех чисел получилось: " << x;
                    delete[] n_chisla;
                }
                if (chooseMN == 9) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n - 1];//массив из чисел для COM_NN_D
                    int* n_otvet1 = new int[n - 1];//массив для ответов
                    int* n_otvet2 = new int[n - 1];//остатки
                    int* n_otvet3 = new int[n - 1];//остатки
                    for (int i = 0; i < n; i++) { // пользователем вводится число
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                        while (n_chisla[i] == 0) {
                            cout << "Делитель будет равен нулю.\n";
                            cout << "Введите число №" << i + 1 << " : ";
                            cin >> n_chisla[i];
                        }
                    }
                    //само решение + вывод//
                    DIV_ZZ_Z(n, n_chisla, n_otvet, n_otvet1, n_otvet2, n_otvet3);
                    for (int i = 0; i < n - 1; i++) {
                        if (n_otvet2[i] == 0)
                            cout << "Частное от " << i + 1 << "-й пары равно: " << n_otvet1[i] << "\n";
                        else cout << "Частное от " << i + 1 << "-й пары равно: " << n_otvet1[i] << '*' << n_otvet2[i] << '/' << n_chisla[i] << "\n";
                    }
                }
                if (chooseMN == 10) {
                    //ввод//
                    n = VVOD_n(n);
                    int* n_chisla = new int[n];
                    int* n_otvet = new int[n - 1];//массив из чисел для COM_NN_D
                    int* n_otvet1 = new int[n - 1];//массив для ответов
                    int* n_otvet2 = new int[n - 1];//остатки
                    int* n_otvet3 = new int[n - 1];//остатки
                    for (int i = 0; i < n; i++) { // пользователем вводится число
                        cout << "Введите число №" << i + 1 << " : ";
                        cin >> n_chisla[i];
                        while (n_chisla[i] == 0) {
                            cout << "Делитель будет равен нулю.\n";
                            cout << "Введите число №" << i + 1 << " : ";
                            cin >> n_chisla[i];
                        }
                    }
                    //само решение + вывод//
                    MOD_ZZ_Z(n, n_chisla, n_otvet, n_otvet1, n_otvet2, n_otvet3);
                    for (int i = 0; i < n - 1; i++) {
                        cout << "Остаток от " << i + 1 << "-й пары равен: " << n_otvet2[i] << "\n";
                    }
                }
                if (chooseMN == 11) { //выход из подменю
                    chN++;
                }
            }
            break;
        case 3:
            //---> Меню рациональных чисел <---
            while (chN == 0) {
                cout << "\n\n====== Рациональные числа ======\n" << "\n1. Сокращение дроби.\n" << "2. Проверка на целое.\n"
                    << "3. Преобразование целого в дробное.\n" << "4. Преобразование дробного в целое .\n" << "5. Сложение дробей.\n"
                    << "6. Вычитание дробей.\n" << "7. Умножение дробей.\n"
                    << "8. Деление дробей.\n" << "9. Назад.\n" << "\nВыберите желаемую функцию:\n";
                cin >> chooseMN;
                while ((chooseMN <= 0) || (chooseMN > 11)) {
                    cout << "Введено неверное число. Попробуйте снова.\n";
                    cin >> chooseMN;
                }
                system("cls");
                if (chooseMN == 1) {
                    //ввод//
                    cout << "Ведите числитель.\n";
                    cin >> n;
                    cout << "Ведите знаменатель.\n";
                    cin >> n2;
                    //само решение + вывод//
                    RED_Q_Q(n, n2);
                }
                if (chooseMN == 2) {
                    cout << "Ведите числитель.\n";
                    cin >> n;
                    cout << "Ведите знаменатель.\n";
                    cin >> n2;
                    INT_Q_B(n, n2);
                }
                if (chooseMN == 3) {
                    cout << "Ведите знаменатель.\n";
                    cin >> n2;
                    TRANS_Z_Q(n2);
                }
                if (chooseMN == 4) {
                    cout << "Знаменатель равен единице. Ведите числитель.\n";
                    cin >> n;
                    n2 = 1;
                    TRANS_Q_Z(n, n2);
                }
                if (chooseMN == 5) {
                    cout << "Сколько дробей вы введете?\n";
                    cin >> n;
                    int* n_ch = new int[n];
                    int* n_zn = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите числитель №" << i + 1 << " : ";
                        cin >> n_ch[i];
                        cout << "Введите знаменатель №" << i + 1 << " : ";
                        cin >> n_zn[i];
                    }
                    ADD_QQ_Q(n, n_ch, n_zn);
                }
                if (chooseMN == 6) {
                    cout << "Сколько дробей вы введете?\n";
                    cin >> n;
                    int* n_ch = new int[n];
                    int* n_zn = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите числитель №" << i + 1 << " : ";
                        cin >> n_ch[i];
                        cout << "Введите знаменатель №" << i + 1 << " : ";
                        cin >> n_zn[i];
                    }
                    SUB_QQ_Q(n, n_ch, n_zn);
                }
                if (chooseMN == 7) {
                    cout << "Сколько дробей вы введете?\n";
                    cin >> n;
                    int* n_ch = new int[n];
                    int* n_zn = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите числитель №" << i + 1 << " : ";
                        cin >> n_ch[i];
                        cout << "Введите знаменатель №" << i + 1 << " : ";
                        cin >> n_zn[i];
                    }
                    MUL_QQ_Q(n, n_ch, n_zn);
                }
                if (chooseMN == 8) {
                    cout << "Сколько дробей вы введете?\n";
                    cin >> n;
                    int* n_ch = new int[n];
                    int* n_zn = new int[n];
                    for (int i = 0; i < n; i++) {
                        cout << "Введите числитель №" << i + 1 << " : ";
                        cin >> n_ch[i];
                        cout << "Введите знаменатель №" << i + 1 << " : ";
                        cin >> n_zn[i];
                    }
                    DIV_QQ_Q(n, n_ch, n_zn);
                }
                if (chooseMN == 9) { //выход из подменю
                    chN++;
                }
            }
            break;
        /*case 4:
            //---> Меню многочленов <---
            while (chN == 0) {
                cout << "\n\n====== Многочлен с рациональными коэффициентами ======\n" << "\n1. Сложение многочленов.\n" << "2. Вычитание многочленов.\n"
                    << "3. Умножение многочлена на рациональное число.\n" << "4. Умножение многочлена на x^k.\n" << "5. Старший коэффициент многочлена.\n"
                    << "6. Степень многочлена.\n" << "7. Вынесение из многочлена НОК знаменателей коэффициентов и НОД числителей.\n"
                    << "8. Умножение многочленов.\n" << "9. Частное от деления многочлена на многочлен при делении с остатком.\n"
                    << "10. Остаток от деления многочлена на многочлен при делении с остатком.\n"
                    << "11. НОД многочленов.\n" << "12. Производная многочлена.\n" << "13. Преобразование многочлена — кратные корни в простые.\n"
                    << "14. Назад.\n" << "\nВыберите желаемую функцию:\n";
                cin >> chooseMN;
                while ((chooseMN <= 0) || (chooseMN > 15)) {
                    cout << "Введено неверное число. Попробуйте снова.\n";
                    cin >> chooseMN;
                }
                system("cls");
                if (chooseMN == 1) {
                    //ввод//
                    //само решение + вывод//
                }
                if (chooseMN == 2) {
                }
                if (chooseMN == 3) {
                }
                if (chooseMN == 4) {
                }
                if (chooseMN == 5) {
                }
                if (chooseMN == 6) {
                }
                if (chooseMN == 7) {
                }
                if (chooseMN == 8) {
                }
                if (chooseMN == 9) {
                }
                if (chooseMN == 10) {
                }
                if (chooseMN == 11) {
                }
                if (chooseMN == 12) {
                }
                if (chooseMN == 13) {
                }
                if (chooseMN == 14) { //выход из подменю
                    chN++;
                }
            }
            break;*/
        case 4:
            while (chN == 0) {
                cout << "\n\n====== Справка ======\n" << "Объяснение работы модулей для пользователя на нескольких примерах блока N.\n"
                    << "\nРабота N1. Сравнение натуральных чисел.\n" << "Работа N2. Проверка на ноль.\n"
                    << "Работа N3. Добавление 1 к натуральному числу.\n" << "Работа N4. Сложение натуральных чисел.\n" << "Работа N5. Вычитание из большего числа меньшего или равного.\n"
                    << "Работа N6. Умножение натурального числа на цифру.\n" << "Работа N7. Умножение натурального числа на 10^k.\n"
                    << "Работа N8. Умножение натуральных чисел.\n" << "Работа N9. Вычитание из натурального другого, умноженного на цифру для случая с неотрицательным результатом.\n"
                    << "Работа N10. Вычисление первой цифры деления большего натурального на меньшее, домноженное на 10^k.\n"
                    << "Работа N11. Частное от деления большего натурального числа на меньшее или равное натуральное с остатком.\n"
                    << "Работа N12. Остаток от деления большего натурального числа на меньшее или равное натуральное с остатком.\n" << "13. Назад.\n" << "\nВыберите желаемую функцию:\n";
                cin >> chooseMN;
                while ((chooseMN <= 0) || (chooseMN > 10)) {
                    cout << "Введено неверное число. Попробуйте снова.\n";
                    cin >> chooseMN;
                }
                system("cls");
                if (chooseMN == 1) {
                    cout << "\nN1 Работает следующим образом - пользователь вводит массив цифр, которые сравниваются между собой попорядку. Первая и последняя цифры не сравниваются.\n";
                }
                if (chooseMN == 2) {
                    cout << "\nN2 Работает следующим образом - пользователь вводит массив цифр, затем по очереди определяется, равно ли число массива нулю.\n";
                }
                if (chooseMN == 3) {
                    cout << "\nN3 Работает следующим образом - пользователь вводит массив цифр, к которым по очереди прибавляется единица.\n";
                }
                if (chooseMN == 4) {
                    cout << "\n\N4 Работает следующим образом - пользователь вводит массив цифр, а функция их всех складывает.\n";
                }
                if (chooseMN == 5) {
                    cout << "\nN5 Работает следующим образом - пользователь вводит массив цифр, а функция сравнивает по два числа по порядку и делает требуемые вычисления.";
                }
                if (chooseMN == 6) {
                    cout << "\n\N6 Работает следующим образом - пользователь вводит массив цифр, затем цифру, на которую будет умножаться весь массив чисел, затем функция поочередно умножает каждый элемент на эту цифру.\n";
                }
                if (chooseMN == 7) {
                    cout << "\n\N7 Работает следующим образом - пользователь вводит массив цифр, затем цифру степени 10, затем функция поочередно умножает каждый элемент на 10 в этой степени.\n";
                }
                if (chooseMN == 8) {
                    cout << "\n\N8 Работает следующим образом - пользователь вводит массив цифр, а функция их всех перемножает.\n";
                }
                if (chooseMN == 9) {
                    cout << "\n\N9 Работает следующим образом - пользователь вводит массив цифр, функция попарно сравнивает числа по полядку, в случае, если результат вычитания будет отрицательным, пользователю нужно будет ввести цифру, на которую будет умножено второе число.\n";
                }
                if (chooseMN == 10) {
                    
                    chN++;
                }
            }
            break;

        case 5:
            en++;
            break;

        default:
            cout << "\nВведено неверное число. Попробуйте снова.\n";
            break;
        }

    }
    system("pause"); //
    return 0;
}



