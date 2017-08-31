/*
交换两个变量的值，并且不开辟额外的内存
*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a, b;
	printf("分别为a和b赋值\n");
	scanf("%d%d", &a, &b);
	a = a + b;
	b = a - b;
	a = a - b;
	printf("交换之后a, b为: %d %d\n", a, b);
	return 0;
}