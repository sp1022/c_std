#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//输入特性
void printAarray(int **p,int len)
{
   for(int i=0;i<len;i++)
   {
     printf("%d\n",*p[i]);
   }
}
void test01()
{
   int **p=malloc(sizeof(int *)*5);
   //在栈上开辟内存
   int a=100;
   int b=200;
   int c=300;
   //栈区数组p[i]维护 栈上(a b c)数据的地址，建立关系
   p[0]=&a;
   p[1]=&b;
   p[2]=&c;
   printAarray(p,3);
   if(p!=NULL){
    free(p);
    p=NULL;
   }
}


//输出特性
void test02()
{
  int *pArray[3];
  for(int i=0;i<3;i++)
  {
    pArray[i]=malloc(4);
    *pArray[i]=i+100;
  }
  int len=sizeof(pArray)/sizeof(int*);//这里sizeof(pArray)=pAarray[0]  +pAarray[1]+pAarray[2]=12
  printAarray(pArray,len);
  //堆区释放
  for(int i=0;i<3;i++)
  {
   if(pArray[i]!=NULL)
   {
    free(pArray[i]);//要释放pArray[i]
    pArray[i]=NULL;
   }
  }
}

void allocteMemory(int **ptr){
  *ptr=malloc(sizeof(int));
  **ptr=100;
}

int main()
{
  test01();   
  test02();

  int *p=NULL;
  allocteMemory(&p);
  if(p!=NULL)
  {
    printf("allocate memory:%d",*p);
    free(p);
  }
}