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
    stud *nextstip;
};

struct group
{
    stud *begin = NULL; //указатель на начало списка студентов группы
    group* nextgr = NULL; //следующая группа
    int num = 0; //номер группы
};

struct idz
{
    int stipend = 0;
    stud *begin = NULL;
    idz *nextgr = NULL;
};

group *beging = NULL; //сразу создаем указатель для хранения начала групп, этот адрес нам нужен во всей программе

string inputname()
{
    string name;
    while (1) 
    {
	    std::cin.ignore(256, '\n');
        getline(std::cin, name);
		if (cin.good()) break;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Неправильный ввод!\n";
        cout << "ФИО: ";
	}
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

void inputkeyboard()
{
    stud *p = new stud;

    system("clear");
    std::cout << "Введите ФИО студента: ";
    p->name = inputname();
    std::cout << "Введите номер группы: ";
    int numgroup;
    while (1) //вводят номер группы, далее проверяем есть ли такая группа, если да, то добавляем в нее, иначе создаем новую
    {
	    std::cin >> numgroup;
		if (cin.good() && numgroup > 0) break;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Неправильный ввод!\n";
        cout << "Введите номер группы: ";
	}
    p->group = numgroup;


    group *gr = beging;
    

    std::cout << "Введите оценки: \n";
    int grades[5];
    for(int i = 0; i < 5; i++)
    {
        printf("[%d]. ", i + 1);
        while (1)
        {
	        std::cin >> grades[i];
	    	if (cin.good() && grades[i] > 0 && grades[i] <= 5) break;
		    cin.clear();
		    cin.ignore(100, '\n');
	    	cout << "Неправильный ввод!\n";
            printf("[%d]. ", i + 1);
	    }
        p->grades[i] = grades[i];
    }
    std::cout << "Введите размер стипендии: ";
    int stipend;
    while (1)
    {
        std::cin >> stipend;
	 	if (cin.good() && stipend >= 0) break;
	    cin.clear();
	    cin.ignore(100, '\n');
	   	cout << "Неправильный ввод!\n";
        cout << "Введите размер стипендии: ";
	}
    
    p->stipend = stipend;
    inputstudent(p);
}

int outputwithkey(group *p)
{
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
    return key;
}


void outputkeyboard(group *p)
{
    if(p == NULL)
    {
        system("clear");
        cout << "Список пуст!\n";
        std::cout << "\nДля продолжения нажмите enter...\n";
        std::cin.ignore(256, '\n');
        getchar();
        return;
    }
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
    system("clear");
    cout << "Результат в файле [./out.txt]\n";
    std::cout << "\nДля продолжения нажмите enter...\n";
    std::cin.ignore(256, '\n');
    getchar();
}

void changeinfo(group *gr)
{
    if(gr == NULL)
    {
        system("clear");
        cout << "Список пуст!\n";
        std::cout << "\nДля продолжения нажмите enter...\n";
        std::cin.ignore(256, '\n');
        getchar();
        return;
    }
    system("clear");
    cout << "Чтобы изменить студента, будет выведен список. Запомните номер студента и затем введите его!\n\n";
    //cout << "Или введите полностью ФИО\n";
    unsigned int count;
    count = outputwithkey(beging);
    unsigned int changenum;
    cout << "Введите номер студента: ";
    while (1)
    {
		cin >> changenum;
		if (cin.good() && changenum > 0 && changenum <= count) break;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Неправильный ввод!\n";
        cout << "Введите номер студента: ";
	}
    stud *del;
    unsigned int k = 1;
    stud *st = gr->begin;
    while(gr != NULL)
    {
        stud *lastst;
        while(st->next != NULL && k < changenum)
        {
            
            lastst = st;
            st = st->next;
            k++;
        }
        if (k < changenum)
        {
            gr = gr->nextgr;
            st = gr->begin;
            k++;
            continue;
        }
        /////
        unsigned int changech;
        cout << "Что изменить: \n";
        cout << "1. Имя\n";
        cout << "2. Группу\n";
        cout << "3. Стипендию\n";
        cout << "4. Оценки\n";
        
        while (1)
        {
		    cin >> changech;
		    if (cin.good() && changech > 0 && changech <= count) break;
		    cin.clear();
		    cin.ignore(100, '\n');
		    cout << "Неправильный ввод!\n";
            cout << "Введите номер студента: ";
	    }

        if(changech == 1)
        {
            cout << "Введите имя: ";
            string name = inputname();
            st->name = name;
        }
        
        if(changech == 2)
        {
            std::cout << "Введите номер группы: ";
            int numgroup;
            while (1)
            {
	            std::cin >> numgroup;
		        if (cin.good() && numgroup > 0) break;
		        cin.clear();
		        cin.ignore(100, '\n');
		        cout << "Неправильный ввод!\n";
                cout << "Введите номер группы: ";
	        }
///////////////////////////
            if (st->next == NULL)
            {
                deletest(st);
            }
            else
            {
                lastst->next = st->next;
                st->group = numgroup;
                inputstudent(st);
                deletest(st);
            }      
            
        }
        
                
        gr = gr->nextgr;
    }
}

void deletegroup(group *destgr)
{
    group *gr;
    group *lastgr;
    gr = beging;
    while(gr != destgr)
    {
        lastgr = gr;
        gr = gr->nextgr;
    }
    stud *k = gr->begin;
    while(k != NULL)
    {
        k = k->next;
        delete k;                  
    }
    if(gr == beging)
    {
        beging = gr->nextgr;
    }
    else
    {
        lastgr->nextgr = gr->nextgr;
    }
    
    delete gr;
}

void deletegroupmenu(group *gr)
{
    unsigned int n = 0;
    system("clear");
    cout << "Группы:\n\n";
    while(gr != NULL)
    {
        cout << ++n << ". " << gr->num << endl;
        gr = gr->nextgr;
    }
    cout << "Введите номер группы: ";
    unsigned int numgroup;
    while (1) 
    {
	    cin >> numgroup;
		if (cin.good() && numgroup > 0) break;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Неправильный ввод!\n";
        cout << "Введите номер группы: ";
	}
    gr = beging;
    bool flag;
    group *lastgr;
    while(gr != NULL)
    {
        if(gr->num == numgroup)
        {
            flag = true;
            stud *k = gr->begin;
            while(k != NULL)
            {
                k = k->next;
                delete k;                  
            }
            if(gr == beging)
            {
                beging = gr->nextgr;
            }
            else
            {
                lastgr->nextgr = gr->nextgr;
            }
            delete gr;
            break;              
        }
        lastgr = gr;
        gr = gr->nextgr;
            
    }
    if(flag == false) cout << "\nТакой группы нет!";
    std::cout << "\nДля продолжения нажмите enter...\n";
    std::cin.ignore(256, '\n');
    getchar();
}

void deletest(stud *destst)
{
    group *gr;
    group *lastgr;
    stud *lastst;
    stud *st;
    gr = beging;
    while(gr != NULL)
    {
        while(st != destst)
        {
            lastst = st;
            st = st->next;
        }
        if(st == destst)
        {
            if(st == gr->begin)
            {
                if(st->next == NULL)
                {
                    lastst->next = NULL;
                    delete st;
                    deletegroup(gr);
                    return;
                }
                else
                {
                   gr->begin = st->next;
                   delete st;
                   return; 
                }
            }
            else
            {
                if(st->next == NULL)
                {
                    lastst->next = NULL;
                    delete st;
                    return;
                }
                else
                {
                    lastst->next = st->next;
                    delete st;
                    return;
                }
                
            }    
        }
        else
        {
            lastgr = gr;
            gr = gr->nextgr;
        }
    }
}

void deletestudent(group *gr)
{
    if(gr == NULL)
    {
        system("clear");
        cout << "Список пуст!\n";
        std::cout << "\nДля продолжения нажмите enter...\n";
        std::cin.ignore(256, '\n');
        getchar();
        return;
    }
    system("clear");
    cout << "Чтобы удалить студента, будет выведен список. Запомните номер студента и затем введите его!\n\n";
    //cout << "Или введите полностью ФИО\n";
    unsigned int count;
    count = outputwithkey(beging);
    unsigned int delnum;
    cout << "Введите номер студента: ";
    while (1)
    {
		cin >> delnum;
		if (cin.good() && delnum > 0 && delnum <= count) break;
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Неправильный ввод!\n";
        cout << "Введите номер студента: ";
	}
    stud *del;
    unsigned int k = 1;
    stud *st = gr->begin;
    while(gr != NULL)
    {
        stud *lastst;
        while(st->next != NULL && k < delnum)
        {
            
            lastst = st;
            st = st->next;
            k++;
        }
        if (k < delnum)
        {
            gr = gr->nextgr;
            st = gr->begin;
            k++;
            continue;
        }
        /////
        if(st == gr->begin)
        {
            if(st->next == NULL)
            {
                //lastst->next = NULL;
                del = st;
                delete del;
                deletegroup(gr);
                return;
            }
            else
            {
                gr->begin = st->next;
                delete st;
                return;
            }
        }
        else
        {
            if(st->next == NULL)
            {
                lastst->next = NULL;
                del = st;
                delete del;
                return;
            }
            else
            {
                del = st;
                lastst->next = st->next;
                delete del;
                return;
            }
        }
        gr = gr->nextgr;
    }
}

void idzfunc(group *gr)
{
    idz *beginidz = new idz;
    beginidz->begin = gr->begin;
    beginidz->stipend = gr->begin->stipend;
    idz *idzgr = beginidz;
    while(gr != NULL)
    {
        stud* st = gr->begin;
        while(st != NULL)
        {
            unsigned int stip = st->stipend;
            if(stip == idzgr->stipend)
            {
                stud *k = idzgr->begin;
                stud *last;
                while(k != NULL)
                {
                    last = k;
                    k = k->nextstip;
                }
                if(k == NULL) k = new stud;
                k->nextstip = st;
            }
            st = st->next;
        }
        gr = gr->nextgr;
    }


    system("clear");
    idzgr = beginidz;
    while(idzgr != NULL)
    {
        cout << "Стипендия: " << idzgr->stipend << endl << endl;
        stud *k = idzgr->begin;
        unsigned int i = 0;
        while(k != NULL)
        {
            cout << i+1 << ". " << k->name << endl;
            k = k->next;
        }
        cout << endl;
        idzgr = idzgr->nextgr;
    }
    std::cout << "\nДля продолжения нажмите enter...\n";
    std::cin.ignore(256, '\n');
    getchar();
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
        while (1) 
        {
	        cin >> menu;
		    if (cin.good() && menu >= 0 && menu <= 8) break;
		    cin.clear();
		    cin.ignore(100, '\n');
		    cout << "Неправильный ввод!\n";
            cout << "Выберите действие: ";
	    }
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
        if (menu == 7)
        {
            deletegroupmenu(beging);
        }
        if (menu == 8)
        {
            idzfunc(beging);
        }
    }
    while (menu != 0);
    return 0;
}