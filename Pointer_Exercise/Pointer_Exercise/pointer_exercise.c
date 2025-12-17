#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define M 3
#define N 4
#define MAX_LEN 80
#define STR_COUNT 10
#define MAX_STR_LEN 30

// (1) 字符串比较函数
int cmpstr(char* str1, char* str2)
{
    while (*str1 && *str2 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

// (2) 数组逆序并求平均值
float reverse(int p[], int n)
{
    int i, temp, sum = 0;

    // 逆序排列
    for (i = 0; i < n / 2; i++)
    {
        temp = p[i];
        p[i] = p[n - 1 - i];
        p[n - 1 - i] = temp;
    }

    // 计算平均值
    for (i = 0; i < n; i++)
    {
        sum += p[i];
    }

    return (float)sum / n;
}

// (3) 删除子字符串
void del_substr(char* str, int k, int m)
{
    int len = strlen(str);

    if (k < 1 || k > len || m < 0)
    {
        return; // 参数检查
    }

    if (k + m - 1 > len)
    {
        m = len - k + 1; // 如果m超出范围，调整m的值
    }

    // 将后面的字符前移
    memmove(&str[k - 1], &str[k - 1 + m], len - (k - 1 + m) + 1);
}

// (4) 删除指定字符
void del_Spechar(char* str, char ch)
{
    char* src = str, * dst = str;

    while (*src)
    {
        if (*src != ch)
        {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';
}

// (5) 求二维数组最大元素值及位置
void find_max_2d(int a[][N], int* max_val, int* max_row, int* max_col)
{
    int i, j;
    *max_val = a[0][0];
    *max_row = 0;
    *max_col = 0;

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (a[i][j] > *max_val)
            {
                *max_val = a[i][j];
                *max_row = i;
                *max_col = j;
            }
        }
    }
}

// (6) 查找字符位置
int lstrchar(char* str, char ch)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == ch)
        {
            return i;
        }
        i++;
    }
    return -1;
}

// (7) 数组求和的三种方法
// 数组下标法
int sum_array_subscript(int arr[][N])
{
    int sum = 0, i, j;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            sum += arr[i][j];
        }
    }
    return sum;
}

// 一级指针法
int sum_array_pointer1(int arr[][N])
{
    int sum = 0, i, j;
    int* p = &arr[0][0];

    for (i = 0; i < M * N; i++)
    {
        sum += *p++;
    }
    return sum;
}

// 二级指针法
int sum_array_pointer2(int arr[][N])
{
    int sum = 0, i, j;
    int (*p)[N] = arr; // 指向一维数组的指针

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            sum += p[i][j];
        }
    }
    return sum;
}

// (8) 统计数字字符个数
void count_digits(char* str, int num[])
{
    int i;

    // 初始化计数器
    for (i = 0; i < 10; i++)
    {
        num[i] = 0;
    }

    // 统计数字字符
    for (i = 0; str[i]; i++)
    {
        if (isdigit(str[i]))
        {
            num[str[i] - '0']++;
        }
    }

    // 输出奇数字符出现的次数
    printf("奇数字符出现次数：\n");
    for (i = 1; i < 10; i += 2)
    {
        if (num[i] > 0)
        {
            printf("字符'%d'出现次数：%d\n", i, num[i]);
        }
    }
}

// (9) 字符串排序
void sort(char* str_array[], int n)
{
    int i, j;
    char* temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (strcmp(str_array[j], str_array[j + 1]) > 0)
            {
                temp = str_array[j];
                str_array[j] = str_array[j + 1];
                str_array[j + 1] = temp;
            }
        }
    }
}

// (10) 提取字符串中的整数
int extract_integers(char* str, int a[])
{
    int count = 0, i = 0, num = 0, in_number = 0;

    while (str[i])
    {
        if (isdigit(str[i]))
        {
            if (!in_number)
            {
                in_number = 1;
                num = 0;
            }
            num = num * 10 + (str[i] - '0');
        }
        else
        {
            if (in_number)
            {
                a[count++] = num;
                in_number = 0;
            }
        }
        i++;
    }

    // 处理字符串末尾的数字
    if (in_number)
    {
        a[count++] = num;
    }

    return count;
}

 //测试函数
