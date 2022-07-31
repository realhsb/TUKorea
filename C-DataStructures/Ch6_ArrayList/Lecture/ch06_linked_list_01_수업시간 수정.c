#include <stdio.h>
#include <stdlib.h>

//
//typedef int element;
typedef struct{
	char name[100]; // �ܾ� ����.
} element;
//
typedef struct ListNode { 	// ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

//
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = head;			//(3)
	head = p;				//(4)
	return head;
}

//
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = NULL;			//(3)
	if (head == NULL) {
		head = p;
	}
	else {
		// linked list�� ������ ��� ã��...  
		ListNode* temp;
		temp = head;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		// ������ ��� ������ ��� �߰��ϱ�...
		temp->link = p;
	}
	return head;
}



// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = pre->link;	//(3)	
	pre->link = p;			//(4)	
	return head;			//(5)	
}

//
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) return NULL;
	removed = head;			// (1)
	head = removed->link;	// (2)
	free(removed);			// (3)
	return head;			// (4)
}

// pre�� ����Ű�� ����� ���� ��带 �����Ѵ�. 
ListNode* delete_pre(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;	// (2)
	free(removed);				// (3)
	return head;				// (4)
}

// linked list ����ϱ�.
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%s->", p->data.name);
	printf("NULL \n");
}



// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;	// lisked list �� ����Ű�� ��� pointer.
	element  data;
	// 1.
	strcpy( data.name, "KIWI" );
	head = insert_last(head, data);
	print_list(head);
	// 2.
	strcpy(data.name, "APPLE");
	head = insert_last(head, data);
	print_list(head);
	// 3.
	strcpy(data.name, "BANANA");
	head = insert_last(head, data);
	print_list(head);
	
	//
	for (int i = 0; i < 3; i++) {
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}