#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void B()
{

}
void A()
{
  int a;//在A B中都可以使用，在main函数中不能使用
  B();
}
int main()
{
   int a;//在main函数，A B函数中都可以使用
   A();
}