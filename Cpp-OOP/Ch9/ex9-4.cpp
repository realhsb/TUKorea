// [예제 9-4] 범위 지정 연산자(::)를 이용한 기본 클래스의 가상 함수 호출
#include <iostream>
using namespace std;

class Shape {
public :
    virtual void draw(){
        cout << "--Shape--";
    }
};

class Circle : public 