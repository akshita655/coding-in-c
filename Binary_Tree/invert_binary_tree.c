#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;
}*root = NULL;

struct node * create_node(){
	int value;
	struct node * newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	printf("Enter the data(-1 for no node): ");
	scanf("%d",&value);
	if(value == -1){
		return NULL;
	}
	newnode -> data = value;
	printf("Enter Left Child of %d ",value);
	newnode -> left = create_node();
	printf("Enter Right Child of %d ",value);
	newnode -> right = create_node();
	return newnode;
}

struct node *invertTree(struct node * root){
	if(root == NULL){
		return NULL;
	}
	struct node * temp = root -> left;
	root -> left = invertTree(root -> right);
	root -> right = invertTree(temp);
	return root;
}

void in_order(struct node *root) {
    if (root != NULL) {
        in_order(root->left);
        printf("%d ",root->data);
        in_order(root->right);
    }
}

int main() {
	struct node * root;
	root = create_node();
	printf("\nOriginal Binary Tree: ");
	in_order(root);
	invertTree(root);
	printf("\nInverted Binary Tree: ");
	in_order(root);
	return 0;
}
