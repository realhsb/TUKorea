//[예제 2-5] C-스트링을 이용하여 암호가 입력되면 프로그램을 종료하는 예
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char password[11];
    cout << "Enter the password for closing program. " << endl;
    while(true){
        cout << "password : ";
        cin >> password;
        if(strcmp(password, "C++") == 0){
            cout << "Off" << endl;
        }else {
            cout << "Not match" << endl;
        }
    }
}