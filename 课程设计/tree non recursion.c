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

void push(struct sNode **top_ref, struct tNode *t);
struct tNode *pop(struct sNode **top_ref);
struct tNode *peek(struct sNode *top_ref);
bool isEmpty(struct sNode *top);

void inorder(struct tNode *root)
{

    struct tNode *current = root;
    struct sNode *s = NULL; // Initialize stack s
    bool done = 0;

    while (!done)
    {

        if (current != NULL) // Reach the left most tNode of the current tNode
        {

            push(&s, current); // place pointer to a tree node on the stack before traversing the node's left subtree
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                printf("%c ", current->data);

                current = current->right; //we have visited the node and its left subtree. Now, it's right subtree's turn
            }
            else
                done = 1;
        }
    }
}

void preorder(struct tNode *root)
{
    struct tNode *current = root;
    struct sNode *s = NULL;
    bool done = false;

    while (!done)
    {
        if (current != NULL)
        {
            printf("%c ", current->data);
            push(&s, current);
            current = current->left;
        }
        else
        {
            if (!isEmpty(s))
            {
                current = pop(&s);
                current = current->right;
            }
            else
                done = true;
        }
    }
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

    printf("preorder display :\n");
    preorder(root);
    printf("\ninorder display:\n");
    inorder(root);
    printf("\npostorder display:\n");
    postorder(root);

    return 0;
}
