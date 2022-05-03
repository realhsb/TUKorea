//[예제 2-7] string 클래스를 이용한 문자열 입력 및 다루기
#include <iostream>
#include <string>
using namespace std;

int main(){
    string song("Falling in love with you");
    string elvis("Elvis Presley");
    string singer;

    cout << song + "을 부른 가수는";
    cout << "hint : 첫 글자는 " << elvis[0] << ")?";

    getline(cin, singer);
    if(singer == elvis)
        cout << "correct";
    else
        cout << "fail! " +  elvis << endl;
}