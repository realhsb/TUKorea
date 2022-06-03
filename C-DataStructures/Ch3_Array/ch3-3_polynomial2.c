#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
typedef struct {
    float coef;     //계수
    int expon;      //차수 degree
} polynomial;

polynomial terms[MAX_TERMS] = {{8,3},{7,1},{1,0},{10,3},{3,2},{1,0}};    
                                                // A :  0      1       2  /B : 3      4      5
int avail = 6;

//두 개의 정수 비교
char compare(int a, int b){
    if (a>b) return '>';
    else if(a==b) return '=';
    else return '<';
}

//새로운 항을 다항식에 추가
void attach(float coef, int expon){
    if(avail >MAX_TERMS){
        fprintf(stderr, "항의 개수가 너무 많음\n");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail].expon = expon;
    avail++;
}

// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce){
    float tempcoef;
    *Cs = avail;
    while (As <= Ae && Bs <= Be){
        switch (compare(terms[As].expon, terms[Bs].expon)) { // 차수 비교
            case '>' :          // A의 차수 > B의 차수
                attach(terms[As].coef, terms[As].expon);
                As++;
                break;
            case '=' :      // A == B
                tempcoef = terms[As].coef + terms[Bs].coef;
                if(tempcoef)
                    attach(tempcoef, terms[As].expon);
                As++; Bs++;
                break;
            case '<' :      // A < B
                attach(terms[Bs].coef, terms[Bs].expon);
                Bs++;
                break;
        }
    }

    // 어느 한 방정식이 완료되면 남은 방정식의 항들을 옮겨줌

    // A의 나머지 항들 이동
    for(; As <= Ae; As++){
        attach(terms[As].coef, terms[As].expon);
    }

    // B의 나머지 항들 이동
    for(; Bs <= Be; Bs++){
        attach(terms[Bs].coef, terms[Bs].expon);
    }
    *Ce = avail - 1;
}

void print_poly(int s, int e){
    for(int i = s; i < e; i++){
        printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
    }
    printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

int main(void){
    int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
    poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
    print_poly(As, Ae);
    print_poly(Bs, Be);
    printf("---------------------------\n");
    print_poly(Cs, Ce);
    return 0;
}