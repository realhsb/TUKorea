// [예제 9-3] 상속이 반복되는 경우 가상 함수 호출
#include <iostream>
using namespace std;

class Base {
public :
    virtual void f() {cout << "Base::f() called" << endl;}
};
class Derived : public Base {
public :
    void f() {cout << "Derived::f() called" << endl;}
};
class GrandDerived : public Derived {
public :
    void f() {cout << "GrandDerived::f() called" << endl;}
};

int main(){
    GrandDerived g;
    Base *bp;
    Derived *dp;
    GrandDerived *gp;

    bp = dp = gp = &g;

    bp -> f();
    dp -> f();
    gp -> f();
}