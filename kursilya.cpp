#include <iostream>
#include <fstream> 
#include <string>
#include <stdio.h>
using namespace std;

struct grup;

struct stud //структура студентов
	{ 
		string n; // имя
		int g; //номер группы
		int grades[5]; //оценки
		int stipend; //стипендия
		grup* grup;
		stud* next = NULL;//следующий элемент в списке потока
		stud* next_gr = NULL;//следующий элемент в списке группы
	};

struct grup //список групп
	{ 

		stud* begin = NULL; //указатель на начало списка студентов группы
		int cou = 0; //количество студентов в группе
		int num; //номер группы

		grup* next = NULL; //следующая группа
	};

struct beginer //структура для хранения первого элемента списка групп и студентов
	{
		stud* stud=NULL; 
		grup* grup=NULL;
	};

grup* new_grup(grup* beg, grup* ne) //функция добалвения группы
{
	grup* g = beg; 
	if (beg == NULL)  //если список пустой задаем новый элемент
		beg = ne; 
	else
		{
			while (g->next != NULL) //новая группа содержит 1 студента так что добавляем ее в конец
				g = g->next;
			g->next = ne;
		}
	return beg; //возвращается указатель на начало списка групп
}

grup* re_grup(grup* beg, grup* ne) //функция перестановки группы при добавлении студента
{
	grup* g = beg; 
	if (beg->next != NULL) 
		{
			if (beg != ne) //убираем элемент из списка групп
				{
					while (g->next != ne)
						g = g->next;
					g->next = ne->next;
				}
			else
				{
					beg = beg->next;
				}
			g = beg;
			if (ne->cou >= g->cou) //ищем место для вставки обратно в список групп
				{
					ne->next = g;
					beg = ne;
				}
			else 
				{
					while ((g->next != NULL) && (g->next->cou > ne->cou))
						g = g->next;
					ne->next = g->next;
					g->next = ne;
				}		
		}
	return beg;
}

beginer* new_stud(stud* ne, beginer* b) //функция добалвения студента
{
	stud* t = b->stud; 
	grup* g = b->grup;
	while ((g != NULL)&&(g->num != ne->g))//ищем группу для добавления в нее сутдента
		g = g->next;
	if (g == NULL) 
		{
			g = new grup; //если не нашлось группы для вставки- создаем новую
			g->num = ne->g;
			b->grup = new_grup(b->grup, g); 
		}
	g->cou++;
	ne->grup = g;
	b->grup=re_grup(b->grup,g);
	if (b->stud == NULL) //добавление в список потока 
		b->stud = ne; 
	else 
		{
			while (t->next != NULL)
				t = t->next;
			t->next = ne;
		}
	t = g->begin;
	if (g->begin == NULL) //добавление в список группы
		g->begin = ne; 
	else
		{
			while (t->next_gr != NULL)
				t = t->next_gr;
			t->next_gr = ne;
		}
	return b; //возвращаем указатель на начало обоих списков
}


beginer* in_file(beginer* beg) //ввод из файла
{
	ifstream file("in.txt"); //открытие файла для чтения
	if (file.is_open())
		{
			while (!file.eof())
				{
					stud* ne = new stud;
					getline(file, ne->n); //чтение данных
					if (ne->n == "") //если прочитана пустая строка не создавать студента
						{
							delete ne;
							break;
						}
					file >> ne->g;
					for (int i = 0; i < 5; i++)
						file >> ne->grades[i];
					file >> ne->stipend;
					new_stud(ne,beg);
					file.get();//переходим на следующую строкуы
				}
			file.close(); 
		}
	return beg;
}

beginer* in(beginer* beg) //ввод
{
	stud* ne = new stud;
	cout << "Введите имя студента" << endl; //чтение данных
	cin.get(); //переход на следующую строку после выбора действия из меню
	getline(std::cin, ne->n);
	cout << "Введите группу" << endl;
	std::cin >> ne->g;
	cout << "Введите оценки" << endl;
	for (int i = 0; i < 5; i++)
		std::cin >> ne->grades[i];
	cout << "Введите стипендию" << endl;
	std::cin >> ne->stipend;
	new_stud(ne, beg);
	return beg; //возвращения указателя на начала списков
}


void out_file(stud* beg) //вывод в файл
{
	ofstream file("out.txt"); //открытие файла на запись
	stud* ne = beg;
	while (ne != NULL)
		{
			file << ne->n << endl; //запись
			file << ne->g << endl;
			for (int i = 0; i < 5; i++)
			{
				file << ne->grades[i]<< " ";
			}
			file << endl << ne->stipend << endl;
			ne = ne->next;
		}
	file.close();
}

void out(stud* beg) //вывод на экран
{
	stud* ne = beg;
	while (ne != NULL) //пока в списке есть студенты
		{
			std::cout << "ФИО:" << ne->n <<"|"<< endl; // | чтобы обозначать, если имя заканчивается на пробел
			std::cout << "Группа:" << ne->g << endl << "Оценки:";
			for (int i = 0; i < 5; i++)
			{
				std::cout << ne->grades[i] << " ";
			}
			std::cout << endl << "Стипендия:" << ne->stipend << endl << endl;
			ne = ne->next; //переход к следующему студенту списка
		}
}

