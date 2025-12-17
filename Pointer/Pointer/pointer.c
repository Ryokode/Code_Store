#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

void swap(int* p1, int* p2);
char* submax(char* s);
int* test(int b[]);
int maxx(int a, int b);

//6.假设整型数组a在main函数中定义，试编写test函数，在其中定义整型数组c。比较整型数组a和c的对应元素值。
// 如果对应元素值相等，则将该元素值赋值给静态数组d的相应单元，最后test函数的返回值带回静态数组d的起始地址，在main函数中将数组d中的所有数据以两种方式全部输出。

int main()
{
	int part;

	printf("1.指针示例\n\
2.指针与数组（下标法）\n\
3.在输入的字符串中查找有无k字符\n\
4.输入两个整数，按从大到小顺序输出这两个数\n\
5.编写一个submax函数，从输入字符串中ASCII码值最大的那个字符开始，将其之后的字符全部输出\n\
6.test指针函数\n\
7.用指针形式实现对函数调用的方法\n");
	scanf("%d", &part);

	if (part == 1)
	{
		int a, b;
		int* pointer1, * pointer2;

		a = 100, b = 10;

		pointer1 = &a;
		pointer2 = &b;

		printf("%d,%d\n", a, b);
		printf("%d,%d\n", *pointer1, *pointer2);
	}
	if (part == 2)
	{
		int arr[10], i;

		for (i = 0; i < 10; i++)
		{
			/*arr[i] = i;*/

			*(arr + i) = i;
		}
		for (i = 0; i < 10; i++)
		{
			if (i % 5 == 0)
				printf("\n");

			printf("\tarr[%d] = %d", i, /*arr[i]*/*(arr + i));
		}
	}
	if (part == 3)
	{
		char st[20], * ps;
		int i;
		ps = st;  //st首地址赋给ps

		printf("Input a string:\n");
		scanf("%s,",ps);

		for (i = 0; ps[i] != '\0'; i++)
		{
			if (ps[i] == 'k')
			{
				printf("There is a 'k' in the string\n");
				break;
			}
		}

		if (ps[i] == '\0')
			printf("There is no 'k' in tne string\n");
	}
	if (part == 4)
	{
		int a, b;
		int* pointer1, * pointer2;

		pointer1 = &a;
		pointer2 = &b;

		scanf("%d,%d", pointer1,pointer2);

		if (a < b)
		{
			swap(pointer1, pointer2);
		}

		printf("%d,%d", a, b);
	}
	if (part == 5)
	{
		char str[20];
		int i;

		printf("输入字符串：\n");
		
		for (i = 0; i < 20; i++)
		{
			scanf("%s", &str[i]);

			if (getchar() == '\n')
				break;
		}

		printf("输出字符串：%s\n", submax(str));
	}
	if (part == 6)
	{
		int a[5] = { 1,7,3,9,5 };
		int* p;

		p = test(a);

		printf("%d,%d,%d,%d,%d\n", *p, *(p + 1), *(p + 2), *(p + 3), *(p + 4));
		printf("%d,%d,%d,%d,%d\n", p[0], p[1], p[2], p[3], p[4]);
	}
	if (part == 7)
	{
		int(* pmax) (int, int);
		int x, y, z;

		pmax = maxx;

		printf("Input two numbers:\n");
		scanf("%d,%d", &x, &y);

		z = (* pmax) (x, y);

		printf("maxnum == %d", z);
	}

	return 0;
}

void swap(int* p1, int* p2)
{
	int temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}

char* submax(char* s)
{
	char* p;
	p = s + 1;

	while (*p)
	{
		if (*p > *s)
			s = p;
		
		p++;
	}

	return (s);
}

int* test(int b[])
{
	int c[5] = { 1,2,3,4,5 }, i;
	static int d[5];

	for (i = 0; i < 5; i++)
	{
		if (*(b + i) == c[i])
			d[i] = c[i];
	}

	return d;
}

int maxx(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}