#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
} *root = NULL;

struct node* create_node(struct node *root, int data);
struct node* findMin(struct node *root);
struct node* deleteNode(struct node *root, int data);
void inorder(struct node *root);

int main() {
    int choice = 1, data;
    while(choice == 1){
        printf("Enter data to insert: ");
        scanf("%d", &data);
        root = create_node(root, data);
        printf("Want to enter more data? (0,1): ");
        scanf("%d", &choice);
    }
    printf("\nInorder before deletion: ");
    inorder(root);
    printf("\nEnter data to delete: ");
    scanf("%d", &data);
    root = deleteNode(root, data);
    printf("Inorder after deletion: ");
    inorder(root);
    return 0;
}

struct node* create_node(struct node *root, int data) {
    struct node *newnode;
    if (root == NULL) {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->left = NULL;
        newnode->data = data;
        newnode->right = NULL;
        return newnode;
    }
    else if (data < root->data) {
        root->left = create_node(root->left, data);
    }
    else {
        root->right = create_node(root->right, data);
    }
    return root;
}

struct node* findMin(struct node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct node* deleteNode(struct node *root, int data) {
    if (root == NULL) {
        return root;
    }

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        struct node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
