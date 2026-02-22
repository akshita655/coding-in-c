//IMPLEMENTATION OF QUEUE USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *front = NULL, *rear = NULL, *temp, *newnode;

void enqueue(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode -> next = NULL;
    if(front == NULL){
        front = newnode;
        rear = newnode;
    }
	else{
        rear -> next = newnode;
        rear = newnode;
    }
}

void dequeue(){
    if(front == NULL){
        printf("Queue is empty!\n");
        return;
    }
	else{
        printf("%d is deleted from the Queue.\n",front->data);
        temp = front;
        front = front->next;
        if(front == NULL){
        	rear = NULL;
		}
        free(temp);
    }
}

void peek(){
    if(front == NULL && rear == NULL){
        printf("Queue is empty!\n");
    }
	else{
        printf("The value at the front is %d\n",front->data);
    }
}

void display(){
	if(front == NULL){
        printf("Queue is empty!\n");
        return;
    }
    temp = front;
    printf("The list is: ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp -> next;
    }
    printf("\n");
}

int main(){
    int choice;
    do{
        printf("Available Operations are: ");
        printf("\n1.Insertion\n2.Deletion\n3.Peek\n4.Display\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
            	printf("Exiting the Program...");
                exit(0);
            default:
                printf("Invalid choice!");
        }
    }while(choice!=0);{
        return 0;
    }
}
