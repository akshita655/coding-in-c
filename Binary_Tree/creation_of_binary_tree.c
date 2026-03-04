//CREATION OF BINARY TREE

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * left;
	struct node * right;
};

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

int main(){
	int c;
	struct node * root;
	root = NULL;
	root = create_node();
    return 0;
}


