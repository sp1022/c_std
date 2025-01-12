#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//测试栈的生长方向
void test01()
{   
   int a=10;//栈底  高内存地址
   int b=10;
   int c=10;
   int d=10;//栈顶  低内存地址
   printf("%d\n",&a);
   printf("%d\n",&b);
   printf("%d\n",&c);
   printf("%d\n",&d);
}
//内存存储方式
void test02()
{
    int a = 0x11223344;
    char * p= &a;
    printf("%x\n",*p);    //44  低位字节(栈顶)
    printf("%x\n",*(p+1));//33
    printf("%x\n",*(p+2));//22
    printf("%x\n",*(p+3));//11  高位字节(栈底)
}
int main()
{
    //test01();
    test02();
}