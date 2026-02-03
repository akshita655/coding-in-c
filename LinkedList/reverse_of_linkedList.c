//REVERSE LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct Node* reverselist(struct Node* head);

struct Node{
	int data;
	struct Node* link;
};

int main(){
	int n;
	struct Node *head = NULL;
	struct Node *temp, *newnode;
	int choice = 1;
	while(choice==1){
		newnode = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d",&newnode->data);
		newnode -> link = NULL;
		if(head == NULL){
			temp = newnode;
			head = newnode;
		}
		else{
			temp -> link = newnode;
			temp = newnode;
		}
		printf("Want to enter more data(0/1): ");
		scanf("%d",&choice);
	}
	printf("Original Linked List is: ");
	temp = head;
	while(temp != NULL){
		printf("%d ",temp -> data);
		temp = temp -> link;
	}
	printf("\n");
	struct Node *temp1 = reverselist(head);
	printf("Reverse Linked List is: ");
	while(temp1 != NULL){
		printf("%d ",temp1 -> data);
		temp1 = temp1 -> link;
	}
	return 0;
}

struct Node* reverselist(struct Node* head) {
    struct Node *prev = NULL, *curr = head, *new_node = NULL;
    while(curr != NULL){
        new_node = curr -> link;
        curr -> link = prev;
        prev = curr;
        curr = new_node;
    }
    return prev;
}
