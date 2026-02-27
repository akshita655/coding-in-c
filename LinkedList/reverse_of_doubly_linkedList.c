//REVERSE OF DOUBLY LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
};

int main(){
	struct Node *head = NULL;
	struct Node *temp = NULL, *newnode = NULL;
	int choice = 1;
	while(choice == 1){
		newnode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d",&newnode -> data);
        newnode -> prev = NULL;
		newnode -> next = NULL;
		if(head == NULL){
			temp = newnode;
			head = newnode;
		}
		else{
			temp -> next = newnode;
            newnode -> prev = temp;
            temp = newnode;
		}
		printf("Want to enter more data(0,1): ");
		scanf("%d",&choice);
	}
	printf("The Doubly linked list is: ");
	if (head == NULL) {
	    printf("Empty.\n");
	    return 0;
	}
	temp = head;
	while(temp != NULL){
		printf("%d ",temp -> data);
		temp = temp -> next;
	}
	printf("\n");
	temp = head;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	printf("Reverse of Doubly Linked List: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->prev;
	}
	temp = head;
	while (temp != NULL) {
    	struct Node *next = temp->next;  
    	free(temp);                     
    	temp = next;                    
	}
	return 0;
}
