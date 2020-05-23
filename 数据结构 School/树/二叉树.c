#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* leftchild;
	struct Node* rightchild;
};

int insert(struct Node** root)
{
	struct Node* temp;

	char data;
	while (scanf("%c", &data) != EOF)
	{
		if (data == '\n')
			break;

		if (*root == NULL)
		{
			(temp) = malloc(sizeof(struct Node));
			(temp)->data = data;
			(temp)->leftchild = NULL;
			(temp)->rightchild = NULL;
			*root = temp;
		}
		else
		{
			return insert(&(*root)->leftchild);
			return insert(&(*root)->rightchild);
		}
	}
}

void preorder(struct Node* root)
{
	if (root != NULL)
	{
		printf("%c-", root->data);
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
}
void inorder(struct Node* root)
{
	if (root != NULL)
	{
		preorder(root->leftchild);
		printf("%c-", root->data);
		preorder(root->rightchild);
	}
}
void postorder(struct Node* root)
{
	if (root != NULL)
	{
		preorder(root->leftchild);
		preorder(root->rightchild);
		printf("%c-", root->data);
	}
}

int main(void)
{
	struct Node* root = NULL;

	insert(&root);
	/* insert(&root, 'a');
	insert(&root, 'b');
	insert(&root, 'c');
	insert(&root, ' ');
	insert(&root, ' ');
	insert(&root, 'd');
	insert(&root, 'e');
	insert(&root, ' ');
	insert(&root, 'g');
	insert(&root, ' ');
	insert(&root, ' ');
	insert(&root, 'f');
	insert(&root, ' ');
	insert(&root, ' ');
	insert(&root, ' '); */

	printf("preorder display :\n");
	preorder(root);
	printf("\ninorder display:\n");
	inorder(root);
	printf("\npostorder display:\n");
	postorder(root);

	return 0;
}