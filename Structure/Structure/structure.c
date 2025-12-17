#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>


#define NUM 3


struct member
{
	char name[20];
	char phone[15];
};

struct stu2
{
	char num2[10];
	char name2[20];
	char sex2;
	int age2;
	float score2;
}boy4, boy3;

struct stu3
{
	char num[10];
	char name[20];
	char sex;
	float score;
}boy5 = {"102","Zhang ping",'M',78.5},*pstu;

struct stu4
{
	char num[10];
	char name[20];
	char sex;
	float score;
};

struct StuNode
{
	char num_node[10];
	char name_node[20];
	char sex_node;
	int age_node;
	float score_node;
	struct StuNode* Next;
};

struct StuNode * Create(int n)  /*创建链表*/
{
	struct StuNode* head = NULL, * pf = NULL, * pb;
	int i;

	/*清空输入缓冲区，避免换行符影响*/
		/*fflush(stdin);*/
	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	for (i = 0; i < n; i++)
	{
		pb = (struct StuNode*)malloc(sizeof(struct StuNode));  //开辟空间

		printf("Please input the No:");  //构造结点
		gets(pb->num_node);
		printf("Please input the Name:");
		gets(pb->name_node);

		printf("Please input the Sex:");
		scanf("%c", &pb->sex_node);
		printf("Please input the Age and Score:");
		scanf("%d %f", &pb->age_node, &pb->score_node);

		while ((c = getchar()) != '\n' && c != EOF);
		/*每次输入后清空缓冲区*/

		pb->Next = NULL;  //暂未使用的指针先设为空

		if (i == 0)  //如果是第一个结点
		{
			head = pb;
			pf = pb;  //记录第一个结点
		}
		else  //否则，插入结点到链表尾部
		{
			pf->Next = pb;  //前一个结点指向当前结点
			pf = pb;  //更新pf为当前结点，移动链表的尾指针
		}
	}
	return(head);  //返回链表的头指针
};

struct StuNode* Insert(struct StuNode* h, char* pnum)  /*插入结点*/
{
	struct StuNode* pa, * pb;
	pa = h;

	int c;
	while ((c = getchar()) != '\n' && c != EOF);

	if (!strcmp(pa->num_node, pnum))    //应该在第一个结点前插入
	{
		pb = (struct StuNode*)malloc(sizeof(struct StuNode));  //开辟空间
		while ((c = getchar()) != '\n' && c != EOF);

		printf("请输入待插入的学生信息：\n");
		printf("Please input the No:");  //构造结点
		gets(pb->num_node);
		printf("Please input the Name:");
		gets(pb->name_node);

		printf("Please input the Sex:");
		scanf("%c", &pb->sex_node);
		printf("Please input the Age and Score:");
		scanf("%d %f", &pb->age_node, &pb->score_node);

		while ((c = getchar()) != '\n' && c != EOF);
		/*每次输入后清空缓冲区*/
		pb->Next = pa;    //插入新结点到链表中
		return pb;        //返回新的链表头指针
	}
	else
	{
		while (pa->Next != NULL)
		{
			if (!strcmp(pa->Next->num_node, pnum))    //应该在第一个结点前插入
			{
				pb = (struct StuNode*)malloc(sizeof(struct StuNode));  //开辟空间
				while ((c = getchar()) != '\n' && c != EOF);

				printf("请输入待插入的学生信息：\n");
				printf("Please input the No:");  //构造结点
				gets(pb->num_node);
				printf("Please input the Name:");
				gets(pb->name_node);

				printf("Please input the Sex:");
				scanf("%c", &pb->sex_node);
				printf("Please input the Age and Score:");
				scanf("%d %f", &pb->age_node, &pb->score_node);

				while ((c = getchar()) != '\n' && c != EOF);
				/*每次输入后清空缓冲区*/
				pb->Next = pa->Next;    //插入新结点到链表中
				pa->Next = pb;
				return h;        
			}
			else
			{
				pa = pa->Next;
			}
		}
		printf("未找到插入位置！\n");
		return h;
	}
};

struct StuNode * Delete(struct StuNode *h,char *pnum)  /*删除指定结点*/
{
	struct StuNode* p, * q;
	p = h;

	if (!strcmp(p->num_node, pnum))  //删除的是第一个结点
	{
		h = p->Next;    //从链表中断开待删除的结点
		free(p);        //释放节点空间
		return h;
	}
	else            //第一个结点时不要删除的
	{
		while (p->Next != NULL)
		{
			if (!strcmp(p->Next->num_node, pnum))    //如果找到待删除结点
			{
				q = p->Next;    //用q指向待删除结点
				p->Next = q->Next;
				free(q);
				return h;    //返回链表头指针
			}
			else
			{
				p = p->Next;  //否则，继续查看下一个结点
			}
		}
		printf("未找到要删除的结点！\n");
		return h;
	}
};

void ShowAll(struct StuNode* h);

void average(struct stu4* ps, int n);

void Search(struct StuNode* h, char* pc);

void Destroy(struct StuNode** ph);

