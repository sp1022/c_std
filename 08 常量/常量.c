#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//const常量修饰符
const int a=100;//放在常量区，受到常量区的保护

void test01()
{
   //a=100;直接修改报错
   //间接修改
   int * p = &a;
   *p = 1000;// 不能修改，可以编译成功，但是无法修改
   printf("a=%d",a);
}


void test02()
{ 
    const int b=10;//局部的常量是放在栈区，伪常量
   int * p = &b;
   *p = 1000;// 不能修改，可以编译成功，但是无法修改
   printf("b=%d",b);
}

//字符串常量是可以共享的，下面p1 p2 p3指向了常量区同一个hello world地址
void test03()
{
  char * p1="hello world";
  char * p2="hello world";
  char * p3="hello world";

  printf("%d\n",p1);
  printf("%d\n",p2);
  printf("%d\n",p3);
}
//字符串常量可以修改吗？直接报内存错误，因为上面说过了，常量区是只读的，不能修改。
void test04()
{
  char * p1="hello world";
  p1[0]='w';

  printf("%s\n",p1);

}
int main()
{
    //test01();
    //test02();
    test03();
    //test04();
}