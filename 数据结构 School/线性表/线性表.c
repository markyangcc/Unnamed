<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
typedef int ElemType; //数据元素的类型
typedef struct
{
    ElemType a[MAXSIZE];
    int length;
} SqList; //顺序存储的结构体类型

SqList a; //函数声明

void creat_list(SqList *L);
void out_list(SqList L);
void insert_sq(SqList *L, int i, ElemType e);
ElemType delete_sq(SqList *L, int i);
int locat_sq(SqList L, ElemType e);

//主函数
int main(void)
{
    int i, k, loc;
    ElemType e, x;
    char ch;
    do
    {
        printf("\n\n\n");
        printf("\n          1.建立线性表");
        printf("\n          2.插入元素");
        printf("\n          3.删除元素");
        printf("\n          4.查找元素");
        printf("\n          0.结束程序运行");
        printf("\n          =====================");
        printf("\n          请输入要执行的操作:  ");
        scanf("%d", &k);
        switch (k)
        {
        case 1:
        {
            creat_list(&a);
            out_list(a);
        }
        break;
        case 2:
        {
            printf("\n请输入插入位置： ", a.length + 1);
            scanf("%d", &i);
            printf("请输入要插入的元素值： ");
            scanf("%d", &e);
            insert_sq(&a, i, e);
            out_list(a);
        }
        break;
        case 3:
        {
            printf("\n请输入要删除元素的位置： ", a.length);
            scanf("%d", &i);
            x = delete_sq(&a, i);

            if (x != -1)
                printf("\n删除的元素为：%d\n", x);
            else
                printf("要删除的元素不存在！");
            out_list(a);
        }
        break;
        case 4:
        {
            printf("\n请输入要查找的元素值：");
            scanf("%d", &e);
            loc = locat_sq(a, e);
            out_list(a);
            if (loc == -1)
                printf("\n未找到指定元素！");
            else
                printf("\n已找到，元素的位置是: %d ", loc);
        }
        break;
        } /*switch*/
    } while (k != 0);
    printf("\n              按回车键，返回...\n");
    ch = getchar();

    return 0;
} /*main*/

//建立线性表
void creat_list(SqList *L)
{
    int i;
    printf("请输入线性表的长度: ");
    scanf("%d", &L->length);
    for (i = 0; i < L->length; i++)
    {
        printf("数据 %d =", i);
        scanf("%d", &(L->a[i]));
    }
}
//输出线性表
void out_list(SqList L)
{
    int i;
    for (i = 0; i <= L.length - 1; i++)
        printf("%10d", L.a[i]);
}

//在线性表的第i个位置插入元素e
void insert_sq(SqList *L, int i, ElemType e)
{
    int j;
    if (L->length == MAXSIZE)
        printf("线性表已满!\n");
    else
    {
        if (i < 1 || i > L->length + 1)
            printf("输入位置错!\n");
        else
        {
            for (j = L->length - 1; j >= i - 1; j--)
                L->a[j + 1] = L->a[j];
            L->a[i] = e; /*将未完成的代码补全,提示：此处添加一条语句，将被删除的元素值赋给e*/
            L->length++;
        }
    }
}

//删除第i个元素，返回其值
ElemType delete_sq(SqList *L, int i)
{
    ElemType x;
    int j;
    if (L->length == 0)
        printf("空表!\n");
    else if (i < 1 || i > L->length)
    {
        printf("输入位置错！\n");
        x = -1;
    }
    else
    {
        x = L->a[i - 1];
        for (j = i; j <= L->length - 1; j++)
            L->a[j] = L->a[j + 1]; /*将未完成的代码补全,提示：此处添加一条语句，将被删除元素之后的元素左移。*/
        L->length--;
    }
    return (x);
}

//查找值为e的元素，返回它的位置
int locat_sq(SqList L, ElemType e)
{
    int i = 0;
    while (L.a[i] != e)
        i++;
    if (i <= L.length - 1)
        return (i + 1);
}
=======
// 线性表的顺序存储结构的操作实现
#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;       //定义元素类型
struct List                //定义单链表结点类型
{
    ElemType *list;//存储空间基址
    int size;      //当前长度
    int MaxSize;   //当前分配的存储容量，即存储线性表的最大长度
};
 
