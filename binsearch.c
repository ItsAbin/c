#include<stdio.h>

int binsearch(int a[],int n,int item)
{
	int top=0, bot=n-1,mid;
	while(top<=bot)
	{
	mid=(top+bot)/2;
	if(a[mid]==item)
		return(mid+1);
	else if(item>a[mid])
		top=mid+1;
	else 
		bot=mid-1;	
	}
	return -1;
}
 
void main()
{
	int n,i,item,sol;
	printf("Enter the number of elements\n");
	scanf("%d", &n);
	int a[n];
	for (int i=0; i<n; i++)
        	{ printf("\nEnter element %d of array: ",i+1);
        	  scanf("%d", &a[i]);
        	}
	printf("Element to be found: \n");
	scanf("%d", &item);
	sol= binsearch(a,n,item);
	
	if(sol==-1)
		printf("Element not found\n");
	else
		printf("Element is found at position %d\n", sol);
 
}
