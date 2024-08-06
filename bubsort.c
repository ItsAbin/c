#include <stdio.h>

void swap(int *p, int *q)
{	int temp;
        temp=*p;
        *p=*q;
        *q=temp;
}

void bubsort(int a[], int n)
{	for(int p=1;p<n;p++)
		for(int c=0; c<n-p;c++)
		{	if(a[c+1]<a[c])
				swap(&a[c],&a[c+1]);
		}
			
}	
void main()
{	int n,a[100];
	printf("Enter number of elements: ");
	scanf("%d",&n);
	// array input
        for (int i=0; i<n; i++)
        	{ printf("\nEnter element %d of array: ",i+1);
        	  scanf("%d", &a[i]);
        	}
        
        bubsort(a,n);
        printf("Sorted array \n");
        // array output
        for (int i=0; i<n; i++)
        	printf("%d\n", a[i]);
}
