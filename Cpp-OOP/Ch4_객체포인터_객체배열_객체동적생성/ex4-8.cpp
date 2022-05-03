// [예제 4-8] Circle 객체의 동적 생성과 반환 응용
#include <iostream>
using namespace std;
class Circle{
    int radius;
public :
    Circle();
    Circle(int r);
    ~Circle();
    void setRadius(int r) {radius = r;}
    double getArea() {return 3.14 * radius * radius;}
};

Circle::Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r){
    radius = r;
    cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle(){
    cout << "소멸자 실행 radius = " << radius << endl;
}
int main(){
    int radius;
    while(true){
        cout << "정수 반지름 입력 (음수면 종료) >> ";
        cin >> radius;
        if(radius < 0) break;
        Circle *p = new Circle(radius);
        cout << "원의 면적은 " << p->getArea() << endl;
        delete p;
    }
}