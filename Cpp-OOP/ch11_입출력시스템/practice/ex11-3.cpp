#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cmd[80];
    cout << "cin.get(char*, int)로 문자열을 읽습니다." << endl;
    while(true){
        cout << "종료하려면 exit을 입력하세요 >> ";
        cin.get(cmd, 80);           // 79개까지의 영어 문자, 38개까지의 한글 문자 읽음 
            // '\n'은 입력 스트림 버퍼에 남겨둠 

        if(strcmp(cmd, "exit") == 0){
            cout << "프로그램을 종료합니다 ... ";
            return 0;
        }
        else
            cin.ignore(1);  // 버퍼에 남아 있는 <Enter> 키 ('\n') 제거 
    }
}

class Point {
    int x, y;
public : 
    Point(int x = 0, int y = 0) {this -> x = x; this -> y = y;}
}

ostream& operator << (ostream& stream, Point a){
    stream << "(" << a.x << ", " << a.y << ")";
    return stream;
}