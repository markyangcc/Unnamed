
/* Implementation of stack using Array in C */

#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 20
#define ElemType int

typedef struct
{
    ElemType stack[MAXNUM];
    int top;
} SqStack;

/*初始化顺序栈*/
void InitStack(SqStack *p)
{
    if (!p)
        printf("内存分配失败！");
    p->top = -1;
}

/*入栈*/
void Push(SqStack *p, ElemType x)
{
    if (p->top < MAXNUM - 1)
    {
        p->top = p->top + 1;
        p->stack[p->top] = x;
    }
    else
        printf("Overflow!\n");
}

/*出栈*/
ElemType Pop(SqStack *p)
{
    ElemType x;
    if (p->top >= 0)
    {
        x = p->stack[p->top]; /*将未完成的代码补全,提示：此处添加一条语句*/
        printf("之前的栈顶数据元素 %d 已经被删除\n", p->stack[p->top]);
        p->top = p->top - 1;
        return (x);
    }
    else
    {
        printf("Underflow!\n");
        return 0;
    }
}

/*取栈顶元素*/
ElemType GetTop(SqStack *p)
{
    ElemType x;
    if (p->top >= 0)
    {
        x = p->stack[p->top]; /*将未完成的代码补全,提示：此处添加一条语句*/
        printf("\n栈顶元素为:%d\n", x);
        return (x);
    }
    else
    {
        printf("Underflow!\n");
        return (0);
    }
}

/*遍历顺序表*/
void DisplayStack(SqStack *p)
{
    int i;
    printf("\n");
    if (p->top < 0)
        printf("这是一个空栈！");
    printf("\n");
    for (i = p->top; i >= 0; i--)
        printf("第 %d 个元数据元素为：%d\n", i, p->stack[i]);
}

/*置空顺序表*/
void setEmpty(SqStack *p)
{
    p->top = -1;
}
int main(void)
{
    SqStack *q;
    int cord;
    ElemType a;
    printf("第一次使用必须初始化！\n");
    do
    {
        printf("\n-----------------------主菜单------------------\n");
        printf("----------------1   初始化顺序栈---------------\n");
        printf("----------------2   插入一个元素---------------\n");
        printf("----------------3   删除栈顶元素---------------\n");
        printf("----------------4   取栈顶元素-----------------\n");
        printf("----------------5   置空顺序栈-----------------\n");
        printf("----------------6   结束程序运行---------------\n");
        printf("-----------------------------------------------\n");
        printf("请从菜单栏中选择（1,2,3,4,5,6）:");
        scanf("%d", &cord);
        printf("\n");
        switch (cord)
        {
        case 1:
            q = (SqStack *)malloc(sizeof(SqStack));
            InitStack(q);
            DisplayStack(q);
            break;
        case 2:
            printf("请输入要插入的数据元素:a=");
            scanf("%d", &a);
            Push(q, a);
            DisplayStack(q);
            break;
        case 3:
            Pop(q);
            DisplayStack(q);
            break;
        case 4:
            GetTop(q);
            DisplayStack(q);
            break;
        case 5:
            setEmpty(q);
            printf("\n顺序栈被置空!\n");
            DisplayStack(q);
            break;
        case 6:
            exit(0);
        }
    } while (cord <= 6);

    return 0;
}
