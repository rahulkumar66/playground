#include<stdio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};

struct nodeStack
{
struct node *ptr;
struct nodeStack *next;
};


struct node* newNode(int);
struct node* insert(int, struct node **);
void traverse_preorder(struct node *);

struct nodeStack* push(struct nodeStack **top,struct node *ptr)
{
	if(*top==NULL)
	{
		struct nodeStack *new_node = (struct nodeStack *) malloc(sizeof(struct nodeStack));
		new_node->next = NULL;
		new_node->ptr = ptr;
		*top=new_node;
		return *top;
	}
	else 
	{
		struct nodeStack *new_node = (struct nodeStack *) malloc(sizeof(struct nodeStack));
		new_node->next = *top;
		new_node->ptr = ptr;
		*top=new_node;
		return *top;
	}
}

struct nodeStack* pop(struct nodeStack **top)
{
	if(*top==NULL)
	{
		printf("empty \n");
	}
	else 
	{
		*top=(*top)->next;
	}
	return *top;
}

void traverse_stack(struct nodeStack *top)
{
	struct nodeStack *temp=top;
	while(temp!=NULL)
	{
		printf("emperor %d\n",(temp->ptr)->data);
		temp=temp->next;
	}
}


void inorder(struct node **root)
{
	int done=0;
	struct node *current=*root;
	struct nodeStack *top=NULL;

	while(done!=1)
	{
		while(current!=NULL)
		{
			push(&top,current);
			current=current->left;
		}
		if(top!=NULL)
		{
			printf("%d\t",(top->ptr)->data);
			if((top->ptr)->right!=NULL)
			{		
				current=(top->ptr)->right;
			}
			pop(&top);

		}
		else
		{
			done=1;
		}

	}	

}

int main()
{
	struct node *root=NULL;
	struct nodeStack *top=NULL;
	insert(10,&root);
	insert(7,&root);
	insert(15,&root);
	insert(4,&root);
	insert(8,&root);
	insert(17,&root);
	//push(&top,root);
	//push(&top,root->left);
	//push(&top,root->right);
	//pop(&top);
	//traverse_stack(top);
	inorder(&root);
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
		traverse_preorder(root->left);
		printf("%d \n",root->data);
		traverse_preorder(root->right);
	}	
}



