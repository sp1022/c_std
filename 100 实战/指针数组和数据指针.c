#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ROWS 3
#define COLS 4
/*
指针数组:可以用于管理大量独立的对象或内存块，比如 Redis 中对内存对象的引用、B+ 树节点的管理、数据库表的行缓存等。
数组指针 type (*varname)[num]:则适用于处理多维数据结构，如二维数组（表示数据表的行列）、数据库查询结果缓存、多维矩阵的存储与处理等。
*/
void func()
{
    /*==========================================数组指针使用案例1===============================*/
    int arr[4]={0,1,2,3};
    //定义数组指针。语法：数据类型(*指针变量名称)[元素个数]
    int (*p)[4]=&arr;
    for(int i=0;i<4;i++)
    {
    printf("%d\n",(*p)[i]);//*p的解引用就是arr
    }

   /*==========================================数组指针使用案例2===============================*/
  //定义一个 3x4 的二维数组
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    // 定义一个数组指针，指向二维数组的首地址
    int (*ptr)[COLS] = matrix;

    // 通过数组指针访问二维数组
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }

}

void func2()
{
 //定义一个指针数组
  char *str[4]={};
  char *a="aaa",*b="bbb",*c="ccc",*d="ddd";
   str[0]=a;
   str[1]=b;
   str[2]=c;
   str[3]=d;
  for(int i=0;i<4;i++)
  {
    printf(".......%s.......%p\n",str[i],str[i]);
  }
}

int main(){
    func2();
}