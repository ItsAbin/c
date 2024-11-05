#include<stdio.h>

void swap(int *p, int *q){
    int temp=*p;
    *p=*q;
    *q=temp;
}

void heapify(int i, int size, int a[]){
    int lc=2*i; //left child
    int rc=(2*i)+1; //right child
    int large=i;
    
    if(lc <= size && a[lc]>a[large])
        large=lc;
    if(rc <= size && a[rc]>a[large])
        large=rc;
    if(large!=i){
        swap(&a[i], &a[large]);
        heapify(large, size, a);
    }
}

void buildheap(int n, int a[]){
    for(int i=n/2; i>=1; i--){
        heapify(i, n, a);
    }
}

void heapsort(int a[], int n){
    buildheap(n, a);
    for(int i=1; i<=n; i++){
        swap(&a[1], &a[(n-i)+1]);
        heapify(1, n-i, a);
    }
}

void main(){
    printf("Enter number of terms: ");
    int n;
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for(int i=1; i<=n; i++)
        scanf("%d", &a[i]);
    heapsort(a, n);
    printf("Sorted Array =>");
    for(int i=1; i<=n; i++)
        printf(" %d", a[i]);
    printf("\n");
}
