#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef int element;

//
typedef struct ListNode { 	// ��� Ÿ���� ����ü�� �����Ѵ�.
	element data;
	struct ListNode* link;
} ListNode;

// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

//
ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;								//(2)
	p->link = head;	// ��� �������� ���� ����		//(3)
	head = p;		// ��� ������ ����				//(4)
	return head;
}

//
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

//
ListNode* reverse(ListNode* head)
{
	// ��ȸ �����ͷ� p, q, r�� ���
	ListNode* p, * pp, * ppp;

	p = head;         		// p�� �������� ���� ����Ʈ
	pp = NULL;        		// q�� �������� ���� ���
	while (p != NULL) {
		ppp = pp;          		// r�� �������� �� ����Ʈ.    
						// r�� q, q�� p�� ���ʷ� ���󰣴�.
		pp = p;
		p = p->link;
		pp->link = ppp;      	// q�� ��ũ ������ �ٲ۴�.
	}
	return pp;
}

// �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;

	printf("> head list ����.\n");
	head = insert_first(head, 10);
	print_list(head);
	head = insert_first(head, 20);
	print_list(head);
	head = insert_first(head, 30);
	print_list(head);

	printf("> After concat.\n");
	head = reverse(head);
	print_list(head);

	return 0;
}