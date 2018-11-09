#include <iostream>
#include <typeinfo>
using namespace std;

int add(int x, int y);
double add(double x, double y);

int main()
{
    int a = 10;
    int& ra = a;
    int *pa = NULL;

    ra = 20;
    *pa = 20;
    //const int a = 10;
    //const int& ra = a;
   
    //double d = 2.0;
    //const int& rd = d;
    //int a = 10;
    //int b = 20;
    ////int&sa;
    //int& ra = a;
    ////long& la = a;
    //int& ra = b;

    //cout << &a << endl;
    //cout << &ra << endl;
    return 0;
}
