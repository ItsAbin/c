#include <stdio.h>

int binsearch(int a[], int top, int bot, int target)
{	int mid;
	
	if(top>bot)
		return (-1);
	
	mid=(top+bot)/2;
	
	if(a[mid]==target)
		return (mid+1);
	else
	{	if(a[mid]<target)
			return binsearch(a,mid+1,bot,target);
		else
			return binsearch(a,top,mid-1,target);
	}
}

void main()
{	int n,a[100],target,top=0,bot;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	bot=n-1;
	// array input
        for (int i=0; i<n; i++)
        	{ printf("\nEnter element %d of array: ",i+1);
        	  scanf("%d", &a[i]);
        	}
        
        printf("Enter the number to be found: ");
        scanf("%d", &target);
        
        int sol=binsearch(a,top,bot,target);
        
        if(sol==-1)
          printf("Number not found\n");
        else
          printf("Number found at position %d.\n",sol);
}
