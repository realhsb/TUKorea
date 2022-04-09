//예제 5-6 '참조에 의한 호출'로 Circle 객체에 참조 전달 
#include <iostream>
using namespace std;
class Circle{
    private :
    int radius;
    public :
    Circle();
    Circle(int r);
    ~Circle();
    double getArea(){return 3.14 * radius * radius;}
    int getRadius(){return radius;}
    void setRadius(int radius){this->radius = radius;}
};
Circle::Circle(){
    radius = 1;
    cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r){
    this->radius=radius;
    cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle(){
    radius = 1;
    cout << "소멸자 실행 radius = " << radius << endl;
}

void increase(Circle &c){   //참조 매개 변수 c
    int r = c.getRadius();
    c.setRadius(r+1);
}

int main(){
    Circle waffle(30);
    increase(waffle);       //참조에 의한 호출
    cout << waffle.getRadius() << endl;
}