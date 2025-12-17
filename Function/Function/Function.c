#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>

//void swap(int* px, int* py)
//{
//	int z = 0;
//	z = *px;
//	*px = *py;
//	*py = z;
//}
////当实参传递给形参的时候，形参是实参的一份临时拷贝，对形参的修改不能改变实参
//
//int Add(int x, int y)
//{
//	int h = 0;
//	h = x + y;
//	return h;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	scanf("%d %d", &a, &b);
//
//	c = Add(a, b);//实际参数不需修改，Add返回值正确即可
//
//	swap(&a, &b);  //实际参数要修改时，取a、b的地址作指针
//	printf("after swap:a = %d,b = %d;after addition:c = %d", a, b,c);
//
//	return 0;
//}


//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int flag = 1;
//		int j = 0;
//		for (j = 2; j <= i - 1; j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//				break;
//			}
//		}
//		if (flag == 1)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	return 0;
//}

//100到200的素数
//int main()
//{
//	/*int i = 0;
//	int count = 0;
//	for (i = 101; i <= 200; i+=2)
//	{
//		if (is_prime(i))
//		{
//			printf("%d ", i);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);*/
//
//	int year = 0;
//	int count = 0;
//	for (year = 1000; year <= 2000; year++)
//	{
//		if (is_leap_year(year))
//		{
//			printf("%d ", year);
//			count++;
//		}
//	}
//	printf("\ncount = %d\n", count);
//
//	int year2 = 0;
//	char y_or_not[20] = { 0 };
//	
//	printf("请输入你要查询的年份\n");
//	scanf("%d", &year2);
//	if (is_leap_year(year2))
//	{
//		printf("%d是闰年\n", year2);
//	}
//	else
//	{
//		printf("%d不是闰年\n", year2);
//	}
//
//	return 0;
//}
//
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int is_leap_year(int y)
//{
//	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//二分查找函数
//这是一个错误的示范[在binary_search函数中写int sz = sizeof(arr) / sizeof(arr[0]);]//err
//数组传参实际上传递的是数组首元素的地址，而不是整个数组
//所以在函数内部计算一个函数参数部分的数组的元素个数是不靠谱的
//int binary_search(int arr[], int k, int sz)//arr[]是主函数内arr[]的指针变量
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
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
//			return mid;//找到了返回下标
//		}
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int k = 7;
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	printf("请输入1-10的数字：\n");
//	scanf("%d", &k);
//
//	int ret = binary_search(arr, k, sz);
//	if (ret == -1)
//	{
//		printf("找不到\n");
//
//	}
//	else
//	{
//		printf("找到了，下标是%d", ret);
//	}
//
//	return 0;
//}

//设计一个函数，计算一维整数数组中去掉最大值和最小值后所有元素的平均值

//#define Num 5
//
//double average(int arr[], int n);  //函数声明
//
//int main()
//{
//	int a[Num], i;
//	double ave;
//	printf("Please enter %d integers:\n", Num);
//
//	for (i = 0; i < Num; i++)
//	{
//		printf("a[%d] = ", i);
//		scanf("%d", &a[i]);
//
//	}
//	ave = average(a, Num);
//
//	printf("Average = %.2lf\n", ave);
//
//	return 0;
//}
//
//double average(int arr[], int n)
//{
//	int i, min = arr[0], max = arr[0];
//
//	double ave = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		ave += arr[i];
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		else if (arr[i] < min)
//		{
//			min = arr[i];
//		}
//	}
//
//	ave -= max + min;
//	ave /= n - 2;
//
//	return ave;
//}

//用递归方法求自然数阶乘n!
//    { 1                 n = 0,1
//n! ={ 
//    { n * (n - 1)!      n > 1

//int factorial(int n);
//
//int main()
//{
//	int n, f;
//	printf("n = ");
//
//	while (1)
//	{
//		scanf("%d", &n);
//		if (n < 0)
//		{
//			printf("Data error.Input again.\n n = ");
//		}
//		else {
//			break;
//		}
//	}
//
//	f = factorial(n);
//	printf("%d! = %d\n", n, f);
//
//	return 0;
//}
//
//int factorial(int n)
//{
//	if (n == 0 || n == 1)  //递归终止条件
//	{
//		return 1;
//	}
//	else
//	{
//		return factorial(n - 1) * n;
//	}
//
//}

//用递归方法求Fibonacci数列中第n个数

//int fib(int n);
//
//int main()
//{
//	int n;
//	printf("n = ");
//	scanf("%d", &n);
//	printf("fib(%d) = %d\n", n, fib(n));
//
//	return 0;
//}
//
//int fib(int n)
//{
//	if (n == 1 || n == 2)
//	{
//		return 1;
//	}
//	else {
//		return fib(n - 2) + fib(n - 1);
//	}
//}

//用静态局部变量计算n!


//int fun(int n);
//
//int main()
//{
//	int n, i, f;
//	printf("n = ");
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++)
//	{
//		f = fun(i);
//	}
//
//	printf("%d! = %d\n", n, f);
//
//	return 0;
//}
//
//int fun(int n)
//{
//	static int p = 1;
//
//	p *= n;
//	
//	return p;
//}

