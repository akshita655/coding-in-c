#include<stdio.h>
#include<stdlib.h>

struct node * create_node(struct node *root, int data);

struct node{
	int data;
	struct node * left;
	struct node * right;
}*root = NULL;

struct node * build(int *nums, int start, int end){
	if(start > end){
		return NULL;
	}
	int mid = (start + end) / 2;
	struct node * root = (struct node *)malloc(sizeof(struct node));
	root -> data = nums[mid];
	root -> left = build(nums, start, mid-1);
	root -> right = build(nums, mid+1, end);
	return root;
}

void inorder(struct node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
	int nums[] = {2,3,5,15,23,44,56,62,89};
	int numsSize = 9;
	struct node * root = build(nums, 0, numsSize - 1);
    printf("Binary Search Tree (Inorder): ");
	inorder(root);
	return 0;
}

