
#include <iostream>
#include <fstream> 
#include <string.h>
#include <stdio.h>
#include <windows.h>

using namespace std;

//структура для хранения студентов
struct stud { 

	char FIO[50];
	int grup;
	int ozenka[5];
	int sum=0;
	int stipend;

/*	void rus() //функция для русификации не работала, но я ее оставила
	{
		CharToOemA(FIO,FIO);
	}*/
	//для хранения следующего элемента в списке
	stud* next = NULL; 
};
//структура для списка групп
struct Grup {

	stud* begin=NULL; //указатель на начало списка студентов группы
	int kol=0;
	int sum=0;
	int num; //номер группы

	Grup* next=NULL;

	//функция добалвения студента в группу
	void vstavka_student(stud* p) 
	{ 
		stud*  plast = NULL;
		stud* pnext = begin;
		//сначала я изменяю статистику группы
		kol++;
		for (int i = 0; i < 5; i++)
			p->sum += p->ozenka[i];
		sum += p->sum;
		//запись в список на нужную позицию
		if( (begin==NULL)||(strcmp(p->FIO, pnext->FIO) < 0) )
		{
			p->next = pnext;
			begin = p;
		}
		else {
			for (; pnext != NULL; pnext = pnext->next)
			{
				if (strcmp(p->FIO, pnext->FIO) >= 0) plast = pnext; //встроенную функция strcmp нашла в интернете, не уверена, что мы ее проходили
				else break;
			}
			plast->next = p;
			p->next = pnext;
		}	
	}

};
//ввод из файла
Grup* vvod_File(Grup* beg, char a[50])
{ 
	ifstream f(a);
	if (f.is_open()) 
	{
		while (!f.eof()) 
		{
			stud* s = new stud;
			f.get();
			f.getline(s->FIO, 128);
			s->rus();
			f >> s->grup >> s->stipend;
			for (int i = 0; i < 5; i++)
				f >> s->ozenka[i];
			//здесь я создаю новую группу или присоединяю к существующей
			Grup* p = beg;
			if (beg == NULL)
			{
				p = new Grup;
				beg = p;
				p->num = s->grup; //всем новым группам присваиваю соответствующий номер
			}
			else
			{
				for (; p->next != NULL; p = p->next)
					if (p->num == s->grup) break;
				if (p->num != s->grup)
				{
					p->next = new Grup;
					p = p->next;
					p->num = s->grup;
				}
			}
			p->vstavka_student(s);
		}
		f.close();
	}
	return beg; //возвращаю указатель на первый элемент в списке групп, иначе не сохраняется 
}
//вывод в файл
void vivod_File(Grup* grup, char a[50])
{ 
	ofstream f(a,ios::app);
	
	stud* s = grup->begin;
	while (s!=NULL)
	{
		s->rus();
		f << endl; //важно, чтобы файл не заканчивался перевоом строки
		f << s->FIO << endl;
		f << s->grup <<" "<< s->stipend << endl;
		for (int i = 0; i < 5; i++)
		{
			f << s->ozenka[i];
			if (i != 4) f << " ";
		}
		s = s->next;
	}
	f.close();
}
//ввод с клавиатуры
Grup* vvod(Grup* beg)
{
	stud* s = new stud;
	cout << "Введите имя\n";
	cin.get(); //cin.getline берет перевод строки за строку, поэтому я использую get
	cin.getline(s->FIO,50);
	s->rus();
	cout << "Введите группу и стипендию\n";
	cin >> s->grup >> s->stipend;
	cout << "Введите оценки\n";
	for (int i = 0; i < 5; i++)
		cin >> s->ozenka[i];
	//здесь тоже создаю группу или присоединяю
	Grup* p = beg;
	if (beg == NULL)
	{
		p = new Grup;
		beg = p;
		p->num = s->grup;
	}
	else 
	{
		for (; p->next != NULL; p = p->next)
			if (p->num == s->grup) break;
		if (p->num != s->grup)
		{
			p->next = new Grup;
			p = p->next;
			p->num = s->grup;
		}
	}
	p->vstavka_student(s);
	return beg;
}
//вывод на экран всех студентов группы
void vivod(Grup* grup)
{
	stud* s = grup->begin;
	while (s != NULL)
	{
		s->rus();
		cout << s->FIO << endl;
		cout << s->grup <<" "<< s->stipend << endl;
		for (int i = 0; i < 5; i++)
			cout << s->ozenka[i]<<" ";
		cout << endl << endl;
		s = s->next;
	}
}
//удаление студента
Grup* delet(Grup* beg, char fio[50], int ngr)
{
	Grup* p = beg;
	for (; p->num != ngr; p=p->next){}
	stud* s = p->begin;
	stud* slast=s;
	//поиск студента для удаления по имени
	for (;s!=NULL && strcmp(s->FIO, fio) != 0; s = s->next)
	{
		slast = s; //сохраняю предыдущего, чтобы список не разрушился при удалении
		if (s == NULL)
			break;
	}
	if (s != NULL)
	{
		//пересоздаю связи
		slast->next = s->next;
		if (s == p->begin)
			p->begin = s->next;
		p->sum -= s->sum;
		p->kol--;
		//если в группе стало 0 студентов я ее удаляю
		if (p->kol == 0)
		{
			p = beg;
			Grup* plast=NULL;
			for (; p->num != s->grup; p = p->next)
				plast = p;
			if (p == beg)
				beg = p->next;
			plast->next = p->next;
			delete p;
		}
		delete s;
	}
	else
		cout << "Ничего не найдено";
	return beg;
}
//изменение данных о студенте
Grup* change(Grup* beg, char fio[50], int ngr) 
{
	Grup* p = beg;
	for (; p->num != ngr; p = p->next) {}
	stud* s = p->begin;
	//здесь я ищу студента для изменения
	for (; strcmp(s->FIO,fio) != 0; s = s->next)
		if (s == NULL)
			break;
	if (s != NULL)
	{
		int a;
		cout << "выберете что поменять:\n";
		cout << "1 Имя \n2 Группу \n3 Стипедию \n4 Оценки\n";
		cin >> a;
		if (a == 1)
		{
			//если меняем имя, то нужно перестроить список
			cin.get();//защита cin.getline
			if (p->kol > 1)
			{
				stud* snew = p->begin;
				stud* slast = snew;
				for (; strcmp(snew->FIO, fio) < 0; snew = snew->next)
				{
					slast = snew;
				}
				cin.getline(s->FIO,50); //после того как убрали связи s со списком меняем имя
				//и добавляем в список обратно
				if (slast != snew)
					slast->next = s->next;
				else
					p->begin = p->begin->next;
				snew = p->begin;
				if (strcmp(snew->FIO, s->FIO) > 0)
				{
					p->begin = s;
					s->next = snew;
				}
				else
				{
					for (;snew!=NULL && strcmp(snew->FIO, s->FIO) < 0; snew = snew->next)
						slast = snew;
					s->next = slast->next;
					slast->next = s;
				}
			}
			else cin.getline(s->FIO, 50);
		}
		else if (a == 2)
		{
			//меняем группу студента
			cin >> s->grup;
			//здесь убираю студента из старой группы
			if (s == p->begin) 
			{
				p->begin = s->next;
			}
			else {
				stud* slast = p->begin;
				stud* snew = slast;
				for (; strcmp(snew->FIO, fio) != 0; snew = snew->next)
				{
					slast = snew;
				}
				slast->next = snew->next;
			}
			p->sum -= s->sum;
			p->kol--;
			int grup = p->num;
			//удаляю группу если в ней не осталось студентов
			if (p->kol == 0)
			{
				p = beg;
				Grup* plast=NULL;
				for (; p->num != grup; p = p->next)
					plast = p;
				if (p == beg)
					beg = p->next;
				plast->next = p->next;
				delete p;
			}
			//ищу или создаю новую группу студенту
			Grup* p = beg;
			for (; p->next != NULL; p = p->next)
				if (p->num == s->grup) break;
			if (p->next == NULL)
			{
				p->next = new Grup;
				p = p->next;
				p->num = s->grup;
			}
			p->vstavka_student(s);
		}
		else if (a == 3)
			cin >> s->stipend;//стипендия меняется проще
		else if (a == 4) 
			for (int i = 0; i < 5; i++) 
			{
				//перезаписываю сумму оценок группы и студента
				p->sum -= s->ozenka[i];
				cin >> s->ozenka[i];
				p->sum += s->ozenka[i];
			}
	
	}
	else
		cout << "Ничего не найдено";
	return beg;
}

