#include <iostream>
#include <string>

#include "Screen.h"
#include "TicketBox.h"
using namespace std;

int main(int argc, const char * argv[]) {
    TUKoreaTBox tBox;
    Screen* screen = NULL;
    bool bScreenMenu = true;
    int select = 0;
    
    tBox.Initialize();      // 3개의 스크린 객체 생성
    while(1) {
        if(bScreenMenu) {
            screen = tBox.selectMenu();
            bScreenMenu = false;
            if(!screen) return 0;
        }
    
        screen->showMovieMenu();
        cout << "메뉴를 선택하세요 : ";
        cin >> select;
        switch (select) {
            case 1:             // 영화 정보
                screen -> showMovieInfo();
                break;
            case 2 :            // 좌석 현황
                screen -> showSeatMap();
                break;
            case 3 :
                screen -> reserveTicket();
                break;
            case 4 :
                screen -> cancelReservation();
                break;
            case 5 :
                screen -> Payment();
                break;
            case 7 :            // 스크린 메인 메뉴
                bScreenMenu = true;
            default:
                break;
        }
    }
    return 0;
}
