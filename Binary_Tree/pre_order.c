#include<stdio.h>
#include<stdlib.h>

struct node * create_node();
void pre_order(struct node * root);

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
	pre_order(root);
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

void pre_order(struct node * root){
	if(root == NULL){
		return;
	}
	printf("%d	",root -> data);
	pre_order(root -> left);
	pre_order(root -> right);
}