int main() 
{
	//русский язык в консоли
	setlocale(LC_ALL, "rus");
	char a[50];
	int vibor;
	Grup* g = NULL;
	do
	{
		//вывод студентов всех групп
		cout << endl;
		Grup* gnext = g;
		for (; gnext != NULL; gnext = gnext->next)
			vivod(gnext);
		//меню
		cout << "Выберете действие:\n1- добавить элемент с клавиатуры 2-добавить элементы из файла 3- вывести элементы в файл\n";
		cout << "4-вывести группу с наибольшим средним баллом 5- удалить студента 6- изменить информацию о студенте 7- выйти\n";
		cin >> vibor;
		//прочитать с клавиатуры
		if (vibor == 1)
			g=vvod(g);
		else if (vibor == 2)
		{
			//прочитать из файла
			cout << "Введите название файла\n";
			cin >> a;
			g=vvod_File(g, a);
		}
		else if (vibor == 3)
		{
			//вывожу студентов всех групп в файл(если он существует записываю в конец)
			cout << "Введите название файла\n";
			cin >> a;
			gnext = g;
			for (; gnext != NULL; gnext = gnext->next)
				vivod_File(gnext,a);
		}
		else if (vibor == 4)
		{
			//поиск группы с макимальным средним баллом 
			Grup* p = g;
			float max = (float)p->sum / (float)p->kol;
			int num;
			for (; p != NULL; p = p->next)
				if ((float)p->sum / (float)p->kol >= max) {
					num = p->num;
					max = (float)p->sum / (float)p->kol; //без float не компилируется
				}
			p = g;
			for (; p->num != num; p = p->next) {}
			//вывод на экранн группы с максимальным средним баллом и пауза
			vivod(p);
			system("pause");
		}
		else if (vibor == 5)
		{
			//здесь я вызываю удаление студента
			int num;
			cout << "Введите ФИО\n";
			cin.get();
			cin.getline(a, 50);
			cout << "Введите номер группы\n";
			cin >> num;
			g = delet(g, a, num);
		}
		else if (vibor == 6)
		{
			//здесь я вызываю изменение данных студента
			int num;
			cout << "Введите ФИО\n";
			cin.get();
			cin.getline(a, 50);
			cout << "Введите номер группы\n";
			cin >> num;
			g = change(g, a, num);
		}
	
	} while (vibor != 7);
	return 0;
}
