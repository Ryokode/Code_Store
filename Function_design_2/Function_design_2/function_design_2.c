#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define SQRSUM(a,b) (a)*(a) + (b)*(b)
#define SQRDIF(a,b) (a)*(a) - (b)*(b)
#define END -1
#define N 100

long long fun(int n);
long long Factorial(int x);
void reverse(char rstr[]);
void change(int arr[], int n);

int main()
{
	int pattern;

	printf("1.输入自然数n，用递归函数求1^3+2^3+3^3+...+n^3的值\n2.计算平方和或平方差\n3.输入任意整数计算其阶乘\n4./输入一个字符串，将该字符串逆序存储并输出\n5.数组元素左移一个位置，将第一个存到末尾\n");
	scanf("%d", &pattern);

	if (pattern == 1)
	{
		int i = 0;
		
		printf("Enter a positive integer:\n");
		scanf("%d", &i);

		if (i <= 0)
			printf("Inuput error!");
		else
		{
			printf("Sum = %lld\n", fun(i));
		}
	}
	if (pattern == 2)
	{
		int i,choice_and_nums[3];

		printf("1.平方和\t2.平方差\n并且输入两个正整数：");
		for (i = 0; i < 3; i++)
		{
			scanf("%d", &choice_and_nums[i]);
		}

		if (choice_and_nums[0] == 1)
		{
			printf("sqrsum = %d\n", SQRSUM(choice_and_nums[1], choice_and_nums[2]));
		}
		else if (choice_and_nums[0] == 2)
		{
			printf("sqrdif = %d\n", SQRDIF(choice_and_nums[1], choice_and_nums[2]));
		}
	}
	if (pattern == 3)
	{
		int x;

		while (1)
		{
			printf("Enter x:");
			scanf("%d", &x);

			if (x <= END)
				break;
			else
				printf("%d! = %lld\n", x, Factorial(x));
		}
	}
	if (pattern == 4)
	{
		char str[N];

		printf("Enter a string:\n");
		gets(str);
		reverse(str);

		printf("The reverse string is:");
		puts(str);
	}
	if (pattern == 5)
	{
		int a[10], i;

		for (i = 0; i < 10; i++)
		{
			scanf("%d", &a[i]);
		}
		change(a, 10);

		for (i = 0; i < 10; i++)
		{
			printf("%d", a[i]);
		}
	}


	return 0;
}

long long fun(int n)
{
	long long k;

	if (n == 1)
		k = 1;
	else
	{
		k = fun(n - 1) + n * n * n;
	}

	return k;
}

long long Factorial(int x)
{
	int i, result = 1;

	for (i = 1; i <= x; i++)
	{
		result *= i;
	}

	return result;
}

void reverse(char rstr[])
{
	char temp[N] = { '\0' };
	int len = strlen(rstr);

	for (int i = 0; i < len; ++i)
	{
		temp[i] = rstr[len - 1 - i];
	}

	strcpy(rstr, temp);
}

void change(int arr[], int n)
{
	int i, temp = arr[0];

	for (i = 0; i < n - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	arr[n - 1] = temp;
}