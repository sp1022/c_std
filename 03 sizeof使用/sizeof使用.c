
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//1 本质不是一个函数，是一个运算符
void test01()
{
    printf("size of int=%d\n",sizeof(int));
    //对于统计变量时，可以不带括号
    double d=3.14;
    printf("size of double=%d\n",sizeof d);
}
//2 size的返回值是什么：是一个unsigned int
void test02()
{
    unsigned int a = 10;
    if(a-20>0)  //如果一个unsinged int和int去运算，结果都会转换为unsinged int,本来结果为-10，结果转换成了一个很大的值，导致结果错误
    {
      printf("大于0:%lu",(a-20));//
    }
    else{
      printf("小于0");
    }
}
//3 统计数组占用的内存空间大小
void calcAarray(int arr[])//数组名传入到函数中，数组名退化为一个指针，指针指向数组中的第一个元素
{
 printf("::::::::::arr占用内存空间bytes：%d",sizeof(arr));//该值打印为8
}
void test03()
{
    int arr[]={1,2,3,4,5,6};
    //printf("arr占用内存空间bytes：%d",sizeof(arr));//该值打印为24
    calcAarray(arr);
}
int main()
{
    //test01();
    //test02();
    test03();
}