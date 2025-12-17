#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


//编写一个判断质数的函数，在主函数输入一个整数，输出是否为质数
//比较字符串大小，将两个字符串中第一个不相同字符的ASCII码值之差作为返回值
//交换数组中的最大值最小值位置
//3x3矩阵转置
//字符冒泡排序
//带参宏求三角形周长和面积
//输出指定行、列、字符的空心矩形

#define MAX_LEN 100
#define PERIMETER(a,b,c) ((a) + (b) + (c))  //有参宏定义

//函数声明
int is_prime(int);  //素数判断函数
int myStrcmp(char *str1, char *str2);  //字符串对比函数
void swapMinMax(int arr[], int n);  //大小交换函数
void transpose(int matrix[3][3]);  //转换函数
void bubbleSort(char chars[], int n);  //冒泡排序函数
void printHollowRectangle(int rows, int cols, char ch);  //矩形函数
double calculate_area(double a, double b, double c);  // 面积计算函数

int main()
{
	int mode;
	printf("Please choose a mode your want.\n1.判断质数\n2.比较字符串大小\n3.交换数组中的最大值最小值位置\n4.3x3矩阵转置\n5.字符冒泡排序\n6.带参宏求三角形周长和面积\n7.输出指定行、列、字符的空心矩形\n");
	scanf("%d", &mode);

	if (mode == 1)
	{
		int n;

		printf("Please enter a positive integer: ");
		scanf("%d", &n);

		if (is_prime(n))
		{
			printf("\n%d is a prime number.\n", n);
		}
		else
		{
			printf("\n%d isn't a prime number.\n", n);
		}

	}
	else if (mode == 2)
	{
		char s1[MAX_LEN] = { 0 }, s2[MAX_LEN] = { 0 };

		printf("Please enter first string: ");
		scanf("%99s", s1);  // %99s限制最大读取长度
		printf("Please enter second string: ");
		scanf("%99s", s2);

		int cut = myStrcmp(s1, s2);

		printf("ASCII码值之差为：%d\n", cut);
	}
	else if (mode == 3)
	{
		int m;

		printf("Enter array size: ");
		scanf("%d", &m);

		int* arr = malloc(m * sizeof(int));

		if (!arr)
		{
			printf("Memory allocation failed!\n");

			return 1;
		}

		printf("Enter %d integers: ", m);

		for (int i = 0; i < m; i++)
		{
			scanf("%d", &arr[i]);
		}

		swapMinMax(arr, m);

		printf("After swap: ");

		for (int i = 0; i < m; i++)
		{
			printf("%d ", arr[i]);
		}

		printf("\n");

		free(arr); // 释放内存
	}
	else if (mode == 4)
	{
		int matrix[3][3];

		printf("Enter 3x3 matrix (9 integers, row by row):\n");

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				scanf("%d", &matrix[i][j]);
			}
		}

		transpose(matrix);

		printf("\nTransposed matrix:\n");

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				printf("%d ", matrix[i][j]);
			}
			printf("\n");
		}
	}
	else if (mode == 5)
	{
		char chars[MAX_LEN];
		int n;

		printf("Enter number of characters: ");
		scanf("%d", &n);

		getchar(); // 清除输入缓冲区中的换行符

		if (n > MAX_LEN - 1)
		{
			printf("Too many characters! Maximum is %d\n", MAX_LEN - 1);

			return 1;
		}

		printf("Enter %d characters (without spaces): ", n);

		for (int i = 0; i < n; i++)
		{
			chars[i] = getchar();
		}

		chars[n] = '\0'; // 添加字符串结束符

		bubbleSort(chars, n);

		printf("Sorted characters: %s\n", chars);
	}
	else if (mode == 6) // 三角形周长和面积
	{
		double a, b, c;

		printf("Enter three sides of triangle: ");
		scanf("%lf %lf %lf", &a, &b, &c);

		if (a <= 0 || b <= 0 || c <= 0)
		{
			printf("Error: Sides must be positive numbers.\n");

			return 1;
		}
		if (a + b <= c || a + c <= b || b + c <= a)
		{
			printf("Error: Not a valid triangle.\n");

			return 1;
		}

		double perimeter = PERIMETER(a, b, c);
		double area = calculate_area(a, b, c);  // 使用函数计算面积

		printf("Perimeter: %.2f\n", perimeter);
		printf("Area: %.2f\n", area);
	}
	else if (mode == 7) // 空心矩形
	{
		int rows, cols;
		char ch;

		printf("Enter rows and columns: ");
		scanf("%d %d", &rows, &cols);

		getchar();

		printf("Enter character: ");
		
		ch = getchar();

		if (rows <= 0 || cols <= 0)
		{
			printf("Error: Rows and columns must be positive integers.\n");

			return 1;
		}

		printHollowRectangle(rows, cols, ch);
	}
	else
	{
		printf("Invalid mode selection!\n");
	}

	return 0;
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

int myStrcmp(char* str1, char* str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

void swapMinMax(int arr[], int n)
{
	if (n <= 0) return; // 安全检查

	int minIndex = 0, maxIndex = 0;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] < arr[minIndex])
		{
			minIndex = i;
		}
		if (arr[i] > arr[maxIndex])
		{
			maxIndex = i;
		}
	}

	// 避免自我交换
	if (minIndex != maxIndex)
	{
		int temp = arr[minIndex];
		arr[minIndex] = arr[maxIndex];
		arr[maxIndex] = temp;
	}
}

void transpose(int matrix[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)  //从j + 1开始，避免交换两次
		{
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}
}

void bubbleSort(char chars[], int n)
{

	if (n <= 1) return; // 安全检查

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (chars[j] > chars[j + 1])
			{
				char temp = chars[j];
				chars[j] = chars[j + 1];
				chars[j + 1] = temp;
			}
		}
	}
}

// 新增面积计算函数
double calculate_area(double a, double b, double c)
{
	double s = (a + b + c) / 2.0;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}

// 修正后的空心矩形函数
void printHollowRectangle(int rows, int cols, char ch)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1)
			{
				printf("%c", ch);
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");  // 关键修复：添加换行符
	}
}
