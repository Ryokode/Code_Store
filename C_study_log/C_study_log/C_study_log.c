#include <stdio.h>
#include <math.h>
//1
//int main()
//{
//	printf("班级：23网络3\n");
//	printf("学号：110201103\n");
//	printf("姓名：LZC\n");
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	printf("熟人两个整数");
//	scanf_s("%d %d",&a ,&b);
//
//	printf("sum=%d\n", a + b);
//	printf("cut=%d\n", a - b);
//	printf("multi=%d\n", a * b);
//	printf("divide=%d\n", a / b);
//
//	return 0;
//}

//int main()
//{
//	float a = 0.0f;
//	a = 3.5 + (int)(8 / 3 * (3.5 + 6.7) / 2) % 4;
//	printf("ret=%.2f", a);
//	return 0;
//}

//int main(void)
//{
//	
//	char c1 = 'a', c2 = 'e';
//	
//	printf("%d,%c", c1, c2 + 2);
//	
//	return 0;
//
//}

//int main(void)
//{
//	int a = 9, b = 2;
//	float x = 6.6, y = 1.1, z;
//	z = a / 2 + b * x / y - 1 / 2;
//	printf("%5.2f", z);
//	
//	return 0;
//}

//int main()
//{
//	
//	float x = 0.0f,a = 0.0f, b = 0.0f;
//	scanf_s("%f %f", &a, &b);
//	x = (a * a + b * b) / sqrt(3 * (a + b));
//
//	printf("x = %.3f",x);
//
//	return 0;
//}

//int main()
//{
//	float a = 0.0f, b = 0.0f, h = 0.0f,v = 0.0f;
//	scanf_s("%f %f %f", &a, &b, &h);
//	v = ((a + b) * h) / 2;
//
//	printf("v = %.2f", v);
//	return 0;
//}

//int main()
//{
//	int x;
//	float y;
//	printf("entry x,y:");
//	scanf_s("%d %f", &x, &y);
//	printf("x + y =%.1f", x + y);
//
//	return 0;
//}

//int main()
//{
//	int x, y, z, temp;
//	printf("please input x,y,z:");
//	scanf_s("%d%d%d", &x, &y, &z);
//	temp = z;
//	z = x;
//	x = y;
//	y = temp;
//	printf("x=%d\ny=%d\nz=%d\n", x, y, z);
//
//	return 0;
//}

int main()
{
	float a, b, c, x1, x2;
	scanf_s("%f%f%f", &a, &b, &c);
	x1 = (0 - b + sqrt(b * b - 4 * a * c)) / 2 * a;
	x2 = (0 - b - sqrt(b * b - 4 * a * c)) / 2 * a;
	printf("x1 = %.2f,x2 = %.2f", x1, x2);

	return 0;
}
