#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

//1.

//int main()
//{
//	int i, j, score, sum;
//	float ave;
//
//	for (i = 1; i <= 5; i++)
//	{
//		printf("Please enter No.%d students' grades of 7 subjects:\n",i);
//		sum = 0;
//
//		for (j = 1; j <= 7; j++)
//		{
//			scanf("%d", &score);
//			sum += score;
//		}
//		ave = sum / 7.0;
//		printf("第%d位同学的总分为%d，平均分为%.2f\n", i, sum, ave);
//	}
//
//
//	return 0;
//}

//2.

//int main()
//{
//	int Growth_per_year, year = 2000;
//	
//	float Indus_Output_Val = 200;
//
//	while (Indus_Output_Val <= 500)
//	{
//		Growth_per_year = 0.045 * Indus_Output_Val;
//		Indus_Output_Val = Indus_Output_Val + Growth_per_year;
//		year++;
//	}
//
//	printf("Industrial Output Value is %f,Growth per year is %d\n", Indus_Output_Val, Growth_per_year);
//	printf("%d years over 500\n", year - 2000);
//
//
//	return 0;
//}

//3.

//int main() {
//
//	int a, b, c;
//
//	for (a = 1; a <= 9; a++)
//	{
//		for (b = 0; b <= 9; b++)
//		{
//			for (c = 0; c <= 9; c++)
//			{
//				if ((a * a * a + b * b * b + c * c * c) == 1099)
//				{
//					printf("%d\n", (10 * a + b) * 10 + c);
//				}
//			}
//		}
//	}
//
//
//	return 0;
//}

//4.

//int main()
//{
//	int i, k, x, s;
//
//	for (x = 1;; x++)
//	{
//		s = 0;
//		k = x;
//		for (i = 1; i <= 8; i++)
//		{
//			s = s + k, k = k * 2;
//		}
//		if (s == 765) break;
//	}
//	printf("\n%d", k / 2);
//
//	return 0;
//}

//5.

//int main()
//{
//	int sum, i, j;
//
//
//	for (i = 1; i < 1000; i++)
//	{
//		sum = 0;
//		for (j = 1; j < i; j++)
//		{
//			if (i % j == 0)
//			{
//				sum += j;
//			}
//			
//		}
//
//		if (sum == i)
//		{
//			printf("%4d", i);
//		}
//	}
//
//
//	return 0;
//}

//int main()
//{
//	int x,s;
//
//	for (x = 3; x % 2 != 0 && x < 100; x = x + 2)
//	{
//		s = x / (int)sqrt(x);
//		if (s != 0)
//		{
//			printf("素数为：%d\t", x);
//		}
//	}
//
//	return 0;
//}


int main()
{
	int x, s;

	for (x = 2; x < 100; x++)
	{
		if (x % 2 != 0)
		{
			s = x / (int)sqrt(x);
			if (s != 0)
			{
				printf("素数为：%d\t", x);
			}
		}
		
	}

	return 0;
}