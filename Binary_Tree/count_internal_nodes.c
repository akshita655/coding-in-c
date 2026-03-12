#include<stdio.h>
#include<stdlib.h>

struct node * create_node();
int count_internal(struct node * root);

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
	printf("Count of Internal Nodes are: %d",count_internal(root));
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

int count_internal(struct node * root){
	if(root == NULL){
		return 0;
	}
	else if(root -> left == NULL && root -> right == NULL){
		return 0;
	}
	else{
		return count_internal(root -> left) + count_internal(root -> right) + 1;
	}
}
