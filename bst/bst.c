#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

struct node* newNode(int);
struct node* insert(int, struct node **);
void traverse_preorder(struct node *);

int main()
{
	struct node *root=NULL;
	insert(20,&root);
	insert(5,&root);
	insert(12,&root);
	insert(50,&root);
	traverse_preorder(root);
	return 0;
}

struct node* newNode(int data)
{
	struct node *new_node = (struct node *) malloc(sizeof(struct node));
	new_node->left = new_node->right=NULL;
	new_node->data = data;
	return new_node;
}

struct node* insert(int value,struct node **root)
{
	if(*root==NULL)
	{
		struct node *x=newNode(value);
		*root = x;
	}
	if(value < (*root)->data)
	{
		insert(value, &((*root)->left));
	}
	else if(value > (*root)->data)
	{
		insert(value, &((*root)->right));
	}
	
}

void traverse_preorder(struct node *root)
{
	if(root != NULL)
	{
		printf("%d \n",root->data);
		traverse_preorder(root->left);
		traverse_preorder(root->right);
	}
	
	
}



