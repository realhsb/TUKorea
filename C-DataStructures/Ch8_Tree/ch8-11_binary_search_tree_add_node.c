#include <stdio.h>
#include <stdlib.h>
#define TRUE	1
#define FALSE	0

typedef struct TreeNode {
	int		key;
	struct	TreeNode* left, * right;
} TreeNode;

TreeNode* btree = NULL;

TreeNode* new_node(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key){

    // 트리가 공백이면 새로운 노드를 반환
    if(node==NULL){
        return new_node(key);
    }

    // 그렇지 않으면 순환적으로 트리를 내려간다
    if(key < node->key){
        node->left = insert_node(node->left, key);
    }else if(key > node->key){
        node->right = insert_node(node->right, key);
    }

    // 변경된 루트 포인터를 반환
    return node;
}

// 반복적인 탐색 함수
TreeNode* search_iter(TreeNode* node, int key){
    while(node!=NULL){
        if(key == node->key){
            return node;
        }else if(key < node->key){
            node = node->left;
        }else {
            node = node->right;
        }
    }
    return NULL;        // 탐색에 실패했을 경우 ,NULL  반환 
}

// 순환적인 탐색 함수
TreeNode* search_recur(TreeNode* node, int key){
    if(node==NULL){
        return NULL;
    }

    if(key == node->key){
        return node;
    }else if(key < node->key){
        return search_recur(node->left, key);
    }else {
        return search_recur(node->right, key);
    }
}

// 중위 순회
inorder(TreeNode* root){
    if(root){
        inorder(root->left);    // 왼쪽서브트리 순회
        printf("%d ", root->key);    // 노드 방문
        inorder(root->right);   // 오른쪽서브트리 순회
    }
}

// 전위 순회
preorder(TreeNode* root){
    if(root){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

// 후위 순회
postorder(TreeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

int main(void)
{
	btree = insert_node( btree, 5 );
	btree = insert_node( btree, 4 );
	btree = insert_node( btree, 3 );
	btree = insert_node( btree, 2 );
	btree = insert_node( btree, 1 );

	inorder( btree );
    printf("\n");
    preorder(btree);
       printf("\n");
    postorder(btree);
	
	return 0;
}