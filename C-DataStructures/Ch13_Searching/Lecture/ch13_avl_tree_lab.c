#include<stdio.h> 
#include<stdlib.h> 
#define MAX(a, b) (a)
// AVL Ʈ�� ��� ����
typedef struct AVLNode
{
	int key;
	struct AVLNode *left;
	struct AVLNode *right;
} AVLNode;

void print_tree(AVLNode* root);

// Ʈ���� ���̸� ��ȯ
int get_height(AVLNode *node)
{
	int height = 0;

	if (node != NULL)
		height = 1 + max(get_height(node->left),
			get_height(node->right));

	return height;
}
// ����� �����μ��� ��ȯ
int get_balance(AVLNode* node)
{
	if (node == NULL) return 0;

	return get_height(node->left)
		- get_height(node->right);
}

// ��带 �������� �����ϴ� �Լ�
AVLNode* create_node(int key)
{
	AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return(node);
}

// ���������� ȸ����Ű�� �Լ�
AVLNode *rotate_right(AVLNode *parent)
{
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;

	// ���ο� ��Ʈ�� ��ȯ
	return child;
}

// �������� ȸ����Ű�� �Լ�
AVLNode *rotate_left(AVLNode *parent)
{
	AVLNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;

	// ���ο� ��Ʈ ��ȯ
	return child;
}

// AVL Ʈ���� ���ο� ��� �߰� �Լ�
// ���ο� ��Ʈ�� ��ȯ�Ѵ�. 
AVLNode* insert(AVLNode* node, int key)
{
	//printf("- insert(%d)\n", key);
	// ���� Ž�� Ʈ���� ��� �߰� ����
	if (node == NULL)
		return(create_node(key));

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else	// ������ Ű�� ������ ����
		return node;

	// ������ �����μ� ����
	int balance = get_balance(node);

	// LL Ÿ�� ó��
	if (balance > 1 && key < node->left->key) {
		printf("-- LL type - rotate right(%d)\n", key);
		return rotate_right(node);
	}

	// RR Ÿ�� ó��
	if (balance < -1 && key > node->right->key) {
		printf("-- RR type - rotate left(%d)\n", key);
		return rotate_left(node);
	}

	// LR Ÿ�� ó��
	if (balance > 1 && key > node->left->key)
	{
		printf("-- LR type - rotate left & right(%d)\n", key);
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}

	// RL Ÿ�� ó��
	if (balance < -1 && key < node->right->key)
	{
		printf("-- RL type - rotate right & left(%d)\n", key);
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

// ���� ��ȸ �Լ�
void preorder(AVLNode *root)
{
	if (root != NULL)
	{
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

// ���� ��ȸ �Լ�
void inorder(AVLNode* root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("[%d] ", root->key);
		inorder(root->right);
	}
}

// ���� ��ȸ �Լ�
void postorder(AVLNode* root)
{
	if (root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d] ", root->key);
	}
}

int main(void)
{
	AVLNode *root = NULL;

	// ���� Ʈ�� ����
	printf("\n> insert(%d)\n", 7);
	root = insert(root, 7);
	print_tree(root);

	return 0;
}

void print_tree(AVLNode* root)
{
	printf("----->pre:	");
	preorder(root);
	printf("\n");
	printf("----->in:	");
	inorder(root);
	printf("\n");
	printf("----->port:	");
	postorder(root);
	printf("\n");
}
