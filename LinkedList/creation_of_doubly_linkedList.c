#include<stdio.h>

struct Node{
	struct Node *prev;
	int data;
	struct Node *next;
};

int main(){
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
	printf("The Doubly linked list is: ");
	temp = head;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
	//THIS CODE IS USED TO DISALLOCTE THE MEMORY OF THE SYSTEM SO THAT SYSTEM DOESNT SLOW DOWN
	temp = head;
	while (temp != NULL) {
    	struct Node *next = temp->next;  // Save the pointer to the next node
    	free(temp);                     // Free the current node's memory
    	temp = next;                    // Move to the next node
	}
}
