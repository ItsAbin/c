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
                sparse[0][k]=a[i][j];
                sparse[1][k]=i;
                sparse[2][k++]=j;
            }
        }
    }
    return k;
}

void display(int a[][10], int k){
    for(int i=0; i<3; i++){
        printf("\n");
        switch(i){
            case 0: printf("Value  : ");
                    break;
            case 1: printf("Row    : ");
                    break;
            case 2: printf("Coloum : ");
                    break;
        }
        for(int j=0; j<k; j++){
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
