#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//%*s %*d跳过数据
void test01()
{
  char * str="12345abcde";
  char buf[1024]={0};//将结果放入buf
  sscanf(str,"%*d%s",buf);
  printf("%s\n",buf);//abcde
}

void test02()
{
  char * str="abcde12345";
  char buf[1024]={0}; 
  //sscanf(str,"%*s%s",buf);
  //printf("%s\n",buf);//空？为什么？因为对于str来说，12345也是字符串。所以%*s都给忽略掉了。正确方式在下面：

  sscanf(str,"%*[a-z]%s",buf);//*[a-z]忽略掉,剩下的保留
  printf("%s\n",buf);
}

//%[width]s 读指定宽度的数据
void test03()
{
  char * str="abcde12345";
  char buf[1024]={0}; 
  sscanf(str,"%5s",buf);
  printf("%s\n",buf);
}
//%[a-z] 匹配a-z任意字符,前提是：碰到第一个不为a-z的字符截止
void test04()
{
  char * str="abcd1235";
  char buf[1024]={0}; 
  sscanf(str,"%[a-z]+",buf);
  printf("%s\n",buf);
}

//%[aBc]  匹配a B c中一员，贪婪匹配
void test05()
{
 //如果遇到匹配失败，后续不进行匹配
  char * str="aabbcaadaa1235";
  char buf[1024]={0}; 
  sscanf(str,"%[abc]",buf);
  printf("%s\n",buf);
}

//%[^a]  匹配非a的任意字符，贪婪匹配
void test06()
{
  char * str="aabbcaadaa1235";
  char buf[1024]={0}; 
  sscanf(str,"%[^1]",buf);
  printf("%s\n",buf);//aabbcaadaa
}

//%[^a-z]  表示读取非a-z以外的字符
void test07()
{
  char * str="12a35aabbcaadaa";
  char buf[1024]={0}; 
  sscanf(str,"%[^abc]",buf);
  printf("%s\n",buf);//
}

//练习1
void test08()
{
  char * str="127.0.0.1";
  int num1,num2,num3,num4;
  sscanf(str,"%d.%d.%d.%d",&num1,&num2,&num3,&num4);//把四个地址分别放入
  printf("%d\n",num1);
  printf("%d\n",num2);
  printf("%d\n",num3);
  printf("%d\n",num4);
}


//练习2
void test09()
{
  char * str="abcde#shipeng@12345";//将shipeng取出
  char buf[1024]={0};
  sscanf(str,"%*[^#]#%[^@]",buf);//思路：%*[^#]表示：去掉非#的所有字符，%*#：表示去掉#。%[^@]：匹配非@以外的所有元素。
  printf("%s\n",buf);
}


//练习3
void test10()
{
  char * str="abcde#shipeng@12345";//将shipeng取出
  char buf[1024]={0};
  sscanf(str,"%*[^#]#%[^@]",buf);//思路：%*[^#]表示：去掉非#的所有字符，%*#：表示去掉#。%[^@]：匹配非@以外的所有元素。
  printf("%s\n",buf);
}

//练习4
void test11()
{
  char * str="hello@itcast.cn";
  char buf[1024]={0};
  char buf2[1024]={0};
  //sscanf(str,"%*[^@]@%s",buf);
  sscanf(str,"%[a-z]%*[@]%s",buf,buf2);
  printf("%s  %s\n",buf,buf2);
}


int main()
{
 //test01();
 //test02();
 //test03();
 //test04();
 //test05();
 //test06();
 //test07();
 //test08();
 //test09();
 test11();
}