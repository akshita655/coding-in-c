#include<stdio.h>
#include<stdlib.h>
#define n 100
int stack[n];
int top = -1;
void push(int stack[]){
	int element;
	printf("Enter element to be enterd: ");
	scanf("%d",&element);
	if(top == n-1){
		printf("Stack Overflow!\n");
	}
	else{
		top++;
		stack[top] = element;
	}
}
void pop(int stack[]){
	if(top == -1){
		printf("Stack Underflow!\n");
	}
	else{
		int item = stack[top];
		top--;
		printf("Popped element is: %d\n",item);
	}
}
void peek(int stack[]){
	if(top == -1){
		printf("Stack is Empty!\n");
	}
	else{
		printf("Top element of stack is: %d\n",stack[top]);
	}
}
void display(int stack[]){
	if(top == -1){
		printf("Stack is Empty!\n");
		return;
	}
	int i;
	for(i=top;i>=0;i--){
		printf("%d ",stack[i]);
	}
	printf("\n");
}
int main(){
	int choice,c;
	do{
		printf("1 - PUSH\n");
		printf("2 - POP\n");
		printf("3 - PEEK\n");
		printf("4 - DISPLAY\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push(stack);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				peek(stack);
				break;
			case 4:
				display(stack);
				break;
			default:
				printf("Invalid choice!\n");
		}
		printf("1 - MORE\n");
		printf("2 - END\n");
		printf("Enter your choice: ");
		scanf("%d",&c);
	}while(c == 1);
	if(c == 2){
		printf("Exiting Program...");
	}
	return 0;
}
