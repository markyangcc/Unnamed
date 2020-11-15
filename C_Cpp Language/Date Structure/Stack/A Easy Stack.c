#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    int top = -1;
    int data[5];
    int choice;
    int num;

    while (1)
    {
        printf("\n==============================================\n");
        printf("            A Easy Stack Presentation\n");
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. peek\n");
        printf("4. exit\n");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter number to push into stack:");
            scanf("%d", &num);
            data[++top] = num;
            break;
        case 2:
        {
            int temp = data[top];
            top = --top;
            printf("%d popped from stack\n", temp);
            break;
        }
        case 3:
            printf("%d is on top of stack\n", data[top]);
            break;
        case 4:
            printf("As you wish.\nExit successfully.");
            exit(EXIT_SUCCESS);
            break;

        default:
            printf("Invalid input.\n");
            exit(EXIT_SUCCESS);
            break;
        }
    }
    return 0;
}