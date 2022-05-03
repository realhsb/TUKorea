#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
typedef int element;
typedef struct {
    element data[MAX_STACK_SIZE];   //배열의 요소는 element 타입으로 선언
    int top;
} StackType;

// 스택 초기화 함수
void init_stack(StackType *s){
    s -> top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
    return (s -> top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s){
    return (s -> top == (MAX_STACK_SIZE - 1));
}

// 삽입 함수
void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }else {
        s->data[++(s->top)] = item;
    }
}

// 삭제 함수
element pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }else {
        return s->data[(s->top)--];
    }
}

// 피크 함수
element peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }else {
        return s->data[s->top];
    }
}

int main(){
    StackType s;

    init_stack(&s);
    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    printf("%d\n", peek(&s));
    printf("%d\n", peek(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
}