#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

//函数声明
void sort(char* name[], int n);
void printline(int (*p)[4]);
char* dayname(int i);
int* seek(int (*prow)[3]);

int Max(int x, int y)
{
	int z;
	if (x > y)
	{
		z = x;
	}
	else
	{
		z = y;
	}
	return z;
}

int Min(int x, int y)
{
	int z;
	if (x < y)
	{
		z = x;
	}
	else
	{
		z = y;
	}
	return z;
}

int add(int x, int y)
{
	return x + y;
}

void process(int x, int y, int (*fun)(int, int))  //第三个参数为函数指针
{
	int result;
	result = (*fun)(x, y);
	printf("%d\n", result);
}

int main()
{
	int pointer;

	printf("1.函数指针\n\
2.使用指向指针的指针\n\
3.指针数组\n\
4.指针二维数组\n\
5.指针字符串数组\n\
6.行指针用作函数参数\n\
7.运用指针数组和指针函数，输入1~7之间的整数，输出对应的星期名\n\
8.找出至少一门成绩不合格者\n");
	scanf("%d", &pointer);

	if (pointer == 1)
	{
		int a, b;

		printf("enter a and b:\n");
		scanf("%d %d", &a, &b);

		printf("max = ");
		process(a, b, Max);

		printf("min = ");
		process(a, b, Min);

		printf("sum = ");
		process(a, b, add);
	}
	else if (pointer == 2)
	{
		int k = 23;
		int* p = &k;
		int** q = &p;

		printf("k = *p = **q = %d\n", **q);
		*p = 45;

		printf("k = *p = **q = %d\n", **q);
		**q = 67;

		printf("k = *p = **q = %d\n", k);
	}
	else if (pointer == 3)
	{
		int a[5] = { 11,13,15,17,19 };
		int* num[5] = { &a[0],&a[1],&a[2],&a[3],&a[4] };
		int** p, i;

		p = num;

		for (i = 0; i < 5; i++)
		{
			printf("%d\t", **p);
			p++;
		}
	}
	else if (pointer == 4)
	{
		int a[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
		int* pa[3] = { a[0],a[1],a[2] };  //a[i] <==>& * (a[i] + 0) <==> &a[i][0]
		int* p = a[0];  //相当于int *p;p = &a[0][0];
		int** q = pa;  //相当于int **q;q = &pa[0];
		int i;

		for (i = 0; i < 3; i++)
		{
			printf("%d,%d,%d\n", *pa[i], p[i], **(q + i));
		}
	}
	else if (pointer == 5)
	{
		char* name[] = { "CHINA","AMERICA","AUSTRALIA","FRANCE","GERMAN" };
		int i;

		sort(name, 5);

		for (i = 0; i < 5; i++)
		{
			printf("%s\n", name[i]);
		}
	}
	else if (pointer == 6)
	{
		int a[3][4] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
		int i;

		for (i = 0; i < 3; i++)
		{
			printline(a + i);
			printf("\n");
		}
	}
	else if (pointer == 7)
	{
		int n;
		char* q;

		printf("Input Day No.:");
		scanf("%d", &n);

		if (n < 0)
		{
			exit(1);
		}

		q = dayname(n);

		printf("Day No.:%2d-->%s\n", n, q);
	}
	else if (pointer == 8)
	{
		int grade[4][3] = { {65,68,88},{55,65,75},{75,78,93},{35,72,49} };
		int i, j, * q;  //定义一个（列）指针变量q

		for (i = 0; i < 4; i++)
		{
			q = seek(grade + i);  //用行指针作实参，调用seek函数
			if (q == *(grade + i))  //该学生至少有一门课成绩不合格
			{  //输出该学生的序号和各项成绩
				printf("No.%d grade list:", i + 1);

				for (j = 0; j < 3; j++)
				{
					printf("%4d", *(q + j));
				}
				printf("\n");
			}
		}
	}

	return 0;
}

void sort(char* name[], int n)  //排序
{
	char* pt;
	int i, j, k;

	for (i = 0; i < n - 1; i++)
	{
		k = i;

		for (j = i + 1; j < n; j++)
		{
			if (strcmp(name[k], name[j]) > 0)
			{
				k = j;
			}
			
		}

		if (k != i)
		{
			pt = name[i];
			name[i] = name[k];
			name[k] = pt;
		}
	}
}

void printline(int (*p)[4])
{
	int j;
	int* q;
	q = *p;  //二级指针p之前加*就变成一级指针

	for (j = 0; j < 4; j++)
		printf("%4d", *(q + j));

}

char* dayname(int i)
{
	char* name[8] = { "Illegal day","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };
	return ((i < 1 || i > 7) ? name[0] : name[i]);
}

int* seek(int (*prow)[3])
{
	int i = 0, * pcol;  //定义一个（列）指针变量pcol
	pcol = *(prow + 1);  //使pcol指向下一行之首（作标志作用）

	for (; i < 3; i++)
	{
		if (*(*prow + i) < 60)  //某门课成绩不合格
		{
			pcol = *prow;  //是pcol指向本行之首
			break;  //退出循环
		}
	}
	return (pcol);
}