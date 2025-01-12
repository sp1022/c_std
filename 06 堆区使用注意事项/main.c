#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//堆区使用
int * getSpace()
{
   int * p=malloc(sizeof(char)*5);//堆区开辟内存
   if (p==NULL)
   {
    return NULL;
   }
   for(int i=0;i<5;i++)
   {
     p[i]=100+i;
   }
   return p;
}

void test01()
{
    int * p=getSpace();
    for(int i=0;i<5;i++)
    {
    printf("%d\n",p[i]);
    }
    free(p);//释放堆区的内存
    p=NULL;
}

//注意事项
/*
4.3 堆区注意：
      如果主调函数中，一个空指针分配内存，则被调函数中，利用同级指针是分配失败的。
      解决方式：利用高级指针修饰低级指针.
      test02()失败
      test03()成功
*/
void allocateSpace(char *pp)
{
   char *temp=malloc(100);
   memset(temp,0,100);//初始化
   strcpy(temp,"hello world");
   pp=temp;
}
void test02()
{
    char *p=NULL;
    allocateSpace(p);
    printf("p=%s\n",p);
}

void allocateSpace2(char **pp)
{
   char *temp=malloc(100);
   memset(temp,0,100);
   strcpy(temp,"hello world");
   *pp=temp;
}
void test03()
{
    char *p=NULL;
    allocateSpace2(&p);
    printf("p2=%s\n",p);
}
int main()
{
    //test01();
    test02();
    test03();
}