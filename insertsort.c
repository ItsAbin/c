#include <stdio.h>

void inputarray(int a[], int n);
void insertsort(int a[], int n);
void outputarray(int a[], int n);


void main()
{	int n,a[100];
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	inputarray(a,n);
	    
    insertsort(a,n);
    
    printf("Sorted array \n");
    outputarray(a,n);
}

void inputarray(int a[], int n)
{	 for (int i=0; i<n; i++)
    	{ printf("\nEnter element %d of array: ",i+1);
    	  scanf("%d", &a[i]);
        }
}

void outputarray(int a[], int n)
{	for (int i=0; i<n; i++)
    	printf("%d\n", a[i]);
}

void insertsort(int a[], int n)
{	int i,j,key;
	for(i=1;i<n;i++)
	{	key=a[i];
		j=i-1;
		for(; j>=0 && a[j]>key; j--)
			a[j+1]=a[j];
	    a[j+1]=key;
	}
}		
