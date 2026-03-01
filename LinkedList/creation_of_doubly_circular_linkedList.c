//CREATION OF DOUBLY CIRCULAR LINKED LIST

#include <stdio.h>
#include <stdlib.h>

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
        if(newnode == NULL){
        	return 0;
		}
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if(head == NULL){
            head = newnode;
            temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
        printf("Want to enter more data(0,1): ");
        scanf("%d", &choice);
    }
    if(head == NULL){
        printf("List is empty.\n");
        return 0;
    }
    temp->next = head;
    head->prev = temp;
    printf("The Doubly Circular linked list is: ");
    temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
    temp = head->next;
    while(temp != head){
        struct Node *next = temp->next;
        free(temp);
        temp = next;
    }
    free(head);
    return 0;
}
