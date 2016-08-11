#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void window(int arr[],int size,int k)
{
	int loop=ceiling(size/k);
	int i,sum=0;
	for(i=0;i<loop;i++)
	{
		sum=a[]
	}
}

void find_sum(int arr[],int size)
{
	int i; 
	for(i=size-1;i>=0;i--)
	{
		if(arr[i]==9)
		{
			arr[i]=0;
		}
		else
		{
			arr[i]++;
			break;
		}
	}

	for(i=0;i<size;i++)
	{
		printf("\n\t%d",arr[i]);
	}
}

int main()
{
	int arr[]={1,2,3,9,9,11,1};
	
	//find_sum(arr,5);
	window(arr,7,3);	
	return 0;
}
