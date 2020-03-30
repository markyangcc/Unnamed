#include <stdio.h>
#include <stdlib.h>

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

int find_node_with_content(struct Node *List, int num);	   //按内容查找
int find_node_with_position(struct Node *List, int index); //按位置查找

void delete_list_from_front(void);		   //链表删除(从head开始删除)
void print_list(struct Node *temp, int n); //打印链表

int main(void)
{
	int ch;
	printf("1. Insert an element at the beginning of linked list.\n");
	printf("2. Insert an element at the end of linked list.\n");
	printf("3. Traverse linked list.\n");
	printf("4. Delete an element from beginning.\n");
	printf("5. Delete an element from end.\n");
	printf("6. Exit\n");

	scanf("%d", &ch);

	for (int i = 0; i < 3; i++)
	{
		int number;
		printf("Enter a number:");
		scanf("%d", &number);
		add_node_at_front(number);
	}
	insert_node(head, 0, 2);
	print_list(head, count);

	delete_node(head, 3);
	print_list(head, count);

	int postion = find_node_with_content(head, 1);
	printf("It's position %d\n", postion);

	int data = find_node_with_position(head, 5);
	printf("The data at that position: %d\n", data);

	print_list(head, count);
	delete_list_from_begin();
	print_list(head, count);
	
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

int find_node_with_content(struct Node *List, int num)
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

int find_node_with_position(struct Node *List, int index)
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

void delete_list_from_begin(void)
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
	for (int i = 0; i < n; i++)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
