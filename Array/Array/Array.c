#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>



//int main()
//{
//	int i;
//	int fib[10] = { 1,1 };
//	for (i = 2; i < 10; i++)
//	{
//		fib[i] = fib[i - 1] + fib[i - 2];
//	}
//	for (i = 0; i < 10; i++)
//	{
//		if (i % 5 == 0)
//		{
//			printf("\n%6d", fib[i]);
//		}
//	
//	}
//
//	printf("\n");
//
//	return 0;
//}

//int main(void)
//{
//	int max, i, j, a[20];
//	srand((unsigned)time(NULL));
//	printf("随机产生20个数分别为：");
//
//	for (i = 0; i < 20; i++)
//	{
//		a[i] = rand() % 100;
//		if (i % 10 == 0)
//			printf("\n%5d", a[i]);
//	}
//	printf("\n");
//
//	max = a[0];
//	j = 0;
//	for (i = 1; i < 20; i++)
//	{
//		if (max < a[i])
//		{
//			max = a[i];
//			j = i;
//		}
//	}
//
//	printf("最大数为：%d，位置：%d，\n", max, j);
//
//
//	return 0;
//}


//int main()
//{
//	char a[20], b[20];
//	int i = 0;
//	printf("Please input a string:");
//	scanf("%s", a);
//
//	do
//	{
//		b[i] = (a[i] >= 'a' && a[i] <= 'z') ? a[i] - 32 : a[i];
//	} while (a[i++]!='\0');
//
//	printf("The content of string array a are:%s\n", a);
//	printf("The content of string array b are:%s\n", b);
//
//	return 0;
//}

//int main()
//{
//	char pw[] = "123456", c[10];
//	int i = 1;
//	printf("please input password first time(three chances):\n");
//	gets(c);
//
//	if (strcmp(pw, c) == 0)
//		printf("Correct!");
//	else
//	{
//		do
//		{
//			printf("please try again\n");
//			gets(c);
//			if (strcmp(pw, c) == 0)
//			{
//				printf("Correct!");
//				break;
//			}
//			else i++;
//
//		} while (i < 3);
//	}
//	if (i == 3)
//	{
//		printf("Your three chances are all run out and all are failed!\n");
//		printf("Please wait 5 mins to input your password again.\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	char str1 [40], str2 [40];
//	printf("Please input two strings\n");
//	gets(str1);
//	gets(str2);
//	_strlwr(str1);
//	_strupr(str2);
//
//	printf("New string:");
//	puts(strcat(str1, str2));
//
//
//	return 0;
//}


//编程实现对学生成绩按从小到大的顺序排序
//方法一：冒泡法排序

//int main()
//{
//	int i, j, n, a[100];
//	int temp;
//	printf("Please input the number of data:\n");
//	scanf("%d", &n);
//	printf("Input %d data:", n);
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	printf("\nOutput the original array:");
//	for (i = 0; i < n; i++)
//	{
//		printf("%3d", a[i]);
//	}
//	for (i = 0; i <= n - 2; i++)
//	{
//		for (j = 0; j <= n - 2 - i; j++)
//		{
//			if (a[j] > a[j + 1])
//			{
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//	printf("\nOutput the sorted array:");
//
//	for (i = 0; i < n; i++)
//	{
//		printf("%3d", a[i]);
//	}
//	printf("\n");
//
//	return 0;
//}

////方法二：选择法排序
//#define N 10
//#define PI 3.1415926
//
//int main()
//{
//	int a[N];
//	int i, j, k, t;
//	printf("Input %d numbers: ", N);
//	
//	for (i = 0; i <= N - 1; i++)
//	{
//		scanf("%d", &a[i]);
//	}
//	for (i = 0; i <= N - 2; i++)
//	{
//		k = i;
//		for (j = i + 1; j <= N-1; j++)
//		{
//			if (a[j] < a[k])
//			{
//				k = j;
//			}
//			if (i != k)
//			{
//				t = a[i];
//				a[i] = a[k];
//				a[k] = t;
//			}
//		}
//	}
//	printf("The sorted numbers:\n");
//	for (i = 0; i <= N - 1; i++)
//	{
//		printf("%d\n", a[i]);
//	}
//
//
//	return 0;
//}

