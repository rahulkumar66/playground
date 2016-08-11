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
	if(data==666)
	{
		struct Node *newNod=createNewNode(data);
		newNod->next=*top;
		*top=newNod;
		newNod->next=*top;
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


void get_ele(struct Node *top,int n)
{
	struct Node *slow=top,*fast=top;
	int i;
	for(i=0;i<n;i++)
	{
		fast=fast->next;
	}

	while(fast!=NULL)
	{
		slow=slow->next;
		fast=fast->next;
	}
	printf(" \nanswer \t%d",slow->data);
}

void detect_loop(struct Node *top)
{
	struct Node *slow=top,*fast=top;
	while(1)
	{
		slow=slow->next;
		
		fast=fast->next;
		fast=fast->next;
		
		if(slow==fast) {
			printf("yay %d",slow->data);
			break;
		}
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
	
	detect_loop(top);
	//traverse(top);
	//get_ele(top,2);	

	return 0;
}
