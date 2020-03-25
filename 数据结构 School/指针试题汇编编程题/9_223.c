/* 通过指针数组p 和一维数组a 构成一个3x2 的二维数组；并为a 数组赋初
值2、4、6、8、…。要求先按行的顺序输出此“二维数组”；然后再按列的顺序输
出它。试编程。 */

#include <stdio.h>

int main(void)
{
    //int *p[3]; //元素是3个指针，准备用它分别来指二维数组的3个元素
    int a[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};

    int array[3][2];

    for (int i = 0; i < 3; i++) //一维数组转二维数组，
    {                           //说实话没懂题目什么意思，我猜是这个意思
        for (int j = 0; j < 2; j++)
            array[i][j] = a[i * 3 + j];
    }

    printf("按行输出:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%-3d", *((*array + i) + j));

        printf("\n");
    }

    printf("按列输出:\n");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
            printf("%-3d", *((*array + j) + i));

        printf("\n");
    }

    return 0;
}
