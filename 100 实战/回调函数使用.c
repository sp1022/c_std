#include<stdio.h>

typedef int(*callBackFuncDef)(int , int ); //定义一个回调函数

//定义一个回调方法
int execMethod(int a,int b, int(*callBackFunc)(int , int ))
{
   return callBackFunc(a,b);
}

int execMethod2(int a,int b, callBackFuncDef callDef)
{
   return callDef(a,b);
}

//定义函数1：加法
int add(int a,int b)
{
    return a+b;
}
//定义函数2：乘法
int mult(int a,int b)
{
    return a*b;
}
int main()
{
    // int num1=10,num2=20;
    // //执行回调
    // int result1=execMethod(num1,num2,add);
    // int result2=execMethod(num1,num2,mult);
    // printf("回调函数使用:%d   %d \n",result1,result2);

    //执行回调 使用typedef
     result1=execMethod2(num1,num2,add);
     result2=execMethod2(num1,num2,mult);
     printf("回调函数2使用:%d   %d",result1,result2);
   
}