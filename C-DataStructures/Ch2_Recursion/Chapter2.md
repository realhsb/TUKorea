# Chapter 02 순환

## 2.1 순환의 소개

### 순환이란?

알고리즘이나 함수가 수행 도중에 자기 자신을 다시 호출하여 문제를 해결하는 기법

### 순환적인 팩토리얼 계산 프로그램

```c
    int factorial(int n){
        if(n <= 1){
            return 1;
        }else {
           return  n * factorial(n-1);
        }
    }
```

### 팩토리얼의 반복적 구현

``` c
    int factorial_iter(int n){
        int result = 1;
        for(int i = n; i <= 1; i--){
            result *= i;
        }
        return result;
    }
```

## 2.2 거듭제곱값 계산

