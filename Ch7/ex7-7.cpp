#include <iostream>
using namespace std;

class Power{
    int kick;
    int punch;
public :
    Power(int kick = 0, int punch = 0){
        this->kick = kick; this -> punch = punch;
    }
    void show();
    Power operator+ (int op2);    //+연산자 함수
};

void Power::show(){
    cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}

Power Power::operator+(int op2){
    Power tmp;      //임시 객체 생성
    tmp.kick = kick + op2;  //kick에 op2 더하기
    //punch에 op2 더하기
    tmp.punch = punch + op2;
    return tmp;                         //임시 객체 생성
}

int main(){
    Power a(3,5), b;
    a.show();
    b.show();
    b = a + 2;
    //b = 2 + a;    a랑 2를 반대로 적으면 에러 발생
    a.show();
    b.show();
}