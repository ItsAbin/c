# include "headlessStack.c"

int inputpriority(char operand){
	switch(operand){
		case '+':
		case '-': return 1;
		case '/':
		case '*': return 3;
		case '^': return 6;
		default: return -1;
	}
}

int instackpriority(char operand){
	switch(operand){
		case '+':
		case '-': return 2;
		case '/':
		case '*': return 4;
		case '^': return 5;
		default: return -1;
	}
}

void main(){
	char infix[50], postfix[50];
	printf("Enter INFIX expression: ");
	scanf("%s",infix);
	int j=0;
	for(int i=0; infix[i]!='\0'; i++){
		int token = infix[i];
		int c=0;
		switch(token){
			case '(': push(token);
					  break;
			case ')': while((c=pop())!='(')
					  	postfix[j++]=c;
					  break;
			case '+':
			case '-':
			case '/':
			case '*':
			case '^': //Checks if Stack is Empty and also priority of the operators
				while(!isEmpty() && (inputpriority(token)<=instackpriority(peek()))){
					  	postfix[j++]=pop();
					  }
					  	push(token);
					  break;
		    default: postfix[j++]=token;
		}
	}
	
	//Dumps all the remaining operator to postfix array
	while(!isEmpty())
		postfix[j++]=pop();
	
	//Appends End of String to postfix
	postfix[j]='\0';
	
	printf("\nPostfix: %s",postfix);
	printf("\n");
}

