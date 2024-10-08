#include"headlessStack.c"
#include<string.h>
int read(char text[]){
	if(!isFull()){
		printf("Enter the string (max 10 char): ");
		scanf("%s",text);
		int len=strlen(text);
		for(int i=0; i<len; i++)
			push(text[i]);
		return len;
	}
}
void main(){
    char text[10],result[10];
    int len = read(text);
    printf("%d\n",len);
    printf("Reversed String: ");
    for(int i=0; i<len; i++)
        printf("%c",pop());
    printf("\n");
}
