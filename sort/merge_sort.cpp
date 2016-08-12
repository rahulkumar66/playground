#include<iostream>

using namespace std;

void merge(int arr[],int l,int m,int r)
{	
	int i,k,j;
	int n1 = m-l+1;
	int n2 = r-m;
	int temp1[n1],temp2[n2];

	for(i=0;i<n1;i++)
	{
		temp1[i]=arr[l+i];
	}

	for(i=0;i<n2;i++)
	{
		temp2[i]=arr[m+i+1];
	}

	i=0;
	j=0;
	k=l;

	while(i<n1 && j<n2)
	{
	 if (temp1[i]<=temp2[j])
        {
            arr[k]=temp1[i];
            i++;
        }
        else
        {
            arr[k]=temp2[j];
            j++;
        }
        k++;
	}

	 while (i < n1)
         {
       	 arr[k]=temp1[i];
       	i++;
	k++;
         }
 
    while (j < n2)
    {
        arr[k] = temp2[j];
        j++;
        k++;
    }

}

void merge_sort(int arr[],int l,int r)
{
	int m;
	if(l<r)
	{
		m=(l+r)/2;
		merge_sort(arr,l,m);
		merge_sort(arr,m+1,r);

		merge(arr,l,m,r);
	}
}

void printArray(int A[], int size)
{
    int i;
    for (i=0;i<size;i++)
	{
        cout<<A[i]<<" ";
	}
}

int main()
{
	int arr[]={12, 11, 13, 5, 6, 7};
	int size=sizeof(arr)/sizeof(arr[0]);
	
	merge_sort(arr,0,size-1);
	printArray(arr, size-1);
	return 0;
}
