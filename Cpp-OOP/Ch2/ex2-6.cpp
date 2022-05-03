//[예제 2–6] cin.getline()을 이용한 문자열 입력
#include <iostream>
using namespace std;

int main(){
    cout << "주소를 입력하세요 >> ";
    
    char address[100];
    cin.getline(address, 100, '\n');        //키보드로부터 주소 읽기

    cout << "주소는 " << address << "\n";   //주소 출력
}