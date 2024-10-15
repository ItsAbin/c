#include<stdio.h>

int sparse[3][10];

void read(int a[][10], int m, int n){
    for(int i=0;i<m;i++){
        printf("\nRow %d \n",i);
        for(int j=0; j<n; j++){
            printf("Enter element %d: ",j+1);
            scanf("%d",&a[i][j]);
        }
    }
}

int convert(int a[][10], int m, int n){
    int k=0;
    for(int i=0;i<m;i++){
        for(int j=0; j<n; j++){
            if(a[i][j] != 0){
                sparse[k][0]=a[i][j];
                sparse[k][1]=i;
                sparse[k++][2]=j;
            }
        }
    }
    return k;
}

void display(int a[][10], int k){
    printf("Value\tRow\tColumn");
    for(int i=0; i<k; i++){
        printf("\n");
        for(int j=0; j<3; j++){
            printf("%d\t", a[i][j]);
        }
    }
}

void main(){
    int m,n;
    printf("Enter order of matrix: ");
    scanf("%d",&m);
    scanf("%d", &n);
    int a[m][n];
    read(a,m,n);
    int k = convert(a,m,n);
    printf("\nSparse Matrix\n");
    display(sparse,k);
    printf("\n");
}
