#include <stdio.h>
#define size 10

char stack[size];
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

void push(char item){
		stack[top++] = item;
}

char pop(){
	return (stack[--top]);
}

char peek(){
	return (stack[top-1]);
}
