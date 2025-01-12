#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int getFileLines(FILE * file)
{
   if(file==NULL)
   {
    return -1;
   }
   char buf[1024];
   int lines=0;
   while (fgets(buf,1024,file)!=NULL) //读取文件内容到buf,每次读取1024
   {
     lines++; 
   }

   //将文件的光标 置首。如果这里不设置，会导致readFileData函数读取数据时，光标位置不对，导致程序报错
   fseek(file,0,SEEK_SET);//将文件file，从某个位置，偏移N个（这里为0，也就是置首）
   //SEEK_SET  置首
   //SEEK_CUR  当前光标
   //SEEK_END  置尾

   return lines;
}

 void readFileData(FILE * file,char ** pArray ,int len)
 {
    if(file == NULL)
    {
        return;
    }
    if(pArray == NULL)
    {
        return;
    }
    if(len<=0)
    {
        return;
    }
    char buf[1024]={0};
    int index=0;
    while (fgets(buf,1024,file)!=NULL) 
    {
         //计算开辟每个字符串的大小
         int currentLen=strlen(buf)+1;//+1为开辟\0的空间
         //将字符串最后的字符回车修改为\0,因为会多打印一个回车。（可以注释掉后查看情况）
         buf[strlen(buf)-1]='\0';
        //开辟空间
        char *currentP=malloc(sizeof(char)*currentLen);
        //将文件中的内容放入到currentp中
        strcpy(currentP,buf);
        //将开辟空间的数据放入数组中
        pArray[index++]=currentP;
        //清空buff，再次使用
        memset(buf,0,1024);
    }
 }

 void showFileData(char **pArray ,int len)
 {
   for(int i=0;i<len;i++)
   {
    printf("第%d行数据为:%s\n",i+1,pArray[i]);
   }
 }


void freeSpace(char **pArray,int len)
{
    for(int i=0;i<len;i++)
    {
        if(pArray[i]!=NULL)
        {
            free(pArray[i]);//释放小的  注意：程序中有几个malloc，就要有几个free.
            pArray[i]=NULL;
        }
    }
    free(pArray); //释放大的
    pArray=NULL;
}

void test01()
{
   //打开文件
   FILE * file=fopen("./test.txt","r");
   if(file == NULL)
   {
     printf("打开文件失败!\n");
     return;
   }
   //获取文件有效行数
   int len=getFileLines(file);
   printf("文件有效行数为:%d\n",len);
   //开始分配空间
   char ** pArray=malloc(sizeof(char *) * len);//开辟len个数组
   //将输入放入
   readFileData(file,pArray,len);

   //打印数组
   showFileData(pArray,len);
   
   //释放堆内存
   freeSpace(pArray,len);

   //关闭文件
   fclose(file);
   file =NULL;
}

int main()
{
    test01();
}