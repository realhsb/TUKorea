//[예제 2–4] 키보드에서 문자열 입력 받고 출력
#include <iostream>
using namespace std;

int main(){
    cout << "이름을 입력하세요. >> ";

    char name[11];  //한글은 5개 글자, 영문은 10개까지 저장 가능
    cin >> name;    //키보드로부터 문자열을 읽음
    cout << "이름 : " << name << "\n";  //이름 출력
}