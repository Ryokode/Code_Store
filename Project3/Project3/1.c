#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//1.typedef[类型定义,类型重命名]

//typedef unsigned int unit;//将unsigned int用unit代替（类似于类型重命名）[只能针对类型进行重命名]
//
//typedef struct Node
//{
//	int date;
//	struct Node* next;    //将struct Node用Node代替（类似于类型重命名）[只能针对类型进行重命名]
//}Node;
//
//int main()
//{
//	unsigned int num = 0;
//	unit num2 = 1;
//	struct Node n;
//	Node n2;
//	
//	return 0;
//}


//2.static[用来修饰变量和函数]
//(1)修饰局部变量
//static修饰局部变量的时候，局部变量出了作用域，不销毁。本质上，static修饰局部变量的时候，改变了变量的存储位置
//影响了变量的生命周期，将局部变量a从栈区变到静态区的静态变量了[栈区(先进后出)用于存放局部变量，进作用域创建，出作用域销毁
// ；第二是堆区(先进先出)，第三是静态区用于存放静态变量(程序结束后才销毁)]

//void test()                //void函数不需要返回值，void是返回类型，不用return 0;
//{
//	static int a = 1;             //无static则每次执行都会给局部变量a重新赋值为1
//	                              //有static则a不销毁，生命周期是整个程序运行的过程，类似于a的结果存档
//	a++;                          //static修饰的语句只会执行一次，知道整个程序执行完毕
//	
//	printf("%d", a);
//}
//
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		test();
//		i++;
//	}
//	return 0;
//}
//(2)修饰全局变量

//int g_val = 2022;            //全局变量是具有外部链接的属性的
//static int g_val2 = 2023;    //static修饰全局变量的时候，这个全局变量的外部连接属性就变成了内部连接属性
//                             //其他源文件(.c)就不能在使用到这个全局变量了
//extern int g_val;            //声明外部符号，当g_val在其他c文件为全局变量时也可以使用，只需利用extern声明一下
//extern int g_val2;           //当在其他文件中声明g_val2时，g_val2不可用
//
////(3)修饰函数
//
//static int Add(int x, int y)//Add函数不再具有外部连接属性，类似于修饰全局变量
//{
//	return x + y;
//}
//
//extern int Add(int x, int y);//如果Add在外部文件中需声明，若Add函数前有static修饰，则不可用
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int z = Add(a, b);
//	printf("%d\n", z);
//	return 0;
//}


//3.register[寄存器]

//int main()
//{
//	//寄存器变量
//	register int num = 3;//建议：3存放在寄存器中
//
//	return 0;
//}