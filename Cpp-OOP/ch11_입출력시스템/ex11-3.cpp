// [예제11-3] get(char*, int)
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char cmd[80];
    cout << "cin.get(char*, int)로 문자열을 읽습니다. " << endl;
    while(true){
        cout << "종료하려면 exit을 입력하세요. ";
        cin.get(cmd, 80);
        if(strcmp(cmd, "exit")==0){
            cout << "프로그램을 종료합니다." ;
            return 0;
        }else
            cin.ignore(1);  // 버퍼에 남아있는 <Enter>키 ('\n') 제거
    }
}
















. 저는 현재 안드로이드 앱 개발 공부 중에 있습니다. 작은 규모의 앱을 개발하면 스마트폰의 내부 저장소나 SD카드를 사용하면 되지만, 
더 큰 규모의 앱을 개발하기 위해서는 외부 저장소를 사용한다는 것을 알았습니다. 백엔드에 대한 