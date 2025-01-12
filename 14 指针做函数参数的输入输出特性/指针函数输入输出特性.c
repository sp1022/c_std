#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/*输入特性：在主调函数中分配内存，在被调函数使用*/
void func(char *p)
{
  strcpy(p,"hello world");
}
//1 在主调函数分配内存，被调函数使用
void test01()
{
  char buf[1024]={0};//在栈上分配内存
  func(buf);
  printf("%s\n",buf);
}


void printStr(char *p)
{
    printf("%s\n",p);
}
//2 主调函数使用堆分配内存
void test02()
{
   char *p=malloc(sizeof(char)*64);
   memset(p,0,64);
   //在被调函数中，输出
   strcpy(p,"hello world");
   printStr(p);
   free(p);
   p=NULL;
}



/*输出特性：在被调函数中分配内存*/
void allocateSpace(char **p)
{
  char *temp=malloc(sizeof(char)*64);
  memset(temp,0,64);
  strcpy(temp,"hello world");
  *p=temp;
}

void test03()
{
  char *p=NULL;
  allocateSpace(&p);//空指针没有分配空间，需要使用高级指针去修饰低级指针
  printf("%s",p);
  free(p);
  p=NULL;
}

int main()
{
  //test01();
  //test02();
  test03();
}