#include <iostream>
#include <string>
using namespace std;

//2차원 평면에서 한점을 표현하는 클래스 Point선언
class Point {
    int x, y;
public :
    void set(int x, int y){
        this->x = x; this->y = y;
    }
    void showPoint(){
        cout << "(" << x << "," << y << ")"
        <<endl;
    }
};

class ColorPoint : public Point {
    string color;
public :
    void setColor(string color) {this->color = color;}
    void showColorPoint();
};

void ColorPoint::showColorPoint(){
    cout << color << ":";
    showPoint();
}

int main(){
    Point p;
    ColorPoint cp;
    cp.set(3,4);
    cp.setColor("Red");
    cp.showColorPoint();
}