//1、初始化线性表L，即进行动态存储空间分配并置L为一个空表
void InitList(struct List *L, int ms)
{
    if (ms < 0) //检查ms是否有效
    {
        printf("ms值非法！\n");
        exit(1);
    }
    L->MaxSize = ms; //置线性表初始存储容量为ms
    L->list = (ElemType *)malloc(ms*sizeof(ElemType)); //动态存储空间分配
    if (!L->list)
    {
        printf("动态存储分配失败！\n");
        exit(1);
    }
    L->size = 0; //初始置线性表为空
}
 
//2、清除线性表L中的所有元素，释放动态存储空间，使之成为一个空表
void ClearList(struct List *L)
{
    if (L->list != NULL)
    {
        free(L->list);
        L->list = 0;
        L->size = L->MaxSize = 0;
    }
}
 
//3、返回线性表L的长度，若L为空则返回0
int SizeList(struct List *L)
{
    return L->size;
}
 
//4、判断线性表L是否为空，若为空则返回1，否则返回0
int EmptyList(struct List *L)
{
    if (L->size == 0)
        return 1;
    else
        return 0;
}
 
//5、返回线性表L中第pos个元素的值，若pos超出范围，则停止程序运行
ElemType GetElem(struct List *L, int pos)
{
    if (pos < 1 || pos > L->size)
    {
        printf("元素序号越界！\n");
        exit(1);
    }
    return L->list[pos - 1];
}
 
//6、顺序扫描（即遍历）输出线性表L中的每个元素
void TraverseList(struct List *L)
{
    int i;
    for (i = 0; i < L->size; i++)
        printf("%d,", L->list[i]);
    printf("\n");
}
 
//7、从线性表L中查找值与x相等的元素（第一个），若查找成功则返回其位置（下标），否则返回-1
int FindList(struct List *L, ElemType x)
{
    int i;
    for (i = 0; i < L->size; i++) //此处类型ElemType为整型，当为字符串类型（char *）时，
        if (L->list[i] == x)      //if语句应改为: if (strcmp(L->list[i], x) == 0)
            return i;
    return -1;
}
 
//8、把线性表L中第pos个元素的值修改为x的值，若修改成功返回1，否则返回0
int UpdatePosList(struct List *L, int pos, ElemType x)
{
    if (pos < 1 || pos > L->size)  //若pos越界则修改失败
        return 0;
    L->list[pos - 1] = x;
    return 1;
}
 
//9、向线性表L的表头插入元素x
//此时需要考虑到线性表存储空间已满的情况，则需要重新分配更大的动态存储空间，具体实现如下：
void againMalloc(struct List *L)
{
    ElemType *p = realloc(L->list, 2*L->MaxSize*sizeof(ElemType));//此处重新分配的空间为原来的2倍
    if (!p)  //重新分配失败
    {
        printf("存储空间用完！\n");
        exit(1);
    }
    L->list = p;             //使list指向新线性表空间
    L->MaxSize = 2 * L->MaxSize;
    printf("存储空间已扩大为当前的2倍！\n");//输出提示已扩充空间
}
 
void InserFirstList(struct List *L, ElemType x) //表头插入元素
{
    int i;
    if (L->size == L->MaxSize) //存储空间已满
        againMalloc(L);        //重新分配更大空间
    for (i = L->size - 1; i >= 0; i--)
        L->list[i + 1] = L->list[i];
    L->list[0] = x;
    L->size++;
}
 
//10、向线性表L的表尾插入元素x
void InsertLastList(struct List *L, ElemType x)
{
    if (L->size == L->MaxSize)
        againMalloc(L);
    L->list[L->size] = x;
    L->size++;
}
 
//11、向线性表L中第pos个元素位置插入元素x，若插入成功返回1，否则返回0
int InsertPosList(struct List *L, int pos, ElemType x)
{
    int i;
    if (pos < 1 || pos > L->size + 1) //pos的合法位置是第一位到最后一位的后一位之间
        return 0;
    if (L->size == L-> MaxSize)
        againMalloc(L);
    for (i = L->size - 1; i >= pos - 1; i--)
        L->list[i + 1] = L->list[i];
    L->list[pos - 1] = x;
    L->size++;
    return 1;
}
 
