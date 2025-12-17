#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define MAXLEN 2

struct DoubleWord
{
	char c1;
	char c2;
	char c3;
	char c4;
};

union share
{
	struct DoubleWord tag;
	unsigned long data;
};

typedef struct _RingNode
{
	int SerialNo;
	struct _RingNode* next;
}RingNode;

RingNode* Create(int n)  /*创建单向循环链表*/
{
	if (n <= 0)
	{
		return NULL;
	}

	RingNode* head = NULL;
	RingNode* pRear = NULL;
	RingNode* pNew = NULL;

	int i;

	for (i = 1; i <= n; i++)
	{
		pNew = (RingNode*)malloc(sizeof(RingNode));  //开辟空间

		if (pNew == NULL)
		{
			return NULL;
		}

		pNew->SerialNo = i;  //设置序号，构造结点
		pNew->next = NULL;  //暂未使用的指针先设为空

		if (head == NULL)
		{
			head = pNew;      //如果是第一个结点
			pNew->next = head;
			pRear = pNew;  //尾指针指向当前结点
		}
		else                  //如果不是第一个结点
		{
			pRear->next = pNew;
			pNew->next = head;
			pRear = pNew;    //移动链表的尾指针
		}
	} 

	return(head);        //返回链表头指针
}

int QuitRing(RingNode* h, int start, int m)
{
	/*从序号为start的人开始报循环数，凡是报到m的人马上出圈，n-1个人出圈后，最后将圈中剩下的那个人的序号返回*/
	int count = 1;
	RingNode* p, * q;
	p = h;

	while (p->SerialNo != start)
	{
		p = p->next;
	}

	while (h->next != h)
	{
		count = 1;

		while (count < m - 1)
		{
			p = p->next;
			count++;
		}

		q = p->next;

		if (q == h)
		{
			h = q->next;
		}

		p->next = q->next;
		printf("序号为%d的人出圈！\n", q->SerialNo);

		free(q);
		p = p->next;
	}

	return h->SerialNo;
}

typedef struct
{
	char name[10];
	int age;
	char job;

	union
	{
		char class[10];
		char office[30];
	}dep;
}MEMBER;

int main()
{
	int cs;
	printf("0.测试\n1.n个人围成一圈，并按圈中的排列次序给所有人编上序号（序号从1到n），\
从序号为start的人开始循环报数（从1到m报数），start的值有用户输入，凡报到m的人就从圈里出来，然后下一个人又从头开始报数直到圈中只剩一个人为止。\
输出从圈里出来的人的序号顺序\n2.学生教师入录\n");
	scanf("%d", &cs);

	switch (cs)
	{
	case 0:
	{
		union share dt;
		dt.data = 0x4c495350;

		printf("%c-->%xH\n", dt.tag.c1, dt.tag.c1);
		printf("%c-->%xH\n", dt.tag.c2, dt.tag.c2);
		printf("%c-->%xH\n", dt.tag.c3, dt.tag.c3);
		printf("%c-->%xH\n", dt.tag.c4, dt.tag.c4);
		printf("%c%c%c%c\n", dt.tag.c4, dt.tag.c3, dt.tag.c2, dt.tag.c1);

		break;
	}

	case 1:
	{
		int n;
		int s, start, m;
		RingNode* head;

		printf("请输入开始报数前的圈中人数：");
		scanf("%d", &n);
		printf("请输入第一个报数人的序号");
		scanf("%d", &start);
		printf("请输入所有报数的最大值（报到该数的人马上从圈中退出）：");
		scanf("%d", &m);

		head = Create(n);
		s = QuitRing(head, start, m);

		printf("圈中最后剩下的人的序号为：%d\n", s);

		break;
	}

	case 2:
	{
		MEMBER body[MAXLEN];
		int i;

		for (i = 0; i < MAXLEN; i++)
		{
			/*fflush(stdin);*/
			int c;
			while ((c = getchar()) != '\n' && c != EOF);

			printf("请输入第%d个人的姓名：", i + 1);
			gets(body[i].name);
			printf("请输入第%d个人的年龄：", i + 1);
			scanf("%d",&body[i].age);
			
			/*fflush(stdin);*/
			while ((c = getchar()) != '\n' && c != EOF);
			printf("请输入第%d个人的身份（学生为s，教师为t）：", i + 1);
			scanf("%c", &body[i].job);

			if ('s' == body[i].job)
			{
				printf("请输入该学生的班级：");
				scanf("%s", body[i].dep.class);
			}
			else
			{
				printf("请输入该教师的办公室：");
				scanf("%s", &body[i].dep.office);
			}
		}

		printf("Name\tAge\tIdentity\tClass/Office\t\n");

		for (i = 0; i < MAXLEN; i++)
		{
			if ('s' == body[i].job)
				printf("%s\t%3d\t%s\t\t%s\n", body[i].name, body[i].age, "student", body[i].dep.class);
			else
				printf("%s\t%3d\t%s\t\t%s\n", body[i].name, body[i].age, "teacher", body[i].dep.office);
		}

		break;
	}

	default:
		printf("Invaild Number!");
	}

	return 0;
}