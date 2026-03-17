#include<stdio.h>
#include<stdlib.h>

struct node * create_node();
int height_tree(struct node * root);

struct node{
	int data;
	struct node * left;
	struct node * right;
};

int main(){
	int c;
	struct node * root;
	root = NULL;
	root = create_node();
	printf("Height of a Tree is: %d",height_tree(root));
	return 0;
}

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

int height_tree(struct node * root){
	int l,r;
	if(root == NULL){
		return -1;
	}
	else{
		l = height_tree(root -> left) + 1;
		r = height_tree(root -> right) + 1;
		if(l > r){
			return l;
		}
		else{
			return r;
		}
	}
}
