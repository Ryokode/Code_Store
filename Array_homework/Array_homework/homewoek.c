#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


//1.从键盘输入15个整数，找出最小数及其位置
//int main()
//{
//	int arr[15], pos, min, i;
//	printf("Please input 15 int numbers\n");
//
//	for (i = 0; i < 15; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	min = arr[0];
//	pos = 0;
//
//	for (i = 1; i < 15; i++)
//	{
//		if (arr[i] < min)
//		{
//			min = arr[i];
//			pos = i;
//		}
//	}
//	printf("最小值为：%d，位置为：%d\n", min, pos);
//
//	return 0;
//}



//2.十进制正整数转化为十六进制数

//int main()
//{
//	int n, i = 0, j;
//	char hex[20];  //存储十六进制各位字符
//
//	printf("请输入十进制数：\n");
//	scanf("%d", &n);
//
//	if (n == 0)
//	{
//		printf("0");
//		return 0;
//	}
//
//	while (n > 0)
//	{
//		int rem = n % 16;
//		if (rem < 10)
//		{
//			hex[i] = '0' + rem;
//		}
//		else {
//			hex[i] = 'A' + (rem - 10);
//		}
//		n /= 16;
//		i++;
//	}
//
//	for (j = i - 1; j >= 0; j--)  //逆序输出
//	{
//		printf("%c", hex[j]);
//	}
//
//	return 0;
//}

//3.统计一行字符中的单词数（以逗号分隔）

//int main()
//{
//	char str[100];
//	int count = 0, in_word = 0, i;
//
//	gets(str);  //或使用更安全的fgets(str,sizeof(str),stdin);
//	for (i = 0; str[i] != '\0'; i++)
//	{
//		if (str[i] == ',' || str[i] == ' ')
//		{
//			in_word = 0;  //遇到分隔符，标记为不在单词中
//		}
//		else {
//			if (!in_word)  //当前字符不是分隔符，且之前不在单词中，则新单词开始
//			{
//				count++;
//				in_word = 1;
//			}
//		}
//	}
//
//	printf("单词数：%d\n", count);
//
//	return 0;
//}

//4.对字符串中下标为偶数的字符排序

//int main()
//{
//	char a[100], temp;
//	int i, j, len, even_len;
//
//	gets(a);
//	len = strlen(a);
//	even_len = (len + 1) / 2;  //计算偶数下标字符的个数
//
//	for (i = 0; i < even_len - 1; i++)  //冒泡排序偶数下标的字符
//	{
//		for (j = 0;j < even_len - 1 - i;j++)
//			if (a[j * 2] > a[(j + 1) * 2])  //比较偶数位置的字符
//			{
//				temp = a[j * 2];
//				a[j * 2] = a[(j + 1) * 2];
//				a[(j + 1) * 2] = temp;
//			}
//	}
//
//	puts(a);
//
//	return 0;
//}

//5.输出10行杨辉三角

//int main()
//{
//	int a[10][10], i, j;
//
//	for (i = 0; i < 10; i++)
//	{
//		a[i][0] = 1;  //每行第一列为1
//		a[i][i] = 1;  //对角线为1
//		for (j = 1; j < i; j++)  //计算中间元素
//		{
//			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//		}
//	}
//
//	for (i = 0; i < 10; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			printf("%4d", a[i][j]);
//			
//		}
//		printf("\n");
//	}
//
//	return 0;
//}

//6.输出Fibonacci数列的前20项（每行5个）

//int main()
//{
//	int fib[20] = { 1,1 };  //初始化前两项
//	int i;
//
//	for (i = 2; i < 20; i++)  // 计算数列
//	{
//		fib[i] = fib[i - 1] + fib[i - 2];
//
//	}
//
//	for (i = 0; i < 20; i++)  //输出，每行5个
//	{
//		printf("%-8d", fib[i]);  //%-8d用于对齐
//		if ((i + 1) % 5 == 0)  //每五个换行
//		{
//			printf("\n");
//		}
//	}
//
//	return 0;
//}


//7.找出二维数组的鞍点（行最大，列最小）

//#define M 3
//#define N 4
//
//int main()
//{
//	int a[M][N];
//	int i, j, k;
//	int max, col_index, flag;
//	printf("请输入a[3][4]的数组内容：\n");
//
//	for (i = 0; i < M; i++)  //输入数组
//	{
//		for (j = 0; j < N; j++)
//		{
//			scanf("%d", &a[i][j]);
//		}
//	}
//
//	flag = 0;  //标记是否找到鞍点
//
//	for (i = 0; i < M; i++)  //找到第i行最大值
//	{
//		max = a[i][0];
//		col_index = 0;
//		for (j = 1; j < N; j++)
//		{
//			if (a[i][j] > max) {
//				max = a[i][j];
//				col_index = j;
//			}
//		}
//
//		for (k = 0; k < M; k++)  //检查max是否是第col_index列的最小值
//		{
//			if (a[k][col_index] < max)
//			{
//				break;  //不是最小值跳出检查
//			}
//		}
//
//		if (k == M)  //循环完整执行，说明是最小值
//		{
//			printf("鞍点：a[%d][%d] = %d\n", i, col_index, max);
//			flag = 1;
//		}
//	}
//	if (!flag)
//	{
//		printf("此数组无鞍点\n");
//	}
//
//
//	return 0;
//}

//8.输入五个字符串，输出最长的字符串

//int main()
//{
//	char str[5][100];//假设每个字符串不超过99个字符
//	int i, max_len = 0, max_index = 0, len;
//
//	printf("请输入五个字符串：\n");
//
//	for (i = 0; i < 5; i++)
//	{
//		gets(str[i]);
//		len = strlen(str[i]);
//		if (len > max_len) {
//			max_len = len;
//			max_index = i;
//		}
//	}
//
//	printf("最长的字符串是：%s\n", str[max_index]);
//
//
//	return 0;
//}

//9.输入字符串，将下标为奇数的字符排序

//int main() {
//
//	char a[100], temp;
//	int i, j, len, odd_len;
//	printf("请输入字符串：\n");
//
//	gets(a);
//	len = strlen(a);
//	odd_len = len / 2;  //奇数下标的字符个数
//
//	for (i = 0; i < odd_len - 1; i++)
//	{
//		for (j = i + 1; j < odd_len; j++)
//		{
//			if (a[i * 2 + 1] > a[j * 2 + 1])
//			{
//				temp = a[i * 2 + 1];
//				a[i * 2 + 1] = a[j * 2 + 1];
//				a[j * 2 + 1] = temp;
//			}
//		}
//	}
//	printf("排序后：%s\n", a);
//
//	return 0;
//}

//10.输入字符串，将其中大写字母转为小写字母，小写字母转为大写字母

int main()
{
	char s[100];
	int i;

	printf("请输入字符串\n");
	gets(s);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
	}
	printf("转换后：%s\n", s);

	return 0;
}