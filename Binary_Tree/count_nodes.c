#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node * create_node();
int count_node(struct node * root);

int main(){
    struct node * root;
    root = NULL;
    root = create_node();
    printf("Total Nodes are: %d", count_node(root));
    return 0;
}

struct node * create_node(){
    int value;
    printf("Enter the data (-1 for no node): ");
    scanf("%d",&value);
    if(value == -1){
        return NULL;
    }
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    printf("Enter Left Child of %d\n", value);
    newnode->left = create_node();
    printf("Enter Right Child of %d\n", value);
    newnode->right = create_node();
    return newnode;
}

int count_node(struct node * root){
    if(root == NULL){
        return 0;
    }
    return 1 + count_node(root->left) + count_node(root->right);
}
