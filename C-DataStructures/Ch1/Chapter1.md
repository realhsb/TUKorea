# Chapter 01 자료구조와 알고리즘

## 1.1 자료구조와 알고리즘

자료구조 : 프로그램에서 자료들을 정리하여 보관하는 여러 가지 구조들
알고리즘 : 컴퓨터로 문제를 풀기 위한 단계적인 절차

### 함수 1.1 최대값 구하기

- 자료구조와 알고리즘은 밀접한 관계를 가지고 있음
  - 프로그램 효율성을 고려하여 자료구조를 결정하면, 자료구조를 활용하는 알고리즘을 선택 또는 설계

```c
#define MAX_ELEMENT 100
int score[MAX_ELEMENT];         //자료구조

int get_max_score(int n){           //학생 수 n
    int i, largest; 
    largest = score[0];
    for(i = 1; i < n; i++){
        if(score[i] > largest){
            largest = score[i];         //알고리즘
        }
    }
    return largest;
}
```

### 알고리즘이란?

- 알고리즘 : 컴퓨터로 문제를 풀기 위한 단계적인 절차
- 문제를 해결하는 방법 고안의 예
  - 문제 : 전화번호 부에서 특정한 사람의 이름 찾기
  - 방법1) 첫 페이지부터 순차적으로 검색 -> 비효율
  - 방법2) 정렬된 상황을 가정하면 이진 탐색(binary search) 방법 사용

### 알고리즘의 조건

- 입력 : 0개 이상의 입력 존재
- 출력 : 1개 이상의 출력 존재
- 명백성 : 각 명령어의 의미는 모호하지 않고 명확
- 유한성 : 한정된 수의 단계 후에는 반드시 종료
- 유효성 : 각 명령어들은 실행 가능한 연산

설명

- 알고리즘은 입력은 없어도 되지만 출력은 반드시 하나 이상 존재해야 함
- 모호한 방법으로 기술된 명령어들의 집합은 알고리즘이라고 할 수 없음
- 실행할 수 없는 명령어(divide by zero)를 사용해도 알고리즘이 아님
- 무한히 반복되어 종료되지 않는 명령어들의 집합도 알고리즘이 아님

### 알고리즘의 기술 방법

- 한글이나 영어 같은 자연어
  - 사람이 읽기 쉬움, 모호성 존재, 모호성을 제거하기 위해 명령어로 사용되는 단어들을 명백하게 정의
  - 예) 배열에서 최대값 찾기 알고리즘
    - ArrayMax(list, n)
    - 1. 배열 list의 첫 번째 요소를 변수 max에 복사
    - 2.배열 list의 다음 요소들을 차례대로 max와 비교하면 더 크면 max로 복사
    - 3. 배열 list의 모든 요소를 비교했으면 max를 반환

- 흐름도(flow chart)
  - 도형을 이용해서 알고리즘을 기술, 복잡할수록 기술하기 힘듦

- 의사 코드(pseudo-code / 슈도코드)
  - 알고리즘 기술하는 용도로 주요 사용되는 언어로서 자연어보다 체계적이고 프로그래밍 언어보다 덜 엄격
ArrayMax(list, N):
    largest <- list[0]
    for i<- 1 to N-1 do
        if list[i] > largest
            then largest<-list[i]
    return largest

- 프로그래밍 언어
  - 예약어들이 명백한 의미를 가져서 알고리즘 기술에 적합

## 1.2 추상 자료형

### 자료형(data type)이란?

- 자료형 : 데이터의 종류
- 기초 자료형 : char, int, float, double ...
- 파생 자료형 : 배열, 포인터
- 사용자 정의 자료형 : 구조체, 공용체, 열거형

자료형

- 데이터의 집합과 연산의 집합
  - 데이터의 종류가 결정되면 데이터에 적용할 수 있는 연산의 종류도 달라짐
  - 모듈러(modular) 연산의 경우 정수에만 적용할 수 있고 실수에는 적용할 수 없는 연산에 해당
- 복잡한 자료형에 대한 연산
  - 연산자가 아닌 함수로 정의, 스택에서 값을 추가하는 연산은 +가 아닌 add()함수로 정의

### 추상 데이터 타입(ADT)이란?

- 데이터 타입을 추상적(수학적)으로 정의한 것
- 데이터나 연산이 무엇인가는 정의되지만, 데이터나 연산을 어떻게 컴퓨터 상에서 구현할 것인지는 정의되지 않음

유래

- 추상화란, 사용자에게 중요한 정보는 강조되고 중요하지 않은 구현 세부 사항은 제거
  - 시스템의 핵심적인 구조나 동작에 집중

### 추상 데이터 타입의 정의

