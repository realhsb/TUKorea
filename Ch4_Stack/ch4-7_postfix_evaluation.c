#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char element;
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

int eval(char exp[]){
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;

    init_stack(&s);
    for(i = 0; i < len; i++){
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/'){      //ch 가 피연산자(숫자)일 때
            value = ch - '0';                   // 숫자 char(0~9)는 아스키 코드 48부터 시작하므로, int 변수에 48을 빼주거나 '0'을 빼주어 만들어준다.
            push(&s, value);    
        }else {
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){
                case '+' : push(&s, op1+op2); break;
                case '-' : push(&s, op1-op2); break;
                case '*' : push(&s, op1*op2); break;
                case '/' : push(&s, op1/op2); break;
            }
        }
    }
    return pop(&s);
}

int main(void){
    int result;
    result = eval("82/3-32*+");         // 7
    printf("%d\n",result);
    return 0;
}