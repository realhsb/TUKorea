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

int check_matching(const char *in){
    StackType s;
    char ch, open_ch;
    int i, n = strlen(in);        // n = 문자열의 길이
    init_stack(&s);                  // 스택 초기화

    for(i = 0; i < n; i++){
        ch = in[i];
        switch(ch){
        case '(' : case '{' : case '[' :            // 왼쪽 괄호면 스택에 삽입
            push(&s, ch);
            break;
        case ')' : case '}' : case ']' :            // 오른쪽 괄호면 스택에서 삭제 비교
            if(is_empty(&s)) return 0;
            else {
                open_ch = pop(&s);
                if((open_ch == '(' && ch != ')') ||
                    open_ch == '{' && ch != '}' ||
                    open_ch == '[' && ch != ']'){
                        return 0;
                    }
                break;
            }
        }
    }
    if(!is_empty(&s)) return 0;     // 스택에 괄호가 남아있으면 오류
    return 1;
}

int main(void){
    char *p = "{ A[(i+1)]=0; }";        //성공
    char *p2 = "{{}}}}}}";                  //실패
    if(check_matching(p2) == 1){
        printf("성공");
    }else {
        printf("실패");
    }
    return 0;
}