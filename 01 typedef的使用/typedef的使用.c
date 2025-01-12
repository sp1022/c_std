#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//1 typedef使用:简化结构使用
typedef  struct person
{
    /* data */
   char name[64];
   int age;
}MyPerson;

void test01()
{
    MyPerson p1={"shipeng",36};
    printf("name=%s,age=%d",p1.name,p1.age);
}
// 2 区分数据类型
void test02()
{
  //char* p1,p2;//p1 p2都是char *吗？明显是不对的
  typedef char* CHAR;
  CHAR p1,p2;
}
//3 提高移值性
typedef int MY_INT;
void test03()
{
    MY_INT a,b;
}
int main()
{
    test01();
    system("pause");//按任意键，暂停
    return EXIT_SUCCESS;
}