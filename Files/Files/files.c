#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int main()
{
	int choice;
	printf("1.显示输入\n2.从源文件复制到目标文件\n3.字符串读/写\n4.信息写入以及输出\n5.fscanf\n6.fprintf\n7.文件定位\n8.文件读写中的测试举例\n");
	scanf("%d", &choice);

	switch (choice)
	{
	case 1:
	{
		FILE* fp;    //定义文件类型的指针变量fp
		char ch, c[80];
		int i, k;

		if ((fp = fopen("eg9_1.txt", "w")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);    //终止运行的程序
		}

		printf("Please Input a String:\n");
		i = 0, k = 0;                         //变量i作为数组的下标，变量k用于统计字符的个数
		scanf("%c", &c[i]);

		while (c[i] != '\n')
		{
			i = i + 1;
			scanf("%c", &c[i]);
			ch = c[i - 1];
			fputc(ch, fp);    //向fp所指向的文件写入字符
			k = k + 1;
		}
		fclose(fp);

		if ((fp = fopen("eg9_1.txt", "r")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		printf("从文件中读取的字符为：");

		for (i = 0; i < k; i++)
		{
			ch = fgetc(fp);
			printf("%c", ch);
		}

		printf("\n");

		fclose(fp);

		break;
	}

	case 2:
	{
		FILE* fp1, * fp2;
		char ch, c1[80], c2[80];

		printf("Please Input source filename:");
		scanf("%s", c1);

		if ((fp1 = fopen(c1, "r")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		printf("Please Input target filename:\n");
		scanf("%s", c2);

		if ((fp2 = fopen(c2, "w")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		while (!feof(fp1))
		{
			ch = fgetc(fp1);
			fputc(ch, fp2);
		}

		fclose(fp1);
		fclose(fp2);

		break;
	}

	case 3:
	{
		char c[80];
		FILE* fp;

		if ((fp = fopen("s3.txt", "w")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		printf("Please input a string:\n");
		scanf("%s", c);

		fputs(c, fp);
		fclose(fp);

		if ((fp = fopen("s3.txt", "r")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		printf("前10个字符为：");
		printf("%s\n", fgets(c, 11, fp));
		printf("前10个字符后面的字符为：");
		
		if (fgets(c,80,fp) != NULL)
			printf("%s\n", c);

		fclose(fp);

		break;
	}

	case 4:
	{
		struct student
		{
			char num[6];
			char name[20];
			char sex;
			int age;
			float score;
		}stu[2] = { {"01","zhang",'m',19,90},{"02","wang",'f',18,80} };

		int i, j;
		FILE* fp;

		if ((fp = fopen("s4.txt", "wb")) == NULL)
		{
			printf("Cannot open this file!");
			exit(0);
		}

		j = sizeof(struct student);

		for (i = 0; i <= 1; i++)
		{
			if (fwrite(&stu[i], j, 1, fp) != 1)
				printf("File Write Error!\n");
		}

		fclose(fp);

		if ((fp = fopen("s4.txt", "rb")) == NULL)
		{
			printf("Cannot open this file!");
			exit(0);
		}

		i = 0;

		while (!feof(fp))
		{
			if (fread(&stu[i], j, 1, fp) == 1)
			{
				printf("%s,%s,%c,%d,%.2f\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].age, stu[i].score);
				i++;
			}
		}

		fclose(fp);

		break;
	}

	case 5:
	{
		char ch;
		int x;
		FILE* fp;

		if ((fp = fopen("s5.txt", "r")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}
		printf("s5.txt文件中的信息为：\n");

		while (!feof(fp))
		{
			fscanf(fp, "%c%d", &ch, &x);
			printf("%c,%3d\n", ch, x);
		}
		fclose(fp);

		break;
	}

	case 6:
	{
		FILE* fp;
		int i, a[20];
		srand((unsigned)time(NULL));
		printf("随机产生的20个数为：");

		for (i = 0; i < 20; i++)
		{
			a[i] = rand() % (100 - 10) + 10;

			if (i % 5 == 0)
				printf("\n");
			printf("%5d", a[i]);
		}
		
		printf("\n");

		if ((fp = fopen("s6.txt", "w")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		for (i = 0; i < 20; i++)
		{
			if (i % 5 == 0)
				fprintf(fp, "%5d", a[i]);
			else
				fprintf(fp, ",%5d", a[i]);
			if ((i + 1) % 5 == 0)
				fprintf(fp, "\n");
		}
		fclose(fp);
		
		break;
	}

	case 7:
	{
		struct student
		{
			char number[6];
			char name[20];
			char sex;
			int age;
			float score;
		}s[2];
		FILE* fp;

		if ((fp = fopen("s4.txt", "rb+")) == NULL)
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		rewind(fp);

		fseek(fp, 1 * sizeof(struct student), 0);

		fread(&s[1], sizeof(struct student), 1, fp);

		printf("%s %s %c %d %.2f\n", s[1].number, s[1].name, s[1].sex, s[1].age, s[1].score);
		fclose(fp);

		break;
	}

	case 8:
	{
		FILE* fp;
		int i, flag;
		char ch, fname[20], str[100];

		printf("Input file name\n");
		scanf("%s", fname);

		if ((fp = fopen(fname, "w")) == NULL);
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		flag = 1;

		while (flag == 1);
		{
			printf("Please input string:\n");
			scanf("%s", str);
			
			fprintf(fp, "%s", str);
			fprintf(fp, "\n");

			getchar();
			printf("Continue Input String?(Y/N)\n");

			ch = getchar();

			if (ch == 'N' || ch == 'n')
				flag = 0;
			getchar();
		}
		fclose(fp);

		printf("The file %s is about:(大写字母转换成小写字母)\n", fname);

		if ((fp = fopen(fname, "r")) == NULL);
		{
			printf("Cannot open this file!\n");
			exit(0);
		}

		while (fscanf(fp, "%s", str) != EOF)
		{
			for (i = 0; str[i] != '\0'; i++)
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
				printf("%s\n", str);
			}
		}
		fclose(fp);
	}

	default:
		printf("Invalid Number!\n");

	}


	return 0;
}