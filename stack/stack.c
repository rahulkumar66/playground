#include<stdio.h>
#include<stdlib.h>

struct nodeStack
{
int data;
struct nodeStack *next;
};

struct nodeStack *push(struct nodeStack **top,int value)
{
	if(*top==NULL)
	{
		struct nodeStack *temp=(struct nodeStack *)(malloc(sizeof(struct nodeStack)));
		temp->data=value;
		temp->next=NULL;
		*top=temp;
		return *top;
	}
	else
	{
		struct nodeStack *temp=(struct nodeStack *)(malloc(sizeof(struct nodeStack)));
		temp->data=value;
		temp->next=*top;
		*top=temp;
		return *top;
	}	
}

struct nodeStack *pop(struct nodeStack **top)
{
	if(*top==NULL)
		printf("empty \n");
	else
		*top=(*top)->next;
	return *top;
}

void traverse_stack(struct nodeStack **top)
{
	struct nodeStack *temp=*top;

	while(temp!=NULL)
	{
		printf("emperor %d\n",temp->data);
		temp=temp->next;
	}
}


int main()
{
	struct nodeStack *top=NULL;
	push(&top,10);
	push(&top,11);
	push(&top,12);
	push(&top,14);

	pop(&top);
	pop(&top);
	
	traverse_stack(&top);
		
	return 0;
}
