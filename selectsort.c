#include <stdio.h>

void swap(int *p, int *q)
{	int temp;
        temp=*p;
        *p=*q;
        *q=temp;
}

void selsort(int a[], int n)
{	int min;	
	for(int p=0;p<n;p++)
	{
		min=p;
		for(int c=p+1;c<n;c++)
		{
			if(a[c]<a[min])
				min=c;
		}
		swap(&a[p],&a[min]);
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
        
        selsort(a,n);
        printf("Sorted array \n");
        // array output
        for (int i=0; i<n; i++)
        	printf("%d\n", a[i]);
}
