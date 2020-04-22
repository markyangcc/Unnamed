#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data;
	struct Node *next;
};

//struct Node *top = malloc(sizeof(struct Node *)); //top stack pointer
//FIXME:struct can't declare in file scope
bool isEmpty(struct Node *top);
void push(struct Node **top, int data);
int pop(struct Node *top);
int peek(struct Node *top);

int main(void)
{
	int data;
	int choice;
	struct Node *top = malloc(sizeof(struct Node *)); //top stack pointer

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
			top->next = NULL;
			//TODO: free all allocated memory
			/*  while (top != NULL)
            {
                struct Node *temp_ptr;
                temp_ptr = top;
                top = top--;
                free(temp_ptr);
            } */
			printf("Stack initialized successfully.\n");
			break;
		case 2:
			printf("Enter the data to push into stack:");
			scanf("%d", &data);
			push(&top, data);
			break;
		case 3:
		{
			bool ret_value = isEmpty(top);
			if (ret_value == true)
			{
				printf("Empty Stack. Requirement denied.\n");
				exit(EXIT_FAILURE);
			}
			data = pop(top);
			printf("popped:%d", data);
			break;
		}
		case 4:
		{
			bool ret_value = isEmpty(top);
			if (ret_value)
			{
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

bool isEmpty(struct Node *top)
{
	return top->next == NULL;
}

void push(struct Node **top, int data)
{
	struct Node *new_node = malloc(sizeof(struct Node *));
	new_node->data = data;
	new_node->next = *top;
	*top = new_node;
}

int pop(struct Node *top)
{
	int data = top->data;
	struct Node *temp_ptr = top;
	top = top->next;
	free(temp_ptr);
	return data;
}

int peek(struct Node *top)
{
	return top->data;
}