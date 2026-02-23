//IMPLEMENTATION OF CIRCULAR QUEUE USING ARRAY

#include<stdio.h>
#include<stdlib.h>

#define N 5

int queue[N];
int front = -1, rear = -1;

void enqueue(){
    int x;
    printf("Enter element: ");
    scanf("%d",&x);
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[front] = x;
    }
	else if((rear+1)%N == front){
        printf("Queue is full!\n");
    }
	else{
        rear = (rear+1)%N;
        queue[rear] = x;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    }
	else if(front==rear){
    	printf("%d is deleted from the queue.\n", queue[front]);
        front = -1;
        rear = -1;
    }
	else{
        printf("%d is deleted from the queue.\n",queue[front]);
        front=(1+front)%N;
    }
}

void peek(){
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    }
    else{
        printf("The first element of the Queue is %d.\n",queue[front]);
    }
}

void display(){
    int i;
    if(front == -1 && rear == -1){
        printf("Queue is empty!\n");
    }
    else{
        i = front;
        printf("The list is:");
        while(i!=rear){
            printf("%d ",queue[i]);
            i = (i+1)%N;        
        }
        printf("%d",queue[i]);
        printf("\n");
    }   
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
    }while(choice!=5);{
        return 0;
    }
}
