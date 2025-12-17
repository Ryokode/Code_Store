#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//1.if语句

//int main()
//{
//	int age = 10;
//	
//	scanf("%d", &age);
//
//	if (age < 18)    //if后要跟多条语句需要用{}括起来，一对{}就是一个代码块
//	{
//		printf("未成年\n");
//		printf("不能饮酒\n");
//	}
//	else            //else同理
//	{
//		printf("成年\n");
//	
//	}
//	
//	if (age < 18)
//		printf("青少年\n");
//	else if (age >= 18 && age < 28)    //大小比较要分开写，&&表示并且
//		printf("青年\n");
//	else if (age >= 28 && age < 45)
//		printf("中年\n");
//	else if (age >= 45 && age < 60)
//		printf("中老年\n");
//	else if (age >= 60 && age < 100)
//		printf("老年\n");
//	else                                //else与最近得if匹配，就近原则
//		printf("老登\n");
//	
//	int r = test();
//	printf("%d\n", r);
//
//	int s = standard();
//	printf("%d\n", s);
//
//	return 0;
//
//}


int test()
{
	int b = 3;
	
	if (b == 3)    //return只能执行一次，return完之后这个main函数就结束执行了，就不会执行之后得return 0;
		return 1;  //如果if不在函数内，则if条件满足后，括号里的内容执行完后还是会执行括号外的
	return 0;      //后一个return执不执行看作用域，如果两个return作用域一样，则前一个执行了后一个就不执行
}

int standard()        //这个就是规范的写法，不会引起歧义
{
	int c = 4;
	if (4 == c)      //4 == c和c == 4一样，但是前一种写法如果少一个=编译器会直接报错就容易查
	{                //后一个少一个=则是把4赋值给c，无语法错误但是不是想要的结果
		return 3;
	}
	else
	{
		return 2;
	}
}

//判断一个数是否为奇数

//int main()
//{
//	int num1 = 0;
//	scanf("%d", &num1);
//	if (num1 % 2 != 0)
//	{
//		printf("奇数\n");
//	}
//	else
//	{
//		printf("偶数");
//	}
//	
//	return 0;
//}

//输出1-100之间的奇数

//int main()
//{
//	int num2 = 1;
//	
//	while (100 > num2)
//	{
//		if (1 == num2%2)
//		{
//			printf("%d ", num2);
//
//		}
//		
//		num2++;
//	}
//	
//	return 0;
//}

//2.switch语句

//int main()
//{
//	int day = 1;
//	scanf("%d", &day);
//	switch (day)           //()内放整形表达式!!!，case后面是与()内整形表达式的对应的整形常量表达式，结构相同则执行结果相同的case
//	{                      //case只决定从哪进，即入口，break是出口
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期日\n");
//		break;
//
//	}
//
//
//	return 0;
//}

//输入1-5，输出的是"weekday";
//输入6-7，输出的是"weekend"

//int main()
//{
//	int day = 1;
//	scanf("%d", &day);
//	switch (day)           //()内放整形表达式!!!，case后面是与()内整形表达式的对应的整形常量表达式，结构相同则执行结果相同的case
//	{                      //case只决定从哪进，即入口，break是出口
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	default:                //所有case都不匹配之后执行default
//		printf("输入数字错误，应在1-7之内\n");
//		break;
//	}
//
//
//	return 0;
//}

int main()
{
	int n = 1;
	int m = 2;
	switch (n)      //case1、2、3没有break!!!会继续执行下去!!!case3后的break是嵌套的switch语句的!!!
	{
	case 1:m++;
	case 2:n++;
	case 3:
		switch (n)
		{
		case 1:n++;
		case 2:m++; n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m = %d, n = %d\n", m, n);
	
	return 0;
}
