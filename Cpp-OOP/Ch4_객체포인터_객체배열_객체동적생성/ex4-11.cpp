//[예제 4–11] string 클래스를 이용한 문자열 생성 및 출력
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string address("서울시");
    string copyAddress(address);

    char text[] = {'L', 'O', 'V', 'E', ' ', 'C', '\0'}; //C스트링
    string title(text);

    cout << str << endl;
    cout << address << endl;
    cout << copyAddress << endl;
    cout << title << endl;
}