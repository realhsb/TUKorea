#include <stdio.h>
#include <stdlib.h>

// 스택이 전역 변수로 구현된다. 
// 스택 element : int
#define	MAX_STACK_SIZE	100		// 스택의 최대 크기

typedef int element;

typedef struct {
	element  	data[MAX_STACK_SIZE];
	int				top;
} StackType;
	

// 공백 상태 검출 함수
int is_empty(StackType *s)
{
	return (s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// 삽입 함수
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}else {
		(s->top)++;
		s->data[s->top] = item;
	}
}
// 삭제 함수
element pop(StackType* s)
{
	element temp;
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		temp = s->data[s->top];
		(s->top)--;
		return temp;
	}
}
// 피크 함수
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

/*
void print_stack(void)
{
	// 1. 스택에 있는 ele. 수 출력 = top + 1
	printf("Stack (%d 개) : ", top + 1);
	for (int i = 0; i <= top; i++) {
		printf("[%d] ", stack[i]);
	}
	printf("\n");
}
*/

void init_stack(StackType* s)
{
	s->top = -1;
}


int main(void)
{
	StackType  s1, s2, s3;

	init_stack( &s1 );
	init_stack( &s2 );
	init_stack( &s3 );

	push(&s1, 1);
	push(&s1, 2);
	push(&s1, 3);

	push(&s2, 100);
	push(&s2, 101);

	push(&s3, 200);
	push(&s3, 201);

	printf("%d\n", pop(&s1));
	printf("%d\n", pop(&s2));
	printf("%d\n", pop(&s3));

	return 0;
}
