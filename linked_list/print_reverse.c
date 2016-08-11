#include<stdio.h>
#include<stdlib.h>

struct Node *top=NULL;

struct Node
{
	struct Node *next;
	int data;
};


struct Node* createNewNode(int data)
{
	struct Node *temp=(struct Node *)(malloc)(sizeof(struct Node));
	temp->data=data;
	temp->next=NULL;
	return temp;
}

struct Node* insert(struct Node **top,int data)
{

	if(*top==NULL)
	{
		*top=createNewNode(data);
		return *top;
	}
	else
        {
		struct Node *newNod=createNewNode(data);
		newNod->next=*top;
		*top=newNod;	
	}
}

void traverse(struct Node *top)
{
	if(top==NULL)	{
		printf("empty");
	}
	else 
	{
		struct Node *temp;
		temp=top;
		while(temp!=NULL)
		{
			printf("\n %d",temp->data);
			temp = temp->next;
		}
	}
}

void traverse_reverse(struct Node *top)
{
	if(top!=NULL)
	{
		traverse_reverse(top->next->next);
		printf("\n\t%d",top->data);
	}
}

int main()
{
	insert(&top,10);
	insert(&top,20);
	insert(&top,30);
	insert(&top,40);
	insert(&top,50);
	insert(&top,666);
	
	traverse(top);	
	traverse_reverse(top);
	return 0;
}

