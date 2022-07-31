//2021158041 한수빈
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
typedef int element;

//
typedef struct ListNode { 	
	element data;
	struct ListNode* link;
} ListNode;

void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

ListNode* insert_first(ListNode* head, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));	//(1)
	p->data = value;								//(2)
	p->link = head;			//(3)
	head = p;					//(4)
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

ListNode* concat_list(ListNode* head1, ListNode* head2)
{
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head2;
	else {
		ListNode* p;
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}

// ListNode* concat_list3(ListNode* head1, ListNode* head2, ListNode* head3)
// {
// 	ListNode* result;
// 	if (head1 == NULL) result = head2;
// 	else if (head2 == NULL) result = head1;
// 	else {
// 		result = head1;
// 		while (result->link != NULL)
// 			result = result->link;
// 		result->link = head2;
// 	}

// 	if(head3==NULL) return result;
// 	else {
// 		while(result->link != NULL)
// 			result = result -> link;
// 		result->link = head3;
// 		//return result;
// 	}
// 	return result;
// }

ListNode* concat_list3(ListNode* head1, ListNode* head2, ListNode* head3) {
	ListNode* result;
	if (head1 == NULL) {
		if(head2 == NULL) {
			result = NULL;
		}else {
			result = head2;
		}
	} else {
		result = head1;
		if(head2 != NULL){
			result = head1;
			while (result->link != NULL)
				result = result->link;
			result->link = head2;
		}
	}
	if(head3==NULL) return result;
	else {
		while(result->link != NULL)
			result = result -> link;
		result->link = head3;
	}
	return result;
}

	
	

int main(void)
{
	ListNode* head1 = NULL;
	ListNode* head2 = NULL;
	ListNode* head3 = NULL;

	printf("> head1 list 생성.\n");
	head1 = insert_first(head1, 10);
	print_list(head1);
	head1 = insert_first(head1, 20);
	print_list(head1);
	head1 = insert_first(head1, 30);
	print_list(head1);

	printf("> head2 list 생성.\n");
	head2 = insert_first(head2, 100);
	print_list(head2);
	head2 = insert_first(head2, 200);
	print_list(head2);
	head2 = insert_first(head2, 300);
	print_list(head2);

	printf("> head3 list 생성.\n");
	head3 = insert_first(head3, 1000);
	print_list(head3);
	head3 = insert_first(head3, 2000);
	print_list(head3);	

	printf("> After concat.\n");
	concat_list3(head1, head2, head3);
	print_list(head1);

	return 0;
}