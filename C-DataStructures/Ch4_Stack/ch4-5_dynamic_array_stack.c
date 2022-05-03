#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100;

typedef int element;
typedef struct {
    element *data;       // data는 포인터로 정의
    int capacity;           // 현재 크기
    int top;
} StackType;

// 스택 생성 함수
void init_stack(StackType *s){
    s->top = -1;
    s->capacity = 1;
    s->data = (element *)malloc(s->capacity * sizeof(element));
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s){
    return (s->top == (s->capacity - 1));
}

// 삽입 함수
void push(StackType *s, element item){
    if(is_full(s)){
        s -> capacity *= 2;         // 공간이 부족하면 메모리를 2배로 더 확보
        s -> data = (element *)realloc(s->data, s->capacity * sizeof(element));
    }
    s -> data[++(s->top)] = item;
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

    int main(void) {
        StackType s;
        init_stack(&s);                     // 스택을 동적으로 할당
        push(&s, 1);
        push(&s, 2);
        push(&s, 3);
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        printf("%d\n", pop(&s));
        free(s.data);                       // 동적 메모리는 반드시 반환해야 한다.
        return 0;
    }
