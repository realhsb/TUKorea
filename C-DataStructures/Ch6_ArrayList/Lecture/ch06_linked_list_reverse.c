#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef int element;

//
typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

// 오류 처리 함수
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
	p->link = head;	// 헤드 포인터의 값을 복사		//(3)
	head = p;		// 헤드 포인터 변경				//(4)
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
	// 순회 포인터로 p, q, r을 사용
	ListNode* p, * pp, * ppp;

	p = head;         		// p는 역순으로 만들 리스트
	pp = NULL;        		// q는 역순으로 만들 노드
	while (p != NULL) {
		ppp = pp;          		// r은 역순으로 된 리스트.    
						// r은 q, q는 p를 차례로 따라간다.
		pp = p;
		p = p->link;
		pp->link = ppp;      	// q의 링크 방향을 바꾼다.
	}
	return pp;
}

// 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;

	printf("> head list 생성.\n");
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