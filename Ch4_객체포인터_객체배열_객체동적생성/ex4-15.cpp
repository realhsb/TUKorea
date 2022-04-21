//[예제 4-15] 문자열 find 및 replace
#include <iostream>
#include <string>
using namespace std;
int main(){
    string s, f, r;
    cout << "여러 줄의 문자열을 입력하세요. 입력의 끝은 &입니다. " << endl;
    getline(cin, s, '&');
    cin.ignore();
    cout << endl << "find : ";
    getline(cin, f, '\n');
    cout << "replace : ";
    getline(cin, r, '\n');
    int startIndex = 0;
    while(true){
        int fIndex = s.find(f, startIndex);
        if(fIndex == -1) break;
        s.replace(fIndex, f.length(), r);
        startIndex = fIndex + r.length();
    }
    cout << s << endl;
}