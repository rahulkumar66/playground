#include<iostream>

using namespace std;

struct Node
{
	struct Node *next;
	struct Node *child;
	int data;
};

struct Node* createNewNode(int data)
{
	struct Node *temp=new Node;
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
		cout<<"empty";
	}
	else 
	{
		struct Node *temp;
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp = temp->next;
		}
	}
}

void flat_list(struct Node *top)
{
	struct Node *current=top;
	struct Node *tail;
	while(top->next != NULL)
	{
		top = top->next;
	}
	tail = top;

	while(current->child!=NULL)
	{
		if(current->child!=NULL)
		{
			tail->next = current->child;
			tail->next = current->child;
			temp = tail->next;
			while(temp != NULL)
			{
				temp = temp->next;
			}
		tail = temp;
	}
	current = current->next;
	}
}

int main()
{
	struct Node *top=NULL;
	insert(&top,10);
	insert(&top,20);
	insert(&top,30);
	insert(&top,40);
	insert(&top,50);
	insert(&top,666);

	flat_list(top);
	
	traverse(top);
}
