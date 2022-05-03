//예제 5-7 참조 매개 변수를 가진 함수 만들기 연습
//키보드로부터 반지름 값을 읽어 Circle객체에 반지름을 설정하는 readRadius() 함수를 작성하라.

#include <iostream>
using namespace std;

class Circle{
    int radius;
    public :
    Circle() {radius = 1;}
    Circle(int r) {this->radius = radius;}
    void setRadius(int radius) {this->radius = radius;}
    double getArea() {return 3.14 * radius * radius;}
};

void readRadius(Circle &c){
    int r;
    cout << "정수 값으로 반지름을 입력하세요>>";
    cin>>r;
    c.setRadius(r);
}

int main(){
    Circle donut;
    readRadius(donut);
    cout << "donut의 면적 = " << donut.getArea() << endl;
}