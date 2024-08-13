#include <stdio.h>
#define size 3

int stack[size];
int top=0;

int isFull(){
	if(top>=size)
		return 1;
	else
		return 0;
}

int isEmpty(){
	if(top<=0)
		return 1;
	else
		return 0;
}

int push(){
	int item;
	if(isFull())
		printf("\nError:( Stack Full\n");
	else{
		printf("Enter Element to be added: ");
		scanf("%d",&item);
		stack[top++] = item;
		printf("%d added\n", item);
		}
}

void pop(){
	if(isEmpty())
		printf("\nError:( Nothing to pop..\n");
	else
		printf("\nPopped Element: %d\n",stack[--top]);
}

void peek(){
	if(isEmpty())
		printf("\nSorry.. Nothing to peek\n");
	else
		printf("Element at Top: %d\n",stack[top-1]);
}

void display(){
	printf("\nStack\n");
	for(int i=0; i<size; i++)
		printf("%d\n",stack[i]);
}

void main(){
	int choice;
	do{
		printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. isFull\n6. isEmpty\n7. Quit\nEnter your Choice: ");
		scanf("%d",&choice);
		
		switch(choice) {
			case 1: push();
					break;
			case 2: pop();
					break;
			case 3: peek();
					break;
			case 4: display();
					break;
			case 5: if(isFull())
						printf("\nYes.. Can't add more\n");
					else
						printf("\nNo.. Enter 6 to check if Stack is Empty\n");
					break;
			case 6: if(isEmpty())
						printf("\nYes.. You can add more\n");
					else
						printf("\nNo.. Enter 5 to check if Stack is Full\n");
			case 7: break;
			default: printf("\nOoops.. Wrong Choice\n");
		}
	}while(choice!=7);
}

		
