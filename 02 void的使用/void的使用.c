#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//01 限制函数的返回值
//02 void* 万能指针
void test03()
{
    void * p=NULL; //指针占用字节数:8个字节？
    printf("void*占用字节:%d",sizeof(p));
    int * pInt = NULL;
    char * pChar = NULL;
    pChar = (char *)pInt;//不同类型指针之间，需要强制类型转换才不会报警告
    pChar = p;//完成指针不通过强制类型转换，就可以转换为任何类型指针
}
int main()
{
    test03();
}