#include<stdio.h>
#include<stdlib.h>

struct node * create_node();
void free_tree(struct node *root);

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
	free_tree(root);
	printf("The tree data has been successfully removed from your memory.");
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

void free_tree(struct node *root) {
    if (root == NULL) {
        return;
    }
    free_tree(root->left);  // Free left subtree
    free_tree(root->right); // Free right subtree
    free(root); // Free the current node
}
