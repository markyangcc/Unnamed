/*编写一程序，将字符串computer赋值给一个字符数组，
然后从第一个字母开始间隔地输出该串。请用指针完成。 */

#include <stdio.h>
#include <string.h>

void print_each_character(char *s, int len);
int main(void)
{
    char str[] = "computer";
    int size = strlen(str);
    print_each_character(str, size);

    return 0;
}

void print_each_character(char *s, int len)
{
    for (int i = 0; i < len; i++)
        printf("%c  ", *s++);
}