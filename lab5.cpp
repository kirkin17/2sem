#include <iostream>
using namespace std;

struct tree
{
	tree* left = NULL;
	tree* right = NULL;
	int num = 0;
};

void addtree(tree* p, int num)
{
	if (p->num == num) return;
	else if (p->num < num)
    {
		if (p->right)
			addtree(p->right, num);
		else
        {
			p->right = new tree;
			p->right->num = num;
		}
	}
	else if (p->num > num)
    {
		if (p->left)
			addtree(p->left, num);
		else
		{
			p->left = new tree;
			p->left->num = num;
		}
	}
}

void ins(tree* p)
{
	if (p != NULL)
    {
		ins(p->left);
		cout << p->num << ' ';
		ins(p->right);
	}
}

void pres(tree* p)
{
	if (p != NULL) 
    {
		cout << p->num << ' ';
		pres(p->left);
		pres(p->right);
	}
}

void posts(tree* p)
{
	if (p != NULL) 
    {
		posts(p->left);
		posts(p->right);
		cout << p->num << ' ';
	}
}


int main(){
	setlocale(LC_ALL, "RU");

	cout << "Введите целые числа: " << endl;
	int num;
	cin >> num;

	tree* p = new tree;
	p->num = num;

	do 
    {
		cin >> num;
		if (!num) break;
		addtree(p, num);
	} 
    while (1);

    cout << endl << "Инфиксный обход: " << endl;
	ins(p);

	cout << endl << "Префиксный обход: " << endl;
	pres(p);

	cout << endl << "Постфиксный обход: " << endl;
	posts(p);

	cout << endl;
}


