#include<stdio.h>
#include <stdlib.h>
typedef struct Node{
    int info;
    struct  Node* link;
}node;

node* front = NULL;
node* rear = NULL;

node* newnode(int value){
    node* c = (node*)malloc(sizeof(node));
    c->info=value;
    c->link=NULL;
    return c;
}

int insert(int value){
    node* p = newnode(value);
    if(front == NULL){
        front=rear=p;
        printf("%d inserted at front\n", value);
    }
    else{
        rear->link = p;
        rear = p;
        printf("%d inserted at rear\n", value);
    }
    
    return 0;
}

int delete(){
    int value;
    if(front == NULL)
        printf("Error :( Queue Empty\n");
    else{
        node* curr = front;
        value = curr->info;
        if(front == rear){
            front=rear=NULL;
            free(curr);
         }
         else{
            front = front->link;
            free(curr);   
         }
    }
    
    return value;
}

int display(){
    node* curr = front;
    if(front==NULL)
        printf("Error :( Queue Empty");
    else{
        while(curr!=NULL){
            printf("%d", curr->info);
            if(curr->link != NULL)
                printf(" -> ");
            curr=curr->link;
        }
        printf("\n");
    }
    
    return 0;
}

int main(){
    int choice,value,item;
	do{
		printf("\n[1] Insert \n[2] Delete\n[3] Display\n[4] Quit\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: printf("Enter Element: ");
			        scanf("%d",&value);
			        insert(value);
					break;
	        case 2: value = delete();
	                printf("%d deleted from queue\n", value);
			        break;
			case 3: display();
			        break;
			case 4: break;
			default: printf("\nOoops.. Wrong Choice\n");
		}
	}while(choice!=4);
	
	return 0;
}

