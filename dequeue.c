#include<stdio.h>
#define size 3
int queue[size];
int front=-1,rear=-1;

int isEmpty(){
    if(front==-1 && rear==-1)
        return 1;
    else 
        return 0;
}

int isFull(){
    if(front==(rear+1)%size)
        return 1;
    else 
        return 0;
}

void insertRear(){
    int item;
	if(isEmpty()){
		rear=front=0;
		printf("Enter element to be added: ");
		scanf("%d",&item);
		queue[rear]=item;
		printf("%d is added to the rear\n",item);
    }
	else{
		 if(isFull())
		 	printf("\nQueue Full\n");
		 else{
		 	printf("Enter element to be added: ");
			scanf("%d",&item);
		 	rear=(rear+1)%size;
		 	queue[rear]=item;
		 	printf("%d is added to the rear\n",item);
		 }
	}
}

void insertFront(){
    int item;
    if(isEmpty()){
		rear=front=0;
		printf("Enter element to be added: ");
		scanf("%d",&item);
		queue[front]=item;
		printf("%d is added to the front\n",item);
	}
    else 
        if(isFull())
		 	printf("\nQueue Full\n");
	    else{
	        front=(front+size-1)%size;
	        printf("Enter element to be added: ");
		    scanf("%d",&item);
	        queue[front]= item;
	        printf("%d is added to the front\n",item);
        }
}

int deleteFront(){
    int item=0;
	if(isEmpty())
		printf("Queue Empty");
	else{
		item=queue[front];
		if(front==rear)
			front=rear=-1;
		else{
			front=(front+1)%size;
			printf("\n%d is deleted from front\n",item);
		}
	}
}

int deleteRear(){
   if(isEmpty())
		printf("Queue Empty");
	else{
		int item=queue[rear];
		if(front==rear)
			front=rear=-1;
		else{
			rear=(rear+size-1)%size;
			printf("\n%d is deleted from rear\n",item);
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
		printf("\n1. Insert Front\n2. Insert Rear\n3. Delete Rear\n4. Delete Front\n5. Display\n6. isFull\n7. isEmpty\n8. Quit\nEnter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1: insertFront();
					break;
			case 2: insertRear();
					break;
			case 3: deleteRear();
					break;
			case 4: deleteFront();
			        break;
			case 5: display();
			        break;
			case 6: if(isFull())
						printf("\nYes.. Can't add more\n");
					else
						printf("\nNo.. Enter 5 to check if Queue is Empty\n");
					break;
			case 7: if(isEmpty())
						printf("\nYes.. You can add more\n");
					else
						printf("\nNo.. Enter 4 to check if Queue is Full\n");
			case 8: break;
			default: printf("\nOoops.. Wrong Choice\n");
		}
	}while(choice!=8);
}
