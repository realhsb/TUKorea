// [예제 8-2] protected 멤버에 대한 접근
#include <iostream>
#include <string>
using namespace std;

class Point {
protected :
    int x, y;   // 한 점 (x, y) 좌표값
public :
    void set(int x, int y);
    void showPoint();
};
void Point::set(int x, int y){
    this->x = x;
    this->y = y;
}
void Point::showPoint(){
    cout << "(" << x << "," << y << ")" << endl;
}

class ColorPoint : public Point {
    string color;
public :
    void setColor(string color);
    void showColorPoint();
    bool equals(ColorPoint p);
};
void ColorPoint::setColor(string color){
    this->color = color;
}
void ColorPoint::showColorPoint(){
    cout << color << ":";
    showPoint();        // Point클래스의 showPoint() 호출
}

bool ColorPoint::equals(ColorPoint p){
    if(x == p.x && y == p.y){
        return true;
    }else {
        return false;
    }
}

int main(){
    Point p;            // 기본 클래스의 객체 생성
    p.set(2,3);
    //p.x = 5;              // 오류! protected 변수를 Point 클래스 내부에서 접근하는 것이 아니므로 에러. main()은 외부 
   // p.y = 3;
    p.showPoint();
    ColorPoint cp;  // 파생 클래스의 객체 생성
    // cp.x = 10;       // 오류! Point 클래스의 protected 변수를 ColorPoint 클래스 내부에서 접근하는 것이 아니므로 에러. main()은 외부 
    // cp.y = 10;
    cp.set(3,4);    cp.setColor("Red"); cp.showColorPoint();
    ColorPoint cp2;
    cp2.set(3,4); cp2.setColor("Red");
    cout << ((cp.equals(cp2)) ? "true" : "false");
}