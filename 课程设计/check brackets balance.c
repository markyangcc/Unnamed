#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#define MAXSIZE 50

typedef struct Node
{
	char data;
	struct Node *next;
} LStackNode, *LinkStack;

void initstack(LinkStack *top);		//将链栈初始化
int isempty(LinkStack top);			//判断链栈是否为空
int peek(LinkStack top, char *e);	//取栈顶元素
int push(LinkStack top, char e);	//进栈操作
int pop(LinkStack top, char *e);	//出栈操作
int stacklength(LinkStack top);		//求表长操作
void freestack(LinkStack top);		//销毁链表
int checkbalanced(char e, char ch); //判断括号

int main(void)
{
	LinkStack S;
	char *p;
	char e;
	char ch[60];
	initstack(&S);
	printf("Input algorithm expressions(),[],{}:");

	fgets(ch, MAXSIZE, stdin);
	p = ch;
	while (*p)
	{
		switch (*p)
		{
		case '(':
		case '[':
		case '{':
			push(S, *p++);
			break;
		case ')':
		case ']':
		case '}':
			if (isempty(S))
			{
				printf("Missing left bracket.\n");
				return 0;
			}
			else
			{
				peek(S, &e);
				if (checkbalanced(e, *p))
				{
					pop(S, &e);
				}
				else
				{
					printf("Brackets do not match.\n");
					return 0;
				}
			}
		default:
			p++;
		}
	}
	if (isempty(S))
		printf("brackets matched.\n");
	else
		printf("Missing right bracket.\n");
	return 0;
}

void initstack(LinkStack *top) //将链栈初始化
{
	if ((*top = (LinkStack)malloc(sizeof(LStackNode))) == NULL)
		exit(-1);
	(*top)->next = NULL;
}

int isempty(LinkStack top) //判断链栈是否为空
{
	if (top->next == NULL)
		return 1;
	else
		return 0;
}

int peek(LinkStack top, char *e) //取栈顶元素
{
	LStackNode *p;
	p = top->next;
	if (!p)
	{
		printf("Empty Stack.");
		return 0;
	}
	*e = p->data;
	return 1;
}

int push(LinkStack top, char e) //进栈操作
{
	LStackNode *p;
	if ((p = (LinkStack)malloc(sizeof(LStackNode))) == NULL)
	{
		printf("Memory allocation failed.");
		return 0;
	}
	p->data = e;
	p->next = top->next;
	top->next = p;
	return 1;
}

int pop(LinkStack top, char *e) //出栈操作
{
	LStackNode *p;
	p = top->next;
	if (!p)
	{
		printf("Empty Stack.");
		return 0;
	}
	top->next = p->next;
	*e = p->data;
	free(p);
	return 1;
}

int stacklength(LinkStack top) //求表长操作
{
	LStackNode *p;
	int count = 0;
	p = top;
	while (p->next != NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}

void freestack(LinkStack top) //销毁链表
{
	LStackNode *p, *q;
	p = top;
	while (!p)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

int checkbalanced(char e, char ch)
{
	if (e == '(' && ch == ')')
		return 1;
	else if (e == '[' && ch == ']')
		return 1;
	else if (e == '{' && ch == '}')
		return 1;
	else
		return 0;
}
