#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
	int data; //此链表存储的数据类型是数字
	struct Node *next;
};

struct Node *head = NULL;			  //全局指针变量
int count = 0;						  //统计节点数，用于判断循环终止条件
void add_node_at_front(int new_data); //头插法
void add_node_at_end(int new_data);	  //尾插法

void insert_node(struct Node *List, int num, int position_index); //插入链表节点
int delete_node(struct Node *List, int position_index);			  //删除链表节点

int search_node_with_content(struct Node *List, int num);	 //链表查找：通过内容查找
int search_node_with_position(struct Node *List, int index); //链表查找：通过位置查找

void delete_list_from_front(void);		   //删除链表(从head开始删除)
void print_list(struct Node *temp, int n); //遍历链表(打印链表)

int main(void)
{
	int ch;
	while (true)
	{
		printf("-------------------------\n");
		printf("1. 链表的建立：头插法.\n");
		printf("2. 链表的建立：尾插法.\n");
		printf("3. 链表节点的插入.\n");
		printf("4. 链表节点的删除.\n");
		printf("5. 链表的查找：按内容查找.\n");
		printf("6. 链表的查找：按位置查找.\n");
		printf("7. 删除链表.\n");
		printf("8. 打印链表.\n");
		printf("9. 退出.\n");
		printf("-------------------------\n");

		printf("\n请输入命令:");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
		{
			int list_len;
			printf("\n需要创建包含多少节点的链表，请输入节点数:");
			scanf("%d", &list_len); //此处省略了输入验证
			for (int i = 0; i < list_len; i++)
			{
				int number;
				printf("输入第 %d 个节点内容:", i + 1);
				scanf("%d", &number); //此处省略了输入验证
				add_node_at_front(number);
			}
		}
		break;
		case 2:
		{
			int list_len;
			printf("\n需要创建包含多少节点的链表，请输入节点数:");
			scanf("%d", &list_len); //此处省略了输入验证
			for (int i = 0; i < list_len; i++)
			{
				int number;
				printf("输入第 %d 个节点内容:", i + 1);
				scanf("%d", &number); //此处省略了输入验证
				add_node_at_end(number);
			}
		}
		break;
		case 3:;
			{
				int number, position_index;
				printf("\n输入要插入的整数和要插入的位置(输入两个整数，并用空格隔开):");
				if (scanf("%d %d", &number, &position_index) != 2) //输入验证，保证读取的是两个整数
				{												   //因为struct Node定义了 Node->data,存储的是int型数字
					printf("Error, 非法输入.");
					exit(EXIT_FAILURE);
				}
				insert_node(head, number, position_index);
				printf("%d 已成功插入链表第 %d 号位置.", number, position_index);
			}
			break;
		case 4:;
			{
				int node_position;
				int number;
				printf("\n输入要删除的节点的位置：");
				scanf("%d", &node_position); //此处省略了输入验证
				number = delete_node(head, node_position);
				printf("%d 已成功从链表第 %d 号位置删除.", number, node_position);
			}
			break;
		case 5:;
			{
				int number;
				int postion; //存储返回值（返回值是该数字在链表中的位置）
				printf("\n输入你要在链表中搜索的数字:");
				scanf("%d", &number); //此处省略了输入验证
				postion = search_node_with_content(head, number);
				printf("第 %d 号节点在链表中的位置是:%d\n", number, postion);
			}
			break;
		case 6:;
			{
				int position;
				int number; //存储返回值（返回值是存储在链表位置上的int型数字）
				printf("\n输入你要在链表中搜索的位置:");
				scanf("%d", &position); //此处省略了输入验证
				number = search_node_with_position(head, position);
				printf("链表第 %d 号节点的位置上存储着数字:%d \n", position, number);
			}
			break;
		case 7:
			delete_list_from_front();
			break;
		case 8:
			print_list(head, count);
			break;
		case 9:
			printf("程序结束.");
			exit(EXIT_SUCCESS);
			break;
		default:
			printf("非法输入，程序终止.(提示：请输入数字1-9).");
			exit(EXIT_SUCCESS);
			break;
		}
	}

	return 0;
}

int delete_node(struct Node *List, int position_index)
{
	int counter = 1;
	int data;
	struct Node *temp;
	while (counter != position_index - 1)
	{
		List = List->next;
		counter++;
	}
	temp = List->next; //temp现在是要删除的节点
	data = temp->data;
	List->next = temp->next; //改变链表链接关系
	count--;
	free(temp); //释放节点
	return data;
}
void insert_node(struct Node *List, int num, int position_index)
{
	int counter = 1;
	struct Node *new_node = malloc(sizeof(struct Node));
	while (counter < position_index - 1) //移动指针到插入位置的前一个节点
	{
		List = List->next;
		counter++;
	}

	new_node->data = num;		 //赋值
	new_node->next = List->next; //与后面链表建立连接
	List->next = new_node;		 //与前面链表建立连接
	count++;
}

int search_node_with_content(struct Node *List, int num)
{
	int index = 1; //记录节点的位置，从1开始计数，符合生活习惯

	while (List->data != num)
	{
		if (List->next == NULL) ///必要的验证
		{
			printf("在链表上找不到数字 %d.\n", num);
			exit(EXIT_SUCCESS);
		}
		List = List->next; //找不到就继续找
		index++;
	}

	return index;
}

int search_node_with_position(struct Node *List, int index)
{
	int counter = 1;
	int data;
	if (index <= 0 || index > count) //必要的验证
	{
		printf("在链表上找不到 %d 号位置.\n", index);
		exit(EXIT_FAILURE);
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

	if (head == NULL) //若head为空
	{
		head = new_node; //让新节点成为head
		head->next = NULL;
		count++;
		return;
	}

	new_node->next = head; //建立与后面节点的连接
	head = new_node;	   //让新节点成为head
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

	while (temp->next != NULL) //移动指针到链表末尾
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
		printf("\n--------------------------------------------\n");
		printf("%d 成功删除.\n", number);
	}
}

void print_list(struct Node *temp, int n)
{
	if (temp == NULL)
		printf("链表为空.");	

	for (int i = 0; i < n; i++)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
