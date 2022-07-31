// [예제8-3] TV, WideTV, SmartTV 생성자 매개 변수 전달
#include <iostream>
#include <string>
using namespace std;

class TV{
    int size;
public :
    TV() {size = 20;}
    TV(int size) {this->size = size;}
    int getSize() {return size;}
};
class WideTV : public TV {
    bool videoIn;
public :
    WideTV(int size, bool videoIn) : TV(size){
        this->videoIn = videoIn;
    }
    bool getVideoIn() {return videoIn;}
};
//WideTV를 상속받는 SmartTV
class SmartTV : public WideTV {
    string ipAddr;
public :
    SmartTV(string ipAddr, int size) : WideTV(size, true){
        this->ipAddr = ipAddr;
    }
    string getIpAddr() {return ipAddr;}
};

int main(){
    // 32인치 크기에 "192.0.0.1"의 인터넷 주소를 가지는 스마트티비 객체 생성 
    SmartTV htv("1920.0.0.1", 32);
    cout << "size = " << htv.getSize() << endl;
    cout << "videoIn = " << boolalpha << htv.getVideoIn() << endl;  // boolalpha는 불린 값을 true, false로 출력되게 하는 조작자 
    cout << "IP = " << htv.getIpAddr() << endl; 
}