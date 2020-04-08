#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LEN sizeof(LNode) //定义LEN为一个节点的长度

typedef struct node
{
    char data;         //数据域
    struct node *next; //指向下一个节点的指针
} LNode, *LinkList;

void CreatList(LinkList, int);                //生成一个单链表
bool ListInsert(LinkList, int, char);         //在单链表中插入一个元素
bool ListDelete(LinkList, int, char *);       //在单链表中删除一个元素
bool ListFind_keyword(LinkList, char, int *); //按关键字查找一个元素
bool ListFind_order(LinkList, char *, int);   //按序号查找一个元素
void ListPrint(LinkList);                     //显示单链表所有元素

int main(void)
{

    LinkList L = (LinkList)malloc(LEN);
    bool temp;
    int num, loc, flag = true;
    char j, ch;

    //---------------------程序解说-----------------------
    printf("本程序实现链式结构的线性表的操作。\n");
    printf("可以进行插入，删除，定位，查找等操作。\n");
    //----------------------------------------------------
    printf("请输入初始时链表长度:"); //输入生成单链表时的元素个数
    scanf("%d", &num);

    while (getchar() != '\n')
        continue;

    CreatList(L, num); //生成单链表
    ListPrint(L);

    while (flag)
    {
        printf("请选择:\n");
        printf("1.显示所有元素\n");     //显示链表元素
        printf("2.插入一个元素\n");     //插入链表元素
        printf("3.删除一个元素\n");     //删除链表元素
        printf("4.按关键字查找元素\n"); //按关键字查找
        printf("5.按序号查找元素\n");   //按序号查找
        printf("6.退出程序      \n");   //退出
        scanf("%c", &j);
        while (getchar() != '\n')
            continue;

        switch (j)
        {
        case '1':
            ListPrint(L);
            break;
        case '2':
        {
            printf("请输入元素(一个字符)和要插入的位置:\n");
            printf("格式:字符，位置；例如:a,3\n");
            scanf("%c,%d", &ch, &loc); //输入要插入的元素和要插入的位置

            while (getchar() != '\n')
                continue;

            temp = ListInsert(L, loc, ch); //插入
            if (temp == false)
                printf("插入失败!\n"); //插入失败
            else
                printf("插入成功!\n"); //成功插入
            ListPrint(L);
            break;
        }
        case '3':
            printf("请输入要删除的元素所在位置:");
            scanf("%d", &loc); //输入要删除的节点的位置

            while (getchar() != '\n')
                continue;

            temp = ListDelete(L, loc, &ch); //删除
            if (temp == false)
                printf("删除失败!\n"); //删除失败
            else
                printf("成功删除了一个元素:%c\n", ch); //删除成功，显示该元素
            ListPrint(L);
            break;

        case '4':
            if (L->next == NULL) //链表为空
                printf("链表为空!\n");
            else
            {
                printf("请输入要查找的元素:");
                scanf("%c", &ch); //输入要查找的元素

                while (getchar() != '\n')
                    continue;

                temp = ListFind_keyword(L, ch, &loc); //按关键字查找
                if (temp == false)
                    printf("没有找到该元素!\n"); //查找失败
                else
                    printf("该元素在链表的第%d个位置。\n", loc);
                //成功查找，显示该元素位置
            }
            ListPrint(L);
            break;
        case '5':
            if (L->next == NULL) //链表为空
                printf("链表为空!\n");
            else
            {
                printf("请输入要查找的位置:");
                scanf("%d", &loc); //输入要查找的元素的位置

                while (getchar() != '\n')
                    continue;

                temp = ListFind_order(L, &ch, loc); //按序号查找
                if (temp == false)
                    printf("该位置不存在!\n"); //查找失败
                else
                    printf("第%d个元素是：%c\n", loc, ch);
                //成功查找，显示该元素
            }
            ListPrint(L);
            break;
        case '6':
            flag = false;
            printf("程序结束，按任意键退出!\n");
            break;
        default:
            flag = false;
            printf("非法输入，程序退出\n");
        }
    }

    return 0;
}

void CreatList(LinkList v, int n)
{ //生成一个带头结点的有n个元素的单链表
    int i;
    LinkList p;
    v->next = NULL;

    printf("请输入%d个字符：例如：abcdefg\n", n);

    for (i = n; i > 0; --i)
    {
        p = (LinkList)malloc(LEN); //生成新结点
        scanf("%c", &(p->data));

        p->next = v->next; //将未完成的代码补全,此处添加一条代码
        v->next = p;
    }
    while (getchar() != '\n')
        continue;
}
bool ListInsert(LinkList v, int i, char e)
{ //在单链表的第i各位置插入元素e，成功返回True，失败返回False
    LinkList p, s;
    int j = 0;
    p = v;
    while (p && j < i - 1)
    {
        p = p->next;
        ++j;
    } //查找第i-1个元素的位置
    if (!p || j > i - 1)
        return false;          //没有找到
    s = (LinkList)malloc(LEN); //生成一个新结点
    s->data = e;
    s->next = p->next; //将未完成的代码补全,此处添加一条代码
                       //提示：将新结点插入到单链表中，即修改指针，完成插入操作
    p->next = s;
    return true;
}

bool ListDelete(LinkList v, int i, char *e)
{ //在单链表中删除第i个元素，成功删除返回True，并用e返回该元素值，失败返回False
    LinkList p, q;
    int j = 0;
    p = v;
    while (p->next && j < i - 1) //查找第i-1个元素位置
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i - 1)
        return false; //查找失败
    q = p->next;
    p->next = q->next; /*将未完成的代码补全,此处添加一条代码,提示：删除该元素*/
    *e = q->data;      /*将未完成的代码补全,此处添加一条代码,提示:e取得该元素值，即修改指针，删除结点q*/
    free(q);           //释放该元素空间
    return true;
}

bool ListFind_keyword(LinkList v, char e, int *i)
{ //在单链表中查找关键字为e的元素，成功返回true,并用i返回该元素位置，
    //失败返回False

    *i = 1;
    LinkList p;
    p = v->next;
    while ((p->data != e) && (p->next != NULL))
    {
        p = p->next; //p指针指向下一个，直到
        (*i)++;      //找到或到链表尾为止
    }
    if (p->data != e) //该元素在链表中不存在
        return false;
    else
    {
        return true;
    }
}

bool ListFind_order(LinkList v, char *e, int i)
{ //在单链表中查找第i个元素，成功返回true，并用e返回该元素值，
    //失败返回False
    LinkList p;
    int j = 0;
    p = v;
    while (j != i /* 将未完成的代码补全, 此处添加一条代码, 提示：移动指针，直到找到第i个元素 */)
    {
        p = p->next;
        ++j;
    }
    if (j != i)
        return false; //查找失败
    else
    {
        *e = p->data; //查找成功，用e取得该元素值
        return true;
    }
}
void ListPrint(LinkList v)
{ //显示链表所有元素
    LinkList q;
    q = v->next;
    printf("链表所有元素:");
    while (q != NULL)
    {
        printf("%c ", q->data);
        q = q->next;
    }
    printf("\n");
}
