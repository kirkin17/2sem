#include <iostream> 
using namespace std;


struct unit 
	{
		int num;
		unit* next = NULL;
	};
	
unit* paste(unit* frst, int a)  
{ 
	unit* p = new unit; 
	p->num = a;
	if (frst == NULL) 
	frst = p;
	else 
	{
		unit* q = frst;
		if (a < q->num)
		{ 
			p->next = q;
			frst = p;
		}
		else 
		{
			unit* last_q =q;
			while (q != NULL && a > q->num) 
			{
				last_q = q;
				q=q->next;
			}
		last_q->next = p;              
		if (q != NULL) p->next = q;
		}
	}
	return frst;
}

void output(unit *p) 
{ 
while (p != NULL)
{
	cout << p->num << " ";
	p = p->next;
} 
cout << endl;
cout << endl;
}

int main()
{
	setlocale(LC_ALL, "rus");
	unit* frst = NULL;
	cout << "Введите последовательность чисел, в конце 0\n";
	while (1)
	{
	int num;
	cin >> num;
	if (num!=0) frst = paste(frst, num);
	else break;
	}
	int num;
	do 
	{ 
		cout << endl;
		output(frst);
		cout << "Введите новое значение, в конце 0\n";
		cin >> num;
		if(num!=0) frst = paste(frst, num);
	}
	while (num != 0);
	return 0;
}

