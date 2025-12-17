#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

//int main()
//{
//	char s[] = "2473", c, i;
//
//	for (i = 0; c = s[i]; i++)
//	{
//		switch (c - '0')
//		{
//		case 2:
//		case 3:putchar(c + 4); continue;
//		case 4:putchar(c + 4); break;
//		case 5:putchar(c + 3);
//		default:putchar(c + 2);
//		}
//	}
//
//
//	return 0;
//}

//int main()
//{
//	char a[2][80],t;
//	int i, j, m, n, k, max;
//
//	for (i = 0; i < 2; i++)
//	{
//		gets(a[i]);
//	}
//
//	t = a[0][0];
//
//	for (i = 0; i < 2; i++)
//	{
//		k = strlen(a[i]);
//		for (j = 0; j <= k; j++)
//		{
//			if (a[i][j] > t)
//			{
//				max = a[i][j];
//				m = i;
//				n = j;
//			}
//		}
//	}
//
//	printf("%c%d%d\n", max, m, n);
//
//	return 0;
//
//}

//输入3行3列的实数矩阵，求其中的最大数和最小数，并且对调这两个数后，再输出

//int main()
//{
//	float f[3][3], max, min;
//	int i, j, max_i, max_j, min_i, min_j;
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			scanf("%f", &f[i][j]);
//			max_i = max_j = min_i = min_j = 0;
//			max = min = f[0][0];
//		}
//	}
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			if (max < f[i][j])
//			{
//				max = f[i][j];
//				max_i = i;
//				max_j = j;
//			}
//			if (min > f[i][j])
//			{
//				min = f[i][j];
//				min_i = i;
//				min_j = j;
//			}
//		}
//	}
//
//	f[max_i][max_j] = min;
//	f[min_i][min_j] = max;
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("\n");
//		for (j = 0; j < 3; j++)
//		{
//			printf("%8.2f", f[i][j]);
//		}
//	}
//
//
//	return 0;
//}

//求出所给字符数组ss中最长字符串的长度，其余字符串左边用字符*补齐，使其与最长的字符串等长。字符数组中共有M个字符串，且串长小于N

//#define M 5
//#define N 20
//
//int main()
//{
//	char ss[M][N] = { "shanghaimingzhu","guangzhou","beijing","tianjing","chongqing" };
//	int i, j, k = 0, n, m, len;
//
//	printf("\nThe original strings are:\n");
//
//	for (i = 0; i < M; i++)
//	{
//		printf("%s\n", ss[i]);
//	}
//
//	for (i = 0; i < M; i++)
//	{
//		len = strlen(ss[i]);
//		if (i == 0)
//		{
//			n = len;
//		}
//		if (len > n)
//		{
//			n = len;
//			k = i;
//		}
//	}
//
//	for (i = 0; i < M; i++)
//	{
//		if (i != k)
//		{
//			m = n;
//			len = strlen(ss[i]);
//			for (j = len; j >= 0; j--)
//			{
//				ss[i][m--] = ss[i][j];
//			}
//			for (j = 0; j < n - len; j++)
//			{
//				ss[i][j] = '*';
//			}
//		}
//	}
//
//	printf("\nThe result:\n");
//
//	for (i = 0; i < M; i++)
//	{
//		printf("%s\n", ss[i]);
//	}
//
//
//	return 0;
//}

//冒泡排序
//用冒泡排序求出由11个整数组成的中间值，并输出所有大于中间值的偶数

//int main()
//{
//	int i,j,temp,array[11];   
//
//	printf("\nPlease input 11 int numbers:\n");
//
//	for (i = 0; i < 11; i++)  //输入数据
//	{
//		scanf("%d", &array[i]);
//	}
//
//	for (i = 0; i < 11; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (array[j] < array[j + 1])
//			{
//				temp = array[j];
//				array[j] = array[j + 1];
//				array[j + 1] = temp;
//			}
//		}
//	}
//
//	printf("\n中间值为:%d", array[5]);
//
//	for (i = 0; i < 5; i++)
//	{
//		if (array[i] % 2 == 0)
//		{
//			printf("\n大于中间值的偶数:%d", array[i]);
//		}
//	}
//
//	return 0;
//}

//二分法排序
//用二分法在一个升序排列的数组中查找一个数。若存在，输出该数及其下标位置；若不存在，则输出表示找不到此数的信息

