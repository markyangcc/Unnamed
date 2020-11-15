//单链表倒置，使用了全局变量

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; //全局变量
struct Node *front_ptr;   //单链表，遵循一个变量只做一件事的原则，故添加一个临时指针
struct Node *rear_ptr;    //单链表，添加一个尾指针用于在链表不同位置间移动
int count = 0;            //记录链表长度变量count
int j;                    //循环计数变量，用于递归结束条件的判断

void creatlist(int new_data);
void print_list(struct Node *temp, int n);
void reverse(void);

int main(void)
{
    int list_len;

    printf("How long you want to create a linked list of nodes, enter the number of nodes:");
    scanf("%d", &list_len);
    for (int i = 0; i < list_len; i++)
    {
        int number;
        printf("Enter the %d number:", i + 1);
        scanf("%d", &number);
        creatlist(number);
    }
    printf("Linked List created:");
    print_list(head, count);

    //初始化->函数递归所需要的变量
    rear_ptr = head;
    front_ptr = head;
    j = count;

    reverse(); //递归调用

    printf("Linked List reversed:");
    print_list(head, count);

    return 0;
}

void reverse(void)
{

    if (j <= count / 2) //用int截断，结点个数为奇数或者偶数同适合
        return;

    int tempdata;
    struct Node *tail; //用于定位尾结点，rear_ptr用于移动指针
    for (int i = 0; i < j; i++)
    {
        tail = rear_ptr;
        rear_ptr = rear_ptr->next;
    }

    tempdata = tail->data; //结点数据data交换
    tail->data = front_ptr->data;
    front_ptr->data = tempdata;
    j--;                         //计数器更新
    front_ptr = front_ptr->next; //前置结点更新
    rear_ptr = head;             //后置结点恢复原状，因为下次循环仍然需要从head指针处开始移动，故需要重置rear_ptr指针

    reverse(); //递归
}

void creatlist(int new_data) //add node at end
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
