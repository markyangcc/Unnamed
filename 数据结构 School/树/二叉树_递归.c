#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

void preorder(struct Node *root);
void inorder(struct Node *root);
void postorder(struct Node *root);
struct Node *newtNode(int data);

int main(void)
{
    struct Node *root = newtNode('a');
    root->left = newtNode('b');
    root->right = newtNode('c');
    root->left->left = newtNode('c');
    root->left->right = newtNode('d');
    root->left->right->left = newtNode('e');
    root->left->right->right = newtNode('f');
    root->left->right->left->right = newtNode('g');

    printf("preorder display :\n");
    preorder(root);
    printf("\ninorder display:\n");
    inorder(root);
    printf("\npostorder display:\n");
    postorder(root);

    return 0;
}

struct Node *newtNode(int data)
{
    struct Node *Node = (struct Node *)malloc(sizeof(struct Node));
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;

    return (Node);
}

void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%2c", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        preorder(root->left);
        printf("%2c", root->data);
        preorder(root->right);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        preorder(root->left);
        preorder(root->right);
        printf("%2c", root->data);
    }
}