- ADT의 정의 : ADT는 객체와 함수들로 정의
  - 객체 : 추상 데이터 타입에 속하는 객체 정의
  - 연산 : 객체들 사이의 연산 정의. 연산은 추상 데이터 타입과 외부를 연결하는 인터페이스의 역할 수행

### 추상 데이터 타입의 예

자연수

- 객체지향언어에서 ADT는 클래스 형태로 구현

- 사용자들은 ADT가 제공하는 연산만 사용 가능
- 사용자들은 ADT가 제공하는 연산들을 사용하는 방법을 알아야 함
- 사용자들은 ADT 내부의 데이터를 접근할 수 없음
- 사용자들은 ADT가 어떻게 구현되는지 몰라도 ADT 사용 가능
  
  ## 1.3 알고리즘의 성능분석 방법

  - 수행 시간 측정 방법
    - 두 개의 알고리즘의 실제 수행 시간을 측정
    - 실제로 구현하는 것이 필요
    - 동일한 하드웨어 사용
  - 알고리즘의 복잡도 분석 방법
    - 직접 구현하지 않고서도 수행 시간 분석
    - 알고리즘이 수행하는 연산의 횟수를 측정하여 비교
    - 일반적으로 연산의 횟수는 n의 함수

### 왜 프로그램의 효율성이 중요한가?

- 컴퓨터 기술 발전, 메모리 용량 증가, 그리고 CPU 성능 개선
- 프로그램 규모가 커지고 있으므로 효율성 매우 중요
  - 처리해야 할 데이터 양 증가
- 실행 속도가 빠른 프로그램에 대한 선호도가 높음

효율적인 알고리즘이란? 결과가 나올 때까지 실행 시간이 짧으면서 컴퓨터 내에 메모리와 기타 자원들을 덜 사용하는 알고리즘

### 수행시간 측정 방법 - 1

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    clock_t start, stop;
    double duration;
    start = clock();                    // 측정 시작

    for(int i = 0; i < 1000000; i++);       // 의미 없는 반복 루프

    stop = clock();
    duration = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("수행시간은 %f초입니다.\n", duration);
    return 0;
}
```

문제점

- 알고리즘을 구현하고 테스트해야 함
  - 복잡한 알고리즘은 구현하기 부담스러움
- 반드시 똑같은 하드웨어를 사용해야 함
  - 슈퍼컴퓨터상 비효율적이라도 pc상에서는 더 빨리 수행 가능
- 소프트웨어 환경 중요
  - C와 같은 컴파일 언어가 베이직 같은 인터프리트 언어보다 빠른 수행
- 실험에 사용했던 데이터가 아닌 데이터에 대해서는 전혀 다른 결과가 나올 수 있음
  - 즉 실험되지 않은 데이터에 대해서는 수행시간을 주장할 수 없음

```c
#include <stdio.h>
#include <time.h>
#define DATA_SIZE 10000
#define LOOP_CNT 10000
int main(void){
    int data[DATA_SIZE];
    double result = 0.0;
    clock_t start, end;
    double duration;

    //data 배열 값 초기화
    for(int i = 0; i < DATA_SIZE; i++){
        data[i] = i + 1;
    }

    // 실행 속도 측정 시작
    printf("> 측정 시작.\n");
    start = clock();    //msec
    for(int j = 0; j < LOOP_CNT; j++){
        for(int i = 0; i < DATA_SIZE; i++){
            result += (double) data[i];
        }
    }
    end = clock();
    printf("> 측정 완료.\n");
    // 속도 측정 완료
    duration =(double) (end - start)  / CLOCKS_PER_SEC;

    printf("> 실행 시간 = %1f  sec\n", duration);
    printf("> CLOCKS_PER_SEC : %d\n",  CLOCKS_PER_SEC);
}
```

실행 결과
 측정 시작.
> 측정 완료.
> 실행 시간 = 0.237112  msec
> CLOCKS_PER_SEC : 1000000

``` c
#include <stdio.h>
#include <time.h>
#define DATA_SIZE 10000
#define LOOP_CNT 10000
int main(void){
    int data[DATA_SIZE];
    double result = 0.0;
    time_t start, end;
    double duration;

    //data 배열 값 초기화
    for(int i = 0; i < DATA_SIZE; i++){
        data[i] = i + 1;
    }

    // 실행 속도 측정 시작
    printf("> 측정 시작.\n");
    start = time(NULL);   //msec
    for(int j = 0; j < LOOP_CNT; j++){
        for(int i = 0; i < DATA_SIZE; i++){
            result += (double) data[i];
        }
    }
    end = time(NULL);
    printf("> 측정 완료.\n");
    // 속도 측정 완료
    duration =(double) (end - start);

    printf("> 실행 시간 = %1f  sec\n", duration);
}
```
