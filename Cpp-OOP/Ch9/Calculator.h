//[예제 9-6]
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
class Calculator {
public :
    virtual int add(int a, int b) = 0;  // 두 정수의 합 리턴
    virtual int subtract(int a, int b) = 0;     // 두 정수의 차 리턴
    virtual double average(int a[], int size) = 0; // 배열 a의 평균 리턴, size는 배열의 크기
};

#endif