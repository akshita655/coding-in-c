//LEVEL ORDER TRAVERSAL OF A BINARY TREE

#include<stdio.h>
#include<stdlib.h>

struct node * create_node();
void level_order(struct node * root);

struct node{
	int data;
	struct node * left;
	struct node * right;
};

int main(){
	int c;
	struct node * root;
	root = create_node();
	printf("\nLevel Order Traversal is: ");
	level_order(root);
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

int height(struct node * root){
	if(root == NULL){
		return 0;
	}
	int l = height(root -> left);
	int r = height(root -> right);
	return 1 + (l > r ? l : r);
}

void print_level(struct node * root, int i){
	if(i == 0){
		printf("%d ", root -> data);
		return;
	}
	print_level(root -> left, i - 1);
	print_level(root -> right, i - 1);
}

void level_order(struct node * root){
	int i;
	int h = height(root);
	for(i=0;i<h;i++){
		print_level(root, i);
	}
}


