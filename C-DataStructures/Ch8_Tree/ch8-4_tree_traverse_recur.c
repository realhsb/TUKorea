#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

//          15
//      4       20
//  1       16      25

TreeNode n1 = {1, NULL, NULL};
TreeNode n2 = {4, &n1, NULL};
TreeNode n3 = {16, NULL, NULL};
TreeNode n4 = {25, NULL, NULL};
TreeNode n5 = {20, &n3, &n4};
TreeNode n6 = {15, &n2, &n5};
TreeNode* root = &n6;

// 중위순회
inorder(TreeNode* root){
    if(root){  
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 전위 순회
preorder(TreeNode* root){
    if(root){
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위 순회
postorder(TreeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}