#include<stdio.h>
#include<stdlib.h>

struct node * create_node();
void post_order(struct node * root);

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
	post_order(root);
	return 0;
}

struct node * create_node(){
	int value;
	printf("Enter the data(-1 for no node): ");
	scanf("%d",&value);
	if(value == -1){
		return NULL;
	}
	struct node * newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	newnode -> data = value;
	printf("Enter Left Child of %d ",value);
	newnode -> left = create_node();
	printf("Enter Right Child of %d ",value);
	newnode -> right = create_node();
	return newnode;
}

void post_order(struct node * root){
	if(root == NULL){
		return;
	}
	post_order(root -> left);
	post_order(root -> right);
	printf("%d	",root -> data);
}
