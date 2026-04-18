//ZIGZAG LEVEL ORDER TRAVERSAL OF A BINARY TREE

#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include <algorithm>
using namespace std;

struct node * create_node();

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

vector<vector<int> > zigzag_level(struct node * root){
    vector<vector<int> > ans;
    if(root == NULL){
        return ans;
    }
    int h = height(root);
    for(int i = 0; i < h; i++){
        vector<int> result;
        level(root, i, result);
        if(i % 2 == 1){
            reverse(result.begin(), result.end());
        }
        ans.push_back(result);
    }
    return ans;
}

void print_zigzag(vector<vector<int> > ans){
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}

int main(){
    struct node *root = create_node();
    vector<vector<int> > ans = zigzag_level(root);
    printf("\nZigzag Level Order Traversal:\n");
    print_zigzag(ans);
    return 0;
}
