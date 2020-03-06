#include <iostream>
using namespace std;
struct x
{
	int a;
	x* right;
	x* down;
};

int main()
{
	setlocale(LC_ALL, "ru");
	int n, m;
	int maxCol, maxStr;
	int t = 0;

	cin >> n >> m;
	
	x* p = new x;
	x* p1;
	x* d = p;
	x* d1 = p;
	x* start = p;
	cin >> p->a;
	for (int i = 0; i < m-1; i++)
	{
		p->right = new x;
		p = p->right;
		cin >> p->a;		
	}
	for (int i = 0; i < n-1; i++)
	{
		p = d1;
		p1 = d1;
		d1->down = new x;
		d1 = d1->down;
		cin >> d1->a;
		d = d1;

		for (int j = 0; j < m-1; j++)
		{
			p = p->right;
			d->right = new x;
			d = d->right;
			cin >> d->a;
			p->down = d;
		}
	}
	p = start;
	p1 = start;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			cout << p->a << " ";
			p = p->right;
		}
		cout << endl;
		p = p1;
		p = p->down;
		p1 = p;
	}
	p = start;
	p1 = start;
	for (int i = 0; i < n; i++)
	{
		maxStr = p1->a;
		for (int j = 0; j < m; j++)
		{
			p = p->right;
			if (p->a > maxStr)
				maxStr = p->a;
		}
		cout << "Максимальный элемент в " << ++t << " строке = " << maxStr << endl;		
		p = p1;
		p = p->down;
		p1 = p;
	}
	p = start;
	p1 = start;
	t = 0;
	cout << endl;
	for (int j = 0; j < m; j++)
	{
		maxCol = p->a;
		for (int i = 0; i < n; i++)
		{
			p = p->down;
			if (p->a > maxCol)
				maxCol = p->a;
		}
		cout << "Максимальный элемент в " << ++t << " столбце = " << maxCol << endl;
		p = p1;
		p = p->right;
		p1 = p;
	}
}
