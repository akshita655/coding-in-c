//DIAMETER OF A BINARY TREE

#include<stdio.h>
#include<stdlib.h>

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
    printf("Enter left child of %d: ", value);
    newnode->left = create_node();
    printf("Enter right child of %d: ", value);
    newnode->right = create_node();
    return newnode;
}

int height(struct node * root){
	if(root == NULL){
		return -1;
	}
	int l = height(root -> left);
	int r = height(root -> right);
	return 1 + (l > r ? l : r);
}

int diameter(struct node * root){
	if(root == NULL){
		return -1;
	}
	int l = diameter(root -> left);
	int r = diameter(root -> right);
	int sp = height(root -> left) + height(root -> right) + 2;
	return (l > r ? (l > sp ? l : sp) : (r > sp ? r : sp));
}

int main(){
    struct node* root;
    root = create_node(); 
    if(root != NULL){
        printf("\nDiameter: %d",diameter(root));
    }
    return 0;
}
