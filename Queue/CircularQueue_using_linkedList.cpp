// IMPLEMENTATION OF CIRCULAR QUEUE USING LINKED LIST

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *newnode, *front = NULL, *rear = NULL, *temp;

void enqueue(){
    newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;

    if(front == NULL){
        front = rear = newnode;
        rear->next = front;
    }
    else{
        rear->next = newnode;
        rear = newnode;
        rear->next = front;
    }
}

void dequeue(){
    if(front == NULL){
        printf("The Queue is empty!\n");
    }
    else if(front == rear){
        printf("%d is deleted from the list\n", front->data);
        free(front);
        front = rear = NULL;
    }
    else{
        printf("%d is deleted from the list\n", front->data);
        temp = front;
        rear->next = front->next;
        front = front->next;
        free(temp);
    }
}

void peek(){
    if(front == NULL){
        printf("The Queue is empty!\n");
    }
    else{
        printf("The first element is %d\n", front->data);
    }
}

void display(){
    if(front == NULL){
        printf("The Queue is empty!\n");
    }
    else{
        printf("The list is: ");
        temp = front;
        while(temp->next != front){
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int main(){
    int choice;
    do{
        printf("\nAvailable Operations are:");
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
                printf("Exiting the Program...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }while(choice != 0);
    return 0;
}
