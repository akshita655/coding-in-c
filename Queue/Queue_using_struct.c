#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct queue{
	int items[max];
	int front, rear;
}queue;

void initializeQueue(queue *q){
	q -> front = -1;
	q -> rear = -1;
}

int is_full(queue *q){
	return q -> rear == max-1;
}

int is_empty(queue *q){
	return q -> front == -1 || q -> front > q -> rear;
}

void enqueue(queue *q){
	int value;
	printf("Enter number: ");
	scanf("%d",&value);
	if(is_full(q)){
		printf("Queue is full, cannot insert %d!\n",value);
		printf("----------------------------------\n");
		return;
	}
	if(is_empty(q)){
		q -> front = 0;
	}
	q -> rear++;
	q -> items[q -> rear] = value;
	printf("%d inserted into the queue!\n",value);
	printf("----------------------------------\n");
}

void dequeue(queue *q){
	if(is_empty(q)){
		printf("Underflow!\n");
		printf("----------------------------------\n");
	}
	else if(q -> front == q -> rear){
		q -> front = -1;
		q -> rear = -1;
	}
	else{
		printf("Element deleted\n");
		printf("----------------------------------\n");
		q -> front++;
	}
}

void displayQueue(queue *q){
	int i;
	if(is_empty(q)){
		printf("Queue is empty!\n");
		printf("----------------------------------\n");
		return;
	}
	printf("Queue Elements are: ");
	for(i = q -> front;i <= q -> rear;i++){
		printf("%d ",q -> items[i]);
	}
	printf("\n");
	printf("----------------------------------\n");
}

int main(){
	queue q;
	initializeQueue(&q);
	int choice,value;
	do{
		printf("Operations available are: \n");
		printf("1 - Insertion\n");
		printf("2 - Deletion\n");
		printf("3 - Display\n");
		printf("4 - Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue(&q);
				break;
			case 2:
				dequeue(&q);
				break;
			case 3:
				displayQueue(&q);
				break;
			case 4:
				printf("Exiting Program!\n");
				break;
			default:
                printf("Invalid choice! Please try again.\n");
                printf("----------------------------------\n");
                break;
		}
	}while(choice != 4);
	return 0;
}
