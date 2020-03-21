//Рациональные числа Q
//Прохоренко Кирилл 9371

//struct Q по идее надо пихнуть куда нибудь в Q.h, где описывается сама структура Q и подключаются нужные структуры для Q 
//#include "Q.h"        //тогда раскоментировать строку и при необходимости переименовать файл

struct Q                //рациональное число, состоящее из числителя(целое) и знаменателя(натуральное)
{
    Z nom;              //числитель
    N denom;            //знаменатель
};


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool INT_Q_B (Q a)       //проверка на целое. если рациональное является целым то true, иначе - false
{
    if (a.denom == 1 || a.nom % a.denom == 0) return true;  //если знаменатель == 1 или числитель делится нацело на знаменатель
    else return false;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Q TRANS_Z_Q (Z a)        //преобразование целого в дробное
{
    Q b;
    b.nom = a;
    b.denom = 1;
    return b;  
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Z TRANS_Q_Z (Q a)       //преобразование дробного в целое
{
    if (a.denom == 1) return a.nom;
    else std::cout << "Преобразовать в целове можно только если знаменатель равен 1!\n";
}