/* 从键盘输入一个字符串，然后按照下面要求输出一个新字符串。
新串是在原串中，每两个字符之间插入一个空格，如原串为 abed, 则新串为 a b c d。
要求在函数insert中完成新串的产生; 并在函数中完成所有相应的输入和输出。*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 50

char *input_s(void);
void *insert(char *s);
void output(char *s);

int main(void)
{
    char *str;
    char *str_new;

    str = input_s();
    str_new = insert(str);
    output(str_new);
    free(str_new);

    return 0;
}

void *insert(char *s)
{
    int s_len = strlen(s);
    char *s_new = (char *)malloc(2 * s_len * sizeof(char)); //malloc()可以使不必在主函数声明字符串数组

    char *s_new_begin = s_new;
    for (int i = 0; i < s_len; i++)
    {
        *s_new++ = *s++;
        *s_new++ = ' ';
    }
    *s_new-- = '\0';     //将被空格覆盖的 \0 重新赋值回来
    s_new = s_new_begin; //将 s_new 指针指回去，可有可无，无用 s_new_begin 替代，等效

    return s_new; //返回新字符串首字符指针
}

char *input_s(void)
{
    static char s[SIZE];

    printf("Enter a string:");
    scanf("%s", &s);

    return s;
}

void output(char *s)
{
    puts(s);
}