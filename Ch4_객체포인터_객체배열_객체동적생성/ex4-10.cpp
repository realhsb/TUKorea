//[예제 4-10] 객체 배열의 동적 생성과 반환 응용
//[예제 4-9] 배열의 동적 생성 및 반환
#include <iostream>
using namespace std;
class Circle{
    int radius;
public :
    Circle();
    Circle(int r);
    ~Circle(){};
    void setRadius(int r) {radius = r;}
    double getArea() {return 3.14 * radius * radius;}
};

Circle::Circle(){
    radius = 1;
}

int main(){
    cout << "생성하고자 하는 원의 개수? ";
    int n, radius;
    cin >> n;
    Circle *pArray = new Circle[n];
    for(int i = 0; i < n; i++){
        cout << "원 " << i+1 << " : ";
        cin >> radius;
        pArray[i].setRadius(radius);
    }

    int count = 0;
    Circle *p = pArray;
    for(int i = 0; i < n; i++){
        cout << p->getArea() << ' ';
        if(p->getArea() >= 100 && p->getArea() <= 200){
            count++;
        }
        p++;
    }
    cout << endl << "면적이 100 이상 200이하인 원의 개수는 " << count << endl;
    delete [] pArray;
}