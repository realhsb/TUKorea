//[예제 3-2] Rectangle 클래스 만들기
#include <iostream>
using namespace std;
class Rectangle {
    public :
        int radius;
        int width;
        int height;
        double getArea();
};
double Rectangle::getArea(){
    return width * height;
}

int main(){
    Rectangle rect;
    rect.width = 3;
    rect.height = 5;
    cout << "사각형 면적은 " << rect.getArea() << endl;
}