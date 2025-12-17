#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

//int main()
//{
//	float weight = 0.0f;
//	float height = 0.0f;
//	float BMI = 0.0f;
//	printf("请输入体重和身高");
//	scanf_s("%f %f", &weight, &height);
//	if (weight >= 50 && weight <= 180 && height >= 50 && height <= 180)
//	{
//		BMI = weight / ((height/100.0) * (height/100.0));
//		printf("BMI=%.2f", BMI);
//	}
//	else {
//		printf("体重身高范围不对");
//	}
//
//	return 0;
//}

//int main() 
//{
//	int i = 1;
//	int n = 0;
//	int ret = 1;
//	int sum = 0;
//
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		ret = ret * i;  //阶乘
//		sum = sum + ret;  //阶乘之和
//	}
//	printf("%d", sum);
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int i = 0;
//	int k = 0;
//	
//	printf("请输入要查找的值");
//	scanf_s("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//	int left = 0;
//	int right = sz - 1;
//	int mid = 0;
//
//	while (left <= right)
//	{
//		/*int mid = (left + right) / 2;*/
//		int mid = left + (right - left) / 2;  //防止前者left+right数值过大超出int范围导致数据不准
//		if (arr[mid] < k)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			printf("找到了，下标是%d", mid);
//			break;
//		}
//	}
//	if (left > right)
//	{
//		printf("找不到");
//	}
//
//	return 0;
//}

//int main()
//{
//	char arr1[] = "welcome to world!!!";
//	char arr2[] = "###################";
//
//	int left = 0;
//	int right = strlen(arr2) - 1;//int right = sizeof(arr1)/sizeof(arr[0])-2;
//
//	//while (left <= right)
//	//{
//	//	arr2[left] = arr1[left];
//	//	arr2[right] = arr1[right];
//	//	printf("%s\n", arr2);
//	//	Sleep(500);  //休眠500ms
//	//	system("cls");  //清屏
//	//	left++;
//	//	right--;
//	//}
//
//	for (left = 0;left <= right;left++,right--)
//	{
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		printf("%s\n", arr2);
//		Sleep(500);  //休眠500ms
//		system("cls");  //清屏
//	}
//
//	printf("%s\n", arr2);
//
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	char password[20] = { 0 };
//
//	for (i = 0; i < 3; i++)
//	{
//		printf("请输入密码:>");
//		scanf_s("%s", password,(unsigned int)sizeof(password)); 
//		//数组名本身就是地址，不用去地址符&
//		//scanf_f需要三个参数，第三个是缓冲器的大小参数
//		//使用sizeof(password)获取数组大小，(unsigned int)是类型转换，确保参数类型匹配
//		if (strcmp(password, "abcdefg") == 0)//strcmp()是用于比较字符串的，相等时strcmp的返回值为0，布尔值则为1结果为真
//		{
//			printf("登录成功");
//			break;
//		}
//		else
//		{
//			printf("密码错误");
//		}
//	}
//	if (i == 3)
//	{
//		printf("密码连续三次错误，退出程序");
//	}
//
//	return 0;
//}

//void menu()
//{
//	printf("********************\n");
//	printf("***** 1.play *******\n");
//	printf("***** 0.exit *******\n");
//	printf("********************\n");
//}
//
//void game()
//{
//	int guess = 0;
//	//0~RAND_MAX(32767)
//	int ret = rand() % 100 + 1;//生成随机数，0-99 --> 1-100
//
//	while (guess != ret)
//	{
//		printf("number,please\n");
//		scanf_s("%d", &guess);
//		if (guess < ret)
//		{
//			printf("smaller\n");
//
//		}
//		else if (guess > ret)
//		{
//			printf("larger\n");
//
//		}
//		else
//		{
//			printf("bingo!\n");
//			break;
//		}
//	}
//}
//
//int main()
//{
//	int input = 0;
//	srand((unsigned int)time(NULL));
//
//	do
//	{
//		menu();
//		printf("please choose noe number:>\n");
//		scanf_s("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("exit game\n");
//			break;
//		default:
//			printf("wrong selection,please choose one more time\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}


//int main()
//{
//	char input[20] = { 0 };
//	system("shutdown -s -t 60");
//again:
//	printf("你的电脑将于60s之后关机，请输入我是猪以取消关机\n");
//	scanf_s("%s", &input);
//	if (strcmp(input, "我是猪") == 0)
//	{
//		system("shutdown -a");
//		printf("已取消关机");
//	}
//	else
//	{
//		printf("错误，请尽快输入我是猪，不然真的关机了！");
//		goto again;
//	}
//
//	return 0;
//}

int main()
{
	int i, j, k;

	for (i = 0; i <= 9; i++)
	{
		for (j = 0; j <= 9 - i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= i; k++)
		{
			printf("%d", k);
		}
		for (k = i - 1; k >= 1; k--);
		{
			printf("%d", k);
		}
		printf("\n");
	}

	return 0;
}