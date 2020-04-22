#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int data;
    struct Node *next;
};

bool isEmpty(struct Node **top);
void push(struct Node **top, int data);
int pop(struct Node **top);
int peek(struct Node *top); //Pass the  point to pointer's pointer or the value of pointer both is ok.
                            //cause, don't need to change value of variable which defined in other scope in this function
                            //better to only pass the pointer's value not the address

int main(void)
{
    int data;
    int choice;

    struct Node *top = malloc(sizeof(struct Node *)); //top pointer,
                                                      // need to be free when it is no use anymore, free it immediately, avoid memory leak

    double *ptr;     //malloc() may not allocate the required memory,
    if (ptr == NULL) //in this case the function returns a null pointer
    {
        printf("Memory allocation failed.Program exit with code 1.\n");
        exit(EXIT_FAILURE);
    }

    top->next = NULL;
    printf("\nStack initialized!\n");
    /* 程序先初始化栈，会分配一个Node空间，这里面的data是没有使用的，但是不用担心，
	isEmpty()检测时先检测Node所指的下一个位置，无论是pop(),还是peek(),当是最后一个Node时(开始分配的Node,指针指向NULL),
	检测到 point to NULL, 程序停止 */

    printf("\n====================================================================\n");
    printf("            Implementation of Stack Using Linked List in C\n");
    printf("1. initialize\n");
    printf("2. push\n");
    printf("3. pop\n");
    printf("4. peek\n");
    printf("5. exit\n");

    while (true) //menu
    {

        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            while (top->next != NULL)
            {
                struct Node *temp_ptr;
                temp_ptr = top;
                top = top->next;
                free(temp_ptr); //void free (void* ptr);
                                //doesn't need to check if it's freed successful
            }

            void free()
                printf("Stack initialized successfully.\n");
            break;
        case 2:
            printf("Enter the data to push into stack:");
            scanf("%d", &data);
            push(&top, data);
            break;
        case 3:
        {
            bool ret_value = isEmpty(&top);
            if (ret_value == true)
            {
                free(top); //free initialization memory
                printf("Empty Stack. Requirement denied.\n");
                exit(EXIT_FAILURE);
            }
            data = pop(&top);
            printf("popped:%d", data);
            break;
        }
        case 4:
        {
            bool ret_value = isEmpty(&top);
            if (ret_value)
            {
                free(top); //free initialization memory
                printf("Empty Stack. Requirement denied.\n");
                exit(EXIT_FAILURE);
            }
            data = peek(top);
            printf("peeked:%d", data);
            break;
        }
        case 5:
            printf("As you wish.\n");
            exit(EXIT_SUCCESS);
            break;
        default:
            printf("Invalid input. Try again.\n");
            break;
        }
    }

    return 0;
}

bool isEmpty(struct Node **top)
{
    return (*top)->next == NULL;
}

void push(struct Node **top, int data)
{
    struct Node *new_node = malloc(sizeof(struct Node *));

    double *ptr;     //malloc() may not allocate the required memory,
    if (ptr == NULL) //in this case the function returns a null pointer
    {
        printf("Memory allocation failed.Program exit with code 1.\n");
        exit(EXIT_FAILURE);
    }

    new_node->data = data;
    new_node->next = *top;
    *top = new_node;
}

int pop(struct Node **top)
{
    int data = (*top)->data;      // Caution:Operators priority, don't forget the brackets for *top
    struct Node *temp_ptr = *top; //probably info:  error: '*top' is a pointer; did you mean to use '->'?
    *top = (*top)->next;
    free(temp_ptr);
    return data;
}

int peek(struct Node *top)
{
    return top->data;
}