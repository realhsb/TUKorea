#include <iostream>
using namespace std;

int main(){
    cout.put('H');
    cout.put('i');
    cout.put(33);       // 아스키 코드 33은 ! 문자
    cout.put('\n');

    cout.put('C').put('+').put('+').put(' ');

    char str[] = "I love programming";
    cout.write(str, 6);
}