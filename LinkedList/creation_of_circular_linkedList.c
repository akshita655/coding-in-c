#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *link;
};

int main() {
    struct Node *head = NULL;
    struct Node *temp = NULL, *newnode;
    int choice = 1;
    while (choice == 1) {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);
        newnode->link = NULL;
        if (head == NULL) {
            head = newnode;
			temp = newnode;
        } else {
            temp->link = newnode;
            temp = newnode;
        }
        printf("Want to enter more data (0,1): ");
        scanf("%d", &choice);
    }
    // Make it circular
    if (temp != NULL) {
        temp->link = head;
    }
    // Print circular linked list
    temp = head;
    printf("The Circular linked list is: ");
    if (temp != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->link;
        } while (temp != head);
    }
    
    return 0;
}

