#include <stdio.h>
#include <stdlib.h>

//CREATION OF A SINGLE NODE
// Define the structure for a node
struct Node {
    int data;            // Data part
    struct Node* link;   // Pointer to the next node
};
int main(){
	int temp;
    struct Node *head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node));
	printf("Enter data: ");
	scanf("%d",&temp);
    head -> data = temp;
    head -> link = NULL;
    printf("%d",head -> data);
    return 0;
}
