#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "config.h"
/**************************静态变量***************
1 程序远行前分配内存
2 生命周期在程序运行结束死亡
3 默认属于内部链接属性(除非引用头文件)，在当前文件中使用
*************************************************/
static int a=10; //全局作用域

/*全局变量
1 在默认c语言环境下，全局变量前加了关键字extern
2 属于外部连接属性 
*/
void test01()
{
   
  static int b=20;//局部作用域
  b++;
  printf("b=%d",b);
}

int main()
{
  extern g_b;//告诉编译器，其他文件中有一个g_b,链接时候在其他文件中寻找
  g_b=10000;
  printf("extern g_b=%d\n",g_b);
  //使用extern
  printf("extern config debug_lelve=%d\n",debug_level);
  printf("extern config server_name=%s\n",server_name);
  test01();
  test01();
}