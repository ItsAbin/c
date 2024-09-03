#include <stdio.h>
#define size 3

int queue[size];
int front=-1, rear=-1;

int isFull(){
	if(((rear+1)%size)==front)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(front==-1 && rear==-1)
		return 1;
	else
		return 0;
}

void insert(){
	int item=0;
	if(isEmpty()){
		rear=front=0;
		printf("Enter element to be added: ");
		scanf("%d",&item);
		queue[rear]=item;
	}
	else{
		 if(isFull())
		 	printf("\nQueue Full\n");
		 else{
		 	printf("Enter element to be added: ");
			scanf("%d",&item);
		 	rear=(rear+1)%size;
		 	queue[rear]=item;
		 	printf("%d is added to the queue\n",item);
		 }
	}
}

void delete(){
	int item=0;
	if(isEmpty())
		printf("Queue Empty");
	else{
		item=queue[front];
		if(front==rear)
			front=rear=-1;
		else{
			front=(front+1)%size;
			printf("\n%d is deleted from queue\n",item);
		}
	}
}

void display(){
	if(isEmpty())
		printf("\nQueue Empty\n");
	else{
		printf("\nQueue\n");
		for(int i=front; i!=rear; i=(i+1)%size)
			printf("%d\t",queue[i]);
	}
	printf("%d",queue[rear]);
}
void main(){
	int choice;
	do{
		printf("\n1. Insert\n2. Delete\n3. Display\n4. isFull\n5. isEmpty\n6. Quit\nEnter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1: insert();
					break;
			case 2: delete();
					break;
			case 3: display();
					break;
			case 4: if(isFull())
						printf("\nYes.. Can't add more\n");
					else
						printf("\nNo.. Enter 5 to check if Queue is Empty\n");
					break;
			case 5: if(isEmpty())
						printf("\nYes.. You can add more\n");
					else
						printf("\nNo.. Enter 4 to check if Queue is Full\n");
			case 6: printf("\nThank you..😊\n");
					break;
			default: printf("\nOoops.. Wrong Choice\n");
		}
	}while(choice!=6);
}
				 
