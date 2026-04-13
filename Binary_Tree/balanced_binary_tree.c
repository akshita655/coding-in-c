#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* create_node(){
    int value;
    printf("Enter data (-1 for no node): ");
    scanf("%d",&value);
    if(value == -1){
        return NULL;
    }
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    printf("Enter left child of %d:\n", value);
    newnode->left = create_node();
    printf("Enter right child of %d:\n", value);
    newnode->right = create_node();
    return newnode;
}

int height(struct node * root){
	if(root == NULL){
		return 0;
	}
	int l = height(root -> left);
	int r = height(root -> right);
	return 1 + (l > r ? l : r);
}

bool isBalanced(struct node * root){
	if(root == NULL){
		return true;
	}
	if(abs(height(root -> left) - height(root -> right)) > 1){
		return false;
	}
	return isBalanced(root -> left) && isBalanced(root -> right);
}

 int main(){
 	struct node* root;
    root = create_node(); 
    bool result = isBalanced(root);
    if (result){
    	printf("\nTree is Balanced!");
	}
	else{
		printf("\nTree is NOT Balanced!");
	}
	return 0;
 }
