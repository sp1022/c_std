#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void test01()
{
    char *p=NULL;
    strcpy(p,"111");//err报错，因为p没有内存地址，是一个空指针

    char *q=0x1234;
    strcpy(q,"111");//err报错，1234是一个未知的地址，所以*q是一个野指针
}
//野指针的情况
int * doWork(){
    int a=1000;
    int *p=&a;
    return p;
}
void test02()
{
   //1 声明未初始化的指针
   //int *p;
   //printf("%d\n",*p);

   //2 malloc后free的指针
   int *p=malloc(sizeof(int));
   *p=100;
   printf("%d\n",*p);
   free(p);
   printf("%d\n",*p);
   printf("%d\n",*p);
   //*p=1000;//不要操作野指针
   p=NULL;//野指针需要设置为null

   //3 指针超出作用域
   int * p2=doWork();//该内存地址在dowork结束后栈区已经释放

   printf("%d\n",*p2);
   printf("%d\n",*p2);

   //4 空指针可以重复释放，野指针不能重复释放
}
int main()
{
    //test01();
    test02();
}