//int main()
//{
//	int a[10] = { 2,5,6,8,11,15,18,22,60,88 };
//	int low, high, i, m, x;
//
//	printf("Please input a number you want to find:\n");
//	scanf("%d", &x);
//
//	for (low = 0, high = 9; low <= high;)
//	{
//		m = (low + high) / 2;
//		if (x == a[m]) break;
//		else if (x > a[m])
//		{
//			low = m + 1;
//		}
//		else
//		{
//			high = m - 1;
//		}
//	}
//
//	if (low <= high)
//	{
//		printf("\n%d is found,the position is %d\n", x, m);
//	}
//	else
//	{
//		printf("\n%d is not found\n", x);
//	}
//
//
//	return 0;
//}

//从键盘输入10个整数，输出这10个数中仅出现一次的数

//int main()
//{
//	int array[10],i,j;
//
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &array[i]);
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j < 10; j++)
//		{
//			if (i != j && array[i] == array[j]) break;
//		}
//		if (j >= 10)
//		{
//			printf("%d", array[i]);
//		}
//	}
//
//
//	return 0;
//}

//从键盘输入M个整数，去掉其中最大的2个数和最小的2个数，求剩余数据的平均值

//#define M 10
//
//int main()
//{
//	int i, j, temp,a[M],sum = 0;
//	float ave;
//
//	for (i = 0; i < M; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//
//	for (i = 0; i < M - 1; i++)
//	{
//		for (j = 0; j < M - i - 1; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//
//	for (i = 0; i < M; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//
//	for (i = 2; i < M - 2; i++)
//	{
//		sum += a[i];
//	}
//
//	ave = sum / (M - 4);
//
//	printf("平均数为：%.2f", ave);
//
//	return 0;
//}

//假设数组a中有10个整形数据，循环左移5次，即第一次左移是第一个元素移至尾部，其他元素左移一位。显示每次移动后的结果

//int main()
//{
//	int i, j, k, a[10] = { 1,4,5,6,-2,5,7,8,6,-7 };
//	printf("原数组元素：\n");
//
//	for (i = 0; i < 10; i++)
//	{
//		printf("%4d", a[i]);
//	}
//
//	printf("\n\n循环前移五次的数组元素：\n");
//
//	for (j = 1; j <= 5; j++)
//	{
//		k = a[0];
//		for (i = 1; i <= 10; i++)
//		{
//			a[i - 1] = a[i];
//		}
//		a[9] = k;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%4d", a[i]);
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}

//已知矩阵A = {(1,4,5,6),(-2,5,7,8),(6,-7,5,2)}，B = {(-1,7,9),(2,-8,6),(6,8,4),(8,9,-7)}求矩阵C，C = A x B

//int main()
//{
//
//	int A[3][4] = { (1,4,5,6),(-2,5,7,8),(6,-7,5,2) }, B[4][3] = { (-1,7,9),(2,-8,6),(6,8,4),(8,9,-7) }, C[3][3] = { 0 }, i, j, k;
//
//	for (i = 0; i < 3; i++)
//	{
//		for (j = 0; j < 3; j++)
//		{
//			for (k = 0; k < 4; k++)
//			{
//				C[i][j] += A[i][k] * B[k][j];
//			}
//		}
//		for (i = 0; i < 3; i++)
//		{
//			for (j = 0; j < 3; j++)
//			{
//				printf("%4d", C[i][j]);
//			}
//			printf("\n");
//		}
//	}
//
//
//	return 0;
//}

//在一行英语短文中找最长的单词。要求将所有单词输出，求最长单词的长度，并将该单词输出。（假设短文最后以“.”结束，单词之间以“,”或空格分隔，不出现其他符号）

int main()
{
	char str[81], maxs[20], s[20], c;
	int i, j, word = 0, num = 0, max = 0;

	printf("Enter the string\n");

	gets(str);  //输入一行英文
	i = 0;

	while ((c = str[i]) != '\0')
	{
		if (c == ' ' || c == ',' || c == '.')  //单词结束
		{
			word = 0;
			s[num] = '\0';
			puts(s);  //输出各个单词
			if (num > max)
			{
				max = num;  //若超过最大值，将num赋值给max
				strcpy(maxs, s);  //单词复制到maxs数组中
			}
			num = 0;  //num重新初始化为0，统计下一个单词的长度
		}
		else if (word == 0)  //新的单词开始
		{
			word = 1;
			s[num] = c;
			num++;
		}
		else {
			s[num] = c;  //在单词中
			num++;
		}
		i++;
	}

	printf("maxword = %s,maxlen = %d\n", maxs, max);

	return 0;
}