/* 设有一数列，包含 10 个数，已按升序排好。现要求编一程序，
它能够把从指定位置开始的n个数按逆序重新排列并输出新的完整数列。
进行逆序处理时要求使用指针方法。试编程。（例如：原数列为 2,4,6,8,10,12,14,16,18, 20，
若要求把从第4个数开始的5个数按逆序重新排列，则得到新数列为 2,4,6,16,14,12,10,8,18,20) */

#include <stdio.h>

void resortarray(int *arr, int p, int n);

int main(void)
{
    int array[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int position, num;
    int array_len;

    printf("Enter two integer(Separate with blankspace),\n"
           "the first to inform the position,\n"
           "the second to inform how many numbers to resort in reverse order:");
    if (scanf("%d %d", &position, &num) != 2) //输入验证
    {
        puts("Error,invalid input.");
        return 0;
    }
    array_len = sizeof(array) / sizeof(int);

    if (position > array_len || num > array_len || (position + num - 1) > array_len) //输入验证
    {
        puts("Error, overflow, operand exceeds array range.");
        return 0;
    }

    printf("\nBefore:\n");
    for (int i = 0; i < 10; i++) //打印未排序时序列
        printf("%d ", array[i]);

    resortarray(array, position, num);

    printf("\nAfter sorted:\n"); //打印排序后序列
    for (int i = 0; i < 10; i++)
        printf("%d ", array[i]);

    return 0;
}

void resortarray(int *arr, int p, int n)
{
    int *begin = (arr + p - 1); // 获取开始排序初始位置
    int temp;

    for (int i = 0; i < n - 1; i++) // Bubble sort
    {
        for (int j = i + 1; j < n; j++)
        {
            if (*(begin + i) < *(begin + j))
            {
                temp = *(begin + i);
                *(begin + i) = *(begin + j);
                *(begin + j) = temp;
            }
        }
    }
}
