#include <iostream>
#include <string>
#include <stdio.h>
#include <fstream>
using namespace std;

struct stud
{
	string name; // имя
	int group; //номер группы
	int grades[5]; //оценки
	int stipend; //стипендия
};

struct group
{
	stud *begin = NULL; //указатель на начало списка студентов группы
	int count = 0; //количество студентов в группе
	int num; //номер группы
	stud* next = NULL; //следующий в списке группы
};

string inputname()
{
	string name;
	getline(cin, name);
	return name;
}

void newstudent(stud *current)
{
	system("cls");
	cout << "Введите ФИО студента: ";
	current->name = inputname();
	cout << "Введите номер группы: ";
	int group;
	cin >> group;
	current->group = group;
	cout << "Введите оценки: ";
	int grades[5];
	for(int i=0; i < 5; i++)
	{
		printf("[%d]. ", i + 1);
		cin >> grades[i];
		current->grades[i] = grades[i];
	}
	cout << "Введите размер стипендии: ";
	int stipend;
	cin >> stipend;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int menu;

	group *current,*last; //сразу создаем указатели для создания хотя бы одной группы и студента
	last = NULL;
	
	do
	{
		system("cls");
		cout << "Меню" << endl << " 1. Ввести данные о студенте с клавиатуры" << endl;
		cout << " 2. Вывести список студентов на экран" << endl;
		cout << " 3. Ввести данные о студентах из файла (in.txt)" << endl;
		cout << " 4. Вывести список студентов в файл" << endl;
		cout << " 5. Изменить данные о студенте" << endl;
		cout << " 6. Удалить студента" << endl;
		cout << " 7. Вывести список групп по кол-ву человек" << endl;
		cout << " 0. Выход" << endl;
		cin >> menu;		
	}
	while (menu != 0);
	return 0;
}