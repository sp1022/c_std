/*
1自动变量是存储在动态存储区(栈区)，在函数调用时赋值，相当于执行一次赋值一次，函数执行完成后自动销毁
2 静态局部变量是存储在静态存储区，是在程序编译的时候赋值，在整个程序运行期间不释放
3 如果一个变量被调用了几万次，甚至上亿次，由于变量是存储在内存当中，会导致频繁的CPU通过总线访问内存，消耗很大.这是就需要register变量，将变量放在CPU的寄存器中，减少消耗。如果寄存器满了，则变为AUTO变量
4 外部变量即全局变量(用extern声明)，他的作用域从变量的开始定义处到本程序的结束,在此作用域内，全局变量可以为程序各个函数引用。编译时外部变量分配在静态存储区(和静态变量一样)
5 如果定义的外部变量，不希望被外部文件调用，则使用static定义个静态变量
6 函数也可以使用extern定义，如果定义为extern（默认可以省略），则可以被外部文件调用,如果不希望被外部文件调用，则定义为static函数
*/ 


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fac(int n)
{    //静态局部变量是存储在静态存储区，是在程序编译的时候赋值，在整个程序运行期间不释放
     //自动变量是存储在栈区，在函数调用时赋值，相当于执行一次赋值一次，函数执行完成后自动销毁
	static int f = 1;//
	f *= n;
	return f;
}
int fac1(int a)
{
	auto int b = 0; //1自动变量是存储在动态存储区(栈区)，在函数调用时赋值，相当于执行一次赋值一次，函数执行完成后自动销毁
	static int c = 3;//2 静态局部变量是存储在静态存储区，是在程序编译的时候赋值，在整个程序运行期间不释放
	//一般情况下，变量的值都是存放在内存当中(包含静态存储方式和动态存储方式)
	b += 1;//第一次调用为b=1,第二次仍然为1
	c += 1;//第一次调用为4，第二次为5,第三次为6
	return a+b+c;
}
 
//3 如果一个变量被调用了几万次，甚至上亿次，由于变量是存储在内存当中，会导致频繁的CPU通过总线访问内存，消耗很大
//这是就需要register变量，将变量放在CPU的寄存器中，减少消耗。如果寄存器满了，则变为AUTO变量
int fac2(int n)
{
	register int i, f = 1;//调用register和没有使用register，可以试试看速度怎么样？
	for (i = 1; i <= n; i++)
	{
		f *= i;
	}
	return f;
}
int max(int x, int y)
{
	int max;
	max = x > y ? x : y;
	return max;
}
//4 外部变量即全局变量(用extern声明)，他的作用域从变量的开始定义处到本程序的结束
//在此作用域内，全局变量可以为程序各个函数引用。编译时外部变量分配在静态存储区(和静态变量一样)
int extern_A = 666;//定义一个全局变量,用于其他文件的调用
//5 如果定义的外部变量，不希望被外部文件调用，则使用static定义个静态变量
int extern_static_A = 888;//如果外部文件调用会报错
//6 函数也可以使用extern定义，如果定义为extern（默认可以省略），则可以被外部文件调用
//如果不希望被外部文件调用，则定义为static函数
typedef u_int8_t uint8;
typedef u_int16_t uint16;
typedef u_int32_t uint32;
typedef u_int64_t uint64;
typedef struct XLogPageHeaderData
{
	uint16		xlp_magic;		/*2 magic value for correctness checks */
	uint16		xlp_info;		/*2 flag bits, see below */
	uint32	xlp_tli;		/*4  TimeLineID of first record on page */
	uint64	xlp_pageaddr;	/*8 XLOG address of this page */

	/*
	 * When there is not enough space on current page for whole record, we
	 * continue on the next page.  xlp_rem_len is the number of bytes
	 * remaining from a previous page; it tracks xl_tot_len in the initial
	 * header.  Note that the continuation data isn't necessarily aligned.
	 */
	uint32		xlp_rem_len;	/*4 total len of remaining data for record */
} XLogPageHeaderData;

typedef struct XLogLongPageHeaderData
{
	XLogPageHeaderData std;		/* standard header fields */
	uint64		xlp_sysid;		/* 8 system identifier from pg_control */
	uint32		xlp_seg_size;	/* 4 just as a cross-check */
	uint32		xlp_xlog_blcksz;	/*4  just as a cross-check */
} XLogLongPageHeaderData;

typedef struct XLogRecord
{
	uint32		xl_tot_len;		/* 4 total len of entire record */
	uint32      xl_xid;		/* 4 xact id */
	uint64	xl_prev;		/* 8 ptr to previous record in log */
	uint8		xl_info;		/* 1 flag bits, see below */
	uint16		xl_rmid;		/* 2 resource manager for this record */
	/* 2 bytes of padding here, initialize to zero */
	uint32	xl_crc;			/* 4 CRC for this record */

	/* XLogRecordBlockHeaders and XLogRecordDataHeader follow, no padding */

} XLogRecord;
void main()
{
	printf("XLogPageHeaderData长度:%lu\n", sizeof(XLogPageHeaderData));
    printf("XLogLongPageHeaderData长度:%lu\n", sizeof(XLogLongPageHeaderData));
	printf("XLogRecord长度:%lu\n", sizeof(XLogRecord));

	printf("------------------------------------------\n");
	int i,a=2,j;
	//j=extern_print();
	printf("------------------------------------------\n");
	for (i = 1; i <= 3; i++)
	{
		printf("%d\n", fac(a));
 
	}
	printf("------------------------------------------\n");
		for (i = 1; i <= 5; i++)
	{
		printf("%d的阶乘=%d\n", i, fac(i));
	}
   printf("------------------------------------------\n");
}
int x = 10, y = 8;