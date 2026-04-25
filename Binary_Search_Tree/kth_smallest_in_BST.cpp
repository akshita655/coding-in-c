#include <iostream>
#include <vector>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};

node* root = NULL;

node* create_node(node* root, int data){
    if(root == NULL){
        node* newnode = new node();
        newnode->data = data;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
    }
    else if(data < root->data){
        root->left = create_node(root->left, data);
    }
    else{
        root->right = create_node(root->right, data);
    }
    return root;
}

void inorder(node* root, vector<int> &result){
    if(root == NULL){
        return;
    }
    inorder(root->left, result);
    result.push_back(root->data);   // ? fixed
    inorder(root->right, result);
}

int main(){
    int choice = 1, data;
    while(choice == 1){
        cout << "Enter data to insert: ";
        cin >> data;
        root = create_node(root, data);
        cout << "Want to enter more data? (0/1): ";
        cin >> choice;
    }

    int k;
    cout << "Enter k: ";
    cin >> k;
    vector<int> result;
    inorder(root, result);
    cout << "Kth smallest element: " << result[k-1];   // ? correct
    return 0;
}
