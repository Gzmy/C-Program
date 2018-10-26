//#include <stdio.h>
//
//namespace N1
//{
//    int a = 10;
//    int b;
//
//    int ADD(int left, int right){
//        return left+right;
//    }
//}
//
//namespace N2
//{
//    int a = 30;
//    int b = 40;
//
//    int sub(int left, int right){
//        return left-right;
//    }
//
//    namespace N3{
//        int a = 50;
//        int b = 60;
//
//        int mul(int left, int right){
//            return left*right;
//        }
//    }
//}
//
////在同一工程中可以定义相同的命名空间
//namespace N1
//{
//    int c = 70;
//    int d = 80;
//
//    int div(int left, int right){
//        return left/right;
//    }
//}
//
//int a = 10000000;
//
//int main()
//{
//    int a = 10;
//    printf("%d\n", a);
//    printf("%d\n", ::a);
//    printf("%d\n", N1::a);
//    return 0;
//} 

#include <iostream>
#include <stdio.h>
using namespace std;

//函数缺省参数
int sum(int a = 10, int b = 20, int c = 30)
{
    return a+b+c;
}

int sub(int a, int b = 10)
{
    return a - b;
}

//函数重载
int dev(int a, int b)
{
    return a * b;
}

double dev(double a, double b)
{
    return a * b;
}

long dev(long a, long b)
{
    return a * b;
}

int add(int a, int b);


//引用没有独立空间,和实体公用一块空间
int& Add(int a, int b)
{
    int c = a + b;
    return c;
}


int main()
{
    int& ret = Add(10, 20);
    Add(100, 200);
    cout<<"Add(10, 20) is :"<<ret<<endl;
    //int a = 10;
    //int& ra = a;
    //printf("%p\n", &a);
    //printf("%p\n", &ra);
    //add(2, 5);
    //return 0;
    //cout<<dev(2, 4)<<endl;
    //cout<<dev(2.5, 4.1)<<endl;
    //cout<<sum(1)<<endl;
    //cout<<sub(5)<<endl;
    return 0;
}
