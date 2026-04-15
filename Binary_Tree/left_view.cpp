//LEFT VIEW OF A BINARY TREE

#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node * create_node();
void left(struct node * root);

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

int height(struct node * root){
	if(root == NULL){
		return 0;
	}
	int l = height(root -> left);
	int r = height(root -> right);
	return 1 + (l > r ? l : r);
}

void level(struct node * root, int i, vector<int> &result){
	if(root == NULL){
		return;
	}
	if(i == 0){
		result.push_back(root -> data);
		return;
	}
	level(root -> left, i - 1, result);
	level(root -> right, i - 1, result);
}

void left(struct node * root){
	int i, h = height(root);
	for(i=0;i<h;i++){
		vector<int> result;
		level(root, i, result);
		if(!result.empty()){
			printf("%d ",result[0]);
		}
	}
}

int main(){
    struct node *root = create_node();
    printf("\nLeft View: ");
    left(root);
    return 0;
}
