#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *leftchild;
    struct Node *rightchild;
};

int insert(struct Node **root, int data); //Pass the pointer point to the address of the root,
                                          // because we need to change the root's value in other functions
void preorder(struct Node *root);
void inorder(struct Node *root);
void postorder(struct Node *root);

int main(void)
{
    struct Node *root = NULL;
    printf("Please enter the characters in one line(then press enter):");
    while (1)
    {
        char ch, data; //ch is a temp variable
        scanf("%c", &ch);

        if (ch == '\n') //prevent \n to be treated as an input character
            break;      //when ch is \n, break the loop, so insert() won't going to work
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

int insert(struct Node **root, int data)
{
    if (*root == NULL)
    {
        (*root) = malloc(sizeof(struct Node));
        (*root)->data = data;
        (*root)->leftchild = NULL; //Prevent memory leak, cause a pointer can point to any memory
        (*root)->rightchild = NULL;
        return 0;
    }
    else
    {
        return insert(&(*root)->leftchild, data);
        return insert(&(*root)->rightchild, data);
    }
}

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
