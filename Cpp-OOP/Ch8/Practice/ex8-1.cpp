#include <iostream>
#include <string>
using namespace std;

class Point {
    int x, y; 
public :
    void set(int x, int y){
        this->x = x; this->y = y;
    }
    void showPoint() {
        cout << "(" << x << "," << y << ")" << endl;
    }
};

class ColorPoint : public Point {
    // 2차원 평면에서 컬러 점을 표현하는 클래스
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


    ColorPoint cp;
    ColorPoint *pDer = &cp;
    Point *pBase = pDer;            // 업 캐스팅

    pDer -> set(3,4);
    pBase -> showPoint();
    pDer -> setColor("Red");
    pDer -> showColorPoint();
    pBase -> showColorPoint();      // 컴파일 오류 


    ColorPoint cp, *pDer;
    Point *pBase = &cp;     // 업캐스팅
    pBase -> set(3,4);
    pBase -> showPoint();

    pDer = (ColorPoint*)pBase;  // 다운 캐스팅
    pDer -> setColor("Red");
    pDer->showColorPoint();     // 정상 컴파일

    Point po, *pBase; 
    ColorPoint *pDer;
    pBase = &po; pDer=(ColorPoint*)pBase;
    pDer->set(3, 4);
    pDer->setColor(“red”);          // 컴파일 오류는 발생하지 않으나, 실행 오류 발생
}

