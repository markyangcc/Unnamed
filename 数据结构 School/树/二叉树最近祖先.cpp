#include <stdio.h>
#include <malloc.h>

typedef struct BiTNode
{ //定义二叉树结点
	char data;
	struct BiTNode* lChild, * rChild;
} BiTNode, * BiTree;
void createBiTree(BiTree& T)
{ //创建二叉树
	char c = getchar();
	if (c == '*')
		T = NULL;
	else
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = c;
		createBiTree(T->lChild);
		createBiTree(T->rChild);
	}
}
bool findPath(BiTree T, BiTree p, BiTree path[], int& n)
{ //找到共同路径
	if (T && p)
	{
		if (p == T)
			return true;
		if (findPath(T->lChild, p, path, n) || findPath(T->rChild, p, path, n))
		{
			path[n] = T;
			n++;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}
BiTree findCloseAncient(BiTree T, BiTree p, BiTree q)
{ //在二叉树T中找到p和q的最近祖先
	int i, j;
	int x = 0, y = 0;              //x表示p的祖先的个数，y表示q的祖先的个数
	BiTree pathP[255], pathQ[255]; //设立两个辅助数组暂存从根到p,q的路径
	findPath(T, p, pathP, x);      //求从根到p,q的路径放在pathp和pathq中
	findPath(T, q, pathQ, y);
	printf("x = %d, y = %d\n", x, y);
	i = x - 1; //从第x-1到第0个存放p的祖先
	j = y - 1; //从第y-1到第0个存放q的祖先
	if (i >= 0 && j >= 0)
	{ //当它们之中的任何一个结点至少存在一个祖先
		while (pathP[i] == pathQ[j] && i > 0 && j > 0)
		{
			i--;
			j--;
		}
		return pathP[i];
	}
	else //当它们之中的任何一个结点都不存在祖先，则返回NULL
		return NULL;
}
//根据c值找到树的一个结点，该结点的值与c相等。传进来之前必须保证t = NULL
void findTNode(BiTree T, BiTree& t, char c)
{
	if (T)
	{
		if (T->data == c)
			t = T;
		findTNode(T->lChild, t, c);
		findTNode(T->rChild, t, c);
	}
}
int main(void)
{
	BiTree T;
	printf("请输入树的结点(先序创建二叉树):\n");
    printf("按以下格式输入:abc**de**f*g***\n");
	createBiTree(T);
	BiTree p = NULL, q = NULL;
	printf("\n请输入p和q的两个结点的值：\n");
	char a, b;
	scanf("\n%c %c", &a, &b);
	findTNode(T, p, a);
	findTNode(T, q, b);
	if (p)
		if (q)
			printf("\np 的值为%c，q的值为%c\n", p->data, q->data);
		else
			printf("\np 的值为%c，q的值为空\n", p->data);
	else if (q)
		printf("\np 的值为空，q 的值为%c\n", q->data);
	else
		printf("\np 的值为空，q 的值为空\n");
	if (p && q)
	{
		BiTree closeAncient = findCloseAncient(T, p, q);
		if (closeAncient)
			printf("\n%c和%c的的最近共同祖先为：%c\n", a, b, closeAncient->data);
		else //当不存在最近祖先（只有一种情况：即p或q其中一个结点为根结点）
			printf("\n不存在最近祖先\n");
	}
}
