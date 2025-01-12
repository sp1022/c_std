#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1 普通变量+指针变量
void test01()
{
    int a=10;
    int *p=NULL;
    p=&a;//建立关系
    *p=1000;//赋值
}

//2 实参+形参 
void changeValue(int * p)
{
    *p=10000;
}
void test02()
{
    int a=10;
    changeValue(&a);//传参，建立关系
    printf("%d\n",a);
}
int main()
{
    test02();
}