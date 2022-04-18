// [예제 3–9] 헤더 파일과 cpp 파일로 분리하기
#include <iostream>
using namespace std;

class Adder {
        int op1, op2;
    public :
        Adder(int a, int b);
        int process();
};
Adder::Adder(int a, int b){
    op1 = a; op2 = b;
}
int Adder::process(){
    return op1 + op2;
}

class Calculator {
    public :
        void run();
};
void Calculator::run(){
    cout << "두 개의 수를 입력하세요 >>";
    int a, b;
    cin >> a >> b;          //두 개의 정수 입력
    Adder adder(a, b);
    cout << adder.process();
}

int main(){
    Calculator calc;
    calc.run();
}