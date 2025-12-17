#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include <math.h>

int main()
{
	/*int i = 0,j=0;
	printf("it works!\n");
	for (i; i < 30; i++) {
		printf("*");
	}
	printf("\n\nV e r y  g o o d !\n\n");
	for (j; j< 30; j++)                   //当j<30时一直循环j++（j++就相当于j=j+1）
	{
   		printf("*");                      //打印出符合for循环条件的*的数量
	}*/
	/*printf("How do you do!\n");*/
	/*int a, b, sum;
	a = 123;
	b = 456;
	sum = a + b;
	printf("sum is %d\n", sum);*/

	// int max(int x, int y);             

	// int a, b, c, f;
	// char  g[3];
	// char * s = "max";
	// char * h = "min";
	// int min(int x, int y);
	// scanf("%d,%d", & a, &b);
	// scanf("%s", g);
	// f = min(a, b);
	// c = max(a, b);

	// if (strcmp(g,s)== 0)
	//     printf("max=%d\n", c);

	// if(strcmp(g, h) == 0)
	//     printf("min=%d\n", f);

	// return 0;

//}
//int max(int x, int y)                    //定义max(int x,int y)
//{
//	int z;
//	if (x > y)
//		z = x;
//	else
//		z = y;
//	return(z);
//}
//int min(int x, int y)                    //定义min(int x,int y)
//{
//	int z;
//	if (x < y)
//		z = x;
//	else
//		z = y;
//	return(z);
//}



		/*int i, t;
		t = 1;
		i = 2;
		while (i <= 5)
		{
			t = t * i;
			i++;


		printf("%d\n", t);*/

		/*int sign = 1;
		double deno = 2.0, sum = 1.0, term;
		while (deno <= 100)
		{
			sign = -sign;
			term = sign / deno;
			sum = sum + term;
			deno++;
		}
		printf("%f\n", sum);*/




		float p0 = 1000, r1 = 0.0036, r2 = 0.0225, r3 = 0.0198, p1, p2, p3;


		p1 = p0 * (1 + r1);
		p2 = p0 * (1 + r2);
		p3 = p0 * (1 + r3 / 2) * (1 + r3 / 2);


		printf("p1=%f\np2=%f\np3=%f\n", p1, p2, p3);






	return 0;

}

