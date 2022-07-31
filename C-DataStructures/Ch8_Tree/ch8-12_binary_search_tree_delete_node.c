#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int key;
    struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int item){
    TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode* insert_node(TreeNode* node, int key){
    if(node == NULL){
        return new_node(key);
    }
    
    if(key < node->key){
        node->left = insert_node(node->left, key);
    }else if(key > node->key) {
        node->right = insert_node(node->right, key);
    }

    return node;
}

TreeNode* min_value_node(TreeNode* node){
    TreeNode* current = node;

    // 맨 왼쪽 단말 노드를 찾으러 내려감
    while(current->left!=NULL){
        current = current->left;
    }
    return current;
}

// 이진 탐색 트리와 키가 주어지면 키가 저장된 노드를 삭제하고
// 새로운 루트 노드를 반환
TreeNode* delete_node(TreeNode* root, int key){
    if(root == NULL) return root;

    // 만약 키가 루트보다 작으면 왼쪽 서브 트리에 있는 것
    if(key < root->key){
        root->left = delete_node(root->left, key);
    }else if(key > root->key){
        root->right = delete_node(root->right, key);
    }else {  // 키가 루트와 같으면 이 노드를 삭제
        // 첫 번째나 두 번째 경우
        if(root->left == NULL){
            TreeNode* temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            TreeNode* temp = root->left;
            free(root);
            return temp;
        }

        // 세 번째 경우
        TreeNode* temp = min_value_node(root->right);
        // 중외 순회시 후계 노드를 복사한다
        root->key = temp->key;
        // 중외 순회시 후계 노드를 삭제한다
        root->right = delete_node(root->right, temp->key);
    }
    return root;
}

TreeNode* search(TreeNode* node, int key){
    if(node == NULL){
        return NULL;
    }

    if(key == node->key){
        return node;
    }else if(key < node->key){
        return search(node->left, key);
    }else {
        return search(node->right, key);
    }
}

inorder(TreeNode* root){
    if(root){
        inorder(root->left);
        printf(" [%2d] ", root->key);
        inorder(root->right);
    }
}

preorder(TreeNode* root){
    if(root){
        printf(" [%2d] ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

postorder(TreeNode* root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf(" [%2d] ", root->key);
    }
}

int main(void)
{
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);

	printf("이진 탐색 트리 중위 순회 결과 \n");
	inorder(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("이진 탐색 트리에서 30을 발견함 \n");
	else
		printf("이진 탐색 트리에서 30을 발견못함 \n");
	return 0;
}