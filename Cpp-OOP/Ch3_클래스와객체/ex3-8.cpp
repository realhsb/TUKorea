//[예제 3-8] 지역 객체와 전역 객체의 생성 및 소멸 순서
#include <iostream>
using namespace std;

class Circle{
    public :
        int radius;
        Circle();
        Circle(int r);
        ~Circle();
        double getArea();
};
Circle::Circle(){
    radius = 1;
     cout << "반지름 " << radius << " 원 생성" << endl;
}
Circle::Circle(int r){
    radius = r;
     cout << "반지름 " << radius << " 원 생성" << endl;
}
Circle::~Circle(){
     cout << "반지름 " << radius << " 원 소멸" << endl;
}
double Circle::getArea(){
    return 3.14 * radius * radius;
}
Circle globalDonut(1000);       // 전역 객체 생성
Circle globalPizza(2000);
void f(){
    Circle fDonut(100);             // 지역 객체 생성
    Circle fPizza(200);
}
int main(){
    Circle mainDonut;               // 지역 객체 생성
    Circle mainPizza(30);
    f();
}