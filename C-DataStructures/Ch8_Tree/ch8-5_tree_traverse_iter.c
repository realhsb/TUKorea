#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 100

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* stack[SIZE];
int top = -1;

void push(TreeNode *p){
	if(top < SIZE -1){
		stack[++top];
	}
}

TreeNode *pop(){
	TreeNode *p = NULL;
	if(top >= 0)
		p = stack[top--];
	return p;
}

void inorder_iter(TreeNode *root){
	while(1){
		for(; root; root = root->left)
			push(root);
		root = pop();
		if(!root) break;
		printf("[%d] ", root->data);
		root = root->right;
	}       
}