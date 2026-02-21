//IMPLEMENTATION OF QUEUE USING ARRAY

#include<stdio.h>
#include<stdlib.h>

#define N 100

int queue[N];
int front = -1,rear = -1;

void enqueue(){
    int x;
    printf("Enter element: ");
    scanf("%d",&x);
    if(front == -1 || front > rear){
        rear = 0;
        front = 0;
    }
	else if(rear == N-1){
        printf("Queue if full!\n");
        return;
    }
	else{
        rear++;
    }
    queue[rear] = x;
}

void dequeue(){
    if(front == -1 || front > rear){
        printf("Queue is empty!\n");
    }
    else{
        printf("%d is deleted from the Queue\n",queue[front]);
        front++;
    }
}

void peek(){
    if(front == -1 || front > rear){
        printf("Queue is empty!\n");
    }
    else{
        printf("The first element of the Queue is %d\n",queue[front]);
    }
}

void display(){
    int i;
    if(front == -1 || front > rear){
        printf("Queue is empty!\n");
    }
    else{
        printf("The Queue is: ");
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
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
                printf("Invalid Choice!\n");
        }
    }while(choice!=0);{
        return 0;
    }
}
