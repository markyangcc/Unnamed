#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top=NULL;

bool isEmpty(void);
void push(int data);
int pop(void);
int peek(void);

int main(void)
{
    int data;
    int choice;
    struct Node *top = NULL;
    printf("\n====================================================================\n");
    printf("            Implementation of Stack Using Linked List in C\n");
    printf("1. initialize\n");
    printf("2. push\n");
    printf("3. pop\n");
    printf("4. peek\n");
    printf("5. exit\n");

    while (true)
    {

        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 2:
            printf("Enter the data to push into stack:");
            scanf("%d", &data);
            push(data);
            break;
        case 3:
            data = pop();
            printf("popped:%d", data);
            break;
        case 4:
            data = peek();
            printf("peeked:%d", data);
            break;
        case 5:
            exit(EXIT_SUCCESS);
            break;
        default:
            break;
        }
    }

    return 0;
}

bool isEmpty(void)
{
    return top == NULL;
}

void push(int data)
{
    struct Node *new_node = malloc(sizeof(struct Node *));
    new_node->data = data;
    new_node->next = top;
    top = new_node;
}

int pop(void)
{
    int data = top->data;
    struct Node *temp_ptr = top;
    top = top->next;
    free(temp_ptr);
    return data;
}

int peek(void)
{
    return top->data;
}