#include<stdio.h>
#include<stdlib.h>

struct node * create_node(struct node *root, int data);
int height(struct node * root);

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
	printf("Height of Tree: %d",height(root));
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

int height(struct node * root){
	if(root == NULL){
		return 0;
	}
	int l = height(root -> left);
	int r = height(root -> right);
	return 1 + (l > r ? l : r);
}
