#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
  //1 未定义长度，要手动增加\0，否则为乱码
  char str[]={'a','b','c','\0'};
  printf("%s\n",str);
  //2 定义了长度，默认会加\0. 
  char str2[100]={'a','b','c'};
  printf("%s\n",str2);
  //3 以"定义会默认增加\0
  char str3[]="hello";
  printf("%s\n",str3);
  printf("%d\n",sizeof(str3));//sizeof会计算\0，所以为6
  printf("%d\n",strlen(str3));//strlen不会计算\0,所以为5

  //4 下面结果是杜少？
  char str4[100]="hello";
  printf("%d\n",sizeof(str4));//100
  printf("%d\n",strlen(str4));//5

  //5 下面是什么结果？
  char str5[]="hello\0world";
  printf("%s\n",str5);//hello  %s碰到\0结束
  printf("%d\n",sizeof(str5));//12
  printf("%d\n",strlen(str5));//5 strlen碰到\0结束结算

  //6 下面是什么结果？
  char str6[]="hello\012world";
  printf("%s\n",str6);//hello world
  printf("%d\n",sizeof(str6));//12
  printf("%d\n",strlen(str6));//11
}
int main()
{
    test01();
}