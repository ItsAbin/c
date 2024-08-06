#include <stdio.h>

void main()
{
	int n, a[n], target, flag=0;
	
	printf("Enter the size of array: ");
	scanf("%d",&n);
	
	// array input
        for (int i=0; i<n; i++)
        	{ printf("\nEnter %d element of array: ",i+1);
        	  scanf("%d", &a[i]);
        	}
        
        printf("Enter the number to be found: ");
        scanf("%d", &target);
        
        // linear search
        for(int i=0; i<n; i++)
        	{ if(a[i]==target)
        	    { printf("Element found at position %d.\n",i+1);
        	      flag=1;
        	      break;
        	    }
        	}
        	
        if(flag==0)
        	printf("\nNumber not present in array\n");
}
