#include <stdio.h>
#include <stdlib.h>

//
typedef int element;
//
typedef struct ListNode { 	// 노드 타입을 구조체로 정의한다.
	element data;
	struct ListNode* link;
} ListNode;

//
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;		//(2)
	p->link = head;			//(3)
	head = p;				//(4)
	return head;
}

// 노드 pre 뒤에 새로운 노드 삽입
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

// pre가 가리키는 노드의 다음 노드를 삭제한다. 
ListNode* delete_pre(ListNode* head, ListNode* pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link;	// (2)
	free(removed);				// (3)
	return head;				// (4)
}

// linked list 출력하기.
void print_list(ListNode* head)
{
	for (ListNode* p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}

int sum_list(ListNode *head){
	int sum = 0;
	for(ListNode* p = head; p != NULL; p = p->link){
		sum += p -> data;
	}
	return sum;
}


// 테스트 프로그램
int main(void)
{
	ListNode* head = NULL;	// lisked list 를 가리키는 헤드 pointer.

	//
	for (int i = 0; i < 5; i++) {
		head = insert_first(head, i);
		print_list(head);
	}
	//
	for (int i = 0; i < 5; i++) {
		head = delete_first(head);
		print_list(head);
	}

	return 0;
}