beginer* change(beginer* begin, string name, int type) //изменение данных о студенте
{
	stud* t = begin->stud;
	while (t->n != name)
		t = t->next;
	
	if (type == 1)
		{
			cin.get();  //чтение нового имени
			getline(std::cin, t->n);
		}
	else if (type == 2)
		{
			cin >> t->g; //чтение новой группы
			t->grup->cou--; //удаление из старой группы
			if (t == t->grup->begin)
				{
					stud* te = t->next_gr;
					t->grup->begin = te;
				}
			else
				if(t->next_gr!=NULL) t->next_gr = t->next_gr->next_gr;

			grup* b=begin->grup;  //поиск группы или создание новой группы
			if (b->num != t->g)
				{
					while ((b != NULL) && (b->num != t->g))
						b = b->next;
					if ((b == NULL) && (b->num != t->g))
						{
							b = new grup;
							b->num = t->g;
							begin->grup = new_grup(begin->grup, b);
						}
				}
			stud* ne = b->begin;
			if (b->begin == NULL) //добавление в список группы
				b->begin = t;
			else
				{
					while (ne->next_gr != NULL)
						ne = ne->next_gr;
					ne->next_gr = t;
				}
			b->cou++;
			t->grup = b;
			begin->grup = re_grup(begin->grup, b); //сортировка групп
		}
	else if (type == 3)
		{
			for (int i = 0; i < 5; i++) //чтение новых оценок
				cin >> t->grades[i];
		}
	else if (type == 4)
		cin >> t->stipend; //чтение новой стипендии
	return begin;
}

beginer* delet(beginer* begin, string name) //удаление студента
{
	stud* t = begin->stud;
	stud* del=NULL;
	if(begin->stud->n==name) //поиск студента по имени и удаление из общего списка
		{
			del = t;
			t = t->next;
			begin->stud = t;
		}
	else
		{
			while (t->next->n != name)
				t = t->next;
			del = t->next;
			if(t->next!=NULL) t->next = t->next->next;
		}
	del->grup->cou--; //удаление из списка группы
	if (del == del->grup->begin)
		{
			t = del->next_gr;
			del->grup->begin = t;
		}
	else
		{
			if(del->next_gr!= NULL) del->next_gr = del->next_gr->next_gr;
		}
	re_grup(begin->grup, del->grup); //сотрировка групп с новым количеством человек
	delete del;
	return begin;
}

int main()
{
	SetConsoleCP(1251);      //русский язык
	SetConsoleOutputCP(1251);
	int select;
	beginer* begin = new beginer;
	do
	{
		system("cls");
		cout << "Выберете:" << endl << " 1. Вывести список студентов на экран" << endl;
		cout << " 2. Вывести список студентов в файл" << endl;
		cout << " 3. Ввести данные о студенте с клавиатуры" << endl;
		cout << " 4. Ввести данные о студентах из файла (in.txt)" << endl;
		cout << " 5. Изменить данные о студенте" << endl;
		cout << " 6. Удалить студента" << endl;
		cout << " 7. Вывести список групп по кол-ву человек" << endl;
		cout << " 9. Для завершения работы" << endl;
		cin >> select;
		if (select == 1) //вывод на экран
			{
				stud* t = begin->stud;
				out(t);
				system ("pause");
			}
		else if (select == 2)//вывод в файл
			{
				stud* t = begin->stud;
				out_file(t);
			}
		else if (select == 3) //прочитать с клавиатуры
			{
				begin=in(begin);
			}
		else if (select == 4)
			{
				begin = in_file(begin);
			}
		else if (select == 5) //изменение информации о студенте
			{
				int type;
				string n;
				out(begin->stud); //вывод студентов, чтоы было проще выбрать по ФИО
				cout << "Введите имя студента:" << endl; 
				cin.get();
				getline(std::cin, n);
				cout << "Выберете данные для изменения:" << endl; //выбор, что изменить
				cout << " 1. ФИО \n 2. Группу \n 3. Оценки \n 4. Стипедию\n";
				cin >> type;
				begin=change(begin,n,type);
			}
		else if (select == 6) //удаление студента
			{ 
				string n;
				out(begin->stud); //вывод студентов чтобы проще выбрать студента для удаления
				cout << "Введите имя студента:" << endl;
				cin.get();
				getline(std::cin, n);
				begin=delet(begin,n);
			}
		else if (select == 7) //дополнительное задание- вывод количества студентов в каждой группе
			{
				grup* t = begin->grup; //список групп отсортирован по убыванию
				while (t != NULL) 
					{
						cout << t->num << ": " << t->cou<<endl;
						t = t->next;
					}
				system("pause");
			}
	} while (select != 9);
	return 0;
}
