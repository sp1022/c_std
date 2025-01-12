#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//calloc
void test01()
{
  //malloc不会做清0的操作，即不会初始化
  //calloc会做初始化
  int *p=calloc(10,sizeof(int));
  for (int i=0;i<10;i++)
  {
    printf("%d",p[i]);
  }
}

//realloc
//如果后续空间足够大，则在原来基础上扩空间。
//如果后续空间不够大，则重新开辟空间，并将原来空间的内容拷贝到新空间
void test02()
{
    int *p=malloc(sizeof(int)*10);
    for(int i=0;i<10;i++)
    {
        p[i]=i+1;
    }
    for(int i=0;i<10;i++)
    {
       printf("%d\n",p[i]);
    }

  printf("扩容前的地址：%d\n",p);
  p=realloc(p,sizeof(int)*20);
  for(int i=0;i<20;i++)
    {
       printf("%d\n",p[i]);
    }
  printf("扩容后的地址：%d\n",p);
}
int main()
{
  //test01();
  test02();
}