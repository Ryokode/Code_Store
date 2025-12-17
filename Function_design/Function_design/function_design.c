#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <Windows.h>


//sub函数的功能为：将字符串s的逆序和正序连接形成一个新串放在t中。

void sub(char* s, char* t);//函数声明
double convert(double temp, char type);
int is_prime(int);  //素数判断函数
void addtion(int nums[], int n, int k, int start, int count, int sum, int* result);
int fun(int n);
void recursion();
void Squeeze(char s[], char c);

int main()
{
	int titile;

	printf("Please select title you need:\n1.sub逆序正序字符串连接\n2.摄氏度和华氏度的转换\n3.n个整数中任选k个相加，求计算出和为素数的有多少种\n4.1+2+...+n的和\n5.recursion\n6.删除字符串s中出现与变量c相同的字符\n");
	scanf("%d", &titile);
	
	if (titile == 1)
	{
		char s[100], t[100];

		printf("Please enter string s:");
		scanf("%s", s);

		sub(s, t);

		printf("The result is:%s\n", t);
	}
	if (titile == 2)
	{
		double temp;
		char type;

		printf("Enter temperature:");
		scanf("%lf", &temp);
		printf("Press C to convert to Celsius,F to convert to Fahrenheit:");
		scanf(" %c", &type);
		printf("Corresponding temperature:%.1f\n", convert(temp, type));
	}
	if (titile == 3)
	{
		int i,nums[20], n, k;

		printf("Please enter number of n and k:\n");
		scanf("%d %d", &n, &k);
		printf("Please enter numbers:");
		for (i = 0; i < n; i++)
		{
			scanf("%d", &nums[i]);
		}

		int result = 0;

		addtion(nums,n,k,0,0,0,&result);

		printf("The number of addtion situation:%d\n", result);
	}
	if (titile == 4)
	{
		int n,f = 0;

		printf("n = :");
		scanf("%d", &n);

		f = fun(n);

		printf("Sum = %d\n", f);
	}
	if (titile == 5)
	{
		recursion();
	}
	if (titile == 6)
	{
		char s[80], c;

		printf("Please enter a string: \n");
		for (int i = 0; i < 80; i++)
		{
			scanf("%s", &s[i]);
			if (getchar() == '\n')
				break;
		}

		printf("Please enter a word you want to delete: \n");
		scanf("%c",&c); 

		Squeeze(s, c);

		puts(s);
	}

	return 0;
}

void sub(char* s, char* t)
{
	int i, d = strlen(s);

	for (i = 0; i < d; i++)
	{
		t[i] = s[d - 1 - i];//逆序复制到t的前半部分
	}

	for (i = 0; i < d; i++)
	{
		t[d + i] = s[i];//正序复制到t的后半部分
	}

	t[2 * d] = '\0';//添加字符串结束符

}

double convert(double temp, char type)
{
	switch (type)
	{
	case 'f':
	case 'F':
		return temp * 9.0 / 5.0 + 32;
	case 'c':
	case 'C':
		return 5.0 / 9.0 * (temp - 32);
	default:
		printf("Invalid type!Returning 0.\n");
		return 0.0;
	}
}

int is_prime(int p)  //判断质数
{
	/*if (p <= 1)
		return 0;
	for (int i = 2; i <= sqrt(p); i++)
	{
		if (p % i == 0)
			return 0;
	}

	return 1;*/

	if (p <= 1)
		return 0;
	if (p == 2)
		return 1;
	if (p % 2 == 0)
		return 0;

	int limit = (int)sqrt(p) + 1;// +1确保边界安全

	for (int i = 3; i <= limit; i += 2)
	{
		if (p % i == 0)
			return 0;
	}

	return 1;
}

void addtion(int nums[],int n, int k,int start,int count,int sum,int *result)
{
	if (count == k)
	{
		if (is_prime(sum))
		{
			(*result)++;
		}
		return;
	}

	for (int i = start; i < n; i++)
	{
		addtion(nums, n, k, i + 1, count + 1, sum + nums[i], result);
	}
}

int fun(int n)
{
	static int v = 0;

	for (int i = 1; i <= n; i++)
	{
		v += i;
	}
	
	return v;
}

void recursion(void)
{
	char c = getchar();
	putchar(c);
	
	if (c != '*')
	{
		recursion();
	}

	putchar(c);
}

void Squeeze(char s[], char c)
{
	int i, j = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != c)
		{
			s[j] = s[i];
			j++;
		}
	}
	s[j] = '\0';
}
