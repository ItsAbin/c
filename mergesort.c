#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
   int info;
   struct Node* link;
}node;
 
node* top=NULL;

node* newnode(int val){
	node* p = (node*)malloc(sizeof(node));
	p->info=val;
	p->link=NULL;
	
	return p;
}

int isEmpty(){
	if(top==NULL)
		return 1;
	else 
		return 0;
}
void push(int val){
	node* p=newnode(val);
	p->link=top;
	top=p;
}

int pop(){
	int val;
	val=top->info;
	node* p=top;
	top=top->link;
	free(p);
	return(val);
}
int peek(){
	return top->info;
}
void display(){
	node* curr=top;
	while(curr!=NULL){
		 printf("%d -> ",curr->info);
		 curr=curr->link;
	}
	printf("Null");
}
void main(){
	int choice,r,ele;
	do{
		printf("\nCLICK:\n1 for push\n2 for pop\n3 for peek\n4 for is isempty\\n5 for display\n6 for quit\n");
	
		printf("Enter your choice\n");
		scanf("%d",&choice);
	
		switch(choice){
			
			case 1: printf("Enter the element to be pushed\n");
				scanf("%d",&ele);
				push(ele);
				break;
			case 2: if(isEmpty())
					printf("Stack is empty");
				else
					printf("Element popped is %d",pop());
				break;
			case 3: if(isEmpty())
					printf("Stack is empty");
			       else
					printf("item at the top is %d",peek());
				break;
			case 4:r=isEmpty();
			       if(r==1)
			       	printf("Stack is empty");
			       else
			       	printf("Stack is not empty");
			       break;
			
			case 5:display();
			       break;
			case 6:printf("THANKYOU");
			       break;       
			default:printf("Invalid choice");
		}
	}while(choice!=6);
}