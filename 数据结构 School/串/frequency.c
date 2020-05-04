/* 6-2 编写一个算法frequency，统计在一个输入字符串中各个不同字符出现的频度。用适当的测试数据来验证这个算法。 */
#include <stdio.h>
#include <string.h>

#define STRSIZE 100

char *s_gets(char *s, int n);
int *frequency(char *string);

int main(void)
{
    char string[STRSIZE];

    printf("输入一个字符串(回车结束): ");
    s_gets(string, STRSIZE);

    int *array = frequency(string);

    int sum = 0; //输入字符总数
    int k = 0;   //计数器
    while (string[k] != '\0')
    {
        sum++;
        k++;
    }

    for (int i = 0; i < '~' - '!'; i++)
        if (array[i] != 0)
            printf("%c 出现次数为 %d 次, 频度 = %4.2lf%%\n", i + '!', *(array + i), ((double)*(array + i) / sum) * 100); //uncontrolled characters printout
    return 0;
}

int *frequency(char *string)
{
    static int array['~' - '!'] = {0}; //must be initialized, or the memory will full of rubbish value

    char ch;
    int i = 0;

    while (string[i] != '\0')
    {
        if (string[i] >= '!' && string[i] <= 'z')
            array[string[i] - '!']++;

        i++;
    }

    return array;
}

char *s_gets(char *s, int n)
{
    char *ret_val;
    int i = 0;

    ret_val = fgets(s, n, stdin);
    if (ret_val)
    {
        while (s[i] != '\n' && s[i] != '\0')
            s++;
        if (s[i] == '\n')
            s[i] = '\0';
        else
        {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}
