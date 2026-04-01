#include<stdio.h>
#include<stdlib.h>

struct node * create_node(struct node *root, int data);
struct node* findMin(struct node *root);

struct node{
	int data;
	struct node * left;
	struct node * right;
}*root = NULL;

int main() {
	int choice = 1, data;
	while(choice == 1){
		printf("Enter data to insert: ");
        scanf("%d", &data);
        root = create_node(root, data);
        printf("Want to enter more data?(0, 1) ");
        scanf("%d",&choice);
	}
	struct node * result = findMin(root);
	printf("Minimum Element in the Tree is: %d",result -> data);
}

struct node* create_node(struct node *root, int data) {
    struct node *newnode;
    if (root == NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->left = NULL;
        newnode->data = data;
        newnode->right = NULL;
        return newnode;
    } else if (data < root->data) {
        root->left = create_node(root->left, data);
    } else {
        root->right = create_node(root->right, data);
    }
    return root;
}

struct node* findMin(struct node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}
