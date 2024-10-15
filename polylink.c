#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int coeff;
    int expo;
    struct  Node* link;
}node;

node* newnode(){
    node* c = (node*)malloc(sizeof(node));
    c->link=NULL;
    return c;
}

node* read(){
    char choice;
    node* term = newnode();
    node* head = term;
    do{ 
        printf("\nEnter Coefficient and Exponent: ");
        scanf("%d%d", &term->coeff, &term->expo);
        printf("Do you want to add more terms (y,n): ");
        scanf(" %c", &choice);
        if(choice == 'y'){
            term->link = newnode();
            term = term->link;
         }   
    }while(choice !='n');
    
    return head;
}

node* add(node* a, node* b){
    node* p,*q;
    p=a;
    q=b;
    node*  = newnode();
    node* result = r;
    while(p != NULL && q != NULL){
        if(p->expo == q->expo){
            r->coeff = p->coeff + q->coeff;
            r->expo = p->expo;
            p = p->link;
            q = q->link;
        }
        else{
            if(p->expo > q->expo){
                r->coeff = p->coeff;
                r->expo = p->expo;
                p = p->link;
            }
            else{
                r->coeff = q->coeff;
                r->expo = q->expo;
                q = q->link;
            }
        }
        if(p != NULL && q != NULL){
            r->link = newnode();
            r = r->link;
        }
    }
    while(p != NULL){
        r->link = newnode();
        r = r->link;
        r->coeff = p->coeff;
        r->expo = p->expo;
        p = p->link;
    }
    while(q != NULL){
       r->link = newnode();
       r = r->link; 
       r->coeff = q->coeff;
       r->expo = q->expo;
       q = q->link;
    }
    
    return result;
}

void display(node* poly){
    while(poly != NULL){
        printf("%dx^%d", poly->coeff, poly->expo);
        if(poly->link != NULL)
            printf(" + ");
        poly = poly->link;
    }
    printf("\n");
}

void main(){
    printf("\nPolynomial 1\n");
    node* a = read();
    printf("\nPolynomial 2\n");
    node* b = read();
    node* result = add(a, b);
    printf("Polynomial 1: ");
    display(a);
    printf("Polynomial 2: ");
    display(b);
    printf("Result      : ");
    display(result);
    printf("\n");
}
