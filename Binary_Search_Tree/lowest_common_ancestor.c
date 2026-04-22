//LOWEST COMMON ANCESTOR IN A BINARY TREE

#include<stdio.h>
#include<stdlib.h>

struct node * create_node();
void level_order(struct node * root);

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

struct node * lca(struct node * root, struct node * p, struct node * q){
	if(root == NULL || root == p || root == q){
		return root;
	}
	if((root -> left == p || root -> left == q) && (root -> right == p || root -> right == q)){
		return root;
	}
	struct node * left = lca(root -> left, p, q);
	struct node * right = lca(root -> right, p, q);
	if(left != NULL && right != NULL) {
		return root;
	}
	return (left == NULL) ? right : left;
}

struct node* find_node(struct node* root, int val){
    if(root == NULL) return NULL;
    if(root->data == val) return root;
    struct node* left = find_node(root->left, val);
    if(left != NULL) return left;
    return find_node(root->right, val);
}

int main(){
    struct node *root = create_node();
    int x, y;
    printf("\nEnter first node value: ");
    scanf("%d", &x);
    printf("Enter second node value: ");
    scanf("%d", &y);
    struct node* p = find_node(root, x);
    struct node* q = find_node(root, y);
    if(p == NULL || q == NULL){
        printf("\nOne or both nodes not found!");
        return 0;
    }
    struct node* ans = lca(root, p, q);
    if(ans != NULL){
        printf("\nLowest Common Ancestor: %d", ans->data);
    }
    else{
        printf("\nNo LCA found.");
    }
    return 0;
}
