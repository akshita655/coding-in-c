#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<limits.h>

struct node * create_node(struct node *root, int data);
bool isValid(struct node * root, int min, int max);

struct node{
    int data;
    struct node * left;
    struct node * right;
}*root = NULL;

struct node* create_node(struct node *root, int data) {
    struct node *newnode;
    if (root == NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->left = NULL;
        newnode->data = data;
        newnode->right = NULL;
        return newnode;
    }
	else if (data < root->data) {
        root->left = create_node(root->left, data);
    }
	else {
        root->right = create_node(root->right, data);
    }
    return root;
}

bool isValid(struct node * root, int min, int max){
    if(root == NULL){
        return true;
    }
    if(root->data <= min || root->data >= max){
        return false;
    }
    return isValid(root->left, min, root->data) && isValid(root->right, root->data, max);
}

int main() {
    int choice = 1, data;
    while(choice == 1){
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = create_node(root, data);
        printf("Want to enter more data?(0, 1): ");
        scanf("%d",&choice);
    }
    printf("\n");
    if(isValid(root, INT_MIN, INT_MAX)){
        printf("Valid BST");
    }
	else{
        printf("Not a BST");
    }
    return 0;
}
