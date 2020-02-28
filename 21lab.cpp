#include <iostream>
using namespace std;
struct x
{
	int* p;
};
int main()
{
	x* h[50];	
	for (int i = 0; i < 50; i++)
	{
		h[i] = new x;		
		h[i]->p = new int;
		*(h[i]->p) = 1;
	}
	x* g = new x[100];
	for (int i = 0; i < 100; i++)
	{
		g[i].p = new int[20];
		for (int j = 0; j < 20; j++)
		{
			g[i].p[j] = 1;
		}
	}
}