//用带参数宏实现求椭圆面积

//#define PI (asin(1) * 2)
//#define area(a,b) (PI * a * b)
//
//int main()
//{
//	double m, n, s;
//	printf("Please input the major radius and the minor radius:");
//	scanf("%lf %lf", &m, &n);
//
//	s = area(m, n);
//
//	printf("S = %f\n", s);
//
//	return 0;
//}

//编写程序，输入年月日，输出该日为该年的第几天

//int leap(int year);
//
//int month_days(int year, int month);
//
//int days(int year, int month, int day);
//
//int main()
//{
//	int year, month, day, t_day;
//
//	printf("Input year-month-day:\n");
//	scanf("%d-%d-%d", &year, &month, &day);
//
//	t_day = days(year, month, day);
//
//	printf("%d-%d-%d is %dth day of the year!\n", year, month, day, t_day);
//
//	return 0;
//}
//
//int leap(int year)
//{
//	int lp = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
//	return lp;
//}
//
//int month_days(int year, int month)
//{
//	int d;
//	
//	switch (month)
//	{
//	case 1:case 3:case 5:case 7:
//	case 8:case 10:case 12:d = 31; break;
//	case 2:d = leap(year) ? 29 : 28; break;
//	default:d = 30;
//	}
//
//	return d;
//}
//
//int days(int year, int month, int day)
//{
//	int i, ds = day;
//
//	for (i = 1; i < month; i++)
//	{
//		ds += month_days(year, i);
//	}
//
//	return ds;
//}

//Hanoi问题。一块板上有三根针A、B、C。A针上套有n个大小不等的圆盘，大的在下，小的在上。
//要把这n个圆盘从A针移动到C针上，每次只能移动一个圆盘，移动可以借助B针进行，但在任何时候，任何针上的圆盘都必须保持大盘在下，小盘在上，求移动的步骤。

//void hanoi(int n, char a, char b, char c)
//{
//	if (n == 1)  //n = 1时，直接将圆盘从A移动到C	
//	{
//		printf("%c -> %c\n", a, c);
//	}
//	else {
//		hanoi(n - 1, a, c, b);  //先将n - 1个圆盘从A经过C移动到B
//		printf("%c -> %c\n", a, c);  //将第n个圆盘从A移动到C
//		hanoi(n - 1, b, a, c);  //再将n - 1个圆盘从B经过A移动到C
//	}
//}
//
//int main(void)
//{
//	int n;
//
//	printf("Input n: ");
//	scanf("%d", &n);
//
//	hanoi(n, 'A', 'B', 'C');  //调用函数hanoi，计算n个圆盘从A经过B移动到C上
//
//}

//编写程序，将一个十进制自然数转换成十六进制数

//void trans10_16(char x[], int m);  //函数声明
//
//int main()
//{
//	int n;
//	char a[33];
//
//	printf("Input a positive integer:");
//	scanf("%d", &n);
//
//	trans10_16(a, n);  //函数调用
//
//	printf("%s\n",a);
//
//	return 0;
//}
//
//void trans10_16(char a[], int m)
//{
//	int r, i, len = 0;
//	char temp;
//
//	while (m > 0)  //用除16取余，逆向取数的方法转换
//	{
//		r = m % 16;
//		if (r < 10)
//		{
//			a[len] = r + '0';  //将数值转换为相应字符，送入数组相应元素
//		}
//		else
//		{
//			a[len] = r + 'A' - 10;
//		}
//		m /= 16;
//		++len;
//	}
//
//	a[len] = '\0';  //在串尾加入结束标记
//
//	for (i = 0; i < len/2; ++i)  //翻转数组
//	{
//		temp = a[i];
//		a[i] = a[len - 1 - i];
//		a[len - 1 - i] = temp;
//	}
//}

//编写程序，输入体重（kg）和身高（m），计算BMI指数 = 体重 / 身高的平方，根据以下标准输出BMI值和对应的结果。
//         BMI范围                 类型
//     0 < BMI < 18.5            体重过低
// 18.5 <= BMI < 24              体重正常
//   24 <= BMI < 28                超重
//         BMI >= 28               肥胖 

double bmi(double weight, double height);
void evaluate(double bmi);

int main()
{
	double weight, height;

	printf("请输入体重，以kg为单位：");
	scanf("%lf", &weight);
	printf("请输入身高，以m为单位：");
	scanf("%lf", &height);

	double BMI = bmi(weight, height);
	printf("BMI = %f\n", BMI);

	evaluate(BMI);

	return 0;
}

double bmi(double weight, double height)
{
	if (weight <= 0 || height <= 0)
		return 0;
	else
		return weight / (height * height);
}

void evaluate(double bmi)
{
	if (bmi <= 0)
	{
		printf("错误！\n");
	}
	else if (bmi < 18.5)
	{
		printf("体重过低\n");

	}
	else if (bmi < 24)
	{
		printf("体重正常\n");
	}
	else if (bmi < 28)
	{
		printf("超重\n");
	}
	else
	{
		printf("肥胖\n");
	}
}