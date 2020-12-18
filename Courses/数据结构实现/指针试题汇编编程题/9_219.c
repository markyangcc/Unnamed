/* 编一程序，将字符串中的第m个字符开始的全部字符复制成另一 个字符串。
要求在主函数中输入字符串及m的值并输出复制结果，在被调用函数中完成复制。 */

#include <stdio.h>
#include <stdlib.h>
#define SIZE 50

void *copy_n_string(char *s, int n, char *s_2);

int main(void)
{
    char str[SIZE];
    char str_2[SIZE];
    int num;

    printf("输入一个字符串:");
    fgets(str, SIZE, stdin);
    printf("输入一个数字告诉我从哪里开始复制:");
    if (scanf("%d", &num) != 1 || num < 1) //输入验证
    {
        puts("Error, 非法输入");
        exit(EXIT_FAILURE);
    }

    copy_n_string(str, num, str_2);

    printf("输出如下:");
    fputs(str_2, stdout);

    return 0;
}

void *copy_n_string(char *s, int n, char *s_2)
{
    for (int i = 0; i < n - 1; i++)
        *s++;

    while (*s != '\0') //开始复制字符串
        *s_2++ = *s++;
}