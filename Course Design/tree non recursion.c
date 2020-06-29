/*
 * @Author: Yang Guang Sheng (杨广升)
 * @Date: 2020-06-28 18:19:39
 * @LastEditTime: 2020-06-30 01:58:42
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Visual Cc:\Visual Studio Code\Unnamed\Course Design\check brackets balance.c
 */ 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct tNode
{
    int data;
    struct tNode *left;
    struct tNode *right;
};

struct sNode
{
    struct tNode *t;
    struct sNode *next;
};

void push(struct sNode **top_ref, struct tNode *t); //入栈
struct tNode *pop(struct sNode **top_ref);          //出栈
struct tNode *peek(struct sNode *top_ref);          //取栈顶元素
struct tNode *newtNode(int data);                   //分配新结点
bool isEmpty(struct sNode *top);                    //判断栈空
void postorder(struct tNode *root);                 //后序遍历

int main(void)
{
    struct tNode *root = newtNode('a');
    root->left = newtNode('b');
    root->right = newtNode('c');
    root->left->left = newtNode('c');
    root->left->right = newtNode('d');
    root->left->right->left = newtNode('e');
    root->left->right->right = newtNode('f');
    root->left->right->left->right = newtNode('g');

    printf("\npostorder display:\n");
    postorder(root);

    return 0;
}

void postorder(struct tNode *root)
{
    struct tNode *current = root;
    struct tNode *lastvisit = root; //need to set a symbol to flag if the node is visited or not when postorder
    struct sNode *s = NULL;

    while (current != NULL || !isEmpty(s))
    {
        while (current != NULL)
        {
            push(&s, current);
            current = current->left;
        }
        current = peek(s); //use peek() not pop() like preorder() and inorder()

        if (current->right == NULL || current->right == lastvisit)
        {
            printf("%c ", current->data);
            pop(&s);
            lastvisit = current;
            current = NULL;
        }
        else
            current = current->right;
    }
}

void push(struct sNode **top_ref, struct tNode *t)
{

    struct sNode *new_tNode = (struct sNode *)malloc(sizeof(struct sNode));

    if (new_tNode == NULL)
    {
        printf("Stack Overflow\n");
        exit(0);
    }
    new_tNode->t = t;
    new_tNode->next = (*top_ref);
    (*top_ref) = new_tNode;
}

bool isEmpty(struct sNode *top)
{
    return (top == NULL) ? 1 : 0;
}

struct tNode *pop(struct sNode **top_ref)
{
    struct tNode *res;
    struct sNode *top;

    if (isEmpty(*top_ref))
    {
        printf("Stack Underflow \n");
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->t;
        *top_ref = top->next;
        free(top);
        return res;
    }
}

struct tNode *peek(struct sNode *top_ref)
{
    return top_ref->t;
}

struct tNode *newtNode(int data)
{
    struct tNode *tNode = (struct tNode *)
        malloc(sizeof(struct tNode));
    tNode->data = data;
    tNode->left = NULL;
    tNode->right = NULL;

    return (tNode);
}
