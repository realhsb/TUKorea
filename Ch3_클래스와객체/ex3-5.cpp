//[예제 3–5] 멤버변수의 초기화와 위임 생성자 활용
#include <iostream>
using namespace std;

class Point {
        int x, y;
    public :
        Point();
        Point(int a, int b);
        void show(){cout << "(" << x << ", " << y << ")" << endl;}
};
// Point::Point(){x = 0; y = 0;}
// Point::Point(int a, int b){x = a; y = b;}

Point::Point() : Point(0, 0){}
Point::Point(int a, int b)
    : x(a), y(b){
}
int main(){
    Point origin;
    Point target(10, 20);
    origin.show();
    target.show();
}