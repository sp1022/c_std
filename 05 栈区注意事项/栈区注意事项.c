#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1 例子1
int * func()
{
  int a =10;//栈上创建的变量
  return &a;
}
void test01()
{
  int *p=func();
  printf("*p=%d\n",*p);//
  printf("*p=%d\n",*p);//结果早已不重要，因为a已经释放，再去操作这块内存是非法操作
}
//2 例子2
char * getString()
{
    char str[]="hello world";
    return str;
}

void test02()
{
   char *p=NULL;
   p=getString();
   printf("p=%s\n",p);//打印出来为乱码，因为hello world先放在内存中的常量区，然后拷贝到栈区的str,调用完成后释放.
}

int main()
{
    test01();
    test02();
}