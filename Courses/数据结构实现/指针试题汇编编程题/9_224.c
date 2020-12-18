/* 有 4 名学生，每个学生考 4 门课程，要求在用户输入学生序号以后能输出该生的全部成绩，用指针型函数来实现。
请编写函数float* search()。
main()
{
    static float score[][4] = {{60, 70, 80, 90}, {50, 89, 67, 88}, {34, 78, 90, 66}, {80, 90, 100, 70}};
    float *search(), *p;
    int i, m;
    printf("enter the number of student:");
    scanf("%d", &m);
    printf("The score of No. %cl are:\n", m);
    p = search(score, m);
    for (i = 0; i < 4; i++)
        print£("% 5. 2£\t", *(p + i));
}
float *search(float (*pointer)[4], int n)
{
}
*/
#include <stdio.h>

float *search(float (*pointer)[4], int n);

int main(void)
{
    static float score[][4] = {{60, 70, 80, 90}, {50, 89, 67, 88}, {34, 78, 90, 66}, {80, 90, 100, 70}};
    float *p;
    int i, m;

    printf("Enter the number of student:");
    scanf("%d", &m);
    printf("The score of No. %cl are:\n", m);

    p = search(score, m);

    for (i = 0; i < 4; i++)
        printf("%5.2f\t", *(p + i));

    return 0;
}
float *search(float (*pointer)[4], int n)
{
    pointer = (pointer + n - 1); //pointer +1 移动的是4个大小

    return *pointer;
}