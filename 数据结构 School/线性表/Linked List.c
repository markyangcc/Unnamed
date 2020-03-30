#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *head = NULL; //全局变量
int count = 0;			  //记录链表结点数，用于循环结束条件的判断

void add_node_at_front(int new_data); //头插法
void add_node_at_end(int new_data);	  //尾插法

void insert_node(struct Node *List, int num, int position_index); //插入节点
void delete_node(struct Node *List, int position_index);		  //删除节点

int search_node_with_content(struct Node *List, int num);	 //按内容查找
int search_node_with_position(struct Node *List, int index); //按位置查找

void delete_list_from_front(void);		   //链表删除(从head开始删除)
void print_list(struct Node *temp, int n); //打印链表

int main(void)
{
	int ch;
	while (true)
	{
		printf("1. Add nodes at the front of list.\n");
		printf("2. Add nodes at the end of list.\n");
		printf("3. Insert a node into the linked list.\n");
		printf("4. Delete a node from the linked list.\n");
		printf("5. Search an node in the linked list by node's conent.\n");
		printf("6. Search an node in the linked list by node's position.\n");
		printf("7. Delete the linked list.\n");
		printf("8. Traverse linked list.\n");
		printf("9. Exit.\n");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:;
			int list_len;
			printf("How long you want to create a linked list of nodes, enter the number of nodes:");
			scanf("%d", &list_len);
			for (int i = 0; i < list_len; i++)
			{
				int number;
				printf("Enter the %d number:", i + 1);
				scanf("%d", &number);
				add_node_at_front(number);
			}
			break;
		case 2:;
			//	int list_len;
			printf("How long you want to create a linked list of nodes, enter the number of nodes:");
			scanf("%d", &list_len); //Ignore input validation here
			for (int i = 0; i < list_len; i++)
			{
				int number;
				printf("Enter the %d number:", i + 1);
				scanf("%d", &number); //Ignore input validation here
				add_node_at_end(number);
			}
			break;
		case 3:;
			int number, position_index;
			printf("Enter the number and position's index(separate two intergers with a blankspace):");
			if (scanf("%d %d", &number, &position_index) != 2) //Input validation. Guaranteed to read two integers,
			{												   //cause struct->data was previously defined to store an int variable
				printf("Error, invalid input.");
				exit(EXIT_FAILURE);
			}
			insert_node(head, number, position_index);
			printf("%d was inserted into the position %d liked list successfully.", number, position_index);
			break;
		case 4:;
			int node_position;
			printf("Enter the position of node in the liked list:");
			scanf("%d", &node_position); //Ignore input validation here
			delete_node(head, node_position);
			printf("%d was deleted from the position %d liked list successfully.", number, position_index);
			break;
		case 5:;
			//int number;
			int postion; //Store return value (which is the position of the number in the liked list)
			printf("Enter the number you are searching in the liked list:");
			scanf("%d", &number);
			postion = search_node_with_content(head, number);
			printf("The node %d position:%d\n", number, postion);
			break;
		case 6:;
			//	int position;
			//	int number; //Store return value (which is the number stored in the position of the liked list)
			printf("Enter the position you are searching in the liked list:");
			scanf("%d", &postion);
			number = search_node_with_content(head, postion);
			printf("The position %d stored number:%d \n", postion, number);
			break;
		case 7:
			delete_list_from_front();
			break;
		case 8:
			print_list(head, count);
			break;
		case 9:
			exit(EXIT_SUCCESS);
			break;
		default:
			exit(EXIT_SUCCESS);
			break;
		}
	} 

	return 0;
}

void delete_node(struct Node *List, int position_index)
{
	int counter = 1;
	struct Node *temp;
	while (counter != position_index - 1)
	{
		List = List->next;
		counter++;
	}
	temp = List->next;
	List->next = temp->next;
	count--;
	free(temp);
}
void insert_node(struct Node *List, int num, int position_index)
{
	int counter = 1;
	struct Node *new_node = malloc(sizeof(struct Node));
	while (counter != position_index - 1) //移动到节点的前一个位置
	{
		List = List->next;
	}

	new_node->data = num;		 //赋值
	new_node->next = List->next; //与后面链表建立连接
	List->next = new_node;		 //与前面链表建立连接
	count++;
}

int search_node_with_content(struct Node *List, int num)
{
	int index = 1; //此处翻译成下标，record node's position(begin from 1)

	while (List->data != num)
	{
		if (List->next == NULL) //有必要的验证
		{
			printf("Can find %d in List\n", num);
			exit(EXIT_SUCCESS);
		}
		List = List->next; //没有找到就继续寻找

		index++;
	}

	return index;
}

int search_node_with_position(struct Node *List, int index)
{
	int counter = 1;
	int data;
	if (index <= 0 || index > count) //有必要的验证
	{
		printf("Can find position %d in List\n", index);
		exit(EXIT_SUCCESS);
	}
	while (counter != index)
	{
		List = List->next;
		counter++;
	}
	data = List->data;

	return data;
}

void add_node_at_front(int new_data)
{

	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = new_data;

	if (head == NULL)
	{
		head = new_node;
		head->next = NULL;
		count++;
		return;
	}

	new_node->next = head;
	head = new_node;
	count++;
}

void add_node_at_end(int new_data)
{
	struct Node *temp;
	struct Node *new_node = malloc(sizeof(struct Node));
	new_node->data = new_data;

	if (head == NULL)
	{
		head = new_node;
		head->next = NULL;
		count++;
		return;
	}

	temp = head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_node;
	new_node->next = NULL;
	count++;
}

void delete_list_from_front(void)
{
	while (count != 0)
	{
		int number;
		struct Node *temp = malloc(sizeof(struct Node));

		if (head == NULL)
		{
			printf("Empty Linked List.\n");
			return;
		}
		number = head->data;
		temp = head->next;
		free(head);
		head = temp;
		count--;

		printf("%d deleted from the beginning successfully.\n", number);
	}
}

void print_list(struct Node *temp, int n)
{
	if (temp == NULL)
	{
		printf("The linked list is empty.");
	}

	for (int i = 0; i < n; i++)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
