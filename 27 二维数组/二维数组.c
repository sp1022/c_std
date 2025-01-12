#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void test01()
{
    //1 第一种方式
    int arr[3][3]=
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    //2 第二种方式
    int arr2[3][3]={1,2,3,4,5,6,7,8,9};
    //3 第三种方式
    int arr3[][3]={1,2,3,4,5,6,7,8,9};

    int(*p)[3]=arr;//指针数组  一般情况下，指向第一行数组指针
    //通过p指针访问元素6
    printf("%d\n",*(*p+5));//*p(重点)   为第一行第一个元素地址,*p+5 为第6个元素地址
    printf("%d\n",*(*(p+1)+2));//p（重点）为第一行的指针，p+1 为第二行的地址，*(p+1)为第二行第一个元素的地址
    printf("%d\n",p[1][2]);
}

//二维数组打印
void printArray(int (*arrP)[3],int len1,int len2)
//void printArray(int arrp[3][3],int len1,int len2)
//void printArray(int arrP[][3],int len1,int len2)
{
   for(int i=0;i<len1;i++)
   {
     for (int j=0;j<len2;j++)
     {
        printf("%d ",arrP[i][j]);//可读性高
        //printf("%d ",*(*(arrP+i)+j));//可读性不高，但是这种方式要掌握
     }
     printf("\n");
   }
}
void test02()
{
     int arr[3][3]=
    {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    printArray(arr,3,3);

    printf("sizeof arr=%d\n",sizeof(arr));//36
    printf("%d\n",&arr);
    printf("%d\n",&arr+1);//上面的地址和下面的地址相差36，即一个步长为sizeof

    //二维数组的数组指针
    int(*p)[3][3]=&arr;
}
int main()
{
  //test01();
  test02();
}