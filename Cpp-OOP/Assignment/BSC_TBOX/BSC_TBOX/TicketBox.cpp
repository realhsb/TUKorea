#include <iostream>
#include "Screen.h"
#include "TicketBox.h"
#include "Statistics.h"
#include <string>
using namespace std;

// 스크린 객체 생성
void TUKoreaTBox::Initialize(){
    //Screen(영화제목, 티켓가격, 좌석(nRowMax), 좌석(nColMax))
    pEuropeScreen = new EuropeScreen("미드나잇 인 파리", 10000, 10, 10);
    pAsiaScreen = new AsiaScreen("무간도3 - 종극무간", 12000, 10, 10);
    pPremiumScreen = new PremiumScreen("에너미 앳 더 게이트", 30000, 6, 6);
}

TUKoreaTBox::TUKoreaTBox(){}

TUKoreaTBox::~TUKoreaTBox(){}

Screen* TUKoreaTBox::selectMenu(){
    int num = 0;
    cout << "1. 유럽 영화 1관\n";
    cout << "2. 아시아 영화 2관\n";
    cout << "3. 프리미엄 영화 3관\n";
    cout << "9. 통계\t관리\n";
    cout << "선택(1~3, 9) 그 외 종료 : ";
    cin >> num;
    cout << endl;
    switch(num){
        case 1 :
            return pEuropeScreen;
        case 2 :
            return pAsiaScreen;
        case 3 :
            return pPremiumScreen;
        case 9 :
            Manage();
            return NULL;
        default:
            return NULL;
    }
}

void TUKoreaTBox:: Manage(){
    string password = "";
    cout << "비밀번호를 입력하세요. : ";
    cin >> password;

    while(true){
        if(password.compare(TICKET_BOX_MANAGER_PWD) == 0){
            int total = Statistics::totalSalesCount(pEuropeScreen) + Statistics::totalSalesCount(pAsiaScreen) + Statistics::totalSalesCount(pPremiumScreen);
            
            cout << "1. 유럽영화 상영관 결제금액 : " << Statistics::totalRevenue(pEuropeScreen) << endl;
            cout << "2. 아시아영화 상영관 결제금액 : " << Statistics::totalRevenue(pAsiaScreen) << endl;
            cout << "3. 프리미엄영화 상영관 결제금액 : " << Statistics::totalRevenue(pPremiumScreen) << endl;

            cout << "4. 전체 티켓 판매량 : " << total << endl;
            break;
        }else {
            cout << "비밀번호가 일치하지 않습니다. 재입력 : ";
            cin >> password;
        }
    } 
}
