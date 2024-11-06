#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int info;
	struct Node* link;
}node;
node* top=NULL;
node* newnode(int val){
	node* p=(node*)malloc(sizeof(node));
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
void push(int item){
	node* p=newnode(item);
	p->link=top;
	top=p;
	printf("%d is added to stack\n", item);
}
int pop(){
		int val=top->info;
		node* p=top;
		top=top->link;
		free(p);
		return val;
}
int peek(){
	return(top->info);
}
void display(){
	node* curr=top;
	while(curr!=NULL){
        printf("%d\t", curr->info);
		curr=curr->link;
	}
}
void main(){
	int item,choice,r;
	do{
	printf("\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Display\n6. Quit\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	switch(choice){
		case 1: printf("Enter the element: ");
			    scanf("%d", &item);
			    push(item);
			    break;
		case 2: if(isEmpty())
				    printf("Stack empty\n");
			    else
				    printf("%d is popped\n",pop());
			    break;
		case 3: if(isEmpty())
		            printf("Stack empty\n");
			    else	
				    printf("Element at the top: %d\n", peek());
			    break;
		case 4:if(isEmpty())	
				    printf("Stackempty\n");
			    else 
				    printf("Stack is not empty\n");
			    break;
		
		case 5: if(isEmpty())
				    printf("Stack is empty\n");
			    else
				    display();
			    break;	
		case 6: break;
		default: printf("Invalid choice.\n");
	}
	}while(choice!=6);

}


