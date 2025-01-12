#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h> //offsetof的头文件
/*
1 指针变量+1后跳跃的字节数
*/
void test01()
{
   char *p=NULL;
   printf("%d\n",p);//0
   printf("%d\n",p+1);//1
   double *p2=NULL;
   printf("%d\n",p2);//0
   printf("%d\n",p2+1);//8
}
/*
2 在解引用的时候取出的字节数
*/
void test02()
{
  char buf[1024]={0};
  int a=1000;
  memcpy(buf,&a,sizeof(int));

  char *p=buf;
  printf("%d\n",*(int *)p);//将char*转换为int*，可以取4个字节
}

//3 指针步长的练习
struct Person
{
    char a;//0-3
    int b;//4-7
    char buf[64];//8-71
    int d;//72-75  查找d的偏移量
};

void test03()
{
    struct Person p={'a',10,"hello world",10000};
    //p中d的偏移量是多少？
    printf("d的偏移量为:%d\n",offsetof(struct Person,d));
    //间接访问d的值
     printf("d的值为:%d\n",*(int*)(((char *)&p)+offsetof(struct Person,d)));
    //直接访问d
     printf("d的值为:%d\n",p.d);
     //使用p->d的方式访问
     struct Person * p2=&p;
     printf("d的值为:%d\n",p2->d);
}

int main()
{
    //test01();
    //test02();
    test03();
}