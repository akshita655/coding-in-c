#include<stdio.h>
#include<stdlib.h>

struct node * create_node(struct node *root, int data);

struct node{
	int data;
	struct node * left;
	struct node * right;
}*root = NULL;

struct node* create_node(struct node *root, int data) {
    struct node *newnode;
    if (root == NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->left = NULL;
        newnode->data = data;
        newnode->right = NULL;
        return newnode;
    } else if (data < root->data) {
        root->left = create_node(root->left, data);
    } else {
        root->right = create_node(root->right, data);
    }
    return root;
}

int rangeSum(struct node* root, int low, int high) {
    if (root == NULL)
        return 0;
    int sum = 0;
    if(root->data >= low && root->data <= high)
        sum += root->data;
    if(root->data > low)
        sum += rangeSum(root->left, low, high);
    if(root->data < high)
        sum += rangeSum(root->right, low, high);
    return sum;
}

int main() {
	int choice = 1, data;
	while(choice == 1){
		printf("Enter data to insert: ");
        scanf("%d", &data);
        root = create_node(root, data);
        printf("Want to enter more data?(0, 1) ");
        scanf("%d",&choice);
	}
	int low, high;
	printf("Enter low value for range sum: ");
	scanf("%d",&low);
	printf("Enter high value for range sum: ");
	scanf("%d",&high);
	int result = rangeSum(root, low, high);
	printf("Sum of the required range is: %d",result);
	return 0;
}

