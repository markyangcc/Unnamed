/* 下面findmax函数将计算数组中的最大元素及其下标值和地址值，请编写
*findmax()函数。

#include <stdio.h>
*findmax(int *s, int t, int *k);
main()
{
    int a[lO] = {12, 23, 34, 45, 56, 67, 78, 89, ll, 22}, k, *add;
    add == findmax(a, 10, &k);
    printf("%cl, %d, %p \n" a[k], k, add);
}
 */
#include <stdio.h>

void *findmax(int *s, int t, int *k);

int main(void)
{
    int a[10] = {12, 23, 34, 45, 56, 67, 78, 89, 11, 22};

    int k, *add;
    add = findmax(a, 10, &k);
    printf("%d, %d, %p \n", a[k], k, add);
}
void *findmax(int *s, int t, int *k)
{
    int *s_begin = s;
    int max = 0;
    int j;

    for (int i = 0; i < t; i++)
    {
        if (*s > max)
            max = *s++;
    }
    s = s_begin;
    
    for (j = 0; j < t; j++)
    {
        if (*(s + j) == max)
        {
            *k = j;
            break;
        }
    }
    return s + j;
}
