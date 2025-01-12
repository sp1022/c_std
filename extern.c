#include <stdio.h>
extern extern_A;
int extern_print()
{
	printf("这里的extern_A是显示的提示extern_A来自main中:%d\n", extern_A);
	return 0;
}