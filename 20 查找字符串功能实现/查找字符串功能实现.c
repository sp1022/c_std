#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int myStrInst(char * str,char * strSub)
{
  int num=0;
  while(*str!='\0')
  {
     if(*str!=*strSub)//如果不相同(按照字符循环)，则继续循环
     {
        str++;
        num++;
        continue;
     }
     //如果相同，则说明有可能和strsub匹配，则开始使用temp进行循环查找
     char * tempStr=str;
     char * tempStrSub=strSub;
     while(*tempStr!='\0')
     {
        if(*tempStr!=*tempStrSub)
        { 
            //匹配失败情况
            str++;
            num++;
            break;
        }
        //临时指针匹配相同情况
        tempStr++;
        tempStrSub++;
     }
     if(*tempStrSub=='\0')//如果strsub都找到了，且已经到了\0，说明找到了
     {
        return num;
     } 
  }
  return -1;
}

void test01()
{
  char * str="abcdefghljlkj";
  int ret =myStrInst(str,"def");
  if (ret!=-1)
  {
    printf("找到了，位置为:%d",ret);
  }
}

int main()
{
 test01();
}