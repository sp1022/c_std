#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//按位取反 ~
void test01()
{
  int num=2;
  printf("~num:%d\n",~num);//-3
  //0 10 ~
  //1 01 原码
  //计算机存的是补马
  //1 01 +1=111
}

//按位与 &(同为真则真)：经常用来判断奇数偶数
/*
  01011000
  10001000
 &
 ---------
  00001000 
*/
void test02()
{
  int num=21;
  if((num & 1)==0)
  {
    printf("偶数\n");
  }
  else
  {
    printf("奇数\n");
  }

}

//按位或 |(一个为真则真，否则为假):常用来置位操作
/*
  00000000
  00100000
|
----------------
  00100000(置位，某些位有特殊的含义)
*/
void test03()
{
  int num1=5;
  int num2=3;
  printf("num1 | num2=%d\n",num1 | num2);
}

//按位异或(同为真则假，同为假则假，一个为真则为真)：可以用来赋值交换
/*
 A=10010011
 B=00111101
^
-------------
 R=10101110
异或的特点：
 A^B=R
 A^R=B
 B^R=A
*/
void test04()
{
  int num1=5;
  int num2=3;
  num1=num1 ^ num2;
  num2=num1 ^ num2;
  num1=num1 ^ num2;
  printf("num1=%d\n",num1);
  printf("num2=%d\n",num2);
}


//左移<<：相当于乘以2的N次方
void test05()
{
  int num1=5;
  printf("num1=<<2:%d\n",num1<<=2);//左移两位,相当于5*2的2次方
}

//右移>>：相当于除以2的N次方
void test06()
{
  int num1=20;
  printf("num1=>>2:%d\n",num1>>=2);//左移两位,相当于20/2的2次方
}

int main()
{
  //test01();
  //test02();
  //test03();
  //test04();
  //test05();
  test06();
}