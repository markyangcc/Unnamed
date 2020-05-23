#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *leftchild;
    struct Node *rightchild;
};

int insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        (*root) = malloc(sizeof(struct Node));
        (*root)->data = data;
        (*root)->leftchild = NULL;
        (*root)->rightchild = NULL;
        return 0;
    }
    else
    {

        return insert(&(*root)->leftchild, data);

        return insert(&(*root)->rightchild, data);
    }
}
void search(int data);
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%2c", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        preorder(root->leftchild);
        printf("%2c", root->data);
        preorder(root->rightchild);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        preorder(root->leftchild);
        preorder(root->rightchild);
        printf("%2c", root->data);
    }
}

int main(void)
{
    struct Node *root = NULL;
    printf("Please enter the characters in one line(then press enter):");
    while (1)
    {
        char ch, data;

        scanf("%c", &ch);
        if (ch == '\n')
            break;
        else
            data = ch;

        insert(&root, data);
    }

    printf("preorder display :\n");
    preorder(root);
    printf("\ninorder display:\n");
    inorder(root);
    printf("\npostorder display:\n");
    postorder(root);

    return 0;
}