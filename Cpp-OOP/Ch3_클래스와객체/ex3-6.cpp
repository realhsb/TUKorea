// [예제 3-6] Rectangle 클래스 만들기
#include <iostream>
using namespace std;

class Rectangle {
        int width, height;
    public :
        Rectangle();
        Rectangle(int w, int h);
        Rectangle(int l);
        bool isSquare();
};

Rectangle::Rectangle(){
    width = height = 1;
}
Rectangle::Rectangle(int w, int h){
    width = w;
    height = h;
}
Rectangle::Rectangle(int l){
    width = height = l;
}
bool Rectangle::isSquare(){
    return width == height;
}

int main(){
    Rectangle rect1;
    Rectangle rect2(3, 5);
    Rectangle rect3(3);

    if(rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
    if(rect2.isSquare()) cout << "rect2은 정사각형이다." << endl;
    if(rect3.isSquare()) cout << "rect3은 정사각형이다." << endl;
}