//#define M 4

//int main()
//{
//	int a[4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 }, b[M][M], i, j;
//	printf("原数组：\n");
//
//	for (i = 0; i < M; i++)
//	{
//		for (j = 0; j < M; j++)
//		{
//			printf("%3d", a[i][j]);
//		}
//		printf("\n");
//	}
//	for (i = 0; i < M; i++)
//	{
//		for (j = 0; j < M; j++)
//		{
//			b[i][j] = a[M - j - 1][i];
//		}
//		
//	}
//	printf("顺时针旋转后的数组：\n");
//	for (i = 0; i < M; i++)
//	{
//		for (j = 0; j < M; j++)
//		{
//			printf("%3d", b[i][j]);
//		}
//		printf("\n");
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int i, j, score, sum;
//	float ave;
//
//	for (i = 1; i <= 5; i++)
//	{
//		sum = 0;
//		printf("输入第%d个学生的7门课程成绩：", i);
//		for (j = 1; j <= 7; j++)
//		{
//			scanf("%d", &score);
//			sum += score;
//		}
//		ave = sum / 7.0;
//		printf("\n第%d个学生的总分为：%d 平均分为：%.2f\n\n", i, sum, ave);
//	}
//
//	return 0;
//}

////假设数组a为4行4列的随机整数，计算每行的平均值，保留两位小数，然后输出平均值和每行的最大值
//int main()
//{
//	int a[4][4];    
//	int i, j, s, max;
//	float ave;
//
//	srand((unsigned)time(NULL));  //以时间为随机数种子
//
//	for (i = 0; i < 4; i++)  //产生16个随机整数
//	{
//		for (j = 0; j < 4; j++)
//		{
//			a[i][j] = rand() % 100;
//		}
//	}
//
//	printf("Output array a:\n");
//
//	for (i = 0; i < 4; i++)
//	{
//		for (j = 0; j < 4; j++)
//		printf("%5d", a[i][j]);
//		printf("\n");
//	}
//
//	for (i = 0; i < 4; i++)
//	{
//		s = 0;
//		for (j = 0; j < 4; j++)
//		s = s + a[i][j];
//		ave = s * 1.0 / 4;
//			printf("aver of line %d is %.2f\n", i + 1, ave);
//	}
//
//	for (i = 0; i < 4; i++)
//	{
//		max = a[i][0];
//		for (j = 1; j < 4; j++)
//		{
//			if (a[i][j] > max) max = a[i][j];
//		}
//		printf("max of line %d is %d\n", i + 1, max);
//	}
//
//
//	return 0;
//}

//从键盘输入N个有序整数，然后在其中查找数据k，若找到，显示查找成功的信息，并将该数据删除；若没有找到，则将数据k插入这些数中，插入操作后数据仍然有序
#define N 8 

int main()
{
	int a[N + 1], k, i, low, high, mid;
	int point;
	printf("Please enter %d order data:", N);
	
	for (i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);  //按从小到大的顺序输入数据
	}
	printf("Please enter the number to be located:");
	scanf("%d", &k);
	low = 0, high = N - 1;

	while (low <= high)  //二分查找
	{
		mid = (low + high) / 2;
		if (a[mid] == k)
		{
			point = mid;  //记录查找值的位置
			break;
		}
		else if (a[mid] < k)
		{
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}

	if (low <= high)  //如果查找成功则删除数据
	{
		printf("The index of data is:%d,Now delete it.\n", point);  //显示查找值的下标
		for (i = point; i < N; i++)  //删除数据
		{
			a[i] = a[i + 1];
		}
		for (i = 0; i < N - 1; i++)
		{
			printf("%4d", a[i]);
			printf("\n");
		}
	}
	else {
		printf("The data is not in the array!Now insert.\n");  //如果查找失败则插入数据
		i = N - 1;
		while (a[i] > k)  //查找并空出插入数据的位置
		{
			a[i + 1] = a[i];
			i = i - 1;
		}
		a[++i] = k;  //插入数据
		for (i = 0; i <= N; i++)
		{
			printf("%4d", a[i]);
			printf("\n");
		}
	}

	return 0;
}