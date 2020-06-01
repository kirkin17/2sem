#include <iostream>
using namespace std;
int main()
{
    while(1){
    float x,y;
    cout << "x: ";
    cin >> x;
    cout << "y: ";
    cin >> y;
    cout << "res: " << (2*x*y)-(y*y)-(2*x)-(4*y) << endl;
    }
}