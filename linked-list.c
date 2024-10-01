#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int info;
    struct  Node* link;
}node;

node* head=NULL;

node* newnode(int val){
    node* c = (node*)malloc(sizeof(node));
    c->info=val;
    c->link=NULL;
    return c;
}

void insertFirst(int val){
    node* p = newnode(val);
    p->link = head;
    head = p;
}

void display(){
    node* curr = head;
    while(curr!=NULL){
        printf("%d ", curr->info);
        curr=curr->link;
    }
}

void main(){
    int choice;
	do{
		printf("\n[1] Insert First\n[2] Display\n[3] Quit\nEnter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1: printf("Enter Element: ");
			        int val;
			        scanf("%d",&val);
			        insertFirst(val);
					break;
			case 2: display();
					break;
			case 3: break;
			default: printf("\nOoops.. Wrong Choice\n");
		}
	}while(choice!=3);
}