//12、向有序（递增）线性表L中插入元素x，使得插入后仍然有序
void InsertOrderList(struct List *L, ElemType x)
{
    int i, j;
    if (L->size == L->MaxSize)
        againMalloc(L);
    for (i = 0; i < L->size; i++)
        if (x < L->list[i])
            break;   //此时i的值即为要插入的位置。若x比所有元素都大，则i自增后的值为size，下面的for循环不执行。
    for (j = L->size - 1; j >= i; j--)
        L->list[j + 1] = L->list[j];
    L->list[i] = x;
    L->size++;
}
 
//13、从线性表L中删除表头元素并返回它，若删除失败则停止程序运行
ElemType DeleteFirstList(struct List *L)
{
    ElemType temp; //临时变量，用于存储表头元素
    int i;
    if (L->size == 0)
    {
        printf("线性表为空，不能删除！\n");
        exit(1);
    }
    temp = L->list[0];
    for (i = 1; i < L->size; i++)
        L->list[i - 1] = L->list[i];
    L->size--;
    return temp;
}
 
//14、从线性表L中删除表尾元素并返回它，若删除失败则停止程序运行
ElemType DeleteLastList(struct List *L)
{
    if (L->size == 0)
    {
        printf("线性表为空，不能删除！\n");
        exit(1);
    }
    L->size--;
    return L->list[L->size];
}
 
//15、从线性表L中删除第pos个元素并返回它，若删除失败则停止程序运行
ElemType DeletePosList(struct List *L, int pos)
{
    ElemType temp;
    int i; 
    if (pos < 1 || pos > L->size)
    {
        printf("pos值越界，不能删除！\n");
        exit(1);
    }
    temp = L->list[pos - 1];
    for (i = pos; i < L->size; i++)
        L->list[i - 1] = L->list[i];
    L->size--;
    return temp;
}
 
//16、从线性表L中删除值为x的第一个元素，若删除成功返回1否则返回0
int DeleteValueList(struct List *L, ElemType x)
{
    int i, j;
    for (i = 0; i < L->size; i++)
        if (L->list[i] == x)
            break; //此时的i即是要删除的位置,
    if (i == L->size)//若找不到，上面的i自增后为size
        return 0;
    for (j = i + 1; j < L->size; j++)
        L->list[j - 1] = L->list[j];
    L->size--;
    return 1;
}
 
 
//主函数
void main()
{
    int a[10] = {2,4,6,8,10,12,14,16,18,20};
    int i;
    struct List L;
    InitList(&L, 5);                 //初始化分配线性表空间为5
    for (i = 0; i < 10; i++)
        InsertLastList(&L, a[i]);    //将数组中的元素依次插入线性表（空间不够，扩大2倍）
    InsertPosList(&L, 11, 48);       //在第11位插入48（空间不够，再次扩大2倍）
    InsertPosList(&L, 1, 64);        //在第1位插入64
    printf("%d\n", GetElem(&L, 4));  //输出第4个元素
    TraverseList(&L);                //遍历输出所有元素
    printf("%d\n", FindList(&L, 10));//查找输出数值为10的元素位置（下标）
    UpdatePosList(&L, 3, 20);        //把第三个元素修改为20
    DeleteFirstList(&L);             //删除表头元素
    DeleteFirstList(&L);
    DeleteLastList(&L);              //删除表尾元素
    DeleteLastList(&L);
    DeletePosList(&L, 5);            //删除第5个元素
    DeletePosList(&L, 7);            //删除第7个元素
    printf("%d\n", SizeList(&L));    //输出线性表长度
    printf("%d\n", EmptyList(&L));   //判断线性表是否为空
    TraverseList(&L);                //遍历输出所有元素
    ClearList(&L);                   //清空线性表，释放空间
}

>>>>>>> b349c10e8b25168a05b1b7d7920d08b4ada0c3c8
