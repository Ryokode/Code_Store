#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*编程题*/
//1.用结构体变量表示平面上的两个点（横坐标和纵坐标），输入两个点，求两点之间的距离。
//2.已知一个无符号的整数占用了4个字节的内存空间，现欲从低位存储地址开始，将其每个字节作为独立的一个ASCII码字符输出，试用共用体实现。例如：十六进制数0x44434241，则输出ABCD。
//3.用结构体变量表示复数（实部和虚部），输入两个复数，求两个复数的和与积。
// 注意：
//若两个复数相加或乘积时虚部为0时，只输出实部。设复数定义为A=a+bi，则：
//复数的加法定义：(a + bi) + (c + di) = (a + c) + (b + d)i
//复数的乘法定义：(a + bi) * (c + di) = (ac - bd) + (ad + bc)i

struct Point  /*定义平面点的结构体*/
{
	float x;
	float y;
};

union IntChar    /*定义共用体，是整数和字符数组共享内存
	*/
{
	unsigned int num;
	char str[4];
};

struct Complex    /*定义表示复数的结构体*/
{
	float real;
	float imag;
};

int main()
{
	int Question;
	printf("1.试题1\t2.试题2\t3.试题3\n");
	scanf("%d", &Question);

	switch (Question)
	{

	case 1:
	{
		struct Point p1, p2;
		float distance;

		//输入第一个点的坐标
		printf("请输入第一个点的横坐标和纵坐标：");
		scanf("%f %f", &p1.x, &p1.y);

		//输入第二个点的坐标
		printf("请输入第二个点的横坐标和纵坐标：");
		scanf("%f %f", &p2.x, &p2.y);

		//计算两点距离
		distance = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
		printf("两点之间的距离为：%f\n", distance);

		break;
	}

	case 2:
	{
		union IntChar ic;
		int i;

		//输入无符号整数
		printf("请输入一个无符号整数：");
		scanf("%u", &ic.num);

		//输出每个字节对应的ASCII字符
		for (i = 0; i < 4; i++)
		{
			printf("%c", ic.str[i]);
		}

		printf("\n");

		break;
	}

	case 3:
	{
		struct Complex c1, c2, sum, product;

		//输入第一个复数
		printf("请输入第一个复数的实部与虚部：");
		scanf("%f %f", &c1.real, &c1.imag);

		//输入第二个复数
		printf("请输入第二个复数的实部与虚部：");
		scanf("%f %f", &c2.real, &c2.imag);

		//计算复数和
		sum.real = c1.real + c2.real;
		sum.imag = c1.imag + c2.imag;

		//计算复数积
		product.real = c1.real * c2.real - c1.imag * c2.imag;
		product.imag = c1.real * c2.imag + c1.imag * c2.real;

		printf("复数和：");
		if (sum.imag == 0)  /*虚部为0时只输出实部*/
		{
			printf("%f\n", sum.real);
		}
		else
		{
			printf("%f + %fi\n", sum.real, sum.imag);
		}

		printf("复数积：");
		if (product.imag == 0)  /*虚部为0时只输出实部*/
		{
			printf("%f\n", product.real);
		}
		else
		{
			printf("%f + %fi\n", product.real, product.imag);
		}

		break;
	}

	default:
		printf("Invaild Number!\n");

	}

	return 0;
}