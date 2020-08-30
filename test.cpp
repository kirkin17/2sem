#include <iostream>
using namespace std;

string inputname()
{
    string name;
    getline(cin, name);
    return name;
}

int main()
{
    string name;
    cout << "Введите имя: ";
    name = inputname();

    cout << name;
}