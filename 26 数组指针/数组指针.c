#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1 先定义出数组的类型，再通过类型定义出数组指针
void test01()
{
  int arr[5]={1,2,3,4,5};
  typedef int(ARRAY_TYPE)[5];//ARRAY_TYPE是一个有 5个int元素的 数组类型
  //创建一个ARRAY_TYPE类型的指针，
  //这段话类似于:int a=10; int *p=&a;
  //其中 a对应了数组arr[5],*p 对应了 *arrP; &a对应了&arr
  ARRAY_TYPE * arrP = &arr;
  //*arrP====arr  *arrP通过解引用就是数组名arr
  for(int i=0;i<5;i++)
  {
    printf("%d\n",(*arrP)[i]);
  }
}




//2 直接定义数组指针变量  常用
void test02()
{
  int arr[5]={1,2,3,4,5};
  //语法：数据类型(*指针变量名称)[元素个数]
  int (*p)[5]=&arr;
  for(int i=0;i<5;i++)
  {
    printf("%d\n",(*p)[i]);//*p的解引用就是arr
  }
}
int main()
{
 // test01();
 test02();
}