int main()
{
	int cases;

	printf("1.struct stu局部\n2.struct stu2全局\n3.结构体数组\n4.指向结构体的指针\n5.结构体与函数\n6.链表\n7.创建存放学生信息的含有n个节点的链表\n");
	scanf("%d", &cases);
	
	switch (cases)
	{

	case 1:
	{
		struct stu
		{
			char num[10];
			char name[11];
			char sex;
			float score;
		}boy2, boy1 = { "080301","Zhang ping",'M',78.5};

		boy2 = boy1;

		printf("Number = %s\nName = %s\n", boy2.num, boy2.name);
		printf("Sex = %c\nScore = %4.1f\n", boy2.sex, boy2.score);

		break;
	}

	case 2:
	{
		printf("Please input the num:\n");
		scanf("%s",&boy3.num2);

		printf("Please input the name:\n");
		scanf("%s",&boy3.name2);

		printf("Please input the age:\n");
		scanf("%d", &boy3.age2);

		printf("Please input the sex:\n");
		scanf("%c", &boy3.sex2);

		printf("Please input the score:\n");
		scanf("%f", &boy3.score2);

		boy4 = boy3;

		printf("Number = %s\nName = %s\nAge = %d\n", boy4.num2, boy4.name2,boy4.age2);
		printf("Sex = %c\nScore = %3.1f\n", boy4.sex2, boy4.score2);

		break;
	}
	case 3:
	{
		struct member classmate[NUM];
		int i;

		for (i = 0; i < NUM; i++)
		{
			printf("Input name:\n");
			gets(classmate[i].name);

			printf("Input phone:\n");
			gets(classmate[i].phone);
		}

		printf("name\t\tphone\n");

		for (i = 0; i < NUM; i++)
		{
			printf("%s\t\t%s\n", classmate[i].name, classmate[i].phone);
		}

		break;
	}

	case 4:
	{
		pstu = &boy5;

		printf("Number = %s\nName = %s\n", boy5.num, boy5.name);
		printf("Sex = %c\nScore = %f\n\n", boy5.sex, boy5.score);

		printf("Number = %s\nName = %s\n", (*pstu).num, (*pstu).name);
		printf("Sex = %c\nScore = %f\n\n", (*pstu).sex, (*pstu).score);

		printf("Number = %s\nName = %s\n", pstu -> num, pstu -> name);
		printf("Sex = %c\nScore = %f\n\n", pstu -> sex, pstu -> score);

		break;
	}

	case 5:
	{
		struct stu4 boy[5] = 
		{
			{"101","Li ping",'M',45},
			{"102","Zhang ping",'M',62.5},
			{"103","He fang",'F',92.5},
			{"104","Cheng ling",'F',87},
			{"105","Wang ming",'M',58}
		};

		average(boy, 5);

		break;
	}

	case 6:
	{
		struct stuchain
		{
			char numchain[10];
			char namechain[20];
			char sexchain;
			float scorechain;
		}*ps;

		ps = (struct stuchain*)malloc(sizeof(struct stuchain));

		strcpy(ps->numchain, "102");
		strcpy(ps->namechain, "Zhang ping");

		ps->sexchain = 'M';
		ps->scorechain = 62.5;

		printf("Number = %s\nName = %s\n", ps->numchain, ps->namechain);
		printf("Sex = %c\nScore = %5.2f\n", ps->sexchain, ps->scorechain);

		free(ps);

		break;
	}

	case 7:
	{
		int n;
		struct StuNode* head,*current,*temp;

		printf("Please input the number of student:");
		scanf("%d", &n);

		int c;
		while ((c = getchar()) != '\n' && c != EOF);

		head = Create(n);
		ShowAll(head);

		printf("Please input a name of you want to serach:\n");

		char sname;
		scanf("%s", &sname);

		Search(head, sname);  /*调用查找函数*/

		//释放链表内存
		current = head;
		while (current != NULL)
		{
			temp = current;
			current = current->Next;
			free(temp);
		}

		break;
	}

	default:
		printf("Invaild Case!\n");

	}
			
	return 0;
}

void average(struct stu4* ps, int n)
{
	int c = 0, i;
	float ave, s = 0;

	for (i = 0; i < n; i++, ps++)
	{
		s = s + ps->score;
		if (ps->score < 60)
		{
			c = c + 1;
		}
	}

	printf("Sum = %5.1f\n", s);

	ave = s / n;

	printf("Average = %5.1f\nNo Pass Count = %d\n", ave, c);
}

void ShowAll(struct StuNode* h)
{
	struct StuNode* p;
	p = h;

	if (h)
	{
		printf("Num\tName\tSex\tAge\tScore\n");
	}
	else
	{
		printf("链表为空！\n");
		return;
	}

	while (p)
	{
		printf("%s\t%s\t%c\t%d\t%3.1f\n", p->num_node, p->name_node, p->sex_node, p->age_node, p->score_node);
		p = p->Next;
	}
}

void Search(struct StuNode* h, char* pc)  /*查找结点*/
{
	struct StuNode* p;
	p = h;
	
	while (p != NULL)
	{
		if (!strcmp(p->name_node, pc))  /*如果找到该结点，则输出*/
		{
			printf("链表中找到姓名为%s的同学，其信息如下:\n", pc);
			printf("%s,%s,%c,%d,%3.1f\n", p->num_node, p->name_node, p->sex_node, p->age_node, p->score_node);
			return;
		}
		else  /*否则，继续查找下一个结点*/
		{
			p = p->Next;
		}
	}
	printf("链表中未找到姓名为%s的同学！\n",pc);  /*给出未找到的提示*/
}

void Destroy(struct StuNode** ph)  /*销毁链表，ph为指向head的二级指针变量*/
{
	struct StuNode* p;
	p = * ph;           //*ph相当于head

	while (p != NULL)
	{
		*ph = p->Next;  //移动指针，继续删除下一个结点
		free(p);
		p = *ph;
	}
	printf("已删除链表中的所有结点，成功销毁整个链表！\n");
	*ph = NULL;        //将空的指针赋值给链表的头指针
}