int main()
{
    int choice;
    printf("请选择题号(1-10): ");
    scanf("%d", &choice);
    getchar(); // 清除输入缓冲区

    switch (choice)
    {
    case 1:
    {
        // 测试字符串比较
        char str1[MAX_LEN], str2[MAX_LEN];
        printf("输入第一个字符串: ");
        fgets(str1, MAX_LEN, stdin);
        str1[strcspn(str1, "\n")] = 0; // 去除换行符

        printf("输入第二个字符串: ");
        fgets(str2, MAX_LEN, stdin);
        str2[strcspn(str2, "\n")] = 0;

        int result = cmpstr(str1, str2);
        if (result < 0) {
            printf("str1 < str2\n");
        }
        else if (result > 0) {
            printf("str1 > str2\n");
        }
        else {
            printf("str1 = str2\n");
        }
        break;
    }

    case 2:
    {
        // 测试数组逆序和平均值
        int arr[] = { 1, 2, 3, 4, 5 };
        int n = sizeof(arr) / sizeof(arr[0]);

        printf("原数组: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        float avg = reverse(arr, n);

        printf("逆序后: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n平均值: %.2f\n", avg);
        break;
    }

    case 3:
    {
        // 测试删除子字符串
        char str[MAX_LEN] = "abcde";
        int k, m;

        printf("原字符串: %s\n", str);
        printf("输入开始位置k和删除字符数m: ");
        scanf("%d %d", &k, &m);

        del_substr(str, k, m);
        printf("删除后: %s\n", str);
        break;
    }

    case 4:
    {
        // 测试删除指定字符
        char str[MAX_LEN] = "I love you!";
        char ch;

        printf("原字符串: %s\n", str);
        printf("输入要删除的字符: ");
        scanf("%c", &ch);

        del_Spechar(str, ch);
        printf("删除后: %s\n", str);
        break;
    }

    case 5:
    {
        // 测试二维数组最大值
        int a[M][N] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
        int max_val, max_row, max_col;

        find_max_2d(a, &max_val, &max_row, &max_col);
        printf("最大元素值: %d\n", max_val);
        printf("位置: 第%d行, 第%d列\n", max_row + 1, max_col + 1);
        break;
    }

    case 6:
    {
        // 测试字符查找
        char str[MAX_LEN] = "Hello, World!";
        char ch;
        int pos;

        printf("字符串: %s\n", str);
        printf("输入要查找的字符: ");
        scanf("%c", &ch);

        pos = lstrchar(str, ch);
        if (pos != -1)
        {
            printf("字符'%c'首次出现在位置: %d\n", ch, pos);
        }
        else
        {
            printf("未找到字符'%c'\n", ch);
        }
        break;
    }

    case 7:
    {
        // 测试数组求和的三种方法
        int arr[M][N] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

        printf("数组元素:\n");

        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }

        printf("数组下标法求和: %d\n", sum_array_subscript(arr));
        printf("一级指针法求和: %d\n", sum_array_pointer1(arr));
        printf("二级指针法求和: %d\n", sum_array_pointer2(arr));
        break;
    }

    case 8:
    {
        // 测试数字字符统计
        char str[MAX_LEN];
        int num[10];

        printf("输入一行数字字符: ");
        fgets(str, MAX_LEN, stdin);
        str[strcspn(str, "\n")] = 0;

        count_digits(str, num);
        break;
    }

    case 9:
    {
        // 测试字符串排序
        char* str_array[STR_COUNT];
        char temp[STR_COUNT][MAX_STR_LEN];

        printf("输入10个字符串:\n");

        for (int i = 0; i < STR_COUNT; i++)
        {
            printf("字符串%d: ", i + 1);
            fgets(temp[i], MAX_STR_LEN, stdin);
            temp[i][strcspn(temp[i], "\n")] = 0;
            str_array[i] = temp[i];
        }

        sort(str_array, STR_COUNT);

        printf("\n排序后的字符串:\n");

        for (int i = 0; i < STR_COUNT; i++)
        {
            printf("%s\n", str_array[i]);
        }
        break;
    }

    case 10:
    {
        // 测试整数提取
        char input[MAX_LEN] = "123a345bcd567";
        int a[MAX_LEN], count;

        printf("输入包含数字的字符串: ");
        fgets(input, MAX_LEN, stdin);
        input[strcspn(input, "\n")] = 0;

        count = extract_integers(input, a);

        printf("找到%d个整数:\n", count);

        for (int i = 0; i < count; i++)
        {
            printf("a[%d] = %d\n", i, a[i]);
        }
        break;
    }

    default:
        printf("无效选择!\n");
    }

    return 0;
}