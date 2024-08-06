#include <stdio.h>

void inputarray(int a[], int n);
void swap(int *p, int *q);
int partition(int a[], int lb, int ub);
void quicksort(int a[],int lb, int ub);
void outputarray(int a[], int n);

int main()
{	int n,a[100];
	printf("Enter number of elements: ");
	scanf("%d",&n);
	
	inputarray(a,n);
	
	// lb= Lower Base   ub= Upper Base
	int lb=0, ub=n-1;
	
    quicksort(a,lb,ub);
    
    printf("Sorted array =>");
    outputarray(a,n);
    
    return 0;
}

void inputarray(int a[], int n)
{	 for (int i=0; i<n; i++)
    	{ printf("\nEnter element %d of array: ",i+1);
    	  scanf("%d", &a[i]);
        }
}

void outputarray(int a[], int n)
{	for (int i=0; i<n; i++)
    	printf("\t%d", a[i]);
    
}

void swap(int *p, int *q)
{	int temp;
        temp=*p;
        *p=*q;
        *q=temp;
}

int partition(int a[], int lb, int ub)
{	int i,j,key;
	key=a[lb];
	i=lb+1; j=ub;
	do{
		while(i<ub && a[i]<key)
			i++;
		while(j>lb && a[j]>key)
			j--;
		if(i<j)
			swap(&a[i],&a[j]);
	  }while(i<j);
	swap(&a[lb],&a[j]);
	return j;
}

void quicksort(int a[],int lb, int ub)
{	int pos;
	if(lb<ub)
	{	pos= partition(a,lb,ub);
		quicksort(a,lb,pos-1);
		quicksort(a,pos+1,ub);
	}
}
	
			
		
	
