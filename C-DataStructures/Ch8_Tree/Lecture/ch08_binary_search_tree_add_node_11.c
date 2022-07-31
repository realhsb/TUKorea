#include <stdio.h>
#define TRUE	1
#define FALSE	0

typedef struct TreeNode {
	int		key;
	struct	TreeNode* left, * right;
} TreeNode;

/*
//		     G
//	     C		  F
//    A	   B   D     E
TreeNode n1 = { 'A',	NULL,	NULL };
TreeNode n2 = { 'B',	NULL,	NULL };
TreeNode n3 = { 'C',	&n1,	&n2 };
TreeNode n4 = { 'D',	NULL,	NULL };
TreeNode n5 = { 'E',	NULL,	NULL };
TreeNode n6 = { 'F',	&n4,	&n5 };
TreeNode n7 = { 'G',	&n3,	&n6 };
*/
TreeNode* btree = NULL;

TreeNode* new_node(int item)
{
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key	= item;
	temp->left	= temp->right	= NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key)
{
	// Ʈ���� �����̸� ���ο� ��带 ��ȯ�Ѵ�. 
	if (node == NULL) {
		return new_node(key);
	}

	// �׷��� ������ ��ȯ������ Ʈ���� ��������. 
	if (key < node->key) {
		node->left = insert_node(node->left, key);
	}
	else if (key > node->key) {
		node->right = insert_node(node->right, key);
	}

	// ����� ��Ʈ �����͸� ��ȯ�Ѵ�. 
	return node;
}

// �ݺ����� Ž�� �Լ�
TreeNode* search_iter(TreeNode* node, int key)
{
	while (node != NULL) {
		if (key == node->key) {
			return node;
		}
		else if (key < node->key) {
			node = node->left;
		}
		else {
			node = node->right;
		}
	}
	return NULL; 	// Ž���� �������� ��� NULL ��ȯ
}

// ��ȯ���� Ž�� �Լ�
TreeNode* search_recur(TreeNode* node, int  key)
{
	if (node == NULL) {
		return NULL;
	}
	if (key == node->key) {
		return node;     // (1)
	}
	else if (key < node->key) {
		return  search_recur(node->left, key);		// (2)
	}
	else {
		return  search_recur(node->right, key);		// (3)
	}
}

// ���� ��ȸ
inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		printf("%d ", root->key); 	// ��� �湮
		inorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
preorder(TreeNode* root) {
	if (root) {
		printf("%d ", root->key); 	// ��� �湮
		preorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}

// ���� ��ȸ
postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);	// ���� ���� Ʈ�� ��ȸ
		postorder(root->right);	// ������ ���� Ʈ�� ��ȸ
		printf("%d ", root->key); 	// ��� �湮
	}
}

//
int main(void)
{
	btree = insert_node( btree, 5 );
	btree = insert_node( btree, 4 );
	btree = insert_node( btree, 3 );
	btree = insert_node( btree, 2 );
	btree = insert_node( btree, 1 );

	inorder( btree );
	
	return 0;
}