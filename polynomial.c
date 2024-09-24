#include<stdio.h>

typedef struct{
	int coeff;
	int pow;
}term;

int read(term poly[]){
	printf("\nEnter number of terms: ");
	int max;
	scanf("%d",&max);
	for(int i=0; i<max; i++){
		printf("Enter coefficient of term %d: ",i+1);
		scanf("%d",&poly[i].coeff);
		printf("Enter exponent of term %d:",i+1);
		scanf("%d",&poly[i].pow);
	}
	return max;//No. of terms
}

int add(term poly1[], term poly2[],term result[], int m, int n){
	int i=0,j=0,k=0;
	while(i<m && j<n){
		if(poly1[i].pow==poly2[j].pow){
			result[k].coeff=poly1[i].coeff+poly2[j++].coeff;
			result[k++].pow=poly1[i++].pow;
		}
		else if(poly1[i].pow>poly2[j].pow)
				result[k++]=poly1[i++];
			 else
			 	result[k++]=poly2[j++];
	}
	//Appending excess terms of poly1
	while(i<m)
		result[k++]=poly1[i++];
	//Appending excess terms of poly2
	while(j<n)
		result[k++]=poly2[j++];
		
	return k; //No. of terms in result
}

void display(term poly[], int n){
	for(int i=0; i<n; i++){
		printf("%d",poly[i].coeff);
		printf("x^%d",poly[i].pow);
		if(i!=(n-1))
			printf(" + ");
	}
	printf("\n");
}

void main(){
	term poly1[10], poly2[10], result[10];
	int m = read(poly1);
	printf("\nFirst Polynomial: ");
	display(poly1, m);
	int n = read(poly2);
	printf("\nSecond Polynomial: ");
	display(poly2, n);
	int p = add(poly1, poly2, result, m, n);
	printf("\nResult: ");
	display(result, p);
}
