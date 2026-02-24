#include<stdio.h>
#include<stdlib.h>

struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
};

void insert_at_end(struct Node *temp,struct Node *head){
	struct Node *newnode1 = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&newnode1->data);
	newnode1->next = NULL;
	temp = head;
	while(temp -> next != NULL){
		temp = temp -> next;
	}
	temp -> next = newnode1;
	newnode1 -> prev = temp;
	temp = head;
	printf("The Updated linked list is: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insert_at_beginning(struct Node *temp,struct Node *head){
	struct Node *temp1;
	struct Node *newnode2 = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&newnode2->data);
	temp1 = head;
	head = newnode2;
	newnode2 -> next = temp1;
	newnode2 -> prev = NULL;
	temp = head;
	printf("The Updated Doubly linked list is: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void insert_at_position(struct Node *temp,struct Node *head){
	int pos;
	struct Node *temp2;
	struct Node *temp3;
	printf("Enter position on which data is to be entered: ");
	scanf("%d",&pos);
	if(pos<1){
		printf("Invalid position!");
	}
	struct Node *newnode3 = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&newnode3->data);
	if(pos == 1){
		temp2 = head;
		head = newnode3;
		temp = newnode3;
		temp -> next = temp2;
		newnode3 -> prev = temp2;
	}
	else if(pos>1){
		temp = head;
		int i;
		for (i = 1; temp != NULL && i < pos - 1; i++) {
	        temp = temp -> next;
	    }
	    newnode3 -> next = temp -> next;
	    temp -> next = newnode3;
	    newnode3 -> prev = temp;
	}
	else{
		printf("Invalid position");
	}
	temp = head;
	printf("The Updated Doubly linked list is: ");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	int n;
	struct Node *head = NULL;
	struct Node *temp = NULL, *newnode = NULL;
	int choice=1;
	while(choice==1){
		newnode = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d",&newnode->data);
        newnode->prev = NULL;
		newnode->next = NULL;
		if(head==NULL){
			temp = newnode;
			head = newnode;
		}
		else{
			temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
		}
		printf("Want to enter more data(0,1): ");
		scanf("%d",&choice);
	}
	printf("1 - Insertion at end\n");
	printf("2 - Insertion at beginning\n");
	printf("3 - Insertion at position\n");
	printf("Enter your choice: ");
	scanf("%d",&n);
	switch(n){
		case 1:
			insert_at_end(temp,head);
			break;
		case 2:
			insert_at_beginning(temp,head);
			break;
		case 3:
			insert_at_position(temp,head);
			break;
		}
	return 0;
}
