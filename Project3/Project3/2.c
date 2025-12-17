#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//1.define

//define定义标识符常量
//#define NUM 100
//
////define定义宏
////宏是有参数的
//#define ADD(x,y) ((x)+(y))//参数是无类型的，宏是完成文本替换的，本身不执行，函数是运行再返回值
//
//int main()
//{
//	/*printf("%d\n", NUM);
//	int n = NUM;
//	printf("%d\n", n);
//	int arr[NUM] = { 0 };*/
//	int a = 10;
//	int b = 20;
//	int c = ADD(a, b);//等于int c = ((a)+(b));
//	printf("%d\n", c);
//
//	return 0;
//}

//2.指针

//int main()
//{
//	int a = 10;//向内存申请4个字节，存储10(int整型需要4个字节)
//	//&a;//取地址操作符，地址取这个变量的首地址
//	printf("%p\n", &a);//%p是以地址的格式来打印数据
//	int* p = &a;//用p变量将a变量的地址存储起来
//	//*说明p是指针变量，即为指针的标识，一个指针一个*，int说明p指向的对象是int类型的
//	//p就为指针变量，地址也称为指针，存放指针(地址)的变量就是指针变量
//	
//	char ch = 'w';
//	char* pc = &ch;
//	
//	*p = 20;//*解引用操作符，意思就是通过p中存放的地址，找到p所指向的对象，*p就是p所指向的对象
//	//有时候&*可以抵消
//	printf("%d\n", a);
//	
//	printf("%zu\n", sizeof(char*));//打印sizeof用%zu
//	printf("%zu\n", sizeof(int*));
//	printf("%zu\n", sizeof(short*));
//	printf("%zu\n", sizeof(float*));
//	printf("%zu\n", sizeof(double*));
//	//32位机器上的地址：32bit位-4byte，所以指针变量的大小是4个字节
//	//64位机器上的地址：64bit位-8byte，所以指针变量的大小是8个字节
//
//	return 0;
//}

//3.结构体(struct)[自定义类型,结构体是把一些单一类型组合在一起的做法]

//学生
struct Stu//是一个类型，作用类似于python中的类或施工的图纸，或者是公式，定义后套用
{
	//成员
	char name[20];
	int age;
	char sex[10];
	char tele[12];
};

void print(struct Stu* ps)//print是创建的函数名，* ps是指针
{
	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).tele);//*ps解引用出地址去访问
	//*ps等同于s这个结构体变量，结构体变量则使用.操作符
	//->
	// 指针则使用->操作符
	//结构体指针变量->成员名
	printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->tele);//ps->访问指针指向的结构体的成员
}
int main()
{
	struct Stu s = { "Ryo",16,"female","13948384795" };

	//结构体对象.成员名[操作符]
	/*printf("%s %d %s %s\n", s.name, s.age, s.sex, s.tele);*/
	
	print(&s);

	return 0;
}

//define不是关键字，是预处理指令