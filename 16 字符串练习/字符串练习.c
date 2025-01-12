
#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//字符串拷贝
void copyString01(char * dest,char * source)
{
    int length=strlen(source);
    for(int i=0;i<length;i++)
    {
        dest[i]=source[i];
    }
    dest[length]='\0';
}
void copyString02(char * dest,char * source)
{
   while(*source!='\0')
   {
      *dest=*source;
      dest++;
      source++;
   }
   *dest='\0';
}

void copyString03(char * dest,char * source)
{
   while(*dest++ = *source++)
   {
   }
}
void test01()
{
    char *str="hello world";
    char buf[1024];
    //copyString01(buf,str);
    //copyString02(buf,str);
    copyString03(buf,str);
    printf("%s\n",buf);
}


//字符串翻转
void reverseStr01(char *p)
{
  int start=0;
  int end=strlen(p)-1;
  char temp;
  while(start<end)
  {
    temp=p[start];
    p[start]=p[end];
    p[end]=temp;
    start++;
    end--;
  }
}

void reverseStr02(char *p)
{
    int len=strlen(p);
    char * start=p;
    char * end=p+len-1;
    while(start<end)
    {
        char temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
}

void test02()
{
  char str[]="abcdef";
  //reverseStr01(str);
  reverseStr02(str);
  printf("%s\n",str);
}

int main()
{
    //test01();
    test02();
}