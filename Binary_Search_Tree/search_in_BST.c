#include<stdio.h>
#include<stdlib.h>

struct node * create_node(struct node *root, int data);
int search(struct node * root, int data);

struct node{
	int data;
	struct node * left;
	struct node * right;
}*root = NULL;

int main() {
	int data, result, choice = 1;
	while(choice == 1){
		printf("Enter data to insert: ");
        scanf("%d", &data);
        root = create_node(root, data);
        printf("Want to enter more data?(0, 1) ");
        scanf("%d",&choice);
	}
	printf("Enter data to search: ");
    scanf("%d", &data);
    result = search(root, data);
    if (result == -1) {
        printf("Node not found.");
    }
	else {
        printf("Node found.");
    }
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

int search(struct node *root, int data) {
    if (root == NULL) {
        return -1;
    }
    if (root->data == data) {
        return 1;
    }
	else if (data < root->data) {
        return search(root->left, data);
    }
	else {
        return search(root->right, data);
    }
}
