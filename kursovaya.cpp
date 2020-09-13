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
    stud *next;
};

struct group
{
    stud *begin = NULL; //указатель на начало списка студентов группы
    group* nextgr = NULL; //следующая группа
    int count = 0; //количество студентов в группе
    int num = 0; //номер группы
};

group *beging = NULL; //сразу создаем указатель для хранения начала групп, этот адрес нам нужен во всей программе

string inputname()
{
    string name;
    std::cin.ignore(256, '\n');
    getline(std::cin, name);
    return name;
}

void inputstudent(stud *p)
{
    group *gr = beging;
    if (gr == NULL)
    {
        beging = new group;
        gr = beging;
        gr->num = p->group;
        gr->begin = p;
    }
    else
    {
        while (gr->nextgr != NULL && gr->num != p->group)
        {
            gr = gr->nextgr;
        }
        if (gr->num == p->group)
        {
            stud *k = gr->begin;
            while(k->next != NULL)
            {
                k = k->next;
            }
            k->next = p;
        }
        else
        {
            gr = beging;
            while(gr->nextgr != NULL)
            {
                gr = gr->nextgr;
            }
            gr->nextgr = new group;
            gr = gr->nextgr;
            gr->begin = p;
            gr->num = p->group;
        }  
    }
}

group inputkeyboard()
{
    stud *p = new stud;

    system("clear");
    std::cout << "Введите ФИО студента: ";
    p->name = inputname();
    std::cout << "Введите номер группы: ";
    int numgroup;
    std::cin >> numgroup; //вводят номер группы, далее проверяем есть ли такая группа, если да, то добавляем в нее, иначе создаем новую
    p->group = numgroup;


    group *gr = beging;
    

    std::cout << "Введите оценки: \n";
    int grades[5];
    for(int i = 0; i < 5; i++)
    {
        printf("[%d]. ", i + 1);
        std::cin.ignore(256, '\n');
        std::cin >> grades[i];
        p->grades[i] = grades[i];
    }
    std::cout << "Введите размер стипендии: ";
    int stipend;
    std::cin.ignore(256, '\n');
    std::cin >> stipend;
    p->stipend = stipend;
    inputstudent(p);
}

void outputkeyboardfordelete(group *p)
{
    system("clear");
    unsigned int key = 1;
    while (p != NULL)
    {
        std::cout << "Группа: " << p->num << endl;
        stud *k;
        k = p->begin;
        while(k != NULL)
        {
            std::cout << "     " << key << ". ";
            std::cout << k->name << endl;
            k = k->next;
            key++;
        }
        p = p->nextgr;        
    }
    std::cout << "\n\nДля продолжения нажмите enter...\n";
    //std::cin.ignore(256, '\n');
    getchar();
    //std::cin.ignore(256, '\n');
}


void outputkeyboard(group *p)
{
    system("clear");
    while (p != NULL)
    {
        std::cout << "Группа: " << p->num << endl;
        stud *k;
        k = p->begin;
        while(k != NULL)
        {
            std::cout << "\tФИО:" << k->name << endl;
            //std::cout << "\tГруппа: " << k->group << endl;
            std::cout << "\tСтипендия: " << k->stipend << endl;
            std::cout << "\tОценки:\n";
            for (int i = 0; i < 5; i++)
            {
                std::cout << "\t\t" << i + 1 << ". " << k->grades[i] << endl;
            }
            cout << endl;
            k = k->next;
        }
        p = p->nextgr;        
    }
    std::cout << "\n\nДля продолжения нажмите enter...\n";
    std::cin.ignore(256, '\n');
    getchar();
}

void inputfile()
{
    ifstream file("in.txt");
    if (file.is_open())
	{
		while (!file.eof())
		{
			stud* st = new stud;
			getline(file, st->name);
			if (st->name == "") //если прочитана пустая строка не создавать студента
			{
			    delete st;
				break;
			}
			file >> st->group;


			for (int i = 0; i < 5; i++) file >> st->grades[i];
			file >> st->stipend;
			inputstudent(st);
			file.get();//переходим на следующую строку
		}
		file.close(); 
	}
}

void outputfile() //вывод в файл
{
	ofstream file("out.txt"); //открытие файла на запись
    group *gr = beging;
    while(gr != NULL)
    {
        file << "Группа: " << gr->num << endl;
	    stud* st = gr->begin;
	    while (st != NULL)
		{
			file << "\tФИО:" << st->name << endl;
            file << "\tСтипендия: " << st->stipend << endl;
            file << "\tОценки:\n";
            for (int i = 0; i < 5; i++)
            {
                file << "\t\t" << i + 1 << ". " << st->grades[i] << endl;
            }
            file << endl;
			st = st->next;
		}
        gr = gr->nextgr;
    }
	file.close();
}

void changeinfo(group *gr)
{

}

void deletestudent(group *gr)
{
    system("clear");
    cout << "Чтобы удалить студента, будет выведен список студентов. Запомните номер студента и затем введите его!\n";
    cout << "Или введите полностью ФИО\n";
    std::cin.ignore(256, '\n');
    std::getchar();
    outputkeyboardfordelete(beging);

}

int main()
{
    setlocale(LC_ALL, "Russian");
    int menu;
    
    do
    {
        system("clear");
        std::cout << "Меню" << endl << " 1. Ввести данные о студенте с клавиатуры" << endl;
        std::cout << " 2. Вывести список студентов на экран" << endl;
        std::cout << " 3. Ввести данные о студентах из файла (\"in.txt\")" << endl;
        std::cout << " 4. Вывести список студентов в файл (\"out.txt\")" << endl;
        std::cout << " 5. Изменить данные о студенте" << endl;
        std::cout << " 6. Удалить студента" << endl;
        std::cout << " 7. Удалить группу" << endl;
        std::cout << " 8. Вывести студентов, сгруппированных по размеру стипендии(ИДЗ)" << endl;
        std::cout << " 0. Выход" << endl << endl;
        std::cout << "Выберите действие: ";
        std::cin >> menu;
        if (menu == 1)
        {
            inputkeyboard();
        }
        if (menu == 2)
        {
            outputkeyboard(beging);
        }
        if (menu == 3)
        {
            inputfile();
        }
        if (menu == 4)
        {
            outputfile();
        }
        if (menu == 5)
        {
            changeinfo(beging);
        }
        if (menu == 6)
        {
            deletestudent(beging);
        }
    }
    while (menu != 0);
    return 0;
}