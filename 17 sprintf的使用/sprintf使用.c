#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void test01()
{
    char buf[1024];
    memset(buf,0,1024);
    sprintf(buf,"今年是%d-%d-%d",2022,12,25);
    printf("%s\n",buf);

    //2 拼接字符串
    memset(buf,0,1024);
    char str1[]="hello";
    char str2[]="world";
    int len=sprintf(buf,"%s %s",str1,str2);
    printf("%s 长度%d\n",buf,len);

    //3 转换
    int a=10000;
    memset(buf,0,1024);
    sprintf(buf,"%d",a);
    printf("%s",buf);//int打印成字符串%s
}
int main()
{
 test01();
}