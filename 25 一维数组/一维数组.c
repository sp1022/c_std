#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{

   int arr[5]={1,2,3,4,5};
   printf("sizeof arr=%d\n",sizeof(arr));//20
   //对数组名取地址
   printf("%d\n",&arr);
   printf("%d\n",&arr+1);//上面的地址+20
   //1 一维数组的名，是不是指向第一个元素的指针？是的，但是有两种特殊情况：
   //第一种：对数组名sizeof，为整个数组的长度
   //第二种：对数组名取地址，步长为整个数组的长度
   //除了这两种以外，一维数组名都是指向第一个元素
   int * p=arr;

   //2 数组名是指针常量，指针的指向是不可以修改的。Int * const p
  // arr=NULL;//这里报错了

  //3 数组访问的时候，下标是否可以为负数？可以
  p=p+3;
  printf("%d\n",p[0]);//4  指针+3后，指向4
  printf("%d\n",p[-1]);//3 指针-1后，指向3
}

void printArray(int arr[],int len)  //int arr[]等价于int *p,为了提高可读性，传参需要int arr[],让别人知道你传的是数组
{
    for(int i=0;i<len;i++)
    {
        printf("%d\n",arr[i]);
    }
}
void test02()
{
    int arr[5]={1,2,3,4,5};
    int len=sizeof(arr)/sizeof(int);
    printArray(arr,len);
}

int main()
{
  //test01();
  test02();
}