#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BiTNode //定义二叉树节点结构
{
    char data;                       //数据域
    struct BiTNode *lchild, *rchild; //左右孩子指针域
} BiTNode, *BiTree;

void CreateBiTree(BiTree); //生成一个二叉树
void PreOrder(BiTree);     //先序递归遍历二叉树
void InOrder(BiTree);      //中序递归遍历二叉树
void PostOrder(BiTree);    //后序递归遍历二叉树

int main(void)
{
    BiTree T;
    char ch, j;
    int flag = 1;
    bool temp;
    //---------------------程序解说-----------------------
    printf("本程序实现二叉树的操作。\n");
    printf("可以进行建立二叉树，递归先序、中序、后序遍历等操作。\n");
    //----------------------------------------------------
    printf("请将先序遍历二叉树的结果输入以建立二叉树。\n");
    printf("对于叶子结点以空格表示。\n");
    printf("例如:abc  de g  f   (回车)，建立如下二叉树：\n");
    printf("           a      \n");
    printf("          /       \n");
    printf("         b        \n");
    printf("        / \\       \n");
    printf("       c   d      \n");
    printf("          / \\     \n");
    printf("         e   f    \n");
    printf("          \\       \n");
    printf("           g      \n");

    CreateBiTree(T); //初始化队列

    while (getchar() != '\n')
        continue;

    while (flag)
    {
        printf("请选择: \n");
        printf("1.递归先序遍历\n");
        printf("2.递归中序遍历\n");
        printf("3.递归后序遍历\n");
        printf("4.退出程序\n");

        scanf("%c", &j);

        switch (j)
        {
        case '1':
            if (T)
            {
                printf("先序遍历二叉树:");
                PreOrder(T);
                printf("\n");
            }
            else
                printf("二叉树为空!\n");
            break;
        case '2':
            if (T)
            {
                printf("中序遍历二叉树:");
                InOrder(T);
                printf("\n");
            }
            else
                printf("二叉树为空!\n");
            break;
        case '3':
            if (T)
            {
                printf("后序遍历二叉树:");
                PostOrder(T);
                printf("\n");
            }
            else
                printf("二叉树为空!\n");
            break;
        default:
            flag = 0;
            printf("程序运行结束，按任意键退出!\n");
        }
    }
    getchar();
}

void CreateBiTree(BiTree T)
{
    char ch;
    scanf("%c", &ch); //读入一个字符
    if (ch == ' ')
        T = NULL;
    else
    {
        T = (BiTNode *)malloc(sizeof(BiTNode)); //生成一个新结点
        T->data = ch;
        CreateBiTree(T->lchild); //生成左子树
        CreateBiTree(T->rchild); //生成右子树
    }
}
void PreOrder(BiTree T)
{
    if (T)
    {
        printf("%c", T->data); //访问结点
        PreOrder(T->lchild);   /*将未完成的代码补全,提示：此处添加一条语句*/
        PreOrder(T->rchild);   /*将未完成的代码补全,提示：此处添加一条语句*/
    }
}
void InOrder(BiTree T)
{
    if (T)
    {
        InOrder(T->lchild);    /*将未完成的代码补全,提示：此处添加一条语句*/
        printf("%c", T->data); //访问结点
        InOrder(T->rchild);    /*将未完成的代码补全,提示：此处添加一条语句*/
    }
}
void PostOrder(BiTree T)
{
    if (T)
    {
        PostOrder(T->lchild);  /*将未完成的代码补全,提示：此处添加一条语句*/
        PostOrder(T->rchild);  /*将未完成的代码补全,提示：此处添加一条语句*/
        printf("%c", T->data); //遍历右子树
    }
}
