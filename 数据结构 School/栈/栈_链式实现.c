#include <stdio.h>
#include <stdlib.h>
typedef int ElemType;
typedef struct StackNode
{
    ElemType data;
    struct StackNode *next;
} StackNode;
typedef struct
{
    StackNode *top; //栈顶指针
} LinkStack;
/*初始化链栈*/
void InitStack(LinkStack *s)
{
    s->top = NULL;
    printf("\n已经初始化链栈\n");
}
/*链栈置空*/
void setEmpty(LinkStack *s)
{
    s->top = NULL;
    printf("\n链栈被置空！\n");
}
/*入栈*/
void pushLstack(LinkStack *s, ElemType x)
{
    StackNode *p;
    p = (StackNode *)malloc(sizeof(StackNode));
    p->data = x;
    p->next = s->top; /*将未完成的代码补全,提示：此处添加一条语句*/
    s->top = p;
}
/*出栈*/
ElemType popLStack(LinkStack *s)
{
    ElemType x;
    StackNode *p;
    p = s->top;
    if (s->top == 0)
    {
        printf("\n栈空，不能出栈！\n");
        return 0;
    }
    x = p->data;
    printf("\n当前出栈的数据是：%d", x);
    s->top = p->next;
    free(p);
    return x;
}
/*取栈顶元素*/
ElemType StackTop(LinkStack *s)
{
    ElemType x;
    if (s->top == 0)
    {
        printf("\n链栈空!\n");
        return 0;
    }
    {
        x = s->top->data; /*将未完成的代码补全,提示：此处添加一条语句*/
        printf("\n\n当前链栈的栈顶元素为：%d\n", x);
        return (x);
    }
}
/*遍历链栈*/
void DisplayStack(LinkStack *s)
{
    printf("\n链栈中的数据为:\n");
    printf("============================\n");
    StackNode *p;
    p = s->top;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("============================\n");
}
int main(void)
{
    int i, n, a;
    LinkStack *s;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    int cord;
    printf("第一次使用必须初始化！\n");
    do
    {
        printf("\n----------主菜单---------\n");
        printf("---- -1   初始化链栈-----\n");
        printf("------2   入栈-----------\n");
        printf("------3   出栈-----------\n");
        printf("------4   取栈顶元素-----\n");
        printf("------5   置空链栈-------\n");
        printf("------6   结束程序运行---\n");
        printf("-------------------------\n");
        printf("请从菜单栏中选择（1,2,3,4,5,6）:");
        scanf("%d", &cord);
        printf("\n");
        switch (cord)
        {
        case 1:
            InitStack(s);
            DisplayStack(s);
            break;
        case 2:
            printf("请输入将要压入链栈的数据个数:n=");
            scanf("%d", &n);
            printf("依次将%d个数据压入链栈:\n", n);
            for (i = 1; i <= n; i++)
            {
                scanf("%d", &a);
                pushLstack(s, a);
            }
            DisplayStack(s);
            break;
        case 3:
            popLStack(s);
            DisplayStack(s);
            break;
        case 4:
            StackTop(s);
            printf("\n");
            break;
        case 5:
            setEmpty(s);
            DisplayStack(s);
            break;
        case 6:
            exit(0);
        }
    } while (cord <= 6);

    return 0;
}
