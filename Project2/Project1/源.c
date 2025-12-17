#define _CRT_SECURE_NO_WARINGS

#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	/*int i, t;
	t = 1;
	i = 2;
	while (i <= 5)
	{
		t = t * i;
		i++;

	}
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