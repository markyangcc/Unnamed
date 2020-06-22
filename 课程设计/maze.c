#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//stack template
struct Node
{
    int data;
    struct Node *next;
};

struct Array2D
{
    int raw; //raw
    int col; //column
};

void def_offset(struct Array2D *offset);
void generate_random_maze();

int main(void)
{ //get maze size
    struct Array2D maze_size;
    printf("Enter 2-D maze size(raws columns):");
    scanf("%d %d", &maze_size.raw, &maze_size.col);

    //build dynamic array
    printf("Building Maze......\n");
    int *maze = (int *)malloc(sizeof(int) * (maze_size.raw * maze_size.col));

    //define offset
    struct Array2D offset[4];
    def_offset(&offset);

    //TODO:keep doing, from generate random maze
    return 0;
}
void def_offset(struct Array2D *offset)
{

    (*(offset + 0)).raw = 0;
    (*(offset + 0)).col = 1; //move right
    (*(offset + 1)).raw = 1;
    (*(offset + 1)).col = 0; //move down
    (*(offset + 2)).raw = 0;
    (*(offset + 2)).col = -1; //move left
    (*(offset + 3)).raw = -1;
    (*(offset + 3)).col = 0; //move up
}

//stack related functions
//top->next = NULL to initialize stack
bool isEmpty(struct Node **top);
void push(struct Node **top, int data);
int pop(struct Node **top);
int peek(struct Node *top);
void display(struct Node **top); //optional function, not the core function of stack

int main(void)
{
    int data;
    int choice;

    struct Node *top = malloc(sizeof(struct Node *)); //top pointer,
                                                      // need to be free when it is no use anymore, free it immediately, avoid memory leak

    /* double *ptr;     //malloc() may not allocate the required memory,
    if (ptr == NULL) //in this case the function returns a null pointer
    {
        printf("Memory allocation failed.Program exit with code 1.\n");
        exit(EXIT_FAILURE);
    } */

    top->next = NULL; //initialize stack
    printf("\nStack initialized!\n");

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

void display(struct Node **top)
{
    struct Node *temp; // don't change the orgian point to relationships

    if ((*top)->next == NULL) // check for stack underflow
    {
        printf("Empty Stack. Requirement denied.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        temp = *top;
        while (temp->next != NULL)
        {
            printf("%d\t", temp->data); // print node data
            temp = temp->next;          // assign temp link to temp
        }
    }
}