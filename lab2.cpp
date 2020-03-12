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

    int n,m;
    cout << "Кол-во строк   : ";
    cin >> n;
    cout << "Кол-во столбцов: ";
    cin >> m;

    //first element
    x* start;
    x* ptr = start;
    x* ptr1 = start;
    ptr = new x;
    cin >> ptr->a;
    
    //next
    for (int i = 0; i < n-1; i++)
    {
        ptr1 = ptr;
        ptr->right = new x;
        ptr = ptr->right;
        cin >> ptr->a;
    }
    for (int i = 0; i < m-1; i++)
    {
        ptr = ptr1;
        ptr->down = new x;
        ptr = ptr->down;
        cin >> ptr->a;
        for (int j = 0; j < m-1; j++)
        {
            ptr->right = new x;
            ptr = ptr->right;
            cin >> ptr->a;
            ptr = ptr1;
            ptr->down = ptr1;
        }
        ptr = ptr1;
        ptr->down = ptr1;
    }

    // output
    ptr = start;
    ptr1 = start;
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{			
			cout << ptr->a << " ";
			ptr = ptr->right;
		}
		cout << endl;
		ptr = ptr1;
		ptr = ptr->down;
		ptr1 = ptr;
	}
}