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
        if (data < (*root)->data)
        {

            return insert(&(*root)->leftchild, data);
        }
        else if (data > (*root)->data)
        {

            return insert(&(*root)->rightchild, data);
        }
        else
            return -1;
    }
}
void search(int data);
void preorder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}
void inorder(struct Node *root)
{
    if (root != NULL)
    {
        preorder(root->leftchild);
        printf("%d\t", root->data);
        preorder(root->rightchild);
    }
}
void postorder(struct Node *root)
{
    if (root != NULL)
    {
        preorder(root->leftchild);
        preorder(root->rightchild);
        printf("%d\t", root->data);
    }
}

int main(void)
{
    struct Node *root = NULL;

    insert(&root, 5);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 3);

    printf("preorder display :\n");
    preorder(root);
    printf("\ninorder display:\n");
    inorder(root);
    printf("\npostorder display:\n");
    postorder(root);

    return 0;
}