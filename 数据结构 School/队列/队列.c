#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

typedef struct tick
{
    char name[10];
    char first[10];
    char dist[10];
    char time[10];
    char flay[10];
    //  int rear, front;
} tickdef;

tickdef q[MAX + 1];

int rear, front;
int count;

void enqueue();
void dequeue();
void clear();
void good_bye();
int menu_select();

void clear()
{
}
void good_bye()
{
    clear();
}

int menu_select()
{
    char c;
    int n;
    clear();

    printf("机票预售系统程序主控模块:\n\n\n");
    printf("\t\t 1.  买票登记 \n");
    printf("\t\t 2.  删除登记 \n");
    printf("\t\t 0.  退    出 \n");
    do
    {
        printf("\n\t\t请按数字0-2键选择功能:");
        c = getchar();
        n = c - 48;
    } while ((n < 0) || (n > 2));
    return (n);
}

void enqueue() //入队操作
{
    char s1[10], s2[10], s3[10], s4[10], s5[10];
    if (rear == MAX)
        rear = 1;
    else if (((rear + 1) % MAX) == front)
    {
        printf("队列溢出错误\n");
        getchar();
        exit(0);
    }
    else
    {
        rear = rear + 1; /*将未完成的代码补全,提示：此处添加一条语句*/
        printf("\n\n\t\t请登记所买机票信息:\n");
        printf("\n\t\t请输入旅客姓名:");
        scanf("%s", s1);
        printf("\n\t\t请输入起飞地点:");
        scanf("%s", s2);
        printf("\n\t\t请输入飞往地点:");
        scanf("%s", s3);
        printf("\n\t\t请输入起飞时间:");
        scanf("%s", s4);
        printf("\n\t\t请输入航班代号:");
        scanf("%s", s5);
        strcpy(q[rear].name, s1);
        strcpy(q[rear].first, s2);
        strcpy(q[rear].dist, s3);
        strcpy(q[rear].time, s4);
        strcpy(q[rear].flay, s5);
    }
}

void dequeue() //删除机票登记信息即出队操作
{
    if (rear == front)
    {
        printf("\n\t\t队列已空，操作错误\n");
        getchar();
        exit(0);
    }
    else
    {
        front = front + 1; /*将未完成的代码补全,提示：此处添加一条语句*/
        printf("\n\n\t\t删除机票登记:\n\n\t\t");
        printf("旅客姓名:%s\n\t\t", q[front].name);
        printf("旅客姓名:%s\n\t\t", q[front].first);
        printf("起飞地点:%s\n\t\t", q[front].dist);
        printf("飞往地点:%s\n\t\t", q[front].time);
        printf("起飞时间:%s\n\t\t", q[front].flay);
    }
    getchar();
}

void main()
{
    int kk;
    rear = 0;
    front = 0;
    do
    {
        kk = menu_select();
        switch (kk)
        {
        case 1:
            enqueue();
            count = rear;
            for (int i = 1; i <= count; i++)
                printf("%s\t%s\t%s\t%s\t%s\n", q[i].name, q[i].first, q[i].dist, q[i].time, q[i].first);
            break;
        case 2:
            dequeue();
            for (int i = front + 1; i <= count; i++)
                printf("%s\t%s\t%s\t%s\t%s\n", q[i].name, q[i].first, q[i].dist, q[i].time, q[i].first);

            break;
        case 0:
            good_bye();
            exit(0);
        default:
            printf("非法输入\n");
            exit(0);
        }
        getchar();
        getchar();
    } while (kk != 0);
}
