#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void test01()
{
    //1 直接修改
    int a=10;
    a=20;
    //2 间接修改
    int *p=&a;
    //*p解引用
    *p=1000;
    printf("a=%d",a);
}

//自定义类型修改练习
typedef struct  Person
{
    /* data */
    char a;//0~3
    int b;//4-7
    char c;//8-11
    int d;//12-15
}MyPerson;
void test02()
{
  MyPerson p1={'a',10,'b',20};
  //直接修改
  p1.d=30;
  printf("person.d=%d\n",p1.d);

  //间接修改1
  MyPerson *p=&p1;
  p->d=100;
  printf("person.d=%d\n",p1.d);

  //间接修改2
  char * p2= &p1;
  //通过将地址转换为 int *，我们告诉编译器，我们打算从这个地址开始读取或写入一个整数（int）类型的值。
  //解引用这个 int * 类型的指针将允许我们直接访问或修改 d 成员的值
  printf("%d\n",*(int *)(p2+12));//通过字节移位取值，char *要跳12次
 printf("%d\n",*((int *)p2+3));//int*，只需要跳3次.先将p2转换为int *。由于内存对齐，只需要跳3次
}

int main()
{
 test02();
}
