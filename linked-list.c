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
    if(head == NULL)
        head = p;
    else{
        p->link = head;
        head = p;
    }
    printf("%d inserted at front\n",val);
}

void insertAfter(int val, int item){
        node* p = newnode(val);
        node* curr = head;
    if(head == NULL){
        printf("List Empty\n",val);
    }
    else{
        while(curr != NULL && curr->info != item)
            curr=curr->link;
        if(curr==NULL)
            printf("Element not found\n");
        else{       
            p->link=curr->link;
            curr->link=p;
            printf("%d inserted after %d\n",val,item);
        }
    }        
}
    

void insertLast(int val){
    node* p = newnode(val);
    node* curr = head;
    if(head == NULL)
        printf("List Doesn't Exist\n");
    else{
        while(curr->link != NULL)
            curr = curr->link;
        curr->link = p;
        printf("%d inserted at last\n",val);
    }
}

void delete(int val){
    node* curr = head;
    node* prev = NULL;
    if(head==NULL)
        printf("List doesn't exist");
    else{
        while(curr != NULL && curr->info != val){
            prev=curr;
            curr=curr->link;
        }
        if(curr == NULL)
            printf("Element not found\n");
        else{
            if(curr==head)
                head=curr->link;
            else
                prev->link=curr->link;
            free(curr);
            printf("%d deleted from list\n",val);
        }
    }
}

void display(){
    node* curr = head;
    if(head==NULL)
        printf("Error :( List not found");
    else{
        while(curr!=NULL){
            printf("%d -> ", curr->info);
            curr=curr->link;
        }
        printf("NULL\n");
    }
}

void main(){
    int choice,val,item;
	do{
		printf("\n[1] Insert First\n[2] Insert Last\n[3] Insert After\n[4] Delete\n[5] Display\n[6] Quit\nEnter your Choice: ");
		scanf("%d",&choice);
		switch(choice) {
			case 1: printf("Enter Element: ");
			        scanf("%d",&val);
			        insertFirst(val);
					break;
			case 2: printf("Enter Element: ");
			        scanf("%d",&val);
			        insertLast(val);
				    break;
		    case 3: printf("Enter Element: ");
			        scanf("%d",&val);
			        printf("Enter Value after which element is inserted: ");
			        scanf("%d",&item);
			        insertAfter(val,item);
				    break;
	        case 4: printf("Enter Element: ");
			        scanf("%d",&val);
			        delete(val);
			        break;
			case 5: display();
			        break;
			case 6: break;
			default: printf("\nOoops.. Wrong Choice\n");
		}
	}while(choice!=6);
}

