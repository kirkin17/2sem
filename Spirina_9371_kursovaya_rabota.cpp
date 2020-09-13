
#include <iostream>
#include <fstream> 
#include <string.h>
#include <stdio.h>

using namespace std;

//��������� ��� �������� ���������
struct stud { 

	char FIO[50];
	int grup;
	int ozenka[5];
	int sum=0;
	int stipend;

	void rus() //������� ��� ����������� �� ��������, �� � �� ��������
	{
		//CharToOemA(FIO,FIO);
	}
	//��� �������� ���������� �������� � ������
	stud* next = NULL; 
};
//��������� ��� ������ �����
struct Grup {

	stud* begin=NULL; //��������� �� ������ ������ ��������� ������
	int kol=0;
	int sum=0;
	int num; //����� ������

	Grup* next=NULL;

	//������� ���������� �������� � ������
	void vstavka_student(stud* p) 
	{ 
		stud*  plast = NULL;
		stud* pnext = begin;
		//������� � ������� ���������� ������
		kol++;
		for (int i = 0; i < 5; i++)
			p->sum += p->ozenka[i];
		sum += p->sum;
		//������ � ������ �� ������ �������
		if( (begin==NULL)||(strcmp(p->FIO, pnext->FIO) < 0) )
		{
			p->next = pnext;
			begin = p;
		}
		else {
			for (; pnext != NULL; pnext = pnext->next)
			{
				if (strcmp(p->FIO, pnext->FIO) >= 0) plast = pnext; //���������� ������� strcmp ����� � ���������, �� �������, ��� �� �� ���������
				else break;
			}
			plast->next = p;
			p->next = pnext;
		}	
	}

};
//���� �� �����
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
			//����� � ������ ����� ������ ��� ����������� � ������������
			Grup* p = beg;
			if (beg == NULL)
			{
				p = new Grup;
				beg = p;
				p->num = s->grup; //���� ����� ������� ���������� ��������������� �����
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
	return beg; //��������� ��������� �� ������ ������� � ������ �����, ����� �� ����������� 
}
//����� � ����
void vivod_File(Grup* grup, char a[50])
{ 
	ofstream f(a,ios::app);
	
	stud* s = grup->begin;
	while (s!=NULL)
	{
		s->rus();
		f << endl; //�����, ����� ���� �� ������������ �������� ������
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
//���� � ����������
Grup* vvod(Grup* beg)
{
	stud* s = new stud;
	cout << "������� ���\n";
	cin.get(); //cin.getline ����� ������� ������ �� ������, ������� � ��������� get
	cin.getline(s->FIO,50);
	s->rus();
	cout << "������� ������ � ���������\n";
	cin >> s->grup >> s->stipend;
	cout << "������� ������\n";
	for (int i = 0; i < 5; i++)
		cin >> s->ozenka[i];
	//����� ���� ������ ������ ��� �����������
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
//����� �� ����� ���� ��������� ������
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
//�������� ��������
Grup* delet(Grup* beg, char fio[50], int ngr)
{
	Grup* p = beg;
	for (; p->num != ngr; p=p->next){}
	stud* s = p->begin;
	stud* slast=s;
	//����� �������� ��� �������� �� �����
	for (;s!=NULL && strcmp(s->FIO, fio) != 0; s = s->next)
	{
		slast = s; //�������� �����������, ����� ������ �� ���������� ��� ��������
		if (s == NULL)
			break;
	}
	if (s != NULL)
	{
		//���������� �����
		slast->next = s->next;
		if (s == p->begin)
			p->begin = s->next;
		p->sum -= s->sum;
		p->kol--;
		//���� � ������ ����� 0 ��������� � �� ������
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
		cout << "������ �� �������";
	return beg;
}
//��������� ������ � ��������
Grup* change(Grup* beg, char fio[50], int ngr) 
{
	Grup* p = beg;
	for (; p->num != ngr; p = p->next) {}
	stud* s = p->begin;
	//����� � ��� �������� ��� ���������
	for (; strcmp(s->FIO,fio) != 0; s = s->next)
		if (s == NULL)
			break;
	if (s != NULL)
	{
		int a;
		cout << "�������� ��� ��������:\n";
		cout << "1 ��� \n2 ������ \n3 �������� \n4 ������\n";
		cin >> a;
		if (a == 1)
		{
			//���� ������ ���, �� ����� ����������� ������
			cin.get();//������ cin.getline
			if (p->kol > 1)
			{
				stud* snew = p->begin;
				stud* slast = snew;
				for (; strcmp(snew->FIO, fio) < 0; snew = snew->next)
				{
					slast = snew;
				}
				cin.getline(s->FIO,50); //����� ���� ��� ������ ����� s �� ������� ������ ���
				//� ��������� � ������ �������
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
			//������ ������ ��������
			cin >> s->grup;
			//����� ������ �������� �� ������ ������
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
			//������ ������ ���� � ��� �� �������� ���������
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
			//��� ��� ������ ����� ������ ��������
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
			cin >> s->stipend;//��������� �������� �����
		else if (a == 4) 
			for (int i = 0; i < 5; i++) 
			{
				//������������� ����� ������ ������ � ��������
				p->sum -= s->ozenka[i];
				cin >> s->ozenka[i];
				p->sum += s->ozenka[i];
			}
	
	}
	else
		cout << "������ �� �������";
	return beg;
}

int main() 
{
	//������� ���� � �������
	setlocale(LC_ALL, "rus");
	char a[50];
	int vibor;
	Grup* g = NULL;
	do
	{
		//����� ��������� ���� �����
		cout << endl;
		Grup* gnext = g;
		for (; gnext != NULL; gnext = gnext->next)
			vivod(gnext);
		//����
		cout << "�������� ��������:\n1- �������� ������� � ���������� 2-�������� �������� �� ����� 3- ������� �������� � ����\n";
		cout << "4-������� ������ � ���������� ������� ������ 5- ������� �������� 6- �������� ���������� � �������� 7- �����\n";
		cin >> vibor;
		//��������� � ����������
		if (vibor == 1)
			g=vvod(g);
		else if (vibor == 2)
		{
			//��������� �� �����
			cout << "������� �������� �����\n";
			cin >> a;
			g=vvod_File(g, a);
		}
		else if (vibor == 3)
		{
			//������ ��������� ���� ����� � ����(���� �� ���������� ��������� � �����)
			cout << "������� �������� �����\n";
			cin >> a;
			gnext = g;
			for (; gnext != NULL; gnext = gnext->next)
				vivod_File(gnext,a);
		}
		else if (vibor == 4)
		{
			//����� ������ � ����������� ������� ������ 
			Grup* p = g;
			float max = (float)p->sum / (float)p->kol;
			int num;
			for (; p != NULL; p = p->next)
				if ((float)p->sum / (float)p->kol >= max) {
					num = p->num;
					max = (float)p->sum / (float)p->kol; //��� float �� �������������
				}
			p = g;
			for (; p->num != num; p = p->next) {}
			//����� �� ������ ������ � ������������ ������� ������ � �����
			vivod(p);
			system("pause");
		}
		else if (vibor == 5)
		{
			//����� � ������� �������� ��������
			int num;
			cout << "������� ���\n";
			cin.get();
			cin.getline(a, 50);
			cout << "������� ����� ������\n";
			cin >> num;
			g = delet(g, a, num);
		}
		else if (vibor == 6)
		{
			//����� � ������� ��������� ������ ��������
			int num;
			cout << "������� ���\n";
			cin.get();
			cin.getline(a, 50);
			cout << "������� ����� ������\n";
			cin >> num;
			g = change(g, a, num);
		}
	
	} while (vibor != 7);
	return 0;
}
