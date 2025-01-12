#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1 指针越界
//2 指针叠加不断改变指针的指向，释放指针出错。
//3 返回局部变量地址
//4 一块指针释放多次

//对错误2的演示例子
void test01()
{
  char *p=malloc(64);
  for(int i=0;i<10;i++)
  {
     *p=i+97;
     printf("%c\n",*p);
      p++;  //一级指针已经移动了10次
  }
  if(p!=NULL)
  {
    free(p);//这里释放时，无法从首位置释放。导致报错。
  }
}

//修改后：是用临时指针*pp指向*p,操作*pp，释放的时候可以释放*p
void test02()
{
  char *p=malloc(64);
  char *pp=p;
  for(int i=0;i<10;i++)
  {
     *pp=i+97;
     printf("%c\n",*pp);
     pp++;
  }
  if(p!=NULL)
  {
    free(p);
  }
}
int main()
{
    test01();
    //test02();
}