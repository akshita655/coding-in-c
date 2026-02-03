//CREATION OF A LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;            
    struct Node* link;   
};

int main(){
	int n;
	struct Node * head = NULL;
	struct Node *temp, *newnode;
	int choice=1;
	while(choice==1){
		newnode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d",&newnode->data);
		newnode->link = NULL;
		if(head==NULL){
			temp = newnode;
			head = newnode;
		}
		else{
			temp->link = newnode;
			temp = newnode;
		}
		printf("Want to enter more data(0,1): ");
		scanf("%d",&choice);
	}
	printf("The Linked List is: ");
	temp = head;
	while(temp != NULL){
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	return 0;
}
