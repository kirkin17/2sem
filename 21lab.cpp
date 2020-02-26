#include <iostream>
using namespace std;

struct x
{
    int *p;
};

int main()
{
    x *h[50];
    for (int i = 0; i < 50; i++)
    {
        h[i] = new x;
        h[i]->p = new int;
     //   h[i]->p = 1;//
    }
}